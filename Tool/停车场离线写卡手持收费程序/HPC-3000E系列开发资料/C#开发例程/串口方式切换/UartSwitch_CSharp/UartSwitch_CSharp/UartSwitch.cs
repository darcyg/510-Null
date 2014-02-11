using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace UartSwicthSpace
{

enum UartSwich_State:byte
{
   UART_NC  =  0,                      /* ���ýӿ������ӷ�ʽ */
   UART_TTL,                           /* ���ýӿ�TTL��ʽ */
   UART_RS232,                         /* ���ýӿ�RS232��ʽ */
   UART_RS485                          /* ���ýӿ�RS485��ʽ */
}

class UartSwichSet
{
/*********************************************************************************************************
** Function name:   		UartSwitchInit
** Descriptions:    		�������ǳ�ʼ�������л�
** input parameters:   	    ��
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    
*********************************************************************************************************/
[System.Runtime.InteropServices.DllImport("UartSwitch.dll")]
public static extern bool UartSwitchInit();


/*********************************************************************************************************
** Function name:   		UartSwitchSetting
** Descriptions:    		������������ѡ�񴮿������ʽ
** input parameters:   	    dwSwitch             ���������ʽѡ��
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    
*********************************************************************************************************/
[System.Runtime.InteropServices.DllImport("UartSwitch.dll")]
public static extern bool UartSwitchSetting(UartSwich_State dwSwitch);



/*********************************************************************************************************
** Function name:   		UartSwitchDeInit
** Descriptions:    		�������ǳ�ʼ�������л�
** input parameters:   	    ��
** output parameters:   	��
** Returned value:     	    TRUE:�ɹ�;FALSE:ʧ��
** Note:                    
*********************************************************************************************************/
[System.Runtime.InteropServices.DllImport("UartSwitch.dll")]
public static extern bool  UartSwitchDeInit();


}
}