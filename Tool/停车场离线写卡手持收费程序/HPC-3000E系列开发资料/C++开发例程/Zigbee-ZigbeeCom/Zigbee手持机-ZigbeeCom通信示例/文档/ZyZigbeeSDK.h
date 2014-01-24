#ifndef __ZYZIGBEESDK_323DSJFFO9U9898_h
#define __ZYZIGBEESDK_323DSJFFO9U9898_h


//��������
////////////////////////  CEL����  ///////////////////////
#define ZYZB_CEL_DEV_NAME		1		//����
#define ZYZB_CEL_DEV_PWD		2		//����
#define ZYZB_CEL_DEV_FVER		3		//�̼��汾
#define ZYZB_CEL_DEV_WORKTYPE	4		//��������
#define ZYZB_CEL_DEV_CHANNEL	5		//ͨ����
#define ZYZB_CEL_DEV_PANID		6		//PAN ID
#define ZYZB_CEL_DEV_LOCALNETID	7
#define ZYZB_CEL_DEV_LOCALMAC	8
#define ZYZB_CEL_DEV_DSTNETID	9
#define ZYZB_CEL_DEV_DSTMAC		10
#define ZYZB_CEL_DEV_TRANRATE	11		//��������
#define ZYZB_CEL_DEV_POWER		12		//���͹���
#define ZYZB_CEL_DEV_RTY		13		//�������Դ���
#define ZYZB_CEL_DEV_RTYSPACE	14		//�������Լ��
#define ZYZB_CEL_DEV_BAUD		15		//���ڲ�����
#define ZYZB_CEL_DEV_DATABIT	16		//����λ
#define ZYZB_CEL_DEV_PARITY		17		//У��λ
#define ZYZB_CEL_DEV_STOPBIT	18		//ֹͣλ
#define ZYZB_CEL_DEV_SENDMODE	19		//����ģʽ
#define ZYZB_CEL_DEV_SAMPLERATE	20		//������
#define ZYZB_CEL_DEV_COMPRESS_SCHEME	21		//ѹ����ʽ


#define ZYZB_CEL_SEARCH_TYPE		1		//����
#define ZYZB_CEL_SEARCH_CHANNEL		2		//ͨ��
#define ZYZB_CEL_SEARCH_RATE		3		//����
#define ZYZB_CEL_SEARCH_PANID		4		//PAN ID
#define ZYZB_CEL_SEARCH_ID			5		//ID
#define ZYZB_CEL_SEARCH_WORKMODE	6		//������ʽ



//SDK�ӿ�
BOOL __stdcall ZYZB_OpenCom(	LPCTSTR	szCom,
								int		iBautRate,
								int		iByteSize,
								int		iParity, 
								int		iStopBits,
								int		iDtrCtl,
								int		iRtsCtl,
								int		iCtsCtl,
								int		iDsrCtl,
								int		iResponse);
BOOL __stdcall ZYZB_CloseCom();
DWORD __stdcall ZYZB_GetLastError();
BOOL __stdcall ZYZB_ComCheckOpen();

//////////////////CEL//////////////////////////////////////
BOOL __stdcall ZYZB_CEL_LoadInfo();
BOOL __stdcall ZYZB_CEL_GetProperty(int iPropertyType, void* pData, int iBufLen);
BOOL __stdcall ZYZB_CEL_SetProperty(int iPropertyType, void* pData, int iBufLen);
BOOL __stdcall ZYZB_CEL_SubmitInfo();
BOOL __stdcall ZYZB_CEL_ResetDev();			//��λ�豸
BOOL __stdcall ZYZB_CEL_ResetToDefault();	//�ָ���������


//�����豸
void __stdcall ZYZB_CEL_ClearSearchArr();
BOOL __stdcall ZYZB_CEL_SearchDev(int iChannel, int iRate);
int  __stdcall ZYZB_CEL_GetSearchDevCount();
BOOL __stdcall ZYZB_CEL_GetSerarchDevProperty(int iIndex, int iType, void *pOut, int iBufLen);

BOOL __stdcall ZYZB_CEL_LoadRemoteDevInfo(int iIndex);
BOOL __stdcall ZYZB_CEL_GetRemoteDevProperty(int iIndex, int iType, void *pOut, int iBufLen);
BOOL __stdcall ZYZB_CEL_SetRemoteDevProperty(int iIndex, int iType, void *pOut, int iBufLen);
BOOL __stdcall ZYZB_CEL_SubmitRemoteDevInfo(int iIndex);
BOOL __stdcall ZYZB_CEL_ResetRemoteDev(int iIndex);			//��λ�豸
BOOL __stdcall ZYZB_CEL_ResetRemoteToDefault(int iIndex);	//�ָ���������


BOOL __stdcall  ZYZB_CEL_Read (LPVOID szBuffer, const DWORD dwSize,DWORD *plReadedSize,DWORD dwTimeOut=1500);
BOOL __stdcall  ZYZB_CEL_Write(LPVOID szBuffer, const DWORD dwSize,DWORD *plWrittenSize,DWORD dwTimeOut=1500);
#endif//(__ZYZIGBEESDK_323DSJFFO9U9898_h)
