//
// Created by sergio on 20/01/18.
//

#include "Nodes.h"

Node::Node(Context &contextP, int columnIndex) {
    context = contextP;
    ColumnIndex = columnIndex;
}

Node::Node(Context &contextP, string &columnName) {
    context = contextP;
    ColumnName = columnName;
}

Node::~Node() {
    delete &context;
}

void RealNode::validate(map<int, string> &data) {

}

