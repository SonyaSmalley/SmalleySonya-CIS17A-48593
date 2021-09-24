/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr - Modified by Sonya Smalley on 9/24/21 @ 13:39
 * Created on September 22nd, 2021, 1:30 PM
 * Purpose:  Compare 1 and 2 Dimensional Vector Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntAry(vector<int>,int); //Print 1D vector array
void prntAry(vector<vector<int>> &); //Print a 2D vector array
void fillAry(vector<int> &,int,int,int); //Fill 1d vector array
void fillAry(vector<vector<int>> &,int,int); //Fill 2d vector array with 0s
void fillAry(vector<vector<int>> &,vector<int> &,int,int); //Fill 2d vector array with 1d vector array
void swap(int &,int &);
void smlLst(vector<int> &,int,int);
void mrkSort(vector<int> &,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    vector<int> array, brray, crray;
    vector<vector<int>> table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillAry(array,rowsize,highRng,lowRng);
    fillAry(brray,rowsize,highRng/10,lowRng/10);
    fillAry(crray,rowsize,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(array,rowsize);
    mrkSort(brray,rowsize);
    mrkSort(crray,rowsize);
    
    //Fill the 2-D array
    fillAry(table,rowsize,colsize);
    fillAry(table,array,rowsize,0);
    fillAry(table,brray,rowsize,1);
    fillAry(table,crray,rowsize,2);
    
    //Print the values in the array
    prntAry(array,perLine);
    prntAry(brray,perLine);
    prntAry(crray,perLine);
    prntAry(table);
    
    //Exit
    return 0;
}

//Fill a 2d vector with a 1d vector
void fillAry(vector<vector<int>> &a,vector<int> &c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

//Fill a 1D vector array
void fillAry(vector<int> &a,int n,int hr,int lr){
    n=n<2?2:n;
    //fill the array
    for(int indx=0;indx<n;indx++){
        a.push_back(rand()%(hr-lr+1)+lr);
    }
}

//Fill 2D vector array with 0s
void fillAry(vector<vector<int>> &a,int rows,int cols){
    //Allocate Memory for 2-D Array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    
    //Fill the array with 0's
    for(int row=0;row<rows;row++){
        a.push_back(vector<int>());
        for(int col=0;col<cols;col++){
            a[row].push_back(0);
        }
    }
}

//Print a 2D vector array
void prntAry(vector<vector<int>> &a){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<a.size();row++){
        for(int col=0;col<a[row].size();col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

//Print 1D vector array
void prntAry(vector<int> a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> &a,int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(vector<int> &a,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}