#include <ValidationSchemaLexer.h>
#include "Validator.h"

using namespace tree;
using namespace validator;

Validator::Validator(string &schema) {
    _schema = schema;
    initialize(1);
}

void Validator::initialize(int verbose) {
    ANTLRInputStream* input = new ANTLRInputStream(_schema);
    ValidationSchemaLexer* lexer = new ValidationSchemaLexer(input);
    CommonTokenStream* tokens = new CommonTokenStream(lexer);
    tokens->fill();
    if(verbose){
        for (auto token : tokens->getTokens()) {
            std::cout << token->toString() << std::endl;
        }
    }
    _parser = new ValidationSchemaParser(tokens);
    _tree = _parser->schema();
    ParseTreeListener* listener = new Listener();
    tree::ParseTreeWalker treeWalker = tree::ParseTreeWalker();
    treeWalker.walk(listener, _tree);
}

ValidationSchemaParser* Validator::getParser() {
    return _parser;
}

ParseTree* Validator::getTree() {
    return _tree;
}

vector<ValidationError> Validator::validate(string &filePath) {
    vector<ValidationError> errors;
    return errors;
}