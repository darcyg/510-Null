/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               WirelessCard.cpp
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

#include "stdafx.h"
#include "Iphlpapi.h"
#include "WirelessCard.h"

#include <winioctl.h>
#include <ntddndis.h>
#include <nuiouser.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/*
*  ����ʹ�õĿ�
*/
#pragma comment( lib, "./wzcsapi.lib" )  
#pragma comment(lib,"iphlpapi.lib")

/*********************************************************************************************************
** Function name:           CWirelessCard
**
** Descriptions:            ������������Ҫ�����뻺�棬��ʼ��������
**
** input parameters:        None
** output parameters:       None
** Returned value:          None
*********************************************************************************************************/
CWirelessCard::CWirelessCard()
{
	m_szWirelessCard1 = new TCHAR[MAX_PATH];
	m_szWirelessCard1[0] = L'\0';
	ZeroMemory(&m_Intf, sizeof(INTF_ENTRY_EX));
	m_dwSSIDCounts = 0;
}

/*********************************************************************************************************
** Function name:           ~CWirelessCard
**
** Descriptions:            ����������ɾ��������ڴ�
**
** input parameters:        None
** output parameters:       None
** Returned value:          None
*********************************************************************************************************/
CWirelessCard::~CWirelessCard()
{
	if (m_szWirelessCard1) {
		delete[] m_szWirelessCard1;
	}
	if ( m_Intf.bInitialized ) {
		WZCDeleteIntfObjEx(&m_Intf);
	}
}

/*********************************************************************************************************
** Function name:           GetFirstWirelessNetworkCard
**
** Descriptions:            ��ȡ��һ������������GUID(����) 
**
** input parameters:        dwLen             szWirelessCard1�ĳ���
** output parameters:       szWirelessCard1   ��������������
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
BOOL CWirelessCard::GetFirstWirelessNetworkCard(OUT TCHAR *szWirelessCard1 /*= NULL*/,
												IN DWORD dwLen /*= 0*/)
{
	INTFS_KEY_TABLE IntfsTable;
	
	IntfsTable.dwNumIntfs = 0;
    IntfsTable.pIntfs = NULL;

	DWORD dwStatus = WZCEnumInterfaces(NULL, &IntfsTable);
	if ( dwStatus != ERROR_SUCCESS) {
		RETAILMSG(1,(TEXT("WZCEnumInterfaces::Error 0x%08X,return FALSE.\r\n"),dwStatus));
		return FALSE;
	}

	if( !IntfsTable.dwNumIntfs ) {
        RETAILMSG(1,(TEXT("WZCEnumInterfaces::System has no wireless card.return FALSE\r\n")));
        return FALSE;
    }
	if ( (szWirelessCard1 != NULL) && (dwLen >= MAX_PATH)) {
		szWirelessCard1[0] = L'\0';	
		wcsncpy(szWirelessCard1, IntfsTable.pIntfs[0].wszGuid, MAX_PATH-1);
	}
	m_szWirelessCard1[0] = L'\0';
	wcsncpy(m_szWirelessCard1, IntfsTable.pIntfs[0].wszGuid, MAX_PATH-1);
	
	RETAILMSG(0,(TEXT("WZCEnumInterfaces::Wireless card GUID:%s\r\n"),m_szWirelessCard1));

	LocalFree(IntfsTable.pIntfs);
	return TRUE;
}

/*********************************************************************************************************
** Function name:           Query
**
** Descriptions:            ��ѯ���������m_Intf��m_dwOutFlags��m_dwSSIDCounts
**
** input parameters:        None
** output parameters:       None
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
BOOL CWirelessCard::Query(void)
{
	if ( m_Intf.bInitialized ) {                                        /* �ͷ�WZC������ڴ�            */
		WZCDeleteIntfObjEx(&m_Intf);
	}
	if (GetFirstWirelessNetworkCard() == FALSE) {
		return FALSE;
	}
	ZeroMemory(&m_Intf, sizeof(INTF_ENTRY_EX));
	m_Intf.wszGuid = m_szWirelessCard1;

	DWORD dwStatus = WZCQueryInterfaceEx(NULL,INTF_ALL,&m_Intf,&m_dwOutFlags);
	
    if (dwStatus != ERROR_SUCCESS) {
        RETAILMSG(1,(TEXT("WZCQueryInterfaceEx::Error 0x%08X\n\r\n"),dwStatus));
        return FALSE;
    }
	m_dwSSIDCounts = this->GetSSIDCounts();
	return TRUE;
}

/*********************************************************************************************************
** Function name:           IsAssociated
**
** Descriptions:            ��ѯ�Ƿ����ӵ�һ�����磬���������������
**
** input parameters:        dwLen      pszSSID �ĳ���
** output parameters:       pszSSID    ���ӳɹ�ʱΪ�����������ƣ�����Ϊ<NO Associated>
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
BOOL CWirelessCard::IsAssociated(OUT TCHAR *pszSSID /*= NULL*/,
								 IN DWORD dwLen /*= 0*/)
{
	if ( m_Intf.bInitialized == FALSE) {
		return FALSE;
	}
	if (!(m_dwOutFlags & INTF_BSSID)) {
		return FALSE;
	}

	IP_ADAPTER_INFO adapterInfo[10];
	ULONG ulLen = sizeof(IP_ADAPTER_INFO)*10;
	DWORD ret = GetAdaptersInfo(adapterInfo,&ulLen);
	for(int i=0;i<ulLen/sizeof(IP_ADAPTER_INFO);i++)
	{
		bool isThisAdapter = true;
		for(int j=0;adapterInfo[i].AdapterName[j]&&m_szWirelessCard1[j];j++)
		{
			if(adapterInfo[i].AdapterName[j] != m_szWirelessCard1[j])
			{
				isThisAdapter = false;
				break;
			}
		}
		if(isThisAdapter)
		{
			if(strcmp(adapterInfo[i].CurrentIpAddress->IpAddress.String,"0.0.0.0") == 0)
				return FALSE;
			else 
				break;
		}
	}
	if (m_Intf.rdSSID.dwDataLen == 0) {
		return FALSE;
	}
	if ( (pszSSID) && (dwLen >= (NDIS_802_11_LENGTH_SSID+1)) ) {
		MultiByteToWideChar(CP_ACP, 
							0, 
							(char*)m_Intf.rdSSID.pData, 
							m_Intf.rdSSID.dwDataLen, 
							pszSSID,
							m_Intf.rdSSID.dwDataLen);
		pszSSID[m_Intf.rdSSID.dwDataLen] = L'\0';
		RETAILMSG(0,(TEXT("IsAssociated::Conect to %s\r\n"),pszSSID));
	}
	return TRUE;
}


/*********************************************************************************************************
** Function name:           GetWzcContext
**
** Descriptions:            ��ѯ��Wireless zero config �����ã���ɨ������
**
** input parameters:        None
** output parameters:       pContext    WZC����������
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
BOOL CWirelessCard::GetWzcContext(IN WZC_CONTEXT *pContext)
{
	if (pContext == NULL) {
		return FALSE;
	}
    
	DWORD dwStatus = WZCQueryContext(NULL, 0x00, pContext, NULL);
    if (dwStatus != ERROR_SUCCESS) {
        RETAILMSG(1,(TEXT("!!! Failed WZCQueryContext.  Err = [0x%08X] !!!\n"), dwStatus));
		return FALSE;
	}
	return TRUE;
}

/*********************************************************************************************************
** Function name:           SetWzcContext
**
** Descriptions:            ����Wireless zero config �����ã���ɨ������
**
** input parameters:        None
** output parameters:       pContext    WZC����������
** Returned value:          TRUE���ɹ���FALSE��ʧ�� 
*********************************************************************************************************/
BOOL CWirelessCard::SetWzcContext(OUT WZC_CONTEXT *pContext)
{
	if (pContext == NULL) {
		return FALSE;
	}
    
	DWORD dwStatus = WZCSetContext(NULL, 0x00, pContext, NULL);
	if (dwStatus != ERROR_SUCCESS) {
        RETAILMSG(1,(TEXT("!!! Failed SetWzcContext.  Err = [0x%08X] !!!\n"), dwStatus));
		return FALSE;
	}
	return TRUE;
}

/*********************************************************************************************************
** Function name:           GetSSIDCounts
**
** Descriptions:            ��ȡɨ�赽���������
**
** input parameters:        None
** output parameters:       None
** Returned value:          ��ȡɨ�赽���������
*********************************************************************************************************/
DWORD CWirelessCard::GetSSIDCounts(void)
{
	DWORD dwCounts = 0;
	do 
	{
		if ( m_Intf.bInitialized == FALSE) {
			break;
		}

		PWZC_802_11_CONFIG_LIST pWzcConfigList = (PWZC_802_11_CONFIG_LIST)m_Intf.rdBSSIDList.pData;
		if (pWzcConfigList == NULL) {
			break;
		}
		
		dwCounts = pWzcConfigList->NumberOfItems;

	} while(0);

	RETAILMSG(0,(TEXT("GetSSIDCounts::%d\r\n"),dwCounts));
	return dwCounts;
}

/*********************************************************************************************************
** Function name:           GetWlanConfig
**
** Descriptions:            ������������ȡWZC_WLAN_CONFIG��֮ǰ����ִ��DoQuery
**
** input parameters:        None
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
BOOL CWirelessCard::GetWlanConfig(DWORD dwIndex,WZC_WLAN_CONFIG *pWlanConfig)
{
	if ( (m_Intf.bInitialized == FALSE) ||(m_dwSSIDCounts == 0) || 
		 (dwIndex >= m_dwSSIDCounts) || (pWlanConfig == NULL) ) {
		return FALSE;
	}

	PWZC_802_11_CONFIG_LIST pWzcConfigList = (PWZC_802_11_CONFIG_LIST)m_Intf.rdBSSIDList.pData;
	if( (pWzcConfigList == NULL) ) {
		return FALSE;
	}

	memcpy ( pWlanConfig, &pWzcConfigList->Config[dwIndex], sizeof(WZC_WLAN_CONFIG));

	return TRUE;
}

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
BOOL CWirelessCard::GetWlanSSID(const IN WZC_WLAN_CONFIG *pWlanConfig,OUT TCHAR *pszSSID,IN DWORD dwLen)
{
	if( (pWlanConfig == NULL) || (pszSSID == NULL) || ( dwLen < (NDIS_802_11_LENGTH_SSID+1) ) ) {
		return FALSE;
	}
	if (pWlanConfig->Ssid.SsidLength == 0) {
		pszSSID[0] = L'\0';
		wcsncpy(pszSSID, _T("<���ε�AP>"), 33);
	} else {
		MultiByteToWideChar(CP_ACP, 
							0, 
							(char*)pWlanConfig->Ssid.Ssid, 
							pWlanConfig->Ssid.SsidLength, 
							pszSSID,
							pWlanConfig->Ssid.SsidLength);
		pszSSID[pWlanConfig->Ssid.SsidLength] = L'\0';
	}
	return TRUE;
}

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
BOOL CWirelessCard::GetWlanMacAddress(const IN WZC_WLAN_CONFIG *pWlanConfig,OUT TCHAR *pszMac,IN DWORD dwLen)
{
	if( (pWlanConfig == NULL) || (pszMac == NULL) && (dwLen < 32)) {
		return FALSE;
	}

	wsprintf(pszMac,_T("%02X:%02X:%02X:%02X:%02X:%02X"),
                            pWlanConfig->MacAddress[0],
                            pWlanConfig->MacAddress[1],
                            pWlanConfig->MacAddress[2],
                            pWlanConfig->MacAddress[3],
                            pWlanConfig->MacAddress[4],
                            pWlanConfig->MacAddress[5]);
	return TRUE;
}

/*********************************************************************************************************
** Function name:           GetWlanRssi
**
** Descriptions:            ��WZC_WLAN_CONFIG����ȡ�ź�ǿ��
**
** input parameters:        pWlanConfig  �������ýṹ��ָ��
** output parameters:       plRssi       �ź�ǿ��
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
BOOL CWirelessCard::GetWlanRssi(const IN WZC_WLAN_CONFIG *pWlanConfig,OUT LONG *plRssi)
{
	if( (pWlanConfig == NULL) || (plRssi == NULL) ) {
		return FALSE;
	}
	*plRssi = pWlanConfig->Rssi;
	return TRUE;
}


const static TCHAR *GszPrivacyMode[8] = {
	L"Ndis802_11WEPEnabled", 
	L"Ndis802_11WEPDisabled",
	L"Ndis802_11WEPKeyAbsent",
	L"Ndis802_11WEPNotSupported",
	L"Ndis802_11Encryption2Enabled",
	L"Ndis802_11Encryption2KeyAbsent",
	L"Ndis802_11Encryption3Enabled",
	L"Ndis802_11Encryption3KeyAbsent"
};

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
BOOL CWirelessCard::GetWlanPrivacyMode(const IN WZC_WLAN_CONFIG *pWlanConfig,
									   OUT TCHAR *szPrivacyMode,
									   IN DWORD dwLen)
{
	if( (pWlanConfig == NULL) || (szPrivacyMode == NULL) || (dwLen < 36) ) {
		return FALSE;
	}
	ULONG ulMode = pWlanConfig->Privacy;
	if (ulMode >= 8) {
		szPrivacyMode[0] = L'\0';
		wcsncpy(szPrivacyMode, _T("<No Supported>"), 36);
		return FALSE;
	}
	szPrivacyMode[0] = L'\0';
	wcsncpy(szPrivacyMode, GszPrivacyMode[ulMode], 36);
	return TRUE;
}

/*********************************************************************************************************
** Function name:           AddToPreferredNetworkList
**
** Descriptions:            ��WZC_WLAN_CONFIG����ӵ���ѡ�б�
**
** input parameters:        pWlanConfig   �������ýṹ��ָ��
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
BOOL CWirelessCard::AddToPreferredNetworkList(IN WZC_WLAN_CONFIG *pWlanConfig)
{
	if ( (m_Intf.bInitialized == FALSE) || (pWlanConfig == NULL) ){
		return FALSE;
	}	

	TCHAR szSSID[NDIS_802_11_LENGTH_SSID+1];

	this->GetWlanSSID(pWlanConfig,szSSID,NDIS_802_11_LENGTH_SSID+1);
	
	WZC_802_11_CONFIG_LIST *pConfigList = (PWZC_802_11_CONFIG_LIST)m_Intf.rdStSSIDList.pData;

	if (!pConfigList) {                                                 /* ��ǰû����ѡ�б�             */
		DWORD dwDataLen = sizeof(WZC_802_11_CONFIG_LIST);
		/*  
		*  Ϊm_Intf����һ����ѡ���������б�
		*/
        WZC_802_11_CONFIG_LIST *pNewConfigList = (WZC_802_11_CONFIG_LIST *)LocalAlloc(LPTR, dwDataLen);
        pNewConfigList->NumberOfItems = 1;
        pNewConfigList->Index = 0;
        memcpy(pNewConfigList->Config, pWlanConfig, sizeof(WZC_WLAN_CONFIG));
        m_Intf.rdStSSIDList.pData = (BYTE*)pNewConfigList;
        m_Intf.rdStSSIDList.dwDataLen = dwDataLen;
	} else {
		bool same = false;
		ULONG uiNumberOfItems = pConfigList->NumberOfItems;
        for(UINT i=0; i<uiNumberOfItems; i++) {
            if(memcmp(&pWlanConfig->Ssid, &pConfigList->Config[i].Ssid, sizeof(NDIS_802_11_SSID)) == 0
				&& memcmp(&pWlanConfig->MacAddress,&pConfigList->Config[i].MacAddress,sizeof(NDIS_802_11_MAC_ADDRESS)) == 0) {
// 				RETAILMSG(1,(TEXT("%s is already in Preferred Net Work List\r\n"),szSSID));
//                 return FALSE;
				same = true;
				memcpy(&pConfigList->Config[i],pWlanConfig,sizeof(WZC_WLAN_CONFIG));
				
				//�����ѡ�б�Ȼ������ӣ���Ȼֱ�Ӷ���Կ���޸Ĳ�������
				INTF_ENTRY_EX tmp = m_Intf;
				tmp.rdStSSIDList.dwDataLen = 0;
				tmp.rdStSSIDList.pData = NULL;
				DWORD ret = WZCSetInterfaceEx(NULL, INTF_PREFLIST, &tmp, &m_dwOutFlags);
				break;
            }
        }

		/*  
		*  Ϊm_Intf���һ����ѡ���������б�
		*/
		if(!same)
		{
			DWORD dwDataLen = sizeof(WZC_802_11_CONFIG_LIST) + (uiNumberOfItems+1)*sizeof(WZC_WLAN_CONFIG);
			WZC_802_11_CONFIG_LIST *pNewConfigList = (WZC_802_11_CONFIG_LIST *)LocalAlloc(LPTR, dwDataLen);
			pNewConfigList->NumberOfItems = uiNumberOfItems + 1;
			pNewConfigList->Index = 0;

			memcpy(pNewConfigList->Config, pWlanConfig, sizeof(WZC_WLAN_CONFIG));
			
			if(pConfigList->NumberOfItems) {
				/*
				*  ���ƾɵ��б��»�����
				*/
				pNewConfigList->Index = pConfigList->Index;
				memcpy(pNewConfigList->Config+1, pConfigList->Config, (uiNumberOfItems)*sizeof(WZC_WLAN_CONFIG));
				LocalFree(pConfigList);
				pConfigList = NULL;
			}
			m_Intf.rdStSSIDList.pData = (BYTE*)pNewConfigList;
			m_Intf.rdStSSIDList.dwDataLen = dwDataLen;
		}
	}

	DWORD dwStatus = WZCSetInterfaceEx(NULL, INTF_PREFLIST, &m_Intf, &m_dwOutFlags);
	if ( dwStatus != ERROR_SUCCESS) {
		return FALSE;
	}

	return TRUE;
}

/*********************************************************************************************************
** Function name:           RemoveAllPreferredNetworkList
**
** Descriptions:            ɾ�����е���ѡ�б�
**
** input parameters:        None
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
BOOL CWirelessCard::RemoveAllPreferredNetworkList(void)
{
	if (m_Intf.bInitialized == FALSE) {
		return FALSE;
	}
	WZC_802_11_CONFIG_LIST *pConfigList = (PWZC_802_11_CONFIG_LIST)m_Intf.rdStSSIDList.pData;
	if (pConfigList != NULL) {
		LocalFree(pConfigList);
		pConfigList = NULL;
	} else {
		return TRUE;
	}
	m_Intf.rdStSSIDList.pData = NULL;
	m_Intf.rdStSSIDList.dwDataLen = 0;
	DWORD dwStatus = WZCSetInterfaceEx(NULL, INTF_PREFLIST, &m_Intf, &m_dwOutFlags);
	if ( dwStatus != ERROR_SUCCESS) {
		return FALSE;
	}
	
	return TRUE;
}

inline unsigned HEX(TCHAR c)
{
	char ch = toupper((char)c);
	if(isdigit(ch))
		return ch-'0';
	else
		return ch-'A'+10;
}
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
BOOL CWirelessCard::InterpretEncryptionKeyValue(IN OUT WZC_WLAN_CONFIG *pWlanConfig,
												IN TCHAR *pKey,
												IN ULONG iKeyIndex,
												IN bool bNeed8021X)
{
	if ( (pWlanConfig == NULL) || (iKeyIndex > 4)){
		return FALSE;
	}

	if(pWlanConfig->Privacy == Ndis802_11WEPEnabled)     
	{      
		if(!bNeed8021X && pKey)      
		{      
			pWlanConfig->KeyIndex = iKeyIndex;     
			pWlanConfig->KeyLength = _tcslen(pKey);     

			if((pWlanConfig->KeyLength == 5) || (pWlanConfig->KeyLength == 13))     
			{     
				for(UINT i=0; i<pWlanConfig->KeyLength; i++)     
					pWlanConfig->KeyMaterial[i] = (UCHAR)pKey[i];     
			}     
			else     
			{     
				if((pKey[0] != TEXT('0')) || (pKey[1] != TEXT('x')))     
				{      
					//                    RETAILMSG(DBG_MSG, (TEXT("Invalid key value.\n")));       
					return FALSE;     
				}     
				pKey += 2;     
				pWlanConfig->KeyLength = wcslen(pKey);     
				if((pWlanConfig->KeyLength != 10) && (pWlanConfig->KeyLength != 26))     
				{     
					//                    RETAILMSG(DBG_MSG, (TEXT("Invalid key value.\n")));       
					return FALSE;     
				}     
				pWlanConfig->KeyLength >>= 1;     
				for(UINT i=0; i<pWlanConfig->KeyLength; i++)     
				{     
					pWlanConfig->KeyMaterial[i] = (HEX(pKey[2 * i]) << 4) | HEX(pKey[2 * i + 1]);     
				}      
			}     
			EncryptWepKMaterial(pWlanConfig);     
			pWlanConfig->dwCtlFlags |= WZCCTL_WEPK_PRESENT;     
		}     
	}     
	else if(pWlanConfig->Privacy == Ndis802_11Encryption2Enabled     
		|| pWlanConfig->Privacy == Ndis802_11Encryption3Enabled)     
	{      
		if(!bNeed8021X && pKey)      
		{     
			pWlanConfig->KeyLength = wcslen(pKey);     
			if((pWlanConfig->KeyLength < 8) || (pWlanConfig->KeyLength > 63))     
			{     
				//                RETAILMSG(DBG_MSG, (TEXT("WPA-PSK/TKIP key should be 8-63 char long string.\n")));       
				return FALSE;     
			}   
			char szEncryptionKeyValue8[64]; // longest key is 63      
			memset(szEncryptionKeyValue8, 0, sizeof(szEncryptionKeyValue8));     
			WideCharToMultiByte(CP_ACP,     
				0,     
				pKey,     
				pWlanConfig->KeyLength + 1,     
				szEncryptionKeyValue8,     
				pWlanConfig->KeyLength + 1,     
				NULL,     
				NULL);     
			WZCPassword2Key(pWlanConfig, szEncryptionKeyValue8);     
			EncryptWepKMaterial(pWlanConfig);     
			pWlanConfig->dwCtlFlags |= WZCCTL_WEPK_XFORMAT     
				| WZCCTL_WEPK_PRESENT     
				| WZCCTL_ONEX_ENABLED;     
		}     
		pWlanConfig->EapolParams.dwEapFlags = EAPOL_ENABLED;     
		pWlanConfig->EapolParams.dwEapType = DEFAULT_EAP_TYPE;     
		pWlanConfig->EapolParams.bEnable8021x = TRUE;     
		pWlanConfig->WPAMCastCipher = Ndis802_11Encryption2Enabled;     
	}   
	return TRUE;
}

/*********************************************************************************************************
** Function name:           EncryptWepKMaterial
**
** Descriptions:            ��Կת��1
**
** input parameters:        pWlanConfig       �������ýṹ��ָ��
** output parameters:       None
** Returned value:          TRUE �ɹ���FALSE ʧ��
*********************************************************************************************************/
void CWirelessCard::EncryptWepKMaterial(IN OUT WZC_WLAN_CONFIG* pwzcConfig) 
{ 
    BYTE chFakeKeyMaterial[] = { 0x56, 0x09, 0x08, 0x98, 0x4D, 0x08, 0x11, 0x66, 0x42, 0x03, 0x01, 0x67, 0x66 }; 
    for (int i = 0; i < WZCCTL_MAX_WEPK_MATERIAL; i++) {
        pwzcConfig->KeyMaterial[i] ^= chFakeKeyMaterial[(7*i)%13]; 
	}
}

