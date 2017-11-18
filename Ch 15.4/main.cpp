//Christopher Alexman		  CSC 17A		 Chapter 15, P. 964, #04
//
// TIME FORMAT
//
#include <iostream>
using namespace std;

class Time                  //the Time class
{
    protected:              //protect, but can be accessed by derived classes
        int hour;
        int min;
        int sec;
    
    public:
        Time()              //constructor, initialize to 0
        {
            hour = 0;
            min = 0;
            sec = 0;
        }
    
        int gethour() const     //accessor functions
            { return hour; }
    
        int getMin() const
            { return min; }
    
        int getSec() const
            { return sec; }
};

class MilTime:public Time             //MilTime class derived from Time class
{
    private:
        int milHrs;
        int milSec;
    
    public:
        MilTime(int hours, int seconds)             //constructor, set values
        {
            milHrs = hours;
            milSec = seconds;
        }
    
        void setTime(int mhours, int msecnds);      //mutator function
    
        int getHour()                               //accessor functions
            { return milHrs; }
        int getStandHr()
            { return hour % 12; }
    
};

void MilTime::setTime(int mhours, int msecnds)
{
    if(mhours < 2359 && mhours > 0 && sec <= 59 && sec >= 0)
    {
        milHrs = mhours;
        milSec = msecnds;
        hour = (milHrs / 100);
        min = milHrs % 100;
        sec = milSec;
    }
    else
    {
        cout << "ERROR. INVALID INPUT.\n\n";
    }
}

int main()
{
    int hr;
    int sec;
    
    MilTime time1(0, 0);                //initialize to 0
    
    cout << "Enter military time: ";        //get user input
    cin >> hr;
    
    while(hr > 2359 || hr < 0)
    {
        cout << "ERROR. Enter military time: ";
        cin >> hr;
    }
    
    cout << "Enter the seconds: ";
    cin >> sec;
    
    while(sec > 59 || sec < 0)
    {
        cout << "ERROR. Enter the seconds: ";
        cin >> sec;
    }
    
    time1.setTime(hr, sec);
    
    cout << "Military time: " << time1.getHour() << " hours" << endl;
    
    if(time1.gethour()/12 == 1)
    {
        cout << "Civilian time: " << time1.getStandHr() << ":";
    
        if(time1.getMin() == 0)
        {
            cout << time1.getMin() << "0" << " PM" << endl;
        }
        else
        {
            cout << time1.getMin() << " PM";
        }
    }
   
    else
    {
        cout << "Civilian time: " << time1.getMin() << ":";
        
        if(time1.getMin() == 0)
        {
            cout << time1.getMin() << "0" << " AM" << endl;
        }
        else
        {
            cout << time1.getMin() << " AM" << endl;
        }
    }
    
    return 0;
}