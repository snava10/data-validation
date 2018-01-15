//
// Created by sergio on 14/01/18.
//

#ifndef ANTLR4CPP_FETCHER_ERROR_H
#define ANTLR4CPP_FETCHER_ERROR_H


#include <iostream>
#include <antlr4-common.h>

using namespace std;
using namespace antlr4;

class Error {

public:
    int column, line;
    string message;

    Error(int lineP, int columnP, string messageP);
};


#endif //ANTLR4CPP_FETCHER_ERROR_H
