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
            std::ostringstream stringStream;
            stringStream << "Cannot covert " << value << " to a real number, it has trailing letters\n";
            errors.push_back(Error(ColumnIndex, ColumnIndex, stringStream.str()));
        }
    }
    catch (const invalid_argument& ia) {
        //ToDo improve the error message
        std::ostringstream stringStream;
        stringStream << "Cannot covert " << value << " to a real number\n";
        Error error(ColumnIndex, ColumnIndex, stringStream.str());
        errors.push_back(error);
    }
    catch (const std::out_of_range& oor) {
        std::ostringstream stringStream;
        stringStream << value << " is out of range\n";
        Error error(ColumnIndex, ColumnIndex, stringStream.str());
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
            std::ostringstream stringStream;
            stringStream << "Cannot covert " << value << " to a real number, it has trailing letters\n";
            errors.push_back(Error(ColumnIndex, ColumnIndex, stringStream.str()));
        }
    }
    catch (const invalid_argument& ia) {
        //ToDo improve the error message
        std::ostringstream stringStream;
        stringStream << "Cannot covert " << value << " to a real number\n";
        Error error(ColumnIndex, ColumnIndex, stringStream.str());
        errors.push_back(error);
    }
    catch (const std::out_of_range& oor) {
        std::ostringstream stringStream;
        stringStream << value << " is out of range\n";
        Error error(ColumnIndex, ColumnIndex, stringStream.str());
        errors.push_back(error);
    }
    return errors;
}

