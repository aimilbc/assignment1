//
//  csGODs.cpp
//  assignment1
//
//  Created by Aimi Ross on 7/10/20.
//  Copyright © 2020 Aimi Ross. All rights reserved.
//

#include <stdio.h>
#include "csGODs.h"
#include <iostream>
#include <iostream>
#include <cmath>

bool comp(int a, int b)
{
    return (a < b);
}

csGODs::csGODs(){

}

int csGODs::freddy(vector<int> &lists){
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

int csGODs::sophie(vector<int> &lists){
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

int csGODs::johnny(vector<int> &lists, int left, int right){

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
    for (int i = center + 1; i <= right; i++) {
        rightBorder += lists[i];
        if(rightBorder > maxRightBorder)
            maxRightBorder = rightBorder;
    }

    return max({maxLeftSum, maxRightSum, maxLeftBorder + maxRightBorder},comp);
}

int csGODs::sally(vector<int> &lists){
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
