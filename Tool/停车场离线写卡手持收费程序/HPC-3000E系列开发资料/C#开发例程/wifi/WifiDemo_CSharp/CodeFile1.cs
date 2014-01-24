﻿using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace bakeup

{
    // Warning: <unknown> 10: Could not locate include file ntddndis.h
    // Error: Failed to resolve name 'PINTF_ENTRY_EX'
    // Error: Failed to resolve name 'PINTF_ENTRY_EX'
    // Error: Failed to resolve name 'PINTF_ENTRY_EX'
    // Error: Failed to resolve name 'PINTF_ENTRY_EX'

    public partial class NativeConstants
    {

        /// NDIS_802_11_LENGTH_SSID -> 32
        public const int NDIS_802_11_LENGTH_SSID = 32;

        /// NDIS_802_11_LENGTH_RATES -> 8
        public const int NDIS_802_11_LENGTH_RATES = 8;

        /// NDIS_802_11_LENGTH_RATES_EX -> 16
        public const int NDIS_802_11_LENGTH_RATES_EX = 16;

        /// NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS -> 0x0f
        public const int NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS = 15;

        /// NDIS_802_11_AUTH_REQUEST_REAUTH -> 0x01
        public const int NDIS_802_11_AUTH_REQUEST_REAUTH = 1;

        /// NDIS_802_11_AUTH_REQUEST_KEYUPDATE -> 0x02
        public const int NDIS_802_11_AUTH_REQUEST_KEYUPDATE = 2;

        /// NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR -> 0x06
        public const int NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR = 6;

        /// NDIS_802_11_AUTH_REQUEST_GROUP_ERROR -> 0x0E
        public const int NDIS_802_11_AUTH_REQUEST_GROUP_ERROR = 14;

        /// NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED -> 0x01
        public const int NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED = 1;

        /// NDIS_802_11_AI_REQFI_CAPABILITIES -> 1
        public const int NDIS_802_11_AI_REQFI_CAPABILITIES = 1;

        /// NDIS_802_11_AI_REQFI_LISTENINTERVAL -> 2
        public const int NDIS_802_11_AI_REQFI_LISTENINTERVAL = 2;

        /// NDIS_802_11_AI_REQFI_CURRENTAPADDRESS -> 4
        public const int NDIS_802_11_AI_REQFI_CURRENTAPADDRESS = 4;

        /// NDIS_802_11_AI_RESFI_CAPABILITIES -> 1
        public const int NDIS_802_11_AI_RESFI_CAPABILITIES = 1;

        /// NDIS_802_11_AI_RESFI_STATUSCODE -> 2
        public const int NDIS_802_11_AI_RESFI_STATUSCODE = 2;

        /// NDIS_802_11_AI_RESFI_ASSOCIATIONID -> 4
        public const int NDIS_802_11_AI_RESFI_ASSOCIATIONID = 4;

        /// _WZCAPI_H_ -> 
        /// Error generating expression: 值不能为空。
        ///参数名: node
        public const string _WZCAPI_H_ = "";

        /// NWB_AUTHMODE_MASK -> 0x03
        public const int NWB_AUTHMODE_MASK = 3;

        /// NWB_SELCATEG_MASK -> 0x1C
        public const int NWB_SELCATEG_MASK = 28;

        /// WZCCTL_MAX_WEPK_MATERIAL -> 32
        public const int WZCCTL_MAX_WEPK_MATERIAL = 32;

        /// WZCCTL_WEPK_PRESENT -> 0x0001
        public const int WZCCTL_WEPK_PRESENT = 1;

        /// WZCCTL_WEPK_XFORMAT -> 0x0002
        public const int WZCCTL_WEPK_XFORMAT = 2;

        /// WZCCTL_VOLATILE -> 0x0004
        public const int WZCCTL_VOLATILE = 4;

        /// WZCCTL_POLICY -> 0x0008
        public const int WZCCTL_POLICY = 8;

        /// WZCCTL_ONEX_ENABLED -> 0x0010
        public const int WZCCTL_ONEX_ENABLED = 16;

        /// WZCDLG_FAILED -> 0x00010001
        public const int WZCDLG_FAILED = 65537;

        /// INTF_ALL -> 0xffffffff
        public const int INTF_ALL = -1;

        /// INTF_ALL_FLAGS -> 0x0000ffff
        public const int INTF_ALL_FLAGS = 65535;

        /// INTF_CM_MASK -> 0x00000007
        public const int INTF_CM_MASK = 7;

        /// INTF_ENABLED -> 0x00008000
        public const int INTF_ENABLED = 32768;

        /// INTF_FALLBACK -> 0x00004000
        public const int INTF_FALLBACK = 16384;

        /// INTF_OIDSSUPP -> 0x00002000
        public const int INTF_OIDSSUPP = 8192;

        /// INTF_VOLATILE -> 0x00001000
        public const int INTF_VOLATILE = 4096;

        /// INTF_POLICY -> 0x00000800
        public const int INTF_POLICY = 2048;

        /// INTF_DESCR -> 0x00010000
        public const int INTF_DESCR = 65536;

        /// INTF_NDISMEDIA -> 0x00020000
        public const int INTF_NDISMEDIA = 131072;

        /// INTF_PREFLIST -> 0x00040000
        public const int INTF_PREFLIST = 262144;

        /// INTF_CAPABILITIES -> 0x00080000
        public const int INTF_CAPABILITIES = 524288;

        /// INTF_ALL_OIDS -> 0xfff00000
        public const int INTF_ALL_OIDS = -1048576;

        /// INTF_HANDLE -> 0x00100000
        public const int INTF_HANDLE = 1048576;

        /// INTF_INFRAMODE -> 0x00200000
        public const int INTF_INFRAMODE = 2097152;

        /// INTF_AUTHMODE -> 0x00400000
        public const int INTF_AUTHMODE = 4194304;

        /// INTF_WEPSTATUS -> 0x00800000
        public const int INTF_WEPSTATUS = 8388608;

        /// INTF_SSID -> 0x01000000
        public const int INTF_SSID = 16777216;

        /// INTF_BSSID -> 0x02000000
        public const int INTF_BSSID = 33554432;

        /// INTF_BSSIDLIST -> 0x04000000
        public const int INTF_BSSIDLIST = 67108864;

        /// INTF_LIST_SCAN -> 0x08000000
        public const int INTF_LIST_SCAN = 134217728;

        /// INTF_ADDWEPKEY -> 0x10000000
        public const int INTF_ADDWEPKEY = 268435456;

        /// INTF_REMWEPKEY -> 0x20000000
        public const int INTF_REMWEPKEY = 536870912;

        /// INTF_LDDEFWKEY -> 0x40000000
        public const int INTF_LDDEFWKEY = 1073741824;

        /// INTFCTL_CM_MASK -> 0x0007
        public const int INTFCTL_CM_MASK = 7;

        /// INTFCTL_ENABLED -> 0x8000
        public const int INTFCTL_ENABLED = 32768;

        /// INTFCTL_FALLBACK -> 0x4000
        public const int INTFCTL_FALLBACK = 16384;

        /// INTFCTL_OIDSSUPP -> 0x2000
        public const int INTFCTL_OIDSSUPP = 8192;

        /// INTFCTL_VOLATILE -> 0x1000
        public const int INTFCTL_VOLATILE = 4096;

        /// INTFCTL_POLICY -> 0x0800
        public const int INTFCTL_POLICY = 2048;

        /// INTFCAP_MAX_CIPHER_MASK -> 0x000000ff
        public const int INTFCAP_MAX_CIPHER_MASK = 255;

        /// INTFCAP_SSN -> 0x00000100
        public const int INTFCAP_SSN = 256;

        /// INTFCAP_80211I -> 0x00000200
        public const int INTFCAP_80211I = 512;

        /// TMMS_DEFAULT_TR -> 0x00000bb8
        public const int TMMS_DEFAULT_TR = 3000;

        /// TMMS_DEFAULT_TC -> 0x0000ea60
        public const int TMMS_DEFAULT_TC = 60000;

        /// TMMS_DEFAULT_TP -> 0x000007d0
        public const int TMMS_DEFAULT_TP = 2000;

        /// TMMS_DEFAULT_TF -> 0x0000ea60
        public const int TMMS_DEFAULT_TF = 60000;

        /// TMMS_DEFAULT_TD -> 0x00001388
        public const int TMMS_DEFAULT_TD = 5000;

        /// WZC_CTXT_LOGGING_ON -> 0x00000001
        public const int WZC_CTXT_LOGGING_ON = 1;

        /// WZC_CONTEXT_CTL_LOG -> 0x00000001
        public const int WZC_CONTEXT_CTL_LOG = 1;

        /// WZC_CONTEXT_CTL_TIMER_TR -> 0x00000002
        public const int WZC_CONTEXT_CTL_TIMER_TR = 2;

        /// WZC_CONTEXT_CTL_TIMER_TC -> 0x00000004
        public const int WZC_CONTEXT_CTL_TIMER_TC = 4;

        /// WZC_CONTEXT_CTL_TIMER_TP -> 0x00000008
        public const int WZC_CONTEXT_CTL_TIMER_TP = 8;

        /// WZC_CONTEXT_CTL_TIMER_TF -> 0x00000010
        public const int WZC_CONTEXT_CTL_TIMER_TF = 16;

        /// WZC_CONTEXT_CTL_TIMER_TD -> 0x00000020
        public const int WZC_CONTEXT_CTL_TIMER_TD = 32;

        /// EAPOL_DISABLED -> 0
        public const int EAPOL_DISABLED = 0;

        /// EAPOL_ENABLED -> 0x80000000
        public const int EAPOL_ENABLED = -2147483648;

        /// EAPOL_MACHINE_AUTH_DISABLED -> 0
        public const int EAPOL_MACHINE_AUTH_DISABLED = 0;

        /// EAPOL_MACHINE_AUTH_ENABLED -> 0x40000000
        public const int EAPOL_MACHINE_AUTH_ENABLED = 1073741824;

        /// EAPOL_GUEST_AUTH_DISABLED -> 0
        public const int EAPOL_GUEST_AUTH_DISABLED = 0;

        /// EAPOL_GUEST_AUTH_ENABLED -> 0x20000000
        public const int EAPOL_GUEST_AUTH_ENABLED = 536870912;

        /// EAP_TYPE_MD5 -> 4
        public const int EAP_TYPE_MD5 = 4;

        /// EAP_TYPE_TLS -> 13
        public const int EAP_TYPE_TLS = 13;

        /// EAP_TYPE_PEAP -> 25
        public const int EAP_TYPE_PEAP = 25;

        /// EAP_TYPE_MSCHAPv2 -> 26
        public const int EAP_TYPE_MSCHAPv2 = 26;

        /// DEFAULT_EAP_TYPE -> EAP_TYPE_TLS
        public const int DEFAULT_EAP_TYPE = NativeConstants.EAP_TYPE_TLS;

        /// DEFAULT_EAPOL_STATE -> EAPOL_ENABLED
        public const int DEFAULT_EAPOL_STATE = NativeConstants.EAPOL_ENABLED;

        /// DEFAULT_MACHINE_AUTH_STATE -> EAPOL_MACHINE_AUTH_ENABLED
        public const int DEFAULT_MACHINE_AUTH_STATE = NativeConstants.EAPOL_MACHINE_AUTH_ENABLED;

        /// DEFAULT_GUEST_AUTH_STATE -> EAPOL_GUEST_AUTH_DISABLED
        public const int DEFAULT_GUEST_AUTH_STATE = NativeConstants.EAPOL_GUEST_AUTH_DISABLED;

        /// DEFAULT_EAP_STATE -> (DEFAULT_EAPOL_STATE | DEFAULT_MACHINE_AUTH_STATE | DEFAULT_GUEST_AUTH_STATE)
        public const int DEFAULT_EAP_STATE = (NativeConstants.DEFAULT_EAPOL_STATE
                    | (NativeConstants.DEFAULT_MACHINE_AUTH_STATE |

    NativeConstants.DEFAULT_GUEST_AUTH_STATE));

        /// SUPPLICANT_MODE_0 -> 0
        public const int SUPPLICANT_MODE_0 = 0;

        /// SUPPLICANT_MODE_1 -> 1
        public const int SUPPLICANT_MODE_1 = 1;

        /// SUPPLICANT_MODE_2 -> 2
        public const int SUPPLICANT_MODE_2 = 2;

        /// SUPPLICANT_MODE_3 -> 3
        public const int SUPPLICANT_MODE_3 = 3;

        /// MAX_SUPPLICANT_MODE -> SUPPLICANT_MODE_3
        public const int MAX_SUPPLICANT_MODE = NativeConstants.SUPPLICANT_MODE_3;

        /// EAPOL_DEFAULT_SUPPLICANT_MODE -> SUPPLICANT_MODE_2
        public const int EAPOL_DEFAULT_SUPPLICANT_MODE = NativeConstants.SUPPLICANT_MODE_2;

        /// EAPOL_AUTH_MODE_0 -> 0
        public const int EAPOL_AUTH_MODE_0 = 0;

        /// EAPOL_AUTH_MODE_1 -> 1
        public const int EAPOL_AUTH_MODE_1 = 1;

        /// EAPOL_AUTH_MODE_2 -> 2
        public const int EAPOL_AUTH_MODE_2 = 2;

        /// MAX_EAPOL_AUTH_MODE -> EAPOL_AUTH_MODE_2
        public const int MAX_EAPOL_AUTH_MODE = NativeConstants.EAPOL_AUTH_MODE_2;

        /// EAPOL_DEFAULT_AUTH_MODE -> EAPOL_AUTH_MODE_1
        public const int EAPOL_DEFAULT_AUTH_MODE = NativeConstants.EAPOL_AUTH_MODE_1;

        /// GUID_STRING_LEN_WITH_TERM -> 39
        public const int GUID_STRING_LEN_WITH_TERM = 39;

        /// RAS_EAP_VALUENAME_HIDEPEAPMSCHAPv2 -> TEXT("HidePEAPMSCHAPv2")
        /// Error generating expression: Error generating function call.  Operation not implemented
        public const string RAS_EAP_VALUENAME_HIDEPEAPMSCHAPv2 = "HidePEAPMSCHAPv2";

        /// EAPCFG_FLAG_RequireUsername -> 0x1
        public const int EAPCFG_FLAG_RequireUsername = 1;

        /// EAPCFG_FLAG_RequirePassword -> 0x2
        public const int EAPCFG_FLAG_RequirePassword = 2;

        /// EAPOL_MUTUAL_AUTH_EAP_ONLY -> 0x00000001
        public const int EAPOL_MUTUAL_AUTH_EAP_ONLY = 1;

        /// MAX_SSID_LEN -> 32
        public const int MAX_SSID_LEN = 32;

        /// EAPOL_VERSION_1 -> 1
        public const int EAPOL_VERSION_1 = 1;

        /// EAPOL_VERSION_2 -> 2
        public const int EAPOL_VERSION_2 = 2;

        /// EAPOL_VERSION_3 -> 3
        public const int EAPOL_VERSION_3 = 3;

        /// EAPOL_CURRENT_VERSION -> EAPOL_VERSION_3
        public const int EAPOL_CURRENT_VERSION = NativeConstants.EAPOL_VERSION_3;

        /// NUM_RESP_BLOBS -> 3
        public const int NUM_RESP_BLOBS = 3;

        /// EAPOL_CERT_TYPE_SMARTCARD -> 1
        public const int EAPOL_CERT_TYPE_SMARTCARD = 1;

        /// EAPOL_CERT_TYPE_MC_CERT -> 2
        public const int EAPOL_CERT_TYPE_MC_CERT = 2;

        /// EAPOLUI_GET_USERIDENTITY -> 0x00000001
        public const int EAPOLUI_GET_USERIDENTITY = 1;

        /// EAPOLUI_GET_USERNAMEPASSWORD -> 0x00000002
        public const int EAPOLUI_GET_USERNAMEPASSWORD = 2;

        /// EAPOLUI_INVOKEINTERACTIVEUI -> 0x00000004
        public const int EAPOLUI_INVOKEINTERACTIVEUI = 4;

        /// EAPOLUI_EAP_NOTIFICATION -> 0x00000008
        public const int EAPOLUI_EAP_NOTIFICATION = 8;

        /// EAPOLUI_REAUTHENTICATE -> 0x00000010
        public const int EAPOLUI_REAUTHENTICATE = 16;

        /// EAPOLUI_CREATEBALLOON -> 0x00000020
        public const int EAPOLUI_CREATEBALLOON = 32;

        /// EAPOLUI_CLEANUP -> 0x00000040
        public const int EAPOLUI_CLEANUP = 64;

        /// EAPOLUI_DUMMY -> 0x00000080
        public const int EAPOLUI_DUMMY = 128;

        /// NUM_EAPOL_DLG_MSGS -> 8
        public const int NUM_EAPOL_DLG_MSGS = 8;

        /// WZC_PORTFLAGS_UP -> 0x00000001
        public const int WZC_PORTFLAGS_UP = 1;

        /// WZC_PORTFLAGS_DOWN -> 0x00000002
        public const int WZC_PORTFLAGS_DOWN = 2;

        /// WZC_PORTFLAGS_SUCCESSFUL_ROAM -> 0x00000004
        public const int WZC_PORTFLAGS_SUCCESSFUL_ROAM = 4;

        /// WZC_PORTFLAGS_PEERMAC_AVAILABLE -> 0x00000008
        public const int WZC_PORTFLAGS_PEERMAC_AVAILABLE = 8;
    }

    public enum NDIS_802_11_STATUS_TYPE
    {

        Ndis802_11StatusType_Authentication,

        Ndis802_11StatusType_MediaStreamMode,

        Ndis802_11StatusType_PMKID_CandidateList,

        Ndis802_11StatusTypeMax,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_STATUS_INDICATION
    {

        /// NDIS_802_11_STATUS_TYPE->_NDIS_802_11_STATUS_TYPE
        public NDIS_802_11_STATUS_TYPE StatusType;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_AUTHENTICATION_REQUEST
    {

        /// ULONG->unsigned int
        public uint Length;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string Bssid;

        /// ULONG->unsigned int
        public uint Flags;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct PMKID_CANDIDATE
    {

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string BSSID;

        /// ULONG->unsigned int
        public uint Flags;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_PMKID_CANDIDATE_LIST
    {

        /// ULONG->unsigned int
        public uint Version;

        /// ULONG->unsigned int
        public uint NumCandidates;

        /// PMKID_CANDIDATE[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public PMKID_CANDIDATE[] CandidateList;
    }

    public enum NDIS_802_11_NETWORK_TYPE
    {

        Ndis802_11FH,

        Ndis802_11DS,

        Ndis802_11OFDM5,

        Ndis802_11OFDM24,

        Ndis802_11Automode,

        Ndis802_11NetworkTypeMax,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_NETWORK_TYPE_LIST
    {

        /// ULONG->unsigned int
        public uint NumberOfItems;

        /// NDIS_802_11_NETWORK_TYPE[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public NDIS_802_11_NETWORK_TYPE[] NetworkType;
    }

    public enum NDIS_802_11_POWER_MODE
    {

        Ndis802_11PowerModeCAM,

        Ndis802_11PowerModeMAX_PSP,

        Ndis802_11PowerModeFast_PSP,

        Ndis802_11PowerModeMax,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_CONFIGURATION_FH
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint HopPattern;

        /// ULONG->unsigned int
        public uint HopSet;

        /// ULONG->unsigned int
        public uint DwellTime;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_CONFIGURATION
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint BeaconPeriod;

        /// ULONG->unsigned int
        public uint ATIMWindow;

        /// ULONG->unsigned int
        public uint DSConfig;

        /// NDIS_802_11_CONFIGURATION_FH->_NDIS_802_11_CONFIGURATION_FH
        public NDIS_802_11_CONFIGURATION_FH FHConfig;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_STATISTICS
    {

        /// ULONG->unsigned int
        public uint Length;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER TransmittedFragmentCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER MulticastTransmittedFrameCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER FailedCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER RetryCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER MultipleRetryCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER RTSSuccessCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER RTSFailureCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER ACKFailureCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER FrameDuplicateCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER ReceivedFragmentCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER MulticastReceivedFrameCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER FCSErrorCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER TKIPLocalMICFailures;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER TKIPICVErrorCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER TKIPCounterMeasuresInvoked;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER TKIPReplays;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER CCMPFormatErrors;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER CCMPReplays;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER CCMPDecryptErrors;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER FourWayHandshakeFailures;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER WEPUndecryptableCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER WEPICVErrorCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER DecryptSuccessCount;

        /// LARGE_INTEGER->_LARGE_INTEGER
        public LARGE_INTEGER DecryptFailureCount;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_KEY
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint KeyIndex;

        /// ULONG->unsigned int
        public uint KeyLength;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string BSSID;

        /// NDIS_802_11_KEY_RSC->ULONGLONG->unsigned __int64
        public ulong KeyRSC;

        /// UCHAR[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 1)]
        public string KeyMaterial;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_REMOVE_KEY
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint KeyIndex;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string BSSID;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_WEP
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint KeyIndex;

        /// ULONG->unsigned int
        public uint KeyLength;

        /// UCHAR[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 1)]
        public string KeyMaterial;
    }

    public enum NDIS_802_11_NETWORK_INFRASTRUCTURE
    {

        Ndis802_11IBSS,

        Ndis802_11Infrastructure,

        Ndis802_11AutoUnknown,

        Ndis802_11InfrastructureMax,
    }

    public enum NDIS_802_11_AUTHENTICATION_MODE
    {

        Ndis802_11AuthModeOpen,

        Ndis802_11AuthModeShared,

        Ndis802_11AuthModeAutoSwitch,

        Ndis802_11AuthModeWPA,

        Ndis802_11AuthModeWPAPSK,

        Ndis802_11AuthModeWPANone,

        Ndis802_11AuthModeWPA2,

        Ndis802_11AuthModeWPA2PSK,

        Ndis802_11AuthModeMax,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_SSID
    {

        /// ULONG->unsigned int
        public uint SsidLength;

        /// UCHAR[32]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 32)]
        public string Ssid;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_WLAN_BSSID
    {

        /// ULONG->unsigned int
        public uint Length;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string MacAddress;

        /// UCHAR[2]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 2)]
        public string Reserved;

        /// NDIS_802_11_SSID->_NDIS_802_11_SSID
        public NDIS_802_11_SSID Ssid;

        /// ULONG->unsigned int
        public uint Privacy;

        /// NDIS_802_11_RSSI->LONG->int
        public int Rssi;

        /// NDIS_802_11_NETWORK_TYPE->_NDIS_802_11_NETWORK_TYPE
        public NDIS_802_11_NETWORK_TYPE NetworkTypeInUse;

        /// NDIS_802_11_CONFIGURATION->_NDIS_802_11_CONFIGURATION
        public NDIS_802_11_CONFIGURATION Configuration;

        /// NDIS_802_11_NETWORK_INFRASTRUCTURE->_NDIS_802_11_NETWORK_INFRASTRUCTURE
        public NDIS_802_11_NETWORK_INFRASTRUCTURE InfrastructureMode;

        /// NDIS_802_11_RATES->UCHAR[8]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 8)]
        public string SupportedRates;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_BSSID_LIST
    {

        /// ULONG->unsigned int
        public uint NumberOfItems;

        /// NDIS_WLAN_BSSID[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public NDIS_WLAN_BSSID[] Bssid;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_WLAN_BSSID_EX
    {

        /// ULONG->unsigned int
        public uint Length;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string MacAddress;

        /// UCHAR[2]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 2)]
        public string Reserved;

        /// NDIS_802_11_SSID->_NDIS_802_11_SSID
        public NDIS_802_11_SSID Ssid;

        /// ULONG->unsigned int
        public uint Privacy;

        /// NDIS_802_11_RSSI->LONG->int
        public int Rssi;

        /// NDIS_802_11_NETWORK_TYPE->_NDIS_802_11_NETWORK_TYPE
        public NDIS_802_11_NETWORK_TYPE NetworkTypeInUse;

        /// NDIS_802_11_CONFIGURATION->_NDIS_802_11_CONFIGURATION
        public NDIS_802_11_CONFIGURATION Configuration;

        /// NDIS_802_11_NETWORK_INFRASTRUCTURE->_NDIS_802_11_NETWORK_INFRASTRUCTURE
        public NDIS_802_11_NETWORK_INFRASTRUCTURE InfrastructureMode;

        /// NDIS_802_11_RATES_EX->UCHAR[16]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string SupportedRates;

        /// ULONG->unsigned int
        public uint IELength;

        /// UCHAR[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 1)]
        public string IEs;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_BSSID_LIST_EX
    {

        /// ULONG->unsigned int
        public uint NumberOfItems;

        /// NDIS_WLAN_BSSID_EX[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public NDIS_WLAN_BSSID_EX[] Bssid;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_FIXED_IEs
    {

        /// UCHAR[8]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 8)]
        public string Timestamp;

        /// USHORT->unsigned short
        public ushort BeaconInterval;

        /// USHORT->unsigned short
        public ushort Capabilities;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_VARIABLE_IEs
    {

        /// UCHAR->unsigned char
        public byte ElementID;

        /// UCHAR->unsigned char
        public byte Length;

        /// UCHAR[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 1)]
        public string data;
    }

    public enum NDIS_802_11_PRIVACY_FILTER
    {

        Ndis802_11PrivFilterAcceptAll,

        Ndis802_11PrivFilter8021xWEP,
    }

    public enum NDIS_802_11_ENCRYPTION_STATUS
    {

        Ndis802_11WEPEnabled,

        /// Ndis802_11Encryption1Enabled -> Ndis802_11WEPEnabled
        Ndis802_11Encryption1Enabled = NDIS_802_11_ENCRYPTION_STATUS.Ndis802_11WEPEnabled,

        Ndis802_11WEPDisabled,

        /// Ndis802_11EncryptionDisabled -> Ndis802_11WEPDisabled
        Ndis802_11EncryptionDisabled = NDIS_802_11_ENCRYPTION_STATUS.Ndis802_11WEPDisabled,

        Ndis802_11WEPKeyAbsent,

        /// Ndis802_11Encryption1KeyAbsent -> Ndis802_11WEPKeyAbsent
        Ndis802_11Encryption1KeyAbsent = NDIS_802_11_ENCRYPTION_STATUS.Ndis802_11WEPKeyAbsent,

        Ndis802_11WEPNotSupported,

        /// Ndis802_11EncryptionNotSupported -> Ndis802_11WEPNotSupported
        Ndis802_11EncryptionNotSupported = NDIS_802_11_ENCRYPTION_STATUS.Ndis802_11WEPNotSupported,

        Ndis802_11Encryption2Enabled,

        Ndis802_11Encryption2KeyAbsent,

        Ndis802_11Encryption3Enabled,

        Ndis802_11Encryption3KeyAbsent,
    }

    public enum NDIS_802_11_RELOAD_DEFAULTS
    {

        Ndis802_11ReloadWEPKeys,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct NDIS_802_11_AI_REQFI
    {

        /// USHORT->unsigned short
        public ushort Capabilities;

        /// USHORT->unsigned short
        public ushort ListenInterval;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string CurrentAPAddress;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_AI_RESFI
    {

        /// USHORT->unsigned short
        public ushort Capabilities;

        /// USHORT->unsigned short
        public ushort StatusCode;

        /// USHORT->unsigned short
        public ushort AssociationId;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_ASSOCIATION_INFORMATION
    {

        /// ULONG->unsigned int
        public uint Length;

        /// USHORT->unsigned short
        public ushort AvailableRequestFixedIEs;

        /// NDIS_802_11_AI_REQFI->_NDIS_802_11_AI_REQFI
        public NDIS_802_11_AI_REQFI RequestFixedIEs;

        /// ULONG->unsigned int
        public uint RequestIELength;

        /// ULONG->unsigned int
        public uint OffsetRequestIEs;

        /// USHORT->unsigned short
        public ushort AvailableResponseFixedIEs;

        /// NDIS_802_11_AI_RESFI->_NDIS_802_11_AI_RESFI
        public NDIS_802_11_AI_RESFI ResponseFixedIEs;

        /// ULONG->unsigned int
        public uint ResponseIELength;

        /// ULONG->unsigned int
        public uint OffsetResponseIEs;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_AUTHENTICATION_EVENT
    {

        /// NDIS_802_11_STATUS_INDICATION->_NDIS_802_11_STATUS_INDICATION
        public NDIS_802_11_STATUS_INDICATION Status;

        /// NDIS_802_11_AUTHENTICATION_REQUEST[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public NDIS_802_11_AUTHENTICATION_REQUEST[] Request;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Explicit)]
    public struct Anonymous_9745a32c_23dd_4b93_8e58_d2f77db69f22
    {

        /// NDIS_802_11_AUTHENTICATION_EVENT->_NDIS_802_11_AUTHENTICATION_EVENT
        [System.Runtime.InteropServices.FieldOffsetAttribute(0)]
        public NDIS_802_11_AUTHENTICATION_EVENT AuthenticationEvent;

        /// NDIS_802_11_RSSI->LONG->int
        [System.Runtime.InteropServices.FieldOffsetAttribute(0)]
        public int RssiTrigger;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_TEST
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint Type;

        /// Anonymous_9745a32c_23dd_4b93_8e58_d2f77db69f22
        public Anonymous_9745a32c_23dd_4b93_8e58_d2f77db69f22 Union1;
    }

    public enum NDIS_802_11_MEDIA_STREAM_MODE
    {

        Ndis802_11MediaStreamOff,

        Ndis802_11MediaStreamOn,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct BSSID_INFO
    {

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string BSSID;

        /// NDIS_802_11_PMKID_VALUE->UCHAR[16]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string PMKID;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_PMKID
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint BSSIDInfoCount;

        /// BSSID_INFO[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public BSSID_INFO[] BSSIDInfo;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_AUTHENTICATION_ENCRYPTION
    {

        /// NDIS_802_11_AUTHENTICATION_MODE->_NDIS_802_11_AUTHENTICATION_MODE
        public NDIS_802_11_AUTHENTICATION_MODE AuthModeSupported;

        /// NDIS_802_11_ENCRYPTION_STATUS->_NDIS_802_11_WEP_STATUS
        public NDIS_802_11_ENCRYPTION_STATUS EncryptStatusSupported;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_CAPABILITY
    {

        /// ULONG->unsigned int
        public uint Length;

        /// ULONG->unsigned int
        public uint Version;

        /// ULONG->unsigned int
        public uint NoOfPMKIDs;

        /// ULONG->unsigned int
        public uint NoOfAuthEncryptPairsSupported;

        /// NDIS_802_11_AUTHENTICATION_ENCRYPTION[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public NDIS_802_11_AUTHENTICATION_ENCRYPTION[] AuthenticationEncryptionSupported;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct NDIS_802_11_NON_BCAST_SSID_LIST
    {

        /// ULONG->unsigned int
        public uint NumberOfItems;

        /// NDIS_802_11_SSID[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public NDIS_802_11_SSID[] Non_Bcast_Ssid;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct RAW_DATA
    {

        /// DWORD->unsigned int
        public uint dwDataLen;

        /// LPBYTE->BYTE*
        public System.IntPtr pData;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct WZC_WLAN_CONFIG
    {

        /// ULONG->unsigned int
        public uint Length;

        /// DWORD->unsigned int
        public uint dwCtlFlags;

        /// NDIS_802_11_MAC_ADDRESS->UCHAR[6]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 6)]
        public string MacAddress;

        /// UCHAR[2]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 2)]
        public string Reserved;

        /// NDIS_802_11_SSID->_NDIS_802_11_SSID
        public NDIS_802_11_SSID Ssid;

        /// ULONG->unsigned int
        public uint Privacy;

        /// NDIS_802_11_RSSI->LONG->int
        public int Rssi;

        /// NDIS_802_11_NETWORK_TYPE->_NDIS_802_11_NETWORK_TYPE
        public NDIS_802_11_NETWORK_TYPE NetworkTypeInUse;

        /// NDIS_802_11_CONFIGURATION->_NDIS_802_11_CONFIGURATION
        public NDIS_802_11_CONFIGURATION Configuration;

        /// NDIS_802_11_NETWORK_INFRASTRUCTURE->_NDIS_802_11_NETWORK_INFRASTRUCTURE
        public NDIS_802_11_NETWORK_INFRASTRUCTURE InfrastructureMode;

        /// NDIS_802_11_RATES->UCHAR[8]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 8)]
        public string SupportedRates;

        /// ULONG->unsigned int
        public uint KeyIndex;

        /// ULONG->unsigned int
        public uint KeyLength;

        /// UCHAR[32]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 32)]
        public string KeyMaterial;

        /// NDIS_802_11_AUTHENTICATION_MODE->_NDIS_802_11_AUTHENTICATION_MODE
        public NDIS_802_11_AUTHENTICATION_MODE AuthenticationMode;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdUserData;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdNetworkData;

        /// ULONG->unsigned int
        public uint WPAMCastCipher;

        /// ULONG->unsigned int
        public uint ulMediaType;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct WZC_802_11_CONFIG_LIST
    {

        /// ULONG->unsigned int
        public uint NumberOfItems;

        /// ULONG->unsigned int
        public uint Index;

        /// WZC_WLAN_CONFIG[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public WZC_WLAN_CONFIG[] Config;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct WZCDLG_DATA
    {

        /// DWORD->unsigned int
        public uint dwCode;

        /// DWORD->unsigned int
        public uint lParam;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct INTF_KEY_ENTRY
    {

        /// LPWSTR->WCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)]
        public string wszGuid;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct INTFS_KEY_TABLE
    {

        /// DWORD->unsigned int
        public uint dwNumIntfs;

        /// PINTF_KEY_ENTRY->Anonymous_7ac93984_08bb_4462_8e7e_00da3b052d97*
        public System.IntPtr pIntfs;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct INTF_ENTRY
    {

        /// LPWSTR->WCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)]
        public string wszGuid;

        /// LPWSTR->WCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)]
        public string wszDescr;

        /// ULONG->unsigned int
        public uint ulMediaState;

        /// ULONG->unsigned int
        public uint ulMediaType;

        /// ULONG->unsigned int
        public uint ulPhysicalMediaType;

        /// INT->int
        public int nInfraMode;

        /// INT->int
        public int nAuthMode;

        /// INT->int
        public int nWepStatus;

        /// DWORD->unsigned int
        public uint dwCtlFlags;

        /// DWORD->unsigned int
        public uint dwCapabilities;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdSSID;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdBSSID;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdBSSIDList;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdStSSIDList;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdCtrlData;

        /// DWORD->unsigned int
        public uint nWPAMCastCipher;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct WZC_CONTEXT
    {

        /// DWORD->unsigned int
        public uint dwFlags;

        /// DWORD->unsigned int
        public uint tmTr;

        /// DWORD->unsigned int
        public uint tmTc;

        /// DWORD->unsigned int
        public uint tmTp;

        /// DWORD->unsigned int
        public uint tmTf;

        /// DWORD->unsigned int
        public uint tmTd;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct DTLNODE
    {

        /// _DTLNODE*
        public System.IntPtr pdtlnodePrev;

        /// _DTLNODE*
        public System.IntPtr pdtlnodeNext;

        /// void*
        public System.IntPtr pData;

        /// LONG_PTR->int
        public int lNodeId;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct DTLLIST
    {

        /// _DTLNODE*
        public System.IntPtr pdtlnodeFirst;

        /// _DTLNODE*
        public System.IntPtr pdtlnodeLast;

        /// LONG->int
        public int lNodes;

        /// LONG_PTR->int
        public int lListId;
    }

    /// Return Type: void
    ///param0: DTLNODE*
    public delegate void PDESTROYNODE(ref DTLNODE param0);

    public enum EAPTLS_CONNPROP_ATTRIBUTE_TYPE
    {

        /// ecatMinimum -> 0
        ecatMinimum = 0,

        ecatFlagRegistryCert,

        ecatFlagScard,

        ecatFlagValidateServer,

        ecatFlagValidateName,

        ecatFlagDiffUser,

        ecatServerNames,

        ecatRootHashes,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPTLS_CONNPROP_ATTRIBUTE
    {

        /// EAPTLS_CONNPROP_ATTRIBUTE_TYPE->_EAPTLS_CONNPROP_ATTRIBUTE_TYPE_
        public EAPTLS_CONNPROP_ATTRIBUTE_TYPE ecaType;

        /// DWORD->unsigned int
        public uint dwLength;

        /// PVOID->void*
        public System.IntPtr Value;
    }

    /// Return Type: DWORD->unsigned int
    ///param0: PBYTE->BYTE*
    public delegate uint RASEAPFREE(ref byte param0);

    /// Return Type: DWORD->unsigned int
    ///param0: DWORD->unsigned int
    ///param1: HWND->HWND__*
    ///param2: DWORD->unsigned int
    ///param3: PBYTE->BYTE*
    ///param4: DWORD->unsigned int
    ///param5: PBYTE*
    ///param6: DWORD*
    public delegate uint RASEAPINVOKECONFIGUI(uint param0, System.IntPtr param1, uint param2, ref byte param3,

    uint param4, ref System.IntPtr param5, ref uint param6);

    /// Return Type: DWORD->unsigned int
    ///param0: DWORD->unsigned int
    ///param1: HWND->HWND__*
    ///param2: DWORD->unsigned int
    ///param3: WCHAR*
    ///param4: WCHAR*
    ///param5: PBYTE->BYTE*
    ///param6: DWORD->unsigned int
    ///param7: PBYTE->BYTE*
    ///param8: DWORD->unsigned int
    ///param9: PBYTE*
    ///param10: DWORD*
    ///param11: WCHAR**
    public delegate uint RASEAPGETIDENTITY(uint param0, System.IntPtr param1, uint param2,

    [System.Runtime.InteropServices.InAttribute()] [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)] string param3,

    [System.Runtime.InteropServices.InAttribute()] [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)] string param4, ref byte param5, uint param6, ref 
    byte param7, uint param8, ref System.IntPtr param9, ref uint param10, ref System.IntPtr param11);

    /// Return Type: DWORD->unsigned int
    ///param0: DWORD->unsigned int
    ///param1: HWND->HWND__*
    ///param2: PBYTE->BYTE*
    ///param3: DWORD->unsigned int
    ///param4: PBYTE*
    ///param5: DWORD*
    public delegate uint RASEAPINVOKEINTERACTIVEUI(uint param0, System.IntPtr param1, ref byte param2, uint

    param3, ref System.IntPtr param4, ref uint param5);

    /// Return Type: DWORD->unsigned int
    ///param0: PEAPTLS_CONNPROP_ATTRIBUTE->_EAPTLS_CONNPROP_ATTRIBUTE*
    ///param1: PVOID*
    ///param2: DWORD*
    ///param3: PVOID*
    ///param4: DWORD*
    public delegate uint RASEAPCREATECONNPROP(ref EAPTLS_CONNPROP_ATTRIBUTE param0, ref System.IntPtr param1,

    ref uint param2, ref System.IntPtr param3, ref uint param4);

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPCFG
    {

        /// DWORD->unsigned int
        public uint dwKey;

        /// TCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPTStr)]
        public string pszFriendlyName;

        /// TCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPTStr)]
        public string pszConfigDll;

        /// TCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPTStr)]
        public string pszIdentityDll;

        /// DWORD->unsigned int
        public uint dwStdCredentialFlags;

        /// BOOL->int
        public int fForceConfig;

        /// BOOL->int
        public int fProvidesMppeKeys;

        /// BYTE*
        public System.IntPtr pData;

        /// DWORD->unsigned int
        public uint cbData;

        /// BYTE*
        public System.IntPtr pUserData;

        /// DWORD->unsigned int
        public uint cbUserData;

        /// BOOL->int
        public int fConfigDllCalled;

        /// GUID->_GUID
        public GUID guidConfigCLSID;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPOL_INTF_PARAMS
    {

        /// DWORD->unsigned int
        public uint dwVersion;

        /// DWORD->unsigned int
        public uint dwReserved2;

        /// DWORD->unsigned int
        public uint dwEapFlags;

        /// DWORD->unsigned int
        public uint dwEapType;

        /// DWORD->unsigned int
        public uint dwSizeOfSSID;

        /// BYTE[32]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 32,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] bSSID;
    }

    public enum EAPOL_STATE
    {

        /// EAPOLSTATE_LOGOFF -> 0
        EAPOLSTATE_LOGOFF = 0,

        EAPOLSTATE_DISCONNECTED,

        EAPOLSTATE_CONNECTING,

        EAPOLSTATE_ACQUIRED,

        EAPOLSTATE_AUTHENTICATING,

        EAPOLSTATE_HELD,

        EAPOLSTATE_AUTHENTICATED,

        EAPOLSTATE_UNDEFINED,
    }

    public enum EAPUISTATE
    {

        /// EAPUISTATE_WAITING_FOR_IDENTITY -> 1
        EAPUISTATE_WAITING_FOR_IDENTITY = 1,

        EAPUISTATE_WAITING_FOR_UI_RESPONSE,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPOL_INTF_STATE
    {

        /// LPWSTR->WCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)]
        public string pwszLocalMACAddr;

        /// LPWSTR->WCHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPWStr)]
        public string pwszRemoteMACAddr;

        /// DWORD->unsigned int
        public uint dwSizeOfSSID;

        /// BYTE[33]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 33,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] bSSID;

        /// LPSTR->CHAR*
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.LPStr)]
        public string pszEapIdentity;

        /// EAPOL_STATE->_EAPOL_STATE
        public EAPOL_STATE dwState;

        /// EAPUISTATE->_EAPUISTATE
        public EAPUISTATE dwEapUIState;

        /// DWORD->unsigned int
        public uint dwEAPOLAuthMode;

        /// DWORD->unsigned int
        public uint dwEAPOLAuthenticationType;

        /// DWORD->unsigned int
        public uint dwEapType;

        /// DWORD->unsigned int
        public uint dwFailCount;

        /// DWORD->unsigned int
        public uint dwPhysicalMediumType;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPOL_AUTH_DATA
    {

        /// DWORD->unsigned int
        public uint dwEapType;

        /// DWORD->unsigned int
        public uint dwSize;

        /// BYTE[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] bData;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPOLUI_RESP
    {

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdData0;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdData1;

        /// RAW_DATA->Anonymous_36569dfb_64b5_4121_8dde_aab489d29571
        public RAW_DATA rdData2;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPOL_POLICY_DATA
    {

        /// BYTE[32]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 32,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] pbWirelessSSID;

        /// DWORD->unsigned int
        public uint dwWirelessSSIDLen;

        /// DWORD->unsigned int
        public uint dwEnable8021x;

        /// DWORD->unsigned int
        public uint dw8021xMode;

        /// DWORD->unsigned int
        public uint dwEAPType;

        /// DWORD->unsigned int
        public uint dwMachineAuthentication;

        /// DWORD->unsigned int
        public uint dwMachineAuthenticationType;

        /// DWORD->unsigned int
        public uint dwGuestAuthentication;

        /// DWORD->unsigned int
        public uint dwIEEE8021xMaxStart;

        /// DWORD->unsigned int
        public uint dwIEEE8021xStartPeriod;

        /// DWORD->unsigned int
        public uint dwIEEE8021xAuthPeriod;

        /// DWORD->unsigned int
        public uint dwIEEE8021xHeldPeriod;

        /// DWORD->unsigned int
        public uint dwEAPDataLen;

        /// LPBYTE->BYTE*
        public System.IntPtr pbEAPData;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct EAPOL_POLICY_LIST
    {

        /// DWORD->unsigned int
        public uint dwNumberOfItems;

        /// EAPOL_POLICY_DATA[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public EAPOL_POLICY_DATA[] EAPOLPolicy;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct EAPOL_EAP_UI_CONTEXT
    {

        /// DWORD->unsigned int
        public uint dwEAPOLUIMsgType;

        /// WCHAR[39]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 39)]
        public string wszGUID;

        /// DWORD->unsigned int
        public uint dwSessionId;

        /// DWORD->unsigned int
        public uint dwContextId;

        /// DWORD->unsigned int
        public uint dwEapId;

        /// DWORD->unsigned int
        public uint dwEapTypeId;

        /// DWORD->unsigned int
        public uint dwEapFlags;

        /// WCHAR[33]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 33)]
        public string wszSSID;

        /// DWORD->unsigned int
        public uint dwSizeOfSSID;

        /// BYTE[32]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 32,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] bSSID;

        /// DWORD->unsigned int
        public uint dwEAPOLState;

        /// DWORD->unsigned int
        public uint dwRetCode;

        /// DWORD->unsigned int
        public uint dwSizeOfEapUIData;

        /// BYTE[1]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 1,

    ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] bEapUIData;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct WZC_PORT_INFO
    {

        /// GUID->_GUID
        public GUID gAdatperId;

        /// RAW_DATA->Anonymous_84b614cf_fe5b_4d5c_af3a_24ca79af2402
        public RAW_DATA PeerMacAddress;

        /// DWORD->unsigned int
        public uint dwFlags;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Explicit)]
    public struct LARGE_INTEGER
    {

        /// Anonymous_9320654f_2227_43bf_a385_74cc8c562686
        [System.Runtime.InteropServices.FieldOffsetAttribute(0)]
        public Anonymous_9320654f_2227_43bf_a385_74cc8c562686 Struct1;

        /// Anonymous_947eb392_1446_4e25_bbd4_10e98165f3a9
        [System.Runtime.InteropServices.FieldOffsetAttribute(0)]
        public Anonymous_947eb392_1446_4e25_bbd4_10e98165f3a9 u;

        /// LONGLONG->__int64
        [System.Runtime.InteropServices.FieldOffsetAttribute(0)]
        public long QuadPart;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential,

    CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct GUID
    {

        /// unsigned int
        public uint Data1;

        /// unsigned short
        public ushort Data2;

        /// unsigned short
        public ushort Data3;

        /// unsigned char[8]
        [System.Runtime.InteropServices.MarshalAsAttribute

    (System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 8)]
        public string Data4;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct HINSTANCE__
    {

        /// int
        public int unused;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct HWND__
    {

        /// int
        public int unused;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct Anonymous_9320654f_2227_43bf_a385_74cc8c562686
    {

        /// DWORD->unsigned int
        public uint LowPart;

        /// LONG->int
        public int HighPart;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute

    (System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct Anonymous_947eb392_1446_4e25_bbd4_10e98165f3a9
    {

        /// DWORD->unsigned int
        public uint LowPart;

        /// LONG->int
        public int HighPart;
    }

    public partial class NativeMethods
    {

        /// Return Type: PVOID->void*
        ///NumBytes: size_t->unsigned int
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "MIDL_user_allocate")]
        public static extern System.IntPtr MIDL_user_allocate([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.SysUInt)] uint NumBytes);


        /// Return Type: void
        ///MemPointer: void*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "MIDL_user_free")]
        public static extern void MIDL_user_free(System.IntPtr MemPointer);


        /// Return Type: HINSTANCE->HINSTANCE__*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCGetSPResModule")]
        public static extern System.IntPtr WZCGetSPResModule();


        /// Return Type: void
        ///pIntf: PINTF_ENTRY->Anonymous_76670dca_5da8_45c7_8331_9a7ac4b2ba8f*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCDeleteIntfObj")]
        public static extern void WZCDeleteIntfObj(ref INTF_ENTRY pIntf);


        /// Return Type: void
        ///pwzcConfig: PWZC_WLAN_CONFIG->Anonymous_82caf423_87d2_46e3_a8f5_27ad44a30ff2*
        ///cszPassword: LPCSTR->CHAR*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCPassword2Key")]
        public static extern void WZCPassword2Key(ref WZC_WLAN_CONFIG pwzcConfig,

        [System.Runtime.InteropServices.InAttribute()] [System.Runtime.InteropServices.MarshalAsAttribute

        (System.Runtime.InteropServices.UnmanagedType.LPStr)] string cszPassword);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pIntfs: PINTFS_KEY_TABLE->Anonymous_f6db7041_c811_4d0e_8ee0_eeb221ec3856*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCEnumInterfaces")]
        public static extern uint WZCEnumInterfaces([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, ref 
    INTFS_KEY_TABLE pIntfs);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///dwInFlags: DWORD->unsigned int
        ///pIntf: PINTF_ENTRY->Anonymous_76670dca_5da8_45c7_8331_9a7ac4b2ba8f*
        ///pdwOutFlags: LPDWORD->DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCQueryInterface")]
        public static extern uint WZCQueryInterface([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, uint dwInFlags,

       ref INTF_ENTRY pIntf, ref uint pdwOutFlags);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///dwInFlags: DWORD->unsigned int
        ///pIntf: PINTF_ENTRY->Anonymous_76670dca_5da8_45c7_8331_9a7ac4b2ba8f*
        ///pdwOutFlags: LPDWORD->DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCSetInterface")]
        public static extern uint WZCSetInterface([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, uint dwInFlags,

       ref INTF_ENTRY pIntf, ref uint pdwOutFlags);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///dwInFlags: DWORD->unsigned int
        ///pIntf: PINTF_ENTRY->Anonymous_76670dca_5da8_45c7_8331_9a7ac4b2ba8f*
        ///pdwOutFlags: LPDWORD->DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCRefreshInterface")]
        public static extern uint WZCRefreshInterface([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, uint dwInFlags,

       ref INTF_ENTRY pIntf, ref uint pdwOutFlags);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///dwInFlags: DWORD->unsigned int
        ///pContext: PWZC_CONTEXT->_wzc_context_t*
        ///pdwOutFlags: LPDWORD->DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCQueryContext")]
        public static extern uint WZCQueryContext([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, uint dwInFlags,

       ref WZC_CONTEXT pContext, ref uint pdwOutFlags);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///dwInFlags: DWORD->unsigned int
        ///pContext: PWZC_CONTEXT->_wzc_context_t*
        ///pdwOutFlags: LPDWORD->DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCSetContext")]
        public static extern uint WZCSetContext([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, uint dwInFlags,

       ref WZC_CONTEXT pContext, ref uint pdwOutFlags);


        /// Return Type: void
        ///param0: DTLLIST*
        ///param1: PDESTROYNODE
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "DtlDestroyList")]
        public static extern void DtlDestroyList(ref DTLLIST param0, PDESTROYNODE param1);


        /// Return Type: DTLNODE*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "CreateEapcfgNode")]
        public static extern System.IntPtr CreateEapcfgNode();


        /// Return Type: void
        ///pNode: DTLNODE*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "DestroyEapcfgNode")]
        public static extern void DestroyEapcfgNode(ref DTLNODE pNode);


        /// Return Type: DTLNODE*
        ///pList: DTLLIST*
        ///dwKey: DWORD->unsigned int
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "EapcfgNodeFromKey")]
        public static extern System.IntPtr EapcfgNodeFromKey(ref DTLLIST pList, uint dwKey);


        /// Return Type: DTLLIST*
        ///dwFlags: DWORD->unsigned int
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "ReadEapcfgList")]
        public static extern System.IntPtr ReadEapcfgList(uint dwFlags);


        /// Return Type: DWORD->unsigned int
        ///pwszGUID: WCHAR*
        ///dwEapTypeId: DWORD->unsigned int
        ///dwSizOfSSID: DWORD->unsigned int
        ///pbSSID: BYTE*
        ///pbUserInfo: PBYTE->BYTE*
        ///pdwInfoSize: DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCGetEapUserInfo")]
        public static extern uint WZCGetEapUserInfo(System.IntPtr pwszGUID, uint dwEapTypeId, uint dwSizOfSSID,

        ref byte pbSSID, ref byte pbUserInfo, ref uint pdwInfoSize);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pwszGuid: PWCHAR->WCHAR*
        ///dwEapTypeId: DWORD->unsigned int
        ///dwSizeOfSSID: DWORD->unsigned int
        ///pbSSID: BYTE*
        ///pbConnInfo: PBYTE->BYTE*
        ///pdwInfoSize: PDWORD->DWORD*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>",

    EntryPoint = "WZCEapolGetCustomAuthData")]
        public static extern uint WZCEapolGetCustomAuthData([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, System.IntPtr

       pwszGuid, uint dwEapTypeId, uint dwSizeOfSSID, ref byte pbSSID, ref byte pbConnInfo, ref uint pdwInfoSize)

       ;


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pwszGuid: PWCHAR->WCHAR*
        ///dwEapTypeId: DWORD->unsigned int
        ///dwSizeOfSSID: DWORD->unsigned int
        ///pbSSID: BYTE*
        ///pbConnInfo: PBYTE->BYTE*
        ///dwInfoSize: DWORD->unsigned int
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>",

    EntryPoint = "WZCEapolSetCustomAuthData")]
        public static extern uint WZCEapolSetCustomAuthData([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, System.IntPtr

       pwszGuid, uint dwEapTypeId, uint dwSizeOfSSID, ref byte pbSSID, ref byte pbConnInfo, uint dwInfoSize);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pwszGuid: PWCHAR->WCHAR*
        ///pIntfParams: EAPOL_INTF_PARAMS*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>",

    EntryPoint = "WZCEapolGetInterfaceParams")]
        public static extern uint WZCEapolGetInterfaceParams([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, System.IntPtr

       pwszGuid, ref EAPOL_INTF_PARAMS pIntfParams);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pwszGuid: PWCHAR->WCHAR*
        ///pIntfParams: EAPOL_INTF_PARAMS*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>",

    EntryPoint = "WZCEapolSetInterfaceParams")]
        public static extern uint WZCEapolSetInterfaceParams([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, System.IntPtr

       pwszGuid, ref EAPOL_INTF_PARAMS pIntfParams);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pwszGuid: PWCHAR->WCHAR*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCEapolReAuthenticate")]
        public static extern uint WZCEapolReAuthenticate([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, System.IntPtr

       pwszGuid);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///pwszGuid: PWCHAR->WCHAR*
        ///pIntfState: EAPOL_INTF_STATE*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCEapolQueryState")]
        public static extern uint WZCEapolQueryState([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr, System.IntPtr

       pwszGuid, ref EAPOL_INTF_STATE pIntfState);


        /// Return Type: DWORD->unsigned int
        ///pIntfState: EAPOL_INTF_STATE*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCEapolFreeState")]
        public static extern uint WZCEapolFreeState(ref EAPOL_INTF_STATE pIntfState);


        /// Return Type: DWORD->unsigned int
        ///pSrvAddr: LPWSTR->WCHAR*
        ///EapolUIContext: EAPOL_EAP_UI_CONTEXT->_EAPOL_EAP_UI_CONTEXT
        ///EapolUIResp: EAPOLUI_RESP->_EAPOLUI_RESP
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WZCEapolUIResponse")]
        public static extern uint WZCEapolUIResponse([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pSrvAddr,

       EAPOL_EAP_UI_CONTEXT EapolUIContext, EAPOLUI_RESP EapolUIResp);


        /// Return Type: DWORD->unsigned int
        ///pServerName: LPWSTR->WCHAR*
        ///pWzcPortInfo: PWZC_PORT_INFO->_WZC_PORT_INFO*
        [System.Runtime.InteropServices.DllImportAttribute("<Unknown>", EntryPoint = "WzcPortIndication")]
        public static extern uint WzcPortIndication([System.Runtime.InteropServices.MarshalAsAttribute

       (System.Runtime.InteropServices.UnmanagedType.LPWStr)] System.Text.StringBuilder pServerName, ref 
    WZC_PORT_INFO pWzcPortInfo);

    }

}
