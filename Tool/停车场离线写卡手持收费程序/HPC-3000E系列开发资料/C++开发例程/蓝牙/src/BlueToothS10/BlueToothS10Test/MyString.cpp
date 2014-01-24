#include "stdafx.h"
#include "MyString.h"

MyString::MyString(void)
{
}

MyString::~MyString(void)
{
}

void MyString::ByteToString(const BYTE *pData, CString *sString, int Length)
{
	if(sString)
		*sString = "";
	CString strSingleByte;
	for (int i = 0; i < Length; i++)
	{
		strSingleByte.Format(_T("%02X "), pData[i]);

		// ����������һ�����ݣ������һ������ַ����������������ֽ�����
		*sString += strSingleByte;
	}
	return;
}


int MyString::StringToByte(CString sString, BYTE *pData, int Length)
{
	CString strSingleByte;
	int nLength = sString.GetLength();
	int i;

	if (nLength > (Length * 3))
	{
		nLength = Length * 3;
	}

	for (i = 0; i <= nLength/3; i++)
	{
		strSingleByte = sString.Mid(3*i, 2);

		// ����ַ���Ϊ�գ���������Ϊ0
		if (strSingleByte.IsEmpty())
		{
			pData[i] = 0;
		}
		else
		{
			pData[i] = 0;
			strSingleByte.MakeUpper();

			for (int j = 0; j < 2; j++)
			{
				pData[i] <<= 4;

				if (isdigit(strSingleByte[j]))
				{// Ϊ���� '0' ~ '9'
					pData[i] |= strSingleByte[j] - '0';
				}
				else
				{// Ϊ���� 'A' ~ 'F'
					pData[i] |= strSingleByte[j] - 'A' + 0x0A;
				}
			}
		}
	}
	return i;
}
void MyString::StringSplit(CString str,CString splitchars,vector<CString> &strVec)
{
	strVec.clear();
	while (true)
	{
		CString n = str.SpanExcluding(splitchars);
		strVec.push_back(n);
		str = str.Right(str.GetLength()-n.GetLength()-1);
		if (str.IsEmpty())
		{
			break;
		}
	}
	return ;
}
void MyString::BCDToDecimal(const CString * bcd,CString *dec)
{
	double value=0;
	int bei=1;
	int num=0;
	for(int i=0;i<bcd->GetLength();i++)
	{
		char c=(char)bcd->GetAt(i);
		if(c == ' ')
		{
			value+=num*bei;
			num=0;
			bei*=100;
		}
		else
		{
			num*=10;
			num+=c-'0';
		}
	}
	value+=num*bei;
	value/=100;
	dec->Format(L"%.2lf",value);
}