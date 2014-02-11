/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               Se955DLL.h
** Latest modified Date:    2011-04-16
** Latest Version:          V1.00
** Descriptions:            Se955�����ͷ�ļ�(Ӧ�ó���ר��)
**
**--------------------------------------------------------------------------------------------------------
** Created by:              �� ��
** Created date:            2011-04-16
** Version:                 V1.00
** Descriptions:            ԭʼ�汾
**
**--------------------------------------------------------------------------------------------------------
** Modified by:                  
** Modified date:           
** Version:                 
** Descriptions:           
**
*********************************************************************************************************/
#ifndef    __Se955DLL_H
#define    __Se955DLL_H

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
#define    SUCCESS_SETTING      47                                     /* �ɹ�����                      */
#define    SEND_OK              48                                     /* ���ͳɹ�                      */
#define    CREATETHREADFAIL     49                                     /* �����߳�ʧ��                  */
#define    INIT_OK              50                                     /* ��ʼ���ɹ�                    */
#define    DATA_ISNULL          51                                     /* ����������Ϊ��                */ 
#define    RECEIVE_SUCCESS      52                                     /* �Ӷ����л�ȡ���ݳɹ�          */         
#define    DATA_ERR_SELECT      53                                     /* ��������ѡ��                  */
#define    ACK_SUCCESS          54                                     /* Ӧ��ɹ�                      */
#define    ACK_FAILED           55                                     /* Ӧ��ʧ��                      */
#define    MODE_FAILED          56                                     /* ģʽ���ô���                  */
#define    IS_WRITING           57                                     /* ��������д�룬���ܶ�ȡ        */ 

/*********************************************************************************************************
  ������ʹ�ܲ�����(����ʵ�ָ��ֱ�����������ʹ�������,Ĭ��Ϊȫ��ʹ��)
*********************************************************************************************************/
#define    UPCA_CODE            0x01                                    /* UPC_A�������                */
#define    UPCE_CODE            0x02                                    /* UPC_E�������                */
#define    UPCE1_CODE           0x0C                                    /* UPC_E1�������               */
#define    EAN8_CODE            0x04                                    /* EAN8�������                 */
#define    EAN13_CODE           0x03                                    /* EAN13�������                */
#define    CODE128              0x08                                    /* CODE128�������              */
#define    EAN_128              0x0E                                    /* EAN_128�������              */
#define    EISBT_128            0x54                                    /* EISBT_128�������            */
#define    CODE39               0x00                                    /* CODE39�������               */
#define    TRIOPTIC_CODE39      0x0D                                    /* TRIOPTIC_CODE39�������      */
#define    CODE93               0x09                                    /* CODE93�������               */
#define    CODE11               0x0A                                    /* CODE11�������               */
#define    INTERLEAVED          0x06                                    /* INTERLEAVED 2 OF 5�������   */
#define    DISCRETE             0x05                                    /* DISCRETE 2 OF 5�������      */
#define    CODABAR              0x07                                    /* CODABAR�������              */
#define    TRANMITFORMAT        0xEB                                    /* CODABAR�������              */
#define    BOOKLANDEAN          0x53                                    /* BOOKLANDEAN�������          */

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
  SE955�Ĳ����ʱ���
*********************************************************************************************************/
#define    B_RATE300            0x01                                    /* ������300                    */
#define    B_RATE600            0x02                                    /* ������600                    */
#define    B_RATE1200           0x03                                    /* ������1200                   */
#define    B_RATE2400           0x04                                    /* ������2400                   */
#define    B_RATE4800           0x05                                    /* ������4800                   */
#define    B_RATE9600           0x06                                    /* ������9600                   */
#define    B_RATE19200          0x07                                    /* ������19200                  */
#define    B_RATE38400          0x08                                    /* ������38400                  */

/*********************************************************************************************************
  Se955��żУ��λ�����궨��
*********************************************************************************************************/
#define	   DAT_ODD              0x00   	                                /* ��У��                       */
#define	   DAT_EVEN             0x01   		                            /* żУ��                       */
#define	   DAT_MARK             0x02  	                                /* ���У��                     */
#define	   DAT_SPACE            0x03                                    /* �ո�У��                     */
#define	   DAT_NONE             0x04		                            /* ��У�� (default)	            */

/*********************************************************************************************************
  Se955ֹͣλ�����궨��
*********************************************************************************************************/
#define	   STOP_BITONE          0x01		                            /* ֹͣλ1λ                    */
#define	   STOP_BITTWO          0x02		                            /* ֹͣλ2λ	                */

/*********************************************************************************************************
  ������ʽ�����궨��
*********************************************************************************************************/
#define    SCAN_HOST            0x08                                   /* ���ģʽ                      */
#define    SCAN_LEVEL           0x00                                   /* Ӳ��ģʽ��ƽ����              */
#define    SCAN_CONTINUE        0x04                                   /* ����ɨ��                      */
#define    SCAN_PULSE           0x02                                   /* Ӳ��ģʽ���崥��              */

/*********************************************************************************************************
** Function name:           Se955SerialInit
** Descriptions:            ���ڽ������ݳ�ʼ��                         
** input parameters:        ucPort         ���ں�,��COM1,COM2
**							ucBaud         ����������
**							ucStop		   ֹͣλ����
**							ucParity	   У��λ����
** output parameters:       NONE
** 
** Returned value:          ��ȷ����INIT_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô���
**                          ����COM_ERR_TIME, �����Ѵ򿪷���COM_ERR_USING, 
**							���ڴ򿪴���COM_ERR_OPEN,���ڽ����̴߳���ʧ�ܷ���CREATETHREADFAIL.
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955SerialInit(UCHAR ucPort, UCHAR ucBaud, UCHAR ucStop, UCHAR ucParity);






/*********************************************************************************************************
** Function name:           Se955SerialTerminate
** Descriptions:            Se955ͨ����ֹ                         
** input parameters:        NONE													
** output parameters:       NONE
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
*********************************************************************************************************/
extern "C" __declspec(dllexport)  BOOL Se955SerialTerminate(void);







/*********************************************************************************************************
** Function name:           Se955AimState
** Descriptions:            ����Se955��׼��ȡ����׼                         
** input parameters:        bAimState         ��׼״̬(ֵΪTRUEʱ����׼
**                                                     ֵΪFALSEʱ��ȡ����׼)
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955AimState(BOOL bAimState);







/*********************************************************************************************************
** Function name:           Se955DecodeState
** Descriptions:            ��ʼɨ�����롢ֹͣɨ������                         
** input parameters:        bDecodeState       ɨ������״̬(ֵΪTRUEʱ����ʼɨ������
**                                                          ֵΪFALSEʱ��ֹͣɨ������)
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955DecodeState(BOOL bDecodeState);








/*********************************************************************************************************
** Function name:           Se955ScanningState
** Descriptions:            ʹ��ɨ�衢����ɨ��                         
** input parameters:        bScanningState        ʹ��״̬(ֵΪTRUEʱ��ʹ��ɨ��
**                                                         ֵΪFALSEʱ������ɨ��)
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955ScanningState(BOOL bScanningState);







/*********************************************************************************************************
** Function name:           Se955LedState
** Descriptions:            ��������LED��������                         
** input parameters:        bLedState         LED״̬(ֵΪTRUEʱ��LED����
**                                                    ֵΪFALSEʱ��LED����)
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955LedState(BOOL bLedState);








/*********************************************************************************************************
** Function name:           Se955TriggerState
** Descriptions:            ������ʽ����                         
** input parameters:        ucTriggerState          ������ʽ(ֵΪSCAN_LEVELʱ��Ӳ����ƽ����ɨ��
**                                                           ֵΪSCAN_PULSEʱ��Ӳ�����崥��ɨ��
**                                                           ֵΪSCAN_HOSTʱ�� �������ɨ��
**                                                           ֵΪSCAN_CONTINUEʱ����������ɨ��)                                                      
**														
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955TriggerState(UCHAR ucTriggerState);








/*********************************************************************************************************
** Function name:           GetDecodeData
** Descriptions:            ��������������                         
** input parameters:        NONE														
** output parameters:       pucReceiveBuf   �������ݻ�����ָ��
**							pucCount        �������ݸ���ָ��
** Returned value:          ��ȷ����RECEIVE_SUCCESS
**							����������Ϊ�շ���DATA_ISNULL.
*********************************************************************************************************/
extern "C" __declspec(dllexport)  int Se955GetDecodeData(BYTE *pucRecieveBuf, BYTE *pucCount);








/*********************************************************************************************************
** Function name:           Se955GetVersion
**
** Descriptions:            ��ȡSe955������汾��
**                          
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ���ص�ǰ������汾��.
**                          (����100����ʾV1.00������110����ʾV1.10......)
*********************************************************************************************************/
extern "C" __declspec(dllexport) DWORD Se955GetVersion (void);







/*********************************************************************************************************
** Function name:           Se955CodeBarEnable
** Descriptions:            ����������ʹ�ܡ�����                         
** input parameters:        ucCodeBar           �����������
**                          ucEnable            ʹ�������(ENABLE��ʾʹ�ܣ�DISABLE��ʾ����)
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport) int Se955CodeBarEnable(UCHAR ucCodeBar, UCHAR ucEnable);




/*********************************************************************************************************
** Function name:           Se955FactorySettings
** Descriptions:            Se955�ָ���������                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
extern "C" __declspec(dllexport) int Se955FactorySettings(void);



#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/



