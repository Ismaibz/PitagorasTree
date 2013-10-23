object GLForm2D: TGLForm2D
  Left = 611
  Top = 525
  Width = 408
  Height = 434
  Caption = 'Formulario Principal'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 112
    Top = 64
    object Archivo: TMenuItem
      Caption = 'Archivo'
      object Salir: TMenuItem
        Caption = 'Salir'
        OnClick = SalirClick
      end
    end
    object Programa: TMenuItem
      Caption = 'Programa'
      object PrimerCuadrado: TMenuItem
        Caption = 'Primer Cuadrado'
      end
      object Expandir: TMenuItem
        Caption = 'Expandir'
      end
    end
    object Zoom: TMenuItem
      Caption = 'Zoom'
      object ZoomIn: TMenuItem
        Caption = 'Zoom In'
      end
      object ZoomOut: TMenuItem
        Caption = 'Zoom Out'
      end
    end
    object Embaldosado: TMenuItem
      Caption = 'Embaldosado'
    end
  end
end
