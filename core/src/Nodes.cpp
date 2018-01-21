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

vector<Error> RealNode::validate(map<int, string> &data) {
    string value = data[ColumnIndex];
    vector<Error> errors = vector<Error>();
    try {
        size_t idx;
        stod(value, &idx);
        if (value.size() != idx){
            errors.push_back(Error(ColumnIndex, ColumnIndex, "Cannot convert value to double, has trailing letters"));
        }
    }
    catch (const invalid_argument& ia) {
        //ToDo improve the error message
        Error error(ColumnIndex, ColumnIndex, "Cannot convert value to double");
        errors.push_back(error);
    }
    catch (const std::out_of_range& oor) {
        Error error(ColumnIndex, ColumnIndex, "The values results is out of the range of double");
        errors.push_back(error);
    }
    return errors;
}

vector<Error> RealNode::validate(map<string, string> &data) {
    string value = data[ColumnName];
    vector<Error> errors = vector<Error>();
    try {
        size_t idx;
        stod(value, &idx);
        if (value.size() != idx){
            errors.push_back(Error(ColumnIndex, ColumnIndex, "Cannot convert value to double, has trailing letters"));
        }
    }
    catch (const invalid_argument& ia) {
        //ToDo improve the error message
        Error error(ColumnIndex, ColumnIndex, "Cannot convert value to double");
        errors.push_back(error);
        cout << ia.what();
    }
    catch (const std::out_of_range& oor) {
        Error error(ColumnIndex, ColumnIndex, "The values results is out of the range of double");
        errors.push_back(error);
    }
    return errors;
}

