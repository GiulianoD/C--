
void print_inFile_v2(FILE *arq, int number){
    int i = 0;

    fprintf(arq,"%s%d\n",LINK, number);
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

void create_linksFile_v2(){
    remove(LINKS);
    FILE *f_source = open_file(SOURCE,"r");
    FILE *f_new = fopen(LINKS,"w");

    seek_patrimony_number_v2(f_source, f_new);

    fclose(f_source);
    fclose(f_new);
}
