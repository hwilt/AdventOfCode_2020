#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
string input;

/*
 * Part One for the day
*/
int partOne() {
    int ret;
    int* x = new int[6];
    int i = 0;
    ifstream file("input/day1.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            x[i] = stoi(line);
            i++;
        }
    }
    file.close();
    for(int k = 0; k < 6; k++){
        if()
    }
    
    
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
    cout << partOne() << endl;
    cout << partTwo();
    return 0;
}