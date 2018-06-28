/********************************************************************************
** Form generated from reading UI file 'stimcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STIMCONTROL_H
#define UI_STIMCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stimcontrol
{
public:
    QAction *actionReset_Variables;
    QAction *actionLoadScene_1;
    QAction *actionLoadScene_2;
    QAction *actionLoadScene_3;
    QAction *actionLoadScene_4;
    QAction *actionEnglish;
    QAction *actionPt_Br;
    QAction *actionSaveScene_1;
    QAction *actionSaveScene_2;
    QAction *actionSaveScene_3;
    QAction *actionSaveScene_4;
    QAction *action25;
    QAction *action50;
    QAction *action75;
    QAction *action100;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QCheckBox *Check_Set_All;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Label_Pulsos;
    QSpinBox *Spin_Pulses;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_Stim1;
    QPushButton *Button_Stim2;
    QPushButton *Button_Stim3;
    QPushButton *Button_Stim4;
    QPushButton *Button_Stim5;
    QPushButton *Button_Stim6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Button_Stim7;
    QPushButton *Button_Stim8;
    QPushButton *Button_Stim9;
    QPushButton *Button_Stim10;
    QPushButton *Button_Stim11;
    QPushButton *Button_Stim12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *Label_PulseWidth_3;
    QSlider *Slider_PulseTrain;
    QSpinBox *Spin_PulseTrain;
    QLabel *Label_a;
    QLabel *Label_Hz_Value;
    QLabel *Label_Hz;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Label_PulseWidth;
    QSlider *Slider_PulseWidth;
    QSpinBox *Spin_PulseWidth;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Label_PulseWidth_2;
    QSlider *Slider_PulseWidthOff;
    QSpinBox *Spin_PulseWidthOff;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *Check_Channel1;
    QCheckBox *Check_Channel2;
    QCheckBox *Check_Channel3;
    QCheckBox *Check_Channel4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *Check_Channel5;
    QCheckBox *Check_Channel6;
    QCheckBox *Check_Channel7;
    QCheckBox *Check_Channel8;
    QCheckBox *Check_Activate;
    QLabel *Label_Repetitions_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_15;
    QLabel *Label_Time;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Label_Time_s;
    QSlider *Slider_Time_s;
    QSpinBox *Spin_Time_s;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Label_Time_ms;
    QSlider *Slider_Time_ms;
    QSpinBox *Spin_Time_ms;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Label_Ciclos;
    QSlider *Slider_Cycles;
    QSpinBox *Spin_Cycles;
    QLCDNumber *Lcd_Chronometer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QListView *LogBox;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *Button_Pause;
    QPushButton *Button_Start;
    QMenuBar *menuBar;
    QMenu *menuSave;
    QMenu *menuLoad;
    QMenu *menuLanguage;
    QMenu *menuBrightness;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stimcontrol)
    {
        if (stimcontrol->objectName().isEmpty())
            stimcontrol->setObjectName(QStringLiteral("stimcontrol"));
        stimcontrol->resize(1171, 653);
        QFont font;
        font.setPointSize(10);
        stimcontrol->setFont(font);
        stimcontrol->setAutoFillBackground(true);
        stimcontrol->setStyleSheet(QStringLiteral(""));
        actionReset_Variables = new QAction(stimcontrol);
        actionReset_Variables->setObjectName(QStringLiteral("actionReset_Variables"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset_Variables->setIcon(icon);
        QFont font1;
        font1.setPointSize(14);
        actionReset_Variables->setFont(font1);
        actionLoadScene_1 = new QAction(stimcontrol);
        actionLoadScene_1->setObjectName(QStringLiteral("actionLoadScene_1"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/blank.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadScene_1->setIcon(icon1);
        actionLoadScene_1->setFont(font1);
        actionLoadScene_2 = new QAction(stimcontrol);
        actionLoadScene_2->setObjectName(QStringLiteral("actionLoadScene_2"));
        actionLoadScene_2->setIcon(icon1);
        actionLoadScene_2->setFont(font1);
        actionLoadScene_3 = new QAction(stimcontrol);
        actionLoadScene_3->setObjectName(QStringLiteral("actionLoadScene_3"));
        actionLoadScene_3->setIcon(icon1);
        actionLoadScene_3->setFont(font1);
        actionLoadScene_4 = new QAction(stimcontrol);
        actionLoadScene_4->setObjectName(QStringLiteral("actionLoadScene_4"));
        actionLoadScene_4->setIcon(icon1);
        actionLoadScene_4->setFont(font1);
        actionEnglish = new QAction(stimcontrol);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/usa.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnglish->setIcon(icon2);
        actionEnglish->setFont(font1);
        actionPt_Br = new QAction(stimcontrol);
        actionPt_Br->setObjectName(QStringLiteral("actionPt_Br"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/brazil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPt_Br->setIcon(icon3);
        actionPt_Br->setFont(font1);
        actionSaveScene_1 = new QAction(stimcontrol);
        actionSaveScene_1->setObjectName(QStringLiteral("actionSaveScene_1"));
        actionSaveScene_1->setIcon(icon1);
        actionSaveScene_1->setFont(font1);
        actionSaveScene_2 = new QAction(stimcontrol);
        actionSaveScene_2->setObjectName(QStringLiteral("actionSaveScene_2"));
        actionSaveScene_2->setIcon(icon1);
        actionSaveScene_2->setFont(font1);
        actionSaveScene_3 = new QAction(stimcontrol);
        actionSaveScene_3->setObjectName(QStringLiteral("actionSaveScene_3"));
        actionSaveScene_3->setIcon(icon1);
        actionSaveScene_3->setFont(font1);
        actionSaveScene_4 = new QAction(stimcontrol);
        actionSaveScene_4->setObjectName(QStringLiteral("actionSaveScene_4"));
        actionSaveScene_4->setIcon(icon1);
        actionSaveScene_4->setFont(font1);
        action25 = new QAction(stimcontrol);
        action25->setObjectName(QStringLiteral("action25"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/brightness25.png"), QSize(), QIcon::Normal, QIcon::Off);
        action25->setIcon(icon4);
        action25->setFont(font1);
        action50 = new QAction(stimcontrol);
        action50->setObjectName(QStringLiteral("action50"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/brightness50.png"), QSize(), QIcon::Normal, QIcon::Off);
        action50->setIcon(icon5);
        action50->setFont(font1);
        action75 = new QAction(stimcontrol);
        action75->setObjectName(QStringLiteral("action75"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/brightness75.png"), QSize(), QIcon::Normal, QIcon::Off);
        action75->setIcon(icon6);
        action75->setFont(font1);
        action100 = new QAction(stimcontrol);
        action100->setObjectName(QStringLiteral("action100"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Images/brightness100.png"), QSize(), QIcon::Normal, QIcon::Off);
        action100->setIcon(icon7);
        action100->setFont(font1);
        centralWidget = new QWidget(stimcontrol);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 3);

        Check_Set_All = new QCheckBox(centralWidget);
        Check_Set_All->setObjectName(QStringLiteral("Check_Set_All"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Check_Set_All->sizePolicy().hasHeightForWidth());
        Check_Set_All->setSizePolicy(sizePolicy);
        Check_Set_All->setFont(font);
        Check_Set_All->setFocusPolicy(Qt::NoFocus);
        Check_Set_All->setAutoFillBackground(false);

        gridLayout->addWidget(Check_Set_All, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        Label_Pulsos = new QLabel(centralWidget);
        Label_Pulsos->setObjectName(QStringLiteral("Label_Pulsos"));
        Label_Pulsos->setFont(font);
        Label_Pulsos->setStyleSheet(QStringLiteral("background-color: transparent;"));

        horizontalLayout_9->addWidget(Label_Pulsos);

        Spin_Pulses = new QSpinBox(centralWidget);
        Spin_Pulses->setObjectName(QStringLiteral("Spin_Pulses"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Spin_Pulses->sizePolicy().hasHeightForWidth());
        Spin_Pulses->setSizePolicy(sizePolicy1);
        Spin_Pulses->setMinimumSize(QSize(0, 40));
        Spin_Pulses->setFont(font);
        Spin_Pulses->setFocusPolicy(Qt::NoFocus);
        Spin_Pulses->setMinimum(1);
        Spin_Pulses->setMaximum(20);

        horizontalLayout_9->addWidget(Spin_Pulses);


        gridLayout->addLayout(horizontalLayout_9, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Button_Stim1 = new QPushButton(centralWidget);
        Button_Stim1->setObjectName(QStringLiteral("Button_Stim1"));
        sizePolicy.setHeightForWidth(Button_Stim1->sizePolicy().hasHeightForWidth());
        Button_Stim1->setSizePolicy(sizePolicy);
        Button_Stim1->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setPointSize(9);
        Button_Stim1->setFont(font2);
        Button_Stim1->setFocusPolicy(Qt::NoFocus);
        Button_Stim1->setCheckable(true);
        Button_Stim1->setChecked(true);

        horizontalLayout->addWidget(Button_Stim1);

        Button_Stim2 = new QPushButton(centralWidget);
        Button_Stim2->setObjectName(QStringLiteral("Button_Stim2"));
        sizePolicy.setHeightForWidth(Button_Stim2->sizePolicy().hasHeightForWidth());
        Button_Stim2->setSizePolicy(sizePolicy);
        Button_Stim2->setMinimumSize(QSize(0, 30));
        Button_Stim2->setFont(font2);
        Button_Stim2->setFocusPolicy(Qt::NoFocus);
        Button_Stim2->setCheckable(true);

        horizontalLayout->addWidget(Button_Stim2);

        Button_Stim3 = new QPushButton(centralWidget);
        Button_Stim3->setObjectName(QStringLiteral("Button_Stim3"));
        sizePolicy.setHeightForWidth(Button_Stim3->sizePolicy().hasHeightForWidth());
        Button_Stim3->setSizePolicy(sizePolicy);
        Button_Stim3->setMinimumSize(QSize(0, 30));
        Button_Stim3->setFont(font2);
        Button_Stim3->setFocusPolicy(Qt::NoFocus);
        Button_Stim3->setCheckable(true);

        horizontalLayout->addWidget(Button_Stim3);

        Button_Stim4 = new QPushButton(centralWidget);
        Button_Stim4->setObjectName(QStringLiteral("Button_Stim4"));
        sizePolicy.setHeightForWidth(Button_Stim4->sizePolicy().hasHeightForWidth());
        Button_Stim4->setSizePolicy(sizePolicy);
        Button_Stim4->setMinimumSize(QSize(0, 30));
        Button_Stim4->setFont(font2);
        Button_Stim4->setFocusPolicy(Qt::NoFocus);
        Button_Stim4->setCheckable(true);

        horizontalLayout->addWidget(Button_Stim4);

        Button_Stim5 = new QPushButton(centralWidget);
        Button_Stim5->setObjectName(QStringLiteral("Button_Stim5"));
        sizePolicy.setHeightForWidth(Button_Stim5->sizePolicy().hasHeightForWidth());
        Button_Stim5->setSizePolicy(sizePolicy);
        Button_Stim5->setMinimumSize(QSize(0, 30));
        Button_Stim5->setFont(font2);
        Button_Stim5->setFocusPolicy(Qt::NoFocus);
        Button_Stim5->setCheckable(true);

        horizontalLayout->addWidget(Button_Stim5);

        Button_Stim6 = new QPushButton(centralWidget);
        Button_Stim6->setObjectName(QStringLiteral("Button_Stim6"));
        sizePolicy.setHeightForWidth(Button_Stim6->sizePolicy().hasHeightForWidth());
        Button_Stim6->setSizePolicy(sizePolicy);
        Button_Stim6->setMinimumSize(QSize(0, 30));
        Button_Stim6->setFont(font2);
        Button_Stim6->setFocusPolicy(Qt::NoFocus);
        Button_Stim6->setCheckable(true);

        horizontalLayout->addWidget(Button_Stim6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Button_Stim7 = new QPushButton(centralWidget);
        Button_Stim7->setObjectName(QStringLiteral("Button_Stim7"));
        sizePolicy.setHeightForWidth(Button_Stim7->sizePolicy().hasHeightForWidth());
        Button_Stim7->setSizePolicy(sizePolicy);
        Button_Stim7->setMinimumSize(QSize(0, 30));
        Button_Stim7->setFont(font2);
        Button_Stim7->setFocusPolicy(Qt::NoFocus);
        Button_Stim7->setCheckable(true);

        horizontalLayout_2->addWidget(Button_Stim7);

        Button_Stim8 = new QPushButton(centralWidget);
        Button_Stim8->setObjectName(QStringLiteral("Button_Stim8"));
        sizePolicy.setHeightForWidth(Button_Stim8->sizePolicy().hasHeightForWidth());
        Button_Stim8->setSizePolicy(sizePolicy);
        Button_Stim8->setMinimumSize(QSize(0, 30));
        Button_Stim8->setFont(font2);
        Button_Stim8->setFocusPolicy(Qt::NoFocus);
        Button_Stim8->setCheckable(true);

        horizontalLayout_2->addWidget(Button_Stim8);

        Button_Stim9 = new QPushButton(centralWidget);
        Button_Stim9->setObjectName(QStringLiteral("Button_Stim9"));
        sizePolicy.setHeightForWidth(Button_Stim9->sizePolicy().hasHeightForWidth());
        Button_Stim9->setSizePolicy(sizePolicy);
        Button_Stim9->setMinimumSize(QSize(0, 30));
        Button_Stim9->setFont(font2);
        Button_Stim9->setFocusPolicy(Qt::NoFocus);
        Button_Stim9->setCheckable(true);

        horizontalLayout_2->addWidget(Button_Stim9);

        Button_Stim10 = new QPushButton(centralWidget);
        Button_Stim10->setObjectName(QStringLiteral("Button_Stim10"));
        sizePolicy.setHeightForWidth(Button_Stim10->sizePolicy().hasHeightForWidth());
        Button_Stim10->setSizePolicy(sizePolicy);
        Button_Stim10->setMinimumSize(QSize(0, 30));
        Button_Stim10->setFont(font2);
        Button_Stim10->setFocusPolicy(Qt::NoFocus);
        Button_Stim10->setCheckable(true);

        horizontalLayout_2->addWidget(Button_Stim10);

        Button_Stim11 = new QPushButton(centralWidget);
        Button_Stim11->setObjectName(QStringLiteral("Button_Stim11"));
        sizePolicy.setHeightForWidth(Button_Stim11->sizePolicy().hasHeightForWidth());
        Button_Stim11->setSizePolicy(sizePolicy);
        Button_Stim11->setMinimumSize(QSize(0, 30));
        Button_Stim11->setFont(font2);
        Button_Stim11->setFocusPolicy(Qt::NoFocus);
        Button_Stim11->setCheckable(true);

        horizontalLayout_2->addWidget(Button_Stim11);

        Button_Stim12 = new QPushButton(centralWidget);
        Button_Stim12->setObjectName(QStringLiteral("Button_Stim12"));
        sizePolicy.setHeightForWidth(Button_Stim12->sizePolicy().hasHeightForWidth());
        Button_Stim12->setSizePolicy(sizePolicy);
        Button_Stim12->setMinimumSize(QSize(0, 30));
        Button_Stim12->setFont(font2);
        Button_Stim12->setFocusPolicy(Qt::NoFocus);
        Button_Stim12->setCheckable(true);

        horizontalLayout_2->addWidget(Button_Stim12);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        Label_PulseWidth_3 = new QLabel(centralWidget);
        Label_PulseWidth_3->setObjectName(QStringLiteral("Label_PulseWidth_3"));
        Label_PulseWidth_3->setFont(font2);

        horizontalLayout_10->addWidget(Label_PulseWidth_3);

        Slider_PulseTrain = new QSlider(centralWidget);
        Slider_PulseTrain->setObjectName(QStringLiteral("Slider_PulseTrain"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Slider_PulseTrain->sizePolicy().hasHeightForWidth());
        Slider_PulseTrain->setSizePolicy(sizePolicy2);
        Slider_PulseTrain->setMinimumSize(QSize(0, 0));
        Slider_PulseTrain->setFocusPolicy(Qt::NoFocus);
        Slider_PulseTrain->setMinimum(10);
        Slider_PulseTrain->setMaximum(16);
        Slider_PulseTrain->setPageStep(1);
        Slider_PulseTrain->setValue(10);
        Slider_PulseTrain->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(Slider_PulseTrain);

        Spin_PulseTrain = new QSpinBox(centralWidget);
        Spin_PulseTrain->setObjectName(QStringLiteral("Spin_PulseTrain"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Spin_PulseTrain->sizePolicy().hasHeightForWidth());
        Spin_PulseTrain->setSizePolicy(sizePolicy3);
        Spin_PulseTrain->setMinimumSize(QSize(0, 40));
        Spin_PulseTrain->setFont(font);
        Spin_PulseTrain->setFocusPolicy(Qt::NoFocus);
        Spin_PulseTrain->setMinimum(10);
        Spin_PulseTrain->setMaximum(40);
        Spin_PulseTrain->setSingleStep(5);
        Spin_PulseTrain->setValue(10);

        horizontalLayout_10->addWidget(Spin_PulseTrain);

        Label_a = new QLabel(centralWidget);
        Label_a->setObjectName(QStringLiteral("Label_a"));
        Label_a->setFont(font2);

        horizontalLayout_10->addWidget(Label_a);

        Label_Hz_Value = new QLabel(centralWidget);
        Label_Hz_Value->setObjectName(QStringLiteral("Label_Hz_Value"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Label_Hz_Value->sizePolicy().hasHeightForWidth());
        Label_Hz_Value->setSizePolicy(sizePolicy4);
        Label_Hz_Value->setMinimumSize(QSize(0, 5));
        Label_Hz_Value->setFont(font2);

        horizontalLayout_10->addWidget(Label_Hz_Value);

        Label_Hz = new QLabel(centralWidget);
        Label_Hz->setObjectName(QStringLiteral("Label_Hz"));
        Label_Hz->setFont(font2);

        horizontalLayout_10->addWidget(Label_Hz);


        gridLayout->addLayout(horizontalLayout_10, 2, 2, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        Label_PulseWidth = new QLabel(centralWidget);
        Label_PulseWidth->setObjectName(QStringLiteral("Label_PulseWidth"));
        Label_PulseWidth->setFont(font2);

        horizontalLayout_6->addWidget(Label_PulseWidth);

        Slider_PulseWidth = new QSlider(centralWidget);
        Slider_PulseWidth->setObjectName(QStringLiteral("Slider_PulseWidth"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Slider_PulseWidth->sizePolicy().hasHeightForWidth());
        Slider_PulseWidth->setSizePolicy(sizePolicy5);
        Slider_PulseWidth->setMouseTracking(false);
        Slider_PulseWidth->setFocusPolicy(Qt::NoFocus);
        Slider_PulseWidth->setMinimum(50);
        Slider_PulseWidth->setMaximum(80);
        Slider_PulseWidth->setPageStep(1);
        Slider_PulseWidth->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(Slider_PulseWidth);

        Spin_PulseWidth = new QSpinBox(centralWidget);
        Spin_PulseWidth->setObjectName(QStringLiteral("Spin_PulseWidth"));
        sizePolicy3.setHeightForWidth(Spin_PulseWidth->sizePolicy().hasHeightForWidth());
        Spin_PulseWidth->setSizePolicy(sizePolicy3);
        Spin_PulseWidth->setMinimumSize(QSize(0, 40));
        Spin_PulseWidth->setFont(font);
        Spin_PulseWidth->setFocusPolicy(Qt::NoFocus);
        Spin_PulseWidth->setMinimum(50);
        Spin_PulseWidth->setMaximum(200);
        Spin_PulseWidth->setSingleStep(5);

        horizontalLayout_6->addWidget(Spin_PulseWidth);


        horizontalLayout_16->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Label_PulseWidth_2 = new QLabel(centralWidget);
        Label_PulseWidth_2->setObjectName(QStringLiteral("Label_PulseWidth_2"));
        Label_PulseWidth_2->setFont(font2);

        horizontalLayout_7->addWidget(Label_PulseWidth_2);

        Slider_PulseWidthOff = new QSlider(centralWidget);
        Slider_PulseWidthOff->setObjectName(QStringLiteral("Slider_PulseWidthOff"));
        sizePolicy5.setHeightForWidth(Slider_PulseWidthOff->sizePolicy().hasHeightForWidth());
        Slider_PulseWidthOff->setSizePolicy(sizePolicy5);
        Slider_PulseWidthOff->setFocusPolicy(Qt::NoFocus);
        Slider_PulseWidthOff->setMinimum(50);
        Slider_PulseWidthOff->setMaximum(80);
        Slider_PulseWidthOff->setPageStep(1);
        Slider_PulseWidthOff->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(Slider_PulseWidthOff);

        Spin_PulseWidthOff = new QSpinBox(centralWidget);
        Spin_PulseWidthOff->setObjectName(QStringLiteral("Spin_PulseWidthOff"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(Spin_PulseWidthOff->sizePolicy().hasHeightForWidth());
        Spin_PulseWidthOff->setSizePolicy(sizePolicy6);
        Spin_PulseWidthOff->setMinimumSize(QSize(0, 40));
        Spin_PulseWidthOff->setFont(font);
        Spin_PulseWidthOff->setFocusPolicy(Qt::NoFocus);
        Spin_PulseWidthOff->setMinimum(50);
        Spin_PulseWidthOff->setMaximum(200);
        Spin_PulseWidthOff->setSingleStep(5);

        horizontalLayout_7->addWidget(Spin_PulseWidthOff);


        horizontalLayout_16->addLayout(horizontalLayout_7);


        gridLayout->addLayout(horizontalLayout_16, 4, 0, 1, 3);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 5, 0, 1, 3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy7);
        groupBox->setMinimumSize(QSize(500, 160));
        groupBox->setMaximumSize(QSize(550, 280));
        groupBox->setFont(font2);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"border: 1px solid gray;\n"
"border-radius 9px;\n"
"margin-top: 0.5em;\n"
"}\n"
""));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox->setFlat(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 561, 40));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Check_Channel1 = new QCheckBox(layoutWidget);
        Check_Channel1->setObjectName(QStringLiteral("Check_Channel1"));
        Check_Channel1->setEnabled(false);
        Check_Channel1->setFont(font);
        Check_Channel1->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(Check_Channel1);

        Check_Channel2 = new QCheckBox(layoutWidget);
        Check_Channel2->setObjectName(QStringLiteral("Check_Channel2"));
        Check_Channel2->setEnabled(false);
        Check_Channel2->setFont(font);
        Check_Channel2->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(Check_Channel2);

        Check_Channel3 = new QCheckBox(layoutWidget);
        Check_Channel3->setObjectName(QStringLiteral("Check_Channel3"));
        Check_Channel3->setEnabled(false);
        Check_Channel3->setFont(font);
        Check_Channel3->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(Check_Channel3);

        Check_Channel4 = new QCheckBox(layoutWidget);
        Check_Channel4->setObjectName(QStringLiteral("Check_Channel4"));
        Check_Channel4->setEnabled(false);
        Check_Channel4->setFont(font);
        Check_Channel4->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(Check_Channel4);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 70, 561, 40));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Check_Channel5 = new QCheckBox(layoutWidget_2);
        Check_Channel5->setObjectName(QStringLiteral("Check_Channel5"));
        Check_Channel5->setEnabled(false);
        Check_Channel5->setFont(font);
        Check_Channel5->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_4->addWidget(Check_Channel5);

        Check_Channel6 = new QCheckBox(layoutWidget_2);
        Check_Channel6->setObjectName(QStringLiteral("Check_Channel6"));
        Check_Channel6->setEnabled(false);
        Check_Channel6->setFont(font);
        Check_Channel6->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_4->addWidget(Check_Channel6);

        Check_Channel7 = new QCheckBox(layoutWidget_2);
        Check_Channel7->setObjectName(QStringLiteral("Check_Channel7"));
        Check_Channel7->setEnabled(false);
        Check_Channel7->setFont(font);
        Check_Channel7->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_4->addWidget(Check_Channel7);

        Check_Channel8 = new QCheckBox(layoutWidget_2);
        Check_Channel8->setObjectName(QStringLiteral("Check_Channel8"));
        Check_Channel8->setEnabled(false);
        Check_Channel8->setFont(font);
        Check_Channel8->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_4->addWidget(Check_Channel8);

        Check_Activate = new QCheckBox(groupBox);
        Check_Activate->setObjectName(QStringLiteral("Check_Activate"));
        Check_Activate->setGeometry(QRect(10, 10, 321, 41));
        Check_Activate->setFont(font);
        Check_Activate->setFocusPolicy(Qt::NoFocus);
        Label_Repetitions_2 = new QLabel(groupBox);
        Label_Repetitions_2->setObjectName(QStringLiteral("Label_Repetitions_2"));
        Label_Repetitions_2->setEnabled(false);
        Label_Repetitions_2->setGeometry(QRect(420, 151, 16, 17));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 120, 491, 44));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_15->setSpacing(4);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        Label_Time = new QLabel(layoutWidget1);
        Label_Time->setObjectName(QStringLiteral("Label_Time"));
        Label_Time->setEnabled(false);
        Label_Time->setFont(font);
        Label_Time->setMargin(0);

        horizontalLayout_15->addWidget(Label_Time);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        Label_Time_s = new QLabel(layoutWidget1);
        Label_Time_s->setObjectName(QStringLiteral("Label_Time_s"));
        Label_Time_s->setEnabled(false);
        Label_Time_s->setFont(font2);

        horizontalLayout_5->addWidget(Label_Time_s);

        Slider_Time_s = new QSlider(layoutWidget1);
        Slider_Time_s->setObjectName(QStringLiteral("Slider_Time_s"));
        Slider_Time_s->setEnabled(false);
        sizePolicy5.setHeightForWidth(Slider_Time_s->sizePolicy().hasHeightForWidth());
        Slider_Time_s->setSizePolicy(sizePolicy5);
        Slider_Time_s->setMinimumSize(QSize(30, 0));
        Slider_Time_s->setFont(font);
        Slider_Time_s->setFocusPolicy(Qt::NoFocus);
        Slider_Time_s->setMinimum(0);
        Slider_Time_s->setMaximum(9);
        Slider_Time_s->setPageStep(1);
        Slider_Time_s->setValue(0);
        Slider_Time_s->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Slider_Time_s);

        Spin_Time_s = new QSpinBox(layoutWidget1);
        Spin_Time_s->setObjectName(QStringLiteral("Spin_Time_s"));
        Spin_Time_s->setEnabled(false);
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(Spin_Time_s->sizePolicy().hasHeightForWidth());
        Spin_Time_s->setSizePolicy(sizePolicy8);
        Spin_Time_s->setMinimumSize(QSize(0, 40));
        Spin_Time_s->setMaximumSize(QSize(16777215, 40));
        Spin_Time_s->setFont(font);
        Spin_Time_s->setFocusPolicy(Qt::NoFocus);
        Spin_Time_s->setMaximum(9);

        horizontalLayout_5->addWidget(Spin_Time_s);


        horizontalLayout_15->addLayout(horizontalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        Label_Time_ms = new QLabel(layoutWidget1);
        Label_Time_ms->setObjectName(QStringLiteral("Label_Time_ms"));
        Label_Time_ms->setEnabled(false);
        Label_Time_ms->setFont(font2);

        horizontalLayout_11->addWidget(Label_Time_ms);

        Slider_Time_ms = new QSlider(layoutWidget1);
        Slider_Time_ms->setObjectName(QStringLiteral("Slider_Time_ms"));
        Slider_Time_ms->setEnabled(false);
        sizePolicy5.setHeightForWidth(Slider_Time_ms->sizePolicy().hasHeightForWidth());
        Slider_Time_ms->setSizePolicy(sizePolicy5);
        Slider_Time_ms->setMinimumSize(QSize(30, 0));
        Slider_Time_ms->setFont(font);
        Slider_Time_ms->setFocusPolicy(Qt::NoFocus);
        Slider_Time_ms->setMinimum(1);
        Slider_Time_ms->setMaximum(10);
        Slider_Time_ms->setPageStep(1);
        Slider_Time_ms->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(Slider_Time_ms);

        Spin_Time_ms = new QSpinBox(layoutWidget1);
        Spin_Time_ms->setObjectName(QStringLiteral("Spin_Time_ms"));
        Spin_Time_ms->setEnabled(false);
        sizePolicy8.setHeightForWidth(Spin_Time_ms->sizePolicy().hasHeightForWidth());
        Spin_Time_ms->setSizePolicy(sizePolicy8);
        Spin_Time_ms->setMinimumSize(QSize(0, 40));
        Spin_Time_ms->setMaximumSize(QSize(16777215, 40));
        Spin_Time_ms->setFont(font);
        Spin_Time_ms->setFocusPolicy(Qt::NoFocus);
        Spin_Time_ms->setMinimum(0);
        Spin_Time_ms->setMaximum(100);
        Spin_Time_ms->setValue(0);
        Spin_Time_ms->setDisplayIntegerBase(10);

        horizontalLayout_11->addWidget(Spin_Time_ms);


        horizontalLayout_15->addLayout(horizontalLayout_11);

        Label_Repetitions_2->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        layoutWidget->raise();
        Check_Activate->raise();

        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        Label_Ciclos = new QLabel(centralWidget);
        Label_Ciclos->setObjectName(QStringLiteral("Label_Ciclos"));
        Label_Ciclos->setFont(font);

        horizontalLayout_8->addWidget(Label_Ciclos);

        Slider_Cycles = new QSlider(centralWidget);
        Slider_Cycles->setObjectName(QStringLiteral("Slider_Cycles"));
        sizePolicy5.setHeightForWidth(Slider_Cycles->sizePolicy().hasHeightForWidth());
        Slider_Cycles->setSizePolicy(sizePolicy5);
        Slider_Cycles->setMinimum(1);
        Slider_Cycles->setMaximum(300);
        Slider_Cycles->setPageStep(1);
        Slider_Cycles->setSliderPosition(1);
        Slider_Cycles->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(Slider_Cycles);

        Spin_Cycles = new QSpinBox(centralWidget);
        Spin_Cycles->setObjectName(QStringLiteral("Spin_Cycles"));
        sizePolicy1.setHeightForWidth(Spin_Cycles->sizePolicy().hasHeightForWidth());
        Spin_Cycles->setSizePolicy(sizePolicy1);
        Spin_Cycles->setMinimumSize(QSize(60, 40));
        Spin_Cycles->setFocusPolicy(Qt::NoFocus);
        Spin_Cycles->setMinimum(1);
        Spin_Cycles->setMaximum(300);

        horizontalLayout_8->addWidget(Spin_Cycles);


        horizontalLayout_13->addLayout(horizontalLayout_8);

        Lcd_Chronometer = new QLCDNumber(centralWidget);
        Lcd_Chronometer->setObjectName(QStringLiteral("Lcd_Chronometer"));
        sizePolicy1.setHeightForWidth(Lcd_Chronometer->sizePolicy().hasHeightForWidth());
        Lcd_Chronometer->setSizePolicy(sizePolicy1);
        Lcd_Chronometer->setMinimumSize(QSize(100, 0));
        Lcd_Chronometer->setSmallDecimalPoint(false);

        horizontalLayout_13->addWidget(Lcd_Chronometer);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_14->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(2, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        LogBox = new QListView(centralWidget);
        LogBox->setObjectName(QStringLiteral("LogBox"));
        sizePolicy7.setHeightForWidth(LogBox->sizePolicy().hasHeightForWidth());
        LogBox->setSizePolicy(sizePolicy7);
        LogBox->setMaximumSize(QSize(250, 16777215));
        LogBox->setAutoFillBackground(false);
        LogBox->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(LogBox);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        Button_Pause = new QPushButton(centralWidget);
        Button_Pause->setObjectName(QStringLiteral("Button_Pause"));
        Button_Pause->setEnabled(false);
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(Button_Pause->sizePolicy().hasHeightForWidth());
        Button_Pause->setSizePolicy(sizePolicy9);
        Button_Pause->setMinimumSize(QSize(0, 40));
        Button_Pause->setMaximumSize(QSize(150, 16777215));
        Button_Pause->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_12->addWidget(Button_Pause);

        Button_Start = new QPushButton(centralWidget);
        Button_Start->setObjectName(QStringLiteral("Button_Start"));
        sizePolicy9.setHeightForWidth(Button_Start->sizePolicy().hasHeightForWidth());
        Button_Start->setSizePolicy(sizePolicy9);
        Button_Start->setMinimumSize(QSize(0, 40));
        Button_Start->setMaximumSize(QSize(150, 16777215));
        Button_Start->setFocusPolicy(Qt::TabFocus);

        horizontalLayout_12->addWidget(Button_Start);


        verticalLayout_2->addLayout(horizontalLayout_12);


        horizontalLayout_14->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_14, 6, 0, 1, 3);

        stimcontrol->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(stimcontrol);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1171, 89));
        QSizePolicy sizePolicy10(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy10);
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        menuBar->setFont(font3);
        menuBar->setStyleSheet(QLatin1String("background-color: rgb(0, 222, 255)\n"
""));
        menuBar->setDefaultUp(false);
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        menuSave->setFont(font4);
        menuLoad = new QMenu(menuBar);
        menuLoad->setObjectName(QStringLiteral("menuLoad"));
        menuLoad->setFont(font4);
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QStringLiteral("menuLanguage"));
        menuLanguage->setFont(font4);
        menuBrightness = new QMenu(menuBar);
        menuBrightness->setObjectName(QStringLiteral("menuBrightness"));
        stimcontrol->setMenuBar(menuBar);
        statusBar = new QStatusBar(stimcontrol);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QLatin1String("background-color: rgb(0, 222, 255)\n"
""));
        stimcontrol->setStatusBar(statusBar);

        menuBar->addAction(menuSave->menuAction());
        menuBar->addAction(menuLoad->menuAction());
        menuBar->addAction(menuBrightness->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuSave->addAction(actionSaveScene_1);
        menuSave->addAction(actionSaveScene_2);
        menuSave->addAction(actionSaveScene_3);
        menuSave->addAction(actionSaveScene_4);
        menuLoad->addAction(actionReset_Variables);
        menuLoad->addSeparator();
        menuLoad->addAction(actionLoadScene_1);
        menuLoad->addAction(actionLoadScene_2);
        menuLoad->addAction(actionLoadScene_3);
        menuLoad->addAction(actionLoadScene_4);
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionPt_Br);
        menuBrightness->addAction(action25);
        menuBrightness->addAction(action50);
        menuBrightness->addAction(action75);
        menuBrightness->addAction(action100);

        retranslateUi(stimcontrol);

        QMetaObject::connectSlotsByName(stimcontrol);
    } // setupUi

    void retranslateUi(QMainWindow *stimcontrol)
    {
        stimcontrol->setWindowTitle(QApplication::translate("stimcontrol", "stimcontrol", Q_NULLPTR));
        actionReset_Variables->setText(QApplication::translate("stimcontrol", "Reset Variables", Q_NULLPTR));
        actionLoadScene_1->setText(QApplication::translate("stimcontrol", "Scene 1", Q_NULLPTR));
        actionLoadScene_2->setText(QApplication::translate("stimcontrol", "Scene 2", Q_NULLPTR));
        actionLoadScene_3->setText(QApplication::translate("stimcontrol", "Scene 3", Q_NULLPTR));
        actionLoadScene_4->setText(QApplication::translate("stimcontrol", "Scene 4", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("stimcontrol", "English", Q_NULLPTR));
        actionPt_Br->setText(QApplication::translate("stimcontrol", "pt-Br", Q_NULLPTR));
        actionSaveScene_1->setText(QApplication::translate("stimcontrol", "Scene 1", Q_NULLPTR));
        actionSaveScene_2->setText(QApplication::translate("stimcontrol", "Scene 2", Q_NULLPTR));
        actionSaveScene_3->setText(QApplication::translate("stimcontrol", "Scene 3", Q_NULLPTR));
        actionSaveScene_4->setText(QApplication::translate("stimcontrol", "Scene 4", Q_NULLPTR));
        action25->setText(QApplication::translate("stimcontrol", "25%", Q_NULLPTR));
        action50->setText(QApplication::translate("stimcontrol", "50%", Q_NULLPTR));
        action75->setText(QApplication::translate("stimcontrol", "75%", Q_NULLPTR));
        action100->setText(QApplication::translate("stimcontrol", "100%", Q_NULLPTR));
        Check_Set_All->setText(QApplication::translate("stimcontrol", "Set for all", Q_NULLPTR));
        Label_Pulsos->setText(QApplication::translate("stimcontrol", "Number of Pulses:", Q_NULLPTR));
        Button_Stim1->setText(QApplication::translate("stimcontrol", "Stimulation 1", Q_NULLPTR));
        Button_Stim2->setText(QApplication::translate("stimcontrol", "Stimulation 2", Q_NULLPTR));
        Button_Stim3->setText(QApplication::translate("stimcontrol", "Stimulation 3", Q_NULLPTR));
        Button_Stim4->setText(QApplication::translate("stimcontrol", "Stimulation 4", Q_NULLPTR));
        Button_Stim5->setText(QApplication::translate("stimcontrol", "Stimulation 5", Q_NULLPTR));
        Button_Stim6->setText(QApplication::translate("stimcontrol", "Stimulation 6", Q_NULLPTR));
        Button_Stim7->setText(QApplication::translate("stimcontrol", "Stimulation 7", Q_NULLPTR));
        Button_Stim8->setText(QApplication::translate("stimcontrol", "Stimulation 8", Q_NULLPTR));
        Button_Stim9->setText(QApplication::translate("stimcontrol", "Stimulation 9", Q_NULLPTR));
        Button_Stim10->setText(QApplication::translate("stimcontrol", "Stimulation 10", Q_NULLPTR));
        Button_Stim11->setText(QApplication::translate("stimcontrol", "Stimulation 11", Q_NULLPTR));
        Button_Stim12->setText(QApplication::translate("stimcontrol", "Stimulation 12", Q_NULLPTR));
        Label_PulseWidth_3->setText(QApplication::translate("stimcontrol", "Signal Control Frequency [Hz]:", Q_NULLPTR));
        Label_a->setText(QApplication::translate("stimcontrol", "(", Q_NULLPTR));
        Label_Hz_Value->setText(QApplication::translate("stimcontrol", "100", Q_NULLPTR));
        Label_Hz->setText(QApplication::translate("stimcontrol", "ms )", Q_NULLPTR));
        Label_PulseWidth->setText(QApplication::translate("stimcontrol", "Pulse Width [us]:", Q_NULLPTR));
        Label_PulseWidth_2->setText(QApplication::translate("stimcontrol", "Width between Pulses [us]:", Q_NULLPTR));
        groupBox->setTitle(QString());
        Check_Channel1->setText(QApplication::translate("stimcontrol", "Channel 1", Q_NULLPTR));
        Check_Channel2->setText(QApplication::translate("stimcontrol", "Channel 2", Q_NULLPTR));
        Check_Channel3->setText(QApplication::translate("stimcontrol", "Channel 3", Q_NULLPTR));
        Check_Channel4->setText(QApplication::translate("stimcontrol", "Channel 4", Q_NULLPTR));
        Check_Channel5->setText(QApplication::translate("stimcontrol", "Channel 5", Q_NULLPTR));
        Check_Channel6->setText(QApplication::translate("stimcontrol", "Channel 6", Q_NULLPTR));
        Check_Channel7->setText(QApplication::translate("stimcontrol", "Channel 7", Q_NULLPTR));
        Check_Channel8->setText(QApplication::translate("stimcontrol", "Channel 8", Q_NULLPTR));
        Check_Activate->setText(QApplication::translate("stimcontrol", "Activate Stimulation", Q_NULLPTR));
        Label_Repetitions_2->setText(QString());
        Label_Time->setText(QApplication::translate("stimcontrol", "Duration:", Q_NULLPTR));
        Label_Time_s->setText(QApplication::translate("stimcontrol", "[s]", Q_NULLPTR));
        Spin_Time_s->setSuffix(QApplication::translate("stimcontrol", ".000", Q_NULLPTR));
        Label_Time_ms->setText(QApplication::translate("stimcontrol", "[ms]", Q_NULLPTR));
        Spin_Time_ms->setSuffix(QString());
        Spin_Time_ms->setPrefix(QString());
        Label_Ciclos->setText(QApplication::translate("stimcontrol", "Number of Cycles:", Q_NULLPTR));
        Button_Pause->setText(QApplication::translate("stimcontrol", "Pause", Q_NULLPTR));
        Button_Start->setText(QApplication::translate("stimcontrol", "Start", Q_NULLPTR));
        menuSave->setTitle(QApplication::translate("stimcontrol", "Save", Q_NULLPTR));
        menuLoad->setTitle(QApplication::translate("stimcontrol", "Load", Q_NULLPTR));
        menuLanguage->setTitle(QApplication::translate("stimcontrol", "Language", Q_NULLPTR));
        menuBrightness->setTitle(QApplication::translate("stimcontrol", "\n"
"Brightness", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stimcontrol: public Ui_stimcontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STIMCONTROL_H
