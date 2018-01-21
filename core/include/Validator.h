#ifndef VALIDATOR_VALIDATOR_H
#define VALIDATOR_VALIDATOR_H

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include "ValidationSchemaParser.h"
#include "SyntaxError.h"
#include "Listener.h"
#include "CustomErrorListener.h"

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
        Validator(string& schema, int verbose=0);
        ~Validator();
        vector<Error> validate(string& filePath);
        vector<Error> validate(map<string, string> data);
        vector<Error> validate(map<int, string> data);
        ParseTree* getTree();
        ValidationSchemaParser* getParser();
        Listener* getListener();
        CustomErrorListener* errorListener;
    };
}

#endif
