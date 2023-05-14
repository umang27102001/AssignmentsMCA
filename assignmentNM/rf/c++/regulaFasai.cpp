#include <bits/stdc++.h>
using namespace std;
double f(double n)
{
    return (pow(n, 3) - n - 4);
}
double mod(double n){
    if (n<0)
    {
        return (-1)*n;
        /* code */
    }
    return n;
    

}
void RegularFalsi(double a, double b)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "Invalid parametes\n";
    }
    else
    {
        double root = (a * f(b) - b * f(a)) / (f(b) - f(a));

        while (mod(f(root)) >= 0.00005)
        {
            if (f(root) == 0)
            {
                break;
            }
            if (f(root)*f(b) < 0)
            {
                a = root;
            }
            else
            {
                b = root;
            }
            root = (a * f(b) - b * f(a)) / (f(b) - f(a));
            

            /* code */
        }

        cout << "The root of the given equation is : "<<root<<endl;
    }
}
int main()
{

    double a,b;
    cout<<"Enter the first parameter. \n";
    cin>>a;
    cout<<"Enter the second parameter. \n";
    cin>>b;
    RegularFalsi(a, b);

    return 0;
}