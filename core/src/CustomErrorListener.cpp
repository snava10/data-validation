//
// Created by sergio on 12/01/18.
//

#include "CustomErrorListener.h"

using namespace validator;

CustomErrorListener::CustomErrorListener() {
    Errors = new vector<SyntaxError>();
}

CustomErrorListener::~CustomErrorListener(){
    delete Errors;
}

void CustomErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                                      size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
    SyntaxError error(offendingSymbol, line, charPositionInLine, msg);
    Errors->push_back(error);
}