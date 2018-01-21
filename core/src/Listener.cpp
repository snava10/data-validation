//
// Created by sergio on 07/01/18.
//

#include <Nodes.h>
#include "Listener.h"

using namespace schemaparser;

Listener::Listener() : ValidationSchemaBaseListener() {
    context = new Context();
    nodes = vector<Node*>();
};
Listener::~Listener() {};

vector<Node*> Listener::getNodes() {
    return nodes;
}

void Listener::enterSeparator_directive(ValidationSchemaParser::Separator_directiveContext *ctx) {
    ValidationSchemaBaseListener::enterSeparator_directive(ctx);
    context->Delimiter = ctx->children[2]->getText().substr(1,1);
}

void Listener::enterQuoted_directive(ValidationSchemaParser::Quoted_directiveContext *ctx) {
    ValidationSchemaBaseListener::enterQuoted_directive(ctx);
    context->Quoted = true;
}

void Listener::enterNo_header_directive(ValidationSchemaParser::No_header_directiveContext *ctx) {
    ValidationSchemaBaseListener::enterNo_header_directive(ctx);
    context->NoHeader = true;
}

void Listener::enterTotal_columns_directive(ValidationSchemaParser::Total_columns_directiveContext *ctx) {
    ValidationSchemaBaseListener::enterTotal_columns_directive(ctx);
    context->TotalColumns = stoi(ctx->children[2]->getText());
}

void Listener::enterReal_number_expr(ValidationSchemaParser::Real_number_exprContext *ctx) {
    ValidationSchemaBaseListener::enterReal_number_expr(ctx);
    // Need column name
    string columnName = columnDefinitionScope->ColumnName;
    RealNode* realNode = new RealNode(context, columnName);
    nodes.push_back(realNode);
}

void Listener::enterColumn_definition(ValidationSchemaParser::Column_definitionContext *ctx) {
    ValidationSchemaBaseListener::enterColumn_definition(ctx);
    columnDefinitionScope = new ColumnDefinitionScope();
}

void Listener::exitColumn_definition(ValidationSchemaParser::Column_definitionContext *ctx) {
    ValidationSchemaBaseListener::exitColumn_definition(ctx);
    columnDefinitionScope = NULL;
}

void Listener::enterName(ValidationSchemaParser::NameContext *ctx) {
    ValidationSchemaBaseListener::enterName(ctx);
    columnDefinitionScope->ColumnName = ctx->getText();
}
