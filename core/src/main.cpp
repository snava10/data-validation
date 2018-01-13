#include <iostream>
#include <antlr4-runtime.h>
#include <Validator.h>
#include "ValidationSchemaParser.h"
#include "ValidationSchemaLexer.h"

using namespace std;
using namespace validator;

int main(){
    string schema = "version 1.1";
    Validator* validator = new Validator(schema);
    return 0;
}
