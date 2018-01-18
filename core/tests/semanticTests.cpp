//
// Created by sergio on 18/01/18.
//

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include "ValidationSchemaParser.h"
#include "gtest/gtest.h"
#include "Validator.h"
#include <experimental/filesystem>

using namespace std;
using namespace schemaparser;
using namespace antlr4;
using namespace tree;
using namespace validator;

namespace fs = std::experimental::filesystem ;


namespace {

// The fixture for testing class Foo.
    class SemanticTest : public ::testing::Test {
    protected:

        string folderPath;

        SemanticTest() {
            // You can do set-up work for each test here.
        }

        virtual ~SemanticTest() {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
            folderPath = "resources/semantic/";
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }
    };

    TEST_F(SemanticTest, SeparatorDirective) {
        ifstream infile;
        infile.open(folderPath + "globalDirectives.csvs");
        string schema;
        if(infile.good()){
            stringstream buffer;
            buffer << infile.rdbuf();
            schema = buffer.str();
            Validator* validator = new Validator(schema);
            EXPECT_EQ(";", validator->getListener()->context->Delimiter);
        }
        infile.close();
    }
}