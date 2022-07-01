#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "_crossplay.h"
#include "projects/create_open_links/create_links.h"

void open_tabs();

int main(){
    //create_linksFile_v2();
    //open_tabs();

    /*char *parent = parent_folder(__FILE__);

    printf("%s", parent);*/

    printf("%s\n", __FILE__);
    return 0;
}

void open_tabs(){
    char *lnk;

    FILE *f;
    f = open_file(LINKS, "r");

    while (!feof(f)){
        fscanf(f,"%s", lnk);

        open_chrome(lnk);

        pause();
    }
    fclose(f);
}
