/* 
 * File:   Numbers.cpp
 * Author: Sonya Smalley 
 * Created on November 9, 2021, 6:39 PM
 * Purpose: Create a Numbers class
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
using namespace std;

class Numbers {
private:
    int number;
    static string ones[10];
    static string teens[10];
    static string tens[8];
    static string hundrd;
    static string thousnd;
public:
    Numbers(int n);
    print();
};


#endif /* NUMBERS_H */

