void print_inFile_v1(FILE *arq, int number[7]){
    int i = 0;

    fprintf(arq,"%s",LINK);
    while (i < 7){
        fprintf(arq,"%c",number[i++]);
    }
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

void create_linksFile_v1(){
    remove(LINKS);
    FILE *f_source = open_file(SOURCE,"r");
    FILE *f_new = fopen(LINKS,"w");

    seek_patrimony_number_v1(f_source, f_new);

    fclose(f_source);
    fclose(f_new);
}
