//HM_ex_2_19.05.2023
#include <iostream> 
#include <fstream> 
#include <string> 
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;
int main() 
{
    ifstream source("source.txt");
    ofstream result("result.txt");
    string words;
    if (!source.is_open()) {
        cerr << "Could not open input file!";
        return 1;
    }
    else
    {
        if (!result.is_open()) 
        {
            cerr << "Could not create output file!";
            return 1;
        }
        else
        {
            while (getline(source, words)) 
            {
                result << words << endl;
            }
            result.close();
        }
        source.close();
    }
    return 0;
}