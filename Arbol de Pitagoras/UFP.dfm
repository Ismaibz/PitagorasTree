object GLForm2D: TGLForm2D
  Left = 196
  Top = 38
  Width = 833
  Height = 631
  Caption = 'Formulario Principal'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    AutoHotkeys = maManual
    Left = 160
    Top = 112
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
        OnClick = PrimerCuadradoClick
      end
      object SiguienteGeneracion: TMenuItem
        Caption = 'Siguiente Generacion'
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