#ifndef VALIDATOR_VALIDATOR_H
#define VALIDATOR_VALIDATOR_H

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include "ValidationSchemaParser.h"
#include "ValidationError.h"
#include "Listener.h"

using namespace std;
using namespace schemaparser;
using namespace antlr4;
using namespace tree;

namespace validator{

    class Validator {
    private:
        void initialize(int verbose);
    protected:
        string _schema;
        ValidationSchemaParser* _parser;
        ParseTree* _tree;
        Listener* listener;

    public:
        Validator(string& schema);
        vector<ValidationError> validate(string& filePath);
        ParseTree* getTree();
        ValidationSchemaParser* getParser();
    };
}

#endif
