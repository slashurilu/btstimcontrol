#include "stimcontrol.h"
#include "ui_stimcontrol.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QMap>
#include <QDebug>
#include <QTimer>
#include <QShortcut>
#include <QElapsedTimer>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QSizePolicy>
#include <QTextStream>
#include <QProgressBar>
#include <pigpio.h>

//BLUETOOTH
#include <iostream>
#include <exception>
#include <vector>
#include <memory>
#include <ctime>
#include "DeviceINQ.h"
#include "Enums.h"
#include "BluetoothException.h"

stimcontrol::stimcontrol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stimcontrol)
{
    ui->setupUi(this);
    ui->menuBar->setVisible(true);
    StatusLabel = new QLabel(this);
    NameLabel = new QLabel(this);
    StatusBar = new QProgressBar(this);
    //channels_message[12] = new QString (this);
    //set background
    QPixmap bkgnd(":/Images/backwhite.png");
       bkgnd = bkgnd.scaled(800, 480, Qt::IgnoreAspectRatio);
      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      this->setPalette(palette);
    //*****************
    ui->statusBar->addPermanentWidget(StatusLabel,1);
    ui->statusBar->addPermanentWidget(StatusBar,1);
    ui->statusBar->addPermanentWidget(NameLabel,0);
    StatusLabel->setStyleSheet("QLabel {color : green; font: 9pt}");
    StatusLabel->setText(" QSTIMBERRY CONTROLLER                 /                   VERSION 1.2.1");
    NameLabel->setText(" LABCIBER - EESC/USP");
    StatusBar->setRange(0,9900);
    StatusBar->setTextVisible(false);
    StatusBar->setValue(0);
    StatusBar->setMaximumWidth(120);
    // initialize params
    if (gpioInitialise() >= 0){
    for(int i=0; i<8; i++)
        gpioSetMode(channels[i], PI_OUTPUT);
    //gpioSetAlertFunc(2, displayChange);
    }
    gpioSetMode(pinHigh, PI_OUTPUT);
    gpioWrite(pinHigh,1);
    stim_saved_id = 0;
    start_index = false;
    pause_index = false;
    stim_flag = -1;
    //chronometer counter
    stopwatch_increment = 0;

    //set_all_flag
    set_all_flag = false;

    //load language
    load_language();

    //set chronometer initial value
    ui->Lcd_Chronometer->display("00:00");

    //Timer Interval: set and connection
    signal_interval=new QTimer(this);
    connect(signal_interval, SIGNAL(timeout()), this, SLOT(Send_Control_Signal()));

    //Chronometer: set and connection
    chronometer=new QTimer(this);
    connect(chronometer, SIGNAL(timeout()), this, SLOT(Chronometer_Increment()));

    //setting the button groupsactionShut_Down
    //only one button in the group can be checked at a time
    stimode_group = new QButtonGroup();
    stimode_group->addButton(ui->Button_Stim1, 0);
    stimode_group->addButton(ui->Button_Stim2, 1);
    stimode_group->addButton(ui->Button_Stim3, 2);
    stimode_group->addButton(ui->Button_Stim4, 3);
    stimode_group->addButton(ui->Button_Stim5, 4);
    stimode_group->addButton(ui->Button_Stim6, 5);
    stimode_group->addButton(ui->Button_Stim7, 6);
    stimode_group->addButton(ui->Button_Stim8, 7);
    stimode_group->addButton(ui->Button_Stim9, 8);
    stimode_group->addButton(ui->Button_Stim10, 9);
    stimode_group->addButton(ui->Button_Stim11, 10);
    stimode_group->addButton(ui->Button_Stim12, 11);
    channel_group[ui->Check_Channel1]=0;
    channel_group[ui->Check_Channel2]=1;
    channel_group[ui->Check_Channel3]=2;
    channel_group[ui->Check_Channel4]=3;
    channel_group[ui->Check_Channel5]=4;
    channel_group[ui->Check_Channel6]=5;
    channel_group[ui->Check_Channel7]=6;
    channel_group[ui->Check_Channel8]=7;

    //set button color
    for(int i=0 ; i<12; i++)
        stimode_group->button(i)->setStyleSheet("* { color: red }");
    ui->Button_Start->setStyleSheet("* { color: blue }");


    //********************************* CONNECTIONS ******************************************
    //Enable Stimulation Parameters when Activate button is toggled.

    //BLUETOOTH CONNECTION
    try
        {
		unique_ptr<DeviceINQ> inq(DeviceINQ::Create());
		vector<device> devices = inq->Inquire();

//		for (const auto& d : devices)
//		{
//			cout << d.name << " " << d.address << endl;
//		}

//		cout << endl << "done, found " << devices.size() << " device(s)" << endl; //INITIALIZATION

                BTSerialPortBinding::Create(devices.at(0).address, 1); // MATCHING => 1 IS THE SERIAL PORT

		BTSerialPortBinding::Connect(); // CONNECT WITH THE DEVICE
                }
        catch (const BluetoothException& e)
            {
                cout << e.what() << endl;
            }

	//END

    for(int i=0 ; i<8; i++){
        connect(ui->Check_Activate, SIGNAL(toggled(bool)),channel_group.key(i), SLOT(setEnabled(bool)));
    }
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Slider_Time_s, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Spin_Time_s, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Label_Time_s, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Slider_Time_ms, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Spin_Time_ms, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Label_Time_ms, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),ui->Label_Time, SLOT(setEnabled(bool)));
    connect(ui->Check_Activate, SIGNAL(toggled(bool)),this, SLOT(SetStimColor(bool)));

    //Creat hotkey for system setting
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(actionClose()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_R), this, SLOT(actionReboot()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this, SLOT(actionShut_Down()));


    //Connect the Spin box with the Slide Bars
    connect(ui->Slider_PulseWidth,SIGNAL(valueChanged(int)),this,SLOT(SliderToSpin_PulseWidth(int)));
    connect(ui->Spin_PulseWidth,SIGNAL(valueChanged(int)),this,SLOT(SpinToSlider_PulseWidth(int)));

    connect(ui->Slider_PulseWidthOff,SIGNAL(valueChanged(int)),this,SLctime>OT(SliderToSpin_PulseWidthOff(int)));
    connect(ui->Spin_PulseWidthOff,SIGNAL(valueChanged(int)),this,SLOT(SpinToSlider_PulseWidthOff(int)));

    connect(ui->Slider_PulseTrain,SIGNAL(valueChanged(int)),this,SLOT(SliderToSpin_PulseTrain(int)));
    connect(ui->Spin_PulseTrain,SIGNAL(valueChanged(int)),this,SLOT(SpinToSlider_PulseTrain(int)));

    connect(ui->Slider_Time_s,SIGNAL(valueChanged(int)),ui->Spin_Time_s,SLOT(setValue(int)));
    connect(ui->Spin_Time_s,SIGNAL(valueChanged(int)),ui->Slider_Time_s,SLOT(setValue(int)));

    connect(ui->Slider_Time_ms,SIGNAL(valueChanged(int)),this,SLOT(SliderToSpin_Time_ms(int)));
    connect(ui->Spin_Time_ms,SIGNAL(valueChanged(int)),this,SLOT(SpinToSlider_Time_ms(int)));

    connect(ui->Slider_Cycles,SIGNAL(valueChanged(int)),this,SLOT(SliderToSpin_Cycles(int)));
    connect(ui->Spin_Cycles,SIGNAL(valueChanged(int)),this,SLOT(SpinToSlider_Cycles(int)));


    //Save and load the Stimulation Parameters
    connect(stimode_group, SIGNAL(buttonReleased(int)), this, SLOT(StimButtonPressed(int)));

    //connect Seconds and Frequency bars to Set_msbar_Parameters
    connect(ui->Spin_Time_s,SIGNAL(valueChanged(int)),this,SLOT(Set_msbar_Parameters()));
    connect(ui->Spin_PulseTrain,SIGNAL(valueChanged(int)),this,SLOT(Set_msbar_Parameters()));

    //connect Set for all button to SetAllParameters
    connect(ui->Check_Set_All, SIGNAL(toggled(bool)),this,SLOT(SetAllParameters(bool)));

    //Call the function to set the parameters of Slider and Spin ms
    Set_msbar_Parameters();
    ui->Slider_Time_ms->setValue(ui->Slider_Time_ms->minimum());
    on_actionReset_Variables_triggered();
    //Connect GPIO to Interrupt
}
//**********************************************************************************************
//*********************************** SLOTS AND FUNCTIONS **************************************
//**********************************************************************************************

//****************************************** MAIN SLOTS ****************************************

/*SLOT called when a stim button is pressed:
 * This function saves the value of the last clicked stim button on its vector
 * and loads the saved values of the current clicked stim button
*/
void stimcontrol::StimButtonPressed(int stim_id)
{
    //Save/Load N_pulse, PulseWidth, PulseWidthOff, PulseTrain values
    //if Set for All button is not checked
    if(set_all_flag==false){
        parameters[stim_saved_id][11] = ui->Spin_Pulses->value();
        parameters[stim_saved_id][12] = ui->Spin_PulseWidth->value();
        parameters[stim_saved_id][13] = ui->Spin_PulseWidthOff->value();
        parameters[stim_saved_id][14] = ui->Spin_PulseTrain->value();
        ui->Spin_Pulses->setValue((int)parameters[stim_id][11]);
        ui->Spin_PulseWidth->setValue((int)parameters[stim_id][12]);
        ui->Spin_PulseWidthOff->setValue((int)parameters[stim_id][13]);
        ui->Spin_PulseTrain->setValue((int)parameters[stim_id][14]);
    }
    int i;
    //Save/Load Channels and Duration value
    for(i=0 ; i<8; i++){
        if(channel_group.key(i)->isChecked()){
            parameters[stim_saved_id][i]=i+1;
            if(parameters[stim_id][i]==0)
                channel_group.key(i)->setChecked(false);
        }
        else{
            parameters[stim_saved_id][i]=0;
            if(parameters[stim_id][i]!=0)
                channel_group.key(i)->setChecked(true);
        }
    }
    //Save seconds + miliseconds duration
    parameters[stim_saved_id][8]=ui->Spin_Time_s->value();
    parameters[stim_saved_id][9]=ui->Spin_Time_ms->value();
    //Load seconds + miliseconds duration
    ui->Spin_Time_s->setValue(parameters[stim_id][8]);
    ui->Spin_Time_ms->setValue(parameters[stim_id][9]);
    //Tick/Untick Activate Button
    if(ui->Check_Activate->isChecked()){
        parameters[stim_saved_id][10] = 1;
        if(parameters[stim_id][10]==0)
            ui->Check_Activate->setChecked(false);
    }
    else{
        parameters[stim_saved_id][10] = 0;
        if(parameters[stim_id][10]==1)
            ui->Check_Activate->setChecked(true);
    }

    //save the last id value
    stim_saved_id = stim_id;

}
void stimcontrol::SetAllParameters(bool isActivated)
{
    if(isActivated){
        set_all_flag = true;
        set_all_parameters[0] = ui->Spin_Pulses->value();
        set_all_parameters[1] = ui->Spin_PulseWidth->value();
        set_all_parameters[2] = ui->Spin_PulseWidthOff->value();
        set_all_parameters[3] = ui->Spin_PulseTrain->value();
        connect(ui->Spin_Pulses,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
        connect(ui->Spin_PulseWidth,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
        connect(ui->Spin_PulseWidthOff,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
        connect(ui->Spin_PulseTrain,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
    }

    else{
        set_all_flag = false;
        disconnect(ui->Spin_Pulses,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
        disconnect(ui->Spin_PulseWidth,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
        disconnect(ui->Spin_PulseWidthOff,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
        disconnect(ui->Spin_PulseTrain,SIGNAL(valueChanged(int)),this,SLOT(Update_All_Parameters()));
    }
}
void stimcontrol::Update_All_Parameters()
{            //Visual indications!! ARRRRUUUUMARRRRRR
    //Clicar e tals
    set_all_parameters[0] = ui->Spin_Pulses->value();
    set_all_parameters[1] = ui->Spin_PulseWidth->value();
    set_all_parameters[2] = ui->Spin_PulseWidthOff->value();
    set_all_parameters[3] = ui->Spin_PulseTrain->value();
}


//function - Save the clicked stim variables value before starting stimulation process
void stimcontrol::Save_LastValues()
{
    int stim_id = stimode_group->checkedId();
    int i;
    //Save Channels and Duration value
    for(i=0 ; i<8; i++){
        if(channel_group.key(i)->isChecked())
            parameters[stim_id][i]=i+1;
        else
            parameters[stim_id][i]=0;
    }
    parameters[stim_id][8]=ui->Spin_Time_s->value();
    parameters[stim_id][9]=ui->Spin_Time_ms->value();
    if(ui->Check_Activate->isChecked())
        parameters[stim_id][10] = 1;
    else
        parameters[stim_saved_id][10] = 0;

     //Save N_pulse, PulseWidth, PulseWidthOff, PulseTrain values
    if(set_all_flag){
        set_all_parameters[0] = ui->Spin_Pulses->value();
        set_all_parameters[1] = ui->Spin_PulseWidth->value();
        set_all_parameters[2] = ui->Spin_PulseWidthOff->value();
        set_all_parameters[3] = ui->Spin_PulseTrain->value();
        }
    else{
        parameters[stim_id][11] = ui->Spin_Pulses->value();
        parameters[stim_id][12] = ui->Spin_PulseWidth->value();
        parameters[stim_id][13] = ui->Spin_PulseWidthOff->value();
        parameters[stim_id][14] = ui->Spin_PulseTrain->value();


    }
}

//**********************************************************************************

void stimcontrol::SetStimColor(bool isActivated)
{
    if(isActivated)
        stimode_group->checkedButton()->setStyleSheet("* { color: green }");
    else
        stimode_group->checkedButton()->setStyleSheet("* { color: red }");
}

//************************** SLIDERS/SPIN SLOTS ************************************
void stimcontrol::SliderToSpin_PulseWidth(int x_value)
{
    ui->Spin_PulseWidth->setValue((x_value-50)*5 + 50);
}

void stimcontrol::SpinToSlider_PulseWidth(int x_value)
{
    ui->Slider_PulseWidth->setValue((x_value-50)/5 + 50);
}


void stimcontrol::SliderToSpin_PulseWidthOff(int x_value)
{
    ui->Spin_PulseWidthOff->setValue((x_value-50)*5 + 50);
}

void stimcontrol::SpinToSlider_PulseWidthOff(int x_value)
{

    ui->Slider_PulseWidthOff->setValue((x_value-50)/5 + 50);
}

void stimcontrol::SliderToSpin_PulseTrain(int x_value)
{
    ui->Spin_PulseTrain->setValue((x_value-10)*5 + 10);
}

void stimcontrol::SpinToSlider_PulseTrain(int x_value)
{
    double interval;
    interval = 10000/x_value;
    interval = interval/10 + 0.5;
    if (interval < 100){
        ui->Label_a->setText("(  ");
    }else {
        ui->Label_a->setText("(");
    }
    ui->Label_Hz_Value->setNum((int)interval);
    ui->Slider_PulseTrain->setValue((x_value-10)/5 + 10);
}


void stimcontrol::SliderToSpin_Time_ms(int x_value)
{
    ui->Spin_Time_ms->setValue((x_value-ui->Slider_Time_ms->minimum())*ui->Spin_Time_ms->singleStep() + ui->Spin_Time_ms->minimum());
    if(ui->Spin_Time_ms->value()==0)
        ui->Spin_Time_ms->setPrefix("0.00");
    else if(ui->Spin_Time_ms->value()<100)
        ui->Spin_Time_ms->setPrefix("0.0");
    else if (ui->Spin_Time_ms->value()<1000)
        ui->Spin_Time_ms->setPrefix("0.");
    else
        ui->Spin_Time_ms->setPrefix("");
}

void stimcontrol::SpinToSlider_Time_ms(int x_value)
{
    ui->Slider_Time_ms->setValue((x_value-ui->Slider_Time_ms->minimum())/ui->Spin_Time_ms->singleStep() + ui->Slider_Time_ms->minimum());
    if(ui->Spin_Time_ms->value()==0)
        ui->Spin_Time_ms->setPrefix("0.00");
    else if(ui->Spin_Time_ms->value()<100)
        ui->Spin_Time_ms->setPrefix("0.0");
    else if (ui->Spin_Time_ms->value()<1000)
        ui->Spin_Time_ms->setPrefix("0.");
    else
        ui->Spin_Time_ms->setPrefix("");
}

void stimcontrol::SliderToSpin_Cycles(int x_value)
{
    ui->Spin_Cycles->setValue(x_value);
}

void stimcontrol::SpinToSlider_Cycles(int x_value)
{
    ui->Slider_Cycles->setValue(x_value);
}

//***************************Set ms Slider Parameters*******************************
void stimcontrol::Set_msbar_Parameters()
{
    double interval;          //Calculate the signal interval
    //Convert the signal frequency from the active stimulation to time Interval (ms)
    interval = 10000/ui->Spin_PulseTrain->value();
    interval = interval/10 + 0.5;    //rounds the number to the closer integer
    int step_value;
    //Set a step value for each frequency level
    switch((int)interval){
        case 25:
            step_value = 4*(int)interval; break;
        case 29:
            step_value = 4*(int)interval; break;
        case 33:
            step_value = 3*(int)interval; break;
        case 40:
            step_value = 3*(int)interval; break;
        case 50:
            step_value = 2*(int)interval; break;
        case 67:
            step_value = 2*(int)interval; break;
        case 100:
            step_value = 1*(int)interval; break;
    }

    int seconds = 1000*ui->Spin_Time_s->value();
    //This result ensures that the min duration value is divided by the interval
    int min_value = seconds%step_value;
    //This result ensures that the max duration value is divided by the interval
    int max_value = (999-min_value)/step_value;
    max_value = max_value*step_value + min_value;
    //Ensures that the new value is valid
    int slider_value = ui->Slider_Time_ms->value() - ui->Slider_Time_ms->minimum();
    if (slider_value>((max_value-min_value)/step_value + min_value))
        slider_value = ((max_value-min_value)/step_value + min_value);
    //set the parameters
    ui->Spin_Time_ms->setSingleStep(step_value);
    ui->Spin_Time_ms->setMinimum(min_value);
    ui->Spin_Time_ms->setMaximum(max_value);
    ui->Slider_Time_ms->setMinimum(min_value);
    ui->Slider_Time_ms->setMaximum((max_value-min_value)/step_value + min_value);
    ui->Slider_Time_ms->setValue(slider_value + min_value);
}



//**********************************************************************************
//*********************** STIMULATION PROCESS BUTTONS ******************************
//**********************************************************************************
void stimcontrol::on_Button_Start_clicked()
{

    //***START BUTTON CLICKED******
    if(start_index==false){
        //Reset chronometer
        stopwatch_increment = 0;
        duration_increment = 0;
        duration_decrement = 0;
        //save last stimulation parameters
        Save_LastValues();
        //disable stim buttons: to avoid user mistakes
        bool SetAll_State = ui->Check_Set_All->isChecked();
        if(SetAll_State == false)
           Enable_SignalSpinSliders(false);
        Enable_Stimbuttons(false);
        ui->groupBox->setEnabled(false);
        //disable menubar and spin cycles
        ui->menuBar->setEnabled(false);
        ui->Spin_Cycles->setEnabled(false);
        //Change "Start" to "Stop"
        if(is_english)
            ui->Button_Start->setText("Stop");
        else
            ui->Button_Start->setText("Parar");
        ui->Button_Start->setStyleSheet("* { background: red ; color: black }"); //rgb(160, 230, 160)
        //Enable pause button
        ui->Button_Pause->setEnabled(true);
        //initialize the stim_parameter matrix with zeros
        for (int i = 0; i<12; i++){
             for (int j = 0; j<16; j++){
                 stim_parameters[i][j]=0;
             }
        }
        //Move tha data from the matrix parameter[][] to the matrix stim_parameters[][]
        int zero_stim = 0;     //init count -> Count of non-zero elements
        int zero_ch = 0;
        //interact over the parameters[12] vector. This process will order the active stimulations
        for (int i = 0; i<12; i++)
        {
            if (parameters[i][10]==1){ //check the activate_flag
                for (int j = 0; j<15; j++)
                    stim_parameters[zero_stim][j] = parameters[i][j];
                stim_parameters[zero_stim][15] = i+1;
                zero_stim++;
            }
        }
        stim_end = zero_stim; //It will be used to not spend unecessary time while stimulating
        stim_init = 0;
        stim_cycles = ui->Spin_Cycles->value();
        //Do the same process to order the active channels on the active stimulations
        for (int i = 0; i<zero_stim; i++)
        {
            zero_ch = 0;
            for(int j = 0; j<8; j++){
                if(stim_parameters[i][j]!=0){ //check the active channels
                    stim_parameters[i][zero_ch]=stim_parameters[i][j];
                    zero_ch++;
                }
            }
            //set 0 for the remaning channel slots
            while (zero_ch<8)
                stim_parameters[i][zero_ch++]=0;
        }

        //=*=*=*=*=*=*=*= BLUETOOTH - SENDING DATA =*=*=*=*=*=*=*=*=

        BTSerialPortBinding::Write(&stim_parameters, sizeof(stim_parameters));

        //set Messages
        //StatusLabel->setText(" Stim: 1 / Ch: 1,2,3,4,5,6,7,8 / Freq: 20 Hz / _|¯|_: 30us /  ¯|_|¯: 40us / Pulses: 5.");
        for (int i= 0; i <zero_stim; i++)
        {
            channels_message[i] = "";
            channels_message[i].append(QString(" Stim: %1 / D:%2ms / Ch:").arg(stim_parameters[i][15]).arg(1000*stim_parameters[i][8] + stim_parameters[i][9]));
            for(int j = 0; j<8; j++){
                if(stim_parameters[i][j]!=0){ //check the active channels
                  channels_message[i].append(QString( " %1," ).arg(stim_parameters[i][j]));
                }
            }
            if(set_all_flag) {
                channels_message[i].replace(channels_message[i].lastIndexOf(","),1, ".");
            } else {
                channels_message[i].replace(channels_message[i].lastIndexOf(","),1, " ");
                channels_message[i].append(QString( "/ Freq: %1Hz / _|¯|_: %2us /  ¯|_|¯: %3us / Pulses: %4." ).arg(stim_parameters[i][14]).arg(stim_parameters[i][12]).arg(stim_parameters[i][13]).arg(stim_parameters[i][11]));
            }
        }

        //Set Stimulation flags
        this->start_index = true;
        //Chronometer Start
        chronometer->start(1000);
        //Elapsed Timer start
        elapsed_time.start();

        //***START STIMULATION***
        signal_interval->start();

    }
    //***STOP BUTTON CLICKED******
    else{
        start_index = false;
        signal_interval->stop();
        chronometer->stop();
        elapsed_time.invalidate();
        //Reset the Pause button
        pause_index = false;
        if(is_english)
            ui->Button_Pause->setText("Pause");
        else
            ui->Button_Pause->setText("Pausar");
        //Disable pause button
        ui->Button_Pause->setEnabled(false);
        if(is_english){
            ui->Button_Start->setText("Start");
            StatusLabel->setText(" STIMULATION FINISHED!");
        }
        else{
            ui->Button_Start->setText("Começar");
            StatusLabel->setText(" ESTIMULAÇÃO FINALIZADA!");
        }
        ui->Button_Start->setStyleSheet("* { color: blue }");
        StatusBar->setValue(0);
        Enable_Stimbuttons(true);
        Enable_SignalSpinSliders(true);
        ui->groupBox->setEnabled(true);
        //enable menubar and spin cycles
        ui->menuBar->setEnabled(true);
        ui->Spin_Cycles->setEnabled(true);
    }
}

//Function called when the signal_interval timeout
void stimcontrol::Send_Control_Signal()
{


    //STIMULATE
    if(stim_init<stim_end){#include <iostream>
        #include <exception>
        #include <vector>
        #include <memory>
        #include <ctime>
        #include "DeviceINQ.h"
        #include "Enums.h"
        #include "BluetoothException.h"
        int interval, duration;          //Calculate the signal interval and duration
        StatusLabel->setText(channels_message[stim_init]);
        if(set_all_flag==false){
            //Convert the signal frequency from the active stimulation to time Interval (ms)
            interval = 10000/stim_parameters[stim_init][14];
            interval = int(interval/10 + 0.5);    //rounds the number to the closer integer
            signal_interval->setInterval(interval);
            duration = 1000*stim_parameters[stim_init][8] + stim_parameters[stim_init][9] - duration_decrement;
        }
        else{
            //Convert the signal frequency from the active stimulation to time Interval (ms)
            interval = 10000/set_all_parameters[3];
            interval = (interval/10 + 0.5);    //rounds the number to the closer integer
            signal_interval->setInterval(interval);
            //real duration!! PS: The program will not show the real duration
            duration = 1000*stim_parameters[stim_init][8] + stim_parameters[stim_init][9] - duration_decrement;
            duration = duration/interval;
            duration = duration*interval;
        }
        //SEND THE SIGNALS TO THE PINS
        if(elapsed_time.elapsed()<duration){
           //Stim indication
            StatusBar->setRange(0,duration + duration_increment);
            StatusBar->setValue(elapsed_time.elapsed() + duration_increment);
            //*STIMULATION MODE*: different control signals for each stimulation
            if(set_all_flag==false){
                    int i;
                    for (i=0; i<stim_parameters[stim_init][11]; i++){
                        int j = 0;
                        while((stim_parameters[stim_init][j]>0)&&(j<8)){
                           gpioWrite(channels[(int)(stim_parameters[stim_init][j])-1], 1);
                            j++;
                        }
                        if(stim_parameters[stim_init][12] > 100) {
                            gpioDelay(100);
                            gpioDelay(stim_parameters[stim_init][12]-100);
                        } else {
                            gpioDelay(stim_parameters[stim_init][12]);
                        }
                        j = 0;
                        while((stim_parameters[stim_init][j]>0)&&(j<8)){
                            gpioWrite(channels[(int)(stim_parameters[stim_init][j])-1], 0);
                            j++;
                        }
                        if(i==(stim_parameters[stim_init][11]-1)) // Avoid last Low Width pulse
                            break;
                        else {
                            if(stim_parameters[stim_init][13] > 100) {
                                gpioDelay(100);
                                gpioDelay(stim_parameters[stim_init][12]-100);
                             } else {
                                gpioDelay(stim_parameters[stim_init][12]);
                            }
                        }
                    }

            }
            //*STIMULATION MODE*: same control signal for each stimulation
            else{

                    int i;
                    for (i=0; i<set_all_parameters[0]; i++){
                        int j = 0;
                        while((stim_parameters[stim_init][j]>0)&&(j<8)){
                            gpioWrite(channels[(int)(stim_parameters[stim_init][j])-1], 1);
                            j++;
                        }
                        if(set_all_parameters[1] > 100) {
                            gpioDelay(100);
                            gpioDelay(set_all_parameters[1]-100);
                        } else {
                            gpioDelay(set_all_parameters[1]);
                        }
                        j = 0;
                        while((stim_parameters[stim_init][j]>0)&&(j<8)){
                            gpioWrite(channels[(int)(stim_parameters[stim_init][j])-1], 0);
                            j++;
                        }
                        if(i==(set_all_parameters[0]-1)) // Avoid last Low Width pulse
                            break;
                        else {
                            if(set_all_parameters[2] > 100) {
                                gpioDelay(100);
                                gpioDelay(set_all_parameters[2]-100);
                            } else {
                                gpioDelay(set_all_parameters[2]);
                            }
                        }
                    }
            }

        }
        //FINISH THE STIMULATION N AND STARTS N+1
        else{
            elapsed_time.restart();
            duration_increment = 0;
            stim_init++;
            duration_decrement = 0;
        }
    }
    //STOP STIMULATION
    else{
        if(stim_cycles<2)
            ui->Button_Start->click();
        else{
            //Starts a new cycle
            stim_init = 0;
           stim_cycles--;
        }
    }


}
//************************ PAUSE STIMULATION BUTTON ******************************
void stimcontrol::on_Button_Pause_clicked()
{
    if(pause_index == false){
        pause_index = true;
        if(is_english)
            ui->Button_Pause->setText("Resume");
        else
            ui->Button_Pause->setText("Resumir");
        signal_interval->stop();
        chronometer->stop();
        //Change the vector to consider the current elapsed time.
        //int duration = 1000*stim_parameters[stim_init][8] + stim_parameters[stim_init][9];
        //duration = duration - elapsed_time.elapsed();
        duration_decrement = elapsed_time.elapsed();
        duration_increment = duration_increment + elapsed_time.elapsed();
        //stim_parameters[stim_init][8] = 0;
        //stim_parameters[stim_init][9] = duration;
    }
    else{
        pause_index = false;
        //int restvalue = (int)stim_parameters[stim_init][9];
        int restvalue = 1000*stim_parameters[stim_init][8] + stim_parameters[stim_init][9];
        restvalue = restvalue - duration_decrement;
        while (restvalue>1000)
            restvalue = restvalue - 1000;
        if(is_english)
            ui->Button_Pause->setText("Pause");
        else
            ui->Button_Pause->setText("Pausar");
        chronometer->start(restvalue);
        elapsed_time.restart();
        signal_interval->start();
    }
}
//**********************************************************************************
//**********************************************************************************

//*********************************** CHRONOMETER **********************************
//
void stimcontrol::Chronometer_Increment()
{
    stopwatch_increment++;
    //qDebug() << stopwatch_increment;
    //set lcd minutes value
    int minutes = stopwatch_increment/60;
    //set lcd seconds value
    int seconds = 0;
    if (stopwatch_increment>60)
        seconds = stopwatch_increment%60;
    else
        seconds = stopwatch_increment;

    //set lcd format: "mm:ss"
    QString text;
    text.append(QString( "%1" ).arg(minutes, 2, 10, QLatin1Char('0')) + ":" +
                QString( "%1" ).arg(seconds, 2, 10, QLatin1Char('0')));

    //display the current time
    ui->Lcd_Chronometer->display(text);
    chronometer->setInterval(1000);
}
//**********************************************************************************

//************************** ENABLE/DISABLE BUTTONS  *******************************
void stimcontrol::Enable_Stimbuttons(bool x_bool){
    ui->Button_Stim1->setEnabled(x_bool);
    ui->Button_Stim2->setEnabled(x_bool);
    ui->Button_Stim3->setEnabled(x_bool);
    ui->Button_Stim4->setEnabled(x_bool);
    ui->Button_Stim5->setEnabled(x_bool);
    ui->Button_Stim6->setEnabled(x_bool);
    ui->Button_Stim7->setEnabled(x_bool);
    ui->Button_Stim8->setEnabled(x_bool);
    ui->Button_Stim9->setEnabled(x_bool);
    ui->Button_Stim10->setEnabled(x_bool);
    ui->Button_Stim11->setEnabled(x_bool);
    ui->Button_Stim12->setEnabled(x_bool);
    ui->Check_Set_All->setEnabled(x_bool);
}
void stimcontrol::Enable_SignalSpinSliders(bool x_bool){
    ui->Slider_PulseTrain->setEnabled(x_bool);
    ui->Slider_PulseWidth->setEnabled(x_bool);
    ui->Slider_PulseWidthOff->setEnabled(x_bool);
    ui->Spin_Pulses->setEnabled(x_bool);
    ui->Spin_PulseTrain->setEnabled(x_bool);
    ui->Spin_PulseWidth->setEnabled(x_bool);
    ui->Spin_PulseWidthOff->setEnabled(x_bool);
    ui->Label_PulseWidth->setEnabled(x_bool);
    ui->Label_PulseWidth_2->setEnabled(x_bool);
    ui->Label_PulseWidth_3->setEnabled(x_bool);
    ui->Label_a->setEnabled(x_bool);
    ui->Label_Hz->setEnabled(x_bool);
    ui->Label_Hz_Value->setEnabled(x_bool);
    ui->Label_Pulsos->setEnabled(x_bool);
}
//**********************************************************************************


//********************************* SAVE ACTIONS ***********************************
void stimcontrol::saveScene(const char* filename)
{
    //save last values
    stim_cycles = ui->Spin_Cycles->value();
    Save_LastValues();
    //open file and save
    QFile file(filename);
        // Trying to open in WriteOnly and Text mode
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            if (is_english)
            {
                StatusLabel->setText("Could not save the stimulation data.");
            }
            else
            {
                StatusLabel->setText("Não foi possível salvar os dados de estimulação.");
            }
            return;
        }
        QTextStream out(&file);
        //write set all flag and stim cycles
        out<<set_all_flag<<","<<stim_cycles<<",";
        //write all parameters
        for(int j = 0; j < 12; j++)
        {
            for(int i = 0; i < 15; i++){
                out<<parameters[j][i]<<" ";
            }
            out<<",";
        }
        //write set all parameters
        for(int i = 0; i < 4; i++){
            out<<set_all_parameters[i]<<" ";
        }
        out<<endl;

        if (is_english)
        {
            StatusLabel->setText("File saved successfully!");
        }
        else
        {
            StatusLabel->setText("Dados salvos com sucesso!");
        }

}

void stimcontrol::on_actionSaveScene_1_triggered()
{
    saveScene("./scene1.dat");
}

void stimcontrol::on_actionSaveScene_2_triggered()
{
    saveScene("./scene2.dat");
}

void stimcontrol::on_actionSaveScene_3_triggered()
{
    saveScene("./scene3.dat");
}

void stimcontrol::on_actionSaveScene_4_triggered()
{
    saveScene("./scene4.dat");
}

//********************************* LOAD ACTIONS ***********************************
//Reset Variables
void stimcontrol::on_actionReset_Variables_triggered()
{
    for (int i = 0; i<12; i++){
         for (int j = 0; j<15; j++){
             parameters[i][j]=0;
             stim_parameters[i][j]=0;
         }
    }
    for (int i = 0; i<4; i++)
        set_all_parameters[i]=0;
    ui->Spin_Pulses->setValue(0);
    ui->Spin_PulseWidth->setValue(0);
    ui->Spin_PulseWidthOff->setValue(0);
    ui->Spin_PulseTrain->setValue(0);
    ui->Spin_Cycles->setValue(1);
    ui->Check_Set_All->setChecked(false);
    ui->Check_Activate->setChecked(false);
    for(int i=0 ; i<8; i++)
        channel_group.key(i)->setChecked(false);

    ui->Spin_Time_s->setValue(0);
    ui->Spin_Time_ms->setValue(0);

    //set button color
    for(int i=0 ; i<12; i++)
        stimode_group->button(i)->setStyleSheet("* { color: red }");
}

//Load Scenes
void stimcontrol::loadScene(const char* filename)
{
    QFile file(filename);
    // Trying to open in ReadOnly and Text mode
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        if (is_english)
        {
            StatusLabel->setText("Could not open file for reading.");
        }
        else
        {
            StatusLabel->setText("Não foi possível carregar os dados.");
        }
        return;
    }
    QTextStream in(&file);
    QString line = in.readAll();
    file.flush();
    file.close();
    QStringList list = line.split(",");
    set_all_flag = list[0].toInt();
    stim_cycles = list[1].toInt();
    QStringList param;
    for(int j = 0; j < 12; j++)
    {
        param = list[j+2].split(" ");
        for(int i = 0; i < 15; i++)
        {
            parameters[j][i] = param[i].toDouble();
            if(param[10].toInt()==1)
            {
                stimode_group->button(j)->setStyleSheet("* { color: green }");
            }
            else
                stimode_group->button(j)->setStyleSheet("* { color: red }");
        }
    }
    param = list[14].split(" ");
    for(int j = 0; j < 4; j++)
        set_all_parameters[j] = param[j].toDouble();
   //---
   disconnect(stimode_group, SIGNAL(buttonReleased(int)), this, SLOT(StimButtonPressed(int)));
   stimode_group->button(0)->click();
   stim_saved_id = 0;
   stim_id = 0;
   //=========================
   if(set_all_flag==false)
   {
       ui->Spin_Pulses->setValue((int)parameters[stim_id][11]);
       ui->Spin_PulseWidth->setValue((int)parameters[stim_id][12]);
       ui->Spin_PulseWidthOff->setValue((int)parameters[stim_id][13]);
       ui->Spin_PulseTrain->setValue((int)parameters[stim_id][14]);
   }
   else
   {
       ui->Spin_Pulses->setValue((int)set_all_parameters[0]);
       ui->Spin_PulseWidth->setValue((int)set_all_parameters[1]);
       ui->Spin_PulseWidthOff->setValue((int)set_all_parameters[2]);
       ui->Spin_PulseTrain->setValue((int)set_all_parameters[3]);
   }
   int i;
   //Save/Load Channels and Duration value
   for(i=0 ; i<8; i++){
       if(channel_group.key(i)->isChecked()){
           if(parameters[stim_id][i]==0)
               channel_group.key(i)->setChecked(false);
       }
       else{
           if(parameters[stim_id][i]!=0)
               channel_group.key(i)->setChecked(true);
       }
   }
   //Load seconds + miliseconds duration
   ui->Spin_Time_s->setValue(parameters[stim_id][8]);
   ui->Spin_Time_ms->setValue(parameters[stim_id][9]);
   //Tick/Untick Activate Button
   if(ui->Check_Activate->isChecked()){
       if(parameters[stim_id][10]==0)
           ui->Check_Activate->setChecked(false);
   }
   else
       if(parameters[stim_id][10]==1)
           ui->Check_Activate->setChecked(true);
   //======================
   connect(stimode_group, SIGNAL(buttonReleased(int)), this, SLOT(StimButtonPressed(int)));
   stimode_group->button(0)->click();
   ui->Check_Set_All->setChecked(set_all_flag);
   ui->Spin_Cycles->setValue(stim_cycles);
   if (is_english)
   {
       StatusLabel->setText("File loaded successfully!");
   }
   else
   {
       StatusLabel->setText("Dados carregados com sucesso!");
   }
}

void stimcontrol::on_actionLoadScene_1_triggered()
{
    loadScene("./scene1.dat");
}

void stimcontrol::on_actionLoadScene_2_triggered()
{
    loadScene("./scene2.dat");
}

void stimcontrol::on_actionLoadScene_3_triggered()
{
    loadScene("./scene3.dat");
}

void stimcontrol::on_actionLoadScene_4_triggered()
{
    loadScene("./scene4.dat");
}

//******************************** HOTKEY SYSTEM ACTIONS **********************************
//Close program: CRTL+Q
void stimcontrol::actionClose()
{
    gpioTerminate();
    abort();
    //system("sudo killall stimcontrol");
}

//Reboot CRTL+R
void stimcontrol::actionReboot()
{
    system("sudo reboot");
}
//Shutdown computer: CRTL+S
void stimcontrol::actionShut_Down()
{
    system("sudo shutdown -h now");
}
//**********************************************************************************

//********************************** BRIGTHNESS ************************************

void stimcontrol::on_action25_triggered()
{
    system("sudo sh -c \"echo 50 > /sys/class/backlight/rpi_backlight/brightness\"");
}

void stimcontrol::on_action50_triggered()
{
    system("sudo sh -c \"echo 100 > /sys/class/backlight/rpi_backlight/brightness\"");
}

void stimcontrol::on_action75_triggered()
{
    system("sudo sh -c \"echo 150 > /sys/class/backlight/rpi_backlight/brightness\"");
}

void stimcontrol::on_action100_triggered()
{
    system("sudo sh -c \"echo 200 > /sys/class/backlight/rpi_backlight/brightness\"");
}

//**********************************************************************************

//********************************* LANGUAGE **************************************
void stimcontrol::save_language(bool flag)
{
    QFile file("./language.dat");
        // Trying to open in WriteOnly and Text mode
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            return;
        }
        QTextStream out(&file);
        out<<flag;
        out<<endl;

}

void stimcontrol::load_language()
{
      QFile file("./language.dat");
      // Trying to open in ReadOnly and Text mode
      if(!file.open(QFile::ReadOnly | QFile::Text))
      {
          return;
      }
      QTextStream in(&file);
      QString line = in.readAll();
      file.flush();
      file.close();
      is_english = line.toInt();
      translate_all(is_english);
}

void stimcontrol::on_actionEnglish_triggered()
{
    is_english = true;
    translate_all(is_english);
    save_language(is_english);
}

void stimcontrol::on_actionPt_Br_triggered()
{
    is_english = false;
    translate_all(is_english);
    save_language(is_english);
}

void stimcontrol::translate_all(bool flag)
{
    //Translate to English
    if(flag)
    {
     //Stim Buttons
        ui->Button_Stim1->setText("Stimulation 1");
        ui->Button_Stim2->setText("Stimulation 2");
        ui->Button_Stim3->setText("Stimulation 3");
        ui->Button_Stim4->setText("Stimulation 4");
        ui->Button_Stim5->setText("Stimulation 5");
        ui->Button_Stim6->setText("Stimulation 6");
        ui->Button_Stim7->setText("Stimulation 7");
        ui->Button_Stim8->setText("Stimulation 8");
        ui->Button_Stim9->setText("Stimulation 9");
        ui->Button_Stim10->setText("Stimulation 10");
        ui->Button_Stim11->setText("Stimulation 11");
        ui->Button_Stim12->setText("Stimulation 12");
    //stimulation parameters
        ui->Check_Set_All->setText("Set for all");
        ui->Label_Pulsos->setText("Number of Pulses:");
        ui->Label_PulseWidth_3->setText("Signal Control Frequency [Hz]:");
        ui->Label_PulseWidth_2->setText("Width between Pulses [us]:");
        ui->Label_PulseWidth->setText("Pulse Width [us]:");
    //Channels parameters
        ui->Check_Activate->setText("Activate Stimulation");
        ui->Check_Channel1->setText("Channel 1");
        ui->Check_Channel2->setText("Channel 2");
        ui->Check_Channel3->setText("Channel 3");
        ui->Check_Channel4->setText("Channel 4");
        ui->Check_Channel5->setText("Channel 5");
        ui->Check_Channel6->setText("Channel 6");
        ui->Check_Channel7->setText("Channel 7");
        ui->Check_Channel8->setText("Channel 8");
        ui->Label_Time->setText("Duration:");
        ui->Label_Ciclos->setText("Number of Cycles:");
    //Start and Pause
        ui->Button_Start->setText("Start");
        ui->Button_Pause->setText("Pause");
    //Menus
        //Save
        ui->menuSave->setTitle("Save");
        ui->actionSaveScene_1->setText("Scene 1");
        ui->actionSaveScene_2->setText("Scene 2");
        ui->actionSaveScene_3->setText("Scene 3");
        ui->actionSaveScene_4->setText("Scene 4");
        //Load
        ui->menuLoad->setTitle("Load");
        ui->actionReset_Variables->setText("Reset Variables");
        ui->actionLoadScene_1->setText("Scene 1");
        ui->actionLoadScene_2->setText("Scene 2");
        ui->actionLoadScene_3->setText("Scene 3");
        ui->actionLoadScene_4->setText("Scene 4");
        //Language
        ui->menuLanguage->setTitle("Language");
        //Brightness
        ui->menuBrightness->setTitle("Brightness");
     }

            //Translate to Pt_Br
     else
     {
     //Stim Buttons
        ui->Button_Stim1->setText("Estimulação 1");
        ui->Button_Stim2->setText("Estimulação 2");
        ui->Button_Stim3->setText("Estimulação 3");
        ui->Button_Stim4->setText("Estimulação 4");
        ui->Button_Stim5->setText("Estimulação 5");
        ui->Button_Stim6->setText("Estimulação 6");
        ui->Button_Stim7->setText("Estimulação 7");
        ui->Button_Stim8->setText("Estimulação 8");
        ui->Button_Stim9->setText("Estimulação 9");
        ui->Button_Stim10->setText("Estimulação 10");
        ui->Button_Stim11->setText("Estimulação 11");
        ui->Button_Stim12->setText("Estimulação 12");
    //stimulation parameters
        ui->Check_Set_All->setText("Atribuir à todos");
        ui->Label_Pulsos->setText("Número de Pulsos:");
        ui->Label_PulseWidth_3->setText("Frequência de Controle [Hz]:");
        ui->Label_PulseWidth_2->setText("Largura entre Pulsos [us]:");
        ui->Label_PulseWidth->setText("Largura dos Pulsos [us]:");
    //Channels parameters
        ui->Check_Activate->setText("Ativar Estimulação");
        ui->Check_Channel1->setText("Canal 1");
        ui->Check_Channel2->setText("Canal 2");
        ui->Check_Channel3->setText("Canal 3");
        ui->Check_Channel4->setText("Canal 4");
        ui->Check_Channel5->setText("Canal 5");
        ui->Check_Channel6->setText("Canal 6");
        ui->Check_Channel7->setText("Canal 7");
        ui->Check_Channel8->setText("Canal 8");
        ui->Label_Time->setText("Duração:");
        ui->Label_Ciclos->setText("Número de Ciclos:");
    //Start and Pause
        ui->Button_Start->setText("Começar");
        ui->Button_Pause->setText("Pausar");
    //Menus
        //Save
        ui->menuSave->setTitle("Salvar");
        ui->actionSaveScene_1->setText("Espaço 1");
        ui->actionSaveScene_2->setText("Espaço 2");
        ui->actionSaveScene_3->setText("Espaço 3");
        ui->actionSaveScene_4->setText("Espaço 4");
        //Load
        ui->menuLoad->setTitle("Carregar");
        ui->actionReset_Variables->setText("Resetar Variáveis");
        ui->actionLoadScene_1->setText("Espaço 1");
        ui->actionLoadScene_2->setText("Espaço 2");
        ui->actionLoadScene_3->setText("Espaço 3");
        ui->actionLoadScene_4->setText("Espaço 4");
        //Language
        ui->menuLanguage->setTitle("Idioma");
        //Brightness
        ui->menuBrightness->setTitle("Brilho");
            }
}
//**********************************************************************************


//kill program
stimcontrol::~stimcontrol()
{
    delete ui;
}





