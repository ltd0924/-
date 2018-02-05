#include <stdio.h>
#include <string.h>

int main()
{
    char src[]="*****";
    char dest[]="91054";
    printf("%s\n",dest);
    memcpy(src+1,dest+1,3);
    int a=(1+4)/2;
    printf("%s\n",src);
    printf("%d\n",a);
    return 0;
}
