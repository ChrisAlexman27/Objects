//Christopher Alexman		  CSC 17A		 Chapter 15, P. 965, #06
//
// ESSAY CLASS
//
#include <iostream>
using namespace std;

class GradedActivity                    //original graded activity class   
{
    private:
        float score;                        //holds the score
            
    public:
        GradedActivity()                //constructor, initializes
            { score = 0.0; }

        GradedActivity(float s)
            { score = s; }

        void setScore(float s)
            { score = s; }

        float getScore() const
            { return score; }

        char getLetterGrade() const
        {
            char letterGrade;           //holds A-F letter grade

            if(score > 100)                             //input validation
                cout << "SCORE OVER 100. TRY AGAIN";
            else if (score > 89)
                letterGrade = 'A';
            else if (score > 79)
                letterGrade = 'B';
            else if (score > 69)
                letterGrade = 'C';
            else if (score > 59)
                letterGrade = 'D';
            else
                letterGrade = 'F';

            return letterGrade;
            }
    };

class Essay : public GradedActivity         //Essay class derived from GA class
{
    private:
        float grammar;
        float spelling;
        float length;
        float content;// 30 points

    public:
        Essay (float g, float s, float l, float c)      //constructor
        {
            grammar = g * 30/100;       //worth 30 pts
            spelling = s * 20/100;      //worth 20 pts
            length = l * 20/100;        //worth 20 pts
            content = c * 30/100;       //worth 30 pts
        }

        float getTotalScore()           //add together, 0-100
        {
            return grammar + spelling + length + content;
        }
};

int main ()
{
    float g;        //grammar
    float s;        //spelling
    float l;        //length
    float c;        //content
    
    cout << "Input grammar, spelling, correct length, and content scored: \n";
    cin >> g >> s >> l >> c;

    Essay one (g, s, l, c);         //send over values

    float totScore = one.getTotalScore();       //get total score

    GradedActivity theScore;                    //create an instance of a class

    theScore.setScore(totScore);

    cout << "\nGrade earned: " << theScore.getLetterGrade() << endl;
    cout << totScore << " out of 100";

    return 0;
}