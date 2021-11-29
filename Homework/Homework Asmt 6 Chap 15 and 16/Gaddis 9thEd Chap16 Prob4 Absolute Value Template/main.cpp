/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on November 28, 2021, 12:38 PM
 * Purpose: Create and demonstrate an absolute value template function
 */

#include <iostream>
using namespace std;

template <class A>
A absVal(A num){
    if (num>=0)
        return num;
    else{
        num*=-1;
        return num;
    }
}

int main(int argc, char** argv) {
    //Declare variables
    int n1=2, n2=-3;
    float n3=2.2f, n4=-3.3;
    
    //Display output
    cout<<"The absolute value of "<<n1<<" is "<<absVal(n1)<<endl;
    cout<<"The absolute value of "<<n2<<" is "<<absVal(n2)<<endl;
    cout<<"The absolute value of "<<n3<<" is "<<absVal(n3)<<endl;
    cout<<"The absolute value of "<<n4<<" is "<<absVal(n4)<<endl;
    
    return 0;
}

