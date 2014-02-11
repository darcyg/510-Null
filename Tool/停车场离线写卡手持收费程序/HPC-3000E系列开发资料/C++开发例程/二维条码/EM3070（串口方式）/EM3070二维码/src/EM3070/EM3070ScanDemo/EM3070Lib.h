/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               EM1300Lib.h
** Latest modified Date:    
** Latest Version:          
** Descriptions:            
**
**--------------------------------------------------------------------------------------------------------
** Created by:              �� ��     
** Created date:            2011-04-13 
** Version:                 V1.00
** Descriptions:            ԭʼ�汾(EM1300Lib�������)
**
**--------------------------------------------------------------------------------------------------------
** Modified by:                                 
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#if !defined(AFX_EM1300LIB_H__97056FA2_C9BC_4095_8E9A_59D91B41F9BC__INCLUDED_)
#define AFX_EM1300LIB_H__97056FA2_C9BC_4095_8E9A_59D91B41F9BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define COMMANDLENGTH 9

/**********************************************************************************************************
  ���ݰ��ṹ��
**********************************************************************************************************/
typedef struct __DPacket {
	BYTE Length;                                                       /* ����checksum֮��,���ݰ��ĳ���  */
	BYTE Opcode;                                                       /* ������                         */
	BYTE MSource;                                                      /* ��Ϣ��Դ                       */
	BYTE Status;                                                       /* ״̬�ֽ�                       */
	BYTE CheckSumHigh;                                                 /* У��͸��ֽ�                   */
	BYTE CheckSumLow;	                                               /* У��͵��ֽ�                   */
} DataPacket;


typedef struct __SDPacket {
	BYTE Length;                                                       /* ����checksum֮�⣬���ݰ��ĳ��� */
	BYTE Opcode;                                                       /* ������                         */
	BYTE MSource;                                                      /* ��Ϣ��Դ                       */
	BYTE Status;                                                       /* ״̬�ֽ�                       */
	BYTE Selection;	                                                   /* ѡ��ģʽ                       */
	BYTE CheckSumHigh;                                                 /* У��͸��ֽ�                   */
	BYTE CheckSumLow;	                                               /* У��͵��ֽ�                   */
} SDataPacket;

typedef struct __PDPacket {
	BYTE Length;                                                       /* ����checksum֮��,���ݰ��ĳ���  */
	BYTE Opcode;                                                       /* ������                         */
	BYTE MSource;                                                      /* ��Ϣ��Դ                       */
	BYTE Status;                                                       /* ״̬�ֽ�                       */
	BYTE BeepCode;	                                                   /* ����������                     */	
	BYTE ParaNum;                                                      /* ������                         */
	BYTE ParaValue;                                                    /* ����ֵ                         */
	BYTE CheckSumHigh;                                                 /* У��͸��ֽ�                   */
	BYTE CheckSumLow;                                                  /* У��͵��ֽ�                   */
} PDataPacket;


typedef struct __TDPacket {
	BYTE Length;                                                       /* ����checksum֮��,���ݰ��ĳ���  */
	BYTE Opcode;                                                       /* ������                         */
	BYTE MSource;                                                      /* ��Ϣ��Դ                       */
	BYTE Status;                                                       /* ״̬�ֽ�                       */
	BYTE BeepCode;	                                                   /* ����������                     */	
	BYTE ParaNum1;                                                     /* ������1                        */                                                     
	BYTE ParaValue1;                                                   /* ������1��ֵ                    */
	BYTE ParaNum2;                                                     /* ������2                        */ 
	BYTE ParaValue2;                                                   /* ������2��ֵ                    */
	BYTE ParaNum3;                                                     /* ������3                        */ 
	BYTE ParaValue3;                                                   /* ������3��ֵ                    */
	BYTE CheckSumHigh;                                                 /* У��͸��ֽ�                   */
	BYTE CheckSumLow;                                                  /* У��͵��ֽ�                   */
} TDataPacket;


typedef struct __MDPacket {
	BYTE Length;                                                       /* ����checksum֮��,���ݰ��ĳ���  */
	BYTE Opcode;                                                       /* ������                         */
	BYTE MSource;                                                      /* ��Ϣ��Դ                       */
	BYTE Status;                                                       /* ״̬�ֽ�                       */
	BYTE BeepCode;	                                                   /* ����������                     */	
	BYTE ParaNum;                                                      /* ������                         */
	BYTE Offset;                                                       /* ƫ����                         */
	BYTE ParaValue;                                                    /* ����ֵ                         */
	BYTE CheckSumHigh;                                                 /* У��͸��ֽ�                   */
	BYTE CheckSumLow;                                                  /* У��͵��ֽ�                   */
} MDataPacket;



typedef struct __NDPacket {
	BYTE Length;                                                       /* ����checksum֮��,���ݰ��ĳ���  */
	BYTE Opcode;                                                       /* ������                         */
	BYTE MSource;                                                      /* ��Ϣ��Դ                       */
	BYTE Status;                                                       /* ״̬�ֽ�                       */
	BYTE BeepCode;	                                                   /* ����������                     */	
	BYTE ParaNum1;                                                     /* ������1                        */                                                     
	BYTE ParaValue1;                                                   /* ������1��ֵ                    */
	BYTE ParaNum2;                                                     /* ������2                        */ 
	BYTE ParaValue2;                                                   /* ������2��ֵ                    */
	BYTE CheckSumHigh;                                                 /* У��͸��ֽ�                   */
	BYTE CheckSumLow;                                                  /* У��͵��ֽ�                   */
} NDataPacket;

/**********************************************************************************************************
  EM1300Lib�����ඨ��
**********************************************************************************************************/
class EM1300Lib
{
public:
	EM1300Lib();
	~EM1300Lib();

	/*
	 *  ���Ѻ���
	 */
	static int  EM1300WakeUp( UCHAR ucPort);

};


#endif // !defined(AFX_EM1300LIB_H__97056FA2_C9BC_4095_8E9A_59D91B41F9BC__INCLUDED_)
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/



