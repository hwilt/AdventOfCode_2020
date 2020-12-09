#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
int input[1000];
int size = 0;
int preamble = 25;
/*
 * Gets the input out of the file and into a string
*/
void getInput() {
    ifstream file("input/day9.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            input[size] = atoi(line.c_str());
            size++;
        }
    }
}

/*
 * Part One for the day
*/
int partOne() {
    int weakness = 0;
    for(int i = preamble; i < size; i++){
        bool valid = false;
        for(int first = 0; first < preamble; first++){
            for(int second = 0; second < preamble; second++){
                if(input[i] == (input[first + i - preamble] + input[second + i - preamble])){
                    valid = true;
                    break;         
                }
            }
        }
        if(!valid){
            weakness = input[i];
            break;
        }
    }
    return weakness;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int ret = 0;
    int invalid = partOne();
    int smallest = 2147483647;
    int largest = 0;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            ret += input[j];
            if(smallest > input[j]){
                smallest = input[j];
            }
            if(largest < input[j]){
                largest = input[j];
            }

            if(ret == invalid && j > 2){
                break;
            }
            else if(ret > invalid){
                ret = 0;
                smallest = 2147483647;
                largest = 0;
                break;
            }
        }
        if(ret == invalid){
            break;
        }
    }
    ret = smallest + largest;
    return ret;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}