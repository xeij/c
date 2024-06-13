#include <stdio.h>
int main()
{
    int n,a=1,b=0;
    printf("Enter a number here: ");
    scanf("%d",&n);
    while(a<n)
    {
        if(n%a==0)
            b+=a;
        a++;
    }
    if(b==n)
        printf("\nIt is a PERFECT number!\n");
    else
        printf("\nIt is NOT a PERFECT number!\n");
return 0;
}
