/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               epcLedLib.cpp
** Latest modified Date:    2007-12-6
** Latest Version:          1.0
** Descriptions:            LED�û����װ����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Lizhenming
** Created date:            2007-12-5
** Version:                 1.0
** Descriptions:            The original version
**
*********************************************************************************************************/

#include "stdafx.h"
#include "epcLedLib.h"
#include "Led.h"

static HANDLE hLedFile = INVALID_HANDLE_VALUE;                          /*  LED�����ļ����             */
void (*GfnNotify1)(BOOL) = NULL;                                        /*  LED1�첽������ɵĻص�����  */                    
void (*GfnNotify2)(BOOL) = NULL;                                        /*  LED2�첽������ɵĻص�����  */                    


/*********************************************************************************************************
** Function name:   		DllMain
** Descriptions:    		epcLed����ں���
** input parameters:   	    hModule             ��dll�ľ��
**                          ul_reason_for_call  ������ԭ��
**                          lpReserved          ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
*********************************************************************************************************/
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
            hLedFile = CreateFile(TEXT("LED1:"),                         /*  �� LED ����              */
                GENERIC_READ | GENERIC_WRITE, 
                0, 
                NULL, 
                OPEN_EXISTING, 
                0, 
                0);
            if (hLedFile == INVALID_HANDLE_VALUE) {
                return FALSE; 
            }
            break;
            
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
            break;
		case DLL_PROCESS_DETACH:
            if (hLedFile != INVALID_HANDLE_VALUE) {
                CloseHandle(hLedFile);                                  /*  �ر� LED ����               */
                hLedFile = INVALID_HANDLE_VALUE;
            }
			break;
    }
    return TRUE;
}

/*********************************************************************************************************
** Function name:   		epcLedOn
** Descriptions:    		����������ָ����LED��
** input parameters:   	    dwLedNum        LED��ţ�LED1,LED2
**                          dwOntime        LED�����ĳ���ʱ��(ms)������0��ʾһֱ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    ������������dwOntime(ms)ʱ�䣬��dwOntimeΪ0ʱ�����̷���
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedOn (DWORD dwLedNum, DWORD dwOntime)
{
    BOOL bRet;
    DWORD dwIoCtrl;

    if (dwLedNum != LED1 && dwLedNum != LED2){
        return FALSE;                                                   /*  LED�������                 */
    }
        
    if (hLedFile == INVALID_HANDLE_VALUE){
        return FALSE;                                                   /*  �������û��              */
    }

    dwIoCtrl = (dwLedNum == LED1) ? LED1_ON : LED2_ON;        
    bRet = DeviceIoControl(hLedFile, dwIoCtrl, NULL,
        0, NULL, 0, NULL, NULL);                                        /*  ����LED                     */
    if (bRet == FALSE){
        return FALSE;
    }

    if (dwOntime == 0){                                                 /*  һֱ����LED                 */
        return TRUE;                                                    /*  ���̷���                    */
    } else {          
        Sleep(dwOntime);                                                /*  ����ָ��ʱ��                */
        bRet = epcLedOff(dwLedNum);                                     /*  Ϩ��LED                     */
    } 
    
    return TRUE;
}

/*********************************************************************************************************
** Function name:   		epcLedOff
** Descriptions:    		������Ϩ��ָ����LED��
** input parameters:   	    dwLedNum        LED��ţ�LED1,LED2
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedOff (DWORD dwLedNum)
{
    BOOL bRet;
    DWORD dwIoCtrl;

    if (dwLedNum != LED1 && dwLedNum != LED2){
        return FALSE;                                                   /*  LED�������                 */
    }
        
    if (hLedFile == INVALID_HANDLE_VALUE){
        return FALSE;                                                   /*  �������û��              */
    }

    dwIoCtrl = (dwLedNum == LED1) ? LED1_OFF : LED2_OFF;        
    bRet = DeviceIoControl(hLedFile, dwIoCtrl, NULL,
        0, NULL, 0, NULL, NULL);                                        /*  Ϩ��LED                     */
    if (bRet == FALSE){
        return FALSE;
    }
    
    return TRUE;
}


/*********************************************************************************************************
** Function name:   		epcLedGetStatus
** Descriptions:    		��������ȡָ����LED�Ƶ�״̬
** input parameters:   	    dwLedNum        LED��ţ�LED1,LED2
** output parameters:   	��
** Returned value:     	    0--������1--Ϩ������--���ִ���
*********************************************************************************************************/
EPCLEDLIB_API DWORD epcLedGetStatus (DWORD dwLedNum)
{
    BOOL bRet;
    DWORD dwIoCtrl;
    BYTE ucStatus;
    DWORD dwActLen;
    
    if (dwLedNum != LED1 && dwLedNum != LED2){
        return (DWORD)-1;                                               /*  LED�������                 */
    }
    
    if (hLedFile == INVALID_HANDLE_VALUE){
        return (DWORD)-1;                                               /*  �������û��              */
    }
    
    dwIoCtrl = (dwLedNum == LED1) ? LED1_GET_STATUS : LED2_GET_STATUS;        
    bRet = DeviceIoControl(hLedFile, dwIoCtrl, NULL,
        0, &ucStatus, 1, &dwActLen, NULL);                              /*  ��ȡLED״̬                 */
    if (bRet == FALSE || dwActLen != 1){
        return (DWORD)-1;
    }
    
    return (DWORD)ucStatus;
}

/*********************************************************************************************************
** Function name:   		epcLedFlashProc
** Descriptions:    		������ʹָ����LED����˸��������ΪepcLedFlash()�������½��̵߳���ں���
** input parameters:   	    ((DWORD*)lparam)[0]     LED��ţ�LED1,LED2
**                          ((DWORD*)lparam)[1]     LED��˸����
**                          ((DWORD*)lparam)[2]     LED�����ĳ���ʱ��(ms)
**                          ((DWORD*)lparam)[3]     LEDϨ��ĳ���ʱ��(ms)
** output parameters:   	��
** Returned value:     	    0
** Note:                    lparam�Ŀռ��СΪ4*sizeof(DWORD)���ɵ��������룬�����������ͷš�
*********************************************************************************************************/
static DWORD epcLedFlashProc(LPVOID lparam)
{
    BOOL bRet = TRUE;
    DWORD dwCnt;
    DWORD dwLedNum;
    DWORD dwOntime;
    DWORD dwOfftime;
    DWORD dwFlashTimes;

    dwLedNum     = ((DWORD*)lparam)[0];
    dwFlashTimes = ((DWORD*)lparam)[1];
    dwOntime     = ((DWORD*)lparam)[2];
    dwOfftime    = ((DWORD*)lparam)[3];
    delete[] lparam;                                                    /*  �ͷ��ɵ�����������ڴ�      */

    for (dwCnt=0; dwCnt<dwFlashTimes; dwCnt++){
        
        bRet = epcLedOn(dwLedNum, 0);                                   /*  ����LED                     */
        if (bRet == FALSE){
            break;
        }
        Sleep(dwOntime);                                                /*  ����ָ��ʱ��                */
        
        bRet = epcLedOff(dwLedNum);                                     /*  Ϩ��LED                     */
        if (bRet == FALSE){
            break;
        }
        Sleep(dwOfftime);                                               /*  Ϩ��ָ��ʱ��                */
    }
    /*
     *	���ûص�����֪ͨӦ�ó����������
     */
    if (dwLedNum == LED1 && GfnNotify1 != NULL){
        GfnNotify1(bRet);
    }

    if (dwLedNum == LED2 && GfnNotify2 != NULL){
        GfnNotify2(bRet);
    }
    return 0;
}

/*********************************************************************************************************
** Function name:   		epcLedFlash
** Descriptions:    		������ʹָ����LED����˸
** input parameters:   	    dwLedNum            LED��ţ�LED1,LED2
**                          dwFlashTimes        LED��˸����
**                          dwOntime            LED�����ĳ���ʱ��(ms)
**                          dwOfftime           LEDϨ��ĳ���ʱ��(ms)
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    ���������첽��ʽִ�У����ᱻ����
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedFlash (DWORD dwLedNum, DWORD dwFlashTimes, DWORD dwOntime, DWORD dwOfftime)
{
    if (dwLedNum != LED1 && dwLedNum != LED2){
        return FALSE;                                                   /*  LED�������                 */
    }
        
    if (hLedFile == INVALID_HANDLE_VALUE){
        return FALSE;                                                   /*  �������û��              */
    }
                                                  
    HANDLE hLedThread;
    DWORD *pdwParam;

    /*
     *	����4*sizeof(DWORD)�ռ������洫���½��̵߳Ĳ���������Ŀռ����½��̸߳����ͷ�
     */
    pdwParam = new DWORD[4];                                                      
    pdwParam[0] = dwLedNum; 
    pdwParam[1] = dwFlashTimes;
    pdwParam[2] = dwOntime;
    pdwParam[3] = dwOfftime;

    hLedThread = CreateThread(NULL, 0, epcLedFlashProc,
                             (void*)pdwParam, 0, NULL);                 /*  ���½��߳������LED����     */
                                                                           
    if (hLedThread == NULL){
        delete[] pdwParam;                                              /*  �����߳�ʧ�ܣ��ͷ������ڴ�  */
        return FALSE;
    }
    CloseHandle(hLedThread);
    
    return TRUE;
}

/*********************************************************************************************************
** Function name:   		epcLedAsyncOn
** Descriptions:    		����������ָ����LED��
** input parameters:   	    dwLedNum            LED��ţ�LED1,LED2
**                          dwOntime            LED�����ĳ���ʱ��(ms)������0��ʾһֱ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    ���������첽��ʽִ�У����ᱻ����
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedAsyncOn (DWORD dwLedNum, DWORD dwOntime)
{
    if (dwOntime == 0){
        return epcLedOn(dwLedNum, dwOntime);                            /*  0��ʾһֱ����               */
    } else {
        return epcLedFlash(dwLedNum, 1, dwOntime, 0);
    }
}

/*********************************************************************************************************
** Function name:   		epcLedCallBackFunc
** Descriptions:    		���ûص�����ָ�룬���첽��LED������ɺ󣬻���øûص�����֪ͨ�û�����
** input parameters:   	    dwLedNum        LED��ţ�LED1,LED2
**                          lpfnNotify      �ص�����ָ�룬�����NULL�����ʾ����Ҫ֪ͨ�û����򡣺�����
**                                          ��Ϊvoid (*lpfnNotify)(BOOL bResult),bResultΪִ�н����
**                                          TRUE��ʾִ�гɹ���FALSE��ʾִ��ʧ��                                          
** output parameters:   	��
** Returned value:     	    ��
*********************************************************************************************************/
EPCLEDLIB_API VOID epcLedSetCallBackFunc( DWORD dwLedNum, void (*lpfnNotify)(BOOL))
{
    if (dwLedNum == LED1){
        GfnNotify1 = lpfnNotify;
    } else if (dwLedNum == LED2){
        GfnNotify2 = lpfnNotify;
    }
}
