
#include <stdio.h>
#include <stdlib.h>
void swap(char *p1, char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main()
{
    char word[5] = "umang";
    int i = 0;
    int j = 4;
    for (; i <= j; i++, j--)
    {
        swap(&word[i], &word[j]);
    }
    word[5] = '\0';
    printf("%s", word);
    return 0;
}