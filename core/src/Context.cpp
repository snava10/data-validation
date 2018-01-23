//
// Created by sergio on 18/01/18.
//

#include "Context.h"

Context::Context() {
    Quoted = false;
    NoHeader = false;
}

Context::~Context() {}

ColumnDefinitionScope::ColumnDefinitionScope() {
    ColumnName = "";
    ColumnIndex = -1;
}

ColumnDefinitionScope::~ColumnDefinitionScope() {}