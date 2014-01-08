﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Ralid.Park.BLL;
using Ralid.Park.BusinessModel.Model;
using Ralid.Park.BusinessModel.Enum;
using Ralid.Park.BusinessModel.Result;
using Ralid.Park.UI.Resources;
using Ralid.Park.BusinessModel.Configuration;
using Ralid.Park.ParkAdapter;
using Ralid.GeneralLibrary.CardReader;

namespace Ralid.Park.UI
{
    public partial class FrmCardRecycle :Form
    {
        public FrmCardRecycle()
        {
            InitializeComponent();
        }

        #region 私有变量
        private bool readCard = false;//是否读到需操作的卡片，用于写卡模式
        #endregion

        public event EventHandler<ItemUpdatedEventArgs> ItemUpdated;
        public CardInfo RecycleCard { get; set; }


        private void CardReadHandler(object sender, CardReadEventArgs e)
        {
            Action action = delegate()
            {
                if (!chkWriteCard.Checked) return;
                //检查是否当前操作的卡片
                if (RecycleCard != null &&
                    !CardOperationManager.Instance.CheckReadCardIDWithMessage(RecycleCard.CardID, e.CardID))
                {
                    readCard = false;
                    return;
                }

                if (!CardOperationManager.Instance.CheckReadDateWithMessage(e.ParkingDate))
                {
                    readCard = false;
                    return;
                }
                else
                {
                    //转换读出的卡片数据
                    if (RecycleCard != null)
                    {
                        CardDateResolver.Instance.SetCardInfoFromData(RecycleCard, e.ParkingDate, true);
                    }
                    else
                    {
                        RecycleCard = CardDateResolver.Instance.GetCardInfoFromData(e.CardID, e.ParkingDate);
                    }
                    this.ucCardInfo.Card = RecycleCard;
                    readCard = true;
                }
            };
            if (this.InvokeRequired)
            {
                this.Invoke(action);
            }
            else
            {
                action();
            }
        }

        private bool CheckInput()
        {
            if (this.chkWriteCard.Checked)
            {
                if (!readCard)
                {
                    MessageBox.Show(Resource1.FrmCardRecycle_ReadCard);
                    return false;
                }

                //写卡模式时，先读取卡片信息
                if (!CardOperationManager.Instance.CheckCardWithMessage(RecycleCard.CardID)) return false;
            }
            return true;
        }     

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void FrmCardRecycle_Load(object sender, EventArgs e)
        {
            this.chkWriteCard.Checked = AppSettings.CurrentSetting.EnableWriteCard;//写卡模式时默认选中
            this.chkWriteCard.Visible = AppSettings.CurrentSetting.EnableWriteCard;//写卡模式时显示

            this.ucCardInfo.Init();
            this.ucCardInfo.UseToShow();
            if (this.RecycleCard != null)
            {
                this.ucCardInfo.Card = this.RecycleCard;
                this.txtTurnbackMoney.DecimalValue = this.RecycleCard.Deposit;
            }
            if (AppSettings.CurrentSetting.EnableWriteCard)
            {
                CardReaderManager.GetInstance(UserSetting.Current.WegenType).PushCardReadRequest(CardReadHandler);
            }
        }


        private void btnOk_Click(object sender, EventArgs e)
        {
            if (RecycleCard != null)
            {
                if (CheckInput())
                {
                    decimal money;
                    money = this.txtTurnbackMoney.DecimalValue;
                    CardBll bll = new CardBll(AppSettings.CurrentSetting.ParkConnect);
                    CommandResult result = bll.CardRecycle(this.RecycleCard, money, this.txtMemo.Text, !AppSettings.CurrentSetting.EnableWriteCard);
                    if (result.Result == ResultCode.Successful)
                    {
                        //写卡模式时，将卡片信息写入卡片，这里会使用循环写卡，直到成功或用户取消
                        if (this.chkWriteCard.Checked)
                        {
                            CardOperationManager.Instance.WriteCardLoop(RecycleCard);                            
                        }

                        if (this.ItemUpdated != null) ItemUpdated(this, new ItemUpdatedEventArgs(RecycleCard));
                        this.Close();
                    }
                    else
                    {
                        MessageBox.Show(result.Message);
                    }
                }
            }
        }

        private void FrmCardRecycle_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (AppSettings.CurrentSetting.EnableWriteCard)
            {
                CardReaderManager.GetInstance(UserSetting.Current.WegenType).PopCardReadRequest(CardReadHandler);
            }
        }

    }
}
