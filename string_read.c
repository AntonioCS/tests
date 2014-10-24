/* 
 * File:   string_read.c
 * Author: antoniocs
 *
 * Created on 19 de Outubro de 2014, 22:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRING_INIT_SIZE 15

//http://www.cprogramming.com/tutorial/unicode.html

typedef struct string {
    char *str;
    int size;
    int length;
    int increase_by; //will have the default of 15 but can be customized per instance
} string, *pstring;

pstring string_init(void);
void string_add_char(pstring, int);
void string_add_str(pstring, char *);
void string_resize(pstring);
void string_destroy(pstring);
void string_clear(pstring);
void string_is_resize_needed(pstring, int);

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

void string_add_char(pstring string, int c) {
    
    if (string_is_resize_needed(string, 1)) {
        string_resize(string);
    } 
    
    string->str[string->length++] = c;    
}

void string_add_str(pstring string, char *str) {    
    int len = strlen(str);
    
    while (string_is_resize_needed(string, len)) {
        string_resize(string);
    }
    
    memcpy(string->str + string->length, str, len);    
}

bool string_is_resize_needed(pstring s, int len_to_add) {        
    return (s->length + len_to_add) >= s->size;
}

void string_resize(pstring string) {    
    char *tmp_buffer = realloc(string->str, (string->size += string->increase_by));
    
    if (tmp_buffer) {
        string->str = tmp_buffer;
        memset(string->str + string->length, 0, string->size - string->length);
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

void string_clear(pstring string) {
    string->size = 0;
    string->length = 0;
    string->increase_by = STRING_INIT_SIZE;
    
    string_resize(string);    
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    char bla[] = "a";
    printf("Size: %d\n", sizeof(bla));
    exit(-1);

    pstring teste = string_init();
    if (teste) {
        FILE *fp = fopen("string_read_test_file.txt", "r");    

        if (fp) {
            int c;
            while ((c = fgetc(fp)) != EOF) {                
                string_add_char(teste, c);            
            }
            
            string_add_str(teste, "TERMINOU esta merda :D");

            
            
            printf("Dados: %s\n", teste->str);
            printf("Size: %d\n", teste->size);
            printf("Length: %d\n", teste->length);
        }

        string_clear(teste);
        string_destroy(teste);
    }
    
    return (EXIT_SUCCESS);
}

