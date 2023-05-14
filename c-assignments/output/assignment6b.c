
#include <stdio.h>
#include <stdlib.h>
struct rectangle{
    int l;
    int b
};
union square{
    int s;
};
int areaR(struct rectangle r){
    return r.l*r.b;
}
int areaS(union square s){
    return s.s*s.s;
}
int main()
{   
    struct rectangle r1={2,3};
    union square s={3};
    printf("The area of rectangle: %d\n",areaR(r1));
    printf("The area of square: %d\n",areaS(s));
    return 0;
}