#define EM4325_SPIBUFFERSIZE					(8+1) 			/* the number of byte of the SendSPI command is 8 bytes*/

/* the following constants defines the number of byte of the commands according to the EM4325 datasheet*/
#define EM4325_SPI_CMD_NBBYTE_REQUESTSTATUS	0x01			/*nb of bytes of the SPIRequestStatus command*/
#define EM4325_SPI_CMD_NBBYTE_BOOT				0x01			/*nb of bytes of the SPIBoot command*/
#define EM4325_SPI_CMD_NBBYTE_READWORD			0x02			/*nb of bytes of the SPIReadWord command */
#define EM4325_SPI_CMD_NBBYTE_WRITEWORD		0x04			/*nb of bytes of the SPIWriteWord command */
#define EM4325_SPI_CMD_NBBYTE_READPAGE			0x02			/*nb of bytes of the SPIReadPage command */
#define EM4325_SPI_CMD_NBBYTE_READREGFILEWORD	0x02			/*nb of bytes of the SPIWRegisterFileWord command */
#define EM4325_SPI_CMD_NBBYTE_WRITEREGFILEWORD	0x04			/*nb of bytes of the SPIWriteRegisterFileWord command */
#define EM4325_SPI_CMD_NBBYTE_REQRN			0x01			/*nb of bytes of the SPIReqNewHandle command */
#define EM4325_SPI_CMD_NBBYTE_REQNEWHANDLE		0x02			/*nb of bytes of the SPIReqNewHandle command */
#define EM4325_SPI_CMD_NBBYTE_SETHANDLE		0x04			/*nb of bytes of the SPISetHandle command */
#define EM4325_SPI_CMD_NBBYTE_SETCOMMPARAMS	0x04			/*nb of bytes of the SPISetCommParams command */
#define EM4325_SPI_CMD_NBBYTE_GETCOMMPARAMS	0x02			/*nb of bytes of the SPIGetCommParams command */
#define EM4325_SPI_CMD_NBBYTE_GETNEWSENSORDATA	0x01			/*nb of bytes of the SPIGetSensorData command (new sample case) */

/* the following constants defines the number of byte of the responses according to the EM4325 datasheet*/
#define EM4325_SPI_RES_NBBYTE_REQUESTSTATUS	0x01			/*nb of bytes of the response to the command SPIRequestStatus*/
#define EM4325_SPI_RES_NBBYTE_BOOT				0x01			/*nb of bytes of the response to the command SPIBoot*/
#define EM4325_SPI_RES_NBBYTE_READWORD			0x03			/*nb of bytes of the response to the command SPIReadWord*/
#define EM4325_SPI_RES_NBBYTE_WRITEWORD		0x01			/*nb of bytes of the response to the command SPIWriteWord*/
#define EM4325_SPI_RES_NBBYTE_READPAGE			0x09			/*nb of bytes of the SPIReadPage response*/
#define EM4325_SPI_RES_NBBYTE_READREGFILEWORD	0x03			/*nb of bytes of the response to the command SPIReadRegisterFileWord*/
#define EM4325_SPI_RES_NBBYTE_WRITEREGFILEWORD	0x01			/*nb of bytes of the response to the command SPIWriteRegisterFileWord*/
#define EM4325_SPI_RES_NBBYTE_REQRN			0x03			/*nb of bytes of the response to the command SPIReqRN*/
#define EM4325_SPI_RES_NBBYTE_REQNEWHANDLE		0x06			/*nb of bytes of the response to the command SPIReqNewHandle*/
#define EM4325_SPI_RES_NBBYTE_SETHANDLE		0x01			/*nb of bytes of the response to the command SPISetHandle*/
#define EM4325_SPI_RES_NBBYTE_SETCOMMPARAMS	0x01			/*nb of bytes of the response to the command SPISetCommParams*/
#define EM4325_SPI_RES_NBBYTE_GETCOMMPARAMS	0x05			/*nb of bytes of the response to the command SPIGetCommParams*/
#define EM4325_SPI_RES_NBBYTE_GETNEWSENSORDATA	0x09			/*nb of bytes of the response to the command SPIGetSensorData (new sample case) */

#define EM4325_SPIMASK_REGISTERFILEWORD		0x07			/* mask of the Register file word parameter of the SPI readRegister fileWord command*/
#define EM4325_SPI_REGISTERFILENBWORD			0x08			/* numeber of word of the register file*/


#define EM4325_TRANSPONDERSTATE_MASK			0x40			/* transponder field of the response to the SPIRequestStatus */
#define EM4325_TRANSPONDERSTATE_SHIFT			0x06			/* transponder field of the response to the SPIRequestStatus */
#define EM4325_DEVICESTATESTATE_MASK			0x38			/* device state field of the response to the SPIRequestStatus */
#define EM4325_DEVICESTATESTATE_SHIFT			0x3				/* device state field of the response to the SPIRequestStatus */
#define EM4325_MEMORYSTATE_MASK				0x04			/* memory state field of the response to the SPIRequestStatus */
#define EM4325_MEMORYSTATE_SHIFT				0x2				/* memory state field of the response to the SPIRequestStatus */
#define EM4325_COMMMANDSTATE_MASK				0x03			/* command state field of the response to the SPIRequestStatus */
#define EM4325_COMMMANDSTATE_SHIFT				0x0				/* command state field of the response to the SPIRequestStatus */
#define EM4325_REGISTERADDDRESS_MASK			0x04			/* register address field of the response to the SPIRequestStatus */
#define EM4325_REGISTERADDDRESS_SHIFT			0x3F			/* register address field of the response to the SPIRequestStatus */


#define EM4325_MEASURETEMERATURE				(0x0400)
/* masks of the temperature in the "sensor data" MSW */
#define EM4325_MASK_TEMERATURE					(0x01FF)
#define EM4325_MASK_MSB_TEMERATURE				(0x00F0)
#define EM4325_MASK_LSB_TEMERATURE				(0x000F)
#define EM4325_MASK_NEG_TEMERATURE				(0x0100)
/* shifts of the temperature in the "sensor data" MSW */
#define EM4325_SHIFT_MSB_TEMERATURE			(4)
#define EM4325_SHIFT_LSB_TEMERATURE			(0)
#define EM4325_SHIFT_NEG_TEMERATURE			(8)
/* coefficients of the temperature in the "sensor data" MSW */
#define EM4325_COEF_MSB_TEMERATURE				(4)
#define EM4325_COEF_LSB_TEMERATURE				(0.25)
#define EM4325_COEF_NEG_TEMERATURE				(-1)
/* invalid measurement) */
#define EM4325_TEMERATURE_INVALID				(0b100000000)

#define EM4325_TEMERATURE_0_KELVIN				(-273)
/*===========================================================================================================
						Enum definition
===========================================================================================================*/
/**
 *  @enum em4325SPIcommandCode_enum
 *  @brief this enum contains EM4325 command set
 */
typedef enum {
	EM4325_SPI_CMD_REQUESTSTATUS =			0xE0,			/*!< command code of the SPIRequestStatus */
	EM4325_SPI_CMD_BOOT =					0xE1,			/*!< command code of the SPI BOOT */
	EM4325_SPI_CMD_ENABLETRANSPONDER =		0xE2,			/*!< command code of the SPITransponder */
	EM4325_SPI_CMD_DISABLETRANSPONDER =	0xE3,			/*!< command code of the SPITransponder */
	EM4325_SPI_CMD_GETSENSORDATA		 =	0xE4,			/*!< command code of the GetSensorData */
	EM4325_SPI_CMD_GETSENSORDATAAFTERNEW =	0xE5,			/*!< command code of the GetSensorDataAfter new sample */
	EM4325_SPI_CMD_READPAGE =				0xE9,			/*!< command code of the SPIReadPage */
	EM4325_SPI_CMD_GETNEWSENSORDATA =		0xE5,			/*!< command code of the Get sensor data after new sample */
	EM4325_SPI_CMD_SETFLAGS =				0xE6,			/*!< command code of the SPISetFlags*/
	EM4325_SPI_CMD_READWORD =				0xE7,			/*!< command code of the SPIReadWord*/
	EM4325_SPI_CMD_WRITEWORD =				0xE8,			/*!< command code of the SPIWriteWord*/
	EM4325_SPI_CMD_READREGFILEWORD =		0xEE,			/*!< command code of the SPIReadRegisterFileWord*/
	EM4325_SPI_CMD_WRITEREGFILEWORD =		0xEF,			/*!< command code of the SPIWriteRegisterFileWord*/
	EM4325_SPI_CMD_REQRN =					0xF0,			/*!< command code of the SPIReqRN*/
	EM4325_SPI_CMD_REQNEWHANDLE =			0xF1,			/*!< command code of the SPIReqNewHandle*/
	EM4325_SPI_CMD_SETHANDLE =				0xF2,			/*!< command code of the SPISetHandle*/
	EM4325_SPI_CMD_SETCOMMPARAMS =			0xF3,			/*!< command code of the SPISetCommParams*/
	EM4325_SPI_CMD_GETCOMMPARAMS =			0xF4,			/*!< command code of the SPIGetCommParams*/
}em4325SPIcommandCode_enum;