/*

*/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;
#define inputFile "input.txt"
#define outputFile "output.txt"
vector<string> inputSequence;
vector<string> output;
int Numdatasets;

void printInput()
{
    fstream myfile(inputFile);
    string line;
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
    return;
}

int ReadInput()
{
    fstream myfile(inputFile);
    string line;
    getline (myfile,line);
    int i = 0;
    Numdatasets = atoi(line.c_str());
    //cout<<Numdatasets<<endl;
    
    while (i < Numdatasets)
    {
        getline(myfile, line); //skips set number
        getline(myfile, line);
        inputSequence.push_back(line);
        i++;
    }
    myfile.close();
    return 0;
}
int GetInput()
{
    string line;
    getline (cin,line);
    int i = 0;
    Numdatasets = atoi(line.c_str());
    
    while (i < Numdatasets)
    {
        getline(cin, line); //skips set number
        getline(cin, line);
        inputSequence.push_back(line);
        i++;
    }
    return 0;
}
int WriteOutputTofile(int i, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
    fstream myfile(outputFile, std::fstream::in | std::fstream::out | std::fstream::app);
    string line;
    if (myfile.is_open())
    { 
        myfile<<i;
        myfile<<" ";
        myfile<<p1;
        myfile<<" ";
        myfile<<p2;
        myfile<<" ";
        myfile<<p3;
        myfile<<" ";
        myfile<<p4;
        myfile<<" ";
        myfile<<p5;
        myfile<<" ";
        myfile<<p6;
        myfile<<" ";
        myfile<<p7;
        myfile<<" ";
        myfile<<p8;
        if (i < Numdatasets)
        {
            myfile<<" \n";
        }
        else
        {
            myfile<<" ";
        }
    }
    return 0;
}

int JudgeRepeatation(int i)
{
    vector<string>::iterator iter = inputSequence.begin();
    iter+=(i-1);
    string temp = *iter;
    //cout<<temp<<endl;
    int p1 = 0; //TTT
    int p2 = 0; //TTH
    int p3 = 0; //THT
    int p4 = 0; //THH
    int p5 = 0; //HTT
    int p6 = 0; //HTH
    int p7 = 0; //HHT
    int p8 = 0; //HHH
    for (int i = 0; i<38; i++)
    {
        //store number of times of occurences of 8 patterns
        if (temp.substr(i,3) == "TTT")
        {
            p1++;
        }
        if (temp.substr(i,3) == "TTH")
        {
            p2++;
        }
        if (temp.substr(i,3) == "THT")
        {
            p3++;
        }
        if (temp.substr(i,3) == "THH")
        {
            p4++;
        }
        if (temp.substr(i,3) == "HTT")
        {
            p5++;
        }
        if (temp.substr(i,3) == "HTH")
        {
            p6++;
        }
        if (temp.substr(i,3) == "HHT")
        {
            p7++;
        }
        if (temp.substr(i,3) == "HHH")
        {
            p8++;
        }
    }
    //save to the output file
    
    //cout<<currentOutput<<endl;
    //WriteOutputTofile(i, p1, p2, p3, p4, p5, p6, p7, p8);
    cout<<i<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" "<<p6<<" "<<p7<<" "<<p8<<endl;
    //cout<<x<<endl;
    return 0;
}


int main()
{
    //ReadInput();
    GetInput();
    for (int i = 1; i<= Numdatasets; i++)
    {
        JudgeRepeatation(i);
    }
}