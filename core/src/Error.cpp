//
// Created by sergio on 14/01/18.
//

#include "Error.h"


Error::Error(int lineP, int columnP, string messageP) {
    line = lineP;
    column = columnP;
    message = messageP;
}

