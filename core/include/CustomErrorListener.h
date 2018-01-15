//
// Created by sergio on 12/01/18.
//

#ifndef ANTLR4CPP_FETCHER_CUSTOMERRORLISTENER_H
#define ANTLR4CPP_FETCHER_CUSTOMERRORLISTENER_H

#include <antlr4-runtime.h>
#include "SyntaxError.h"

using namespace antlr4;
using namespace std;


class CustomErrorListener : public BaseErrorListener {

protected:
    vector<SyntaxError> *Errors;
public:
    CustomErrorListener();
    ~CustomErrorListener();
    virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol,
                                        size_t line, size_t charPositionInLine,
                                        const string &msg, exception_ptr e) override;
    vector<SyntaxError> *getErrors();
};


#endif //ANTLR4CPP_FETCHER_CUSTOMERRORLISTENER_H
