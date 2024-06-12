#include <stdio.h>
int main() {

    int num,sum=0,prevnum;
    scanf("%d",&num);
    prevnum=num-1;
    while(num!=-1)
    {
       if(prevnum!=num)
       {
           sum++;
           prevnum=num;
       }
       scanf("%d",&num);
    }
    printf("%d",sum);
    return 0;
}
