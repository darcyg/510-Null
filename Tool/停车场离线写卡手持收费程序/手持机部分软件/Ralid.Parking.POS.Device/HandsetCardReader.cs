using System;
using System.Collections.Generic;
using System.Text;
using NLSCAN.MacCtrl;
using System.Runtime.InteropServices;
using Ralid.Parking.POS.Tool;

namespace Ralid.Parking.POS.Device
{
    public class HandsetCardReader : POSDeviceBase
    {
        #region dll��̬�����
        /// <summary>
        /// �򿪶�����
        /// </summary>
        /// <param name="devname">��������</param>
        /// <param name="flag">����������</param>
        /// <returns>���������</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_Open")]
        private static extern IntPtr NLRF_Open(string devname, string flag);

        /// <summary>
        /// �رն�����
        /// </summary>
        /// <param name="hdev">���������</param>
        /// <returns>�ɹ�Ϊ0��ʧ��Ϊ��0</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_Close")]
        private static extern int NLRF_Close(IntPtr hdev);

        /// <summary>
        /// ��ȡ��Ƭ�������
        /// </summary>
        /// <param name="hdev">���������</param>
        /// <param name="Sector">����</param>
        /// <param name="Blk">��</param>
        /// <param name="pBuf">���ڴ����ȡ�����ݵ�ָ��</param>
        /// <param name="dwLen">pBuf�ĳ���</param>
        /// <returns>�ɹ�����pBuf�ĳ��ȣ�ʧ�ܷ���һ������</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_ReadBlk", CharSet = CharSet.Auto)]
        private static extern int NLRF_ReadBlk(IntPtr hdev, int Sector, int Blk, byte[] pBuf, int dwLen);

        /// <summary>
        /// ��Ƭ�Ŀ�д����
        /// </summary>
        /// <param name="hdev">���������</param>
        /// <param name="Sector">����</param>
        /// <param name="Blk">��</param>
        /// <param name="pBuf">Ҫд�������</param>
        /// <param name="dwLen">Ҫд������ݵĳ���</param>
        /// <returns>�ɹ�����д�����ݵĳ��ȣ�ʧ�ܷ���һ������</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_WriteBlk")]
        private static extern int NLRF_WriteBlk(IntPtr hdev, int Sector, int Blk, byte[] pBuf, int dwLen);

        /// <summary>
        /// ���鿨Ƭ����
        /// </summary>
        /// <param name="hdev">���������</param>
        /// <param name="nKeyType">Ҫ���������</param>
        /// <param name="pKey">���ڼ��������</param>
        /// <param name="dwKeyLen">����ĳ���</param>
        /// <returns>�ɹ�����0��ʧ�ܷ��ط�0</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_ChkKey")]
        private static extern int NLRF_ChkKey(IntPtr hdev, int nKeyType, byte[] pKey, int dwKeyLen);

        /// <summary>
        /// ���ÿ�Ƭ����
        /// </summary>
        /// <param name="hdev">���������</param>
        /// <param name="nKeyType">Ҫ�������������</param>
        /// <param name="pOldKey">������</param>
        /// <param name="pKey">������</param>
        /// <param name="OdwKeyLen">�����볤��</param>
        /// <param name="dwKeyLen">�����볤��</param>
        /// <returns>�ɹ�����0��ʧ�ܷ��ط�0</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_SetKey")]
        private static extern int NLRF_SetKey(IntPtr hdev, int nKeyType, byte[] pOldKey, byte[] pKey, int OdwKeyLen, int dwKeyLen);

        /// <summary>
        /// ��ѯ��Ƭ��Ϣ
        /// </summary>
        /// <param name="hdev">���������</param>
        /// <param name="pInfo">��Ƭ��Ϣ����</param>
        /// <returns>�ɹ�����0��ʧ�ܷ��ط�0</returns>
        [DllImport("RFID.dll", EntryPoint = "NLRF_QueryCardInfo")]
        private static extern int NLRF_QueryCardInfo(IntPtr hdev, ref RFDEV_CARDINFO pInfo);

        [StructLayout(LayoutKind.Sequential)]
        public struct RFDEV_CARDINFO
        {
            public int nSector;
            public int nBlkCnt;
            public int nBlkSize;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public byte[] CardNum;
        }
        #endregion

        #region ���캯��
        public HandsetCardReader()
        {
        }
        #endregion

        #region ����
        public IntPtr _Hdev;
        #endregion

        #region ����������
        /// <summary>
        /// ����������-�ɹ���ʾ
        /// </summary>
        public override void  Buzz_OK()
        {
            int m_iFreq = 2730;
            int m_iVolume = 60;
            int m_iMdelay = 100;
            int m_iBuzCtrlRe = -1;
            m_iBuzCtrlRe = NLSSysCtrl.buz_ctrl(m_iFreq, m_iVolume, m_iMdelay);
        }

        /// <summary>
        /// ����������-ʧ����ʾ
        /// </summary>

        public override void  Buzz_Fail()
        {
            int m_iFreq = 2730;
            int m_iVolume = 60;
            int m_iMdelay = 650;
            int m_iBuzCtrlRe = -1;
            m_iBuzCtrlRe = NLSSysCtrl.buz_ctrl(m_iFreq, m_iVolume, m_iMdelay);

            m_iMdelay = 200;
            m_iBuzCtrlRe = NLSSysCtrl.buz_ctrl(m_iFreq, m_iVolume, m_iMdelay);

            m_iMdelay = 650;
            m_iBuzCtrlRe = NLSSysCtrl.buz_ctrl(m_iFreq, m_iVolume, m_iMdelay);
        }
        #endregion

        #region RFID ���
        /// <summary>
        /// �豸�򿪺������ɹ�����true��ʧ�ܷ���false
        /// </summary>
        /// <returns></returns>
        public override bool OpenRFID()
        {
            _Hdev = NLRF_Open("NL_CS2040", "COM7:9600,n,8,1");
            return IsRFIDOpened;
        }

        /// <summary>
        /// �豸�رպ������ɹ�����true��ʧ�ܷ���false
        /// </summary>
        /// <returns></returns>
        public override bool CloseRFID()
        {
            if (NLRF_Close(_Hdev) == 0)
            {
                _Hdev = IntPtr.Zero;
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// �ж��豸�Ƿ��
        /// </summary>
        /// <returns></returns>
        public override bool IsRFIDOpened
        {
            get
            {
                return _Hdev != IntPtr.Zero;
            }
        }

        /// <summary>
        /// ��鿨Ƭ���뺯��
        /// </summary>
        /// <param name="sector">����</param>
        /// <param name="keybyte">����</param>
        /// <returns></returns>
        public override bool CheckKey(int sector, byte[] keybyte)
        {
            string temp = HexStringConverter.HexToString(keybyte, string.Empty);
            if (!string.IsNullOrEmpty(temp))
            {
                byte[] key = System.Text.ASCIIEncoding.ASCII.GetBytes(temp);
                if (NLRF_ChkKey(_Hdev, 0, key, 12) == 0)
                {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// ��ȡ��n����m�������
        /// </summary>
        /// <param name="Sector">����</param>
        /// <param name="Blk">��</param>
        /// <returns></returns>
        public override byte[] ReadBlock(int Sector, int Blk)
        {
            int bulkSize = 16;
            byte[] readbyte = new byte[bulkSize];
            int iread = NLRF_ReadBlk(_Hdev, Sector, Blk, readbyte, bulkSize);
            if (iread != bulkSize)
            {
                readbyte = null;
            }
            return readbyte;
        }

        /// <summary>
        /// ��ȡ��Ƭ�����к�
        /// </summary>
        /// <returns></returns>
        public override string ReadCardID()
        {
            string readdata = "";
            RFDEV_CARDINFO card = new RFDEV_CARDINFO();
            card.CardNum = new byte[4];
            int ret = NLRF_QueryCardInfo(_Hdev, ref card);
            if (ret == 0)
            {
                readdata = SEBinaryConverter.BytesToLong(card.CardNum).ToString();
            }
            return readdata;
        }

        /// <summary>
        /// ��n����m��д������
        /// </summary>
        /// <param name="wstr">д������</param>
        /// <param name="Sector">����</param>
        /// <param name="Blk">��</param>
        /// <returns></returns>
        public override bool WriteBlock(byte[] wstr, int Sector, int Blk)
        {
            int ret = NLRF_WriteBlk(_Hdev, Sector, Blk, wstr, 16);
            if (ret > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        #endregion
    }
}
