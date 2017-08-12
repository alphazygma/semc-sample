#include <iostream>
#include <cstdio>
#include <vector>
#include "use_rational.hpp"
#include "libs/Generic/Pointer/Jump.hpp"

using namespace std;

void fa() { puts("Some random string for `fa`"); }
void fb() { puts("Just printing this string"); }

int main(int argc, const char * argv[]) {
    
    // Creating a list that contains the function pointer and the name of it for display on the prompt
    vector<pair<void (*)(), string>> fnDataList = {
        {fa, "fa"},
        {fb, "fb"},
        {printUseRational, "printUseRational"}
    };
    
/*
 This comment is just to keep a reference of the previous way I used to use the function pointer 
 list as a vector and a separate vector for the function names, and though it worked, it was
 lengthy and also increased the possibility of more errors due to having the vectors separate
 and using a more complicated constructor before C++11
 
    // Creating a list of function pointers that will be use for the Jump functionality
    void (*funcList[])() = {
        // Including two simple functions
        fa, fb,
        
        // Including a funtion related to Rational numbers that show Class functionality
        // as well as operator overloading
        printUseRational
    };
    // Now converting the function pointers array to a vector so it is easier to handle
    // instead of having to use the `nullptr` last element trick and pre-loop to determine the
    // array size
    vector<void (*)()> funcPtrList(funcList, funcList + sizeof(funcList)/sizeof(funcList[0]));
    
    // Since we can't obtain the name of a function from it's pointer, but we want to
    // show them for the prompt, we create a new list that contains the name of the functions
    string nameList[] = { "fa", "fb", "printUseRational" };
    vector<string> funcNameList(nameList, nameList + sizeof(nameList)/sizeof(string));
 */
    
    Generic::Pointer::Jump jumper(fnDataList);
    
    while( jumper.jump(jumper.prompt()) );
    
    return 0;
}