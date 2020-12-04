#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
string input[25];
int size = 0;
string required[7] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
int resize = 6;
/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day4.txt");
    if (file.is_open()) {
        string line;
        string already;
        while(getline(file, line)){
            if(line.length() != 1){
                input[size] += line;
            }
            else{
                size++;
            }
        }
    }
}

/*
 * Part One for the day
*/
int partOne() {
    int ret = 0;
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << "input["
        cout << "input[" << i << "]: " << input[i] << endl;
    }
    
    
    return ret;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int ret = 0;
    //TODO: Fill this in


    return ret;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}