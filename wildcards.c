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
    bool match = false;

    if (vsize == 0 &&  wsize == 0) {
        match = true;
    }
    /*
    else if (vsize == 0 && wcard[0] != '*') {
        match = false;
    }
    */
    else {
        int v = 0;
        int w = 0;
        int lookAhead = 0;
        bool searchMode = false;
        char search = '\0';
        
                
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
                
                if (!value[v] && !wcard[w]) {
                    if (searchMode) {
                        match = false;
                    }
                    break;
                }
                if (searchMode) {
                    char currentValue = value[v+lookAhead];
                    if (currentValue == search) {
                        match = true;
                        
                        searchMode = false;
                        search = '\0';
                        lookAhead = 0;   
                        w++;
                    }
                    
                    if (currentValue == '\0') {
                        match = false;
                        break;
                    }
                    
                    v++;                    
                    continue;
                }                
                else if ((wcard[w] == ONECHAR && value[v] == '\0') || (wcard[w] != value[v] && wcard[w] != ONECHAR)) {
                    match = false;
                    break;
                }
                else {
                    match = true;
                }
                
                w++;
                v++;
            }           
        }        
    }
    
    return match;
}