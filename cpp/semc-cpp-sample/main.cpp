#include <iostream>
#include <cstdio>
#include <vector>

#include "use_rational.hpp"
#include "Generic/Pointer/Jump.hpp"
#include "Data/Providers/DataProviderFactory.hpp"

using namespace std;
using namespace Data::Providers;

void fa() { puts("Some random string for `fa`"); }
void fb() { puts("Just printing this string"); }

/**
 * Small function just to show use of variable arguments function
 */
double variadicAverage(const int count, ...)
{
    va_list ap;
    int i;
    double total = 0.0;
    
    va_start(ap, count);
    for(i = 0; i < count; ++i) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / count;
}

int main(int argc, const char * argv[]) {
    
    // ---------------------------------------------------------------------------------------------
    cout << "Processing variadic average function" << endl;
    int size = 5;
    printf("avg of (3, 6, 7, 8, 50) = %f\n", variadicAverage(size, 3.0, 6.0, 7.0, 8.0, 50.0));
    
    // Using different ways to print a new line, just for sample purposes, in actual application,
    // a standard way should be used for code consistency.
    cout << endl << endl;

    
    // ---------------------------------------------------------------------------------------------
    cout << "Processing example of provider with Factory" << endl;
    
    DataProviderFactory dpFactory;
    DataProviderInterface * dp = dpFactory.getProvider(DataProviderFactory::ProviderTypeEnum::TEST);
    
    vector<vector<string>> data = dp->getData();
    
    for (auto row : data) {
        for (auto col : row) {
            printf("%s\t", col.c_str());
        }
        printf("\n");
    }
    
    cout << endl << endl;
    

    // ---------------------------------------------------------------------------------------------
    cout << "Processing Prompt with Jump functions" << endl;
    
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