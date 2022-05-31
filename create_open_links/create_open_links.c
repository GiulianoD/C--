#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SOURCE "dell.txt"
#define LINKS "links.txt"
#define LINK "https://sistemas.tjes.jus.br/patrimonio/inventario/consulta-materiais.php?numero_patrimonio="

void print_inFile(FILE *arq, int number[7]);
void print_inFile_v2(FILE *arq, int number);
FILE *open_file(const char *path, const char *mode);
void seek_patrimony_number_v1(FILE *f_source, FILE *f_new);
void seek_patrimony_number_v2(FILE *f_source, FILE *f_new);
void create_linksFile_v1();
void create_linksFile_v2();
void open_tabs();

void print_inFile_v1(FILE *arq, int number[7]){
    int i = 0;

    fprintf(arq,"%s",LINK);
    while (i < 7){
        fprintf(arq,"%c",number[i++]);
    }
}

void print_inFile_v2(FILE *arq, int number){
    int i = 0;

    fprintf(arq,"%s%d\n",LINK, number);
}

FILE *open_file(const char *path, const char *mode){
    FILE *f = fopen(path, mode);

    if (f) return f;
    fclose(f);

    printf("File not found. Please verify the path:\n%s\n\nError on line %d\n", path, __LINE__);
    system("pause");
    exit(0);
}

void seek_patrimony_number_v1(FILE *f_source, FILE *f_new){ /*using an integer array*/
    int id[7];
    id[6]='\n'; /*the last character of every array will be a BreakLine char*/
    int i = 0;
    int char_number;

    while ((char_number = getc(f_source)) != EOF){
        /*when the program succesfully get a patrimony number*/
        if (i>=6) {
            i = 0;
            print_inFile_v1(f_new, id);
            fscanf(f_source,"%*[^\n]\n");
        }

        /*ignoring the whole line, as it doesn't starts with a number*/
        if (char_number < '0' || char_number > '9'){
            fscanf(f_source,"%*[^\n]\n");
        }

        /*when the program finds a number*/
        if (i< 6 && char_number >= '0' && char_number <= '9'){
            id[i] = char_number;
            i++;
        }
    }
}

void seek_patrimony_number_v2(FILE *f_source, FILE *f_new){ /*using an integer and NOT array*/
    int id = 0;
    int i = 0;
    int char_number;

    while ((char_number = getc(f_source)) != EOF){
        /*when the program succesfully get a patrimony number*/
        if (i>=6) {
            print_inFile_v2(f_new, id);
            fscanf(f_source,"%*[^\n]\n");
            id= 0;
            i = 0;
        }

        /*ignoring the whole line, as it doesn't starts with a number*/
        if (char_number < '0' || char_number > '9'){
            fscanf(f_source,"%*[^\n]\n");
        }

        /*when the program finds a number*/
        if (i< 6 && char_number >= '0' && char_number <= '9'){
            id += (char_number-'0') * pow(10,5-i);
            i++;
        }
    }
}

void create_linksFile_v1(){
    remove(LINKS);
    FILE *f_source = open_file(SOURCE,"r");
    FILE *f_new = fopen(LINKS,"w");

    seek_patrimony_number_v1(f_source, f_new);

    fclose(f_source);
    fclose(f_new);
}

void create_linksFile_v2(){
    remove(LINKS);
    FILE *f_source = open_file(SOURCE,"r");
    FILE *f_new = fopen(LINKS,"w");

    seek_patrimony_number_v2(f_source, f_new);

    fclose(f_source);
    fclose(f_new);
}

void open_tabs(){
    char cmd[111];
    char lnk[98];

    FILE *arq;
    arq = open_file(LINKS, "r");

    while (!feof(arq)){
        fscanf(arq,"%s", lnk);
        strcpy(cmd,"start chrome ");
        strcat(cmd, lnk);

        system(cmd);
        system("pause");
    }
    fclose(arq);
}

int main(){
    create_linksFile_v2();
    open_tabs();

    return 0;
}
