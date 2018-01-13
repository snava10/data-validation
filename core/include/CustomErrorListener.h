//
// Created by sergio on 12/01/18.
//

#ifndef ANTLR4CPP_FETCHER_CUSTOMERRORLISTENER_H
#define ANTLR4CPP_FETCHER_CUSTOMERRORLISTENER_H

#include <antlr4-runtime.h>

using namespace antlr4;
using namespace std;

namespace validator {

    class Error {

    };

    class SyntaxError : public Error {
    public:
        Token *OffendingSymbol;
        size_t Line;
        size_t CharPositionInLine;
        string &Msg;

        SyntaxError(Token *offendingSymbol, size_t line, size_t charPositionInLine, string msg);

    };

    class CustomErrorListener : public BaseErrorListener {

    protected:
        vector<SyntaxError> *Errors;
    public:
        CustomErrorListener();
        ~CustomErrorListener();
        void BaseErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol,
                                            size_t line, size_t charPositionInLine,
                                            const string &msg, exception_ptr e);
    };
}

#endif //ANTLR4CPP_FETCHER_CUSTOMERRORLISTENER_H
