//
// Created by sergio on 07/01/18.
//

#ifndef ANTLR4CPP_FETCHER_LISTENER_H
#define ANTLR4CPP_FETCHER_LISTENER_H

#include <antlr4-runtime.h>
#include <ValidationSchemaBaseListener.h>
#include "Context.h"

using namespace schemaparser;

class Listener : public ValidationSchemaBaseListener {
public:
    Context *context;
    Listener();
    ~Listener();
    void enterSeparator_directive(ValidationSchemaParser::Separator_directiveContext *ctx) override;
    void enterQuoted_directive(ValidationSchemaParser::Quoted_directiveContext *ctx) override;
    void enterNo_header_directive(ValidationSchemaParser::No_header_directiveContext *ctx) override;
    void enterTotal_columns_directive(ValidationSchemaParser::Total_columns_directiveContext *ctx) override;
};

#endif //ANTLR4CPP_FETCHER_LISTENER_H
