#include <stdio.h>

int main()
{
    FILE *fp; 
    long int size=0;

    fp=fopen("temp.txt","r");

    fseek(fp,0,SEEK_END);

    size=ftell(fp);

    if(size!=-1)
        printf("File size is: %ld\n",size);
    else
        printf("There is some ERROR.\n");

    return 0;
}
