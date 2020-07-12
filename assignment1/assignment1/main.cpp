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
#include "csGODs.h"

using namespace std;

int mainMenu();
void createVector(vector<int> &);
void findMax(vector<int> &);

int main(int argc, const char * argv[]) {
    vector<int> lists;
    int maxNum = 0;

    csGODs algorithms;

    int pickedNum = mainMenu();
    /*=================== Main Menu ===================
     1. Quit the program
     2. Time Freddy's algorithm
     3. Time Sophie's algorithm
     4. Time Johnny's algorithm
     5. Time Sally's algorithm*/

    // executs program while input is not 1
    while (pickedNum != 1){
        
        createVector(lists);
        
        switch (pickedNum) {
            case 2:{
                cout << "Freddy's algorithm" << endl;
                
                auto start = chrono::high_resolution_clock::now();
                maxNum = algorithms.freddy(lists);
                auto end = chrono::high_resolution_clock::now();
                
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }

            case 3:{
                cout << "Sophie's algorithm" << endl;
                
                auto start = chrono::high_resolution_clock::now();
                maxNum = algorithms.sophie(lists);
                auto end = chrono::high_resolution_clock::now();
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }

            case 4:{
                cout << "Johnny's algorithm" << endl;

                auto start = chrono::high_resolution_clock::now();
                //maxNum = (lists.size() > 0) ? algorithms.johnny(lists, 0, lists.size()-1) : 0;    // source from Michael Barela
                if(lists.size() > 0)
                    maxNum = algorithms.johnny(lists, 0, (int)lists.size()-1);
                auto end = chrono::high_resolution_clock::now();
                cout << "max subarray is " << maxNum << "." << endl;
                chrono::duration<float> duration = end - start;
                cout << duration.count() * 1000.0f << "ms" << endl;
                lists.clear();
                break;
            }

            case 5:{
                cout << "Sally's algorithm" << endl;

                auto start = chrono::high_resolution_clock::now();
                maxNum = algorithms.sally(lists);
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


//int main(int argc, const char * argv[]) {
//
//
//
//    vector<int> lists1;
//    vector<int> lists2;
//    vector<int> lists3;
//    vector<int> lists4;
//    vector<int> lists5;
//    vector<int> lists6;
//
//    mt19937 mt_rand(1);
//    uniform_int_distribution<int> rangeSet(-100, 100);
//    uniform_int_distribution<int> rangeSet2(-100, 0);
//    uniform_int_distribution<int> rangeSet3(0, 100);
//
//    // test case 1: some + and some - with array size 10
//    for (int i = 0; i < 10; i++){
//        lists1.push_back(rangeSet(mt_rand));
//    }
//
//    // test case 2: some + and some - with array size 11
//    for (int i = 0; i < 11; i++){
//        lists2.push_back(rangeSet(mt_rand));
//    }
//
//    // test case 3 is already defined at the top(an array with no valuse)
//
//    // test case 4: all - with array size 10
//    for (int i = 0; i < 10; i++){
//        lists4.push_back(rangeSet2(mt_rand));
//    }
//
//    // test case 5: all 0 with array size 10
//    for (int i = 0; i < 10; i++){
//        lists5.push_back(0);
//    }
//
//    // test case 6: all + with array size 10
//    for (int i = 0; i < 10; i++){
//        lists6.push_back(rangeSet3(mt_rand));
//    }
//
//    findMax(lists1);
//    findMax(lists2);
//    findMax(lists3);
//    findMax(lists4);
//    findMax(lists5);
//    findMax(lists6);
//
//
//    return 0;
//}
//
//void findMax(vector<int> &lists){
//    csGODs algorithms;
//
//    int maxNum1 = algorithms.freddy(lists);
//    cout << "Freddy found max subarray is " << maxNum1 << "." << endl;
//
//    int maxNum2 = algorithms.sophie(lists);
//    cout << "Sophie found max subarray is " << maxNum2 << "." << endl;
//
//    int maxNum3;
//    if(lists.size() > 0)
//        maxNum3 = algorithms.johnny(lists, 0, (int)lists.size()-1);
//    else
//        maxNum3 = 0;
//    cout << "Johnny found max subarray is " << maxNum3 << "." << endl;
//
//    int maxNum4 = algorithms.sally(lists);
//    cout << "Sally found max subarray is " << maxNum4 << "." << endl;
//}
//
