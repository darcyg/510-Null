// CeSerial.h: interface for the CCeSerial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CESERIAL_H__8DCCE440_633D_4524_BF0A_DAA447B2794C__INCLUDED_)
#define AFX_CESERIAL_H__8DCCE440_633D_4524_BF0A_DAA447B2794C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/*********************************************************************************************************
  �������ڽ��ջص�����ָ�� ��������
*********************************************************************************************************/
typedef void  (CALLBACK *PFUN_COMRCV)(LPVOID pvUserParam, BYTE *pucBuf, DWORD dwRcvLen);

/*********************************************************************************************************
���ڲ������󷵻�ֵ����
*********************************************************************************************************/
#define COM_OK              0
#define COM_ERR_PARA        41
#define COM_ERR_TIME        42
#define COM_ERR_USING       43
#define COM_ERR_OPEN        44

/*********************************************************************************************************
  ���ںŶ���
*********************************************************************************************************/
typedef enum  {
	ECOM1 = 1,
	ECOM2,
	ECOM3,
	ECOM4,
    ECOM5,
    ECOM6,
    ECOM7,
    ECOM8,
    ECOM9
}	EPort;


/*********************************************************************************************************
  ����������ֵ����
*********************************************************************************************************/
typedef enum  {
		EBaud110     = 110,		                                        /*  110 bits/s                  */
		EBaud300     = 300,		                                        /*  300 bits/s                  */
		EBaud600     = 600,		                                        /*  600 bits/s                  */
		EBaud1200    = 1200,	                                        /*  1200 bits/s                 */
		EBaud2400    = 2400,	                                        /*  2400 bits/s                 */
		EBaud4800    = 4800,	                                        /*  4800 bits/s                 */
		EBaud9600    = 9600,	                                        /*  9600 bits/s                 */
		EBaud14400   = 14400,	                                        /*  14400 bits/s                */
		EBaud19200   = 19200,	                                        /*  19200 bits/sec              */
		EBaud38400   = 38400,	                                        /*  38400 bits/sec              */
		EBaud56000   = 56000,	                                        /*  56000 bits/sec              */
		EBaud57600   = 57600,	                                        /*  57600 bits/sec              */
		EBaud115200  = 115200	                                        /*  115200 bits/sec	            */
}	EBaudrate;


/*********************************************************************************************************
  ����λ����ֵ����
*********************************************************************************************************/
typedef enum  {
		EData5       =  5,			                                    /*  5 bits per byte             */
		EData6       =  6,			                                    /*  6 bits per byte             */
		EData7       =  7,			                                    /*  7 bits per byte             */
		EData8       =  8			                                    /*  8 bits per byte (default)   */
}	EDataBits;


/*********************************************************************************************************
  ֹͣλ����ֵ����
*********************************************************************************************************/
typedef enum  {
		EStop1       = 0,			                                    /*  1 stopbit (default)         */
		EStop1_5     = 1,			                                    /*  1.5 stopbit                 */
		EStop2       = 2			                                    /*  2 stopbits                  */
}	EStopBits;


/*********************************************************************************************************
  ��ż��������ֵ����
*********************************************************************************************************/
typedef enum  {
		EParNone    = NOPARITY,    	                                    /*  ��У�� (default)	        */
		EParOdd     = ODDPARITY,		                                /*  ��У��                      */
		EParEven    = EVENPARITY,  	                                    /*  żУ��                      */
		EParMark    = MARKPARITY,  	                                    /*  ���У��                    */
		EParSpace   = SPACEPARITY		                                /*  �ո�У��                    */
}  EParity;


/*********************************************************************************************************
   DTRӲ����������ֵ����
*********************************************************************************************************/
typedef enum  {
		EDtrDisable    = DTR_CONTROL_DISABLE,    	                    /*  DTR��ΪOFF (default)	    */
		EDtrEnable     = DTR_CONTROL_ENABLE,		                    /*  DTR��ΪON                   */
		EDtrHandshake  = DTR_CONTROL_HANDSHAKE,  	                    /*  ����DTR�����֡�             */
}  EDtrCon;


/*********************************************************************************************************
  RTSӲ����������ֵ����
*********************************************************************************************************/
typedef enum  {
		ERtsDisable    = RTS_CONTROL_DISABLE,    	                    /*  RTS��ΪOFF (default)        */
		ERtsEnable     = RTS_CONTROL_ENABLE,		                    /*  RTS��ΪON                   */
		ERtsHandshake  = RTS_CONTROL_HANDSHAKE,  	        /*  �����ջ���������С�ڰ���ʱRTSΪON,      */
                                                            /*  �����ջ��������ݳ����ķ�֮����ʱRTSΪOFF*/
		ERtsToggle     = RTS_CONTROL_TOGGLE,  	                        /*  �����ݷ���ʱRTS��ΪON,      */
                                                                        /*  ���ݷ������RTS�ָ�ΪOFF    */
}  ERtsCon;



/*********************************************************************************************************
  CCeSerial�ඨ��
*********************************************************************************************************/
//class  AFX_EXT_CLASS  CCeSerial  
class  CCeSerial 
{
public:
	CCeSerial();
	virtual ~CCeSerial();

    /* 
     *  �򿪴���
     */
	int epcSerialOpen(EPort  Port, EBaudrate  BaudRate);

	int epcSerialOpen(EPort      Port,      EBaudrate  BaudRate, 
                      EDataBits  DataBits,  EStopBits  StopBits, EParity  Parity);

	int epcSerialOpen(EPort      Port,      EBaudrate  BaudRate, 
                      EDataBits  DataBits,  EStopBits  StopBits, EParity  Parity,
		              EDtrCon    DTRShake,  ERtsCon    RTSShake);
	
	/* 
     *  �رմ���
     */
	BOOL epcSerialClose(void);
	
    /* 
     *  �������� (����ʽ)
     */
	BOOL epcSerialSendData(BYTE *pucSendBuf, DWORD dwLength);

    /* 
     *  ���ڽ������� (����ʽ)
     *  dwLengthΪҪ���յ����ݸ��������Ϊ1024�ֽ�.
     */
	DWORD epcSerialRcvData(BYTE  *pucRcvBuf, DWORD  dwLength, DWORD  dwOutTime, BOOL  bClrComBuf);  
	

    /* 
     *  ���ڽ������� (������ʽ)
     *  ˵�������ñ������Ὠ��һ���̴߳������ݽ��գ���ֻ����epcSerialRcvData()��epcSerialClose()ʱ 
     *        �Ż�ر��߳� (�����̱߳��ر�֮ǰ�������ٴε��ñ�����)
     */   
	BOOL epcSerialRcvDataTread(DWORD  dwLength,	                        /*  �������ݸ��������Ϊ1024    */
					           DWORD  dwOutTime,		                /*  ���ճ�ʱʱ������            */
		                       PFUN_COMRCV  pfunOnComRcv,	            /*  �������ݳɹ��ص�����ָ��    */
					           LPVOID  pvUserParam);	                /*  �ص�������Ҫ���û���������  */
    /*
     *	������ջ�����
     */
    BOOL epcSerialRxClear();
	int CCeSerial::epcSetRTS(BOOL bEnRts);

private:
	DCB     dcbCOM;								                        /*  ���ڲ����ṹ��              */
	HANDLE  hCOM;							                            /*  ���ڲ������                */

	HANDLE  hRcvThread;						                            /*  �����߳̾��                */
    HANDLE  hExitThreadEvent;				                            /*  ���ڽ����߳��˳��¼�        */		

	/* 
     *  ���ڽ����̼߳���Ӧ����	
     */
	DWORD        dwRcvLength;
	PFUN_COMRCV  pfunRcvOnComRcv;
	LPVOID       pvRcvUserParam;

	static DWORD  WINAPI epcSerialComRcvTread(LPVOID  pvParam);

    /* 
     *  ���ڲ������÷���
     */
	BOOL epcSerialSetCom(EBaudrate  BaudRate,  EDataBits  DataBits, 
                         EStopBits  StopBits,  EParity    Parity,
				         EDtrCon    DTRShake,  ERtsCon    RTSShake);
public:
	BOOL epcCloseRcvThread(void);
};


#endif // !defined(AFX_CESERIAL1_H__D0079FDD_3F13_44EF_92CD_28E045E6F309__INCLUDED_)



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/