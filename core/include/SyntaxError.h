//
// Created by sergio on 07/01/18.
//

#ifndef ANTLR4CPP_FETCHER_VALIDATIONERROR_H
#define ANTLR4CPP_FETCHER_VALIDATIONERROR_H

#include <iostream>
#include <antlr4-common.h>
#include "Error.h"

using namespace std;
using namespace antlr4;

class SyntaxError : public Error {
public:
    Token *OffendingSymbol;
    size_t Line;
    size_t CharPositionInLine;
    string Msg;

    SyntaxError(Token *offendingSymbol, size_t line, size_t charPositionInLine, string msg);

};

#endif //ANTLR4CPP_FETCHER_VALIDATIONERROR_H
