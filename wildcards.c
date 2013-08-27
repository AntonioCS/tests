
#include "wildcards.h"

bool wildcard(char *value, char *wcard) {
    size_t vsize = strlen(value);
    size_t wsize = strlen(wcard);
    
    bool no_match = false;

    if (wsize > vsize) {
        return false;
    }

    for (int w = 0, v = 0; w < wsize; w++, v++) {     
        switch (wcard[w]) {
            case MULTICHAR:
                //if we find a * at the end of the wildcard everything after that will match so we are done
                if (w == wsize) {
                    goto match;
                } else {                    
                    w++;
                    while (v < vsize) {
                        if (wcard[w] == value[v++]) {
                            no_match = true;
                            break;
                        }
                    }
                    if (no_match) {
                        goto no_match;
                    }
                }
                break;
            case ONECHAR:
                break;
            default:
                if (wcard[w] != value[v]) {
                    goto no_match;
                }
        }
    }

    match:
    return true;
    
    no_match:
    return false;

}
