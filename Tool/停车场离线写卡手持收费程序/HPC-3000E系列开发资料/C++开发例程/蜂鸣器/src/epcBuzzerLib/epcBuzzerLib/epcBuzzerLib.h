// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the EPCBUZZERLIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// EPCBUZZERLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef EPCBUZZERLIB_EXPORTS
#define EPCBUZZERLIB_API __declspec(dllexport)
#else
#define EPCBUZZERLIB_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*********************************************************************************************************
	** Function name:   		epcBuzzerOn
	** Descriptions:    		������ʹ����������ָ��ʱ��
	** input parameters:   	    dwOntime    ����������������ʱ��(ms)������0��ʾһֱ����
	** output parameters:   	��
	** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
	** Note:                    ������������dwOntime(ms)ʱ�䣬��dwOntimeΪ0ʱ�����̷���
	*********************************************************************************************************/
	EPCBUZZERLIB_API BOOL epcBuzzerOn (DWORD dwOntime);

	/*********************************************************************************************************
	** Function name:   		epcBuzzerOff
	** Descriptions:    		������ʹ��������ֹ
	** input parameters:   	    ��
	** output parameters:   	��
	** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
	*********************************************************************************************************/
	EPCBUZZERLIB_API BOOL epcBuzzerOff (VOID);

	/*********************************************************************************************************
	** Function name:   		epcBuzzerGetStatus
	** Descriptions:    		��������ȡ��������״̬
	** input parameters:   	    ��
	** output parameters:   	��
	** Returned value:     	    0--������������1--��������ֹ������--���ִ���
	*********************************************************************************************************/
	EPCBUZZERLIB_API DWORD epcBuzzerGetStatus (VOID);

	/*********************************************************************************************************
	** Function name:   		epcBuzzerAsyncOn
	** Descriptions:    		������ʹ����������ָ��ʱ��
	** input parameters:   	    dwOntime    ����������������ʱ��(ms)������0��ʾһֱ����
	** output parameters:   	��
	** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
	** Note:                    ���������첽��ʽִ�У����ᱻ����
	*********************************************************************************************************/
	EPCBUZZERLIB_API BOOL epcBuzzerAsyncOn (DWORD dwOntime);

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
	EPCBUZZERLIB_API BOOL epcBuzzerBeeps (DWORD dwFlashTimes, DWORD dwOntime, DWORD dwOfftime);

	/*********************************************************************************************************
	** Function name:   		epcBuzzerSetCallBackFunc
	** Descriptions:    		���ûص�����ָ�룬���첽�ķ���������������ɺ󣬻���øûص�����֪ͨ�û�����
	** input parameters:   	    lpfnNotify      �ص�����ָ��,�����NULL�����ʾ����Ҫ֪ͨ�û����򡣺�����
	**                                          ��Ϊvoid (*lpfnNotify)(BOOL bResult),bResultΪִ�н����
	**                                          TRUE��ʾִ�гɹ���FALSE��ʾִ��ʧ��    
	** output parameters:   	��
	** Returned value:     	    ��
	*********************************************************************************************************/
	EPCBUZZERLIB_API VOID epcBuzzerSetCallBackFunc( void (*lpfnNotify)(BOOL));

#ifdef __cplusplus
}
#endif
