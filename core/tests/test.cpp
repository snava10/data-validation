#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include "ValidationSchemaParser.h"
#include "gtest/gtest.h"
#include "Validator.h"
#include <fstream>

using namespace std;
using namespace schemaparser;
using namespace antlr4;
using namespace tree;
using namespace validator;

TEST(case1, name1) {
    ASSERT_TRUE(1);
};

TEST(case1, validator_initialization){
    string schema = "version 1.1";
    Validator* validator = new Validator(schema);
    ASSERT_TRUE(validator);
}

TEST(syntactic, any){
    ifstream infile;
    infile.open("resources/syntactic/any.csvs");
    string schema;
    if(infile.good()){
        stringstream buffer;
        buffer << infile.rdbuf();
        schema = buffer.str();
        cout << "Schema " << schema << endl;

        Validator* validator = new Validator(schema);
    }

    infile.close();


}

