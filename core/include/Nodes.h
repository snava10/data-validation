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

enum NodeKind {
    REAL_NODE,
    INTEGER_NODE
};

class Node {
protected:
    Context* context;
    NodeKind nodeKind;
public:
    Node(Context *pContext, const string columnName);
    Node(Context *pContext, int columnIndex);
    ~Node();
    vector<Error> Errors;
    string ColumnName;
    int ColumnIndex;
    virtual void validate(map<string, string> &data)=0;
    virtual void validate(map<int, string> &data)=0;
    NodeKind getNodeKind();
};

class RealNode: public Node {
public:
    RealNode(Context *pContext, const string columnName) : Node(pContext, columnName) { nodeKind = REAL_NODE; }
    RealNode(Context *pContext, int columnIndex) : Node(pContext, columnIndex) { nodeKind = REAL_NODE; }
    ~RealNode(){}

    void validate(map<string, string> &data) override;
    void validate(map<int, string> &data) override;
};
class IntegerNode: public Node {
public:
    IntegerNode(Context *context, const string& columnName):Node(context, columnName){ nodeKind = INTEGER_NODE; }
    IntegerNode(Context* context, int columnIndex):Node(context, columnIndex){ nodeKind = INTEGER_NODE; }
};

#endif //ANTLR4CPP_FETCHER_NODES_H
