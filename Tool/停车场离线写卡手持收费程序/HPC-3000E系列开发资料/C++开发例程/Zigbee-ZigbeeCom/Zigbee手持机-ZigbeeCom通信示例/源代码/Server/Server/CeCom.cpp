#include "stdafx.h"

#define CECOM_GLOBALS

#include "CeCom.h"
#include "CeSerial.h"

CCeSerial CeSerial;



BOOL Com_OpenPort(int m_Port)
{	
	EPort ePort = (EPort)(ECOM1 + m_Port);
	return CeSerial.epcSerialOpen(ePort, EBaud115200);
}

BOOL Com_ClosePort(void)
{
	return CeSerial.epcSerialClose();
}


BOOL Com_SendData(unsigned char *SendBuf, unsigned char SendLen)
{
	return CeSerial.epcSerialSendData(SendBuf, SendLen);
}


/*********************************************************************************************************
** ��������:		Com_RcvDataTread
** ��������:		���մ������ݡ��̷߳�ʽ��
** �������:        ucLength        �������ݸ��������Ϊ64
**                  dwOutTime       ���ճ�ʱʱ����� (��λΪmS����СΪ10)
**                  pfunOnComRcv    �������ݳɹ��ص�����ָ��
**                  pvUserParam     �ص�������Ҫ���û���������
** �������:		NONE
** 
** ������ֵ:		�����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
*********************************************************************************************************/
BOOL Com_RcvDataTread(BYTE ucLength, DWORD dwOutTime, PFUN_COMRCV pfunOnComRcv, LPVOID pvUserParam)
{
	return CeSerial.epcSerialRcvDataTread((DWORD)ucLength, dwOutTime, pfunOnComRcv, pvUserParam);
}


DWORD Com_RcvData(BYTE  *pucRcvBuf, DWORD  dwLength, DWORD  dwOutTime, BOOL  bClrComBuf)
{
	return CeSerial.epcSerialRcvData(pucRcvBuf, dwLength, dwOutTime, bClrComBuf); 
}

BOOL Com_Clear()
{
	return CeSerial.epcSerialRxClear();
}

BOOL CloseRcvThread(void)
{
	return CeSerial.epcCloseRcvThread();
}

