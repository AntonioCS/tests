

#include "console_data.h"

#define SIZE 10

char *getData() {    
    
    char *data = calloc(SIZE,1);
    char *more_data = NULL;    
    int times = 0;
       
    while (1) {
        fgets(data + ((times++)*SIZE),SIZE,stdin);
        
        if (strstr(data,"\n")) {                        
            break;
        }
        else {            
            more_data = realloc(data,SIZE);
            
            if (more_data != NULL) {
                data = more_data;              
            }
            else {                
                free(data);
                data = NULL;               
                fprintf(stderr,"Error giving memory");
                break;
            }
        }
    }
    
    return data;
}
