object Form1: TForm1
  Left = 0
  Top = 0
  AlphaBlend = True
  ClientHeight = 785
  ClientWidth = 1665
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object TabbedNotebook1: TTabbedNotebook
    Left = 0
    Top = 0
    Width = 1665
    Height = 785
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Century Gothic'
    Font.Style = []
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'Tahoma'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1083#1072#1074#1085#1072#1103
      object StringGrid1: TStringGrid
        Left = 21
        Top = 29
        Width = 1150
        Height = 700
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Color = clWhite
        ColCount = 7
        DefaultColWidth = 132
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 0
      end
      object Panel1: TPanel
        Left = 1207
        Top = 29
        Width = 420
        Height = 702
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 1
        object Label1: TLabel
          Left = 123
          Top = 8
          Width = 176
          Height = 37
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -30
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
        end
        object Button1: TButton
          Left = 131
          Top = 598
          Width = 158
          Height = 64
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1091#1089#1082
          Enabled = False
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -33
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button1Click
        end
        object RadioGroup1: TRadioGroup
          Left = 89
          Top = 92
          Width = 242
          Height = 119
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1052#1077#1090#1086#1076' '#1053#1054#1055#1055
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object CheckBox1: TCheckBox
          Left = 102
          Top = 126
          Width = 43
          Height = 22
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = '(1)'
          Checked = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 2
          OnClick = CheckBox1Click
        end
        object RadioGroup2: TRadioGroup
          Left = 89
          Top = 248
          Width = 242
          Height = 119
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1052#1077#1090#1086#1076' '#1048#1052
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object CheckBox2: TCheckBox
          Left = 102
          Top = 167
          Width = 43
          Height = 23
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = '(2)'
          Checked = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 4
          OnClick = CheckBox2Click
        end
        object CheckBox3: TCheckBox
          Left = 102
          Top = 282
          Width = 43
          Height = 23
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = '(1)'
          Checked = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 5
          OnClick = CheckBox3Click
        end
        object CheckBox4: TCheckBox
          Left = 102
          Top = 324
          Width = 43
          Height = 23
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = '(2)'
          Checked = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 6
          OnClick = CheckBox4Click
        end
        object SpinEdit1: TSpinEdit
          Left = 153
          Top = 124
          Width = 158
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          MaxValue = 100
          MinValue = 0
          ParentFont = False
          TabOrder = 7
          Value = 1
        end
        object SpinEdit2: TSpinEdit
          Left = 153
          Top = 166
          Width = 158
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          MaxValue = 100
          MinValue = 0
          ParentFont = False
          TabOrder = 8
          Value = 1
        end
        object SpinEdit3: TSpinEdit
          Left = 153
          Top = 281
          Width = 158
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          MaxValue = 100
          MinValue = 0
          ParentFont = False
          TabOrder = 9
          Value = 1
        end
        object SpinEdit4: TSpinEdit
          Left = 153
          Top = 321
          Width = 158
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Century Gothic'
          Font.Style = []
          MaxValue = 100
          MinValue = 0
          ParentFont = False
          TabOrder = 10
          Value = 1
        end
      end
      object DirectoryListBox1: TDirectoryListBox
        Left = 21
        Top = 29
        Width = 1150
        Height = 700
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Enabled = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Century Gothic'
        Font.Style = []
        ItemHeight = 27
        ParentFont = False
        TabOrder = 2
        Visible = False
        OnClick = DirectoryListBox1Click
      end
    end
    object TTabPage
      Left = 4
      Top = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
      object Chart1: TChart
        Left = 5
        Top = 2
        Width = 1644
        Height = 751
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Legend.Title.Font.Name = 'Century Gothic'
        Legend.Visible = False
        Title.Font.Charset = RUSSIAN_CHARSET
        Title.Font.Color = clBlack
        Title.Font.Height = -23
        Title.Font.Name = 'Century Gothic'
        Title.Text.Strings = (
          #1055#1083#1072#1075#1080#1072#1090' '#1074' '#1087#1088#1086#1075#1088#1072#1084#1084#1072#1093)
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.Minimum = 1.000000000000000000
        BottomAxis.MinimumOffset = 50
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMaximum = False
        LeftAxis.Maximum = 100.000000000000000000
        View3D = False
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          22
          15
          22)
        ColorPaletteIndex = 13
        object Series1: TBarSeries
          BarBrush.Gradient.EndColor = 6519581
          BarBrush.Gradient.Visible = True
          ColorEachPoint = True
          ConePercent = 100
          BarStyle = bsRectGradient
          Gradient.EndColor = 6519581
          Gradient.Visible = True
          Sides = 128
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 32
      Caption = #1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077
      object Chart2: TChart
        Left = 5
        Top = 6
        Width = 1644
        Height = 747
        Legend.CustomPosition = True
        Legend.Font.Height = -23
        Legend.Font.Name = 'Century Gothic'
        Legend.Left = 35
        Legend.ResizeChart = False
        Legend.Symbol.Continuous = True
        Legend.Symbol.Gradient.EndColor = 52223
        Legend.Symbol.Gradient.MidColor = clWhite
        Legend.Symbol.Gradient.StartColor = clSilver
        Legend.TextStyle = ltsPlain
        Legend.Top = 40
        Title.Font.Color = clBlack
        Title.Font.Height = -23
        Title.Font.Name = 'Century Schoolbook'
        Title.Text.Strings = (
          #1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1087#1088#1086#1075#1088#1072#1084#1084' '#1087#1086' '#1091#1088#1086#1074#1085#1103#1084' '#1087#1083#1072#1075#1080#1072#1090#1072)
        Chart3DPercent = 100
        View3D = False
        View3DOptions.Elevation = 315
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          22
          15
          22)
        ColorPaletteIndex = 8
        object Series2: TPieSeries
          Marks.Brush.Gradient.Visible = True
          Marks.Font.Height = -20
          Marks.Style = smsPercent
          Marks.Callout.Length = 20
          XValues.Order = loAscending
          YValues.Name = 'Pie'
          YValues.Order = loNone
          Frame.InnerBrush.BackColor = clRed
          Frame.InnerBrush.Gradient.EndColor = clGray
          Frame.InnerBrush.Gradient.MidColor = clWhite
          Frame.InnerBrush.Gradient.StartColor = 4210752
          Frame.InnerBrush.Gradient.Visible = True
          Frame.MiddleBrush.BackColor = clYellow
          Frame.MiddleBrush.Gradient.EndColor = 8553090
          Frame.MiddleBrush.Gradient.MidColor = clWhite
          Frame.MiddleBrush.Gradient.StartColor = clGray
          Frame.MiddleBrush.Gradient.Visible = True
          Frame.OuterBrush.BackColor = clGreen
          Frame.OuterBrush.Gradient.EndColor = 4210752
          Frame.OuterBrush.Gradient.MidColor = clWhite
          Frame.OuterBrush.Gradient.StartColor = clSilver
          Frame.OuterBrush.Gradient.Visible = True
          Frame.Width = 4
          OtherSlice.Legend.Visible = False
          PiePen.Visible = False
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 1220
    Top = 16
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1042#1099#1073#1088#1072#1090#1100
        ShortCut = 16463
        OnClick = N2Click
      end
    end
    object N3: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N5: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
        ShortCut = 112
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        ShortCut = 113
        OnClick = N6Click
      end
    end
  end
end
