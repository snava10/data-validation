//
// Created by sergio on 07/01/18.
//

#include "ValidationError.h"

ValidationError::ValidationError(int lineP, int columnP, string messageP) {
    line = lineP;
    column = columnP;
    message = messageP;
}
