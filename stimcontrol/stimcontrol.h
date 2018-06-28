#ifndef STIMCONTROL_H
#define STIMCONTROL_H

#include <QMainWindow>
#include  <QObject>
#include <QButtonGroup>
#include <QCheckBox>
#include <QString>
#include <QMap>
#include <QTimer>
#include <QElapsedTimer>
#include <QLabel>
#include <QProgressBar>

namespace Ui {
class stimcontrol;
}

class stimcontrol : public QMainWindow
{
    Q_OBJECT

public:
    explicit stimcontrol(QWidget *parent = 0);
    ~stimcontrol();

private:
    Ui::stimcontrol *ui;
    QLabel *StatusLabel;
    QLabel *NameLabel;
    QProgressBar *StatusBar;
    QTimer *signal_interval;
    QString channels_message[12];
    QTimer *chronometer;
    QElapsedTimer elapsed_time;
    int stopwatch_increment;
    //Stimulation variables
    QButtonGroup* stimode_group;
    int stim_id;
    int stim_saved_id;
    int stim_flag;
    int stim_end;
    int stim_init;
    int stim_cycles;
    int duration_increment;
    int duration_decrement;
    int pulse_counter;
    bool start_index;
    bool pause_index;
    QMap <QCheckBox *, int> channel_group;
    //[0,7]channels, [8]seconds, [9]miliseconds, [10]active_flag,[11]N_pulses, [12]pulsewidth, [13]pulsewidthoff, [14]pulsetrain, [15] stim number
    double parameters[12][15];
    double stim_parameters[12][16];
    //[0]N_pulses, [1]pulsewidth, [2]btw_pulsewidth, [3]pulsetrain
    double set_all_parameters[4];
    bool set_all_flag;
    // language flag
    bool is_english;

    //Channels pins
    //int channels[8]={22,23,24,25,8,10,9,11};
    int channels[8]={11,9,10,8,25,22,24,23};
    int pinHigh = 18;

private slots:
    void StimButtonPressed(int);
    void Update_All_Parameters();
    void SetStimColor(bool);
    void SetAllParameters(bool);
    void SliderToSpin_PulseWidth(int);
    void SpinToSlider_PulseWidth(int);
    void SliderToSpin_PulseWidthOff(int);
    void SpinToSlider_PulseWidthOff(int);
    void SliderToSpin_PulseTrain(int);
    void SpinToSlider_PulseTrain(int);
    void SliderToSpin_Cycles(int);
    void SpinToSlider_Cycles(int);
    void Set_msbar_Parameters();
    void SliderToSpin_Time_ms(int);
    void SpinToSlider_Time_ms(int);
    void Chronometer_Increment();
    void Send_Control_Signal();
    void on_Button_Start_clicked();
    void actionClose();
    void actionReboot();
    void actionShut_Down();
    void on_Button_Pause_clicked();
    //functions without connections
    void Enable_Stimbuttons(bool);
    void Enable_SignalSpinSliders(bool);
    void Save_LastValues();
    void on_actionReset_Variables_triggered();
    void on_actionEnglish_triggered();
    void on_actionPt_Br_triggered();
    void translate_all(bool);
    void save_language(bool);
    void load_language();
    void saveScene(const char*);
    void loadScene(const char*);
    void on_actionSaveScene_1_triggered();
    void on_actionSaveScene_2_triggered();
    void on_actionSaveScene_3_triggered();
    void on_actionSaveScene_4_triggered();
    void on_actionLoadScene_1_triggered();
    void on_actionLoadScene_2_triggered();
    void on_actionLoadScene_3_triggered();
    void on_actionLoadScene_4_triggered();
    void on_action25_triggered();
    void on_action50_triggered();
    void on_action75_triggered();
    void on_action100_triggered();
};

#endif // STIMCONTROL_H
