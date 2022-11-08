#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <conio.h> // getch & putch

#define ASCII_BKSPC 8 // backspack on ascII
#define ASCII_LNBRK 10 // line break on ascII
#define ASCII_ENTER 13 // enter on ascII
#define PSS_LIMIT 30 // limit size of the password (in characters)
#define PSS_CH '*' // character to be shown as passwork mask
#define CLR "cls" // string to be passed as param to system() in order to clear the console (differs on each OS)

int main(){
    char c;
    char *password = malloc(PSS_LIMIT);
    char current_size = 0;
    int aux;

    while (1){
        c = getch();

        if (c == ASCII_ENTER){ // verify if the char entered was the enter key
            password[current_size] = 0;
            break;
        }

        if (c == ASCII_BKSPC){ // verify if the char entered was a backspace
            if (current_size) current_size--;

        } else // if we manage to get in here, so the character typed is part of the password

        if (current_size < PSS_LIMIT){ // check if the pass have reached the limit already
            password[current_size++] = c;
        }

        system(CLR);
        aux = 0;
        while (aux++ < current_size) // print on screen
            putch(PSS_CH);
    }

    printf("\n");
    printf("%s", password);
    free(password);
    getch();

    return 0;
}
