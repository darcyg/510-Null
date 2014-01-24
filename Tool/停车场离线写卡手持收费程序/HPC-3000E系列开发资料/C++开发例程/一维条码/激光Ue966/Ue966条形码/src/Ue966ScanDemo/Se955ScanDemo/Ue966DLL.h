/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               Ue966DLL.h
** Latest modified Date:    2011-04-16
** Latest Version:          V1.00
** Descriptions:            Ue966�����ͷ�ļ�(Ӧ�ó���ר��)
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
#ifndef    __Ue966DLL_H
#define    __Ue966DLL_H

#if defined(__cplusplus)
extern "C"
{
#endif


#ifdef Ue966DLL_API				// Linked as a DLL
#define Ue966DLL_API		__declspec(dllimport)
#else
#define Ue966DLL_API		__declspec(dllexport)
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
#define    UNDEFINE             58                                     /* �޷���������                  */
#define    SYSTEMNOSAFE         59                                     /* �ǰ�ȫϵͳ                    */
#define    TAIL_FAILED          60                                     /* �ǰ�ȫϵͳ                    */

/*********************************************************************************************************
  ������ʹ�ܲ�����(����ʵ�ָ��ֱ�����������ʹ�������)
*********************************************************************************************************/
#define    UPCA_CODE            0x01                                    /* UPC_A�������                */
#define    UPCE_CODE            0x02                                    /* UPC_E�������                */
#define    UPCE1_CODE           0x0C                                    /* UPC_E1�������               */
#define    EAN8_CODE            0x04                                    /* EAN8�������                 */
#define    EAN13_CODE           0x03                                    /* EAN13�������                */
#define    BOOKLANDEAN          0x53                                    /* BOOKLANDEAN�������          */
#define    CODE128              0x08                                    /* CODE128�������              */
#define    EAN_128              0x0E                                    /* EAN_128�������              */
#define    ISBT_128             0x54                                    /* ISBT_128�������            */
#define    CODE39               0x00                                    /* CODE39�������               */
#define    TRIOPTIC_CODE39      0x0D                                    /* TRIOPTIC_CODE39�������      */
#define    CODE39_FULL          0x11                                    /* CODE39 FULL ASCII�������    */
#define    CODE93               0x09                                    /* CODE93�������               */
#define    CODE11               0x0A                                    /* CODE11�������               */
#define    INTERLEAVED          0x06                                    /* INTERLEAVED 2 OF 5�������   */
#define    DISCRETE             0x05                                    /* DISCRETE 2 OF 5�������      */
#define    CODABAR              0x07                                    /* CODABAR�������              */
#define    MSI                  0x0B                                    /* MSI�������                  */
#define    CHINESE_2OF5         0xFF                                    /* CHINESE 2 OF 5�������       */
#define    RSS_14               0xFE                                    /* RSS_14�������               */
#define    RSS_LIMITED          0xFD                                    /* RSS_LIMITED�������          */
#define    RSS_EXPANDED         0xFC                                    /* RSS_EXPANDED�������         */


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
  Ue966�Ĳ����ʱ���
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
  Ue966��żУ��λ�����궨��
*********************************************************************************************************/
#define	   DAT_ODD              0x00   	                                /* ��У��                       */
#define	   DAT_EVEN             0x01   		                            /* żУ��                       */
#define	   DAT_MARK             0x02  	                                /* ���У��                     */
#define	   DAT_SPACE            0x03                                    /* �ո�У��                     */
#define	   DAT_NONE             0x04		                            /* ��У�� (default)	            */

/*********************************************************************************************************
  Ue966ֹͣλ�����궨��
*********************************************************************************************************/
#define	   STOP_BITONE          0x01		                            /* ֹͣλ1λ                    */
#define	   STOP_BITTWO          0x02		                            /* ֹͣλ2λ	                */

/*********************************************************************************************************
  ������ʽ�����궨��
*********************************************************************************************************/
#define    SCAN_HOST            0x08                                   /* ���ģʽ                      */
#define    SCAN_CONTINUE        0x04                                   /* ����ɨ��                      */

/*********************************************************************************************************
** Function name:           Ue966SerialInit
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
Ue966DLL_API  int Ue966SerialInit(unsigned char ucPort, unsigned char ucBaud, unsigned char ucStop, unsigned char ucParity);






/*********************************************************************************************************
** Function name:           Ue966SerialTerminate
** Descriptions:            Ue966ͨ����ֹ                         
** input parameters:        NONE													
** output parameters:       NONE
** Returned value:          �����ɹ�����true, ����ʧ�ܷ���false.
*********************************************************************************************************/
Ue966DLL_API  bool Ue966SerialTerminate(void);








/*********************************************************************************************************
** Function name:           Ue966DecodeState
** Descriptions:            ��ʼɨ�����롢ֹͣɨ������                         
** input parameters:        bDecodeState       ɨ������״̬(ֵΪtrueʱ����ʼɨ������
**                                                          ֵΪfalseʱ��ֹͣɨ������)
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
Ue966DLL_API  int Ue966DecodeState(bool bDecodeState);









/*********************************************************************************************************
** Function name:           Ue966TriggerState
** Descriptions:            ������ʽ����                         
** input parameters:        ucTriggerState          ������ʽ( ֵΪSCAN_HOSTʱ�� �������ɨ��
**                                                           ֵΪSCAN_CONTINUEʱ����������ɨ��)                                                      
**														
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
Ue966DLL_API  int Ue966TriggerState(unsigned char ucTriggerState);








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
Ue966DLL_API  int Ue966GetDecodeData(unsigned char *pucRecieveBuf, unsigned char *pucCount);








/*********************************************************************************************************
** Function name:           Ue966GetVersion
**
** Descriptions:            ��ȡUe966������汾��
**                          
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ���ص�ǰ������汾��.
**                          (����100����ʾV1.00������110����ʾV1.10......)
*********************************************************************************************************/
Ue966DLL_API unsigned int Ue966GetVersion (void);







/*********************************************************************************************************
** Function name:           Ue966CodeBarEnable
** Descriptions:            ����������ʹ�ܡ�����                         
** input parameters:        ucCodeBar           �����������
**                          ucEnable            ʹ�������(ENABLE��ʾʹ�ܣ�DISABLE��ʾ����)
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
Ue966DLL_API int Ue966CodeBarEnable(unsigned char ucCodeBar, unsigned char ucEnable);





/*********************************************************************************************************
** Function name:           Ue966CodeBarSetLength
** Descriptions:            ���������볤�� 
**                           
** input parameters:        ucCodeBar           �����������
**                          ucLength1           ����1
**                          ucLength2           ����2
**                                              ���ֻҪ����һ���ض�����,��ucLength1����Ϊ��Ҫ�ĳ���,
**                                              ucLength2����Ϊ0;
**                                              �����Ҫ���������ض�����,��ֱ����ú�ucLength1��ucLength2,
**                                              ��ʱ,ucLength1�������ucLength2;
**                                              �����Ҫ�������䳤��,��ֱ����ú�ucLength1��ucLength2
**                                              ucLength1����С��ucLength2,���ȷ�ΧΪucLength1��ucLength2;
**                                              �����Ҫ�������ⳤ��,��ucLength1��ucLength2������Ϊ0
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED 
*********************************************************************************************************/
Ue966DLL_API int Ue966CodeBarSetLength(unsigned char ucCodeBar, unsigned char ucLength1, unsigned char ucLength2);






/*********************************************************************************************************
** Function name:           Ue966FactorySettings
** Descriptions:            Ue966�ָ���������                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          �ɹ����÷���SUCCESS_SETTING, ����δ�򿪷���COM_NOTOPEN,
**							���ںŲ������󷵻�COM_ERR_SELECT,���ͳɹ��յ�ʧ��Ӧ��
**                          ����δ�յ�Ӧ�𷵻�ACK_FAILED	
*********************************************************************************************************/
Ue966DLL_API int Ue966FactorySettings(void);



#if defined(__cplusplus)
}
#endif

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/



