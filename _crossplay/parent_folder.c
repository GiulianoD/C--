#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *parent_folder(char *path){
    int i = strlen(path);
    char *parent = malloc(i);
    strcpy(parent, path);

    while (path[i] != '\\' && parent[i] != '/' )
        i--;

    parent[i]=0;

    printf("%s\n", path);
    printf("%d", sizeof(path));
    printf("%s\n", parent);

    return parent;
}
