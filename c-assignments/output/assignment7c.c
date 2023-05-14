
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f = fopen("myText.txt", "a+");
    if (!f)
    {
        printf("Error crating File\n");
    }
    fputs("hello this is umang", f);
    fputs("hello this is umang kanchan", f);
    char str[100];
    fgets(str, 50, f);
    printf("%s", str);
    free(f);
    return 0;
}