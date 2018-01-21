//
// Created by sergio on 19/01/18.
//

#ifndef ANTLR4CPP_FETCHER_NODES_H
#define ANTLR4CPP_FETCHER_NODES_H

#include "Error.h"
#include "Context.h"
#include <vector>
#include <map>
#include <ValidationSchemaBaseListener.h>

using namespace schemaparser;

class Node {
protected:
    Context context;
public:
    Node(Context &context, string &columnName);
    Node(Context &context, int columnIndex);
    ~Node();
    vector<Error> Errors;
    string ColumnName;
    string ColumnIndex;
    virtual void validate(map<string, string> &data)=0;
    virtual void validate(map<int, string> &data)=0;
};

class RealNode: public Node {
    RealNode(Context &context, string &columnName):Node(context, columnName) {}
    RealNode(Context &context, int columnIndex):Node(context, columnIndex) {}
    void validate(map<string, string> &data) override;
    void validate(map<int, string> &data) override;
};
class IntegerNode: public Node {
    IntegerNode(Context &context, string &columnName):Node(context, columnName){}
    IntegerNode(Context &context, int columnIndex):Node(context, columnIndex){}
};

#endif //ANTLR4CPP_FETCHER_NODES_H
