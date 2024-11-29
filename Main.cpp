#include <stdlib.h>
#include <string.h>

#include "Giperchitka.h"

static const char* EXPR_FILE = "Expression.txt";

int main()
{
    struct expr_t expression = {};
    struct file_t file_expr = {};

    file_expr.file_ptr = fopen(EXPR_FILE, "r");

    ExprCtor(&expression);

    if (ScanFile(&file_expr, &expression) == SCAN_FILE_POISON)
    {
        return -1;
    }

    for (int i = 0; i < file_expr.file_size; i++)
    {
        printf("%c", expression.string[i]);
    }
    printf("\n");

    int result = 0;

    result = GetG(&expression);

    printf("%d\n", result);

    ExprDtor(&expression);
    return 0;
}
//
// int GetG(struct expr_t* expr)
// {
//     int val = GetE(expr);
//
//     if (expr->string[expr->index] != '$')
//     {
//         printf("done\n");
//         SyntaxError();
//         expr->index++;
//     }
//
//     return val;
// }
//
// int GetN(struct expr_t* expr)
// {
//     int val = 0;
//
//     int old_p = expr->index;
//
//     if (('0' <= expr->string[expr->index]) && (expr->string[expr->index] <= '9'))
//     {
//         val = expr->string[expr->index] - '0';
//         expr->index++;
//     }
//
//     if (old_p == expr->index)
//     {
//         printf("done\n");
//         SyntaxError();
//     }
//
//     return val;
// }
//
// int GetE(struct expr_t* expr)
// {
//     int val = GetT(expr);
//
//     while ((expr->string[expr->index] == '+') || (expr->string[expr->index] == '-'))
//     {
//         int op = expr->string[expr->index];
//         expr->index++;
//         int val2 = GetT(expr);
//
//         if (op == '+')
//         {
//             val += val2;
//         }
//
//         else
//         {
//             val -= val2;
//         }
//     }
//
//     return val;
// }
//
// int GetT(struct expr_t* expr)
// {
//     int val = GetP(expr);
//
//     while ((expr->string[expr->index] == '*') || (expr->string[expr->index] == '/'))
//     {
//         int op = expr->string[expr->index];
//         expr->index++;
//         int val2 = GetP(expr);
//
//         if (op == '*')
//         {
//             val *= val2;
//         }
//
//         else
//         {
//             val /= val2;
//         }
//     }
//
//     return val;
// }
//
// int GetP(struct expr_t* expr)
// {
//     if (expr->string[expr->index] == '(')
//     {
//         expr->index++;
//         int val = GetE(expr);
//
//         if (expr->string[expr->index] != ')')
//         {
//             printf("done\n");
//             SyntaxError();
//         }
//
//         expr->index++;
//         return val;
//     }
//     else
//     {
//         return GetN(expr);
//     }
// }
//
// void SyntaxError()
// {
//     //printf("done\n");
//     exit(0);
// }
//
