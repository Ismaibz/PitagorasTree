object FormEmbaldosado: TFormEmbaldosado
  Left = 226
  Top = 223
  Width = 247
  Height = 181
  Caption = 'Embaldosado'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 186
    Height = 16
    Caption = 'Indique el numero de columnas'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object TextEmbaldosado: TEdit
    Left = 88
    Top = 48
    Width = 49
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '5'
  end
  object BotonAceptar: TButton
    Left = 72
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 1
    OnClick = BotonAceptarClick
  end
end
