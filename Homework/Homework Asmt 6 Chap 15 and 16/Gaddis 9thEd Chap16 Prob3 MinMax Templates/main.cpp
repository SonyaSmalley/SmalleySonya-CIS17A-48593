/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on November 27, 2021, 5:04 PM
 * Purpose: Create Min and Max template functions
 */

//System Libraries
#include <iostream>
using namespace std;

//Template Minimum Function
template <class M>
M minimum(M n1,M n2){
    if (n1<n2)
        return n1;
    else
        return n2;
}

//Template Maximum Function
template <class X>
X maximum(X n1,X n2){
    if (n1>n2)
        return n1;
    else
        return n2;
}

int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int num1=2, num2=4;
    float num3=3, num4=5;
    
    //Display Output
    cout<<"Comparing two integers: "<<num1<<" and "<<num2<<endl;
    cout<<minimum(num1,num2)<<" is the smallest number, and ";
    cout<<maximum(num2,num1)<<" is the largest number."<<endl;
    
    cout<<"Comparing two floats: "<<num3<<" and "<<num4<<endl;
    cout<<minimum(num4,num3)<<" is the smallest number, and ";
    cout<<maximum(num3,num4)<<" is the largest number."<<endl;
    
    return 0;
}