#ifndef CREATE_LINKS_H
#define CREATE_LINKS_H

#define SOURCE "create_open_links/source.txt"
#define LINKS "create_open_links/links.txt"
#define LINK "https://sistemas.tjes.jus.br/patrimonio/inventario/consulta-materiais.php?numero_patrimonio="

#include "functions/create_links_v1.c"
#include "functions/create_links_v2.c"

void print_inFile(FILE *arq, int number[7]);
void print_inFile_v2(FILE *arq, int number);
void seek_patrimony_number_v1(FILE *f_source, FILE *f_new);
void seek_patrimony_number_v2(FILE *f_source, FILE *f_new);
void create_linksFile_v1();
void create_linksFile_v2();

#endif
