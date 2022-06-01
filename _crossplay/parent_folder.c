#include <string.h>
#include <stdio.h>

int main(){
    char *parent;
    strcpy(parent, __FILE__);

    int i = strlen(__FILE__);
    while (__FILE__[i] != '\\' && parent[i] != '/' )
        i--;

    parent[i]=0;

    printf("%s\n", __FILE__);
    printf("%s\n", parent);

    return 0;
}
