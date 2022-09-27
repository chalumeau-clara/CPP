//
// Created by clara on 22/09/22.
//
#include <iostream>
using namespace std;
// I use the Knuth–Morris–Pratt algorithm
#include "find_motive.h"

// Create the fallback list
void preTraitment(string motive, int f[]) {
    int lmotive = motive.length();
    int i = 1, j = 0;
    f[0] = 0; // list fallback
    while (i < lmotive) {
        if (motive[i] == motive[j]) {
            f[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
            j = f[j-1];
        else
            f[i] = 0;
            i++;
    }
}

// search the motive in the text
int find_motive(string text, string motive) {
    int ltext = text.length();
    int lmotive = motive.length();
    if (lmotive > ltext) return 0;

    int f[lmotive]; // list fallback
    preTraitment(motive, f); // construct the fallback list
    int i = 0,j = 0;

    int count = 0;
    while (i < ltext) {
        if (text[i] == motive[j]) {
            i++;
            j++;
            if (j == lmotive) { // find
                count++;
                j = 0;
                i++;
            }
        }
        else {
            if (j == 0) i++;
            else j = f[j];
        }
    }
    return count;
}