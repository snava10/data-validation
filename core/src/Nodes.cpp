//
// Created by sergio on 20/01/18.
//

#include "Nodes.h"

Node::Node(Context *pContext, int columnIndex) {
    context = pContext;
    ColumnIndex = columnIndex;
}

Node::Node(Context *pContext, const string columnName) {
    context = pContext;
    ColumnName = columnName;
}

Node::~Node() {
    delete context;
}

NodeKind Node::getNodeKind() {
    return nodeKind;
}

void RealNode::validate(map<int, string> &data) {
    string value = data[ColumnIndex];

    try {
        stod(value);
    }
    catch (const invalid_argument& ia) {
        //ToDo improve the error message
        Error *error = new Error(ColumnIndex, ColumnIndex, "Cannot convert value to double");
        Errors.push_back(*error);
    }
    catch (const std::out_of_range& oor) {
        Error *error = new Error(ColumnIndex, ColumnIndex, "The values results is out of the range of double");
        Errors.push_back(*error);
    }
}
void RealNode::validate(map<string, string> &data) {
}

