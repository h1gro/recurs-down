#include <stdlib.h>
#include <assert.h>

#include "Giperchitka.h"

int GetG(struct expr_t* expr)
{
    assert(expr);
    assert(expr->string);
    assert(expr->index >= 0);

    int val = GetE(expr);

    if (expr->string[expr->index] != '$')
    {
        printf("done\n");
        SyntaxError();
        expr->index++;
    }

    return val;
}

int GetN(struct expr_t* expr)
{
    assert(expr);
    assert(expr->string);
    assert(expr->index >= 0);

    int val = 0;

    int old_p = expr->index;

    while (('0' <= expr->string[expr->index]) && (expr->string[expr->index] <= '9'))
    {
        val = val * 10 + expr->string[expr->index] - '0';
        expr->index++;
    }

    if (old_p == expr->index)
    {
        printf("done\n");
        SyntaxError();
    }

    return val;
}

int GetE(struct expr_t* expr)
{
    assert(expr);
    assert(expr->string);
    assert(expr->index >= 0);

    int val = GetT(expr);

    while ((expr->string[expr->index] == '+') || (expr->string[expr->index] == '-'))
    {
        int op = expr->string[expr->index];
        expr->index++;
        int val2 = GetT(expr);

        if (op == '+')
        {
            val += val2;
        }

        else
        {
            val -= val2;
        }
    }

    return val;
}

int GetT(struct expr_t* expr)
{
    assert(expr);
    assert(expr->string);
    assert(expr->index >= 0);

    int val = GetP(expr);

    while ((expr->string[expr->index] == '*') || (expr->string[expr->index] == '/'))
    {
        int op = expr->string[expr->index];
        expr->index++;
        int val2 = GetP(expr);

        if (op == '*')
        {
            val *= val2;
        }

        else
        {
            val /= val2;
        }
    }

    return val;
}

int GetP(struct expr_t* expr)
{
    assert(expr);
    assert(expr->string);
    assert(expr->index >= 0);

    if (expr->string[expr->index] == '(')
    {
        expr->index++;
        int val = GetE(expr);

        if (expr->string[expr->index] != ')')
        {
            printf("done\n");
            SyntaxError();
        }

        expr->index++;
        return val;
    }
    else
    {
        return GetN(expr);
    }
}

void SyntaxError()
{
    //printf("done\n");
    exit(0);
}
