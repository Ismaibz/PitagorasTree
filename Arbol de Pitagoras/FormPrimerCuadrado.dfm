object FormLado: TFormLado
  Left = 232
  Top = 227
  Width = 453
  Height = 191
  Caption = 'Elija el tamaño del lado'
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
    Left = 144
    Top = 56
    Width = 42
    Height = 24
    Caption = 'Lado'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 16
    Width = 398
    Height = 16
    Caption = 
      'Seleccione un tamaño de lado y  luego pinche en la posición inic' +
      'ial'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object TamanoLado: TEdit
    Left = 224
    Top = 56
    Width = 81
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object BotonAceptar: TButton
    Left = 176
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 1
    OnClick = BotonAceptarClick
  end
end
