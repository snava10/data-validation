//
// Created by sergio on 07/01/18.
//

#ifndef ANTLR4CPP_FETCHER_VALIDATIONERROR_H
#define ANTLR4CPP_FETCHER_VALIDATIONERROR_H

#include <iostream>

using namespace std;

class ValidationError {
public:
    int column, line;
    string message;

    ValidationError(int lineP, int columnP, string messageP);

};


#endif //ANTLR4CPP_FETCHER_VALIDATIONERROR_H
