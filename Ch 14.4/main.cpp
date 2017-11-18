//Christopher Alexman		  CSC 17A		 Chapter 14, P. 885, #04
//
// NUMDAYS CLASS
//
#include <iostream>
using namespace std;

class NumDays
{
    private:
        float hours;
        float days;
    
    public:

        NumDays()                   //constructor, initialize values to 0
        {
            hours = 0;
            days = 0;
        }

        NumDays(float h)       //constructor, to store and retrieve hrs/days
        {
            hours = h;
            days = h / 8;
        }

//accessor functions
        float getHours()
            { return hours; }

        float getDays()
            { return days; }

//mutator functions
        void setHours(double h)
            { hours = h; }

        void setDays(double d)
            { days = d; }

//overloaded operators
        float operator + (const NumDays &right)     //returns sum of the two
        {                                           //objects hour members
            return hours + right.hours;
        }
        float operator - (const NumDays &right)     //returns the difference of
        {                                           //the two objects hour members
            return hours - right.hours;
        }
        NumDays operator ++ ()                      //increment, number of days 
        {                                           //automatically recalculated
            ++hours;
            days = hours / 8;
            return *this;
        }
        NumDays operator ++ (int)
        {
            NumDays temp(hours);
            hours++;
            days = (hours + 1) / 8;
            return temp;
        }
        NumDays operator -- ()                      //decrement, number of days
        {                                           //automalically recalculated
            --hours;
            days = hours / 8;
            return *this;
        }
        NumDays operator -- (int)
        {
            NumDays temp(hours);
            hours--;
            days = (hours - 1) / 8;
            return temp;
        }
};

int main()
{
    NumDays test1 = NumDays(8);              //create different test trials
    NumDays test2 = NumDays(12);
    NumDays test3 = NumDays(18);
    NumDays test4 = NumDays(50);
    NumDays test5 = NumDays(100);
    
    NumDays plus;
    NumDays minus;
    NumDays holder;

    cout << "Hours: " << test1.getHours() << endl; 
    cout << "Days: " << test1.getDays() << endl << endl;
    
    cout << "Hours: " << test2.getHours() << endl; 
    cout << "Days: " << test2.getDays() << endl << endl;
    
    cout << "Hours: " << test3.getHours() << endl; 
    cout << "Days: " << test3.getDays() << endl << endl;
    
    cout << "Hours: " << test4.getHours() << endl; 
    cout << "Days: " << test4.getDays() << endl << endl;
    
    cout << "Hours: " << test5.getHours() << endl; 
    cout << "Days: " << test5.getDays() << endl << endl << endl;
    
    cout << "These are for the values in test 1 and test 2.\n";
    cout << "Addition operator: ";
    plus = test1 + test2;
    cout << plus.getDays() << endl;;

    cout << "Subtraction operator: ";
    minus = test2 - test1;
    cout << minus.getDays() << endl;;
    
    cout << "Prefix increment operator: ";
    holder = ++plus;
    cout << holder.getDays() << endl;;
    
    cout << "Postfix increment operator: ";
    holder = plus++;
    cout << holder.getDays() << endl;;
    
    cout << "Prefix decrement operator: ";
    holder = --plus;
    cout << holder.getDays() << endl;;
    
    cout << "Postfix decrement operator: ";
    holder = plus--;
    cout << holder.getDays() << endl;;
    
    return 0;
}