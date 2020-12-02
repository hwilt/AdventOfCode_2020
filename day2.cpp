#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

//input for the day
string input[1000];
int size = 0;

/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day2.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            input[size] = line;
            size++;
        }
    }
    
}

/*
 * Part One for the day
*/
int partOne() {
    int ret = 0;
    int high;
    int low;
    char character;
    string inputline;
    int count = 0;
    for(int i = 0; i < size; i++){
        low = stoi(input[i].substr(0,input[i].find("-")));
        high = stoi(input[i].substr(input[i].find("-")+1,input[i].find(" ")-1));
        character = input[i][input[i].find(" ")+1];
        inputline = input[i].substr(input[i].rfind(" ")+1);
        for (int j = 0; j < (int)inputline.size(); j++)
        {
            if (inputline[j] == character){
                count++;
            }
        }
        if (count >= low && count <= high){
            ret++;
        }
        count = 0;
    }
    return ret;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int ret = 0;
    int high;
    int low;
    char character;
    string inputline;
    for(int i = 0; i < size; i++){
        low = stoi(input[i].substr(0,input[i].find("-")));
        high = stoi(input[i].substr(input[i].find("-")+1,input[i].find(" ")-1));
        character = input[i][input[i].find(" ")+1];
        inputline = input[i].substr(input[i].rfind(" ")+1);
        char char1 = inputline[low - 1];
        char char2 = inputline[high - 1];
        if (char1 == character && char2 != character){
            ret++;
        }
        else if (char1 != character && char2 == character){
            ret++;
        }
    }
    return ret;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}