#ifndef         __BK_BRIGHTNESS_CTL_H__
#define         __BK_BRIGHTNESS_CTL_H__

#ifdef  __cplusplus
extern "C" 
{
#endif

    //���嵱���÷����ı�ʱ������֪ͨϵͳʱ���õ����¼����������
#define BKL_INACTIVE_EVENT_NAME         L"PowerManager/UserActivity_Inactive"
#define BKL_ACTIVE_EVENT_NAME           L"PowerManager/UserActivity_Active"
#define BKL_USER_ACTIVE_EVENT_NAME      L"PowerManager/ActivityTimer/UserActivity"
#define EVENTNAME_BACKLIGHTCHANGEEVENT  L"BackLightChangeEvent"

    //����ע�������������
#define RK_CONTROLPANEL_BACKLIGHT       L"ControlPanel\\Backlight"
#define RV_BATTERYTIMEOUT               L"BatteryTimeout"
#define RV_USEBATTERY                   L"UseBattery"
#define RV_ACTIMEOUT                    L"ACTimeout"
#define RV_USEAC                        L"UseExt"
#define RV_BATBKL_ONTAP                 L"UseBattery" 
#define RV_ACBKL_ONTAP                  L"UseExt"
#define RV_BACKLIGHT_BRIGHTNESS         L"LightPercent"




#ifdef  __cplusplus
};
#endif

#endif