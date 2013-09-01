#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MULTICHAR '*'    
#define ONECHAR '?'
#define null NULL

/**
 * 
 * @param value
 * @param wcard
 * @return 
 * 
 * Example usage:
 * wildcard("Hello World","Hello*"); - True
    wildcard("Hello World","*Hello*"); - True
    wildcard("Hello World","He?lo*"); - True
    wildcard("Hello World","Hello World"); - True
    wildcard("Hello World","Hello"); - False
*/
bool wildcard(const char *value, char *wcard) {
            
    int vsize = (int)strlen(value);
    int wsize = (int)strlen(wcard);        
    
    //printf("Size value -> %d\n",vsize);
    //printf("Size wcard -> %d\n",wsize);
    
    bool match = false;
    /*
    if (wsize <= 2) {        
        if (*wcard == '*' ||
            strcmp("?*",wcard) == 0 ||
                strcmp("*?",wcard) == 0 ||
                    (*wcard == '?' && vsize == 1)) {
            match = true;
        }        
    }
    else */if (vsize == 0 && wcard[0] != '*') {
        match = false;
    }
 
    else {
        int v = 0;
        int w = 0;
        bool searchMode = false;
        char search = '\0';
        char lookAhead = 0;
                
        while (true) {            
            if (wcard[w] == MULTICHAR) {
                //starts with * and the value matches the wcard
                if (w == 0 && strcmp(wcard+1,value) == 0) {
                    match = true;
                    break;                    
                }                                
                //the * is the last character in the pattern
                if (!wcard[w+1]) {                    
                    match = true;
                    break;
                }
                else {
                    //search for the next char in the pattern that is not a ?
                    while (wcard[++w] == ONECHAR) {
                        lookAhead++;
                    }        
                    
                    //if the next char in the pattern is another * we go to the start (in case we have a pattern like **a, stupid I know, but it might happen)
                    if (wcard[w] == MULTICHAR) {
                        continue;
                    }
                    
                    search = wcard[w];
                    searchMode = true;
                }
            }
                  
            else {
                
                if (!value[v] && wcard[w]) {
                    break;
                }
                /*
                if (!value[v] && !wcard[w]) { //Both are empty 
                    match = true;
                    break;
                }                  
                else */ 
                if (searchMode) {                    
                    if (value[++v+lookAhead] == search) {
                        searchMode = false;
                        search = '\0';
                        lookAhead = 0;
                        
                        continue;
                    }
                }
                else if (wcard[w] != value[v] && wcard[w] != ONECHAR) {
                    match = false;
                    break;
                }
                
                w++;
                v++;
            }           
        }        
    }
    
    return match;
}