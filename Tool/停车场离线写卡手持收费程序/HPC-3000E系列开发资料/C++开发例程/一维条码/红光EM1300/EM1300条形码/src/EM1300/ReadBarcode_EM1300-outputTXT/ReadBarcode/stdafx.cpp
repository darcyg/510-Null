// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// ReadBarcode.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
//���Ӵ�ӡlog��Ϣ
void Log(const char * s,int length)
{
    FILE *pFile = fopen("\\Windows\\log.txt","a");
    fwrite(s,1,length,pFile);
    fclose(pFile);
}

