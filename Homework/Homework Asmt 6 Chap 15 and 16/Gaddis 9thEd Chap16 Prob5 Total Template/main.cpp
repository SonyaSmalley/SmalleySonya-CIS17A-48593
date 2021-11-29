/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on November 28, 2021, 12:48 PM
 * Purpose: Create a total function
 */

#include <iostream>
using namespace std;

template <class T>
T total(T num1, T num2){
    static T sum=0; //do static variables not work the same for templates?
    
    sum+=num1+num2;
    
    return sum;
}


int main(int argc, char** argv) {
    //Declare variables
    int n1,n2;
    float n3,n4;
    
    //Initialize variables
    cout<<"Enter two integers to be summed: ";
    cin>>n1>>n2;
    
    //Call total
    cout<<total(n1,n2)<<endl;
    
    //Get new number
    cout<<"Enter two doubles to be summed: ";
    cin>>n3>>n4;
    
    //Call total
    cout<<total(n3,n4)<<endl;
    
    return 0;
}

