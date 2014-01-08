﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization ;
using Ralid.Park.BusinessModel.Enum ;

namespace Ralid.Park.BusinessModel.Model
{
    [Serializable ()]
    [DataContract]
    public class ParkInfo
    {
        #region 重载操作符
        public static bool operator ==(ParkInfo park1, ParkInfo park2)
        {
            return object.Equals(park1, park2);
        }

        public static bool operator !=(ParkInfo park1, ParkInfo park2)
        {
            return !object.Equals(park1, park2);
        }
        #endregion

        #region 构造函数
        public ParkInfo()
        {
            ParkFullText = "车位已满!";
            VacantText = "车位:";
            _Entrances = new List<EntranceInfo>();
            _SubParks = new List<ParkInfo>();
        }
        #endregion

        #region 私有变量
        [DataMember (Name ="Entrances")]
        private List<EntranceInfo> _Entrances;

        [DataMember(Name="SubParks")]
        private List<ParkInfo> _SubParks;
        #endregion

        #region 公共属性
        /// <summary>
        /// 车场ID
        /// </summary>
        [DataMember (Name ="ParkID")]
        public int ParkID { get; set; }

        /// <summary>
        /// 车场名
        /// </summary>
        [DataMember (Name ="ParkName")]
        public string ParkName { get; set; }

        /// <summary>
        /// 满位时显示字符
        /// </summary>
        [DataMember (Name ="ParkFullText")]
        public string ParkFullText { get; set; }

        /// <summary>
        /// 空余车位显示字符
        /// </summary>
        [DataMember (Name ="VacantText")]
        public string VacantText { get; set; }

        /// <summary>
        /// 总车位数量
        /// </summary>
        [DataMember (Name ="TotalPosition")]
        public short TotalPosition { get; set; }

        /// <summary>
        /// 最低车位数量
        /// </summary>
        [DataMember (Name ="MinPosition")] 
        public short MinPosition{get;set;}

        /// <summary>
        /// 余位数
        /// </summary>
        [DataMember (Name ="Vacant")]
        public short Vacant { get; set; }

        /// <summary>
        /// 命令服务器地址
        /// </summary>
        [DataMember (Name ="ParkAdapterUri")]
        public string ParkAdapterUri { get; set; }

        /// <summary>
        /// 获取或设置停车场主机的串口号
        /// </summary>
        [DataMember (Name ="CommPort")]
        public byte CommPort { get; set; }

        /// <summary>
        /// 获取或设置通讯工作站
        /// </summary>
        [DataMember (Name ="HostWorkstation")]
        public string HostWorkstation { get; set; }

        /// <summary>
        /// 获取或设置停车场车牌识别服务的地址
        /// </summary>
        [DataMember (Name="CarPlateRecognizeUri")]
        public string CarPlateRecognizeUri { get; set; }

        /// <summary>
        /// 获取或设置停车场的状态
        /// </summary>
        [DataMember]
        public EntranceStatus Status { get; set; }
        /// <summary>
        /// 获取或设置停车场是否为内套停车场
        /// </summary>
        [DataMember]
        public bool IsNested { get; set; }
        /// <summary>
        /// 获取或设置父车场的ID
        /// </summary>
        [DataMember]
        public int? ParentID { get; set; }
        /// <summary>
        /// 获取或设置停车场的最上层停车场ID
        /// </summary>
        [DataMember(Name = "RootParkID")]
        public int RootParkID { get; set; }
        /// <summary>
        /// 获取或设置停车场的工作模式
        /// </summary>
        [DataMember]
        public ParkWorkMode WorkMode { get; set; }
        /// <summary>
        /// 获取或设置停车场的通道硬件类型
        /// </summary>
        [DataMember]
        public EntranceDeviceType DeviceType { get; set; }
        /// <summary>
        /// 获取或设置停车场的选项
        /// </summary>
        [DataMember]
        public int Options { get; set; }
        /// <summary>
        /// 获取停车场的所有子车场
        /// </summary>
        public List<ParkInfo> SubParks
        {
            get
            {
                return _SubParks;
            }
        }

        /// <summary>
        /// 获取停车场的所有控制器的列表
        /// </summary>
        public List<EntranceInfo> Entrances
        {
            get
            {
                return _Entrances;
            }
        }
        /// <summary>
        /// 获取停车场的主控制器
        /// </summary>
        public EntranceInfo MastEntrance
        {
            get
            {
                foreach (EntranceInfo entrace in _Entrances)
                {
                    if (entrace.IsMaster) return entrace;
                }
                return null;
            }
        }
        /// <summary>
        /// 通过控制器ID获取控制器
        /// </summary>
        /// <param name="address">控制器地地址</param>
        /// <returns></returns>
        public EntranceInfo GetEntrance(int entranceID)
        {
            foreach (EntranceInfo entrance in _Entrances)
            {
                if (entrance.EntranceID == entranceID)
                {
                    return entrance;
                }
            }
            if (_SubParks != null && _SubParks.Count > 0)
            {
                foreach (ParkInfo park in _SubParks)
                {
                    EntranceInfo en = park.GetEntrance(entranceID);
                    if (en != null) return en;
                }
            }
            return null;
        }

        public List<EntranceInfo> GetEntrances(bool containNestPark)
        {
            List<EntranceInfo> items = new List<EntranceInfo>();
            if (_Entrances != null) items.AddRange(_Entrances);
            if (containNestPark)
            {
                if (_SubParks != null)
                {
                    foreach (ParkInfo p in _SubParks)
                    {
                        if (p._Entrances != null) items.AddRange(p._Entrances);
                    }
                }
            }
            return items;
        }

        /// <summary>
        /// 获取停车场是否是顶层停车场
        /// </summary>
        public bool IsRootPark
        {
            get { return ParentID == null; }
        }

        /// <summary>
        /// 获取停车场是否写卡模式
        /// </summary>
        public bool IsWriteCardMode
        {
            get { return DeviceType == EntranceDeviceType.NETEntrance && WorkMode == ParkWorkMode.OffLine; }
        }
        #endregion

        #region 重写基类方法
        public override bool Equals(object obj)
        {
            bool equal = false;
            if (obj is ParkInfo)
            {
                ParkInfo park = obj as ParkInfo;
                equal = park.ParkID == this.ParkID;
            }
            return equal;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
        /// <summary>
        /// 复制一个停车场内容
        /// </summary>
        /// <returns></returns>
        public ParkInfo Clone()
        {
            return (ParkInfo)this.MemberwiseClone();
        }
        #endregion
    }
}
