/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               EM1300DLL.h
** Latest modified Date:    2012-04-16
** Latest Version:          V1.01
** Descriptions:            EM1300�����ͷ�ļ�(Ӧ�ó���ר��)
**
*********************************************************************************************************/
#ifndef    __EM1300DLL_H
#define    __EM1300DLL_H

#if defined(__cplusplus)
extern "C"
{
#endif


#ifdef EM1300DLL_API				// Linked as a DLL
#define EM1300DLL_API		__declspec(dllimport)
#else
#define EM1300DLL_API		__declspec(dllexport)
#endif

/*********************************************************************************************************
  ���ڲ������󷵻�ֵ����
*********************************************************************************************************/
#define    COM_OK               0                                      /* ���ڴ򿪳ɹ�                  */
#define    COM_ERR_PARA         41                                     /* ���ڲ������ô���              */
#define    COM_ERR_TIME         42                                     /* ��ʱ�������ô���              */
#define    COM_ERR_USING        43                                     /* �����Ѿ���ʹ��                */
#define    COM_ERR_OPEN         44                                     /* ���ڴ򿪴���                  */                          
#define    COM_NOTOPEN          45                                     /* ����δ��                    */                                  

/*********************************************************************************************************
  ��д���ݲ�������ֵ����
*********************************************************************************************************/
#define    SUCCESS_SETTING      47                                     /* �ɹ�����						*/
#define    SEND_OK              48                                     /* ���ͳɹ�						*/
#define    CREATETHREADFAIL     49                                     /* �����߳�ʧ��					*/
#define    INIT_OK              50                                     /* ��ʼ���ɹ�						*/
#define    DATA_ISNULL          51                                     /* ����������Ϊ��					*/ 
#define    RECEIVE_SUCCESS      52                                     /* �Ӷ����л�ȡ���ݳɹ�				*/         
#define    DATA_ERR_SELECT      53                                     /* ��������ѡ��					*/
#define    ACK_SUCCESS          54                                     /* Ӧ��ɹ�						*/
#define    ACK_FAILED           55                                     /* Ӧ��ʧ��						*/
#define    MODE_FAILED          56                                     /* ģʽ���ô���					*/
#define    IS_WRITING           57                                     /* ��������д�룬���ܶ�ȡ			*/ 
#define    UNDEFINE             58                                     /* �޷���������					*/
#define    SYSTEMNOSAFE         59                                     /* �ǰ�ȫϵͳ						*/
#define	   TAIL_FAILED			60									   /* ����β�ַ�ʧ��					*/
#define	   SCANMODENOTSUPPORT	61									   /* ɨ��ģʽ��֧��					*/
#define	   CODEBARNOTSUPPORT	61									   /* ɨ��ģʽ��֧��					*/
#define    ACK_TIMEOUT          55                                     /* Ӧ��ʱ						*/

/*********************************************************************************************************
  ������ʹ�ܲ�����(����ʵ�ָ��ֱ�����������ʹ�������)
*********************************************************************************************************/
#define    CODE128				0                                     /* CODE 128�������              */
#define    EAN_128				1                                     /* UCC/EAN-128�������           */
#define    AIM_128				2                                     /* AIM 128�������               */
#define    EAN_8				4                                     /* EAN-8�������                 */
#define    EAN_13				5                                     /* EAN-13�������                */
#define    ISSN					6                                     /* ISSN�������                  */
#define    ISBN					7                                     /* ISBN�������                  */
#define    UPC_E				8                                     /* UPC_E�������                 */
#define    UPC_A				9                                     /* UPC_A�������                 */
#define    INTERLEAVED2OF5		10                                    /* Interleaved 2 of 5�������    */
#define    ITF_6				11                                    /* ITF-6�������                 */
#define    ITF_14				12                                    /* ITF-14�������                */
#define    DEUTSCHE14           13                                    /* Deutsche 14�������           */
#define    DEUTSCHE12           14                                    /* Deutsche 12�������           */
#define    COOP25				15                                    /* COOP 25�������               */
#define    MATRIX2OF5           16                                    /* Matrix 2 of 5�������         */
#define    INDUSTRIAL25         17                                    /* Industrial 25�������         */
#define    STANDARD25           18                                    /* Standard 25�������           */
#define    CODE39				20                                    /* Code 39�������               */
#define    CODABAR				21                                    /* Codabar�������               */
#define    CODE93				22                                    /* Code 93�������               */
#define    CODE11				23                                    /* Code 11�������               */
#define    PLESSEY				24                                    /* Plessey�������               */
#define    MSI_PLESSEY          25                                    /* MSI-Plessey�������           */
#define    GS1DATABAR           26                                    /* GS1 Databar�������           */


/*********************************************************************************************************
  ������ʹ�������
*********************************************************************************************************/
#define    ENABLE               0x01                                    /* ʹ��                         */
#define    DISABLE              0x00                                    /* ����                         */



/*********************************************************************************************************
  ���ںŲ����궨��
*********************************************************************************************************/
#define    COM1                 0
#define    COM2                 1
#define    COM3                 2
#define    COM4                 3
#define    COM5                 4
#define    COM6                 5
#define    COM7                 6
#define    COM8                 7
#define    COM9                 8

/*********************************************************************************************************
  ������ʽ�����궨��
*********************************************************************************************************/
#define	   SCAN_INTERVAL		12						               /* ���ɨ��ģʽ					*/
#define    SCAN_PERCEIVE        13                                     /* ��Ӧɨ��ģʽ					*/
#define    SCAN_CONTINUE        14                                     /* ����ɨ��ģʽ					*/
#define	   SCAN_LAZYPERCEIVE	15                                     /* �ӳٸ�Ӧɨ��ģʽ				*/
#define    SCAN_SINGLE          16                                     /* ����ɨ��ģʽ					*/

/*********************************************************************************************************
** Function name:           EM1300SerialInit
** Descriptions:            ���ڽ������ݳ�ʼ��                         
** input parameters:        ucPort         ���ں�,��COM1,COM2
** output parameters:       NONE
** 
** Returned value:          ��ȷ����INIT_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô���
**                          ����COM_ERR_TIME, �����Ѵ򿪷���COM_ERR_USING, 
**							���ڴ򿪴���COM_ERR_OPEN,���ڽ����̴߳���ʧ�ܷ���CREATETHREADFAIL.
*********************************************************************************************************/
EM1300DLL_API  int EM1300SerialInit(unsigned char ucPort);






/*********************************************************************************************************
** Function name:           EM1300SerialTerminate
** Descriptions:            EM1300ͨ����ֹ                         
** input parameters:        NONE													
** output parameters:       NONE
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
*********************************************************************************************************/
EM1300DLL_API  bool EM1300SerialTerminate(void);







/*********************************************************************************************************
** Function name:           EM1300DecodeState
** Descriptions:            ��ʼɨ�����롢ֹͣɨ������                         
** input parameters:        bDecodeState       ɨ������״̬(ֵΪtrueʱ����ʼɨ������
**                                                          ֵΪfalseʱ��ֹͣɨ������)
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
*********************************************************************************************************/
EM1300DLL_API  int EM1300DecodeState(bool bDecodeState);









/*********************************************************************************************************
** Function name:           EM1300TriggerState
** Descriptions:            ������ʽ����                         
** input parameters:        ucTriggerState          ������ʽ(ֵΪSCAN_INTERVALʱ�����ɨ��ģʽ
**                                                           ֵΪSCAN_PERCEIVEʱ����Ӧɨ��ģʽ
**                                                           ֵΪSCAN_CONTINUEʱ�� ����ɨ��ģʽ
**                                                           ֵΪSCAN_LAZYPERCEIVEʱ�� �ӳٸ�Ӧɨ��ģʽ
**                                                           ֵΪSCAN_SINGLEʱ������ɨ��ģʽ)                                                      
**														
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ڲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
**							���ߴ���ɨ��ģʽ��֧�ַ���SCANMODENOTSUPPORT
*********************************************************************************************************/
EM1300DLL_API  int EM1300TriggerState(unsigned char TriggerState);








/*********************************************************************************************************
** Function name:           GetDecodeData
** Descriptions:            ��������������                         
** input parameters:        NONE														
** output parameters:       pucReceiveBuf   �������ݻ�����ָ��
**							pucCount        �������ݸ���ָ��
** Returned value:          ��ȷ����RECEIVE_SUCCESS
**							����������Ϊ�շ���DATA_ISNULL
**                          ��������д�޷���ȡʱ����IS_WRITING.
*********************************************************************************************************/
EM1300DLL_API  int EM1300GetDecodeData(unsigned char *pucRecieveBuf, unsigned char *pucCount);








/*********************************************************************************************************
** Function name:           EM1300GetVersion
**
** Descriptions:            ��ȡEM1300������汾��
**                          
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ���ص�ǰ������汾��.
**                          (����100����ʾV1.00������110����ʾV1.10......)
*********************************************************************************************************/
EM1300DLL_API unsigned int EM1300GetVersion (void);







/*********************************************************************************************************
** Function name:           EM1300CodeBarEnable
** Descriptions:            ����������ʹ�ܡ�����                         
** input parameters:        ucCodeBar           �����������
**                          ucEnable            ʹ�������(ENABLE��ʾʹ�ܣ�DISABLE��ʾ����)
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
**                          �������������Ʋ�֧�ַ���CODEBARNOTSUPPORT
*********************************************************************************************************/
EM1300DLL_API int EM1300CodeBarEnable(unsigned char ucCodeBar, unsigned char ucEnable);





/*********************************************************************************************************
** Function name:           EM1300CodeBarRestoreSetting
** Descriptions:            ���������������� 
**                           
** input parameters:        ucCodeBar           �����������
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
**                          �������������Ʋ�֧�ַ���CODEBARNOTSUPPORT
*********************************************************************************************************/
EM1300DLL_API int EM1300CodeBarRestoreSetting(unsigned char ucCodeBar);






/*********************************************************************************************************
** Function name:           EM1300FactorySettings
** Descriptions:            EM1300�ָ���������                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
*********************************************************************************************************/
EM1300DLL_API int EM1300FactorySettings(void);







/*********************************************************************************************************
** Function name:           EM1300SpecialCommand
** Descriptions:            ����ӿ�,����������Ҫ,������δ�ṩ�Ĺ���ʵ��                         
** input parameters:        cmd					�����ַ���
**							length				�����
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
*********************************************************************************************************/
EM1300DLL_API int EM1300SpecialCommand(char cmd[],int length);


#if defined(__cplusplus)
}
#endif

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/



