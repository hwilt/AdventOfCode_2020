#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
string input;

/*
 * Gets the input out of the file and into a string
*/
string getInput() {
    string out;
    ifstream file("input/day20.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            out += line;
        }
    }
    return out;
}

/*
 * Part One for the day
*/
int partOne(string in) {
    int ret;
    //TODO: Fill this in
    
    
    
    return ret;
}

/*
 * Part Twp for the day
*/
int partTwo(string in) {
    int ret;
    //TODO: Fill this in


    return ret;
}

int main() {
    input = getInput();
    cout << partOne(input) << endl;
    cout << partTwo(input);
    return 0;
}