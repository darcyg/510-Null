VERSION 5.00
Begin VB.Form TollForm 
   BackColor       =   &H80000005&
   Caption         =   "Form1"
   ClientHeight    =   13410
   ClientLeft      =   840
   ClientTop       =   2010
   ClientWidth     =   14295
   LinkTopic       =   "Form1"
   ScaleHeight     =   13410
   ScaleWidth      =   14295
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   1095
      Left            =   3360
      TabIndex        =   38
      Top             =   3840
      Width           =   2175
   End
   Begin VB.CheckBox Check2 
      Caption         =   "�й�ҹ�շ�"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   7
      Left            =   10200
      TabIndex        =   37
      Top             =   2160
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "��������볡�շ�"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   6
      Left            =   8160
      TabIndex        =   36
      Top             =   2160
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "ÿ����������ʱ��"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   5
      Left            =   6120
      TabIndex        =   35
      Top             =   2160
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "�й�ҹ�շ�"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   4
      Left            =   4080
      TabIndex        =   34
      Top             =   2160
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "���ۼ��б��л�ʱ��"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   3
      Left            =   10200
      TabIndex        =   33
      Top             =   1800
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "�������л�ʱ��"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   2
      Left            =   8160
      TabIndex        =   32
      Top             =   1800
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "���ۼ��б��շ�"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   1
      Left            =   6120
      TabIndex        =   31
      Top             =   1800
      Width           =   1935
   End
   Begin VB.CheckBox Check2 
      Caption         =   "���볡����շ�"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   0
      Left            =   4080
      TabIndex        =   30
      Top             =   1800
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "����"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   7
      Left            =   10200
      TabIndex        =   29
      Top             =   1320
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "����"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   6
      Left            =   8160
      TabIndex        =   28
      Top             =   1320
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "����"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   5
      Left            =   6120
      TabIndex        =   27
      Top             =   1320
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "�������ⲻͬ"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   4
      Left            =   4080
      TabIndex        =   26
      Top             =   1320
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "����Ϊ����"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   3
      Left            =   10200
      TabIndex        =   25
      Top             =   960
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "����Ϊ����"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   2
      Left            =   8160
      TabIndex        =   24
      Top             =   960
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "�й����ռ��յ���"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   1
      Left            =   6120
      TabIndex        =   23
      Top             =   960
      Width           =   1935
   End
   Begin VB.CheckBox Check1 
      Caption         =   "�����շѲ�ͬ"
      ForeColor       =   &H8000000D&
      Height          =   255
      Index           =   0
      Left            =   4080
      TabIndex        =   22
      Top             =   960
      Width           =   1935
   End
   Begin VB.ComboBox Combo2 
      BackColor       =   &H80000002&
      ForeColor       =   &H80000004&
      Height          =   300
      ItemData        =   "Form1.frx":0000
      Left            =   6240
      List            =   "Form1.frx":003A
      TabIndex        =   20
      Text            =   "ѡ���շѱ���"
      Top             =   240
      Width           =   1935
   End
   Begin VB.ComboBox Combo0 
      BackColor       =   &H80000002&
      ForeColor       =   &H80000004&
      Height          =   300
      ItemData        =   "Form1.frx":00D5
      Left            =   2160
      List            =   "Form1.frx":010F
      TabIndex        =   1
      Text            =   "ѡ��������"
      Top             =   240
      Width           =   1575
   End
   Begin VB.ComboBox Combo1 
      BackColor       =   &H80000002&
      ForeColor       =   &H80000009&
      Height          =   300
      Index           =   0
      ItemData        =   "Form1.frx":01AA
      Left            =   2160
      List            =   "Form1.frx":01E3
      TabIndex        =   2
      Text            =   "ѡ���Ӧ�շѱ�"
      Top             =   720
      Width           =   1575
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000005&
      Caption         =   "�̶��ڼ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Left            =   720
      TabIndex        =   21
      Top             =   6960
      Width           =   1335
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000005&
      Caption         =   "���ʱ��(����)"
      ForeColor       =   &H80000002&
      Height          =   255
      Left            =   720
      TabIndex        =   19
      Top             =   6600
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��4�ֳ��ͼ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   15
      Left            =   360
      TabIndex        =   18
      Top             =   6120
      Width           =   1695
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��3�ֳ��ͼ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   14
      Left            =   360
      TabIndex        =   17
      Top             =   5760
      Width           =   1695
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��2�ֳ��ͼ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   13
      Left            =   360
      TabIndex        =   16
      Top             =   5400
      Width           =   1695
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��1�ֳ��ͼ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   12
      Left            =   360
      TabIndex        =   15
      Top             =   5040
      Width           =   1695
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��2�ֳ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   11
      Left            =   720
      TabIndex        =   14
      Top             =   4680
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��2�ֳ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   10
      Left            =   720
      TabIndex        =   13
      Top             =   4320
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��2�ֳ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   9
      Left            =   720
      TabIndex        =   12
      Top             =   3960
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��1�ֳ�������"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   8
      Left            =   720
      TabIndex        =   11
      Top             =   3600
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��4�ֳ��ͼ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   7
      Left            =   720
      TabIndex        =   10
      Top             =   3240
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��3�ֳ��ͼ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   6
      Left            =   720
      TabIndex        =   9
      Top             =   2880
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��2�ֳ��ͼ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   5
      Left            =   720
      TabIndex        =   8
      Top             =   2520
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��1�ֳ��ͼ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   4
      Left            =   720
      TabIndex        =   7
      Top             =   2160
      Width           =   1335
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��4�ֳ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   3
      Left            =   1080
      TabIndex        =   6
      Top             =   1800
      Width           =   975
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��3�ֳ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   2
      Left            =   1080
      TabIndex        =   5
      Top             =   1440
      Width           =   975
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��2�ֳ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   1
      Left            =   1080
      TabIndex        =   4
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000005&
      Caption         =   "��1�ֳ���"
      ForeColor       =   &H80000002&
      Height          =   255
      Index           =   0
      Left            =   1080
      TabIndex        =   3
      Top             =   720
      Width           =   975
   End
   Begin VB.Label Label0 
      BackColor       =   &H80000005&
      Caption         =   "��������"
      ForeColor       =   &H80000002&
      Height          =   255
      Left            =   1200
      TabIndex        =   0
      Top             =   240
      Width           =   855
   End
End
Attribute VB_Name = "TollForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Adodc1_WillMove(ByVal adReason As ADODB.EventReasonEnum, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)

End Sub

Private Sub Command1_Click()
     l = 8                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself                   'RS232������ַ
     OutData(4) = TYPE_Itself                   '���ձ���
     OutData(5) = COMR_SoftReset
     OutData(6) = 1                             '��������
     OutData(7) = 1                             '����
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

End Sub
