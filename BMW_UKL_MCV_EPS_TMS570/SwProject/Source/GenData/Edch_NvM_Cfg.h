

/* --------{ BMW C Source File }-------- */

/* !LINKSTO EDCH_SDD_0311, 1
 */



#ifndef EDCH_NVM_CFG_H
#define EDCH_NVM_CFG_H

/*==================[inclusions]==============================================*/

/*==================[macros]==================================================*/

/* !LINKSTO EDCH_SDD_0251, 1
 */
#if (defined EDCH_CODINGSW_CNT)
#error EDCH_CODINGSW_CNT is already defined
#endif
/**
 * \brief Count of configured OBD relevant coding switches
 */
#define EDCH_CODINGSW_CNT 0U

/* !LINKSTO EDCH_SDD_0256, 1
 */
#if (defined EDCH_CVNTABLE_CNT)
#error EDCH_CVNTABLE_CNT is already defined
#endif
/**
 * \brief Count of configured EdchCvnDefinitionBlock
 */
#define EDCH_CVNTABLE_CNT 3U

/* !LINKSTO EDCH_SDD_0260, 1
 */
#if (defined Edch_SubCvn_0_val)
#error Edch_SubCvn_0_val is already defined
#endif
/**
 * \brief Allias for CRC32 values for Sub-CVN 0
 */
#define Edch_SubCvn_0_val Edch_SubCvn_val[0U]

#if (defined Edch_SubCvn_0_DefaultVal)
#error Edch_SubCvn_0_DefaultVal is already defined
#endif
/**
 * \brief Allias for CRC32 default values for Sub-CVN 0
 */
#define Edch_SubCvn_0_DefaultVal Edch_SubCvnDefaultVal[0U]

#if (defined Edch_SubCvn_1_val)
#error Edch_SubCvn_1_val is already defined
#endif
/**
 * \brief Allias for CRC32 values for Sub-CVN 1
 */
#define Edch_SubCvn_1_val Edch_SubCvn_val[1U]

#if (defined Edch_SubCvn_1_DefaultVal)
#error Edch_SubCvn_1_DefaultVal is already defined
#endif
/**
 * \brief Allias for CRC32 default values for Sub-CVN 1
 */
#define Edch_SubCvn_1_DefaultVal Edch_SubCvnDefaultVal[1U]

#if (defined Edch_SubCvn_2_val)
#error Edch_SubCvn_2_val is already defined
#endif
/**
 * \brief Allias for CRC32 values for Sub-CVN 2
 */
#define Edch_SubCvn_2_val Edch_SubCvn_val[2U]

#if (defined Edch_SubCvn_2_DefaultVal)
#error Edch_SubCvn_2_DefaultVal is already defined
#endif
/**
 * \brief Allias for CRC32 default values for Sub-CVN 2
 */
#define Edch_SubCvn_2_DefaultVal Edch_SubCvnDefaultVal[2U]


/*==================[type definitions]========================================*/

/*==================[external function declarations]==========================*/

/*==================[internal function declarations]==========================*/

/*==================[external constants]======================================*/

/*==================[internal constants]======================================*/

/*==================[external data]===========================================*/

/*==================[internal data]===========================================*/

/*==================[external function definitions]===========================*/

/*==================[internal function definitions]===========================*/

#endif /* if (!defined EDCH_NVM_CFG_H) */
/*==================[end of file]=============================================*/
