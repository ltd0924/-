#include <stdio.h>
#include <string.h>

int main()
{
    char src[]="********";
    char dest[]="asdfghjklzxc";
    printf("%s\n",dest);
    memcpy(dest,src,strlen(src));
    printf("%s\n",dest);
    return 0;
}
