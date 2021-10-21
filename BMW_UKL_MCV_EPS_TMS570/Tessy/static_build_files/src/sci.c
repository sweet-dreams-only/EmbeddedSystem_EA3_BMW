/** @file sci.c 
*   @brief SCI Driver Implmentation File
*   @date 14.September.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "sci.h"

unsigned char receive_command[8];
unsigned int Task_Number = 0;
unsigned int SubTask_Number = 0;

/** @struct sciTransfer
*   @breif Interrupt mode globals
*
*/
struct g_sciTransfer
{
    unsigned       length;
    unsigned char *data;
} g_sciTransfer[2];


/** @fn void sciInit(void)
*   @brief Initializes the SCI Driver
*
*   This function initializes the SCI module.
*/
void sciInit(void)
{
    /** @b intalise SCI1 @b */

    /** - bring SCI out of reset */
    sciREG1->GCR0 = 1U;

    /** - Disable all interrupts */
    sciREG1->CLRINT    = 0xFFFFFFFF;
    sciREG1->CLRINTLVL = 0xFFFFFFFF;

    /** - global control 1 */
    sciREG1->GCR1 = (1 << 25)  /* enable transmit */
                  | (1 << 24)  /* enable receive */
                  | (0 << 10)  /* Disable multi buffer mode */
                  | (1 << 5)   /* internal clock (device has no clock pin) */
                  | ((1-1) << 4)  /* number of stop bits */
                  | (1 << 3)  /* even parity, otherwise odd */
                  | (0 << 2)  /* no parity */
                  | (1 << 1);  /* asynchronous timing mode */

    /** - set baudrate */
    sciREG1->BAUD = 325;  /* baudrate */

    /** - tranmision length */
    sciREG1->LENGTH = 7;  /* length */

    /** - set SCI pins functional mode */
    sciREG1->FUN = (1 << 2)  /* tx pin */
                 | (1 << 1)  /* rx pin */
                 | (0);  /* clk pin */

    /** - set SCI pins default output value */
    sciREG1->DOUT = (0 << 2)  /* tx pin */
                  | (0 << 1)  /* rx pin */
                  | (0);  /* clk pin */

    /** - set SCI pins output direction */
    sciREG1->DIR = (0 << 2)  /* tx pin */
                 | (0 << 1)  /* rx pin */
                 | (0);  /* clk pin */

    /** - set SCI pins open drain enable */
    sciREG1->ODR = (0 << 2)  /* tx pin */
                 | (0 << 1)  /* rx pin */
                 | (0);  /* clk pin */

    /** - set SCI pins pullup/pulldown enable */
    sciREG1->PD = (0 << 2)  /* tx pin */
                | (0 << 1)  /* rx pin */
                | (0);  /* clk pin */

    /** - set SCI pins pullup/pulldown select */
    sciREG1->PSL = (1 << 2)  /* tx pin */
                 | (1 << 1)  /* rx pin */
                 | (1);  /* clk pin */

    /** - set interrupt level */
    sciREG1->SETINTLVL = (0 << 26)  /* Framing error */
                       | (0 << 25)  /* Overrun error */
                       | (0 << 24)  /* Pariry error */
                       | (0 << 9)  /* Receive */
                       | (0 << 8)  /* Transmit */
                       | (0 << 1)  /* Wakeup */
                       | (0);  /* Break detect */

    /** - clear interrupt flags */
    sciREG1->FLR = 0xFFFFFFFF;

    /** - set interrupt enable */
    sciREG1->SETINT = (0 << 26)  /* Framing error */
                    | (0 << 25)  /* Overrun error */
                    | (0 << 24)  /* Pariry error */
                    | (1 << 9)  /* Receive */
                    | (0 << 8)  /* Transmit */
                    | (0 << 1)  /* Wakeup */
                    | (0);  /* Break detect */

    /** - inialise global transfer variables */
    g_sciTransfer[0].length = 0;

    /** - Finaly start SCI1 */
    sciREG1->GCR1 |= (1 << 7);
}


/** @fn void sciSetFunctional(sciBASE_t *sci, unsigned port)
*   @brief Change functional behavoiur of pins at runtime.
*   @param[in] sci   - sci module base address
*   @param[in] port  - Value to write to FUN register
*
*   Change the value of the PCFUN register at runtime, this allows to
*   dynaimcaly change the functionality of the SCI pins between functional
*   and GIO mode.
*/
void sciSetFunctional(sciBASE_t *sci, unsigned port)
{
    sci->FUN = port;
}


/** @fn void sciSetBaudrate(sciBASE_t *sci, unsigned baud)
*   @brief Change baudrate at runtime.
*   @param[in] sci  - sci module base address
*   @param[in] baud - baudrate in Hz
*
*   Change the SCI baudrate at runtime.
*/
void sciSetBaudrate(sciBASE_t *sci, unsigned baud)
{
    double   vclk = 80.0 * 1000000.0;
    unsigned f    = sci->GCR1 & 2 ? 16 : 1;

    sci->BAUD = ((unsigned)(vclk /(f*baud)) - 1) & 0x00FFFFFF;
}


/** @fn int sciIsTxReady(sciBASE_t *sci)
*   @breif Check if Tx buffer empty
*   @param[in] sci - sci module base address
*
*   @return The TX ready flag
*
*   Checks to see if the Tx buffer ready flag is set, returns
*   0 is flags not set otherwise will return the Tx flag itself.
*/
int sciIsTxReady(sciBASE_t *sci)
{
    return sci->FLR & SCI_TX_INT;
}


/** @fn void sciSendByte(sciBASE_t *sci, unsigned char byte)
*   @breif Send Byte
*   @param[in] sci  - sci module base address
*   @param[in] byte - byte to transfer
*
*   Sends a single byte in polling mode, will wait in the
*   routine until the transmit buffer is empty before sending
*   the byte.  Use sciIsTxReady to check for Tx buffer empty
*   before calling sciSendByte to avoid waiting.
*/
void sciSendByte(sciBASE_t *sci, unsigned char byte)
{
    while ((sci->FLR & SCI_TX_INT) == 0) { /* wait */ };
    sci->TD = byte;
}


/** @fn void sciSend(sciBASE_t *sci, unsigned length, unsigned char *data)
*   @breif Send Data
*   @param[in] sci    - sci module base address
*   @param[in] length - number of data words to transfer
*   @param[in] data   - pointer to data to send
*
*   Send a block of data pointed to by 'data' and 'length' bytes
*   long.  If interrupts have been enabled the data is sent using
*   interrupt mode, otherwise polling mode is used.  In interrupt
*   mode transmition of the first byte is started and the routine
*   returns imediatly, sciSend must not be called again until the
*   transfer is complete, when the sciNotification callback will
*   be called.  In polling mode, sciSend will not return  until 
*   the transfer is complete.
*
*   @Note if data word is less than 8 bits, then the data must be left
*         aligned in the data byte.
*/
void sciSend(sciBASE_t *sci, unsigned length, unsigned char *data)
{
    if (sci->SETINT & SCI_TX_INT)
    {
        /* we are in interrupt mode */
        int index = sci == sciREG1 ? 0 : 1;
        
        g_sciTransfer[index].length = length;
        g_sciTransfer[index].data   = data;

        /* start transmit by sending first byte */        
        sci->TD = *g_sciTransfer[index].data++;
    }
    else
    {
        /* send the data */
        while (length-- > 0)
        {
            while ((sci->FLR & SCI_TX_INT) == 0) { /* wait */ };
            sci->TD = *data++;
        }
    }
}


/** @fn int sciIsRxReady(sciBASE_t *sci)
*   @breif Check if Rx buffer full
*   @param[in] sci - sci module base address
*
*   @return The Rx ready flag
*
*   Checks to see if the Rx buffer full flag is set, returns
*   0 is flags not set otherwise will return the Rx flag itself.
*/
int sciIsRxReady(sciBASE_t *sci)
{
    return sci->FLR & SCI_RX_INT;
}


/** @fn int sciRxError(sciBASE_t *sci)
*   @breif Return Rx Error flags
*   @param[in] sci - sci module base address
*
*   @return The Rx error flags
*
*   Returns the Rx framing, overun and parity errors flags,
*   also clears the error flags before returning.
*/
int sciRxError(sciBASE_t *sci)
{
    int status = sci->FLR & (SCI_FE_INT | SCI_OE_INT |SCI_PE_INT);

    sci->FLR = SCI_FE_INT | SCI_OE_INT | SCI_PE_INT;

    return status;
}


/** @fn unsigned sciReceiveByte(sciBASE_t *sci)
*   @breif Receive Byte
*   @param[in] sci - sci module base address
*
*   @return Received byte
*
*    Recieves a single byte in polling mode.  If there is
*    not a byte in the receive buffer the routine will wait
*    until one is received.   Use sciIsRxReady to check to
*    see if the buffer is full to avoid waiting.
*/
int sciReceiveByte(sciBASE_t *sci)
{
    while ((sci->FLR & SCI_RX_INT) == 0) { /* wait */ };

    return sci->RD;
}


/** @fn void sciReceive(sciBASE_t *sci, unsigned length, unsigned char *data)
*   @breif Receive Data
*   @param[in] sci    - sci module base address
*   @param[in] length - number of data words to transfer
*   @param[in] data   - pointer to data buffer
*
*   Receive a block of 'length' bytes long and place it into the 
*   data buffer pointed to by 'data'.  If interrupts have been 
*   enabled the data is received using interrupt mode, otherwise
*   polling mode is used.  In interrupt mode receive is setup and
*   the routine returns imediatly, sciReceive must not be called 
*   again until the transfer is complete, when the sciNotification 
*   callback will be called.  In polling mode, sciReceive will not
*   return  until the transfer is complete.
*/
void sciReceive(sciBASE_t *sci, unsigned length, unsigned char *data)
{
    if (sci->SETINT & SCI_RX_INT)
    {
        /* we are in interrupt mode */
        int index = sci == sciREG1 ? 0 : 1;
        
        /* clear error flags */
        sci->FLR = SCI_FE_INT | SCI_OE_INT | SCI_PE_INT;

        g_sciTransfer[index].length = length;
        g_sciTransfer[index].data   = data;
    }
    else
    {   
        while (length-- > 0)
        {
            while ((sci->FLR & SCI_RX_INT) == 0) { /* wait */ };
            *data++ = sci->RD;
        }
    }
}


/** @fn sciEnableNotification(sciBASE_t *sci, unsigned flags)
*   @breif Enable interrupts
*   @param[in] sci   - sci module base address
*   @param[in] flags - Interrupts to be enabled, can be ored value of:
*                      SCI_FE_INT    - framming error,
*                      SCI_OE_INT    - overrun error,
*                      SCI_PE_INT    - parity error,
*                      SCI_RX_INT    - receive buffer ready,
*                      SCI_TX_INT    - transmit buffer ready,
*                      SCI_WAKE_INT  - wakeup,
*                      SCI_BREAK_INT - break detect
*/
void sciEnableNotification(sciBASE_t *sci, unsigned flags)
{
    sci->SETINT = flags;
}


/** @fn sciDisableNotification(sciBASE_t *sci, unsigned flags)
*   @breif Disable interrupts
*   @param[in] sci   - sci module base address
*   @param[in] flags - Interrupts to be disabled, can be ored value of:
*                      SCI_FE_INT    - framming error,
*                      SCI_OE_INT    - overrun error,
*                      SCI_PE_INT    - parity error,
*                      SCI_RX_INT    - receive buffer ready,
*                      SCI_TX_INT    - transmit buffer ready,
*                      SCI_WAKE_INT  - wakeup,
*                      SCI_BREAK_INT - break detect
*/
void sciDisableNotification(sciBASE_t *sci, unsigned flags)
{
    sci->CLRINT = flags;
}


/** @fn void sciHighLevelInterrupt(void)
*   @breif High Level Interrupt for SCI1
*/
#pragma INTERRUPT(sciHighLevelInterrupt, IRQ)

void sciHighLevelInterrupt(void)
{
    unsigned vec = sciREG1->INTVECT0;

    switch (vec)
    {
    case 1:
        sciNotification(SCI_WAKE_INT);
        break;
    case 3:
        sciNotification(SCI_PE_INT);
        break;
    case 6:
        sciNotification(SCI_FE_INT);
        break;
    case 7:
        sciNotification(SCI_BREAK_INT);
        break;
    case 9:
        sciNotification(SCI_OE_INT);
        break;

    case 11:
        /* receive */
        {   unsigned byte = sciREG1->RD;

            if (g_sciTransfer[0].length > 0)
            {
                *g_sciTransfer[0].data++ = byte;
                g_sciTransfer[0].length--;
                if (g_sciTransfer[0].length == 0)
                {
                    sciNotification(SCI_RX_INT);
                }
            }
        }
        break;

    case 12:
        /* transmit */
        if (g_sciTransfer[0].length > 0)
        {
            sciREG1->TD = *g_sciTransfer[0].data++;
            g_sciTransfer[0].length--;
        }
        else
        {
            sciNotification(SCI_TX_INT);
        }
        break;

    default:
        /* phantom interrupt, clear flags and return */
        sciREG1->FLR = ~sciREG1->SETINTLVL & 0x07000303;
    }
}


/** @fn void sciHighLevelInterrupt(void)
*   @breif Low Level Interrupt for SCI1
*/
#pragma INTERRUPT(sciLowLevelInterrupt1, IRQ)

void sciLowLevelInterrupt1(void)
{
    unsigned vec = sciREG1->INTVECT1;

    switch (vec)
    {
    case 1:
        sciNotification(SCI_WAKE_INT);
        break;
    case 3:
        sciNotification(SCI_PE_INT);
        break;
    case 6:
        sciNotification(SCI_FE_INT);
        break;
    case 7:
        sciNotification(SCI_BREAK_INT);
        break;
    case 9:
        sciNotification(SCI_OE_INT);
        break;

    case 11:
        /* receive */
        {   unsigned byte = sciREG1->RD;

            if (g_sciTransfer[0].length > 0)
            {
                *g_sciTransfer[0].data++ = byte;
                g_sciTransfer[0].length--;
                if (g_sciTransfer[0].length == 0)
                {
                    sciNotification(SCI_RX_INT);
                }
            }
        }
        break;

    case 12:
        /* transmit */
        if (g_sciTransfer[0].length > 0)
        {
            sciREG1->TD = *g_sciTransfer[0].data++;
            g_sciTransfer[0].length--;
        }
        else
        {
            sciNotification(SCI_TX_INT);
        }
        break;

    default:
        /* phantom interrupt, clear flags and return */
        sciREG1->FLR = sciREG1->SETINTLVL & 0x07000303;
    }
}
/** @fn void sciSend_32bitdata(sciBASE_t *sci, unsigned int data)
*
*	Function used for send a 32bit data on to the SCI at the 
*   configured baud rate    
*/
void sciSend_32bitdata(sciBASE_t *sci, unsigned int data)
{
	unsigned char c_get ;
  	volatile int i = 0;
  	for( i = 8 ; i > 0 ; i-- )
  	{
 		c_get = (data>>28)&15 ;
		if( c_get > 9 )
			c_get += 7 ;
		c_get += 48 ;
		while ((sci->FLR & SCI_TX_INT) == 0) { /* wait */ };
		sci->TD = c_get;
		data = data<<4 ;
	}
}


/** @fn void sciNotification(unsigned flags)
*   
*	This function is called after a SCI Command( 8 Bytes)
*   is received by the micro. 
* 		Typical Command from PC  --> *DOTTSS!
*		*  --> Starter			- 	1st Byte
*		DO --> Just a Word		- 	2nd and 3rd byte
*		TT --> Task Number 		- 	4th and 5th Byte			
* 		SS --> Sub Task Number	-	6th and 7th Byte
* 		!  --> End 				-	8th byte
*/
void sciNotification(unsigned flags)
{
	/** Check for the Valid Command 
	 * 	* - Starter 
	 *  ! - End of Command 
	 */
	if(receive_command[0] == '*' && receive_command[7] == '!')
	{	
		/** - 4th and 5th byte received are Task Number, 
		 * combine them to form one decimal Number */
		Task_Number =  (unsigned int)(((receive_command[3] - 48) * 10) + (receive_command[4] - 48));

		/** - 6th and 7th byte received are Sub Task Number, 
		 * combine them to form one decimal Number */
		SubTask_Number =  (unsigned int)(((receive_command[5] - 48) * 10) + (receive_command[6] - 48));
		
		/** - Get ready to receive the next Command */
		sciReceive	(sciREG1, 8, receive_command);
		
		/** - Acknowledge once the Valid Command is received */
		sciSend		(sciREG1, 8, (unsigned char *) "*VALID#!");
	}
	else
	{
		/** - Get ready to receive the next Command */
		sciReceive	(sciREG1, 8, receive_command);
		/** - Acknowledge once the InValid Command is received */
		sciSend		(sciREG1, 8, (unsigned char *) "WHO R U?");
	}
}


