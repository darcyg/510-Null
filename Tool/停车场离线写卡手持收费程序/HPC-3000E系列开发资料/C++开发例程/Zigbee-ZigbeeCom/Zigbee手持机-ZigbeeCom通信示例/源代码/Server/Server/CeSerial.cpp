// CeSerial.cpp: implementation of the CCeSerial class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CeSerial.h"
//#include "epcSerial.h"


//#ifdef _DEBUG
//#undef THIS_FILE
//static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
//#endif



/*********************************************************************************************************
** Function name:           CCeSerial
**
** Descriptions:            CCeSerial���캯������ʼ������Ա������
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ��
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
CCeSerial::CCeSerial ()
{
	hCOM             = INVALID_HANDLE_VALUE;		                    /*  ���ڲ������                */
	hRcvThread       = NULL;					                        /*  ���ڽ����߳̾��            */
	hExitThreadEvent = NULL;			                                /*  ���ڽ����߳��˳��¼�        */	
	
	dwRcvLength      = 1024;					                        /*  �����߳�ÿ�ν������ݵĸ���  */
	pfunRcvOnComRcv  = NULL;				                            /*  �������ݳɹ��ص�����ָ��    */
	pvRcvUserParam   = NULL;					                        /*  �ص�������Ҫ���û���������  */
}




/*********************************************************************************************************
** Function name:           ~CCeSerial
**
** Descriptions:            CCeSerial�𹹺������رմ��ڣ�������ڽ����߳�û���˳�����֪ͨ���˳���
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          ��
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
CCeSerial::~CCeSerial ()
{
	epcSerialClose();					                                /*  �رմ���                    */	
}

int CCeSerial::epcSetRTS(BOOL bEnRts)
{
	/* �жϴ����Ƿ��Ѵ򿪣����򷵻� */
	if (hCOM == INVALID_HANDLE_VALUE) {
		return (COM_ERR_USING);	
	}

	if (bEnRts)  
	{	
		if (EscapeCommFunction (hCOM, SETRTS))
		{
			return COM_OK;
		}
	}  
	else
	{
		if (EscapeCommFunction (hCOM, CLRRTS))
		{
			return COM_OK;
		}
	}
	return COM_ERR_PARA;
}


/*********************************************************************************************************
** Function name:           epcSerialSetCom
**
** Descriptions:            ���ô��ڲ����ʣ�����λ��ֹͣλ����żУ��λ�ȡ�
**                          ʹ�ñ�����ǰ����򿪺ô��ڣ����ҰѾ��������hCOM�С�
** input parameters:        BaudRate        ������
**                          DataBits        ����λ
**                          StopBits        ֹͣλ
**                          Parity          ��żУ��λ
**                          DTRShake        DTRӲ������������
**                          RTSShake        RTSӲ������������
** output parameters:       NONE
** 
** Returned value:          ��ȷ����COM_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô��󷵻�COM_ERR_TIME.
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:             ���ܱ�
** Modified date:           2008/11/20
**                          �޸�"���ó�ʱ����"�Σ����ӳ�ʱʱ�䡣(V1.02)
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
int CCeSerial::epcSerialSetCom (EBaudrate  BaudRate, 
					            EDataBits  DataBits,  EStopBits  StopBits, EParity  Parity,
			                    EDtrCon    DTRShake,  ERtsCon    RTSShake)
{
	COMMTIMEOUTS  ctoTimeOut;

	/*
	 *	���ô��ڲ���
	 */ 
	GetCommState(hCOM, &dcbCOM);						                /*  ��ȡ���ڵ�DCB               */
	dcbCOM.BaudRate = BaudRate;							                /*  ����������                  */ 
	dcbCOM.ByteSize = DataBits;							                /*  ����λ����                  */	
	dcbCOM.StopBits = StopBits;							                /*  ֹͣλ����                  */
	dcbCOM.Parity   = Parity;								            /*  ��żУ������                */

    if (Parity != EParNone)  {
        dcbCOM.fParity = TRUE;			                                /*  ��żУ��ʹ�ܿ���            */
    }  else  {
        dcbCOM.fParity = FALSE;
    }
	     	
	dcbCOM.fBinary = TRUE;									            /*  ���������ģʽ              */

	if (DTRShake == EDtrDisable)	{							
		dcbCOM.fDtrControl  = DTRShake;			                        /*  Ӳ��������������            */	
		dcbCOM.fOutxDsrFlow = FALSE;
    }  else  {
		dcbCOM.fDtrControl  = DTRShake;
		dcbCOM.fOutxDsrFlow = TRUE;
	}
	
	if (RTSShake == ERtsDisable)  {	
		dcbCOM.fRtsControl  = RTSShake;
		dcbCOM.fOutxCtsFlow = FALSE;
    }  else  {
		dcbCOM.fRtsControl  = RTSShake;
		dcbCOM.fOutxCtsFlow = TRUE;
	}
	
	dcbCOM.fOutX = FALSE;						    /*  ��ֹ��������ơ�fOutX: �յ�Xoff��ֹͣ����       */
	dcbCOM.fInX  = FALSE;							/*  ��ֹ��������ơ�fInX: ����������������Xoff    */
	dcbCOM.fTXContinueOnXoff = FALSE;				/*  ��ֹ��������ơ�fInX�¼�֮�󣬷����Ƿ��������  */
	
	/*
	 *  ����״̬����
	 */
	SetCommMask(hCOM, EV_RXCHAR);					                    /*  �����¼�:���յ�һ���ַ�     */	
	SetupComm(hCOM, 16384, 16384);					                    /*  ���ý����뷢�͵Ļ�������С  */
	if ( !SetCommState(hCOM, &dcbCOM) )  {			                    /*  ���ô��ڵ�DCB               */	
		//RETAILMSG(1,(TEXT("�޷�����ǰ�������ö˿ڣ��������!")));
		epcSerialClose();						    /*  ClosePort()������hCOM = INVALID_HANDLE_VALUE    */
		return (COM_ERR_PARA);
	}
	
	/*
     *  ���ó�ʱ����
     */
	GetCommTimeouts(hCOM, &ctoTimeOut);		
	ctoTimeOut.ReadIntervalTimeout         = MAXDWORD;			        /*  �����ַ������ʱ����      */
	ctoTimeOut.ReadTotalTimeoutMultiplier  = 1;		
	ctoTimeOut.ReadTotalTimeoutConstant    = 1;		                /*  �������ܳ�ʱ����            */
	ctoTimeOut.WriteTotalTimeoutMultiplier = 1;
	ctoTimeOut.WriteTotalTimeoutConstant   = 1;  /*  д�����ܳ�ʱ���� (дΪ0����ʾû�г�ʱ����)      */		
	if ( !SetCommTimeouts(hCOM, &ctoTimeOut) )  {
		//RETAILMSG(1,(TEXT("�޷����ó�ʱ����!")));
		epcSerialClose();
		return (COM_ERR_TIME);
	}

	return (COM_OK);
}




/*********************************************************************************************************
  ���ڶ˿�������
*********************************************************************************************************/
const TCHAR GstrPortTbl[9][12] = {_T("COM1:"), _T("COM2:"), _T("COM3:"), _T("COM4:"),
                                  _T("COM5:"), _T("COM6:"), _T("COM7:"), _T("COM8:"), _T("COM9:")};


/*********************************************************************************************************
** Function name:           epcSerialOpen
**
** Descriptions:            �򿪴��ڡ����ڹ���ģʽΪ8λ����λ��1λֹͣλ������żУ��λ��
**                          
** input parameters:        Port        ���ں�,��ECOM1,ECOM2
**                          BaudRate    ������,��EBaud9600,EBaud115200
** output parameters:       NONE
** 
** Returned value:          ��ȷ����COM_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô���
**                          ����COM_ERR_TIME, �����Ѵ򿪷���COM_ERR_USING, ���ڴ򿪴���COM_ERR_OPEN.
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
int CCeSerial::epcSerialOpen (EPort  Port, EBaudrate  BaudRate)
{	
    int  iErr;

	/* 
     *  �жϴ����Ƿ��Ѵ򿪣����򷵻�
     */
	if (hCOM != INVALID_HANDLE_VALUE) {
        return (COM_ERR_USING);	
    }

	/* 
     *  �����ж�
     */
	if ( (Port > ECOM9) || (Port < ECOM1) ) {	
		//RETAILMSG(1,(TEXT("�򿪴��ںŲ�������.")));
		return (COM_ERR_PARA);
	}

	if ( (BaudRate > EBaud115200) || (BaudRate < EBaud110) ) {
		//RETAILMSG(1,(TEXT("�����ʲ�������.")));
		return (COM_ERR_PARA);
	}

	/* 
     *  �򿪴���  (��GstrPortTbl[]���в��ʱ,ע���±�Ϊ0��Ӧ��ECOM1)
     */
	hCOM = CreateFile(GstrPortTbl[Port-1], GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	if (hCOM == INVALID_HANDLE_VALUE)  {
		//RETAILMSG(1,(TEXT("�޷��򿪶˿ڻ�˿��Ѵ�!�����Ƿ��ѱ�ռ��.")));
		return (COM_ERR_OPEN);
	}

	/* 
     *  ���ô��� (8λ����λ��1λֹͣλ������żУ�飬��ֹӲ��������)
     */
    iErr = epcSerialSetCom(BaudRate, EData8, EStop1, EParNone, EDtrDisable, ERtsDisable);
    if (iErr !=  COM_OK) {
        return (iErr); 
    }
	
	/* 
     *  �����/��������
     */
	PurgeComm(hCOM, PURGE_TXCLEAR | PURGE_RXCLEAR);	 	

	return (COM_OK);
}




/*********************************************************************************************************
** Function name:           epcSerialOpen
**
** Descriptions:            �򿪴��ڡ�Ӳ�������ƽ�ֹ��
**                          
** input parameters:        Port        ���ں�,��ECOM1,ECOM2
**                          BaudRate    ������,��EBaud9600,EBaud115200
**                          DataBits    ����λ,��EData8
**                          StopBits    ֹͣλ,��EStop1 
**                          Parity      ��żУ��λ,��EParNone, EParOdd
** output parameters:       NONE
** 
** Returned value:          ��ȷ����COM_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô���
**                          ����COM_ERR_TIME, �����Ѵ򿪷���COM_ERR_USING, ���ڴ򿪴���COM_ERR_OPEN.
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
int CCeSerial::epcSerialOpen (EPort      Port,     EBaudrate  BaudRate, 
						      EDataBits  DataBits, EStopBits  StopBits, EParity  Parity)
{	
    int  iErr;

	/* 
     *  �жϴ����Ƿ��Ѵ򿪣����򷵻�
     */
	if (hCOM != INVALID_HANDLE_VALUE) {
        return (COM_ERR_USING);	
    }
	
	/* 
     *  �����ж�
     */
	if ( (Port > ECOM9) || (Port < ECOM1) ) {	
		//RETAILMSG(1,(TEXT("�򿪴��ںŲ�������.")));
		return (COM_ERR_PARA);
	}
	
	if ( (BaudRate > EBaud115200) || (BaudRate < EBaud110) ) {
		//RETAILMSG(1,(TEXT("�����ʲ�������.")));
		return (COM_ERR_PARA);
	}
	
	/* 
     *  �򿪴���
     */
	hCOM = CreateFile(GstrPortTbl[Port-1], GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	if (hCOM == INVALID_HANDLE_VALUE) {
		//RETAILMSG(1,(TEXT("�޷��򿪶˿ڻ�˿��Ѵ�!�����Ƿ��ѱ�ռ��.")));
		return (COM_ERR_OPEN);
	}
	
	/* 
     *  ���ô��� (��ֹӲ��������)
     */
	iErr = epcSerialSetCom(BaudRate, DataBits, StopBits, Parity, EDtrDisable, ERtsDisable); 
    if (iErr !=  COM_OK) {
        return (iErr); 
    }
	
	/* 
     *  �����/��������
     */
	PurgeComm(hCOM, PURGE_TXCLEAR | PURGE_RXCLEAR);	 	
	
	return (COM_OK);
}




/*********************************************************************************************************
** Function name:           epcSerialOpen
**
** Descriptions:            �򿪴���
**                          
** input parameters:        Port        ���ں�,��ECOM1,ECOM2
**                          BaudRate    ������,��EBaud9600,EBaud115200
**                          DataBits    ����λ,��EData8
**                          StopBits    ֹͣλ,��EStop1 
**                          Parity      ��żУ��λ,��EParNone, EParOdd
**                          DTRShake    DTRӲ������������
**                          RTSShake    RTSӲ������������
** output parameters:       NONE
** 
** Returned value:          ��ȷ����COM_OK, �������ò������󷵻�COM_ERR_PARA, ��ʱ���ô���
**                          ����COM_ERR_TIME, �����Ѵ򿪷���COM_ERR_USING, ���ڴ򿪴���COM_ERR_OPEN.
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
int CCeSerial::epcSerialOpen (EPort      Port,      EBaudrate  BaudRate, 
						      EDataBits  DataBits,  EStopBits  StopBits, EParity  Parity,
						      EDtrCon    DTRShake,  ERtsCon    RTSShake)
{ 
    int  iErr;
    
	/* 
     *  �жϴ����Ƿ��Ѵ򿪣����򷵻�
     */
	if (hCOM != INVALID_HANDLE_VALUE) {
        return (COM_ERR_USING);	
    }
	
	/* 
     *  �����ж�
     */
	if ( (Port > ECOM9) || (Port < ECOM1) ) {	
		//RETAILMSG(1,(TEXT("�򿪴��ںŲ�������.")));
		return (COM_ERR_PARA);
	}
	
	if( (BaudRate > EBaud115200) || (BaudRate < EBaud110) ) {
		//RETAILMSG(1,(TEXT("�����ʲ�������.")));
		return (COM_ERR_PARA);
	}
	
	/* 
     *  �򿪴���
     */
	hCOM = CreateFile(GstrPortTbl[Port-1], GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	if (hCOM == INVALID_HANDLE_VALUE) {
		//RETAILMSG(1,(TEXT("�޷��򿪶˿ڻ�˿��Ѵ�!�����Ƿ��ѱ�ռ��.")));
		return (COM_ERR_OPEN);
	}
	
	/* 
     *  ���ô��� (��ֹӲ��������)
     */
	iErr = epcSerialSetCom(BaudRate, DataBits, StopBits, Parity, DTRShake, RTSShake); 
    if (iErr !=  COM_OK) {
        return (iErr); 
    }
	
	/* 
     *  �����/��������
     */
	PurgeComm(hCOM, PURGE_TXCLEAR | PURGE_RXCLEAR);	 	
	
	return (COM_OK);
}




/*********************************************************************************************************
** Function name:           epcSerialClose
**
** Descriptions:            �رմ��ڡ�������hCOM = INVALID_HANDLE_VALUE��
**                          
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
**                          (����ʧ��ԭ��: hCOMֵ����)
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
BOOL CCeSerial::epcSerialClose (void)
{
	if (hRcvThread != NULL) {	
		SetEvent(hExitThreadEvent);				                        /*  ֪ͨ���ڽ����߳��˳�        */
		WaitForSingleObject(hRcvThread, 500);		                    /*  �ȴ��߳��˳�                */
		
        CloseHandle(hRcvThread);					                    /*  �رս����߳̾��            */
		CloseHandle(hExitThreadEvent);				                    /*  �ر��߳��˳��¼����        */		
		hRcvThread = NULL;
	}
	
	if (hCOM != INVALID_HANDLE_VALUE) {
		SetCommMask(hCOM, 0);		
		PurgeComm(hCOM, PURGE_TXCLEAR | PURGE_RXCLEAR);	                /*  �����/������               */
		CloseHandle(hCOM);								                /*  �رմ��ڲ������            */
		hCOM = INVALID_HANDLE_VALUE;
		return (TRUE);
	}

	return (FALSE);
}





/*********************************************************************************************************
** Function name:           epcSerialSendData
**
** Descriptions:            ���ʹ�������
**                          
** input parameters:        pucSendBuf      �������ݻ�����ָ��
**                          dwLength        �������ݸ���
** output parameters:       NONE
** 
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
**                          (����ʧ��ԭ��: ��������򴮿�û�д�)
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
BOOL CCeSerial::epcSerialSendData (BYTE  *pucSendBuf, DWORD  dwLength)
{
	DWORD    dwActLen;
	COMSTAT  comstatTest;
	DWORD    dwErrorFlags;

	/*
	 *  �����ж�
	 */ 
    if ( (pucSendBuf == NULL) || (dwLength < 1) ) {
        return (FALSE);
    }

	/*
	 *  �жϴ����Ƿ��Ѿ���	
	 */ 
	if (hCOM == INVALID_HANDLE_VALUE) {
		//RETAILMSG(1,(TEXT("����δ��!")));
		return (FALSE);
	}

	/*
	 *  ������ڴ���	
	 */ 
	ClearCommError(hCOM, &dwErrorFlags, &comstatTest);

	/*
	 *  ��������	
	 */ 
	WriteFile(hCOM, pucSendBuf, dwLength, &dwActLen, NULL);	            
	return (TRUE);
}






/*********************************************************************************************************
** Function name:           epcSerialRcvData
**
** Descriptions:            ���մ������ݡ�������ʽ��
**                          
** input parameters:        dwLength        Ҫ�������ݸ��� (���Ϊ1024)
**                          dwOutTime       ���ճ�ʱʱ�� (Ҫ����10)
**                          bClrComBuf      ΪTRUEʱ,�ڽ���ǰ��������ڽ��ջ�����, ΪFLASEʱ�����
** output parameters:       pucRcvBuf       �������ݻ�����ָ��
** 
** Returned value:          ���������ݸ��� (�������󡢴���û�д򿪻�û�н��յ����ݣ�����0).
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
DWORD CCeSerial::epcSerialRcvData (BYTE  *pucRcvBuf, DWORD  dwLength, DWORD  dwOutTime, BOOL  bClrComBuf)
{
//    COMMTIMEOUTS  ctoTimeOut;
	DWORD         dwLengthRcv;
	COMSTAT       comstatTest;
	DWORD         dwErrorFlags;

	/*
	 *  �����ж�
	 */ 
    if ( (pucRcvBuf == NULL) || (dwLength < 1) ) {
        return (0);
    }

    if (dwLength > 1024) {
        dwLength = 1024;
    }

    if (dwOutTime < 1) {
        dwOutTime = 1;
    }

	/*
	 *  �жϴ����Ƿ��Ѿ���	
	 */ 
	if (hCOM == INVALID_HANDLE_VALUE) {
		//RETAILMSG(1,(TEXT("����δ��!")));
		return (0);
	}

	/*
	 *  �رմ��ڽ����߳�
	 */
	//if (hRcvThread != NULL) {		
	//	SetEvent(hExitThreadEvent);				                        /*  ֪ͨ���ڽ����߳��˳�        */
	//	WaitForSingleObject(hRcvThread, 500);		                    /*  �ȴ��߳��˳�                */
		
    //    CloseHandle(hRcvThread);					                    /*  �رս����߳̾��            */
	//	CloseHandle(hExitThreadEvent);				                    /*  �ر��߳��˳��¼����        */		
	//	hRcvThread = NULL;
	//}

	/*
	 *  ���ó�ʱ����	
	 */ 
	//GetCommTimeouts(hCOM, &ctoTimeOut);		
	//ctoTimeOut.ReadIntervalTimeout        = dwOutTime;	                /*  �����ַ������ʱ����      */
	//ctoTimeOut.ReadTotalTimeoutMultiplier = 1;		
	//ctoTimeOut.ReadTotalTimeoutConstant   = dwOutTime;	                /*  �������ܳ�ʱ����            */		
	//SetCommTimeouts(hCOM, &ctoTimeOut);

	/*
	 *  ������ڴ���	
	 */ 
	ClearCommError(hCOM, &dwErrorFlags, &comstatTest);

	/*
	 *  ������ջ�����	
	 */ 
    if (bClrComBuf) {
        PurgeComm(hCOM, PURGE_RXCLEAR);	
    }

	/*
	 *  ��������	
	 */ 
	ReadFile(hCOM, pucRcvBuf, dwLength, &dwLengthRcv, NULL);
	return (dwLengthRcv);
}





/*********************************************************************************************************
** Function name:           epcSerialRcvDataTread
**
** Descriptions:            ���ڽ����߳�
**                          
** input parameters:        pvParam         �̲߳���,�����߳�ʱ����
** output parameters:       NONE
** 
** Returned value:          �߳��˳�ʱ����0, ����ֵû���⺬��
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
DWORD  WINAPI CCeSerial::epcSerialComRcvTread (LPVOID  pvParam)
{
	DWORD  dwLength;
	BOOL   bReadState;

	BYTE  *pucRcvBuf = new BYTE[1028];

	CCeSerial *pCeSerial = (CCeSerial *)pvParam;

	while (TRUE)  {	
        /* 
         *  �ȴ��߳��˳��¼� 
         */
        if (WaitForSingleObject(pCeSerial->hExitThreadEvent, 0) == WAIT_OBJECT_0)  {
            break;	
        }

		if (pCeSerial->hCOM != INVALID_HANDLE_VALUE) {	
            /* 
             *  ���ڶ�ȡ���� 
             */
			bReadState = ReadFile(pCeSerial->hCOM, pucRcvBuf, pCeSerial->dwRcvLength, &dwLength, NULL);
			if (bReadState) {					
                /* 
                 *  ���ճɹ����ûص����� 
                 */
                if(dwLength != 0) {
                    pCeSerial->pfunRcvOnComRcv(pCeSerial->pvRcvUserParam, pucRcvBuf, dwLength);		
                }
			}
        }  else  {
            break;                                                      /*  ���ھ�������˳��߳�      */
        }

        Sleep(1);
	}		

	delete[] pucRcvBuf;
	return (0);
}




/*********************************************************************************************************
** Function name:           epcSerialRcvDataTread
**
** Descriptions:            ���մ������ݡ��̷߳�ʽ��
**                          
** input parameters:        dwLength        �������ݸ��������Ϊ1024
**                          dwOutTime       ���ճ�ʱʱ����� (��λΪmS����СΪ10)
**                          pfunOnComRcv    �������ݳɹ��ص�����ָ��
**                          pvUserParam     �ص�������Ҫ���û���������
** output parameters:       NONE
** 
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
**                          (����ʧ��ԭ��: �������󡢴���û�д򿪻򴮿ڽ����߳��ѽ�����)
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
BOOL CCeSerial::epcSerialRcvDataTread (DWORD        dwLength,     DWORD   dwOutTime,
				                       PFUN_COMRCV  pfunOnComRcv, LPVOID  pvUserParam)

{
	DWORD         dwThreadID;
	COMMTIMEOUTS  ctoTimeOut;
	
	/* 
     *  �����ж�
     */
    if ( (dwLength < 1) || (pfunOnComRcv == NULL) ) {
        return (FALSE);
    }

    if (dwLength > 1024) {
        dwLength = 1024;
    }

    if (dwOutTime < 10) {
        dwOutTime = 10;
    }
	
	/* 
     *  �жϴ����Ƿ��Ѿ���
     */
	if (hCOM == INVALID_HANDLE_VALUE)  {
		//RETAILMSG(1,(TEXT("����δ��!")));
		return (FALSE);
	}
	
	/* 
     *  �жϴ��ڽ����߳��Ƿ��ѽ���
     */
	if (hRcvThread != NULL) {	
        //RETAILMSG(1,(TEXT("���ڽ����߳��ѽ�����!")));
		return (FALSE);	
	}

	/* 
     *  ���ó�ʱ����
     */
	GetCommTimeouts(hCOM, &ctoTimeOut);		
	ctoTimeOut.ReadIntervalTimeout        = dwOutTime;			        /*  �����ַ������ʱ����      */
	ctoTimeOut.ReadTotalTimeoutMultiplier = 1;		
	ctoTimeOut.ReadTotalTimeoutConstant   = dwOutTime;	                /*  �������ܳ�ʱ����            */	
	SetCommTimeouts(hCOM, &ctoTimeOut);

	/* 
     *  �����̲߳���
     */
	dwRcvLength     = dwLength;
	pfunRcvOnComRcv = pfunOnComRcv;
	pvRcvUserParam  = pvUserParam;

	/* 
     *  �������ڽ����߳�			
     */
	hExitThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);            /*  �������ڽ����߳��˳��¼�    */			
	hRcvThread = CreateThread(0, 0, epcSerialComRcvTread, this, 0, &dwThreadID);
	if (hRcvThread == NULL)  {
		CloseHandle(hExitThreadEvent);				                    /* �ر��߳��˳��¼����         */
		//RETAILMSG(1,(TEXT("���������߳�ʧ��!")));
		return (FALSE);
	}	

	return (TRUE);
}




/*********************************************************************************************************
** Function name:           epcSerialRxClear
**
** Descriptions:            ������ջ�������
**                          
** input parameters:        NONE
** output parameters:       NONE
** 
** Returned value:          �����ɹ�����TRUE, ����ʧ�ܷ���FALSE.
**                          (����ʧ��ԭ��: ����û�д�)
**
** Created by:              ���ܱ�
** Created Date:            2007/10/10
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
BOOL CCeSerial::epcSerialRxClear()
{
    COMSTAT  comstatTest;
    DWORD    dwErrorFlags;
    
    /*
	 *  �жϴ����Ƿ��Ѿ���	
	 */ 
	if (hCOM == INVALID_HANDLE_VALUE) {
		//RETAILMSG(1,(TEXT("����δ��!")));
		return (FALSE);
	}
    
    /*
	 *  ������ڴ���	
	 */ 
	ClearCommError(hCOM, &dwErrorFlags, &comstatTest);

	/*
	 *  ������ջ�����	
	 */     
    PurgeComm(hCOM, PURGE_RXCLEAR);	    

    return (TRUE);    
}



BOOL CCeSerial::epcCloseRcvThread(void)
{
	if (hRcvThread != NULL) {		
		SetEvent(hExitThreadEvent);				                        /*  ֪ͨ���ڽ����߳��˳�        */
		WaitForSingleObject(hRcvThread, 500);		                    /*  �ȴ��߳��˳�                */

		CloseHandle(hRcvThread);					                    /*  �رս����߳̾��            */
		CloseHandle(hExitThreadEvent);				                    /*  �ر��߳��˳��¼����        */		
		hRcvThread = NULL;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*********************************************************************************************************
  END FILE
*********************************************************************************************************/