//
// Created by sergio on 21/01/18.
//

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include "ValidationSchemaParser.h"
#include "gtest/gtest.h"
#include "Validator.h"
// #include <filesystem>
#include <experimental/filesystem>
#include <fstream>
#include <iostream>


using namespace std;
using namespace schemaparser;
using namespace antlr4;
using namespace tree;
using namespace validator;

namespace fs = std::experimental::filesystem ;

namespace {

    class ValidationTest : public ::testing::Test {
    protected:

        string folderPath;

        ValidationTest() {
            // You can do set-up work for each test here.
            folderPath = "resources/validation/";
        }

        virtual ~ValidationTest() {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
            folderPath = "resources/validation/";
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
    };

    TEST_F(ValidationTest, RealNumberValid) {
        ifstream infile;
        infile.open(folderPath + "realNumber.csvs");
        string schema;
        if(infile.good()){
            stringstream buffer;
            buffer << infile.rdbuf();
            schema = buffer.str();
            Validator* validator = new Validator(schema);

            map<string, string> data;
            data["acolumn"] = "123.456";
            data["bcolumn"] = "131.4376";

            vector<Error> errors = validator->validate(data);
            ASSERT_EQ(0, errors.size());
        }
        infile.close();
    }

    TEST_F(ValidationTest, RealNumberInvalid) {
        ifstream infile;
        infile.open(folderPath + "realNumber.csvs");
        string schema;
        if(infile.good()){
            stringstream buffer;
            buffer << infile.rdbuf();
            schema = buffer.str();
            Validator* validator = new Validator(schema);

            map<string, string> data;
            data["acolumn"] = "asda";
            data["bcolumn"] = "131.435a";

            vector<Error> errors = validator->validate(data);
            ASSERT_EQ(errors.size(), 2);
            cout << errors[0].message;
            cout << errors[1].message;
        }
        else{
            cout << "File not found";
        }
        infile.close();
    }
}