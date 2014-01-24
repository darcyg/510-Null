
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the EPCLEDLIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// EPCLEDLIB_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef EPCLEDLIB_EXPORTS
#define EPCLEDLIB_API __declspec(dllexport)
#else
#define EPCLEDLIB_API __declspec(dllimport)
#endif

#define  LED1   1
#define  LED2   2
 
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************
** Function name:   		epcLedOn
** Descriptions:    		�˺�������ָ����LED��
** input parameters:   	    dwLedNum            LED��ţ�1--LED1��2--LED2
**                          dwOntime            LED�����ĳ���ʱ��(ms)������0��ʾһֱ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    �ú���������dwOntime(ms)ʱ�䣬��dwOntimeΪ0ʱ�����̷���
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedOn (DWORD dwLedNum, DWORD dwOntime);

/*********************************************************************************************************
** Function name:   		epcLedAsyncOn
** Descriptions:    		�˺�������ָ����LED��
** input parameters:   	    dwLedNum            LED��ţ�1--LED1��2--LED2
**                          dwOntime            LED�����ĳ���ʱ��(ms)������0��ʾһֱ����
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    �ú������첽��ʽִ�У����ᱻ����
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedAsyncOn (DWORD dwLedNum, DWORD dwOntime);

/*********************************************************************************************************
** Function name:   		epcLedOff
** Descriptions:    		�˺���Ϩ��ָ����LED��
** input parameters:   	    dwLedNum            LED��ţ�1--LED1��2--LED2
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedOff (DWORD dwLedNum);

/*********************************************************************************************************
** Function name:   		epcLedFlash
** Descriptions:    		�˺���ʹָ����LED����˸
** input parameters:   	    dwLedNum            LED��ţ�1--LED1��2--LED2
**                          dwFlashTimes        LED��˸����
**                          dwOntime            LED�����ĳ���ʱ��(ms)
**                          dwOfftime           LEDϨ��ĳ���ʱ��(ms)
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    �ú������첽��ʽִ�У����ᱻ����
*********************************************************************************************************/
EPCLEDLIB_API BOOL epcLedFlash (DWORD dwLedNum, DWORD dwFlashTimes, DWORD dwOntime, DWORD dwOfftime);

/*********************************************************************************************************
** Function name:   		epcLedGetStatus
** Descriptions:    		�˺�����ȡָ����LED�Ƶ�״̬
** input parameters:   	    dwLedNum            LED��ţ�1--LED1��2--LED2
** output parameters:   	��
** Returned value:     	    0--������1--Ϩ������--���ִ���
*********************************************************************************************************/
EPCLEDLIB_API DWORD epcLedGetStatus (DWORD dwLedNum);

/*********************************************************************************************************
** Function name:   		epcLedCallBackFunc
** Descriptions:    		���ûص�����ָ�룬���첽��LED������ɺ󣬻���øûص�����֪ͨ�û�����
** input parameters:   	    dwLedNum        LED��ţ�1--LED1��2--LED2
**                          lpfnNotify      �ص�����ָ�룬�����NULL�����ʾ����Ҫ֪ͨ�û����򡣺�����
**                                          ��Ϊvoid (*lpfnNotify)(BOOL bResult),bResultΪִ�н����
**                                          TRUE��ʾִ�гɹ���FALSE��ʾִ��ʧ��                                          
** output parameters:   	��
** Returned value:     	    ��
*********************************************************************************************************/
EPCLEDLIB_API VOID epcLedSetCallBackFunc( DWORD dwLedNum, void (*lpfnNotify)(BOOL));

#ifdef __cplusplus
}
#endif