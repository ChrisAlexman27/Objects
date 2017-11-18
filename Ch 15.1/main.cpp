//Christopher Alexman		  CSC 17A		 Chapter 15, P. 963, #01
//
// EMPLOYEE AND PRODUCTIONWORKER CLASSES
//
#include <iostream>
#include <iomanip>
using namespace std;

class Employee                      //original employee class, holds
{
    protected:                   //protected, can be accessed by derived classes
        string name;
        int number;
        string date;

    public:   
        Employee()                  //constructor, initializes values
        {
            name = " ";
            number = 0;
            date = " ";
        }

        Employee(string na, int nu, string d)     //constructor, set the values
        {   
            name = na;
            number = nu;
            date = d;
        }

        void setName(string str)            //the mutator functions
            { name = str; }
        void setNum(int num)
            { number = num; }
        void setDate(string d)
            { date = d; }
        
        string getName()                    //the accessor functions
            { return name; }
        int getNum()
            { return number; }
        string getDate()
            {return date; }

};

class ProductionWorker:public Employee          //derived class
{
    private:
        int shift;                          //for shift 1 or 2
        float pay;                          //employees hourly pay

    public: 
        ProductionWorker()                  //constructor, initialize to 0
        {
            shift = 0;
            pay = 0;
        }
        
        ProductionWorker(int s, float p)       //constructor, assign values
        {
            shift = s;
            pay = p;
        }

        void setShift(int s)                    //the mutator functions
            { shift = s; }
        void setPay(float p)
            { pay = p; }
        
        int getShift()                          //the accessor functions
            { return shift; }
        float getPay()
            { return pay; }

};

int main()
{
    int shift;
    float pay;
    
    cout << setprecision(2) << fixed;   //to format float pay

    cout << "Enter shift(1-Day shift or 2-Night shift): ";
    cin >> shift;

    cout << "Enter hourly pay: ";
    cin >> pay;

    ProductionWorker emp1(shift, pay);          //send over values

     emp1.setName("Chris");                     //set values and output them

     emp1.setNum(149765);

     emp1.setDate("August 18, 2017");
     
     cout << "\nEMPLOYEE INFO\n";
     cout << "---------------------\n";

     cout << "Name: " << emp1.getName() <<endl;

     cout << "Number: " << emp1.getNum() <<endl;

     cout << "Date of hire: " << emp1.getDate() <<endl;

     cout << "Shift: " << emp1.getShift() <<endl;

     cout << "Hourly Pay: " << emp1.getPay() <<endl;

     return 0;

}