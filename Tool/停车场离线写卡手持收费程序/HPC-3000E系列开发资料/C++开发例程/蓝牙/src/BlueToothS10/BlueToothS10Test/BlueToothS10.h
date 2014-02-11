// BlueToothS10.h : BlueToothS10 DLL ����ͷ�ļ�
//

#pragma once


#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef BlueToothS10_API
#define BlueToothS10_API __declspec(dllimport)
#else
#define BlueToothS10_API __declspec(dllexport)
#endif

/*********************************************************************************************************
**	��������ֵ����
*********************************************************************************************************/
#define SUCCESS_SETTING				0
#define SYSTEMNOTSUPPORT			1
#define COMNOTOPEN					5
#define COMISUSING					6
#define COMOPENERROR				7
#define OPENDRIVEFAILED				2
#define OPERATIONMODENOTSUPPORT		3
#define ROLENOTSUPPORT				8
#define ENDFAILED					10
#define RECEIVETIMEOUT				11
#define RECEIVEEXCEPTION			12
#define ERROR_SETTING				13
#define FAILURE_SETTING				14
#define UNKNOWN_SETTING				15
#define PARAMINVALID				17
#define SETINQUIRECONFFAILED		18
#define DISC_LINK_LOSS				19
#define DISC_NO_SLC					20
#define DISC_TIMEOUT				21
#define DISC_ERROR					22
#define BUFFERTOOSMALL				23
#define SETTOATMODEFAILED			24
#define COMPARAMERROR				25
#define MODEERROR					26
#define SENDDATAERROR				27

//����ģʽ
enum S10_OperationMode		
{
	ATCommandMode,			//AT����ģʽ
	CommunicationMode		//ͨ��ģʽ
};

//����ģ���ɫ
enum S10_Role
{
	Slave,
	Master,
	Loopback
};

//����
enum S10_Coms
{
	COM1 = 1,
	COM2,
	COM3,
	COM4,
	COM5,	
	COM6,
	COM7,
	COM8
};

//���������豸�ṹ��
struct BlueToothDevice
{
	unsigned char addr[6];		//��ַ
	unsigned long deviceClass;	//�豸��
	short rssi;					//RSSI�ź�ǿ��
};


/*********************************************************************************************************
** Function name:           S10_GetDLLVersion
** Descriptions:            ��ȡ��̬���ӿ�汾��                   
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ���ض�̬���ӿ�汾�ţ�����100����ʾV1.00������110����ʾV1.10����
*********************************************************************************************************/
BlueToothS10_API int S10_GetDLLVersion();


/*********************************************************************************************************
** Function name:           S10_SetOperationMode
** Descriptions:            ���ô��ڲ���ģʽ                         
** input parameters:        mode       ����ģʽ
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			�ɹ�
**							OPENDRIVEFAILED			����������ʧ��
**							PARAMINVALID			����ģʽ��֧��
**							FAILURE_SETTING			���ò���ģʽʧ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetOperationMode(S10_OperationMode mode);



/*********************************************************************************************************
** Function name:           S10_Init
** Descriptions:            ��ʼ��                         
** input parameters:        com       ���ں�
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			��ʼ���ɹ�
**							COMPARAMERROR			���ڲ�������
**							SETTOATMODEFAILED		����AT����ģʽʧ��
**							COMISUSING				�����ѱ�ռ��
**							COMOPENERROR			���ڴ򿪴���
**							SYSTEMNOTSUPPORT		ϵͳ����ȫ
*********************************************************************************************************/
BlueToothS10_API int S10_Init(S10_Coms com);




/*********************************************************************************************************
** Function name:           S10_Close
** Descriptions:            �ر�����ͨ��                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			�رճɹ�
**							FAILURE_SETTING			�ر�ʧ��
*********************************************************************************************************/
BlueToothS10_API int S10_Close();


/*********************************************************************************************************
** Function name:           S10_Reboot
** Descriptions:            ��������ģ��                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_Reboot();


/*********************************************************************************************************
** Function name:           S10_GetModuleVersion
** Descriptions:            ��ȡ����ģ������汾��                   
** input parameters:        buf				�汾�ַ������뻺����ָ��              
**							bufLength		���뻺��������
** output parameters:       bufLength		�汾�ַ�������(���������ַ���
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							BUFFERTOOSMALL			����������̫С
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetModuleVersion(char buf[],unsigned int &bufLength);


/*********************************************************************************************************
** Function name:           S10_RestoreFactorySettings
** Descriptions				����ģ��ָ�����Ĭ������             
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_RestoreFactorySettings();


/*********************************************************************************************************
** Function name:           S10_GetAddress
** Descriptions:            ��ȡ����������ַ                   
** input parameters:        addr			������ַ���뻺����ָ��(6�ֽ�) 
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetAddress(unsigned char addr[]);



/*********************************************************************************************************
** Function name:           S10_SetDeviceName
** Descriptions				���������豸����              
** input parameters:        buf			�����豸�����ַ���ָ��
**						    bufLength	�ַ�������(���������ַ���
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetDeviceName(char buf[],unsigned int bufLength);



/*********************************************************************************************************
** Function name:           S10_GetDeviceName
** Descriptions:            ��ȡ�����豸����                   
** input parameters:        buf				�豸�������뻺����ָ��              
**							bufLength		���뻺��������
** output parameters:       bufLength		�豸�����ַ�������(���������ַ���
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							BUFFERTOOSMALL			����������̫С
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetDeviceName(char buf[],unsigned int &bufLength);



/*********************************************************************************************************
** Function name:           S10_GetRemoteDeviceName
** Descriptions:            ��ȡԶ�������豸����                   
** input parameters:        addr			Զ�������豸��ַ(6�ֽ�) 
**							buf				Զ���豸�������뻺����ָ��              
**							bufLength		���뻺��������
** output parameters:       bufLength		Զ���豸�����ַ�������(���������ַ���
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							BUFFERTOOSMALL			����������̫С
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetRemoteDeviceName(unsigned char addr[],char buf[],unsigned int &bufLength);



/*********************************************************************************************************
** Function name:           S10_SetRole
** Descriptions:            ��������ģ���ɫ                         
** input parameters:        role       ����ģ���ɫ
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							PARAMINVALID			ģ���ɫ��֧��
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetRole(S10_Role role);



/*********************************************************************************************************
** Function name:           S10_GetRole
** Descriptions:            ��ȡ����ģ���ɫ                   
** input parameters:        NONE
** output parameters:       role			����ģ���ɫ
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetRole(S10_Role &role);



/*********************************************************************************************************
** Function name:           S10_SetDeviceClass
** Descriptions:            ���������豸��                         
** input parameters:        deviceClass       �����豸��
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetDeviceClass(unsigned int deviceClass);



/*********************************************************************************************************
** Function name:           S10_GetDeviceClass
** Descriptions:            ��ȡ�����豸��                         
** input parameters:        NONE
** output parameters:       deviceClass       �����豸��
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetDeviceClass(unsigned int &deviceClass);



/*********************************************************************************************************
** Function name:           S10_SetAccessCode
** Descriptions:            ���ò�ѯ������                         
** input parameters:        accessCode       ��ѯ������
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetAccessCode(unsigned int accessCode);



/*********************************************************************************************************
** Function name:           S10_GetAccessCode
** Descriptions:            ��ȡ��ѯ������                         
** input parameters:        NONE
** output parameters:       accessCode       ��ѯ������
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetAccessCode(unsigned int &accessCode);



/*********************************************************************************************************
** Function name:           S10_SetMatchingCode
** Descriptions:            ���������                         
** input parameters:        buf				������ַ���ָ��                 
**							bufLength       ����볤��(���������ַ���
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetMatchingCode(char buf[],unsigned int bufLength);



/*********************************************************************************************************
** Function name:           S10_GetMatchingCode
** Descriptions:            ��ȡ�����                   
** input parameters:        buf				��������뻺����ָ��              
**							bufLength		���뻺��������
** output parameters:       bufLength		������ַ�������(���������ַ���
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							BUFFERTOOSMALL			����������̫С
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetMatchingCode(char buf[],unsigned int &bufLength);


/*********************************************************************************************************
** Function name:           S10_SetConnectMode
** Descriptions:            ��������ģʽ                         
** input parameters:        bBinding		�Ƿ�ʹ��ָ����������ģʽ��ͨ�����ð󶨵�ַ��    
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetConnectMode(bool bBinding);




/*********************************************************************************************************
** Function name:           S10_GetConnectMode
** Descriptions:            ��ȡ����ģʽ                         
** input parameters:        NONE    
** output parameters:       bBinding		�Ƿ�ʹ��ָ����������ģʽ��ͨ�����ð󶨵�ַ��
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetConnectMode(bool &bBinding);



/*********************************************************************************************************
** Function name:           S10_SetBindingAddress
** Descriptions:            ��������ģ��󶨵�ַ                         
** input parameters:        addr       Ŀ������ģ���ַ(6�ֽ�)
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetBindingAddress(unsigned char addr[]);


/*********************************************************************************************************
** Function name:           S10_GetBindingAddress
** Descriptions:            ��ȡ����ģ��󶨵�ַ                         
** input parameters:        addr       ������ģ���ַ������(6�ֽ�) 
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetBindingAddress(unsigned char addr[]);


/*********************************************************************************************************
** Function name:           S10_SetSafeParameters
** Descriptions:            ���ð�ȫ����ģʽ                         
** input parameters:        safeLevel       ��ȫ�ȼ���0-3��
**							encryptLevel    ���ܵȼ���0-2��
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							PARAMINVALID			�ȼ���������ȷ
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetSafeParameters(unsigned int safeLevel,unsigned int encryptLevel);



/*********************************************************************************************************
** Function name:           S10_GetSafeParameters
** Descriptions:            ��ȡ��ȫ����ģʽ                         
** input parameters:        NONE
** output parameters:       safeLevel       ��ȫ�ȼ���0-3��
**							encryptLevel    ���ܵȼ���0-2��
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetSafeParameters(unsigned int &safeLevel,unsigned int &encryptLevel);



/*********************************************************************************************************
** Function name:           S10_InquireDevice
** Descriptions:            ��ѯ�����豸                         
** input parameters:        rssi       �Ƿ���ʾ�ź�ǿ��       
**					        maxcnt     ��������豸��Ӧ��   
**					        timeout    ��ѯ�豸��ʱʱ��(�룩
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							SETINQUIRECONFFAILED	���ò�ѯ����ʧ��
**							PARAMINVALID			��ʱʱ���������ȷ��������1-60)
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_InquireDevice(bool rssi,unsigned int maxcnt,unsigned int timeout);



/*********************************************************************************************************
** Function name:           S10_GetInquiredDevice
** Descriptions:            ��ȡ��ѯ���������豸                         
** input parameters:		NONE
** output parameters:       btd			�����豸��Ϣ�ṹ��
** 
** Returned value:          true					��ȡ�ɹ�
**							false					��ȡʧ��
*********************************************************************************************************/
BlueToothS10_API bool S10_GetInquiredDevice(BlueToothDevice &btd);



/*********************************************************************************************************
** Function name:           S10_InquireCancel
** Descriptions:            ȡ�������豸��ѯ                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			ȡ���ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			ȡ��ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_InquireCancel();



/*********************************************************************************************************
** Function name:           S10_MatchDevice
** Descriptions:            �����豸���                         
** input parameters:		addr		Ŀ������ģ���ַ(6�ֽ�)     
**							timeout		��Գ�ʱʱ��(�룩
** output parameters:       NONE		
** 
** Returned value:          SUCCESS_SETTING			��Գɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							PARAMINVALID			��ʱʱ���������ȷ����Գ�ʱʱ�������1-20)
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			���ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_MatchDevice(unsigned char addr[],unsigned int timeout);



/*********************************************************************************************************
** Function name:           S10_ConnectDevice
** Descriptions:            �����豸����                         
** input parameters:		addr		Ŀ������ģ���ַ(6�ֽ�)  
** output parameters:       NONE		
** 
** Returned value:          SUCCESS_SETTING			���ӳɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_ConnectDevice(unsigned char addr[]);




/*********************************************************************************************************
** Function name:           S10_Disconnect
** Descriptions:            �Ͽ������豸����                         
** input parameters:		NONE  
** output parameters:       NONE		
** 
** Returned value:          SUCCESS_SETTING			�Ͽ��ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							DISC_LINK_LOSS			���Ӷ�ʧ
**							DISC_NO_SLC				û������
**							DISC_TIMEOUT			�Ͽ���ʱ
**							DISC_ERROR				�Ͽ�����
**							FAILURE_SETTING			�Ͽ�ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_Disconnect();



/*********************************************************************************************************
** Function name:           S10_AutoSleep
** Descriptions:            ��������ʹ��                         
** input parameters:		enable		�Ƿ�ʹ���Զ�����  
** output parameters:       NONE		
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_AutoSleep(bool enable);


/*********************************************************************************************************
** Function name:           S10_SetFilterMode
** Descriptions:            ���������豸����׼��                         
** input parameters:        filterDeviceClass       �Ƿ�ʹ���豸�����   
**					        filterAccessCode		�Ƿ�ʹ�÷��������
** output parameters:       NONE
** 
** Returned value:          SUCCESS_SETTING			���óɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			����ʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SetFilterMode(bool filterDeviceClass,bool filterAccessCode);



/*********************************************************************************************************
** Function name:           S10_GetFilterMode
** Descriptions:            ��ȡ�����豸����׼��                         
** input parameters:        NONE
** output parameters:       filterDeviceClass       �Ƿ�ʹ���豸�����   
**					        filterAccessCode		�Ƿ�ʹ�÷��������
** 
** Returned value:          SUCCESS_SETTING			��ȡ�ɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							RECEIVETIMEOUT			�������ݳ�ʱ
**							FAILURE_SETTING			��ȡʧ��
**							ERROR_SETTING			��������
**							MODEERROR				ģʽ���󣨲�����ATģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_GetFilterMode(bool &filterDeviceClass,bool &filterAccessCode);



/*********************************************************************************************************
** Function name:           S10_SendData
** Descriptions:            ��ͨ��ģʽ�·�������                         
** input parameters:        buf				���ͻ�����ָ��
**					        bufLength		�������ݳ���
** output parameters:       bufLength		ʵ�ʷ����ֽ���
** 
** Returned value:          SUCCESS_SETTING			���ͳɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							SENDDATAERROR			�������ݴ���
**							MODEERROR				ģʽ���󣨲�����ͨ��ģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_SendData(unsigned char buf[],unsigned int &bufLength);



/*********************************************************************************************************
** Function name:           S10_RecvData
** Descriptions:            ��ͨ��ģʽ�½�������                         
** input parameters:        buf				���ջ�����ָ��
**					        bufLength		���ջ���������
** output parameters:       bufLength		ʵ�ʽ����ֽ���
** 
** Returned value:          SUCCESS_SETTING			���ճɹ�
**							COMNOTOPEN				����δ�򿪣�δ��ʼ����
**							MODEERROR				ģʽ���󣨲�����ͨ��ģʽ��
*********************************************************************************************************/
BlueToothS10_API int S10_RecvData(unsigned char buf[],unsigned int &bufLength);



/*********************************************************************************************************
** Function name:           S10_GetLastError
** Descriptions:            ��ȡ�ϴδ���Ĵ���                         
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          -1		û�д���
**							����		�������
*********************************************************************************************************/
BlueToothS10_API int S10_GetLastError();


#if defined(__cplusplus)
}
#endif