//
//  main.cpp
//  assignment1
//
//  Created by Aimi Ross on 7/8/20.
//  Copyright © 2020 Aimi Ross. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

int mainMenu();
void createVector(vector<int> &);
int freddy(vector<int> &);
int sophie(vector<int> &);
int johnny(vector<int> &, int, int);
int sally(vector<int> &);
bool comp(int a, int b)
{
    return (a < b);
}

int main(int argc, const char * argv[]) {
    vector<int> lists;
    int maxNum = 0;
    
    int pickedNum = mainMenu();
    /*=================== Main Menu ===================
     1. Quit the program
     2. Time Freddy's algorithm
     3. Time Sophie's algorithm
     4. Time Johnny's algorithm
     5. Time Sally's algorithm*/
    
    // executs program while input is not 1
    while (pickedNum != 1){
        switch (pickedNum) {
            case 2:{
                cout << "Freddy's algorithm" << endl;

                createVector(lists);
//                for (int element : lists){
//                    cout << element << endl;
//                }
                auto start = chrono::high_resolution_clock::now();
                maxNum = freddy(lists);
                auto end = chrono::high_resolution_clock::now();
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }
                
            case 3:{
                cout << "Sophie's algorithm" << endl;
                
                createVector(lists);
//                for (int element : lists){
//                    cout << element << endl;
//                }
                auto start = chrono::high_resolution_clock::now();
                maxNum = sophie(lists);
                auto end = chrono::high_resolution_clock::now();
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }
                
            case 4:{
                cout << "Johnny's algorithm" << endl;
                
                createVector(lists);
//                for (int element : lists){
//                    cout << element << endl;
//                }
                auto start = chrono::high_resolution_clock::now();
                maxNum = johnny(lists, 0, lists.size()-1);
                auto end = chrono::high_resolution_clock::now();
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }
                
            case 5:{
                cout << "Sally's algorithm" << endl;
                
                createVector(lists);
//                for (int element : lists){
//                    cout << element << endl;
//                }
                auto start = chrono::high_resolution_clock::now();
                maxNum = sally(lists);
                auto end = chrono::high_resolution_clock::now();
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }
            default:{
                cout << "--- Wrong input. Enter between 1-5. ---" << endl;
                break;
            }
        }
        pickedNum = mainMenu();
    }
    
    return 0;
}

int mainMenu(){
    int pickedNum = 0;
    
    cout << "\n=================== Main Menu ===================" << endl;
    cout << "1. Quit the program" << endl;
    cout << "2. Time Freddy's algorithm" << endl;
    cout << "3. Time Sophie's algorithm" << endl;
    cout << "4. Time Johnny's algorithm" << endl;
    cout << "5. Time Sally's algorithm" << endl;
    cout << "Enter an integer: ";
    cin >> pickedNum;
    
    return pickedNum;
}

void createVector(vector<int> &lists){
    
    int size,seed;
    cout << "Seed: ";
    cin >> seed;
    cout << "Size: ";
    cin >> size;
    
    mt19937 mt_rand(seed);
    uniform_int_distribution<int> rangeSet(-100, 100);
    
    for (int i = 0; i < size; i++){
        lists.push_back(rangeSet(mt_rand));
    }
    
}

int freddy(vector<int> &lists){
    int max = 0;
    
    for (int i = 0; i < lists.size(); i++){
        for (int j = i; j < lists.size(); j++){
            int thisSum = 0;
            for(int k = i; k <= j; k++)
                thisSum += lists[k];
            if (thisSum > max)
                max = thisSum;
        }
    }
    return max;
}

int sophie(vector<int> &lists){
    int max = 0;
    
    for (int i = 0; i < lists.size(); i++){
        int thisSum = 0;
        for(int j = i; j < lists.size(); j++){
            thisSum += lists[j];
            if(thisSum > max)
                max = thisSum;
        }
    }
    
    return max;
}

int johnny(vector<int> &lists, int left, int right){
    
    if (left == right) {
        if(left > 0)
            return lists[left];
        return 0;
    }
    
    int center = floor((left + right)/2);
    int maxLeftSum = johnny(lists, left, center);
    int maxRightSum = johnny(lists, center + 1, right);
    
    int maxLeftBorder = 0;
    int leftBorder = 0;
    for (int i = center; i >= left; i--) {
        leftBorder += lists[i];
        if(leftBorder > maxLeftBorder)
            maxLeftBorder = leftBorder;
    }
    
    int maxRightBorder = 0;
    int rightBorder = 0;
    for (int i = center + 1; i < right; i++) {
        rightBorder += lists[i];
        if(rightBorder > maxRightBorder)
            maxRightBorder = rightBorder;
    }
    
    return max({maxLeftSum, maxRightSum, maxLeftBorder + maxRightBorder},comp);
}

int sally(vector<int> &lists){
    int max = 0;
    int thisSum = 0;
    for(int i = 0; i < lists.size(); i++){
        thisSum += lists[i];
        if(thisSum > max)
            max = thisSum;
        else if(thisSum<0)
            thisSum = 0;
    }
    return max;
}
