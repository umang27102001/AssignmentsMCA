#include <stdio.h>
#include <math.h>
float CI(int p, int r, int t)
{
    float R = (1 + r / 100.0);
    printf("\n%f\n",R);
    R = pow(R, t);
    float ans = p * R;
    return ans-p;
}
float SI(int p, int r, int t)
{
    return (p * r * t) / 100.0;
}
int main()
{
    int p, r, t, interest;
    float ans;
    printf("Enter 0 for Compound Iterest\n");
    printf("Enter 1 for Simple Iterest\n");
    scanf("%d", &interest);
    if (interest == 0)
    {
        printf("Enter Principal\n");
        scanf("%d", &p);
        printf("Enter Rate\n");
        scanf("%d", &r);
        printf("Enter Time in years\n");
        scanf("%d", &t);
        ans = CI(p, r, t);
        printf("The Compound Interest is: %0.3f \n", ans);
    }
    else
    {
        printf("Enter Principal\n");
        scanf("%d", &p);
        printf("Enter Rate\n");
        scanf("%d", &r);
        printf("Enter Time in years\n");
        scanf("%d", &t);
        ans = SI(p, r, t);
        printf("The Simple Interest is: %0.3f \n", ans);
    }
    return 0;
}