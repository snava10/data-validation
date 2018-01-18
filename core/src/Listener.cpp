//
// Created by sergio on 07/01/18.
//

#include "Listener.h"

using namespace schemaparser;

Listener::Listener() {
    context = new Context();
};
Listener::~Listener() {};

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