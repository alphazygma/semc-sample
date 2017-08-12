#include <iostream>
#include <cstdio>

#include "Jump.hpp"

using namespace std;
using namespace Generic::Pointer;

// ---------------------------------------------------------------------------
// Implementing private methods

void Jump::_printPrompt() {
    puts("---------------------------------------");
    puts("Choose an option:");
    int i = 0;
    for (auto fnPair : _fnDataList) {
        printf("%d. Function %s()\n", ++i, fnPair.second.c_str());
    }
    puts("Q. Quit.");
}

char * Jump::_getInput() {
    fflush(stdout);                      // flush after prompt
    const int buffsz = 16;               // constant for buffer size
    static char jump_response[buffsz];   // static storage for response buffer
    fgets(jump_response, buffsz, stdin); // get response from console
    
    return jump_response;
}

string Jump::_getStrInput() {
    char * jumpInput = _getInput();
    string sResponse(jumpInput);
    
    return sResponse;
}

void Jump::_jumpExecDelegate(int inputChar) {
    // Decreasing the input by one to have a matching index
    int idx = inputChar - 1;
    
    // Adding a new line just for formatting
    cout << endl;
    
    if (idx < 0 || idx >= _fnDataList.size()) {
        puts("invalid choice");
    } else {
        printf("Calling : %s()\n", _fnDataList.at(idx).second.c_str());;
        _fnDataList.at(idx).first();
    }
    
    cout << endl;
}

// ---------------------------------------------------------------------------
// Implementing public methods & constructor

Jump::Jump(vector<pair<void (*)(), string>> fnDataList) {
    _fnDataList  = fnDataList;
}

const char * Jump::prompt() {
    _printPrompt();
    return _getInput();
}

const string Jump::strPrompt() {
    _printPrompt();
    return _getStrInput();
}

int Jump::jump( const char * rs ) {
    char code = rs[0];
    if(code == 'q' || code == 'Q') {
        return 0;
    }
    
    int inputChar = (int)code - '0';   // convert ASCII numeral to int
    
    _jumpExecDelegate(inputChar);
    return 1;
}

int Jump::strJump( const string & rs ) {
    string code = rs.substr(0, 1);
    if(code == "q" || code == "Q") {
        return 0;
    }

    int inputChar = stoi(code);
    
    _jumpExecDelegate(inputChar);
    return 1;
}
