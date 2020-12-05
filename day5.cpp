#include <iostream>
#include <fstream>

#include <string>
#include <sstream>

#include <vector>
#include <map>
#include <set>
#include <list>

#include <algorithm>
#include <iterator>

using namespace std;

//input for the day
string input[869];
int inSize = 0;

/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day5.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            input[inSize] = line;
            inSize++;
        }
    }
}

void search(const char& c, int& min, int& max) {
    int mid = min + max;
    if (c == 'F' || c == 'L') {
        if (mid%2 == 0) {
            max = mid/2 - 1;
        }
        else {
            max = mid/2;
        }
    }
    else if (c == 'B' || c == 'R') {
        if (mid%2 == 0) {
            min = mid/2;
        }
        else {
            min = mid/2 + 1;
        }
    }
}

int getSeatID(string& line) {
    int minR = 0, maxR = 127;
    int minC = 0, maxC = 7;
    for (int i=0; i<7; ++i) {
    	search(line[i], minR, maxR);
    }
    for (int i=7; i<line.size(); ++i) {
    	search(line[i], minC, maxC);
    }
    return minR * 8 + minC;
}

/*
 * Part One for the day
*/
int partOne() {
    int seatID[inSize + 1];
    int highest = -1;
    for(int i = 0; i < inSize; i++){
        seatID[i] = getSeatID(input[i]);
    }
    for(int i = 0; i < inSize; i++){
        if(seatID[i] > highest){
            highest = seatID[i];
        }
    }
    return highest;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int mySeat = -1;
    vector<int> seatIDs;
    for(int i = 0; i < inSize; i++){
        seatIDs.push_back(getSeatID(input[i]));
    }
    std::sort(seatIDs.begin(), seatIDs.end());

    for(int i = 1; i < seatIDs.size(); i++){
        if (seatIDs[i] - 2 == seatIDs[i-1]){
            mySeat = seatIDs[i] - 1;
        }
            
    }    
    return mySeat;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}