#include <ValidationSchemaLexer.h>
#include "Validator.h"

using namespace tree;
using namespace validator;

Validator::Validator(string &schema, int verbose) {
    _schema = schema;
    initialize(verbose);
}

Validator::~Validator() {
    delete listener;
    delete _parser;
    delete _tree;

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
    errorListener = new CustomErrorListener();
    _parser = new ValidationSchemaParser(tokens);
    _parser -> removeErrorListeners();
    _parser->addErrorListener(errorListener);
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

vector<Error> Validator::validate(string &filePath) {
    vector<Error> errors;
    return errors;
}