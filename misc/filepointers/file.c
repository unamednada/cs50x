#include <stdio.h>

int main(void)
{
    FILE* ptr1 = fopen("sample.csv", "r");
    FILE* ptr2 = fopen("sample.csv", "a");

    fputc('a', ptr2);
    fputc('\n', ptr2);
    fclose(ptr2);
    char ch;
    while((ch = fgetc(ptr1)) != EOF)
        printf("%c", ch);
    fclose(ptr1);
}