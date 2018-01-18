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
    cout << ctx->children[2]->getText().substr(1,1);
}

