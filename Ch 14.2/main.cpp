//Christopher Alexman		  CSC 17A		 Chapter 14, P. 884, #02
//
// DAY OF THE YEAR
//
#include <iostream>
using namespace std;

class DayOfYear 
{
    int input;
    static string Months[];
    static int day[];

    public:
        DayOfYear()                 //constructor
            {input = 0; }           
        DayOfYear(int day)           //constructor
            {input = day; }          

        void print();               //to print the result in the other form
};

string DayOfYear::Months[] = {"January", "February", "March", "April", "May", 
                              "June", "July", "August", "September", "October",
                              "November", "December" };
int DayOfYear::day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//******************************************************************************
// print outputs the day of the year from the array values
//******************************************************************************
void DayOfYear::print()
{
    int index = 0;
    while(input > day[index])           //while input > each element in day arry
    {
        input -= day[index];            //reduce index by arrays element amount
        index++;                        //increment index
    }

    cout << Months[index] << " " << input << endl;      //output the date

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