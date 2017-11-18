//Christopher Alexman		  CSC 17A		 Chapter 15, P. 964, #02
//
// EMPLOYEE AND PRODUCTIONWORKER CLASSES
//
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
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

        Employee(string na,int nu,string d)     //constructor, set the values
        {   
            name = na;
            number = nu;
            date = d;
        }

        void setName(string str)                //the mutator function
            { name = str; }
        void setNum(int num)
            { number = num; }
        void setDate(string d)
            { date = d; }
        
        string getName()                        //the accessor functions
            { return name; }
        int getNum()
            { return number; }
        string getDate()
            {return date; }

};

class ShiftSupervisor:public Employee       //ShiftSupervisor derived from Emp
{
    private:
        float annualS;
        float bonus;
        
    public: 
        ShiftSupervisor()                   //constructor, initialize values
        {
            annualS = 0.0;
            bonus = 0.0;
        }
        ShiftSupervisor(float a, float b)
        {
            annualS = a;
            bonus = b;
        }
        
        void setAnn(float a)                        //the mutator functions
            { annualS = a; }
        void setBon(float b)
            { bonus = b; }
        
        float getAnn()                              //the accessor functions
            { return annualS; }
        float getBon()
            { return bonus; }
};

int main()
{
    ShiftSupervisor emp1;                   //instance of a class
    
    float annualS;                          //the annual salary 
    float bonus;                            //the bonus
    
    cout << setprecision(2) << fixed;       //to format float values
        
    emp1.setName("Chris");                  //set values manually
    emp1.setNum(149765);    
    emp1.setDate("August 18, 2017");
   
    cout << "Annual salary: ";              //get remaining values from user
    cin >> annualS;
    
    cout << "Annual bonus: ";
    cin >> bonus;
    
    emp1.setAnn(annualS);                   //set user inputted values
    emp1.setBon(bonus);
    
    cout << "\nEMPLOYEE DETAILS\n";                 //output with a format
    cout << "----------------\n";
    cout << "Name: " << emp1.getName() << endl;
    cout << "Number: " << emp1.getNum() << endl;
    cout << "Date: " << emp1.getDate() << endl;
    cout << "Salary: " << emp1.getAnn() << endl;
    cout << "Bonus: " << emp1.getBon() << endl;
    
    return 0;
}