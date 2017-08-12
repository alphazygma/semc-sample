//
//  Jump.hpp
//  semc-cpp-sample
//
//  Created by Alejandro B. Salazar on 8/11/17.
//  Copyright © 2017 Alejandro B. Salazar. All rights reserved.
//

#ifndef Jump_hpp
#define Jump_hpp

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

namespace Generic {
namespace Pointer{
    /**
     * Simple class interface to handle fractions
     * @author Alejandro B. Salazar
     */
    class Jump {
    private:
        vector<void (*)()> _funcPtrList;
        vector<string> _funcNameList;

        /** Prints the prompt options. */
        void _printPrompt();
        
        /** 
         * Get's the user input as a standar C string
         * @return the user input
         */
        char * _getInput();
        
        /**
         * Get's the user input as a standar C++ string
         * @return the user input
         */
        string _getStrInput();
        
        void _jumpExecDelegate(int inputChar);
        
    public:
        Jump(vector<void (*)()> funcPtrList, vector<string> funcNameList);
        
        const char * prompt();
        const string strPrompt();
        
        int jump( const char * rs );
        int strJump( const string & rs );
        
    };
} // namespace Pointer
} // namespace Generic

#endif /* Jump_hpp */
