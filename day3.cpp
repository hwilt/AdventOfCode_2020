#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
string input[324];
int size = 0;

/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day3.txt");
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
    int j = 0;
    for(int i = 0; i < size; i++){
        if(input[i].compare(j, 1, "#") == 0){
            ret++;
        }
        j = (j+3)%31;
    }
    return ret;
}

/*
 * Part Twp for the day
*/
int partTwo(int right, int down) {
    int ret;
    int j = 0;
    for(int i = 0; i < size; i += down){
        if(input[i].compare(j, 1, "#") == 0){
            ret++;
        }
        j = (j+right)%31;
    }
    return ret;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << partTwo(1,1) << endl;
    unsigned int r1d1 = partTwo(1,1);
    cout << partTwo(3,1) << endl;
    unsigned int r3d1 = partTwo(3,1);
    cout << partTwo(5,1) << endl;
    unsigned int r5d1 = partTwo(5,1);
    cout << partTwo(7,1) << endl;
    unsigned int r7d1 = partTwo(7,1);
    cout << partTwo(1,2) << endl;
    unsigned int r1d2 = partTwo(1,2);
    cout << "Part 2: " << endl << "Slope(1,1)" << r1d1 << endl << "Slope(3,1)" << r3d1 << endl << "Slope(5,1)" << r5d1 << endl << "Slope(7,1)" << r7d1 << endl << "Slope(1,2)" << r1d2 << endl;
    unsigned int total = r1d1 * r3d1 * r5d1 * r7d1 * r1d2;
    cout << "Total Multiplied: " << total << endl;
    return 0;
}