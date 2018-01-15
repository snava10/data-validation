//
// Created by sergio on 07/01/18.
//

#include "SyntaxError.h"

SyntaxError::SyntaxError(Token *offendingSymbol, size_t line, size_t charPositionInLine, string msg)
        : Error(line, charPositionInLine, msg) {
    this->OffendingSymbol = offendingSymbol;
    this->Line = line;
    this->CharPositionInLine = charPositionInLine;
    this->Msg = msg;
}

