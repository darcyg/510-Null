// epcBuzzerLib.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "epcBuzzerLib.h"
#include <windows.h>
#include <commctrl.h>

/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               epcBuzzerLib.cpp
** Latest modified Date:    2007-12-6
** Latest Version:          1.0
** Descriptions:            �������û����װ����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Lizhenming
** Created date:            2007-12-5
** Version:                 1.0
** Descriptions:            The original version
**
*********************************************************************************************************/

#include "stdafx.h"
#include "epcBuzzerLib.h"


static HANDLE hBuzzerFile = INVALID_HANDLE_VALUE;                       /*  �����������ļ����          */
void (*GfnNotify)(BOOL) = NULL;                                         /*  �첽������ɵ��õĻص�����  */                    

BOOL APIENTRY DllMain( HANDLE hModule, 
					  DWORD  ul_reason_for_call, 
					  LPVOID lpReserved
					  )
{
	UNREFERENCED_PARAMETER(hModule);
	UNREFERENCED_PARAMETER(lpReserved);

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hBuzzerFile = CreateFile(TEXT("BZR1:"),                     /*  �򿪷���������             */
			GENERIC_READ | GENERIC_WRITE, 
			0, 
			NULL, 
			OPEN_EXISTING, 
			0, 
			0);
		if (hBuzzerFile == INVALID_HANDLE_VALUE) {
			return FALSE; 
		}
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (hBuzzerFile != INVALID_HANDLE_VALUE) {
			CloseHandle(hBuzzerFile);                               /*  �رշ���������              */
			hBuzzerFile = INVALID_HANDLE_VALUE;
		}
		break;
	}
	return TRUE;
}


/*********************************************************************************************************
** Function name:   		epcBuzzerOn
** Descriptions:    		������ʹ����������ָ��ʱ��
** input parameters:   	    dwOntime    ����������������ʱ��(ms)������0��ʾһֱ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    ������������dwOntime(ms)ʱ�䣬��dwOntimeΪ0ʱ�����̷���
*********************************************************************************************************/
EPCBUZZERLIB_API BOOL epcBuzzerOn (DWORD dwOntime)
{
	BOOL bRet;
	BYTE ucTmp;
	DWORD dwActLen;

	if (hBuzzerFile == INVALID_HANDLE_VALUE){
		return FALSE;                                                   /*  �������û��              */
	}

	ucTmp = 0;
	bRet = WriteFile(hBuzzerFile, &ucTmp, 1, &dwActLen, NULL);          /*  ʹ����������                */
	if (bRet == FALSE || dwActLen != 1){
		return FALSE;
	}

	if (dwOntime == 0){                                                 /*  ������һֱ����              */
		return TRUE;                                                    /*  ���̷���                    */
	} else {          
		Sleep(dwOntime);                                                /*  ����ָ��ʱ��                */
		bRet = epcBuzzerOff();                                          /*  ��ֹ������                  */
	} 

	return TRUE;
}

/*********************************************************************************************************
** Function name:   		epcBuzzerOff
** Descriptions:    		������ʹ��������ֹ
** input parameters:   	    ��
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
*********************************************************************************************************/
EPCBUZZERLIB_API BOOL epcBuzzerOff (VOID)
{
	BOOL bRet;
	BYTE ucTmp;
	DWORD dwActLen;

	if (hBuzzerFile == INVALID_HANDLE_VALUE){
		return FALSE;                                                   /*  �������û��              */
	}

	ucTmp = 1;
	bRet = WriteFile(hBuzzerFile, &ucTmp, 1, &dwActLen, NULL);          /*  ʹ��������ֹ                */
	if (bRet == FALSE || dwActLen != 1){
		return FALSE;
	}

	return TRUE;
}

/*********************************************************************************************************
** Function name:   		epcBuzzerGetStatus
** Descriptions:    		��������ȡ��������״̬
** input parameters:   	    ��
** output parameters:   	��
** Returned value:     	    0--������������1--��������ֹ������--���ִ���
*********************************************************************************************************/
EPCBUZZERLIB_API DWORD epcBuzzerGetStatus (VOID)
{
	BOOL bRet;
	BYTE ucStatus;
	DWORD dwActLen;

	if (hBuzzerFile == INVALID_HANDLE_VALUE){
		return (DWORD)-1;                                               /*  �������û��              */
	}

	bRet = ReadFile(hBuzzerFile, &ucStatus, 1, &dwActLen, NULL);        /*  ��ȡ������״̬              */
	if (bRet == FALSE || dwActLen != 1){
		return (DWORD)-1;
	}

	return (DWORD)ucStatus;
}

/*********************************************************************************************************
** Function name:   		epcBuzzerBeepsProc
** Descriptions:    		������ʹ����������ָ�����������С�������ΪepcBuzzerBeeps()�������½��̵߳���ں���
** input parameters:   	    ((DWORD*)lparam)[0]     ���������д���
**                          ((DWORD*)lparam)[1]     ����������ʱ��(ms)
**                          ((DWORD*)lparam)[2]     ��������ֹʱ��(ms)
** output parameters:   	��
** Returned value:     	    0
** Note:                    lparam�Ŀռ��СΪ3*sizeof(DWORD)���ɵ��������룬�����������ͷš�
*********************************************************************************************************/
static DWORD epcBuzzerBeepsProc (LPVOID lparam)
{
	BOOL bRet = TRUE;
	DWORD dwCnt;
	DWORD dwOntime;
	DWORD dwOfftime;
	DWORD dwFlashTimes;

	dwFlashTimes = ((DWORD*)lparam)[0];
	dwOntime     = ((DWORD*)lparam)[1];
	dwOfftime    = ((DWORD*)lparam)[2];
	delete[] lparam;                                                    /*  �ͷ��ɵ�����������ڴ�      */

	for (dwCnt=0; dwCnt<dwFlashTimes; dwCnt++){

		bRet = epcBuzzerOn(0);                                          /*  ʹ����������                */
		if (bRet == FALSE){
			break;
		}
		Sleep(dwOntime);                                                /*  ����ָ��ʱ��                */

		bRet = epcBuzzerOff();                                          /*  ʹ��������ֹ                */
		if (bRet == FALSE){
			break;
		}
		Sleep(dwOfftime);                                               /*  ��ָֹ��ʱ��                */
	}

	if (GfnNotify != NULL){                                             /*  ��������˻ص������������  */
		GfnNotify(bRet);                                                /*  �ص�����֪ͨӦ�ó���        */
	}

	return 0;
}

/*********************************************************************************************************
** Function name:   		epcBuzzerBeeps
** Descriptions:    		������ʹ����������ָ������������
** input parameters:   	    dwFlashTimes        ���������д���
**                          dwOntime            ����������ʱ��(ms)
**                          dwOfftime           ��������ֹʱ��(ms)
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    ���������첽��ʽִ�У����ᱻ����
*********************************************************************************************************/
EPCBUZZERLIB_API BOOL epcBuzzerBeeps (DWORD dwFlashTimes, DWORD dwOntime, DWORD dwOfftime)
{ 
	if (hBuzzerFile == INVALID_HANDLE_VALUE){
		return FALSE;                                                   /*  �������û��              */
	}

	HANDLE hBzrThread;
	DWORD *pdwParam; 
	/*
	*	����3*sizeof(DWORD)�ռ������洫���½��̵߳Ĳ���������Ŀռ����½��̸߳����ͷ�
	*/
	pdwParam   = new DWORD[3];
	pdwParam[0] = dwFlashTimes;
	pdwParam[1] = dwOntime;
	pdwParam[2] = dwOfftime;

	hBzrThread = CreateThread(NULL, 0, epcBuzzerBeepsProc,
		(void*)pdwParam, 0, NULL);                 /*  ���½��߳�����ɷ���������  */

	if (hBzrThread == NULL){
		delete[] pdwParam;                                              /*  �����߳�ʧ�ܣ��ͷ������ڴ�  */
		return FALSE;
	}
	CloseHandle(hBzrThread);

	return TRUE;
}

/*********************************************************************************************************
** Function name:   		epcBuzzerAsyncOn
** Descriptions:    		������ʹ����������ָ��ʱ��
** input parameters:   	    dwOntime    ����������������ʱ��(ms)������0��ʾһֱ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    ���������첽��ʽִ�У����ᱻ����
*********************************************************************************************************/
EPCBUZZERLIB_API BOOL epcBuzzerAsyncOn (DWORD dwOntime)
{
	if (dwOntime == 0){
		return epcBuzzerOn(dwOntime);                                   /*  0��ʾһֱ����               */
	} else {
		return epcBuzzerBeeps(1, dwOntime, 0);
	}
}

/*********************************************************************************************************
** Function name:   		epcBuzzerCallBackFunc
** Descriptions:    		���ûص�����ָ�룬���첽�ķ���������������ɺ󣬻���øûص�����֪ͨ�û�����
** input parameters:   	    lpfnNotify      �ص�����ָ��,�����NULL�����ʾ����Ҫ֪ͨ�û����򡣺�����
**                                          ��Ϊvoid (*lpfnNotify)(BOOL bResult),bResultΪִ�н����
**                                          TRUE��ʾִ�гɹ���FALSE��ʾִ��ʧ��    
** output parameters:   	��
** Returned value:     	    ��
*********************************************************************************************************/
EPCBUZZERLIB_API VOID epcBuzzerSetCallBackFunc( void (*lpfnNotify)(BOOL))
{
	GfnNotify = lpfnNotify;
}

