/** @file std_het.h
*   @brief NHET Instructions Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*	The 
* 
*   (c) Texas Instruments 2009, All rights reserved.
*/
#if defined(_TMS470_BIG) || defined(__big_endian__)
#ifndef HETBYTE
#   define HETBYTE unsigned char
#endif

typedef volatile struct memory_format
{
  unsigned int program_word  ;
  unsigned int control_word  ;
  unsigned int data_word     ;
  unsigned int reserved_word ;
} HET_MEMORY  ;

/*---------------------------------------------*/
/* ACMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct acmp_format
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 3 ;
  unsigned int                      : 5 ;
 
  unsigned int                      : 11 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int                      : 1 ;
  unsigned int count_prv            : 1 ;   
  unsigned int pin_action           : 1 ;
  unsigned int                      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;
 
} ACMP_FIELDS;
 
typedef volatile union
{
  ACMP_FIELDS  acmp   ;
  HET_MEMORY   memory ;
} ACMP_INSTRUCTION;


/*---------------------------------------------*/
/* ECMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct ecmp_format   
{
  unsigned int                      : 11 ;          
  unsigned int brk                  : 1 ;          
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int angle_compare        : 1 ;
  unsigned int                      : 2 ;
  unsigned int                      : 5 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ; 
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/

} ECMP_FIELDS;

typedef volatile union 
{
  ECMP_FIELDS  ecmp   ;
  HET_MEMORY   memory ;
} ECMP_INSTRUCTION;


/*---------------------------------------------*/
/* SCMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct scmp_format     
{
  unsigned int                      : 11 ;          
  unsigned int brk                  : 1 ;          
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int                      : 1 ;
  unsigned int                      : 2 ;
  unsigned int                      : 5 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int                      : 1 ;
  unsigned int restart_en           : 1 ;
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;

} SCMP_FIELDS ;

typedef volatile union 
{
  SCMP_FIELDS  scmp   ;
  HET_MEMORY   memory ;
} SCMP_INSTRUCTION;


/*---------------------------------------------*/
/* MCMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct mcmp_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int hr_lr                : 1 ;
  unsigned int angle_compare        : 1 ;
  unsigned int                      : 1 ;
  unsigned int save_subtract        : 1 ;
  unsigned int                      : 4 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int sub_opcode           : 1 ;
  unsigned int order                : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} MCMP_FIELDS ; 

typedef volatile union 
{
  MCMP_FIELDS  mcmp   ;
  HET_MEMORY   memory ;
} MCMP_INSTRUCTION;

/*---------------------------------------------*/
/* MOV64 INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct mov64_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int remote_address       : 8 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/* TCJ */
/*unsigned int hr_data              : 5 ; */

} MOV64_FIELDS ; 

typedef volatile union 
{
  MOV64_FIELDS  mov64  ;
  HET_MEMORY    memory ;
} MOV64_INSTRUCTION;


/*---------------------------------------------*/
/* DADM64 INSTRUCTION                          */
/*---------------------------------------------*/
typedef volatile struct dadm64_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int remote_address       : 8 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} DADM64_FIELDS ; 

typedef volatile union 
{
  DADM64_FIELDS  dadm64 ;
  HET_MEMORY     memory ;
} DADM64_INSTRUCTION;


/*---------------------------------------------*/
/* RADM64 INSTRUCTION                          */
/*---------------------------------------------*/
typedef volatile struct RADM64_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int remote_address       : 8 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} RADM64_FIELDS ; 


typedef volatile union 
{
  RADM64_FIELDS  radm64 ;
  HET_MEMORY     memory ;
} RADM64_INSTRUCTION;


/*---------------------------------------------*/
/* MOV32 INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct MOV32_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int remote_address       : 8 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int                      : 14 ;
  unsigned int init_flag            : 1 ;
  unsigned int sub_opcode           : 1 ;
  unsigned int move_type            : 2 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int                      : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} MOV32_FIELDS ; 


typedef volatile union 
{
  MOV32_FIELDS  mov32  ;
  HET_MEMORY    memory ;
} MOV32_INSTRUCTION;


/*---------------------------------------------*/
/* ADM32 INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct ADM32_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int remote_address       : 8 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int                      : 14 ;
  unsigned int init_flag            : 1 ;
  unsigned int sub_opcode           : 1 ;
  unsigned int move_type            : 2 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int                      : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ; */
 
} ADM32_FIELDS ; 


typedef volatile union 
{
  ADM32_FIELDS  adm32  ;
  HET_MEMORY    memory ;
} ADM32_INSTRUCTION;


/*---------------------------------------------*/
/* ADCNST INSTRUCTION                          */
/*---------------------------------------------*/
typedef volatile struct ADCNST_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int remote_address       : 8 ;
 
  unsigned int                      : 10 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int const                : 20 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} ADCNST_FIELDS ;


typedef volatile union 
{
  ADCNST_FIELDS  adcnst ;
  HET_MEMORY     memory ;
} ADCNST_INSTRUCTION;


/*---------------------------------------------*/
/* CNT INSTRUCTION                             */
/*---------------------------------------------*/
typedef volatile struct CNT_format                     
{
  unsigned int                      : 11 ;          
  unsigned int brk                  : 1 ;          
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int angle_cnt            : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int                      : 4 ;
  unsigned int interrupt_enable     : 1 ;
 

  unsigned int                      : 10 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int max                  : 20 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;

} CNT_FIELDS ; 

typedef volatile union 
{
  CNT_FIELDS   cnt    ; 
  HET_MEMORY   memory ;
} CNT_INSTRUCTION;


/*---------------------------------------------*/
/* APCNT INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct apcnt_format
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int interrupt_enable     : 1 ;
  unsigned int period_pulse_select  : 2 ;
  unsigned int pin_select           : 5 ;
 
  unsigned int                      : 10 ;
  unsigned int                      : 1 ;
  unsigned int previous_bit         : 1 ;
  unsigned int count                : 20 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;
 
} APCNT_FIELDS ;
 
typedef volatile union
{
  APCNT_FIELDS  apcnt   ;
  HET_MEMORY   memory ;
} APCNT_INSTRUCTION;
 
 

/*---------------------------------------------*/
/* PCNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct pcnt_format                     
{
  unsigned int                      : 11 ;          
  unsigned int brk                  : 1 ;          
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int interrupt_enable     : 1 ;
  unsigned int period_pulse_select  : 2 ;
  unsigned int pin_select           : 5 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int previous_bit         : 1 ;
  unsigned int count                : 20 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/

} PCNT_FIELDS ;      

typedef volatile union 
{
  PCNT_FIELDS  pcnt   ; 
  HET_MEMORY   memory ;
} PCNT_INSTRUCTION;


/*---------------------------------------------*/
/* SCNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct scnt_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 1 ;
  unsigned int count_mode           : 2 ;
  unsigned int step_width           : 2 ;
  unsigned int                      : 3 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int                      : 1 ;
  unsigned int gap_start            : 20 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;

} SCNT_FIELDS ;      

typedef volatile union 
{
  SCNT_FIELDS  scnt   ; 
  HET_MEMORY   memory ;
} SCNT_INSTRUCTION;



/*---------------------------------------------*/
/* ACNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct acnt_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int edge_select          : 1 ;
  unsigned int                      : 6 ;
  unsigned int interrupt_enable     : 1 ; 

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int                      : 1 ;
  unsigned int gap_end              : 20 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;

} ACNT_FIELDS ;      

typedef volatile union 
{
  ACNT_FIELDS  acnt   ; 
  HET_MEMORY   memory ;
} ACNT_INSTRUCTION;


/*---------------------------------------------*/
/* ECNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct ecnt_format
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 1 ;
  unsigned int count_mode           : 2 ;
  unsigned int cap_en               : 1 ;
  unsigned int                      : 4 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int previous_bit         : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int count_cond           : 3 ;
  unsigned int                      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;
 
} ECNT_FIELDS ;
 
typedef volatile union
{
  ECNT_FIELDS  ecnt   ;
  HET_MEMORY   memory ;
} ECNT_INSTRUCTION;


/*---------------------------------------------*/
/* DJNZ INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct djnz_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;          
  unsigned int op_code              : 4 ;
  unsigned int                      : 1 ;
  unsigned int count_mode           : 2 ;
  unsigned int                      : 5 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int                      : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int                      : 9 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;

} DJNZ_FIELDS ;      

typedef volatile union 
{
  DJNZ_FIELDS  djnz   ; 
  HET_MEMORY   memory ;
} DJNZ_INSTRUCTION;


/*---------------------------------------------*/
/* PWCNT INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct pwcnt_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 1 ;
  unsigned int count_mode           : 2 ;
  unsigned int                      : 5 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int                      : 2 ;
  unsigned int pin_action           : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;
 
} PWCNT_FIELDS ;      

typedef volatile union 
{
  PWCNT_FIELDS  pwcnt ;
  HET_MEMORY   memory ;
} PWCNT_INSTRUCTION;


/*---------------------------------------------*/
/* WCAP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct wcap_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 8 ;
  
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int previous_bit         : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int capture_condition    : 2 ;
  unsigned int                      : 2 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;
/*TCJ*/
/*unsigned int hr_data              : 5 ;*/

} WCAP_FIELDS ;      

typedef volatile union 
{
  WCAP_FIELDS  wcap   ; 
  HET_MEMORY   memory ;
} WCAP_INSTRUCTION;
 


/*---------------------------------------------*/
/* BR   INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct br_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 8 ;

  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int previous_bit         : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int pin_select           : 5 ;
  unsigned int branch_condition     : 3 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int interrupt_enable     : 1 ;
 
  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} BR_FIELDS ;      

typedef volatile union 
{
  BR_FIELDS  br     ; 
  HET_MEMORY memory ;
} BR_INSTRUCTION;

 
/*---------------------------------------------*/
/* SHFT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct shft_format                     
{
  unsigned int                      : 11 ;
  unsigned int brk                  : 1 ;
  unsigned int next_program_address : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int                      : 4 ;
  unsigned int shift_mode           : 4 ;
 
  unsigned int                      : 10 ;
  unsigned int control              : 1 ;
  unsigned int                      : 1 ;
  unsigned int cond_addr            : 8 ;
  unsigned int data_pin_select      : 5 ;
  unsigned int shift_condition      : 2 ;
  unsigned int                      : 2 ;
  unsigned int t_register_select    : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int interrupt_enable     : 1 ;

  unsigned int                      : 7 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 5 ;

} SHFT_FIELDS ;      

typedef volatile union 
{
  SHFT_FIELDS  shft   ; 
  HET_MEMORY   memory ;
} SHFT_INSTRUCTION;


#elif defined(_TMS470_LITTLE) || defined(__little_endian__)
#ifndef HETBYTE
#   define HETBYTE unsigned char
#endif

typedef volatile struct memory_format
{
  unsigned int program_word  ;
  unsigned int control_word  ;
  unsigned int data_word     ;
  unsigned int reserved_word ;
} HET_MEMORY  ;



/*---------------------------------------------*/
/* ACMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct acmp_format
{
  unsigned int                      : 5 ;
  unsigned int                      : 3 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int                      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int count_prv            : 1 ; 
  unsigned int                      : 1 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int                      : 11 ; 

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ; 

} ACMP_FIELDS;
 
typedef volatile union
{
  ACMP_FIELDS  acmp   ;
  HET_MEMORY   memory ;
} ACMP_INSTRUCTION;


/*---------------------------------------------*/
/* ECMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct ecmp_format   
{
  unsigned int                      : 5 ;         
  unsigned int                      : 2 ;         
  unsigned int angle_compare        : 1 ;         
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ; 
  unsigned int brk                  : 1 ; 
  unsigned int                      : 11 ; 

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ; 
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/

} ECMP_FIELDS;

typedef volatile union 
{
  ECMP_FIELDS  ecmp   ;
  HET_MEMORY   memory ;
} ECMP_INSTRUCTION;


/*---------------------------------------------*/
/* SCMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct scmp_format     
{
  unsigned int                      : 5 ;          
  unsigned int                      : 2 ;          
  unsigned int                      : 1 ;        
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ; 
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int interrupt_enable     : 1 ;
  unsigned int restart_en           : 1 ;
  unsigned int                      : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;

} SCMP_FIELDS ;

typedef volatile union 
{
  SCMP_FIELDS  scmp   ;
  HET_MEMORY   memory ;
} SCMP_INSTRUCTION;


/*---------------------------------------------*/
/* MCMP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct mcmp_format                     
{
  unsigned int                      : 4 ;
  unsigned int save_subtract        : 1 ;
  unsigned int                      : 1 ;
  unsigned int angle_compare        : 1 ;
  unsigned int hr_lr                : 1 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;
   
  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int order                : 1 ;
  unsigned int sub_opcode           : 1 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ; 

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} MCMP_FIELDS ; 

typedef volatile union 
{
  MCMP_FIELDS  mcmp   ;
  HET_MEMORY   memory ;
} MCMP_INSTRUCTION;

/*---------------------------------------------*/
/* MOV64 INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct mov64_format                     
{
  unsigned int remote_address       : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;          
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;
   
  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/* TCJ */
/*unsigned int hr_data              : 5 ; */

} MOV64_FIELDS ; 

typedef volatile union 
{
  MOV64_FIELDS  mov64  ;
  HET_MEMORY    memory ;
} MOV64_INSTRUCTION;


/*---------------------------------------------*/
/* DADM64 INSTRUCTION                          */
/*---------------------------------------------*/
typedef volatile struct dadm64_format                     
{
  unsigned int remote_address       : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ; 

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} DADM64_FIELDS ; 

typedef volatile union 
{
  DADM64_FIELDS  dadm64 ;
  HET_MEMORY     memory ;
} DADM64_INSTRUCTION;


/*---------------------------------------------*/
/* RADM64 INSTRUCTION                          */
/*---------------------------------------------*/
typedef volatile struct RADM64_format                     
{
  unsigned int remote_address       : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int compare_mode         : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;
   
  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} RADM64_FIELDS ; 


typedef volatile union 
{
  RADM64_FIELDS  radm64 ;
  HET_MEMORY     memory ;
} RADM64_INSTRUCTION;


/*---------------------------------------------*/
/* MOV32 INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct MOV32_format                     
{
  unsigned int remote_address       : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int                      : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int move_type            : 2 ;
  unsigned int sub_opcode           : 1 ;
  unsigned int init_flag            : 1 ;
  unsigned int                      : 14 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ; 

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} MOV32_FIELDS ; 


typedef volatile union 
{
  MOV32_FIELDS  mov32  ;
  HET_MEMORY    memory ;
} MOV32_INSTRUCTION;


/*---------------------------------------------*/
/* ADM32 INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct ADM32_format                     
{
  unsigned int remote_address       : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;
 
  unsigned int                      : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int move_type            : 2 ;
  unsigned int sub_opcode           : 1 ;
  unsigned int init_flag            : 1 ;
  unsigned int                      : 14 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int data                 : 25 ; 
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ; */
 
} ADM32_FIELDS ; 


typedef volatile union 
{
  ADM32_FIELDS  adm32  ;
  HET_MEMORY    memory ;
} ADM32_INSTRUCTION;


/*---------------------------------------------*/
/* ADCNST INSTRUCTION                          */
/*---------------------------------------------*/
typedef volatile struct ADCNST_format                     
{
  unsigned int remote_address       : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int const                : 20 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int                      : 10 ; 

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;


/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} ADCNST_FIELDS ;


typedef volatile union 
{
  ADCNST_FIELDS  adcnst ;
  HET_MEMORY     memory ;
} ADCNST_INSTRUCTION;


/*---------------------------------------------*/
/* CNT INSTRUCTION                             */
/*---------------------------------------------*/
typedef volatile struct CNT_format                     
{
  unsigned int interrupt_enable     : 1 ;          
  unsigned int                      : 4 ;           
  unsigned int ab_register_select   : 1 ;         
  unsigned int t_register_select    : 1 ;
  unsigned int angle_cnt            : 1 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ; 
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int max                  : 20 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;

} CNT_FIELDS ; 

typedef volatile union 
{
  CNT_FIELDS   cnt    ; 
  HET_MEMORY   memory ;
} CNT_INSTRUCTION;


/*---------------------------------------------*/
/* APCNT INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct apcnt_format
{
  unsigned int pin_select           : 5 ;
  unsigned int period_pulse_select  : 2 ;
  unsigned int interrupt_enable     : 1 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int count                : 20 ;
  unsigned int previous_bit         : 1 ;
  unsigned int                      : 1 ;
  unsigned int                      : 10 ;
 
  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;
 
} APCNT_FIELDS ;
 
typedef volatile union
{
  APCNT_FIELDS  apcnt   ;
  HET_MEMORY   memory ;
} APCNT_INSTRUCTION;
 
 

/*---------------------------------------------*/
/* PCNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct pcnt_format                     
{
  unsigned int pin_select           : 5 ;         
  unsigned int period_pulse_select  : 2 ;         
  unsigned int interrupt_enable     : 1 ;          
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ; 
  unsigned int                      : 11 ; 

  unsigned int count                : 20 ;
  unsigned int previous_bit         : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/

} PCNT_FIELDS ;      

typedef volatile union 
{
  PCNT_FIELDS  pcnt   ; 
  HET_MEMORY   memory ;
} PCNT_INSTRUCTION;


/*---------------------------------------------*/
/* SCNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct scnt_format                     
{
  unsigned int                      : 3 ;
  unsigned int step_width           : 2 ;
  unsigned int count_mode           : 2 ;
  unsigned int                      : 1 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int gap_start            : 20 ;
  unsigned int                      : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;

} SCNT_FIELDS ;      

typedef volatile union 
{
  SCNT_FIELDS  scnt   ; 
  HET_MEMORY   memory ;
} SCNT_INSTRUCTION;



/*---------------------------------------------*/
/* ACNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct acnt_format                     
{
  unsigned int interrupt_enable     : 1 ;
  unsigned int                      : 6 ;
  unsigned int edge_select          : 1 ;          
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ; 
  unsigned int                      : 11 ;

  unsigned int gap_end              : 20 ;
  unsigned int                      : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;
 
  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;

} ACNT_FIELDS ;      

typedef volatile union 
{
  ACNT_FIELDS  acnt   ; 
  HET_MEMORY   memory ;
} ACNT_INSTRUCTION;


/*---------------------------------------------*/
/* ECNT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct ecnt_format
{
  unsigned int                      : 4 ;
  unsigned int cap_en               : 1 ;
  unsigned int count_mode           : 2 ;
  unsigned int                      : 1 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int                      : 1 ;
  unsigned int count_cond           : 3 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int previous_bit         : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;
   
} ECNT_FIELDS ;
 
typedef volatile union
{
  ECNT_FIELDS  ecnt   ;
  HET_MEMORY   memory ;
} ECNT_INSTRUCTION;


/*---------------------------------------------*/
/* DJNZ INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct djnz_format                     
{
  unsigned int                      : 5 ;
  unsigned int count_mode           : 2 ;
  unsigned int                      : 1 ;         
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ; 
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int                      : 9 ;
  unsigned int cond_addr            : 8 ;
  unsigned int                      : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;

} DJNZ_FIELDS ;      

typedef volatile union 
{
  DJNZ_FIELDS  djnz   ; 
  HET_MEMORY   memory ;
} DJNZ_INSTRUCTION;


/*---------------------------------------------*/
/* PWCNT INSTRUCTION                           */
/*---------------------------------------------*/
typedef volatile struct pwcnt_format                     
{
  unsigned int                      : 5 ;
  unsigned int count_mode           : 2 ;
  unsigned int                      : 1 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int optional_action      : 1 ;
  unsigned int pin_action           : 1 ;
  unsigned int                      : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int en_pin_action        : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;
   
} PWCNT_FIELDS ;      

typedef volatile union 
{
  PWCNT_FIELDS  pwcnt ;
  HET_MEMORY   memory ;
} PWCNT_INSTRUCTION;


/*---------------------------------------------*/
/* WCAP INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct wcap_format                     
{
  unsigned int                      : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;  

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int                      : 2 ;
  unsigned int capture_condition    : 2 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int previous_bit         : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int data                 : 25 ;
  unsigned int                      : 7 ;
/*TCJ*/
/*unsigned int hr_data              : 5 ;*/

} WCAP_FIELDS ;      

typedef volatile union 
{
  WCAP_FIELDS  wcap   ; 
  HET_MEMORY   memory ;
} WCAP_INSTRUCTION;
 


/*---------------------------------------------*/
/* BR   INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct br_format                     
{
  unsigned int                      : 8 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ;

  unsigned int interrupt_enable     : 1 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int                      : 1 ;
  unsigned int branch_condition     : 3 ;
  unsigned int pin_select           : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int previous_bit         : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ; 

  unsigned int                      : 7 ;
  unsigned int data                 : 25 ;

/*TCJ*/
/*unsigned int hr_data              : 5 ;*/
 
} BR_FIELDS ;      

typedef volatile union 
{
  BR_FIELDS  br     ; 
  HET_MEMORY memory ;
} BR_INSTRUCTION;

 
/*---------------------------------------------*/
/* SHFT INSTRUCTION                            */
/*---------------------------------------------*/
typedef volatile struct shft_format                     
{
  unsigned int shift_mode           : 4 ;
  unsigned int                      : 4 ;
  unsigned int op_code              : 4 ;
  unsigned int next_program_address : 8 ;
  unsigned int brk                  : 1 ;
  unsigned int                      : 11 ; 

  unsigned int interrupt_enable     : 1 ;
  unsigned int ab_register_select   : 1 ;
  unsigned int t_register_select    : 1 ;
  unsigned int                      : 2 ;
  unsigned int shift_condition      : 2 ;
  unsigned int data_pin_select      : 5 ;
  unsigned int cond_addr            : 8 ;
  unsigned int                      : 1 ;
  unsigned int control              : 1 ;
  unsigned int                      : 10 ;

  unsigned int                      : 5 ;
  unsigned int data                 : 20 ;
  unsigned int                      : 7 ;

} SHFT_FIELDS ;      

typedef volatile union 
{
  SHFT_FIELDS  shft   ; 
  HET_MEMORY   memory ;
} SHFT_INSTRUCTION;


#endif
