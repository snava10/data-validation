//
// Created by sergio on 12/01/18.
//

#include "CustomErrorListener.h"

CustomErrorListener::CustomErrorListener() {
    Errors = new vector<SyntaxError>();
}

CustomErrorListener::~CustomErrorListener(){
    delete Errors;
}

void CustomErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                                      size_t charPositionInLine, const string &msg, exception_ptr e) {
    // Token *offendingSymbol, size_t line, size_t charPositionInLine, string msg
    SyntaxError error(offendingSymbol, line, charPositionInLine, msg);
    Errors->push_back(error);

}

vector<SyntaxError>* CustomErrorListener::getErrors() {
    return Errors;
}