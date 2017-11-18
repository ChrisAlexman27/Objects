//Christopher Alexman		  CSC 17A		 Chapter 15, P. 964, #03
//
// TEAMLEADER CLASS
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

        Employee(string na,int nu,string d)     //constructor, set the values
        {   
            name = na;
            number = nu;
            date = d;
        }

        void setName(string str)                //the mutator functions
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

        void setShift(int s)                //the mutator functions
            {shift = s; }
        void setHourlyPay(float p)
            { pay = p; }
        
        int getShift()                      //the accessor functions
            { return shift; }
        float getPay()
            { return pay; }

};

class TeamLeader:public ProductionWorker
{
    private:        
        float mBonus;               //the monthly bonus
        int reqHrs;                 //the required training hours
        int attHrs;                 //the attended training hours
        
    public:
        TeamLeader()
        {
            mBonus = 0.0;
            reqHrs = 0;
            attHrs = 0;
        }
        TeamLeader(float m, int r, int a)
        {
            mBonus = m;
            reqHrs = r;
            attHrs = a;
        }
        
        void setBon(float m)                //the mutator functions
            { mBonus = m; }
        void setReq(int r)
            { reqHrs = r; }
        void setAtt(int a)
            { attHrs = a; }
        
        float getBon()                      //the accessor functions
            { return mBonus; }
        int getReq()
            { return reqHrs; }
        int getAtt()
            { return attHrs; }
};

int main()
{
    TeamLeader person1;                     //define an instance of a class

    float mBonus;                           //monthly bonus
    int reqHrs;                             //required training hours   
    int attHrs;                             //attained training hours
    
    cout << setprecision(2) << fixed;       //to format float value

    person1.setName("Chris");                     //set values and output them

    person1.setNum(149765);

    person1.setDate("August 18, 2017");
     
    cout << "Monthly bonus: ";                  //get user input for 3 variables
    cin >> mBonus;
     
    cout << "Required hours: ";
    cin >> reqHrs;
      
    cout << "Attained hours: ";
    cin >> attHrs;
     
    person1.setBon(mBonus);                 //set those 3 variables
    person1.setReq(reqHrs);
    person1.setAtt(attHrs);
     
     cout << "\nEMPLOYEE INFO\n";                       //output to format
     cout << "---------------------\n";
     cout << "Name: " << person1.getName() <<endl;
     cout << "Number: " << person1.getNum() <<endl;
     cout << "Date of hire: " << person1.getDate() <<endl;
     cout << "Bonus: " << person1.getBon() <<endl;
     cout << "Required Hours: " << person1.getReq() <<endl;
     cout << "Attained hours: " << person1.getAtt() << endl;

     return 0;

}