/* 
 * File: main
 * Author: Sonya Smalley
 * Created on September 29, 2021, 8:24 PM
 * Purpose: Create a budget report based on a user's monthly spending
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Spending //Monthly Spending Categories
{
    float housing, //housing
          utlts, //utilities
          houshld, //household expenses
          transp, //transportation
          food, //food
          med, //medical
          insr, //insurance
          ent, //entertainment
          clthng, //clothing
          misc; //miscellaneous
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData(Spending &); //Get the aamounts spent in each budget category during a month
void showDat(Spending,Spending); //Displays a report indicating the amount over or under budget in each category

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Spending month; //A month of expenses
    Spending budget={500.0,150.0,65.0,50.0,250.0,30.0,100.0,150.0,75.0,50.0}; //Monthly budget
    
    //Initialize Variables
    getData(month);
    
    //Process or map Inputs to Outputs
    showDat(month,budget);
    //Display Outputs

    //Exit stage right!
    return 0;
}

//Pass in the Monthly Budget Structure and populate the month's expenses
void getData(Spending &costs) //Get the amounts spent in each budget category during a month
{
    cout<<"Enter housing cost for the month:$\n";
    cin>>costs.housing;
    cout<<"Enter utilities cost for the month:$\n";
    cin>>costs.utlts;
    cout<<"Enter household expenses cost for the month:$\n";
    cin>>costs.houshld;
    cout<<"Enter transportation cost for the month:$\n";
    cin>>costs.transp;
    cout<<"Enter food cost for the month:$\n";
    cin>>costs.food;
    cout<<"Enter medical cost for the month:$\n";
    cin>>costs.med;
    cout<<"Enter insurance cost for the month:$\n";
    cin>>costs.insr;
    cout<<"Enter entertainment cost for the month:$\n";
    cin>>costs.ent;
    cout<<"Enter clothing cost for the month:$\n";
    cin>>costs.clthng;
    cout<<"Enter miscellaneous cost for the month:$\n";
    cin>>costs.misc;
}

//Pass in the month's spending and the monthly budget
void showDat(Spending m,Spending budg) //Displays a report indicating the amount over or under budget in each category
{
    
    float delta=0.0, //How much above or below budget was each expense this month
         deltTot=0.0; //How much above or below budget were expenses this months
    
    //Find the amounts over/under budget for each expense category
    //Housing
    delta=budg.housing-m.housing;
    deltTot+=delta;
    cout<<"Housing "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Utilities
    delta=budg.utlts-m.utlts;
    deltTot+=delta;
    cout<<"Utilities "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Household expenses
    delta=budg.houshld-m.houshld;
    deltTot+=delta;
    cout<<"Household Expenses "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Transportation
    delta=budg.transp-m.transp;
    deltTot+=delta;
    cout<<"Transportation "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Food
    delta=budg.food-m.food;
    deltTot+=delta;
    cout<<"Food "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Medical
    delta=budg.med-m.med;
    deltTot+=delta;
    cout<<"Medical "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Insurance
    delta=budg.insr-m.insr;
    deltTot+=delta;
    cout<<"Insurance "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Entertainment
    delta=budg.ent-m.ent;
    deltTot+=delta;
    cout<<"Entertainment "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Clothing
    delta=budg.clthng-m.clthng;
    deltTot+=delta;
    cout<<"Clothing "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
    //Miscellaneous
    delta=budg.misc-m.misc;
    deltTot+=delta;
    cout<<"Miscellaneous "<<((delta==0.0)?"Even":(delta>0.0)?"Under":"Over")<<endl;
   
    //Display the delta for the month's expenses vs the month's budget
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"You were $"<<deltTot<<((deltTot<0.00)?" over":(deltTot>0.00)?" under":" exactly on")<<" budget";
}