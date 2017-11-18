//Christopher Alexman		  CSC 17A		 Chapter 14, P. 887, #10
//
// CORPORATE SALES
//
#include <iostream>
using namespace std;

class DivSales
{
    private:
        int qSales[4];
        static float ttlSals;
    
    public:
        void sum(int, int, int, int);
        int sales(int);
        static float getInput()
            { return ttlSals; }
};

void DivSales::sum(int a, int b, int c, int d)
{
    qSales[0] = a;
    qSales[1] = b;
    qSales[2] = c;
    qSales[3] = d;
    
    ttlSals = ttlSals + a + b + c + d;
}

int DivSales::sales(int num)
{
    int input;
    
    input = qSales[num];
    
    return input;
}

int main()
{
    DivSales div;
    
    float a;
    float b;
    float c;
    float d;
    
    cout << "Enter sales for Division 1: \n";
    cout << "Quarter 1: ";
    cin >> a;
    
    cout << "Quarter 2: ";
    cin >> a;
    
    cout << "Quarter 3: ";
    cin >> a;
    
    cout << "Quarter 4: ";
    cin >> a;
    
    cout << "\nTotal of sales: " << div.sum();
    
    
    return 0;
}