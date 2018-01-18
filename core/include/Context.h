//
// Created by sergio on 18/01/18.
//

#ifndef ANTLR4CPP_FETCHER_CONTEXT_H
#define ANTLR4CPP_FETCHER_CONTEXT_H

#include <string>

using namespace std;

class Context {
public:
    string Delimiter;
    bool Quoted;
    bool NoHeader;
    int TotalColumns;

    Context();
    ~Context();
};

#endif //ANTLR4CPP_FETCHER_CONTEXT_H
