//////////////////////////////////////////////////////////////////////////  
/// COPY RIGHT NOTICE  
/// Copyright(c) 2012��������Զ  
/// All rights reserved.  
///  
/// @file tk.h  
/// @brief һЩ���õĺ����͸�������  
///  
///   
///  
/// @date 2012/03/23  
///  
///
////////////////////////////////////////////////////////////////////////// 


#pragma once
#include <algorithm>
#include <vector>
using namespace std;


namespace TK
{

    //����һ��delete ptr�ķ�����
    struct DeletePtr
    {
        template<class T>
        void operator() (T* t)
        {
            delete t;
        }
    };

    void ShowFullScreen( HWND hwnd );

    //��ó���·������\����
    CString GetAppPath();

    // �ж�Ŀ¼�Ƿ����
    BOOL IsFolderExist( CString strDir );

    // ���ID���SN���Ƿ���ȷ
    // �������Ϊ4��ֻ������ĸ������
    BOOL VertifyCodeString( const CString& str , HWND hwnd );

    void SetCombSel( CComboBox& comb, int data );

    CString GetComPort( int port );

    void U2M(LPSTR t,LPCWSTR f, UINT CodePage); //UnicodeToMultiByte
    void M2U(LPWSTR t,LPCSTR f ,UINT CodePage);//MultiByteToUnicode
    void Unicode2Ansi(LPSTR to,LPCWSTR from);
    int  GetLenUnicode2Ansi(LPCWSTR from);
    int  GetLenAnsi2Unicode(LPCSTR from);
    void Ansi2Unicode(LPWSTR to,LPCSTR from);
};
