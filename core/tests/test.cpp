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

// The fixture for testing class Foo.
    class SyntacticTest : public ::testing::Test {
    protected:

        string folderPath;

        SyntacticTest() {
            // You can do set-up work for each test here.
            folderPath = "resources/syntactic/";
        }

        virtual ~SyntacticTest() {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
            folderPath = "resources/syntactic/";
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
    };

    TEST_F(SyntacticTest, PossitiveTestsOnly) {

        for(auto& p: fs::directory_iterator(folderPath)) {
            ifstream infile;
            infile.open(p.path().string());
            string schema;
            if(infile.good()){
                stringstream buffer;
                buffer << infile.rdbuf();
                schema = buffer.str();
                // cout << "Schema " << schema << endl;
                Validator* validator = new Validator(schema);
                EXPECT_EQ(0, validator->errorListener->getErrors()->size());
            }
            infile.close();
        }
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
