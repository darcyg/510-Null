﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Ralid.Park.BusinessModel.Model;
using Ralid.Park.BusinessModel.SearchCondition;
using Ralid.Park.BusinessModel.Enum;
using Ralid.Park.BusinessModel;
using Ralid.Park.BusinessModel.Result;
using Ralid.Park.DAL.IDAL;

namespace Ralid.Park.BLL
{
    public class VideoSourceBll
    {
        #region 构造函数
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="repoUri">存储层的资源标识(可以是数据库连接字符串或文件名等，根据存储层的不同可以设置不同的值)</param>
        public VideoSourceBll(string repoUri)
        {
            provider = ProviderFactory.Create<IVideoSourceProvider>(repoUri);
        }
        #endregion

        #region 私有变量
        IVideoSourceProvider provider;
        #endregion

        #region 公共方法
        public QueryResult<VideoSourceInfo> GetVideoSourceByID(int id)
        {
            return provider.GetByID(id);
        }

        public QueryResultList<VideoSourceInfo> GetAllVideoSources()
        {
            return provider.GetAll();
        }

        public QueryResultList<VideoSourceInfo> GetVideoSourcesOfEntrance(int entranceID)
        {
            QueryResultList<VideoSourceInfo> result = GetAllVideoSources();
            result.QueryObjects = result.QueryObjects.Where(v => v.EntranceID == entranceID).ToList();
            return result;
        }

        public CommandResult Insert(VideoSourceInfo info)
        {
            return provider.Insert(info);
        }

        public CommandResult Update(VideoSourceInfo info)
        {
            VideoSourceInfo original = GetVideoSourceByID(info.VideoID).QueryObject;
            return provider.Update(info, original);
        }

        public CommandResult Delete(VideoSourceInfo info)
        {
            return provider.Delete(info);
        }

        /// <summary>
        /// 删除所有视频
        /// </summary>
        /// <returns></returns>
        public CommandResult DeleteAllVideos()
        {
            return provider.DeleteAllItems();
        }

        /// <summary>
        /// 插入包括主键值的视频记录
        /// </summary>
        /// <param name="info"></param>
        /// <returns></returns>
        public CommandResult InsertWithPrimaryKey(VideoSourceInfo info)
        {
            return provider.InsertWithPrimaryKey(info);
        }

        /// <summary>
        /// 更新控制板，如没有视频，则新插入视频记录
        /// </summary>
        /// <param name="info"></param>
        /// <param name="withPrimaryKey">是否插入主键值</param>
        /// <returns></returns>
        public CommandResult UpdateOrInsert(VideoSourceInfo info, bool withPrimaryKey)
        {
            VideoSourceInfo original = provider.GetByID(info.VideoID).QueryObject;

            if (original != null)
            {
                return provider.Update(info, original);
            }
            else if (withPrimaryKey)
            {
                return provider.InsertWithPrimaryKey(info);
            }
            else
            {
                return provider.Insert(info);
            }
        }
        #endregion
    }
}
