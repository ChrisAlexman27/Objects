//Christopher Alexman		  CSC 17A		 Chapter 14, P. 884, #01
//
// NUMBERS CLASS
//
#include <iostream>
using namespace std;

class Numbers                           //numbers class
{
    public:
        int number;                     //user input of the int

        static string lessThan20[ ];    //static array of string objects
        static string twntyTo100[ ];    //static array of string objects
        static string hundred;
        static string thousand;

        Numbers(int);                   //Constructor
        void print();                   //to print the english form
};

//the arrays with all of the English words
string Numbers::lessThan20[ ] = { "zero", "one", "two", "three", "four", "five", 
                                  "six", "seven", "eight", "nine", "ten", 
                                  "eleven", "twelve", "thirteen", "fourteen", 
                                  "fifteen", "sixteen", "seventeen", "eighteen", 
                                  "nineteen" };
string Numbers::twntyTo100[ ] = { " ", " ", "twenty", "thirty", "forty", 
                                  "fifty", "sixty", "seventy", "eighty", 
                                  "ninety" };
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

//********************************************************************************
// This constructor accepts the number integer from the user. If it is outside
// the bounds the number is never set and the English form will be zero.
//********************************************************************************
Numbers::Numbers(int num)
{
    if (num >= 0 && num <= 9999)
    {
        number = num;
    }
    else
    {
        cout << "ERROR. Outside of range.\n";
    }
}

//********************************************************************************
// print prints out the English from of the number
//********************************************************************************
void Numbers::print()
{
    int K = 0;              //for the thousands
    int H = 0;              //for the hundreds
    int T = 0;              //for less than 100
    int N = 0;              //a holder variable
    
string EngNum = " ";            //for the english description of the number

//for values 1000 and up
if (number > 999)
{
    K = number / 1000;                                  //will be 1-9
    EngNum = lessThan20[K] + " " + thousand + " ";      
    N = K * 1000;                                       //restore original num
}

//for values 100 to 999
if (number > 99)
{
    if (number > 999)
    {
        H = (number - N)/100;                       //reduce number to hundreds
    }
    else
    {
        H = number / 100;                           //will be 1-9
    }

    EngNum += lessThan20[H] + " " + hundred + " ";  
    N += (H * 100);                                 //restore original num
}

//for values in the tens
if (N > 0)
{
    T = number - N;
}
else
{
    T = number;
}

//for values in the tens
if (T > 19)
{
EngNum += twntyTo100[(T/10)] + " " + lessThan20[(T%10)];
}
else
EngNum += lessThan20[T];

// Display English description
cout << "English description: " << EngNum;
}

int main()
{
int input;                                  //for the user's input

cout << "Enter a number (0-9999): ";        //get user input
cin >> input;

Numbers n(input);                           //send the value over

n.print();                                  //print english form

return 0;
}