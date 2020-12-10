#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
string input[10];
int size = 0;
/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day10.txt");
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
    int ret;
    //TODO: Fill this in
    
    
    
    return ret;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int ret;
    //TODO: Fill this in


    return ret;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}