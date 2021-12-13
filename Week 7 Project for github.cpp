/*
Noah Yacoub
ITCS 2530
12/12/2021
Week 7 - Project

For the assignment you be modifying your code from the Week 06 - Programming Assignment. Here are the requirements:

Your program must use one structure that contains the following member variables:
    -a string data type that will hold the name of the bowler.
    -a one-dimensional array of integers to store the bowler's 4 scores.
    -an integer to hold the average bowling score.
Your program must contain at least the following functions:
an Boolean returning function called GetBowlingData to read and store data into an array of structures. The function should take as input parameters the file name and an empty array of structures, which it should fill from the file (BowlingScores.txt  download) and return a status of either success or failure (i.e. true or false).
a void function called GetAverageScore that is used to calculate the average bowling score. The function should take as input the array of structures which it should fill with the average score of each bowler.
a void function called PrettyPrintResults to output the results, i.e. bowler name, scores and average.
Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.
Use repetition structures (loops) in your functions to perform calculations and printing. Remember "dimensions = loops". So a 2 dimensional array will require 2 loops to completely iterate over all of the elements in the array.
Don't use magic numbers. Instead use global constants at the top of the program under the includes.
And as always include lots of meaningful comments so that I can follow you logic and know that you understand the program you wrote.
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>

using namespace std;

//functions defined
int GetBowlingData(int argc, char* argv[]);
void GetAverageScore();
void PrettyPrintResults();

//constant variables
const int rounds_per_game = 5; //meaning 5 rounds
const int player_count = 10; //meaning 10 players max

//main counter for loops
int bowlerCount = 0;

//main struct for project
struct bowler
{
    string BowlerName{};
    int BowlerScore[rounds_per_game]{};
    double BowlerAvScore{};
};

//initialize array struct
bowler bowlerData[player_count];

int main(int argc, char* argv[])
{
    if (argc < 2) //arguement count check
    {
        cout << "Error with input agrs.." << endl;
        return false;
    }

    GetBowlingData(argc, argv); //no loop required all processed without output

    bowlerCount = 0;
    while (bowlerCount < player_count) //uses one loop for 2 types of output
    {
        PrettyPrintResults(); //contains nested loop
        GetAverageScore();
        bowlerCount++;
    }
    return 0;
}

int GetBowlingData(int argc, char* argv[])
{
    //inputs we will take from argv[1]
    string name;
    double round[rounds_per_game];

    //counting variables
    //int bowlerCount;
    double temp_bowlerfulltotal;
    //double bowleravg;

    ifstream inputFile;
    inputFile.open(argv[1]);

    if (!inputFile) //file check 
    {
        cout << "Error with wrong file name!" << endl;
        return false;
    }

    //bowler bowlerData;
    while (!inputFile.eof())
    {
        //bowlerCount = 0;
        //limits format to name followed by 4 scores exactly
        while (inputFile >> name >> round[0] >> round[1] >> round[2] >> round[3] >> round[4])
        {
            temp_bowlerfulltotal = 0;
            temp_bowlerfulltotal = round[0] + round[1] + round[2] + round[3] + round[4];

            
            bowlerData[bowlerCount].BowlerName = name;
            for (int r = 0; r < rounds_per_game; r++)
            {
                bowlerData[bowlerCount].BowlerScore[r] = round[r];
            }
            bowlerData[bowlerCount].BowlerAvScore = temp_bowlerfulltotal / rounds_per_game;
            bowlerCount++;
        }
    }
    inputFile.close();
    return true; 
}

void GetAverageScore()
{
    //prints bowler average scores
    cout << "Average Score" << endl;
    cout << bowlerData[bowlerCount].BowlerAvScore << endl;
    cout << endl;
}

void PrettyPrintResults()
{
    //prints bowlers scores one by one
    cout << bowlerData[bowlerCount].BowlerName << endl;
    for (int i = 0; i < rounds_per_game; i++)
        cout << bowlerData[bowlerCount].BowlerScore[i] << endl;
}


/* UNUSED CODE
    lots of various debugging lines, some were helpful some were not
    //string line;
    //getline(inputFile, line);
    //cout << line;
    //inputFile.get(x);
    //getline(inputFile, stringinput, ' ');

    //for(i=0;i%5=0;i++)

    //getline(inputFile, stringinput);
    //cout << stringinput << endl;

    //cout << x;

    //int round1, round2, round3, round4;
    //cout << '\n' << name << endl;

    //cout << bowlerCount;
    //cout << name << " " << round1 << " " << round2 << " " << round3 << " " << round4 << '\n' << endl;

    /////cout << BowlerNames[bowlerCount] << " ";

    //cout << sizeof(BowlerScores) << endl;

    //
    //BowlerScores[bowlerCount][0] = round1;
    //BowlerScores[bowlerCount][1] = round2;
    //BowlerScores[bowlerCount][2] = round3;
    //BowlerScores[bowlerCount][3] = round4;

    //cout << "adding..." << temp_bowlerfulltotal << endl;
    //cout << "added: " << temp_bowlerfulltotal << endl;
    //cout << name;

    /*
    //prints bowler names
    cout << "Bowler names" << endl;
    for (int x = 0; x < player_count; x++)
    {
        cout << BowlerNames[x] << endl;
    }
    cout << endl;

    //prints bowler scores
    for (int x = 0; x < player_count; x++)
    {
        cout << "bowler " << x << "'s scores" << endl;
        for (int x2 = 0; x2 < rounds_per_game; x2++)
        {
            cout << BowlerScores[x][x2] << endl;
        }
    }
    cout << endl;

    //prints bowler average scores
    cout << "bowler average scores" << endl;
    for (int y = 0; y < player_count; y++)
    {
        cout << BowlerAvScores[y] << endl;
    }
    cout << endl;

    //takes inputs of filename, and two empty arrays

*/