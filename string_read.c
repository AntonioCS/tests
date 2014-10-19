/* 
 * File:   string_read.c
 * Author: antoniocs
 *
 * Created on 19 de Outubro de 2014, 22:27
 */

#include <stdio.h>
#include <stdlib.h>

#define STRING_INIT_SIZE 15

typedef struct string {
    char *str;
    int size;
    int length;
    int increase_by; //will have the default of 15 but can be customized per instance
} string, *pstring;

pstring string_init(void);
void string_add(pstring, char *);
void string_resize(pstring);
void string_destroy(pstring);

pstring string_init() {
    pstring newstr = malloc(sizeof(string));
    
    if (newstr != NULL) {
        newstr->str = calloc(STRING_INIT_SIZE, sizeof(char));
        if (newstr->str == NULL) {
            perror("Unable to allocate space for string");
            exit(-1);
        }

        newstr->increase_by = newstr->size = STRING_INIT_SIZE;
        newstr->length = 0;

        return newstr;
    }
    
    return NULL;
}

void string_add(pstring string, char *p) {
    while (*p) {
        string->str[string->length++] = *p++;
         
        if (string->length == string->size) {
            string_resize(string);
        }
    }
    
    string->str[string->length] = '\0';    
}

void string_resize(pstring string) {    
    char *tmp_buffer = realloc(string->str, (string->size += string->increase_by));
    
    if (tmp_buffer) {
        string->str = tmp_buffer;
    }
    else {
        perror("Unable to reallocate memory");
        exit(-1);
    }
}

void string_destroy(pstring string) {
    free(string->str);    
    free(string);
}

/*
 * 
 */
int main(int argc, char** argv) {

    pstring teste = string_init();
    if (teste) {
        FILE *fp = fopen("wildcards.c", "r");    

        if (fp) {
            int c;
            while ((c = fgetc(fp)) != EOF) {
                string_add(teste, (char *)&c);            
            }

            printf("Dados: %s\n", teste->str);
            printf("Size: %d\n", teste->size);
            printf("Length: %d\n", teste->length);
        }

        string_destroy(teste);
    }
    
    return (EXIT_SUCCESS);
}

