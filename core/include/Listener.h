//
// Created by sergio on 07/01/18.
//

#ifndef ANTLR4CPP_FETCHER_LISTENER_H
#define ANTLR4CPP_FETCHER_LISTENER_H

#include <antlr4-runtime.h>
#include <ValidationSchemaBaseListener.h>
#include "Context.h"
#include "Nodes.h"

using namespace schemaparser;

class Listener : public ValidationSchemaBaseListener {
protected:
    vector<Node*>* nodes;
public:
    Context *context;
    ColumnDefinitionScope *columnDefinitionScope;
    Listener();
    ~Listener();
    vector<Node*>* getNodes();
    void enterSeparator_directive(ValidationSchemaParser::Separator_directiveContext *ctx) override;
    void enterQuoted_directive(ValidationSchemaParser::Quoted_directiveContext *ctx) override;
    void enterNo_header_directive(ValidationSchemaParser::No_header_directiveContext *ctx) override;
    void enterTotal_columns_directive(ValidationSchemaParser::Total_columns_directiveContext *ctx) override;
    void enterReal_number_expr(ValidationSchemaParser::Real_number_exprContext *ctx) override;
    void enterColumn_definition(ValidationSchemaParser::Column_definitionContext *ctx) override;
    void exitColumn_definition(ValidationSchemaParser::Column_definitionContext *ctx) override;
    void enterName(ValidationSchemaParser::NameContext *ctx) override;
};

#endif //ANTLR4CPP_FETCHER_LISTENER_H
