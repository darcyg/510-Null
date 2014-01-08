﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Ralid.Park.DAL.IDAL;
using Ralid.Park.BusinessModel.Model;
using Ralid.Park.BusinessModel.SearchCondition;

namespace Ralid.Park.DAL.LinqDataProvider
{
    public class CardRecycleRecordProvider : ProviderBase<CardRecycleRecord, string>, ICardRecycleRecordProvider
    {
        public CardRecycleRecordProvider()
        {
        }

        public CardRecycleRecordProvider(string connStr)
            : base(connStr)
        {
        }

        #region  重写基类方法
        protected override List<CardRecycleRecord> GetingItems(ParkDataContext parking, SearchCondition search)
        {
            if (search is RecordSearchCondition)
            {
                RecordSearchCondition con = search as RecordSearchCondition;
                IQueryable<CardRecycleRecord> result = parking.CardRecycle;
                if (con.RecordDateTimeRange != null)
                {
                    result = result.Where(c => c.RecycleDateTime >= con.RecordDateTimeRange.Begin).AsQueryable();
                    result = result.Where(c => c.RecycleDateTime <= con.RecordDateTimeRange.End).AsQueryable();
                }
                if (con.Operator != null) result = result.Where(c => c.OperatorID == con.Operator.OperatorName);
                if (con.StationID != null && con.StationID != "") result = result.Where(c => c.StationID == con.StationID);
                if (!string.IsNullOrEmpty(con.CardID)) result = result.Where(c => c.CardID.Contains(con.CardID));
                if (!string.IsNullOrEmpty(con.CardCertificate)) result = result.Where(c => c.CardCertificate.Contains(con.CardCertificate));
                if (!string.IsNullOrEmpty(con.OwnerName)) result = result.Where(c => c.OwnerName.Contains(con.OwnerName));
                if (!string.IsNullOrEmpty(con.CarPlate)) result = result.Where(c => c.CarPlate.Contains(con.CarPlate));
                if (con.IsUnSettled != null)
                {
                    if (con.IsUnSettled.Value) result = result.Where(c => c.SettleDateTime == null);
                    else result = result.Where(c => c.SettleDateTime != null);
                }
                if (con.SettleDateTime != null) result = result.Where(c => c.SettleDateTime == con.SettleDateTime.Value);
                List<CardRecycleRecord> items = result.ToList();
                if (con.CardType != null) items = items.Where(c => c.CardType == con.CardType).ToList();
                return items;
            }
            return new List<CardRecycleRecord>();
        }
        #endregion
    }
}
