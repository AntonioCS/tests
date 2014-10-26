/* 
 * File:   mstash_str_read.c
 * Author: antoniocs
 *
 * Created on 19 de Outubro de 2014, 22:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MSTASH_STRING_INIT_SIZE 15
#define MSTASH_READ_FILE_BUFFER_SIZE 1024

//http://www.cprogramming.com/tutorial/unicode.html

typedef struct mstash_str {
    char *str;

    int size;
    int length;

    int increase_by; //will have the default of 15 but can be customized per instance
} mstash_str, *pmstash_str;

static pmstash_str mstash_str_init(void);
static void mstash_str_add_char(pmstash_str, int);
static void mstash_str_add_str(pmstash_str, char *);
static void mstash_str_add_str_num(pmstash_str, char *, int);
static void mstash_str_resize(pmstash_str);
static void mstash_str_destroy(pmstash_str);
static void mstash_str_clear(pmstash_str);
static bool mstash_str_is_resize_needed(pmstash_str, int);
static void mstash_str_from_file(pmstash_str, const char *);

pmstash_str mstash_str_init() {
    pmstash_str newstr = malloc(sizeof (mstash_str));

    if (newstr != NULL) {
        newstr->str = calloc(MSTASH_STRING_INIT_SIZE, sizeof (char));
        if (newstr->str == NULL) {
            perror("Unable to allocate space for string");
            exit(-1);
        }

        newstr->increase_by = newstr->size = MSTASH_STRING_INIT_SIZE;
        newstr->length = 0;

        return newstr;
    }

    return NULL;
}

void mstash_str_add_char(pmstash_str string, int c) {

    if (mstash_str_is_resize_needed(string, 1)) {
        mstash_str_resize(string);
    }

    string->str[string->length++] = c;
}

void mstash_str_add_str(pmstash_str s, char *str) {
    int len = strlen(str);
    mstash_str_add_str_num(s, str, len);
}

void mstash_str_add_str_num(pmstash_str s, char *str, int length) {
    while (mstash_str_is_resize_needed(s, length)) {
        mstash_str_resize(s);
    }

    memcpy(s->str + s->length, str, length);
    s->length += length;
}

bool mstash_str_is_resize_needed(pmstash_str s, int len_to_add) {
    return (s->length + len_to_add) >= s->size;
}

void mstash_str_resize(pmstash_str string) {
    char *tmp_buffer = realloc(string->str, (string->size += string->increase_by));

    if (tmp_buffer) {
        string->str = tmp_buffer;
        memset(string->str + string->length, 0, string->size - string->length);
    } else {
        perror("Unable to reallocate memory");
        exit(-1);
    }
}

void mstash_str_destroy(pmstash_str s) {
    free(s->str);
    free(s);
}

void mstash_str_clear(pmstash_str s) {
    s->size = 0;
    s->length = 0;
    s->increase_by = MSTASH_STRING_INIT_SIZE;

    mstash_str_resize(s);
}

void mstash_str_from_file(pmstash_str s, const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp != NULL) {
        char buffer[MSTASH_READ_FILE_BUFFER_SIZE] = {'\0'};
        int buf_size = MSTASH_READ_FILE_BUFFER_SIZE - 1;
        int inc_by = s->increase_by;
        size_t read;

        s->increase_by = MSTASH_READ_FILE_BUFFER_SIZE;

        do {
            read = fread(buffer, 1, buf_size, fp);
            mstash_str_add_str_num(s, buffer, read);                       
        } while (read == buf_size);

        s->increase_by = inc_by;
        fclose(fp);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    //char bla[] = "鷜鷙a";
    //printf("Size: %lu\n", sizeof(bla));
    //exit(-1);

    pmstash_str teste = mstash_str_init();
    //mstash_str_from_file(teste, "string_read_test_file.txt");
    //mstash_str_from_file(teste, "string_read_chinese_small.txt");
    mstash_str_from_file(teste, "html_test_file.htm");

    printf("Dados: %s\n", teste->str);
    printf("Size: %d\n", teste->size);
    printf("Length: %d\n", teste->length);

    /*
    if (teste) {
        FILE *fp = fopen("string_read_test_file.txt", "r");    

        if (fp) {
            int c;
            while ((c = fgetc(fp)) != EOF) {                
                mstash_str_add_char(teste, c);            
            }
            
            mstash_str_add_str(teste, "TERMINOU esta merda :D");

            
            
            printf("Dados: %s\n", teste->str);
            printf("Size: %d\n", teste->size);
            printf("Length: %d\n", teste->length);
        }

        mstash_str_clear(teste);
        mstash_str_destroy(teste);
    }
    //*/
    return (EXIT_SUCCESS);
}

