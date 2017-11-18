//Christopher Alexman		  CSC 17A		 Chapter 14, P. 884, #03
//
// DAY OF THE YEAR MODIFICATION
//
#include <iostream>
#include <string>
using namespace std;

class DayOfYear 
{
    private:
        int input;
        static string Months[];
        static int day[];
        
        int dayYear;
        int dayMnth;
        string mnthNme;

    public:
        DayOfYear()                 //constructor
            {input = 0; }           
        DayOfYear(int day);         //constructor        
        DayOfYear(string month, int days);
        
        void print();               //to print the result in the other form
        DayOfYear& operator++();
        DayOfYear& operator--();
};

string DayOfYear::Months[] = {"January", "February", "March", "April", "May", 
                              "June", "July", "August", "September", "October",
                              "November", "December" };
int DayOfYear::day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

DayOfYear::DayOfYear(int d)
{
    dayYear = d;
    dayMnth = dayYear;
    int index = 0;
    while (1 == 1)
    {
        if(dayMnth <= day[index])
        {
            mnthNme = Months[index];
        }
        else
        {
            dayMnth -= day[index++];
        }
    }
}

DayOfYear::DayOfYear(string month, int days)
{

}

//******************************************************************************
// print outputs the day of the year from the array values
//******************************************************************************
void DayOfYear::print()
{
    cout << "The day " << dayYear << " is " << mnthNme << " " << dayMnth; 
//    int index = 0;
//    while(input > day[index])           //while input > each element in day arry
//    {
//        input -= day[index];            //reduce index by arrays element amount
//        index++;                        //increment index
//    }
//
//    cout << Months[index] << " " << input << endl;      //output the date

}

int main() 
{
    int input;                              //for the user input
    
    cout << "Enter a value(1-365): ";       //get input value
    cin >> input;
    
    while(input > 365 || input < 1)         //input validation
    {       
        cout << "ERROR. Enter a value(1-365): ";
        cin >> input;
    }

    DayOfYear test(input);              //send input over

    test.print();                       //print the other form out

return 0;
}