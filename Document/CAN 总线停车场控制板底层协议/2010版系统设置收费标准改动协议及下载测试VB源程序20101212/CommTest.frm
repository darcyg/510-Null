VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form MainForm 
   Caption         =   "2010��CAN����ͣ����ϵͳ���������ó�ʽ20101212  ��ѡ��20100318���ڵ����ݿ����أ��������"
   ClientHeight    =   8730
   ClientLeft      =   525
   ClientTop       =   1065
   ClientWidth     =   12840
   ClipControls    =   0   'False
   BeginProperty Font 
      Name            =   "Wingdings"
      Size            =   9.75
      Charset         =   2
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H0000FFFF&
   LinkTopic       =   "Form2"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   13942.56
   ScaleMode       =   0  'User
   ScaleWidth      =   27439.91
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "��ȡID��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   1
      Left            =   360
      MaskColor       =   &H00FF8080&
      TabIndex        =   60
      Top             =   7440
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "��ȡID���Ż�"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   6
      Left            =   1320
      MaskColor       =   &H00FF8080&
      TabIndex        =   59
      Top             =   6840
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "Mfֹͣ����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   0
      Left            =   360
      MaskColor       =   &H00FF8080&
      TabIndex        =   58
      Top             =   6840
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "Mf������ʱ��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   9
      Left            =   2280
      MaskColor       =   &H00FF8080&
      TabIndex        =   57
      Top             =   6840
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "Mf�����Żݴ�ֵ��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   10
      Left            =   2280
      MaskColor       =   &H00FF8080&
      TabIndex        =   56
      Top             =   7440
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "Mf��ʱ������"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   11
      Left            =   3240
      MaskColor       =   &H00FF8080&
      TabIndex        =   55
      Top             =   6840
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran2 
      BackColor       =   &H8000000D&
      Caption         =   "Mf�Żݳ�ֵ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   12
      Left            =   3240
      MaskColor       =   &H00FF8080&
      TabIndex        =   54
      Top             =   7440
      UseMaskColor    =   -1  'True
      Width           =   855
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "�¼���Ч"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   29
      Left            =   6840
      MaskColor       =   &H00FF8080&
      TabIndex        =   53
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "�ֶ���բ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   20
      Left            =   5760
      MaskColor       =   &H00FF8080&
      TabIndex        =   51
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "���ر�������"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   44
      Left            =   11280
      MaskColor       =   &H00FF8080&
      TabIndex        =   43
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   1335
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "�������"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   18
      Left            =   2520
      MaskColor       =   &H00FF8080&
      TabIndex        =   50
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "���߲�ѯ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   12
      Left            =   2520
      MaskColor       =   &H00FF8080&
      TabIndex        =   49
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "ʵʱģʽ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   10
      Left            =   1440
      MaskColor       =   &H00FF8080&
      TabIndex        =   48
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "�Զ�ģʽ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   9
      Left            =   1440
      MaskColor       =   &H00FF8080&
      TabIndex        =   47
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "����һ��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   51
      Left            =   4680
      MaskColor       =   &H00FF8080&
      TabIndex        =   46
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "���س���"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   50
      Left            =   4680
      MaskColor       =   &H00FF8080&
      TabIndex        =   45
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.TextBox Text2 
      BackColor       =   &H00FF0000&
      BeginProperty Font 
         Name            =   "����"
         Size            =   14.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   405
      Left            =   360
      OLEDragMode     =   1  'Automatic
      OLEDropMode     =   2  'Automatic
      ScrollBars      =   2  'Vertical
      TabIndex        =   42
      Text            =   "1"
      Top             =   4680
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "̧բ����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   19
      Left            =   5760
      MaskColor       =   &H00FF8080&
      TabIndex        =   41
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H000000FF&
      Caption         =   "ѡ�������ļ�"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Index           =   49
      Left            =   11280
      MaskColor       =   &H8000000D&
      Style           =   1  'Graphical
      TabIndex        =   40
      Top             =   4560
      Width           =   1335
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   10920
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "����ϵͳ����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   48
      Left            =   9840
      MaskColor       =   &H00FF8080&
      TabIndex        =   39
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   1335
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "��λ��λ����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   47
      Left            =   8400
      MaskColor       =   &H00FF8080&
      TabIndex        =   38
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   1335
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "��λ��������"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   46
      Left            =   8400
      MaskColor       =   &H00FF8080&
      TabIndex        =   37
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   1335
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "�����շѱ�׼"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   45
      Left            =   9840
      MaskColor       =   &H00FF8080&
      TabIndex        =   36
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   1335
   End
   Begin VB.TextBox Text3 
      BackColor       =   &H00FF0000&
      BeginProperty Font 
         Name            =   "����"
         Size            =   14.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   555
      Left            =   1440
      OLEDragMode     =   1  'Automatic
      OLEDropMode     =   2  'Automatic
      ScrollBars      =   2  'Vertical
      TabIndex        =   35
      Text            =   " �й��׼� CAN BUS IC/ID�� �ѻ�ϵͳ "
      Top             =   4560
      Width           =   9735
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "ʱ������"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   17
      Left            =   6840
      MaskColor       =   &H00FF8080&
      TabIndex        =   34
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "�ͻ�����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   16
      Left            =   3600
      MaskColor       =   &H00FF8080&
      TabIndex        =   33
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "������λ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   14
      Left            =   360
      MaskColor       =   &H00FF8080&
      TabIndex        =   32
      Top             =   6000
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "ֱͨ��ʾ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   15
      Left            =   3600
      MaskColor       =   &H00FF8080&
      TabIndex        =   31
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.CommandButton Tran1 
      BackColor       =   &H8000000D&
      Caption         =   "������λ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   11
      Left            =   360
      MaskColor       =   &H00FF8080&
      TabIndex        =   30
      Top             =   5400
      UseMaskColor    =   -1  'True
      Width           =   975
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   11640
      Top             =   120
   End
   Begin VB.Frame Frame3 
      Caption         =   "����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2775
      Left            =   240
      TabIndex        =   9
      Top             =   1440
      Width           =   12375
      Begin VB.TextBox Text4 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   1575
         Left            =   120
         MultiLine       =   -1  'True
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         ScrollBars      =   2  'Vertical
         TabIndex        =   21
         Text            =   "CommTest.frx":0000
         Top             =   960
         Width           =   12135
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   6
         Left            =   11640
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   20
         Tag             =   "100"
         Text            =   "06"
         Top             =   600
         Width           =   375
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   5
         Left            =   8640
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   19
         Text            =   "05"
         Top             =   600
         Width           =   3015
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   4
         Left            =   8280
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   18
         Text            =   "04"
         Top             =   600
         Width           =   375
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   3
         Left            =   5520
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   17
         Text            =   "03"
         Top             =   600
         Width           =   2775
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   2
         Left            =   3360
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   16
         Text            =   "02"
         Top             =   600
         Width           =   2175
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   1
         Left            =   1200
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   15
         Text            =   $"CommTest.frx":000D
         Top             =   600
         Width           =   2175
      End
      Begin VB.TextBox Text1 
         BackColor       =   &H00FF00FF&
         BeginProperty Font 
            Name            =   "����"
            Size            =   10.5
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   345
         Index           =   0
         Left            =   120
         OLEDragMode     =   1  'Automatic
         OLEDropMode     =   2  'Automatic
         TabIndex        =   14
         Text            =   $"CommTest.frx":0015
         Top             =   600
         Width           =   1095
      End
      Begin VB.Label Label2 
         Caption         =   "CRCУ��"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   14
         Left            =   11400
         TabIndex        =   28
         Top             =   360
         Width           =   735
      End
      Begin VB.Label Label2 
         Caption         =   "ָ�������ϸ"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   17
         Left            =   9360
         TabIndex        =   27
         Top             =   360
         Width           =   1335
      End
      Begin VB.Label Label2 
         Caption         =   "��������"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   18
         Left            =   8040
         TabIndex        =   26
         Top             =   360
         Width           =   855
      End
      Begin VB.Label Label2 
         Caption         =   "ָ������"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   19
         Left            =   6480
         TabIndex        =   25
         Top             =   360
         Width           =   855
      End
      Begin VB.Label Label2 
         Caption         =   "ָ����ʼ��"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   23
         Left            =   240
         TabIndex        =   24
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label2 
         Caption         =   "�����豸"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   25
         Left            =   1920
         TabIndex        =   23
         Top             =   360
         Width           =   855
      End
      Begin VB.Label Label2 
         Caption         =   "ָ�����"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   26
         Left            =   4080
         TabIndex        =   22
         Top             =   360
         Width           =   855
      End
   End
   Begin VB.Frame ����ѡ�� 
      Caption         =   "����ѡ��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   240
      TabIndex        =   4
      Top             =   600
      Width           =   4095
      Begin VB.OptionButton Option1 
         Caption         =   "COM1"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   0
         Left            =   240
         TabIndex        =   8
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option1 
         Caption         =   "COM2"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   1
         Left            =   1200
         TabIndex        =   7
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option1 
         Caption         =   "COM3"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   2
         Left            =   2160
         TabIndex        =   6
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option1 
         Caption         =   "COM4"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   3
         Left            =   3120
         TabIndex        =   5
         Top             =   240
         Width           =   855
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "������ѡ��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   4440
      TabIndex        =   1
      Top             =   600
      Width           =   5775
      Begin VB.OptionButton Option2 
         Caption         =   "115200"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   5
         Left            =   4680
         TabIndex        =   13
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option2 
         Caption         =   "57600"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   4
         Left            =   3720
         TabIndex        =   12
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option2 
         Caption         =   "38400"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   3
         Left            =   2760
         TabIndex        =   11
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option2 
         Caption         =   "19200"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   2
         Left            =   1800
         TabIndex        =   10
         Top             =   240
         Width           =   855
      End
      Begin VB.OptionButton Option2 
         Caption         =   "9600"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   1
         Left            =   960
         TabIndex        =   3
         Top             =   240
         Width           =   735
      End
      Begin VB.OptionButton Option2 
         Caption         =   "2400"
         BeginProperty Font 
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   2
         Top             =   240
         Width           =   735
      End
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   10320
      Top             =   720
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
      InBufferSize    =   512
      InputMode       =   1
   End
   Begin VB.Label Label3 
      Caption         =   "2006-10-18"
      BeginProperty Font 
         Name            =   "Wingdings"
         Size            =   14.25
         Charset         =   2
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   375
      Index           =   0
      Left            =   11040
      TabIndex        =   52
      Top             =   600
      Width           =   1575
   End
   Begin VB.Label Label2 
      Caption         =   "ѡ�����"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Index           =   0
      Left            =   480
      TabIndex        =   44
      Top             =   4440
      Width           =   855
   End
   Begin VB.Label Label3 
      Caption         =   "12:12:30"
      BeginProperty Font 
         Name            =   "Wingdings"
         Size            =   14.25
         Charset         =   2
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   375
      Index           =   1
      Left            =   11160
      TabIndex        =   29
      Top             =   960
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "2010��CAN����ͣ����ϵͳ���������ó�ʽ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   2040
      TabIndex        =   0
      Top             =   0
      Width           =   8775
   End
   Begin VB.Menu DataEdit 
      Caption         =   "ϵͳ���ü��շѱ�׼�޸�"
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim RxCommByteCount As Integer
Dim RxData(512) As Byte
Dim Database1 As Database
'Dim TableRxCommand As TableDef
Dim RecordsetRx As Recordset
Dim RecordsetAddress As Recordset
Dim RecordsetCommand As Recordset

Dim DatabaseTran As Database
Dim DataTollTableName As Recordset
Dim RecordsetTran As Recordset

Dim RxText As String
Dim RelayNum As Byte
Dim CardWait As Byte
Dim CardValid As Byte
Dim CardInvalid As Byte
Dim LinkMode1 As Byte
Dim Volume As Byte
Dim VehicleType As Byte


Const CONCommSyn1 = &HFE
Const CONCommSyn2 = &HFD
Const CONCommSyn3 = &HFE
Const ADDR_Broadcast = &HF0                                      '�㲥��ַ�����豸broadcast
Const ADDR_NotAssign = &HFF                                      'δ�����ַ�豸
                                                                 '�豸ר��ָ�����0x10-0x1D(0x01-0x0Fͨ��ָ��)���ܿ�CONCommSyn 1E1F
Const ADDR_Myself = &H0                                            'һ�н�������232��ָ������豸�ı�������
Const TYPE_Itself = &H0                                          'һ�н����豸�ı�������
Const ADDR_RS232_1 = &HF1                                         '�����豸��1��(Ĭ�ϵ�)����
Const ADDR_RS232_2 = &HF2                                         '�����豸��2�Ŵ���

Const ADDR_CanManager = &H1                                      '�Դμ����Ե�CAN��������
Const ADDR_SystemManageMachine = &H1                             'ϵͳ�������ַ(01-1D)��PC����
Const ADDR_PassageController = &H0                               '����ͨ��������,����㲥��ַ= &H20,ԭ����ͬ����Ӳ���ɻ���,���ֳ��������,��������(��������)������,���ӳ���ֻ���޸Ĺ��������.��Ȼ����Ҳ��������.
Const ADDR_EntranceController = &H20                             '����ͨ��������,����㲥��ַ0x20,ԭ����ͬ����Ӳ���ɻ���,���ֳ��������,��������(��������)������,���ӳ���ֻ���޸Ĺ��������.��Ȼ����Ҳ��������.
'Const ADDR_ExitController = &H40                                '����ͨ��������,����㲥��ַ0x20,ԭ����ͬ����Ӳ���ɻ���,���ֳ��������,��������(��������)������,���ӳ���ֻ���޸Ĺ��������.��Ȼ����Ҳ��������.
                                                                 '�Ž������������幫�õ�ָ�Ӧͳһ����Χ���ַԼͬ
                                                                 '���Ѵ���������幫�õ�ָ�Ӧͳһ����Χ���ַԼͬ
                                                                 '���ݿ����������幫�õ�ָ�Ӧͳһ����Χ���ַԼͬ
Const ADDR_LedScreen = &H60                                      '������ʾ����������ʾ����ָ�Ϊ���ַ���
Const ADDR_HeatPrinter = &H70                                    '����ֽƱ��ָ�Ϊ���ַ���
Const ADDR_VehicleDetector = &H80                                '�������������32��������������
Const ADDR_CardProvider = &HA0                                   '�Զ������������Զ��տ������������ɹҽӴ��豸��ָ�Ӧͳһ
Const ADDR_Reader = &HB0                                         'ID�Ŷ���ͷ���������ɹҽӴ��豸��ָ�Ӧͳһ
Const ADDR_AutoBarrier = &HC0                                    '�Զ���բ�����������ɹҽӴ��豸��ָ�Ӧͳһ
Const ADDR_IOModel = &HD0                                        'ͨ��IOģ�飬һ�������豸�����幫�õ�ָ�Ӧͳһ����Χ���ַԼͬ
Const ADDR_ParkingGuider = &HE0                                  'ͣ����������һ�������豸�����幫�õ�ָ�Ӧͳһ������������ʵʱ��λ����
Const ADDR_Other = &HF0                                          '�����豸

  '���Է��͵�ָ��
Const COMR_SoftReset = &H2                                       '������ʽ+1�ֽڲ���,����=1=�����λ
Const COMR_SetDateTime = &H3                                     'ʱ������+year,month,day,hour,minute,second,week
Const COMR_Beep = &H7                                            '��������+1�ֽڲ���,����Ϊ��������
'����Ϊ�ɹ㲥��ָ��
Const LEDR_Display = &H10                                        'ֱͨ��ʾָ��+
Const LEDR_StoreSentance = &H13                                  '������ʾָ��+
Const SMMR_LinkMode = &H20                                       '�����ѻ�����ģʽ+1�ֽڲ���,����=0/1=�ѻ�/����
Const SMMR_LoadCardsPrefix = &H21                                'װ�ػ�׷�ӿ�Ƭ����֪ͨ,����2�ֽ���ʼ���(0-65534)���ټ�2�ֽڿ�Ƭ��������(1-65535),���齫������Ƭһ������ȫ��װ��,���õĿ�Ƭ�ȼ���.�־���������1�ֽ����ţ�256��/1������,
Const SMMR_LoadOneCard = &H22                                    'װ�ػ�׷�ӿ�Ƭ����һ��,����2�ֽ����(0-65534)����Ƭ�������밴ID����������,װ�ؿ�Ƭ�ڼ�ϵͳֹͣ����.
Const SMMR_ModifyOneCard = &H23                                  '�޸Ŀ�Ƭ����һ��,���ڿ�Ƭ��ʧ/����/���ڵ�,�޸Ŀ�Ƭ�ڼ�ϵͳ��������.
Const SMMR_FetchCardsRequest = &H25                             '��ȡ��Ƭ��������
Const SMMR_ReceiveCardsResult = &H26                            '�տ�Ƭ����Ӧ��
Const SMMR_LoadTimeTable = &H27                                 '�����շ�ʱ�̱�
Const SMMR_LoadTollTable = &H28                                 '�����շѽ���
Const SMMR_LoadTotalPlace = &H29                                '���ظ������ܳ�λ����,����Ϊ����������[1](1-31)+1�ų����ܳ�λ��[2]+2�ų����ܳ�λ��[2]+...
Const SMMR_SetVacant = &H2A                                     '���ظ�����ʣ�೵λ����,����Ϊ��1�ų���ʣ�೵λ��[2]+2�ų���ʣ�೵λ��[2]+...
Const SMMR_WriteParameterTable = &H2B                           'д����ֲ����� 1�ֽڱ����+�������
Const SMMR_ReadParameterTable = &H2C                            '��ȡ���ֲ����� 1�ֽ���ʼ�����+1�ֽ���ֹ����š�
Const SMMR_Volume = &H2D                                        '����+1�ֽڲ���;0=�ر�;1=ԭʼ��������;2=X2�Ӵ�һ��;3=X4�ټӴ�һ����
Const SMMR_LoadAudioPrefix = &H2E                               'װ�ػ�׷����������֪ͨ,����2�ֽ���ʼ���(0-65534)���ټ�2�ֽڿ�Ƭ��������(1-65535),���齫������Ƭһ������ȫ��װ��,���õĿ�Ƭ�ȼ���.�־���������1�ֽ����ţ�256��/1������,
Const SMMR_LoadAudioBlock = &H2F                                'װ�ػ�׷���������ݿ�,����2�ֽ����ݿ����(0-65534)��200�ֽ�����,
Const SMMR_EventWait = &H30                                     '�ֳ��¼���Ϥ�ȴ���PC��������3������Ӧ���ݴ��ж��Ƿ�������
     Const PCWAT_Capture = 0                                    '�ȴ����ͼ��׽  '��Ч���ͱ����ڸ�ͤ�ڵ���ʾ������ʾ
     Const PCWAT_Compare = 1                                    '�ȴ�����ͼ��Ա�
     Const PCWAT_Toll = 2                                       '�ȴ������շ����
     Const PCWAT_CompareToll = 3                                '�ȴ�����ͼ��Աȼ��շ����
Const SMMR_EventValid = &H31                                    '�ֳ��¼�ȷ����Ч���˹�̧բ�¼���¼��Ч�����ͼ��׽�����ڶԱ����շ���Ч��
     Const PCVID_Capture = 0                                    '���ͼ��׽��Ч  '��Ч���ͱ����ڸ�ͤ�ڵ���ʾ������ʾ
     Const PCVID_Compare = 1                                    '����ͼ��Ա���Ч
     Const PCVID_ChangeOperater = 3                             '����Ա���������Ч
     Const PCVID_Toll = 4                                       '�����շ������Ч
     Const PCVID_CompareToll = 5                                '����ͼ��Աȼ��շ������Ч
     Const PCVID_Event = 6                                      '�¼���¼�����Ч
Const SMMR_EventInvalid = &H32                                  '�ֳ��¼�ȷ����Ч������ͼ��ԱȲ�����Ч��
     Const PCINV_Compare = 0                                    '����ͼ��Ա���Ч
Const SMMR_FetchEvent = &H33                                    '��ȡ�¼���¼����
Const SMMR_EventOk = &H34                                       '�����¼���¼Ӧ��
Const SMMR_EventPointerRequest = &H35                           '��ѯ�¼���¼ָ��(��һ����¼�����)
Const SMMR_SetEventPointer = &H36                               '�����¼���¼ָ��(��һ����¼�����),�¼���¼ָ��ı��,����ȡ����ָ��֮ǰ����ʷ�¼�,��ȡ�����������!!


Const PCMR_CardWait = &H60                                       '����������ȴ�ָ��+n�ֽڲ���
     '��һ����
     Const WAT_Reply = 0                                        '��ʾ:��ȴ�ȷ��
     Const WAT_Capture = 1                                      '��ʾ:��ͼ��׽
     Const WAT_Picture = 2                                      '��ʾ:��ͼ��Ա�
     Const WAT_Toll = 3                                         '��ʾ:��ʾ�շ���Ϣ
     '��ʾ�շ���Ϣ��������
     Const INF_Toll1 = 2                                        '����:moneyL moneyH  ��ʾ���շ�XXXXԪ
     Const INF_Toll2 = 8                                        '����:HourIn,MinuteIn,SecondIn,HourOut,MinuteOut,SecondOut,moneyL,moneyH��ʾXX:XX:XX��;XX:XX:XX��;�շ�XXXXԪ
     Const INF_Toll3 = 14                                       '����:YearIn,MonthIn,DayIn,HourIn,MinuteIn,SecondIn,YearOut,MonthOut,DayOut,HourOut,MinuteOut,SecondOut,moneyL,moneyH��ʾYY/MM/DD XX:XX:XX��;YY/MM/DD XX:XX:XX��;�շ�XXXXԪ
Const PCMR_CardValid = &H63                                     '����Чָ��+1�ֽڲ���
     Const VID_In = 0                                           '��ʾ:��ӭ������
     Const VID_Out = 1                                          '��ʾ:һ·ƽ����
     Const VID_CollectCard = 2                                  '��ʾ:��忨����
Const PCMR_CardInvalid = &H64                                   '����Чָ��+1�ֽڲ���
     Const INV_ReadCard = 0                                     '��ʾ:���ٶ�������������д��ʹ��
     Const INV_NotRegister = 1                                  '��ʾ:�˿�δ�Ǽ�
     Const INV_HaveIn = 2                                       '��ʾ:�˿����ڳ�
     Const INV_StillOut = 3                                     '��ʾ:�˿�δ����
     Const INV_CardLoss = 4                                     '��ʾ:�˿��ѹ�ʧ
     Const INV_CardLock = 5                                     '��ʾ:�˿�������
     Const INV_OverDate = 6                                     '��ʾ:�˿��ѹ���
     Const INV_NotPaid = 7                                      '��ʾ:�˿�δ����
     Const INV_OverTime = 8                                     '��ʾ:��ʱ������
     Const INV_Picture = 9                                      '��ʾ:ͼ�񲻷���
     Const INV_ParkFull = 10                                    '��ʾ:��λ������
Const PCMR_Information = &H67                                   '��ʾ+2�ֽڲ�����Ϣ
     Const INF_ValidDate = 0                                    'Month,day      ��ʾ��XX��XXֹЧ
     Const INF_RemainDay = 1                                    'dayL,dayH      ��ʾ������XXXX��
     Const INF_RemainMoney = 2                                  'RemainMoneyL,H ��ʾ����ֵXXXXԪ
     Const INF_ValidDate2 = 3                                   'year,month,day ��ʾ��XX-XX-XXֹ
Const ABMR_Operation = &HC0                                     '��բֱͨ����ָ��+2�ֽڲ���"ho"/"ca"/"nc""dw"/"st"=̧բ����/̧բ��������/̧բ����������/��բ/ͣբ
Const IOMR_SingleOutput = &HD0                                  '��������0x00=OFF,0x01=ON;0x02/3=TOGGLE;1�ֽ�ͨ����(�̵�����)0-255;1�ֽڹ�λʱ�����:0=���ֲ���λ,1-255=0.1-25.5sec;1�ֽڹ�λ������ʽ0x00=OFF=����/�ͷ�,0x01=ON=��һ/����,0x02=TOGGLE��ת����, 0x03=ѭ����ת
Const IOMR_BatchOutput = &HD1                                   '���������ֽ���n,n�ֽڶ�������,��Ӧ0��(nx8-1)�ż̵���,��ӦBIT=0=OFF,1=ON;1�ֽڹ�λʱ�����:0=���ֲ���λ,1=255=0.1-25.5sec;1�ֽڹ�λ������ʽ0x00=OFF=����/�ͷ�,0x01=ON=��һ/����,0x02=TOGGLE��ת����, 0x03=ѭ����ת
Const IOMR_SingleInput = &HD2                                   '+ͨ����0-255����ѯ��ͨ�������ƽ
Const IOMR_BatchInput = &HD3                                    '+ͨ����0-255����ѯ����ͨ�������ƽ
Const IOMR_SingleADC = &HD4                                     '+ͨ����0-255����ѯ��ͨ��ģ��ת�����
Const IOMR_BatchADC = &HD5                                      '+ͨ����0-255����ѯ����ͨ��ģ��ת�����
Const IOMR_SingleDAC = &HD6                                     '+ͨ����0-255�������ͨ����ģת����ѹ
Const IOMR_BatchDAC = &HD7                                      '+ͨ����0-255���������ͨ����ģת����ѹ
Const PGMR_SetPlace = &HE0                                       '��λ��Ϣָ��+������+�ܳ�λ��2byte+ʣ�೵λ��2�ֽ� �ܳ�λ������=0
Const CPMR_Lock = &HA0                                      '���ط����� 0xA0
Const CPMR_Cardout = &HA1                                   '0xA1����������ָ��

 ' ���Խ��յ�ָ��
Const COMT_ResetOk = &H1                                         '���߱���+1�ֽڲ���,����=1=�ϵ����߸�λOK
Const VDMT_VDCar = &H98                                          '���������ָ��+1�ֽڲ���,����=0/1=����/����
Const CPMT_CardButt = &HA8                                       '��ȡ����ť
Const CPMT_CardOut = &HA9                                        '����������һ�ſ�
Const CPMT_CardIn = &HAA                                         '�տ����տ�һ�ſ�
Const CPMT_CardNone = &HAB                                       '�������޿�
Const CPMT_CardFew = &HAC                                        '������ȱ��
Const CPMT_CardLoad = &HAD                                       '������װ��
Const CPMT_CardAdd = &HAE                                        '��������
Const CPMT_CardJam = &HAF                                        '����������
Const RWMT_CardID = &HB8                                         '�ϴ�����+CardKind+4bytesID; +0-nbytesData�ı�������ȷ�ʽ���������ݡ�
     '��CardKind�����غ�00-0FΪ��������10-1FΪ��ͨ�����ڼƷѿ۷�
     Const CARD_Local = &H0                                           '������
     Const CARD_Mifare = &H1                                          'Mifare
     Const CARD_Legic = &H2                                           'LEGIC
     Const CARD_Ti = &H3                                              'Ti
     Const CARD_Wg26 = &H4                                            '�޷�ȷ����WG26��(EM��/΢����)
     Const CARD_Wg34 = &H5                                            '�޷�ȷ����WG34��(EM��/΢����
     Const CARD_EM = &H6                                              'EM
     Const CARD_Motorola = &H7                                        'Motorola
     Const CARD_HID = &H8                                             'HID

     Const CARD_Public = &H10                                         '��ͨ��
     Const CARD_SZT = &H11                                            '����ͨ
     Const CARD_YCT = &H12                                            '���ͨ
     'ָ����Դ����,ͣ���������������Ҷ�ͷ��ʶ���Ա��ж�̨ʽ��д��
     Const ADDR_Mifare = &HB1                                         'Mifare��ͷ
     Const ADDR_Reader232 = &HB2                                      '232LEGIC/485���ͨ/TiRFM001
     Const ADDR_Wg1 = &HB3                                            'wg1ID��ͷ
     Const ADDR_Wg2 = &HB4                                            'wg2ID��ͷ
     Const ADDR_Wg3 = &HB5                                            'wg3ID��ͷ


Const CONCardRecordMax = 4096                       '����װ�ؿ�Ƭ����
Const LEDR_Append = &H11                            '��������ָ������ظ�  // disp immediately current input
Const LEDR_LoopStart = &H12                         '��������ָ������ظ�  // set loop disp start point or End loop disp
Const LEDR_StoreSentence = &H13                     '0-255  sentence addr
Const LEDR_StoreLoopSentence = &H14                 '0-255  sentence addr
Const LEDR_SelectSentence = &H15                    '0-255  sentence addr
Const LEDR_DispMode = &H16                          'disp mode 00-99
Const LEDR_SetStayTime = &H17                       '0-255  Sec
'---------------------------------�ڲ���ʾ���Ʒ�--------------------------------------------------------------------------------
Const LEDD_LF = &H13                                'shift_up a new line
Const LEDD_CR = &H14                                'restart a new line



Private Sub DataEdit_Click()
Load SystemSet
SystemSet.Show
End Sub

Private Sub Form_Load()
'ChDir App.Path    'Change the working directory to the application located path.
'ChDrive App.Path


MSComm1.RThreshold = 1
ReceCommandByteCount = 0
RxText = "����ָ��ԭ�루˫��������������" + vbCrLf


Option2(1).Value = True
Option1(0).Value = True
RelayNum = 0
CardWait = 0
CardValid = 0
CardInvalid = 0
LinkMode1 = 1
Volume = 0
VehicleType = 0
End Sub
Private Sub MainForm_Unload()
Workspaces(0).Close
End Sub

Private Sub MSComm1_OnComm()
On Error GoTo ErrorHandler
Dim a, b, c, crc As Byte
Dim RxDa() As Byte
Dim DataRommandNew As Recordset
Retry:
Select Case MSComm1.CommEvent
                     ' Errors
Case comBreak:     Text4.Text = "A Break was received."
Case comCDTO:      Text4.Text = "CD (RLSD) Timeout."
Case comCTSTO:     Text4.Text = "CTS Timeout."
Case comDSRTO:     Text4.Text = "DSR Timeout."
Case comFrame:     Text4.Text = "Framing Error"
Case comOverrun:   Text4.Text = "Data Lost."
Case comRxOver:    Text4.Text = "Receive buffer overflow."
Case comRxParity:  Text4.Text = "Parity Error."
Case comTxFull:    Text4.Text = "Transmit buffer full."
                     ' Events
Case comEvCD:      Text4.Text = "Change in the CD line."
Case comEvCTS:     Text4.Text = "Change in the CTS line."
Case comEvDSR:     Text4.Text = "Change in the DSR line."
Case comEvRing:    Text4.Text = "Change in the Ring Indicator."
Case comEvSend:    Text4.Text = "There are SThreshold number of characters in the transmit buffer."
Case comEvReceive: 'Text4.Text = "Received RThreshold # of chars."
Receive:
  If MSComm1.RThreshold = 1 Then
     MSComm1.InputLen = 1
     RxDa = MSComm1.Input
     RxData(RxCommByteCount) = RxDa(0)
     c = RxData(RxCommByteCount)
     RxCommByteCount = RxCommByteCount + 1
     Select Case RxCommByteCount
     Case 1:
          If c <> CONCommSyn1 Then
             RxCommByteCount = 0
          End If
     Case 2:
          If c <> CONCommSyn2 Then
             RxCommByteCount = 0
          End If
     Case 3:
          If c <> CONCommSyn3 Then
             RxCommByteCount = 0
          End If
     Case 4: '�����豸��ַ
     Case 5: '�����豸��ַ
     Case 6: '�豸ָ��
     Case 7: '��������
             MSComm1.RThreshold = c + 1  '��������+CRC
     Case 8: GoTo ReceiveComplted        '����������Ϊ0ʱ
     End Select
     If Len(Hex(c)) = 1 Then
         RxText = RxText + "0" + Hex(c) + " "
     Else
         RxText = RxText + Hex(c) + " "
     End If
  Else
     MSComm1.InputLen = MSComm1.RThreshold
     RxDa = MSComm1.Input
     a = MSComm1.RThreshold - 1
     For c = 0 To a
       RxData(RxCommByteCount) = RxDa(c)
       RxCommByteCount = RxCommByteCount + 1
     Next c
ReceiveComplted:
     s = ""
     For c = 0 To RxData(6) + 8 - 1           'ͷ7byte+crc=8byte,-1��Ŵ�����
         If Len(Hex(RxData(c))) = 1 Then
            s = s + "0" + Hex(RxData(c)) + " "
         Else
            s = s + Hex(RxData(c)) + " "
         End If
     Next c
     crc = 0
     For c = 3 To RxData(6) + 8 - 1 - 1       'ͷ7byte+crc=8byte,-1��Ŵ�����-1����CRC
         crc = crc Xor RxData(c)
     Next c
     If crc = RxData(RxData(6) + 7) Then
        RxText = RxText + Mid(s, 22) + vbCrLf
       ' RxText = Mid(s, 22) + vbCrLf
        Text1(0).Text = Mid(s, 1, 9)
        Text1(4).Text = Mid(s, 19, 2)
        Text1(5).Text = Mid(s, 22, Len(s) - 21 - 3)
        Text1(6).Text = Mid(s, Len(s) - 2, 2)
        
     Else
        RxText = RxText + Mid(s, 22) + "CRC_Error!" + vbCrLf
      '  RxText = Mid(s, 22) + "CRC_Error!" + vbCrLf
     End If
     MSComm1.RThreshold = 1
     RxCommByteCount = 0
     If Len(RxText) > 2500 Then
        RxText = Mid(RxText, Len(RxText) - 2500)
     End If
  End If
  Text4.Text = RxText
  If (MSComm1.InBufferCount >= MSComm1.RThreshold) Then
      GoTo Receive
  End If
End Select
If Len(RxText) > 2600 Then
   MSComm1.PortOpen = False
End If
Exit Sub
ErrorHandler:
WhaToDo% = MsgBox("Error" & Err.Number & Err.Description & " occurred", vbRetryCancel)
If WhaToDo% = vbRetry Then Resume

End Sub

Private Sub option1_Click(Index As Integer)
I = MSComm1.CommPort
On Error GoTo CommErrorHandler
If MSComm1.PortOpen = True Then
   MSComm1.PortOpen = False
End If
MSComm1.CommPort = Index + 1

MSComm1.PortOpen = True
If Option2(0).Value = True Then
   MSComm1.Settings = "2400,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(Index + 1) + ",����:2400,N,8,1"
ElseIf Option2(1).Value = True Then
   MSComm1.Settings = "9600,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(Index + 1) + ",����:9600,N,8,1"
ElseIf Option2(2).Value = True Then
   MSComm1.Settings = "19200,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(Index + 1) + ",����:19200,N,8,1"
ElseIf Option2(3).Value = True Then
   MSComm1.Settings = "57600,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(Index + 1) + ",����:57600,N,8,1"
End If
MSComm1.InputMode = comInputModeBinary
MSComm1.RThreshold = 1
Exit Sub
CommErrorHandler:
Select Case Err.Number
Case 8000: Text = "Operation not valid while the port is opened"
Case 8001: Text = "Timeout value must be greater than zero"
Case 8002: Text = "Invalid Port Number ��Ч�Ĵ��ںţ�"
Case 8003: Text = "Property available only at run time"
Case 8004: Text = "Property is read only at runtime"
Case 8005: Text = "Port already open"
Case 8006: Text = "The device identifier is invalid or unsupported"
Case 8007: Text = "The Device 's baud rate is unsupported"
Case 8008: Text = "The specified byte size is invalid"
Case 8009: Text = "The default parameters are in error"
Case 8010: Text = "The hardware is not available (locked by another device)"
Case 8011: Text = "The function cannot allocate the queues"
Case 8012: Text = "The device is not open"
Case 8013: Text = "The device is already open "
Case 8014: Text = "Could not enable comm notification"
Case 8015: Text = "Could not set comm state"
Case 8016: Text = "Could not set comm event mask"
Case 8018: Text = "Operation valid only when the port is open"
Case 8019: Text = "Device busy"
Case 8020: Text = "Error reading comm device"
Case Else: Text = "���ڳ���������ѡ��"
End Select
WhaToDo% = MsgBox(Text, vbRetryCancel)
If WhaToDo% = vbRetry Then Resume

hu:
MSComm1.CommPort = I
MSComm1.PortOpen = True
Option1(Index).Value = False
Option1(I - 1).Value = True

End Sub
Private Sub Option2_Click(Index As Integer)
Select Case Index
Case 0:
   MSComm1.Settings = "2400,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(MSComm1.CommPort) + ",����:2400,N,8,1"
Case 1:
   MSComm1.Settings = "9600,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(MSComm1.CommPort) + ",����:9600,N,8,1"
Case 2:
   MSComm1.Settings = "19200,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(MSComm1.CommPort) + ",����:19200,N,8,1"
Case 3:
   MSComm1.Settings = "38400,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(MSComm1.CommPort) + ",����:38400,N,8,1"
Case 4:
   MSComm1.Settings = "57600,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(MSComm1.CommPort) + ",����:57600,N,8,1"
Case 5:
   MSComm1.Settings = "115200,n,8,1"
   Text4.Text = "ѡ�񴮿�" + Str(MSComm1.CommPort) + ",����:115200,N,8,1"
End Select
End Sub

Private Sub Timer1_Timer()
Label3(0).Caption = Format(Now, "yyyy-mm-dd")
Label3(1).Caption = Format(Now, "hh:mm:ss")
End Sub
Private Sub Text4_DblClick()
Text4.Text = "����ָ��ԭ�루˫��������������" + vbCrLf
RxText = "����ָ��ԭ�루˫��������������" + vbCrLf
If MSComm1.PortOpen = False Then MSComm1.PortOpen = True
End Sub

Private Sub Tran1_Click(Index As Integer)
Dim OutData() As Byte
Dim Data(256) As Byte
Dim RecordTotal As Integer
Dim RecordCount As Integer
Dim DataLen As Long
Const CONFirstLoadCardNum = 100  '<256
If MSComm1.PortOpen = False Then MSComm1.PortOpen = True
   

Select Case Index
Case 0                                          '���ؿ�Ƭ����ָ֪ͨ��
     l = 11                                     '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                   '������ַ
     OutData(4) = TYPE_Itself                   '����
     OutData(5) = SMMR_LoadCardsPrefix          '���ؿ�Ƭ����ָ֪ͨ��
     OutData(6) = 4                             '��������
     If DataCards.Recordset.RecordCount = 0 Then
        MsgBox "��ǰ��Ƭ������������,�����������!"
       ' DataCards.Recordset.AddNew
        Exit Sub
     Else
        DataCards.Recordset.MoveLast
        DataCards.Recordset.MoveFirst
     End If
     If DataCards.Recordset.RecordCount > CONCardRecordMax Then
        MsgBox "��ǰ��Ƭ�������¼����������" + Str(CONCardRecordMax) + "��,���ȴ�������!"
        Exit Sub
     End If
     RecordTotal = DataCards.Recordset.RecordCount
     If RecordTotal > CONFirstLoadCardNum Then
        RecordTotal = CONFirstLoadCardNum
     End If
     OutData(7) = 0                             '׼�����ؼ�¼��ʼ���(0-65534)��λ�ֽ�
     OutData(8) = 0                             '׼�����ؼ�¼��ʼ��Ÿ�λ�ֽ�
     OutData(9) = RecordTotal Mod 256           '׼�����ؼ�¼����(1-65535)��λ�ֽ�
     OutData(10) = RecordTotal \ 256             '׼�����ؼ�¼������¼��λ�ֽ�
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     '-------------------------------------------------------------------------------------------------------------------------
     l = 49                                     '=���Ԫ�����
     ReDim OutData(l)
     DataCards.Recordset.MoveFirst              '�������Ϊdata3ʱ��֧��
NextCardRecord:
         OutData(0) = CONCommSyn1
         OutData(1) = CONCommSyn2
         OutData(2) = CONCommSyn3
         OutData(3) = Val(Text2.Text)               '������ַ
         OutData(4) = TYPE_Itself               '����
         OutData(5) = SMMR_LoadOneCard          '���ؿ�Ƭ����һ��
         OutData(6) = 42                        '��������,��������CRC
         OutData(7) = DataCards.Recordset.AbsolutePosition Mod 256      '��Ƭ�������(0-65534)��λ�ֽ�
         OutData(8) = DataCards.Recordset.AbsolutePosition \ 256        '��Ƭ�������(0-65534)��λ�ֽ�
         s = DataCards.Recordset.Fields("��Ƭ����").Value
         OutData(9) = Val("&H" + Mid(s, 7, 2))
         OutData(10) = Val("&H" + Mid(s, 5, 2))
         OutData(11) = Val("&H" + Mid(s, 3, 2))
         OutData(12) = Val("&H" + Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("ע���־").Value
         OutData(13) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(13) = OutData(13) + 2 ^ (8 - m)
            End If
         Next m
         OutData(14) = DataCards.Recordset.Fields("��Ƭ����").Value
         s = DataCards.Recordset.Fields("ֹЧ����").Value
         OutData(15) = Val(Mid(s, 5, 2))
         OutData(16) = Val(Mid(s, 3, 2))
         OutData(17) = Val(Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("�볡Ȩ��").Value
         OutData(18) = 0
         For m = 1 To 8
            If Mid(s, 24 + m, 1) = "1" Then                             '���ϵ��ֽ���ǰ��ʽ�����λ����0��ͣ����
               OutData(18) = OutData(18) + 2 ^ (8 - m)
            End If
         Next m
         OutData(19) = 0
         For m = 1 To 8
            If Mid(s, 16 + m, 1) = "1" Then
               OutData(19) = OutData(19) + 2 ^ (8 - m)
            End If
         Next m
         OutData(20) = 0
         For m = 1 To 8
            If Mid(s, 8 + m, 1) = "1" Then
               OutData(20) = OutData(20) + 2 ^ (8 - m)
            End If
         Next m
         OutData(21) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(21) = OutData(21) + 2 ^ (8 - m)
            End If
         Next m
         s = DataCards.Recordset.Fields("��Ƭ���").Value
         I = Val(s) Mod 65536
         OutData(22) = I Mod 256                                        '��Ƭ���(0-65535)��λ�ֽ�
         OutData(23) = I \ 256                                          '��Ƭ���(0-65535)��λ�ֽ�
         s = DataCards.Recordset.Fields("�����ʺ�").Value
         OutData(24) = Asc(Mid(s, 1, 1))
         OutData(25) = Asc(Mid(s, 2, 1))
         OutData(26) = Asc(Mid(s, 3, 1))
         OutData(27) = Asc(Mid(s, 4, 1))
         OutData(28) = Asc(Mid(s, 5, 1))
         OutData(29) = Asc(Mid(s, 6, 1))
         OutData(30) = Asc(Mid(s, 7, 1))
         OutData(31) = Asc(Mid(s, 8, 1))
         OutData(32) = Asc(Mid(s, 9, 1))
         OutData(33) = Asc(Mid(s, 10, 1))
         s = Hex(DataCards.Recordset.Fields("��ֵ���").Value)
         m = Len(s)
         If m >= 2 Then
            OutData(34) = Val("&H" + Mid(s, m - 1, 2))
         Else
            OutData(34) = Val("&H" + s)
         End If
         If m >= 4 Then
            OutData(35) = Val("&H" + Mid(s, m - 3, 2))
         Else
            If m = 3 Then
                OutData(35) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(35) = 0
            End If
         End If
         If m >= 6 Then
            OutData(36) = Val("&H" + Mid(s, m - 5, 2))
         Else
            If m = 5 Then
                OutData(36) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(36) = 0
            End If
         End If
         If m >= 8 Then
            OutData(37) = Val("&H" + Mid(s, m - 5, 2))
         Else
            If m = 7 Then
                OutData(37) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(37) = 0
            End If
         End If
         s = DataCards.Recordset.Fields("ͣ����־").Value
         OutData(38) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(38) = OutData(38) + 2 ^ (8 - m)
            End If
         Next m
         s = DataCards.Recordset.Fields("����ʱ��").Value
         OutData(39) = Val(Mid(s, 11, 2))
         OutData(40) = Val(Mid(s, 9, 2))
         OutData(41) = Val(Mid(s, 7, 2))
         OutData(42) = Val(Mid(s, 5, 2))
         OutData(43) = Val(Mid(s, 3, 2))
         OutData(44) = Val(Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("ͣ��λ��").Value
         OutData(45) = Asc(Mid(s, 1, 1))
         OutData(46) = Asc(Mid(s, 2, 1))
         OutData(47) = Asc(Mid(s, 3, 1))
         OutData(48) = Asc(Mid(s, 4, 1))
         OutData(l) = 0
          For I = 3 To l - 1
         OutData(l) = OutData(l) Xor OutData(I)
         Next I
         MSComm1.Output = OutData
         DataCards.Recordset.MoveNext
     If DataCards.Recordset.AbsolutePosition < RecordTotal Then GoTo NextCardRecord
Case 1                                          '׷�����ؿ�Ƭ����֪ͨ
     l = 11                                     '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                   '������ַ
     OutData(4) = TYPE_Itself                   '����
     OutData(5) = SMMR_LoadCardsPrefix          '���ؿ�Ƭ����ָ֪ͨ��
     OutData(6) = 4                             '��������
     If DataCards.Recordset.RecordCount = 0 Then
        MsgBox "��ǰ��Ƭ������������,�����������!"
       ' DataCards.Recordset.AddNew
        Exit Sub
     Else
        DataCards.Recordset.MoveLast
        DataCards.Recordset.MoveFirst
     End If
     If DataCards.Recordset.RecordCount > CONCardRecordMax Then
        MsgBox "��ǰ��Ƭ�������¼����������" + Str(CONCardRecordMax) + "��,���ȴ�������!"
        Exit Sub
     End If
     RecordTotal = DataCards.Recordset.RecordCount
     If RecordTotal <= CONFirstLoadCardNum Then
        MsgBox "��ǰ��Ƭ�������¼��ȫ�������ˣ���׷�Ӽ�¼��"
        Exit Sub
     End If
     OutData(7) = CONFirstLoadCardNum Mod 256   '׼�����ؼ�¼��ʼ���(0-65534)��λ�ֽ�
     OutData(8) = CONFirstLoadCardNum \ 256     '׼�����ؼ�¼��ʼ��Ÿ�λ�ֽ�
     OutData(9) = RecordTotal Mod 256           '׼�����ؼ�¼����(1-65535)��λ�ֽ�
     OutData(10) = RecordTotal \ 256            '׼�����ؼ�¼������¼��λ�ֽ�
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     '-------------------------------------------------------------------------------------------------------------------------
     l = 49                                     '=���Ԫ�����
     ReDim OutData(l)
     DataCards.Recordset.MoveFirst              '�������Ϊdata3ʱ��֧��
NextCardRecord1:
     DataCards.Recordset.MoveNext
     If DataCards.Recordset.AbsolutePosition < CONFirstLoadCardNum Then GoTo NextCardRecord1
NextCardRecord2:
         OutData(0) = CONCommSyn1
         OutData(1) = CONCommSyn2
         OutData(2) = CONCommSyn3
         OutData(3) = Val(Text2.Text)               '������ַ
         OutData(4) = TYPE_Itself               '����
         OutData(5) = SMMR_LoadOneCard          '���ؿ�Ƭ����һ��
         OutData(6) = 42                        '��������,��������CRC
         OutData(7) = DataCards.Recordset.AbsolutePosition Mod 256     '��Ƭ�������(0-65534)��λ�ֽ�
         OutData(8) = DataCards.Recordset.AbsolutePosition \ 256        '��Ƭ�������(0-65534)��λ�ֽ�
         s = DataCards.Recordset.Fields("��Ƭ����").Value
         OutData(9) = Val("&H" + Mid(s, 7, 2))
         OutData(10) = Val("&H" + Mid(s, 5, 2))
         OutData(11) = Val("&H" + Mid(s, 3, 2))
         OutData(12) = Val("&H" + Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("ע���־").Value
         OutData(13) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(13) = OutData(13) + 2 ^ (8 - m)
            End If
         Next m
         OutData(14) = DataCards.Recordset.Fields("��Ƭ����").Value
         s = DataCards.Recordset.Fields("ֹЧ����").Value
         OutData(15) = Val(Mid(s, 5, 2))
         OutData(16) = Val(Mid(s, 3, 2))
         OutData(17) = Val(Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("�볡Ȩ��").Value
         OutData(18) = 0
         For m = 1 To 8
            If Mid(s, 24 + m, 1) = "1" Then                             '���ϵ��ֽ���ǰ��ʽ�����λ����0��ͣ����
               OutData(18) = OutData(18) + 2 ^ (8 - m)
            End If
         Next m
         OutData(19) = 0
         For m = 1 To 8
            If Mid(s, 16 + m, 1) = "1" Then
               OutData(19) = OutData(19) + 2 ^ (8 - m)
            End If
         Next m
         OutData(20) = 0
         For m = 1 To 8
            If Mid(s, 8 + m, 1) = "1" Then
               OutData(20) = OutData(20) + 2 ^ (8 - m)
            End If
         Next m
         OutData(21) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(21) = OutData(21) + 2 ^ (8 - m)
            End If
         Next m
         s = DataCards.Recordset.Fields("��Ƭ���").Value
         I = Val(s) Mod 65536
         OutData(22) = I Mod 256                                        '��Ƭ���(0-65535)��λ�ֽ�
         OutData(23) = I \ 256                                          '��Ƭ���(0-65535)��λ�ֽ�
         s = DataCards.Recordset.Fields("�����ʺ�").Value
         OutData(24) = Asc(Mid(s, 1, 1))
         OutData(25) = Asc(Mid(s, 2, 1))
         OutData(26) = Asc(Mid(s, 3, 1))
         OutData(27) = Asc(Mid(s, 4, 1))
         OutData(28) = Asc(Mid(s, 5, 1))
         OutData(29) = Asc(Mid(s, 6, 1))
         OutData(30) = Asc(Mid(s, 7, 1))
         OutData(31) = Asc(Mid(s, 8, 1))
         OutData(32) = Asc(Mid(s, 9, 1))
         OutData(33) = Asc(Mid(s, 10, 1))
         s = Hex(DataCards.Recordset.Fields("��ֵ���").Value)
         m = Len(s)
         If m >= 2 Then
            OutData(34) = Val("&H" + Mid(s, m - 1, 2))
         Else
            OutData(34) = Val("&H" + s)
         End If
         If m >= 4 Then
            OutData(35) = Val("&H" + Mid(s, m - 3, 2))
         Else
            If m = 3 Then
                OutData(35) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(35) = 0
            End If
         End If
         If m >= 6 Then
            OutData(36) = Val("&H" + Mid(s, m - 5, 2))
         Else
            If m = 5 Then
                OutData(36) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(36) = 0
            End If
         End If
         If m >= 8 Then
            OutData(37) = Val("&H" + Mid(s, m - 5, 2))
         Else
            If m = 7 Then
                OutData(37) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(37) = 0
            End If
         End If
         s = DataCards.Recordset.Fields("ͣ����־").Value
         OutData(38) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(38) = OutData(38) + 2 ^ (8 - m)
            End If
         Next m
         s = DataCards.Recordset.Fields("����ʱ��").Value
         OutData(39) = Val(Mid(s, 11, 2))
         OutData(40) = Val(Mid(s, 9, 2))
         OutData(41) = Val(Mid(s, 7, 2))
         OutData(42) = Val(Mid(s, 5, 2))
         OutData(43) = Val(Mid(s, 3, 2))
         OutData(44) = Val(Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("ͣ��λ��").Value
         OutData(45) = Asc(Mid(s, 1, 1))
         OutData(46) = Asc(Mid(s, 2, 1))
         OutData(47) = Asc(Mid(s, 3, 1))
         OutData(48) = Asc(Mid(s, 4, 1))
         OutData(l) = 0
          For I = 3 To l - 1
         OutData(l) = OutData(l) Xor OutData(I)
         Next I
         MSComm1.Output = OutData
         DataCards.Recordset.MoveNext
     If DataCards.Recordset.EOF = False Then GoTo NextCardRecord2
Case 2                                          '�޸Ŀ�Ƭ����һ��,
     '-------------------------------------------------------------------------------------------------------------------------
     l = 49                                     '=���Ԫ�����
     ReDim OutData(l)
     DataCards.Recordset.MoveFirst              '�������Ϊdata3ʱ��֧��
     DataCards.Recordset.MoveNext
     DataCards.Recordset.MoveNext
     DataCards.Recordset.MoveNext
         OutData(0) = CONCommSyn1
         OutData(1) = CONCommSyn2
         OutData(2) = CONCommSyn3
         OutData(3) = Val(Text2.Text)               '������ַ
         OutData(4) = TYPE_Itself               '����
         OutData(5) = SMMR_ModifyOneCard        '�޸Ŀ�Ƭ����һ��
         OutData(6) = 42                        '��������,��������CRC
         OutData(7) = DataCards.Recordset.AbsolutePosition Mod 256      '��Ƭ�������(0-65534)��λ�ֽ�
         OutData(8) = DataCards.Recordset.AbsolutePosition \ 256        '��Ƭ�������(0-65534)��λ�ֽ�
         s = DataCards.Recordset.Fields("��Ƭ����").Value
         OutData(9) = Val("&H" + Mid(s, 7, 2))
         OutData(10) = Val("&H" + Mid(s, 5, 2))
         OutData(11) = Val("&H" + Mid(s, 3, 2))
         OutData(12) = Val("&H" + Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("ע���־").Value
         OutData(13) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(13) = OutData(13) + 2 ^ (8 - m)
            End If
         Next m
         OutData(14) = DataCards.Recordset.Fields("��Ƭ����").Value
         s = DataCards.Recordset.Fields("ֹЧ����").Value
         OutData(15) = Val(Mid(s, 5, 2))
         OutData(16) = Val(Mid(s, 3, 2))
         OutData(17) = Val(Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("�볡Ȩ��").Value
         OutData(18) = 0
         For m = 1 To 8
            If Mid(s, 24 + m, 1) = "1" Then                             '���ϵ��ֽ���ǰ��ʽ�����λ����0��ͣ����
               OutData(18) = OutData(18) + 2 ^ (8 - m)
            End If
         Next m
         OutData(19) = 0
         For m = 1 To 8
            If Mid(s, 16 + m, 1) = "1" Then
               OutData(19) = OutData(19) + 2 ^ (8 - m)
            End If
         Next m
         OutData(20) = 0
         For m = 1 To 8
            If Mid(s, 8 + m, 1) = "1" Then
               OutData(20) = OutData(20) + 2 ^ (8 - m)
            End If
         Next m
         OutData(21) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(21) = OutData(21) + 2 ^ (8 - m)
            End If
         Next m
         s = DataCards.Recordset.Fields("��Ƭ���").Value
         I = Val(s) Mod 65536
         OutData(22) = I Mod 256                                        '��Ƭ���(0-65535)��λ�ֽ�
         OutData(23) = I \ 256                                          '��Ƭ���(0-65535)��λ�ֽ�
         s = DataCards.Recordset.Fields("�����ʺ�").Value
         OutData(24) = Asc(Mid(s, 1, 1))
         OutData(25) = Asc(Mid(s, 2, 1))
         OutData(26) = Asc(Mid(s, 3, 1))
         OutData(27) = Asc(Mid(s, 4, 1))
         OutData(28) = Asc(Mid(s, 5, 1))
         OutData(29) = Asc(Mid(s, 6, 1))
         OutData(30) = Asc(Mid(s, 7, 1))
         OutData(31) = Asc(Mid(s, 8, 1))
         OutData(32) = Asc(Mid(s, 9, 1))
         OutData(33) = Asc(Mid(s, 10, 1))
         s = Hex(DataCards.Recordset.Fields("��ֵ���").Value)
         m = Len(s)
         If m >= 2 Then
            OutData(34) = Val("&H" + Mid(s, m - 1, 2))
         Else
            OutData(34) = Val("&H" + s)
         End If
         If m >= 4 Then
            OutData(35) = Val("&H" + Mid(s, m - 3, 2))
         Else
            If m = 3 Then
                OutData(35) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(35) = 0
            End If
         End If
         If m >= 6 Then
            OutData(36) = Val("&H" + Mid(s, m - 5, 2))
         Else
            If m = 5 Then
                OutData(36) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(36) = 0
            End If
         End If
         If m >= 8 Then
            OutData(37) = Val("&H" + Mid(s, m - 5, 2))
         Else
            If m = 7 Then
                OutData(37) = Val("&H" + Mid(s, 1, 1))
            Else
                OutData(37) = 0
            End If
         End If
         s = DataCards.Recordset.Fields("ͣ����־").Value
         OutData(38) = 0
         For m = 1 To 8
            If Mid(s, m, 1) = "1" Then
               OutData(38) = OutData(38) + 2 ^ (8 - m)
            End If
         Next m
         s = DataCards.Recordset.Fields("����ʱ��").Value
         OutData(39) = Val(Mid(s, 11, 2))
         OutData(40) = Val(Mid(s, 9, 2))
         OutData(41) = Val(Mid(s, 7, 2))
         OutData(42) = Val(Mid(s, 5, 2))
         OutData(43) = Val(Mid(s, 3, 2))
         OutData(44) = Val(Mid(s, 1, 2))
         s = DataCards.Recordset.Fields("ͣ��λ��").Value
         OutData(45) = Asc(Mid(s, 1, 1))
         OutData(46) = Asc(Mid(s, 2, 1))
         OutData(47) = Asc(Mid(s, 3, 1))
         OutData(48) = Asc(Mid(s, 4, 1))
         OutData(l) = 0
          For I = 3 To l - 1
         OutData(l) = OutData(l) Xor OutData(I)
         Next I
         MSComm1.Output = OutData
Case 3                                      '��ȡ��Ƭ��������
     l = 7                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)        '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = SMMR_FetchCardsRequest    '��ȡ������Ƭ��������
     OutData(6) = 0                         '��������
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 9                                          '�Զ�ģʽ
     l = 8                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = 7 'ADDR_Myself                   'RS232������ַ
     OutData(4) = TYPE_Itself                   '���ձ���
     OutData(5) = SMMR_LinkMode                 'ģʽ�л�����/�ѻ�
     OutData(6) = 1                             '��������
     OutData(7) = 0                             '�Զ�ģʽ
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 10                                         '����ģʽ
     l = 8                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself                   'RS232������ַ
     OutData(4) = TYPE_Itself                   '���ձ���
     OutData(5) = SMMR_LinkMode                 'ģʽ�л�����/�ѻ�
     OutData(6) = 1                             '��������
     OutData(7) = 3                             '4=����ģʽ 3=ʵʱģʽ
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData


Case 11                                         '��������
     l = 8                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                   'RS232������ַ
     OutData(4) = TYPE_Itself                   '���ձ���
     OutData(5) = COMR_SoftReset
     OutData(6) = 1                             '��������
     OutData(7) = 1                             '����
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 12                                         '���߲�ѯ
     l = 8                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself                 '0�����ͨ��������
     OutData(4) = TYPE_Itself                   '���ձ���
     OutData(5) = COMR_SoftReset
     OutData(6) = 1                             '��������
     OutData(7) = 5                            '��2��
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 14                                         '���߹㲥��λ
     l = 8                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Broadcast                'CAN���߹㲥��ַ
     OutData(4) = TYPE_Itself                   '����
     OutData(5) = COMR_SoftReset
     OutData(6) = 1                             '��������
     OutData(7) = 1                             '����
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 15                                         '����ֱͨ��ʾ:Hellow hyn
     l = 17                                      '=���Ԫ�����
     S1 = Text3.Text
     l1 = 0
     For I = 1 To Len(S1)
       s = Mid(S1, I, 1)
       If (s > Chr(127)) Then
           l1 = l1 + 2
       Else
           l1 = l1 + 1
       End If
     Next I
     l = l1 + 7
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = 97 'ADDR_Broadcast                'CAN���߹㲥��ַ
'     OutData(4) = TYPE_Itself                   '����
     OutData(4) = 0 'ADDR_LedScreen
'     OutData(4) = TYPE_Itself                   '����
     OutData(5) = LEDR_Display
     OutData(6) = l1                            '��������
     k = 7
     For I = 1 To Len(S1)
       s = Mid(S1, I, 1)
       If (s > Chr(127)) Then
          OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 1, 2))
          k = k + 1
          OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 3, 2))
       Else
          OutData(k) = Asc(s)
       End If
          k = k + 1
     Next I
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

Case 16                                         '������ʾ:
     S1 = Text3.Text
     l1 = 0
     For I = 1 To Len(S1)
       s = Mid(S1, I, 1)
       If (s > Chr(127)) Then
           l1 = l1 + 2
       Else
           l1 = l1 + 1
       End If
     Next I
     l = l1 + 7 + 1
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Broadcast                'CAN���߹㲥��ַ
'     OutData(4) = TYPE_Itself                   '����
     OutData(4) = ADDR_LedScreen
'     OutData(4) = TYPE_Itself                   '����
     OutData(5) = LEDR_StoreSentance
     OutData(6) = l1 + 1                        '��������
     OutData(7) = 0                             '��������
     k = 8
     For I = 1 To Len(S1)
       s = Mid(S1, I, 1)
       If (s > Chr(127)) Then
          OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 1, 2))
          k = k + 1
          OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 3, 2))
       Else
          OutData(k) = Asc(s)
       End If
          k = k + 1
     Next I
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

Case 17                                         'ʱ������
     l = 15                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text) 'ADDR_Broadcast '   '����ͨ��������
     OutData(4) = TYPE_Itself  'ADDR_Broadcast '   '����
     OutData(5) = COMR_SetDateTime
     OutData(6) = 8                             '��������
     t = Now
     OutData(7) = Second(t)
     OutData(8) = Minute(t)
     OutData(9) = Hour(t)
     OutData(10) = Day(t)
     OutData(11) = Month(t)
     OutData(12) = Year(t) - 2000
     OutData(13) = Weekday(t)                '1~7=������~��
     OutData(14) = 2                    '��ʾģʽ1=���Ĺ���ʱ�䣬2=ֻ��ʱ�䣬3=Ӣ������ʱ�䣬4=��������ʱ�䣬5=��Ӣ������ʱ��
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 18                                         '��淢�� ������ʾ:
     S1 = Text3.Text
     l1 = 0
     For I = 1 To Len(S1)
       s = Mid(S1, I, 1)
       If (s > Chr(127)) Then
           l1 = l1 + 2
       Else
           l1 = l1 + 1
       End If
     Next I
     l = l1 + 7 + 1
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Broadcast                'CAN���߹㲥��ַ
'     OutData(4) = TYPE_Itself                   '����
     OutData(4) = 111 'ADDR_LedScreen+
'     OutData(4) = TYPE_Itself                   '����
     OutData(5) = LEDR_StoreSentance
     OutData(6) = l1 + 1                        '��������
     OutData(7) = 0                             '��������
     k = 8
     For I = 1 To Len(S1)
       s = Mid(S1, I, 1)
       If (s > Chr(127)) Then
          OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 1, 2))
          k = k + 1
          OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 3, 2))
       Else
          OutData(k) = Asc(s)
       End If
          k = k + 1
     Next I
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData


Case 19                                         '��բ����
     l = 9                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text) 'ADDR_Broadcast
     OutData(4) = TYPE_Itself 'ADDR_AutoBarrier + 1            '����
     OutData(5) = ABMR_Operation
     OutData(6) = 2                            '��������
     OutData(7) = Asc("u")
     OutData(8) = 2
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

Case 20                                         '��բ
     l = 9                                      '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text) 'ADDR_Broadcast
     OutData(4) = TYPE_Itself 'ADDR_AutoBarrier + 1            '����
     OutData(5) = ABMR_Operation
     OutData(6) = 2                            '��������
     OutData(7) = Asc("d")
     OutData(8) = Asc("w")
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

Case 29                                          '�ȴ��¼���Ч
     l = 10                                     '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself
     OutData(4) = TYPE_Itself      '����
     OutData(5) = SMMR_EventValid
     OutData(6) = 3                             '��������
     OutData(7) = 1                             'ͨ����ַ
     OutData(8) = 88                            '����Ա���
     OutData(9) = 0                             '�����Ч
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

Case 45 '���շѷ�������
    
     s = Text3.Text
     Set DatabaseTran = DBEngine.Workspaces(0).OpenDatabase(s)
     Set RecordsetTran = DatabaseTran.OpenRecordset("���ݱ�", dbOpenSnapshot) 'source,type=1Table���ݱ����������ݷ�������ֱ���޸�,2=Dynaset��̬�������ݶ����ڴ��п��ٲ���,4=Snapshot�������ڴ��в�ѯ�����޸�

     If RecordsetTran.RecordCount = 0 Then
        MsgBox "��ǰͣ�����ʱ�������,�����������!"
        Exit Sub
     Else
        RecordsetTran.MoveLast
        RecordsetTran.MoveFirst
     End If
     If RecordsetTran.RecordCount < 8 Then
        MsgBox "��ǰͣ�����ʱ����ݲ���" + Str(TimeTotal) + "��,���ȴ�������!"
        Exit Sub
     End If
     '--------------------------------------------------����Holidayѡ��б�-----------------------------------------------------------------------------
     DataLen = 243
     Page = &HD0 - &HC0                                 '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     p = 8
     
     '-------------1�ֽڣ����ֽڶ�����ѡ��
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     For a = 0 To 0                                     '��һ���ֽ�
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Holiday").Value
         If IsNull(s) Then s = "0"
         ls = Len(s)
         If ls > 8 Then                                 'ɾ����߳���λ
            s = Mid(s, ls - 7, 8)
            ls = 8
         End If
         I = 0
         For m = 0 To ls - 1                            '��������8λ
             If Mid(s, ls - m, 1) = "1" Then
                I = I + 2 ^ m
             End If
         Next m
         OutData(p + a) = I
     Next a
     p = p + 1
     
     '-------------15�ֽڣ����ֽ�ѡ��                   '�޿ո�
     For a = 0 To 14
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Holiday").Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     p = p + 15
     
     '------------64�ֽڣ�32��˫�ֽ�����:MM-DD
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     For a = 0 To 31                                    '2�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Holiday").Value
         If IsNull(s) Then s = "0"
         OutData(p) = Val(Mid(s, 4, 2))                 'MM-DD
         OutData(p + 1) = Val(Mid(s, 1, 2))
         p = p + 2
     Next a
     
     '------------162�ֽڣ�54��3�ֽ�����:MM-DD
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     For a = 0 To 53                                    '3�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Holiday").Value
         If IsNull(s) Then s = "0"
         OutData(p) = Val(Mid(s, 9, 2))                 '�б�����:YYYY-MM-DD
         OutData(p + 1) = Val(Mid(s, 6, 2))
         OutData(p + 2) = Val(Mid(s, 3, 2))
         p = p + 3
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    '---------------------------------------------------����Comsuption������-----------------------------------------------------------------------------
     '--------------------------------------------------����Tollѡ��б�-----------------------------------------------------------------------------
     RecordsetTran.FindFirst "Index=103"                'ͷ����¼Ϊ�ո�
     s = RecordsetTran.Fields("Toll").Value
     If IsNull(s) Then s = "0"
     DecimalDigits = Val(s)
     If DecimalDigits > 2 Then DecimalDigits = 2       '������λС��
    

     DataLen = 161
     Page = &HD2 - &HC0                                 '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     p = 8
     
     '-------------16�ֽڣ����ֽ�ѡ��                   '�޿ո�
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     For a = 0 To 15
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Toll").Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     p = p + 16
     
     '------------16�ֽ�-------------------
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     For a = 0 To 1                                     '��2��˫�ֽڶ�����
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Toll").Value
         If IsNull(s) Then s = "0"
         ls = Len(s)
         If ls > 16 Then                                 'ɾ����߳���λ
            s = Mid(s, ls - 15, 16)
            ls = 16
         End If
         I = 0
         For m = 0 To ls - 1                            '��������16λ
             If Mid(s, ls - m, 1) = "1" Then
                I = I + 2 ^ m
             End If
         Next m
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
     Next a
     For a = 0 To 5                                     '6������˫�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Toll").Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
     Next a
     
     '-------------8X(4+4)X2=128�ֽڣ�8��4����4����˫�ֽڶ�����
     For a = 0 To 7
         RecordsetTran.MoveNext                              '������
         RecordsetTran.MoveNext
         
         For b = 0 To 3
             RecordsetTran.MoveNext
             s = RecordsetTran.Fields("Toll").Value
             If IsNull(s) Then s = "0"
             ls = Len(s)
             If ls > 16 Then                                 'ɾ����߳���λ
                s = Mid(s, ls - 15, 16)
                ls = 16
             End If
             I = 0
             For m = 0 To ls - 1                             '��������16λ
                 If Mid(s, ls - m, 1) = "1" Then
                    I = I + 2 ^ m
                 End If
             Next m
             OutData(p) = I Mod 256
             OutData(p + 1) = I \ 256
             p = p + 2
         Next b
         RecordsetTran.MoveNext                              '��1��
         For b = 0 To 3
             RecordsetTran.MoveNext
             s = RecordsetTran.Fields("Toll").Value
             If IsNull(s) Then s = "0"
             ls = Len(s)
             If ls > 16 Then                                 'ɾ����߳���λ
                s = Mid(s, ls - 15, 16)
                ls = 16
             End If
             I = 0
             For m = 0 To ls - 1                             '��������16λ
                 If Mid(s, ls - m, 1) = "1" Then
                    I = I + 2 ^ m
                 End If
             Next m
             OutData(p) = I Mod 256
             OutData(p + 1) = I \ 256
             p = p + 2
         Next b
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    '---------------------------------------------------����Category0-15���ֳ����շѱ�-------------------------------------------------------------------
     Dim FieldName(16) As String
     FieldName(0) = "Category0"
     FieldName(1) = "Category1"
     FieldName(2) = "Category2"
     FieldName(3) = "Category3"
     FieldName(4) = "Category4"
     FieldName(5) = "Category5"
     FieldName(6) = "Category6"
     FieldName(7) = "Category7"
     FieldName(8) = "Category8"
     FieldName(9) = "Category9"
     FieldName(10) = "Category10"
     FieldName(11) = "Category11"
     FieldName(12) = "Category12"
     FieldName(13) = "Category13"
     FieldName(14) = "Category14"
     FieldName(15) = "Category15"
     
 For Category = 0 To 15
     DataLen = 240
     Page = &HD3 - &HC0 + Category                      '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�����
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     '-------------16�ֽڣ����ֽ�ѡ��-------------------
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     p = 8
     For a = 0 To 15
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     p = p + 16
     
     '-------------����Ϊ�����շѲ���-------------------
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     
     RecordsetTran.MoveNext                             '1�ֽ����볡��¼�շ�ģʽ
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     OutData(p) = Val(s)
     p = p + 1
     
     RecordsetTran.MoveNext                             '���볡��¼���ϴγ���ʱ��������ʱ��(����)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '���볡��¼�����շ��շѽ��(Ԫ)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     I = I * 10 ^ DecimalDigits                         '�շѽ��(С��->����Ԫ)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '����1�ֽ�
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     OutData(p) = Val(s)
     p = p + 1
     
     RecordsetTran.MoveNext                             '���õ��볡ͣ�����ʱ��(����)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '���õĹ��������ͷʱ��(����)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '�����շ�����ʱʱ��(����)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '���õ������޶�Ʒ�ʱ��(Сʱ)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s) * 60
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '���õ������޶�Ʒѽ��(Ԫ)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     I = I * 10 ^ DecimalDigits                         '�շѽ��(С��->����Ԫ)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     
     '---------����ʱ����ͨ�շѲ���---------------------
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     For a = 0 To 3                                     '��ͨ�շ�ģʽ��4�����ֽ�
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     p = p + 4
    
     RecordsetTran.MoveNext                             '�볡�շѼƷ�ʱ��(����)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
    
     RecordsetTran.MoveNext                             '�볡�շ��շѽ��(Ԫ)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     I = I * 10 ^ DecimalDigits                         '�շѽ��(С��->����Ԫ)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '��λʱ���շѣ��Ʒ�ʱ��(����)
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
    
     RecordsetTran.MoveNext                             '��λʱ���շѽ��(Ԫ )
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     I = I * 10 ^ DecimalDigits                         '�շѽ��(С��->����Ԫ)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '����˫�ֽ�1
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext                             '����˫�ֽ�2
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     '---------�������շѲ���--------------------------
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     OutData(p) = Val(s)
     p = p + 1
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(Mid(s, 1, 2)) * 60 + Val(Mid(s, 4, 2))     'HH:MM
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     OutData(p) = Val(s)
     p = p + 1
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields(FieldName(Category)).Value
     If IsNull(s) Then s = "0"
     I = Val(s)
     OutData(p) = I Mod 256
     OutData(p + 1) = I \ 256
     p = p + 2
     
     For a = 0 To 9 Step 2
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         OutData(p + a) = I Mod 256
         OutData(p + a + 1) = I \ 256
     Next a
     p = p + 10
     
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     
     For a = 0 To 7                                     '8�����ֽ�
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     p = p + 8
     
     '---------5��19�ֽ�----------------------
         RecordsetTran.MoveNext                             '��1��
     For a = 0 To 4
         RecordsetTran.MoveNext                             '��1��
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(Mid(s, 1, 2)) * 60 + Val(Mid(s, 4, 2))     '(HH:MM-HH:MM)
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         I = Val(Mid(s, 7, 2)) * 60 + Val(Mid(s, 10, 2))    '(HH:MM-HH:MM)
         OutData(p + 2) = I Mod 256
         OutData(p + 3) = I \ 256
         p = p + 4
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(Mid(s, 1, 2)) * 60 + Val(Mid(s, 4, 2))     '(HH:MM-HH:MM)
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         I = Val(Mid(s, 7, 2)) * 60 + Val(Mid(s, 10, 2))    '(HH:MM-HH:MM)
         OutData(p + 2) = I Mod 256
         OutData(p + 3) = I \ 256
         p = p + 4
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         I = I * 10 ^ DecimalDigits
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2

         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         OutData(p) = Val(s)
         p = p + 1
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         I = I * 10 ^ DecimalDigits
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2

         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         I = I * 10 ^ DecimalDigits
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
     Next a
     
     '---------18��4�ֽڵ��շ��б�--------------------------
         RecordsetTran.MoveNext                             '������
         RecordsetTran.MoveNext
     For a = 0 To 17
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s) * 60
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields(FieldName(Category)).Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         I = I * 10 ^ DecimalDigits
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         p = p + 2
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
Next Category

Case 46 '��λ���������غ���λ
     '----------------------------------------------------����Vacant��λ����-----------------------------------------------------------------------------
    
     s = Text3.Text
     Set DatabaseTran = DBEngine.Workspaces(0).OpenDatabase(s)
     Set RecordsetTran = DatabaseTran.OpenRecordset("���ݱ�", dbOpenSnapshot) '�ڴ˴򿪿��Զ�����
     
     RecordsetTran.FindFirst "Index=100"               '�ֳ�����
     s = RecordsetTran.Fields("VacantLimit").Value
     If IsNull(s) Then s = "0"
     ParkAmount = Val(s)
     DataLen = 2 * ParkAmount
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_SetVacant                        '���ظ�����ʣ�೵λ����,����Ϊ���ܳ���ʣ�೵λ��[2]+1�ų���ʣ�೵λ��[2]+2�ų���ʣ�೵λ��[2]+...
     OutData(6) = DataLen                               '��������
     
     
     For a = 0 To ParkAmount - 1
         s = RecordsetTran.Fields("Vacant").Value
         If IsNull(s) Then s = "0"
         I = Val(s)                                    'ʣ�೵λ
         OutData(7 + a * 2) = I Mod 256
         OutData(8 + a * 2) = I \ 256
         RecordsetTran.MoveNext
     Next a
     
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
     

    
    '---------------------------------------------------����VacantLimit��λ�����޲�����-----------------------------------------------------------------------------
     DataLen = 3 + 4 * (ParkAmount + 1)
     Page = 9                                           '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("VacantLimit").Value
     If IsNull(s) Then s = "0"
     OutData(8) = Val(s)                                '�ֳ�������(0-11)

     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("VacantLimit").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '����1�ֽ�
     
     For a = 0 To ParkAmount
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("VacantLimit").Value
         If IsNull(s) Then s = "0"
         I = Val(s)                                     '��λ����
         OutData(10 + a * 4) = I Mod 256
         OutData(11 + a * 4) = I \ 256
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("VacantLimit").Value
         If IsNull(s) Then s = "0"
         Dim Int1 As Integer
         Int1 = Val(s)                                  '��λ����
         If Int1 >= 0 Then
             OutData(12 + a * 4) = Int1 Mod 256
             OutData(13 + a * 4) = Int1 \ 256
         Else
             s = Hex(Int1)                                  'Int1<0 ,S����=4
             OutData(12 + a * 4) = Val("&H" + Mid(s, 3, 2))
             OutData(13 + a * 4) = Val("&H" + Mid(s, 1, 2))
         End If
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    
    '---------------------------------------------------����VacantText��λ�ַ�-----------------------------------------------------------------------------
     DataLen = 5 + 20 * (ParkAmount + 1)
     Page = 10                                         '����ҳ��

     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("VacantText").Value
     If IsNull(s) Then s = "0"
     OutData(8) = Val(s)                                '��λ�ַ�����

     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("VacantText").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '��λ����λ��
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("VacantText").Value
     If IsNull(s) Then s = "0"
     OutData(10) = Val(s)                               '��λ������ģʽ
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("VacantText").Value
     If IsNull(s) Then s = "0"
     OutData(11) = Val(s)                               '������ʾģʽ
     
     For a = 0 To ParkAmount
         RecordsetTran.MoveNext
         S1 = RecordsetTran.Fields("VacantText").Value
         If IsNull(S1) Then s = "No Text"
         k = 12 + 20 * a
         For I = 0 To 19
             OutData(k + I) = Asc(" ")                  '��ʼ��Ϊ20���ո�
         Next I
         For I = 1 To Len(S1)                           '�ַ�����û��ϵ,��һѭ���ֱ�����
             s = Mid(S1, I, 1)
             If (s > Chr(127)) Then
                 OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 1, 2))
                 k = k + 1
                 OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 3, 2))
             Else
                 OutData(k) = Asc(s)
             End If
             k = k + 1
         Next I
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    '---------------------------------------------------����ParkFullText��λ�ַ�-----------------------------------------------------------------------------
     DataLen = 5 + 20 * (ParkAmount + 1)
     Page = 11                                         '����ҳ��

     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("ParkFullText").Value
     If IsNull(s) Then s = "0"
     OutData(8) = Val(s)                                '��λ�ַ�����

     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("ParkFullText").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '����1�ֽ�
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("ParkFullText").Value
     If IsNull(s) Then s = "0"
     OutData(10) = Val(s)                               '����1�ֽ�
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("ParkFullText").Value
     If IsNull(s) Then s = "0"
     OutData(11) = Val(s)                               '��λ��ʾģʽ
     
     For a = 0 To ParkAmount
         RecordsetTran.MoveNext
         S1 = RecordsetTran.Fields("ParkFullText").Value
         If IsNull(S1) Then s = "No Text"
         k = 12 + 20 * a
         For I = 0 To 19
             OutData(k + I) = Asc(" ")                  '��ʼ��Ϊ20���ո�
         Next I
         For I = 1 To Len(S1)                           '�ַ�����û��ϵ,��һѭ���ֱ�����
             s = Mid(S1, I, 1)
             If (s > Chr(127)) Then
                 OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 1, 2))
                 k = k + 1
                 OutData(k) = Val("&H" + Mid(Hex(Asc(s)), 3, 2))
             Else
                 OutData(k) = Asc(s)
             End If
             k = k + 1
         Next I
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep

    '---------------------------------------------------����DirectionVD������-----------------------------------------------------------------------------
     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("DirectionVD").Value
     If IsNull(s) Then s = "0"
     VDAmount = Val(s)
     DataLen = 3 + VDAmount
     Page = 36                                          '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     OutData(8) = VDAmount                              'VD����

     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("DirectionVD").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '����1�ֽ�
     
     For a = 0 To VDAmount - 1
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("DirectionVD").Value
         If IsNull(s) Then s = "255"
         I = Val(s)                                     '�����ظ�
         OutData(10 + a) = I
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    
    '---------------------------------------------------����EnterArea������-----------------------------------------------------------------------------
     DataLen = 3 + VDAmount
     Page = 37                                          '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��

     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("EnterArea").Value
     If IsNull(s) Then s = "0"
     OutData(8) = Val(s)                                '����1�ֽ�
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("EnterArea").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '����1�ֽ�
     
     For a = 0 To VDAmount - 1
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("EnterArea").Value
         If IsNull(s) Then s = "0"
         I = Val(s)                                     '�����ظ�
         OutData(10 + a) = I
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    
    '---------------------------------------------------����LeaveArea������-----------------------------------------------------------------------------
     DataLen = 3 + VDAmount
     Page = 38                                          '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��

     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("LeaveArea").Value
     If IsNull(s) Then s = "0"
     OutData(8) = Val(s)                                '����1�ֽ�
     
     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("LeaveArea").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '����1�ֽ�
     
     For a = 0 To VDAmount - 1
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("LeaveArea").Value
         If IsNull(s) Then s = "0"
         I = Val(s)                                     '�����ظ�
         OutData(10 + a) = I
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep

Case 47 '��λ����
     '----------------------------------------------------����Vacant��λ����-----------------------------------------------------------------------------
    
     s = Text3.Text
     Set DatabaseTran = DBEngine.Workspaces(0).OpenDatabase(s)
     Set RecordsetTran = DatabaseTran.OpenRecordset("���ݱ�", dbOpenSnapshot) '�ڴ˴򿪿��Զ�����
     
     RecordsetTran.FindFirst "Index=100"               '�ֳ�����
     s = RecordsetTran.Fields("VacantLimit").Value
     If IsNull(s) Then s = "0"
     ParkAmount = Val(s)
     DataLen = 2 * ParkAmount
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_SetVacant                        '���ظ�����ʣ�೵λ����,����Ϊ���ܳ���ʣ�೵λ��[2]+1�ų���ʣ�೵λ��[2]+2�ų���ʣ�೵λ��[2]+...
     OutData(6) = DataLen                               '��������
     
     
     For a = 0 To ParkAmount - 1
         s = RecordsetTran.Fields("Vacant").Value
         If IsNull(s) Then s = "0"
         I = Val(s)                                    'ʣ�೵λ
         OutData(7 + a * 2) = I Mod 256
         OutData(8 + a * 2) = I \ 256
         RecordsetTran.MoveNext
     Next a
     
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep

    '---------------------------------------------------����VacantLimit��λ�����޲�����-----------------------------------------------------------------------------
     DataLen = 3 + 4 * (ParkAmount + 1)
     Page = 9                                           '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     RecordsetTran.FindFirst "Index=100"                'ͷ����¼
     s = RecordsetTran.Fields("VacantLimit").Value
     If IsNull(s) Then s = "0"
     OutData(8) = Val(s)                                '�ֳ�������(0-11)

     RecordsetTran.MoveNext
     s = RecordsetTran.Fields("VacantLimit").Value
     If IsNull(s) Then s = "0"
     OutData(9) = Val(s)                                '����1�ֽ�
     
     For a = 0 To ParkAmount
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("VacantLimit").Value
         If IsNull(s) Then s = "0"
         I = Val(s)                                     '��λ����
         OutData(10 + a * 4) = I Mod 256
         OutData(11 + a * 4) = I \ 256
         
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("VacantLimit").Value
         If IsNull(s) Then s = "0"
         Int1 = Val(s)                                  '��λ����
         If Int1 >= 0 Then
             OutData(12 + a * 4) = Int1 Mod 256
             OutData(13 + a * 4) = Int1 \ 256
         Else
             s = Hex(Int1)                                  'Int1<0 ,S����=4
             OutData(12 + a * 4) = Val("&H" + Mid(s, 3, 2))
             OutData(13 + a * 4) = Val("&H" + Mid(s, 1, 2))
         End If
     Next a
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
     
Case 48 '�����û�ϵͳ����
     '----------------------------------------------------����Board����-----------------------------------------------------------------------------
    
     s = Text3.Text
     Set DatabaseTran = DBEngine.Workspaces(0).OpenDatabase(s)
     Set RecordsetTran = DatabaseTran.OpenRecordset("���ݱ�", dbOpenSnapshot) '�ڴ˴򿪿��Զ�����
     
     DataLen = 129
     Page = &HCE - &HC0                                 '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     '-------------16�ֽڣ����ֽڶ����ư����豸ѡ��
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     p = 8
     For a = 0 To 15
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Board").Value
         If IsNull(s) Then s = "0"
         ls = Len(s)
         If ls > 8 Then                                  'ɾ����߳���λ
            s = Mid(s, ls - 7, 8)
            ls = 8
         End If
         I = 0
         For m = 0 To ls - 1                             '��������8λ
             If Mid(s, ls - m, 1) = "1" Then
                I = I + 2 ^ m
             End If
         Next m
         OutData(p + a) = I
     Next a
     
     '-------------16�ֽڣ����ֽڶ����ƹ��������ͨѡ��
     RecordsetTran.MoveNext                              '������
     RecordsetTran.MoveNext
     p = p + 16
     For a = 0 To 15
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Board").Value
         If IsNull(s) Then s = "0"
         ls = Len(s)
         If ls > 8 Then                                  'ɾ����߳���λ
            s = Mid(s, ls - 7, 8)
            ls = 8
         End If
         I = 0
         For m = 0 To ls - 1                             '��������8λ
             If Mid(s, ls - m, 1) = "1" Then
                I = I + 2 ^ m
             End If
         Next m
         OutData(p + a) = I
     Next a
     
     '-------------16�ֽڣ����ֽ�100msѡ��
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     p = p + 16
     For a = 0 To 15
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Board").Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     
     '------------16�ֽڣ�˫�ֽڲ���
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     p = p + 16
     For a = 0 To 15 Step 2                             '2�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Board").Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         OutData(p + a) = I Mod 256
         OutData(p + 1 + a) = I \ 256
     Next a
     
     '------------32�ֽڣ����ֽ�ʱ�β���ѡ��
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     p = p + 16
     For a = 0 To 31 Step 4                             '8��4�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Board").Value
         If IsNull(s) Then s = "0"
         I = Val(Mid(s, 1, 2)) * 60 + Val(Mid(s, 4, 2)) '��ʼ-����ʱ�� HH:MM-HH:MM
         OutData(p + a) = I Mod 256
         OutData(p + 1 + a) = I \ 256
         I = Val(Mid(s, 7, 2)) * 60 + Val(Mid(s, 10, 2))
         OutData(p + 2 + a) = I Mod 256
         OutData(p + 3 + a) = I \ 256
     Next a
     
     '-------------32�ֽڣ�˫�ֽڶ����ƿ�բģʽ
     RecordsetTran.MoveNext                              '������
     RecordsetTran.MoveNext
     p = p + 32
     For a = 0 To 31 Step 2                              '2�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Board").Value
         If IsNull(s) Then s = "0"
         ls = Len(s)
         If ls > 16 Then                                  'ɾ����߳���λ
            s = Mid(s, ls - 15, 16)
            ls = 16
         End If
         I = 0
         For m = 0 To ls - 1                             '��������16λ
             If Mid(s, ls - m, 1) = "1" Then
                I = I + 2 ^ m
             End If
         Next m
         OutData(p + a) = I Mod 256
         OutData(p + 1 + a) = I \ 256
     Next a

     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
     
     '----------------------------------------------------����Manage����-----------------------------------------------------------------------------
     DataLen = 113
     Page = &HCF - &HC0                                 '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     '-------------16�ֽڣ����ֽ�ѡ��-------
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     p = 8
     For a = 0 To 15
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Manage").Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     
     '------------16�ֽڣ�8��˫�ֽڲ���
     RecordsetTran.MoveNext                             '������
     RecordsetTran.MoveNext
     p = p + 16
     For a = 0 To 15 Step 2                             '2�ֽڲ���
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Manage").Value
         If IsNull(s) Then s = "0"
         I = Val(s)
         OutData(p + a) = I Mod 256
         OutData(p + 1 + a) = I \ 256
     Next a
     
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     RecordsetTran.MoveNext
     
     '-------------16�ֽ�5�飬���ֽڶ�����16�࿨ͨ��/���/����/�ڳ����/�ڳ�����ѡ��
     p = p + 16 - 16                                         '�����ּ�16��
     For b = 0 To 3
         RecordsetTran.MoveNext                              '������
         RecordsetTran.MoveNext
         p = p + 16
         For a = 0 To 15
             RecordsetTran.MoveNext
             s = RecordsetTran.Fields("Manage").Value
             If IsNull(s) Then s = "0"
             ls = Len(s)
             If ls > 8 Then                                  'ɾ����߳���λ
                s = Mid(s, ls - 7, 8)
                ls = 8
             End If
             I = 0
             For m = 0 To ls - 1                             '��������8λ
                 If Mid(s, ls - m, 1) = "1" Then
                    I = I + 2 ^ m
                 End If
             Next m
             OutData(p + a) = I
         Next a
     Next b
    
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
    
     '----------------------------------------------------����Access����-----------------------------------------------------------------------------
     DataLen = 255 - 12                                 '=255 ,��ȻRXBuf=512����ͬʱ����������ʱ�����
     Page = &HCC - &HC0                                 '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     '-------------26�ֽڣ����ֽ�ѡ��-------
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     p = 8
     For a = 0 To 25
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Access").Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     
     p = p + 26 - 12
     '-------------12�ֽ�18�飬˫�ֽڶ����ƿ�բģʽ
     For b = 0 To 17 '18
         RecordsetTran.MoveNext                              '������
         RecordsetTran.MoveNext
         p = p + 12
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("Access").Value
         If IsNull(s) Then s = "0"
         I = Val(Mid(s, 1, 2)) * 60 + Val(Mid(s, 4, 2))     '��ʼ-����ʱ�� HH:MM-HH:MM
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         I = Val(Mid(s, 7, 2)) * 60 + Val(Mid(s, 10, 2))
         OutData(p + 2) = I Mod 256
         OutData(p + 3) = I \ 256
         For a = 0 To 7 Step 2                               '4��2�ֽڲ���
             RecordsetTran.MoveNext
             s = RecordsetTran.Fields("Access").Value
             If IsNull(s) Then s = "0"
             ls = Len(s)
             If ls > 16 Then                                  'ɾ����߳���λ
                s = Mid(s, ls - 15, 16)
                ls = 16
             End If
             I = 0
             For m = 0 To ls - 1                             '��������16λ
                 If Mid(s, ls - m, 1) = "1" Then
                    I = I + 2 ^ m
                 End If
             Next m
             OutData(p + 4 + a) = I Mod 256
             OutData(p + 4 + a + 1) = I \ 256
         Next a
     Next b
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep
     '----------------------------------------------------����HolidayAccess����-----------------------------------------------------------------------------
     DataLen = 255 - 12                                 '=255 ,��ȻRXBuf=512����ͬʱ����������ʱ�����
     Page = &HCD - &HC0                                 '����ҳ��
     
     l = 7 + DataLen                                    '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                       '������ַ
     OutData(4) = TYPE_Itself                           '����
     OutData(5) = SMMR_WriteParameterTable              'д����ֲ����� 1�ֽڱ����+�������
     OutData(6) = DataLen                               '��������
     OutData(7) = Page                                  '����ҳ��
     
     '-------------26�ֽڣ����ֽ�ѡ��-------
     RecordsetTran.FindFirst "Index=101"                'ͷ����¼Ϊ�ո�
     p = 8
     For a = 0 To 25
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("HolidayAccess").Value
         If IsNull(s) Then s = "0"
         OutData(p + a) = Val(s)
     Next a
     
     p = p + 26 - 12
     '-------------12�ֽ�18�飬˫�ֽڶ����ƿ�բģʽ
     For b = 0 To 17 '18
         RecordsetTran.MoveNext                              '������
         RecordsetTran.MoveNext
         p = p + 12
         RecordsetTran.MoveNext
         s = RecordsetTran.Fields("HolidayAccess").Value
         If IsNull(s) Then s = "0"
         I = Val(Mid(s, 1, 2)) * 60 + Val(Mid(s, 4, 2))     '��ʼ-����ʱ�� HH:MM-HH:MM
         OutData(p) = I Mod 256
         OutData(p + 1) = I \ 256
         I = Val(Mid(s, 7, 2)) * 60 + Val(Mid(s, 10, 2))
         OutData(p + 2) = I Mod 256
         OutData(p + 3) = I \ 256
         For a = 0 To 7 Step 2                               '4��2�ֽڲ���
             RecordsetTran.MoveNext
             s = RecordsetTran.Fields("HolidayAccess").Value
             If IsNull(s) Then s = "0"
             ls = Len(s)
             If ls > 16 Then                                  'ɾ����߳���λ
                s = Mid(s, ls - 15, 16)
                ls = 16
             End If
             I = 0
             For m = 0 To ls - 1                             '��������16λ
                 If Mid(s, ls - m, 1) = "1" Then
                    I = I + 2 ^ m
                 End If
             Next m
             OutData(p + 4 + a) = I Mod 256
             OutData(p + 4 + a + 1) = I \ 256
         Next a
     Next b
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     Beep

Case 49
     CommonDialog1.Filter = "Access Files (*.mdb)|*.mdb"
     CommonDialog1.FilterIndex = 1      ' Specify default filter.
     CommonDialog1.ShowOpen             ' Display the File Open dialog box.
     Text3.Text = CommonDialog1.FileName

Case 50                                     '���ط�����+1�ֽڲ���;0=�ر�;1=����
     l = 8                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = CPMR_Lock                 '���ط����� 0xA0
     OutData(6) = 1                         '��������
     Volume = Volume + 1
     If Volume >= 2 Then Volume = 0
     OutData(7) = Volume
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData

Case 51                                     '����+1�ֽڲ���;0=�ر�;1=ԭʼ��������;2=X2�Ӵ�һ��;3=X4�ټӴ�һ����
     l = 7                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = Val(Text2.Text)                           '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = CPMR_Cardout              ' 0xA1����������ָ��
     OutData(6) = 0                         '��������
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
     

End Select
End Sub

Private Sub Tran2_Click(Index As Integer)
Dim OutData() As Byte
If MSComm1.PortOpen = False Then MSComm1.PortOpen = True
Select Case Index
Case 0                                       'ֹͣѰ��
     l = 8                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 1                        '��������
     OutData(7) = &H0                       'MFRW_Halt
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 1                                       '��ȡID
     l = 8                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 1                        '��������
     OutData(7) = &H1                       'MFRW_ReadID
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 6                                       '��ȡReadID��Privilege
     l = 8                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 1                        '��������
     OutData(7) = &H6                       'MFRW_ReadPrivilege
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 9                                       '��ʽ��������ʱ��
     l = 13                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 6                         '��������
     OutData(7) = &HE                       'MFRW_FormatCard
     s = Text1(5).Text
     OutData(8) = Val("&H" + Mid(s, 4, 2)) 'Ŀ�꿨ID�š�4��
     OutData(9) = Val("&H" + Mid(s, 7, 2))
     OutData(10) = Val("&H" + Mid(s, 10, 2))
     OutData(11) = Val("&H" + Mid(s, 13, 2))
     OutData(12) = 9                        '���Ϳ���[1]��0x09=��ʱ����0x11=�Żݴ�ֵ��
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 10                                       '��ʽ�������Żݴ�ֵ��
     l = 13                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 6                         '��������
     OutData(7) = &HE                       'MFRW_FormatCard
     s = Text1(5).Text
     OutData(8) = Val("&H" + Mid(s, 4, 2)) 'Ŀ�꿨ID�š�4��
     OutData(9) = Val("&H" + Mid(s, 7, 2))
     OutData(10) = Val("&H" + Mid(s, 10, 2))
     OutData(11) = Val("&H" + Mid(s, 13, 2))
     OutData(12) = &H11                        '���Ϳ���[1]��0x09=��ʱ����0x11=�Żݴ�ֵ��
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 11                                      '��ʱ������
     l = 16                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 9                         '��������
     OutData(7) = &HD                       'PrivilegeSave
     s = Text1(5).Text
     OutData(8) = Val("&H" + Mid(s, 4, 2)) 'Ŀ�꿨ID�š�4��
     OutData(9) = Val("&H" + Mid(s, 7, 2))
     OutData(10) = Val("&H" + Mid(s, 10, 2))
     OutData(11) = Val("&H" + Mid(s, 13, 2))
     OutData(12) = 9                        '���Ϳ���[1]                 0x09=��ʱ����0x11=�Żݴ�ֵ��
     OutData(13) = &H80                     'ͣ�����Ż�״̬[1]           ��ʱ����BIT7=������־��BIT1=���Żݣ�  �Żݴ�ֵ����BIT1=1=���Żݴ�ֵ��BIT1=0=�Żݴ�ֵ��ת����Pos��
     OutData(14) = 0                        '��ʱ��=�Żݻ���[1]          �Żݴ�ֵ��=�Żݴ�����λ�ֽ�
     OutData(15) = 0                        '��ʱ��=�Ż��������[1]      �Żݴ�ֵ��=�Żݴ�����λ�ֽ�
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
Case 12                                      'д�Ż�ͣ��
     l = 16                                  '=���Ԫ�����
     ReDim OutData(l)
     OutData(0) = CONCommSyn1
     OutData(1) = CONCommSyn2
     OutData(2) = CONCommSyn3
     OutData(3) = ADDR_Myself               '������ַ
     OutData(4) = TYPE_Itself               '����
     OutData(5) = &H84                      'MFRWR_ReadWrite
     OutData(6) = 9                         '��������
     OutData(7) = &HD                       'PrivilegeSave
     s = Text1(5).Text
     OutData(8) = Val("&H" + Mid(s, 4, 2)) 'Ŀ�꿨ID�š�4��
     OutData(9) = Val("&H" + Mid(s, 7, 2))
     OutData(10) = Val("&H" + Mid(s, 10, 2))
     OutData(11) = Val("&H" + Mid(s, 13, 2))
     OutData(12) = &H11                      '���Ϳ���[1]                 0x09=��ʱ����0x11=�Żݴ�ֵ��
     OutData(13) = &H1                    'ͣ�����Ż�״̬[1]           ��ʱ����BIT7=������־��BIT1=���Żݣ�  �Żݴ�ֵ����BIT1=1=���Żݴ�ֵ��BIT1=0=�Żݴ�ֵ��ת����Pos��
     OutData(14) = 100                      '��ʱ��=�Żݻ���[1]          �Żݴ�ֵ��=�Żݴ�����λ�ֽ�
     OutData(15) = 0                        '��ʱ��=�Ż��������[1]      �Żݴ�ֵ��=�Żݴ�����λ�ֽ�
     
     OutData(l) = 0
     For I = 3 To l - 1
     OutData(l) = OutData(l) Xor OutData(I)
     Next I
     MSComm1.Output = OutData
End Select

End Sub
