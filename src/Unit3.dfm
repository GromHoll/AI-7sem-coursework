object ViewForm: TViewForm
  Left = 0
  Top = 0
  Caption = 'Dictionary Viewer'
  ClientHeight = 444
  ClientWidth = 330
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
  object Memo: TMemo
    Left = 8
    Top = 8
    Width = 314
    Height = 400
    Lines.Strings = (
      'Memo')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object SaveButton: TButton
    Left = 8
    Top = 414
    Width = 146
    Height = 25
    Caption = 'Save'
    TabOrder = 1
    OnClick = SaveButtonClick
  end
  object CancelButton: TButton
    Left = 176
    Top = 414
    Width = 146
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
end
