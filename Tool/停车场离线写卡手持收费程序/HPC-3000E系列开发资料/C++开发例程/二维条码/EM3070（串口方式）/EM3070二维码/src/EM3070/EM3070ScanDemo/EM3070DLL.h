/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               EM3070DLL.h
** Latest modified Date:    2012-04-16
** Latest Version:          V1.01
** Descriptions:            EM3070�����ͷ�ļ�(Ӧ�ó���ר��)
**
*********************************************************************************************************/
#ifndef    __EM3070DLL_H
#define    __EM3070DLL_H

#if defined(__cplusplus)
extern "C"
{
#endif


#ifdef EM3070DLL_API				// Linked as a DLL
#define EM3070DLL_API		__declspec(dllimport)
#else
#define EM3070DLL_API		__declspec(dllexport)
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
#define	   PREX_FAILED			62									   /* ����β�ַ�ʧ��					*/
#define	   FACTORY_FAILED		63									   /* �ָ���������ʧ��					*/


/*********************************************************************************************************
  ������ʹ�ܲ�����(EM3070Ĭ��������������ƾ�ʹ��)
*********************************************************************************************************/
#define    CODE128				0                                     /* CODE 128�������              */
#define    EAN_8				1                                     /* EAN-8�������           */
#define    EAN_13				2                                     /* EAN-13�������               */
#define    UPC_E				3                                     /* UPC_E�������                 */
#define    UPC_A				4                                     /* UPC_A�������                */
#define    INTERLEAVED2OF5		5                                     /* INTERLEAVED2OF5�������                  */
#define    MATRIX2OF5			6                                     /* ISBN�������                  */      
#define    CODE39				7                                    /* ITF-14�������                */
#define    CODABAR              8                                    /* Deutsche 14�������           */
#define    CODE93               9                                    /* Deutsche 12�������           */
#define    UCCEAN_128			10                                    /* COOP 25�������               */
#define    GS1DATABAR           11                                    /* Matrix 2 of 5�������         */
#define    EANUCCCOMPOSITE      12                                    /* Industrial 25�������         */
#define    UPCEANCOMPOSITE      13                                    /* Standard 25�������           */
#define    CODE11				14                                    /* Code 39�������               */
#define    ISBN				    15                                    /* Codabar�������               */
#define    Industrial_25		16                                    /* Code 93�������               */
#define    Standard_25			17                                    /* Code 11�������               */
#define    PLESSEY				18                                    /* Plessey�������               */
#define    MSI_PLESSEY          19                                    /* MSI-Plessey�������           */
#define    PDF_417              20                                    /* GS1 Databar�������           */
#define    QR_CODE              21                                    /* GS1 Databar�������           */
#define    AZTEC                22                                    /* GS1 Databar�������           */
#define    DATAMATRIX           23                                    /* GS1 Databar�������           */
#define    CHINESESENSECODE     24                                    /* GS1 Databar�������           */
#define    MAXICODE             25                                    /* GS1 Databar�������           */

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
#define	   SCAN_MANUAL		    00						               /* �ֶ�ɨ��ģʽ					*/
#define    SCAN_AUTO            10                                     /* �Զ�ɨ��ģʽ					*/
#define    SCAN_CONTINUE        20                                     /* ����ɨ��ģʽ					*/
#define    SCAN_SINGLE          30                                  /* ��������ɨ��ģʽ					*/

/*********************************************************************************************************
** Function name:           EM3070SerialInit
** Descriptions:            ���ڽ������ݳ�ʼ��                         
** input parameters:        ucPort         ���ں�,��COM1,COM2
** output parameters:       NONE
** 
** Returned value:          ��ȷ����INIT_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô���
**                          ����COM_ERR_TIME, �����Ѵ򿪷���COM_ERR_USING, 
**							���ڴ򿪴���COM_ERR_OPEN,���ڽ����̴߳���ʧ�ܷ���CREATETHREADFAIL.
*********************************************************************************************************/
EM3070DLL_API  int EM3070SerialInit(unsigned char ucPort);






/*********************************************************************************************************
** Function name:           EM3070SerialTerminate
** Descriptions:            EM3070ͨ����ֹ                         
** input parameters:        NONE													
** output parameters:       NONE
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
*********************************************************************************************************/
EM3070DLL_API  bool EM3070SerialTerminate(void);







/*********************************************************************************************************
** Function name:           EM3070DecodeState
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
EM3070DLL_API  int EM3070DecodeState(bool bDecodeState);









/*********************************************************************************************************
** Function name:           EM3070TriggerState
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
EM3070DLL_API  int EM3070TriggerState(unsigned char TriggerState);








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
EM3070DLL_API  int EM3070GetDecodeData(unsigned char *pucRecieveBuf, unsigned char *pucCount);








/*********************************************************************************************************
** Function name:           EM3070GetVersion
**
** Descriptions:            ��ȡEM3070������汾��
**                          
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ���ص�ǰ������汾��.
**                          (����100����ʾV1.00������110����ʾV1.10......)
*********************************************************************************************************/
EM3070DLL_API unsigned int EM3070GetVersion (void);







/*********************************************************************************************************
** Function name:           EM3070CodeBarEnable
** Descriptions:            ����������ʹ�ܡ�����                         
** input parameters:        ucCodeBar           �����������
**                          ucEnable            ʹ�������(ENABLE��ʾʹ�ܣ�DISABLE��ʾ����)
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
**                          �������������Ʋ�֧�ַ���CODEBARNOTSUPPORT
*********************************************************************************************************/
EM3070DLL_API int EM3070CodeBarEnable(unsigned char ucCodeBar, unsigned char ucEnable);





/*********************************************************************************************************
** Function name:           EM3070CodeBarRestoreSetting
** Descriptions:            ���������������� 
**                           
** input parameters:        ucCodeBar           �����������
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
**                          �������������Ʋ�֧�ַ���CODEBARNOTSUPPORT
*********************************************************************************************************/
EM3070DLL_API int EM3070CodeBarRestoreSetting(unsigned char ucCodeBar);






/*********************************************************************************************************
** Function name:           EM3070FactorySettings
** Descriptions:            EM3070�ָ���������                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,
**							���ͳɹ��յ�ʧ��Ӧ��ACK_FAILED
**                          ����δ�յ�Ӧ�𷵻�ACK_TIMEOUT
*********************************************************************************************************/
EM3070DLL_API int EM3070FactorySettings(void);







/*********************************************************************************************************
** Function name:           EM3070SpecialCommand
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
EM3070DLL_API int EM3070SpecialCommand(char cmd[],int length);


#if defined(__cplusplus)
}
#endif

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/



