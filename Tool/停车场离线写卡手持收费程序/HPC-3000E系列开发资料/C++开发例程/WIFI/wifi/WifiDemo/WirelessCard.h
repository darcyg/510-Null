/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               WirelessCard.h
** Latest modified Date:    2011-06-14
** Latest Version:          1.0
** Descriptions:            
**
**--------------------------------------------------------------------------------------------------------
** Created by:              LiuFei
** Created date:            2011-06-14
** Version:                 1.0
** Descriptions:            Wifi��WZC����
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#if !defined(AFX_WIRELESSCARD_H__8A39692A_7C22_43A7_8303_6460A7F5154C__INCLUDED_)
#define AFX_WIRELESSCARD_H__8A39692A_7C22_43A7_8303_6460A7F5154C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
*  ����WZC API����ؽṹ���ͷ�ļ�
*/
#include "wzcsapi.h"


class CWirelessCard  
{
private:
	TCHAR         *m_szWirelessCard1;                                   /* ��һ������������GUID         */
	INTF_ENTRY_EX  m_Intf;                                              /* �����ѯ����������Ϣ         */
    DWORD          m_dwOutFlags;                                        /* �����ѯʱ�����Flag         */
	DWORD          m_dwSSIDCounts;                                      /* �����ѯʱ�ж��ٸ���������   */
public:
/*********************************************************************************************************
** Function name:           CWirelessCard
**
** Descriptions:            ������������Ҫ�����뻺�棬��ʼ��������
**
** input parameters:        None
** output parameters:       None
** Returned value:          None
*********************************************************************************************************/
	CWirelessCard();

/*********************************************************************************************************
** Function name:           ~CWirelessCard
**
** Descriptions:            ����������ɾ��������ڴ�
**
** input parameters:        None
** output parameters:       None
** Returned value:          None
*********************************************************************************************************/
	virtual ~CWirelessCard();

/*********************************************************************************************************
** Function name:           GetFirstWirelessNetworkCard
**
** Descriptions:            ��ȡ��һ������������GUID(����) 
**
** input parameters:        dwLen             szWirelessCard1�ĳ���
** output parameters:       szWirelessCard1   ��������������
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/	
	BOOL GetFirstWirelessNetworkCard(OUT TCHAR *szWirelessCard1 = NULL,
						             IN DWORD dwLen = 0);

/*********************************************************************************************************
** Function name:           Query
**
** Descriptions:            ��ѯ���������m_Intf��m_dwOutFlags��m_dwSSIDCounts
**
** input parameters:        None
** output parameters:       None
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
	BOOL Query(void);

/*********************************************************************************************************
** Function name:           GetSSIDCounts
**
** Descriptions:            ��ȡɨ�赽���������
**
** input parameters:        None
** output parameters:       None
** Returned value:          ��ȡɨ�赽���������
*********************************************************************************************************/
	DWORD GetSSIDCounts(void);

/*********************************************************************************************************
** Function name:           IsAssociated
**
** Descriptions:            ��ѯ�Ƿ����ӵ�һ�����磬���������������
**
** input parameters:        dwLen      pszSSID �ĳ���
** output parameters:       pszSSID    ���ӳɹ�ʱΪ�����������ƣ�����Ϊ<NO Associated>
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
	BOOL IsAssociated(OUT TCHAR *pszSSID = NULL,
		              IN DWORD dwLen = 0);

/*********************************************************************************************************
** Function name:           GetWzcContext
**
** Descriptions:            ��ѯ��Wireless zero config �����ã���ɨ������
**
** input parameters:        None
** output parameters:       pContext    WZC����������
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
	BOOL GetWzcContext(WZC_CONTEXT *pContext);

/*********************************************************************************************************
** Function name:           SetWzcContext
**
** Descriptions:            ����Wireless zero config �����ã���ɨ������
**
** input parameters:        None
** output parameters:       pContext    WZC����������
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
	BOOL SetWzcContext(WZC_CONTEXT *pContext);

/*********************************************************************************************************
** Function name:           GetWlanConfig
**
** Descriptions:            ������������ȡWZC_WLAN_CONFIG��֮ǰ����ִ��DoQuery
**
** input parameters:        None
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	BOOL GetWlanConfig(DWORD dwIndex,WZC_WLAN_CONFIG *pWlanConfig);

/*********************************************************************************************************
** Function name:           GetWlanSSID
**
** Descriptions:            ��WZC_WLAN_CONFIG����ȡSSID
**
** input parameters:        pWlanConfig  �������ýṹ��ָ��
**                          dwLen        pszSSID���ȣ�������ڵ���33
** output parameters:       pszSSID      �������ƣ���С������ڵ���33(SSID���Ϊ32)
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	BOOL GetWlanSSID(const IN WZC_WLAN_CONFIG *pWlanConfig,
					 OUT TCHAR *pszSSID,
					 IN DWORD dwLen);  

/*********************************************************************************************************
** Function name:           GetWlanMacAddress
**
** Descriptions:            ��WZC_WLAN_CONFIG����ȡMAC��ַ
**
** input parameters:        pWlanConfig  �������ýṹ��ָ��
**                          dwLen        pszMac���ȣ�������ڵ���32
** output parameters:       pszMac       MAC��ַ(Wide Char)����С������ڵ���32
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/	
	BOOL GetWlanMacAddress(const IN WZC_WLAN_CONFIG *pWlanConfig,
		                   OUT TCHAR *pszMac,
		                   IN DWORD dwLen);

/*********************************************************************************************************
** Function name:           GetWlanRssi
**
** Descriptions:            ��WZC_WLAN_CONFIG����ȡ�ź�ǿ��
**
** input parameters:        pWlanConfig  �������ýṹ��ָ��
** output parameters:       plRssi       �ź�ǿ��
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/	
	BOOL GetWlanRssi(const IN WZC_WLAN_CONFIG *pWlanConfig,
					 OUT LONG *plRssi);

/*********************************************************************************************************
** Function name:           GetWlanPrivacyMode
**
** Descriptions:            ��WZC_WLAN_CONFIG����ȡ���ܷ�ʽ
**
** input parameters:        pWlanConfig   �������ýṹ��ָ��
**                          dwLen         szPrivacyMode�ĳ���
** output parameters:       szPrivacyMode ���ܷ�ʽ�����ȱ�����ڵ���36
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	BOOL GetWlanPrivacyMode(const IN WZC_WLAN_CONFIG *pWlanConfig,
							OUT TCHAR *szPrivacyMode,
							IN DWORD dwLen);

/*********************************************************************************************************
** Function name:           AddToPreferredNetworkList
**
** Descriptions:            ��WZC_WLAN_CONFIG����ӵ���ѡ�б�
**
** input parameters:        pWlanConfig   �������ýṹ��ָ��
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	BOOL AddToPreferredNetworkList(IN WZC_WLAN_CONFIG *pWlanConfig);

/*********************************************************************************************************
** Function name:           RemoveAllPreferredNetworkList
**
** Descriptions:            ɾ�����е���ѡ�б�
**
** input parameters:        None
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	BOOL RemoveAllPreferredNetworkList(void);

/*********************************************************************************************************
** Function name:           InterpretEncryptionKeyValue
**
** Descriptions:            ΪWZC_WLAN_CONFIG���һ��Key���ú���Ŀǰ��֧�ֿ���ϵͳWEP��5��13λASCII���룬
**
** input parameters:        pWlanConfig       �������ýṹ��ָ��
**                          szEncryptionKey   ��Կ��������Կ�ַ�������L'\0'����
**                          ulKeyIndex        ��Կ����
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	BOOL InterpretEncryptionKeyValue(IN OUT WZC_WLAN_CONFIG *pWlanConfig,
									 IN TCHAR *szEncryptionKey,
									 IN ULONG ulKeyIndex,
									 IN bool bNeed8021X);
private:
/*********************************************************************************************************
** Function name:           EncryptWepKMaterial
**
** Descriptions:            ��Կת��1
**
** input parameters:        pWlanConfig       �������ýṹ��ָ��
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
	static void EncryptWepKMaterial(IN OUT WZC_WLAN_CONFIG* pwzcConfig);
public:
	
};

#endif // !defined(AFX_WIRELESSCARD_H__8A39692A_7C22_43A7_8303_6460A7F5154C__INCLUDED_)
