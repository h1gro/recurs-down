#ifndef GIPERCHITCKA
#define GIPERCHITCKA

#include <stdio.h>

const int EXPR_SIZE        = 1000;
const int SCAN_FILE_POISON = 153153;
const int NO_SPACE         = 109901;
const int SIZE_COMMAND     = 153;
const double EPSILON       = 1E-6;

struct expr_t
{
    char* string;
    int   index;
};

struct file_t
{
    FILE*  file_ptr;
    size_t file_size;
    size_t index_buf;
    char*  buffer;
};

int CheckFile             (FILE* file);
int GetG                  (struct expr_t* expr);
int GetN                  (struct expr_t* expr);
int GetE                  (struct expr_t* expr);
int GetT                  (struct expr_t* expr);
int GetP                  (struct expr_t* expr);
int IsEqual               (double elem1, double elem2);

void ClearBuffer          ();
void SyntaxError          ();
void CheckFclose          (FILE* file_ptr);
void ExprDtor             (struct expr_t* expr);
void ExprCtor             (struct expr_t* expr);
void SystemWithIntArg     (const char* str, int number_dump);
void ChangeSymbolInBuffer (char* buffer, size_t size_buffer, char symbol1, char symbol2);

size_t ScanFile           (struct file_t* akin, struct expr_t* expr);
size_t FindNoSpace        (struct file_t* akin, size_t index);
size_t SkipSpacesForPrint (struct file_t* akin, size_t index);

void BufferCtor           (struct file_t* tree, struct expr_t* expr);

#endif
