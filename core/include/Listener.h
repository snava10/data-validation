//
// Created by sergio on 07/01/18.
//

#ifndef ANTLR4CPP_FETCHER_LISTENER_H
#define ANTLR4CPP_FETCHER_LISTENER_H

#include <antlr4-runtime.h>
#include <ValidationSchemaBaseListener.h>

using namespace schemaparser;

namespace validator {

    class Listener : public ValidationSchemaBaseListener {
    public:
        virtual void ValidationSchemaListener::enterBody(ValidationSchemaParser::BodyContext *ctx);
    };

}
#endif //ANTLR4CPP_FETCHER_LISTENER_H
