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
int Numdatasets;
int power(int x, int p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p == 2)
    {
        return x*x;
    }
    return x*power(x,p-1);
}

int main()
{
    cin>>Numdatasets;
    int B = 0;
    int x = 0;
    int y = 0;
    int n = 0;
    int j = 0;
    int p = 0;
    int temp = 0;
    for (int i = 0; i < Numdatasets; i++)
    {
        vector<int> xBbase;
        vector<int> yBbase;
        cin>>n;
        cin>>B;
        cin>>x;
        cin>>y;
        while (power(B, j)<x)
        {
            if (power(B, j+1) > x)
            {
                break;
            }
            j++;
        }
        //x has j+1 digits in base B
        for (int z = 0; z< j+1;z++)
        {
            xBbase.push_back(0);
        }
        temp = x;
        p = j;
        while (temp!=0)
        {
            if (power(B,p)>temp)
            {
                p--;
                continue;
            }
            for (int w = 1; w<B;w++)
            {
                if (w*power(B,p) == temp)
                {
                    *(xBbase.begin()+p) = w;
                    temp = temp - w*power(B,p);
                    break;
                }
                if (w*power(B,p) < temp && (w+1)*power(B,p) > temp)
                {
                    *(xBbase.begin()+p) = w;
                    temp = temp - w*power(B,p);
                    p--;
                    break;
                }
            }
        }
        j= 0;
        while (power(B, j)<y)
        {
            if (power(B, j+1) > y)
            {
                break;
            }
            j++;
        }
        //y has j+1 digits in base B
        for (int z = 0; z< j+1;z++)
        {
            yBbase.push_back(0);
        }
        temp = y;
        p = j;
        while (temp!=0)
        {
            if (power(B,p)>temp)
            {
                p--;
                continue;
            }
            for (int w = 1; w<B;w++)
            {
                if (w*power(B,p) == temp)
                {
                    *(yBbase.begin()+p) = w;
                    temp = temp - w*power(B,p);
                    break;
                }
                if (w*power(B,p) < temp && (w+1)*power(B,p) > temp)
                {
                    *(yBbase.begin()+p) = w;
                    temp = temp - w*power(B,p);
                    p--;
                    break;
                }
            }
        }
        if (xBbase.size() > yBbase.size())
        {
            for (int m = 0; m< yBbase.size();m++)
            {
                *(xBbase.begin()+m) = (*(xBbase.begin()+m) + *(yBbase.begin()+m)) % B;
            }
            int result = 0;
            for (int m = 0; m< xBbase.size();m++)
            {
                result+=*(xBbase.begin()+m) * power(B,m);
            }
            cout<<i+1<<" "<<result<<endl;
        }
        else
        {
            for (int m = 0; m< xBbase.size();m++)
            {
                *(yBbase.begin()+m) = (*(yBbase.begin()+m) + *(xBbase.begin()+m)) % B;
            }
            int result = 0;
            for (int m = 0; m< yBbase.size();m++)
            {
                result+=*(yBbase.begin()+m) * power(B,m);
            }
            cout<<i+1<<" "<<result<<endl;
        }
    }
    return 0;
}