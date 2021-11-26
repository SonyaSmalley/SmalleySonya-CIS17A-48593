/* 
 * File:   Numbers.cpp
 * Author: Sonya Smalley 
 * Created on November 9, 2021, 6:39 PM
 * Purpose: Create a Numbers class
 */

#include "Numbers.h"
#include <iostream>
#include <string>
using namespace std;

//Definitions of static variables
string Numbers::ones[10]={"zero","one","two","three","four","five","six",
                "seven","eight","nine"};
string Numbers::teens[10]={"ten","eleven","twelve","thirteen","fourteen",
                "fifteen","sixteen","seventeen","eighteen","nineteen"};
string Numbers::tens[8]={"twenty","thirty","forty","fifty","sixty",
                "seventy","eighty","ninety"};
string Numbers::hundrd="hundred";
string Numbers::thousnd="thousand";

Numbers::Numbers(int n){
    while (n<0 || n<1000 || n>9999){
        cout<<"Invalid entry. Please enter a non-negative four-digit integer: ";
        cin>>n;
    }
    number=n;
    
}

Numbers::print(){
    //Output the thousands
    cout<<ones[number/1000]<<" "<<thousnd<<" ";
    
    //Output the hundreds
    if (number/100%10==0)
            cout<<"";
    else
        cout<<ones[number/100%10]<<" "<<hundrd<<" ";
    
    //Output the tens and ones
    if (number/10%10==0){ //output if tens place is 0
        if (number%10==0)
            cout<<endl;
        else
            cout<<ones[number%10]<<endl;
    }
    else if (number/10%10==1){ //output if tens place is a one
        cout<<teens[number%10]<<endl;
    }
    else if (number/10%10>1){ //output if tens place is greater than one
        cout<<tens[(number/10%10)-2];
        if (number%10==0)
            cout<<endl;
        else
            cout<<ones[number%10]<<endl;
    }
}
