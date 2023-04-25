//Anthony Lim
//1221618450
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MM.h"
#include <iostream>
#include <vector>
using namespace std;

vector<NODE*> localList;

void Push(NODE* node) {
    localList.insert(localList.begin(), node);
}

void EraseFront() {
    localList.erase(localList.begin());
}

bool isEmpty() {
    if (localList.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void Print(float x) {
    cout<<"Key values on local list:" << endl;
    for (int i = 0; i<x; i++) {
        try {
        cout<<localList.at(i)->key<<"\n";
        }
        catch (out_of_range) {
            break;
        }
        
    }
}