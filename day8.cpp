#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//input for the day
string input[9];
int size = 0;
/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day8.txt");
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
    int accumulator = 0;
    string line = "";
    int token;
    int i = 0;
    vector<int> visited;
    while(i < size){
        line = input[i];
        token = stoi(line.substr(line.find(" ")));
        line.erase(line.find(" "));
        if(line.compare("nop") == 0){
            visited.push_back(i);
            i++;
        }
        else if(line.compare("acc") == 0){
            visited.push_back(i);
            accumulator += token;
            i++;
        }
        else if(line.compare("jmp") == 0){
            visited.push_back(i);
            i += token;
        }
        sort(visited.begin(), visited.end());
        if(binary_search(visited.begin(), visited.end(), i)){
            break;
        }
    }
    return accumulator;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int accumulator = 0;
    string line = "";
    int token;
    int i = 0;
    vector<int> visited;
    while(i < size){
        line = in[i];
        token = stoi(line.substr(line.find(" ")));
        line.erase(line.find(" "));
        if(line.compare("nop") == 0){
            visited.push_back(i);
            i++;
        }
        else if(line.compare("acc") == 0){
            visited.push_back(i);
            accumulator += token;
            i++;
        }
        else if(line.compare("jmp") == 0){
            visited.push_back(i);
            i += token;
        }
        sort(visited.begin(), visited.end());
        if(binary_search(visited.begin(), visited.end(), i)){
            break;
        }
    }
    return -1;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}