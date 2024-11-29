#include <stdlib.h>
#include <assert.h>

#include "Giperchitka.h"

void ExprCtor(struct expr_t* expr)
{
    expr->string = (char*) calloc(EXPR_SIZE, sizeof(char));

    assert(expr->string);
}

void ExprDtor(struct expr_t* expr)
{
    free(expr->string);

    expr->index = 0;
}

