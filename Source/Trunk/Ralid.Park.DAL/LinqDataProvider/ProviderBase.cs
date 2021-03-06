﻿using System;
using System.Linq;
using System.Data.Linq;
using System.Data.SqlClient;
using System.Collections.Generic;
using Ralid.Park.DAL.IDAL;
using Ralid.Park.BusinessModel.Resouce;
using Ralid.Park.BusinessModel.Result;
using Ralid.Park.BusinessModel.Enum;
using Ralid.Park.BusinessModel.Interface;
using Ralid.Park.BusinessModel.SearchCondition;
using Ralid.GeneralLibrary.ExceptionHandling;

namespace Ralid.Park.DAL.LinqDataProvider
{
    public abstract class ProviderBase<TInfo, TID> : IProvider<TInfo, TID> where TInfo : class, new()
    {
        protected readonly string successMsg = "ok";

        public string ConnectStr { get; set; }


        public  ProviderBase(string connectStr)
        {
            this.ConnectStr = connectStr;
        }

        public ProviderBase()
        {
        }

        

        #region IProvider <TInfo> 成员

        public QueryResult<TInfo> GetByID(TID id)
        {

            QueryResult<TInfo> result;
            try
            {
                ParkDataContext parking = ParkDataContextFactory.CreateParking(ConnectStr);
                if (parking == null)
                {
                    result = new QueryResult<TInfo>(ResultCode.CannotConnectServer, ResultCodeDecription.GetDescription(ResultCode.CannotConnectServer), null);
                }
                else
                {
                    TInfo info = GetingItemByID(id, parking);
                    if (info != null)
                    {
                        result = new QueryResult<TInfo>(ResultCode.Successful, successMsg, info);
                    }
                    else
                    {
                        result = new QueryResult<TInfo>(ResultCode.Fail, ResultCodeDecription.GetDescription(ResultCode.Fail), info);
                    }
                }
            }
            catch (SqlException ex)
            {
                result = new QueryResult<TInfo>(ResultCodeResolver.GetFromSqlExceptionNumber(ex.Number), ex.Message, null);
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "GetByID()");
            }
            catch (Exception ex)
            {
                result = new QueryResult<TInfo>(ResultCode.Fail, ex.Message, null);
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "GetByID()");
            }
            return result;
        }

        public QueryResultList<TInfo> GetAll()
        {
            QueryResultList<TInfo> result;
            try
            {
                ParkDataContext parking = ParkDataContextFactory.CreateParking(ConnectStr);
                if (parking == null)
                {
                    result = new QueryResultList<TInfo>(ResultCode.CannotConnectServer, ResultCodeDecription.GetDescription(ResultCode.CannotConnectServer), new List<TInfo>());
                }
                else
                {
                    List<TInfo> infoes = GetingAllItems(parking);
                    result = new QueryResultList<TInfo>(ResultCode.Successful, successMsg, infoes);
                }
            }
            catch (SqlException ex)
            {
                result = new QueryResultList<TInfo>(ResultCodeResolver.GetFromSqlExceptionNumber(ex.Number), ex.Message, new List<TInfo>());
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "GetAll()");
            }
            catch (Exception ex)
            {
                result = new QueryResultList<TInfo>(ResultCode.Fail, ex.Message, new List<TInfo>());
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "GetAll()");
            }
            return result;
        }

        public QueryResultList<TInfo> GetItems(SearchCondition search)
        {
            QueryResultList<TInfo> result;
            try
            {
                ParkDataContext parking = ParkDataContextFactory.CreateParking(ConnectStr);
                if (parking == null)
                {
                    result = new QueryResultList<TInfo>(ResultCode.CannotConnectServer, ResultCodeDecription.GetDescription(ResultCode.CannotConnectServer), new List<TInfo>());
                }
                else
                {
                    List<TInfo> infoes;
                    if (search != null)
                    {
                        infoes = GetingItems(parking, search);
                    }
                    else
                    {
                        infoes = GetingAllItems(parking);
                    }
                    result = new QueryResultList<TInfo>(ResultCode.Successful, successMsg, infoes);
                }
            }
            catch (SqlException ex)
            {
                result = new QueryResultList<TInfo>(ResultCodeResolver.GetFromSqlExceptionNumber(ex.Number), ex.Message, new List<TInfo>());
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "GetItems()");
            }
            catch (Exception ex)
            {
                result = new QueryResultList<TInfo>(ResultCode.Fail, ex.Message, new List<TInfo>());
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "GetItems()");
            }
            return result;
        }

        public CommandResult Insert(TInfo info)
        {
            CommandResult result;
            try
            {
                ParkDataContext parking = ParkDataContextFactory.CreateParking(ConnectStr);
                if (parking == null)
                {
                    result = new CommandResult(ResultCode.CannotConnectServer, ResultCodeDecription.GetDescription(ResultCode.CannotConnectServer));
                }
                else
                {
                    InsertingItem(info, parking);
                    parking.SubmitChanges();
                    result = new CommandResult(ResultCode.Successful, successMsg);
                }
            }
            catch (SqlException ex)
            {
                result = new CommandResult(ResultCodeResolver.GetFromSqlExceptionNumber(ex.Number), ex.Message);
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "Insert()");
            }
            catch (Exception ex)
            {
                result = new CommandResult(ResultCode.Fail, ex.Message);
                ExceptionPolicy.HandleException(ex, this.GetType().Name + "." + "Insert()");
            }
            return result;
        }

        public CommandResult Update(TInfo newVal, TInfo original)
        {
            CommandResult result;
            try
            {
                ParkDataContext parking = ParkDataContextFactory.CreateParking(ConnectStr);
                if (parking == null)
                {
                    result = new CommandResult(ResultCode.CannotConnectServer, ResultCodeDecription.GetDescription(ResultCode.CannotConnectServer));
                }
                else
                {
                    UpdatingItem(newVal, original, parking);
                    parking.SubmitChanges();
                    result = new CommandResult(ResultCode.Successful, successMsg);
                }
            }
            catch (SqlException ex)
            {
                result = new CommandResult(ResultCodeResolver.GetFromSqlExceptionNumber(ex.Number), ex.Message);
                ExceptionPolicy.HandleException(ex, this.GetType().FullName + "." + "Update()");
            }
            catch (Exception ex)
            {
                result = new CommandResult(ResultCode.Fail, ex.Message);
                ExceptionPolicy.HandleException(ex, this.GetType().FullName + "." + "Update()");
            }
            return result;
        }

        public CommandResult Delete(TInfo info)
        {
            CommandResult result;
            try
            {
                ParkDataContext parking = ParkDataContextFactory.CreateParking(ConnectStr);
                if (parking == null)
                {
                    result = new CommandResult(ResultCode.CannotConnectServer, ResultCodeDecription.GetDescription(ResultCode.CannotConnectServer));
                }
                else
                {
                    DeletingItem(info, parking);
                    parking.SubmitChanges();
                    result = new CommandResult(ResultCode.Successful, successMsg);
                }
            }
            catch (SqlException ex)
            {
                result = new CommandResult(ResultCodeResolver.GetFromSqlExceptionNumber(ex.Number), ex.Message);
                ExceptionPolicy.HandleException(ex, this.GetType().FullName + "." + "Delete()");
            }
            catch (Exception ex)
            {
                result = new CommandResult(ResultCode.Fail, ex.Message);
                ExceptionPolicy.HandleException(ex, this.GetType().FullName + "." + "Delete()");
            }
            return result;
        }

        public void Insert(TInfo info, IUnitWork unitWork)
        {
            if (unitWork == null)
            {
                throw new NullReferenceException("参数unitWork为空!");
            }
            if (unitWork is UnitWork)
            {
                UnitWork trans = unitWork as UnitWork;
                ParkDataContext parking = trans.Parking;
                if (parking != null)
                {
                    InsertingItem(info, parking);
                }
            }
            //else if (unitWork is TransactionsWork)
            //{
            //    TransactionsWork trans = unitWork as TransactionsWork;
            //    if (trans.Master.Parking != null)
            //    {
            //        InsertingItem(info, trans.Master.Parking);
            //    }
            //    if (trans.Standby.Parking != null)
            //    {
            //        InsertingItem(info, trans.Standby.Parking);
            //    }
            //}
            else
            {
                throw new InvalidCastException("参数unitWork不能转换成类型Ralid.LinqDataProvider.UnitWork/TransactionsWork," +
                        "请检查参数是否是一个Ralid.LinqDataProvider.UnitWork/TransactionsWork实例!");
            }
        }

        public void Update(TInfo newVal, TInfo originalVal, IUnitWork unitWork)
        {
            if (unitWork == null)
            {
                throw new NullReferenceException("参数unitWork为空!");
            }
            if (unitWork is UnitWork)
            {
                UnitWork trans = unitWork as UnitWork;
                ParkDataContext parking = trans.Parking;
                if (parking != null)
                {
                    UpdatingItem(newVal, originalVal, parking);
                }
            }
            //else if (unitWork is TransactionsWork)
            //{
            //    TransactionsWork trans = unitWork as TransactionsWork;
            //    if (trans.Master.Parking != null)
            //    {
            //        UpdatingItem(newVal, originalVal, trans.Master.Parking);
            //    }
            //    if (trans.Standby.Parking != null)
            //    {
            //        UpdatingItem(newVal, originalVal, trans.Standby.Parking);
            //    }
            //}
            else
            {
                throw new InvalidCastException("参数unitWork不能转换成类型Ralid.LinqDataProvider.UnitWork/TransactionsWork," +
                    "请检查参数是否是一个Ralid.LinqDataProvider.UnitWork/TransactionsWork实例!");
            }
        }

        public void Delete(TInfo info, IUnitWork unitWork)
        {
            if (unitWork == null)
            {
                throw new NullReferenceException("参数unitWork为空!");
            }
            if (unitWork is UnitWork)
            {
                UnitWork trans = unitWork as UnitWork;
                ParkDataContext parking = trans.Parking;
                if (parking != null)
                {
                    DeletingItem(info, parking);
                }
            }
            //else if (unitWork is TransactionsWork)
            //{
            //    TransactionsWork trans = unitWork as TransactionsWork;
            //    if (trans.Master.Parking != null)
            //    {
            //        DeletingItem(info, trans.Master.Parking);
            //    }
            //    if (trans.Standby.Parking != null)
            //    {
            //        DeletingItem(info, trans.Standby.Parking);
            //    }
            //}
            else
            {
                throw new InvalidCastException("参数unitWork不能转换成类型Ralid.LinqDataProvider.UnitWork/TransactionsWork," +
                    "请检查参数是否是一个Ralid.LinqDataProvider.UnitWork/TransactionsWork实例!");
            }
        }
        #endregion

        #region 模板方法
        protected virtual TInfo GetingItemByID(TID id, ParkDataContext parking)
        {
            //每一个子类都要重写这个方法
            throw new Exception("子类没有重写GetingItemByID方法!");
        }
        protected virtual List<TInfo> GetingAllItems(ParkDataContext parking)
        {
            //如果实体类要加载其关联数据,就重写此方法
            return parking.GetTable<TInfo>().Select(t => t).ToList();
        }
        protected virtual List<TInfo> GetingItems(ParkDataContext parking, SearchCondition search)
        {
            //如果要实现这个功能,子类一定要重写这个方法
            throw new NotImplementedException("子类没有重写GetingItems方法");
        }
        protected virtual void InsertingItem(TInfo info, ParkDataContext parking)
        {
            parking.GetTable<TInfo>().InsertOnSubmit(info);
        }
        protected virtual void UpdatingItem(TInfo newVal, TInfo original, ParkDataContext parking)
        {
            //所有实体都可以用这个方法来更新数据
            parking.GetTable<TInfo>().Attach(newVal, original);
        }
        protected virtual void DeletingItem(TInfo info, ParkDataContext parking)
        {
            //如果删除实体时要删除其关联数据,就得重写这个方法
            parking.GetTable<TInfo>().Attach(info);
            parking.GetTable<TInfo>().DeleteOnSubmit(info);
        }
        #endregion
    }
}
