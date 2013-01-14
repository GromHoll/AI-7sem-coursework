object MainMenuForm: TMainMenuForm
  Left = 0
  Top = 0
  Caption = 'Management Eling'
  ClientHeight = 454
  ClientWidth = 711
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Scaled = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 43
    Height = 17
    Caption = 'Terms:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 231
    Top = 119
    Width = 42
    Height = 17
    Caption = 'Result:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TermsCheckListBox: TCheckListBox
    Left = 8
    Top = 31
    Width = 217
    Height = 418
    ItemHeight = 13
    Sorted = True
    TabOrder = 0
  end
  object ResultMemo: TMemo
    Left = 231
    Top = 150
    Width = 474
    Height = 299
    Lines.Strings = (
      'ResultMemo')
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object SearchButton: TButton
    Left = 591
    Top = 119
    Width = 114
    Height = 25
    Caption = 'Search'
    TabOrder = 2
    OnClick = SearchButtonClick
  end
  object SearchModeRadioGroup: TRadioGroup
    Left = 231
    Top = 31
    Width = 114
    Height = 82
    Caption = 'Terms Search Mode'
    TabOrder = 3
    OnClick = SearchModeRadioGroupClick
  end
  object SearchLimitGroupBox: TGroupBox
    Left = 591
    Top = 31
    Width = 114
    Height = 82
    Caption = 'Search Limit'
    TabOrder = 4
    object Label3: TLabel
      Left = 3
      Top = 50
      Width = 33
      Height = 13
      Caption = 'Count:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LimitCheckBox: TCheckBox
      Left = 3
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Enable Limit'
      TabOrder = 0
      OnClick = LimitCheckBoxClick
    end
    object LimitCSpinEdit: TCSpinEdit
      Left = 42
      Top = 47
      Width = 72
      Height = 22
      Enabled = False
      MaxValue = 10
      MinValue = 1
      TabOrder = 1
      Value = 1
    end
  end
  object CohesionGroupBox: TGroupBox
    Left = 471
    Top = 31
    Width = 114
    Height = 82
    Caption = 'Cohesion Mode'
    TabOrder = 5
    object Label4: TLabel
      Left = 3
      Top = 50
      Width = 33
      Height = 13
      Caption = 'Count:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object CohesionCheckBox: TCheckBox
      Left = 3
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Enable Cohesion'
      TabOrder = 0
      OnClick = CohesionCheckBoxClick
    end
    object CohesionCSpinEdit: TCSpinEdit
      Left = 42
      Top = 47
      Width = 69
      Height = 22
      ParentCustomHint = False
      Enabled = False
      MaxValue = 10
      MinValue = 1
      TabOrder = 1
      Value = 1
    end
  end
  object GroupBox1: TGroupBox
    Left = 351
    Top = 31
    Width = 114
    Height = 82
    Caption = 'Logical Inference Deep'
    TabOrder = 6
    object Label5: TLabel
      Left = 6
      Top = 50
      Width = 29
      Height = 13
      Caption = 'Deep:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object DeepCSpinEdit: TCSpinEdit
      Left = 45
      Top = 47
      Width = 69
      Height = 22
      ParentCustomHint = False
      Enabled = False
      MaxValue = 7
      MinValue = 2
      TabOrder = 0
      Value = 1
    end
  end
  object MainMenu: TMainMenu
    Left = 88
    Top = 328
    object FileMenu: TMenuItem
      Caption = 'Knowledge Base'
      object AddMolingMenu: TMenuItem
        Caption = 'Add Moling'
        OnClick = AddMolingMenuClick
      end
      object MolingsMenu: TMenuItem
        Caption = 'Molings'
        OnClick = MolingsMenuClick
      end
      object SourceMenu: TMenuItem
        Caption = 'Source'
        OnClick = SourceMenuClick
      end
      object ExitMenu: TMenuItem
        Caption = 'Exit'
        OnClick = ExitMenuClick
      end
    end
    object DictionaryMenu: TMenuItem
      Caption = 'Dictionary'
      object TermMenu: TMenuItem
        Caption = 'Term'
        OnClick = TermMenuClick
      end
      object RelationshipMenu: TMenuItem
        Caption = 'Relationship'
        OnClick = RelationshipMenuClick
      end
      object QualitativeFeature: TMenuItem
        Caption = 'Qualitative Feature'
        OnClick = QualitativeFeatureClick
      end
      object QuantitativeAttribute: TMenuItem
        Caption = 'Quantitative Attribute'
        OnClick = QuantitativeAttributeClick
      end
      object LogLingLink: TMenuItem
        Caption = 'Logical/Linguistic Link'
        OnClick = LogLingLinkClick
      end
    end
  end
end
