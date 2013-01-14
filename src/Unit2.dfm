object AddMolingForm: TAddMolingForm
  Left = 0
  Top = 0
  Caption = 'Add Moling'
  ClientHeight = 162
  ClientWidth = 724
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label7: TLabel
    Left = 175
    Top = 16
    Width = 80
    Height = 13
    Caption = 'Kernel of Moling:'
  end
  object Label8: TLabel
    Left = 175
    Top = 43
    Width = 97
    Height = 13
    Caption = 'Sequence of Codes:'
  end
  object Label9: TLabel
    Left = 175
    Top = 70
    Width = 91
    Height = 13
    Caption = 'Value of Reliability:'
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 145
    Height = 145
    Caption = 'ID of Moling'
    TabOrder = 0
    object Label1: TLabel
      Left = 15
      Top = 24
      Width = 37
      Height = 13
      Caption = 'Source:'
    end
    object Label2: TLabel
      Left = 14
      Top = 43
      Width = 43
      Height = 13
      Caption = 'Chapter:'
    end
    object Label3: TLabel
      Left = 15
      Top = 62
      Width = 54
      Height = 13
      Caption = 'Paragraph:'
    end
    object Label4: TLabel
      Left = 14
      Top = 81
      Width = 72
      Height = 13
      Caption = 'Subparagraph:'
    end
    object Label5: TLabel
      Left = 14
      Top = 100
      Width = 36
      Height = 13
      Caption = 'Indent:'
    end
    object Label6: TLabel
      Left = 15
      Top = 119
      Width = 49
      Height = 13
      Caption = 'Sentence:'
    end
    object IDEdit1: TEdit
      Left = 92
      Top = 21
      Width = 44
      Height = 21
      NumbersOnly = True
      TabOrder = 0
      Text = '0'
    end
    object IDEdit4: TEdit
      Left = 92
      Top = 78
      Width = 44
      Height = 21
      NumbersOnly = True
      TabOrder = 1
      Text = '0'
    end
    object IDEdit2: TEdit
      Left = 92
      Top = 40
      Width = 44
      Height = 21
      NumbersOnly = True
      TabOrder = 2
      Text = '0'
    end
    object IDEdit3: TEdit
      Left = 92
      Top = 59
      Width = 44
      Height = 21
      NumbersOnly = True
      TabOrder = 3
      Text = '0'
    end
    object IDEdit6: TEdit
      Left = 92
      Top = 116
      Width = 44
      Height = 21
      NumbersOnly = True
      TabOrder = 4
      Text = '0'
    end
    object IDEdit5: TEdit
      Left = 92
      Top = 100
      Width = 44
      Height = 21
      NumbersOnly = True
      TabOrder = 5
      Text = '0'
    end
  end
  object KernelEdit: TEdit
    Left = 286
    Top = 13
    Width = 429
    Height = 21
    TabOrder = 1
  end
  object CodesEdit: TEdit
    Left = 286
    Top = 40
    Width = 429
    Height = 21
    TabOrder = 2
  end
  object ValueEdit: TEdit
    Left = 286
    Top = 67
    Width = 59
    Height = 21
    ReadOnly = True
    TabOrder = 3
    Text = '0'
  end
  object ValueTrackBar: TTrackBar
    Left = 351
    Top = 67
    Width = 364
    Height = 35
    Max = 100
    TabOrder = 4
    OnChange = ValueTrackBarChange
  end
  object CancelButton: TButton
    Left = 576
    Top = 129
    Width = 140
    Height = 25
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = CancelButtonClick
  end
  object AddButton: TButton
    Left = 430
    Top = 129
    Width = 140
    Height = 25
    Caption = 'Add'
    TabOrder = 6
    OnClick = AddButtonClick
  end
end
