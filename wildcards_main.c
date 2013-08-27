/* 
 * File:   main.c
 * Author: AntonioCS
 *
 * Created on 4 de Julho de 2012, 21:21
 */

#include <stdio.h>
#include <stdlib.h>
#include "wildcards.h"

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    char text[] = "blab";
    char *wcard = "bl*b";
    
    
    if (wildcard(text,wcard)) {
        printf("Match\n");
    }
    else {
        printf("No match\n");
    }
    */
    
    //printf("Result: %d <- Should be true\n",wildcard("Hello World","Hello*"));
    //printf("Result: %d <- Should be true\n",wildcard("Hello World","*Hello*"));
    printf("Result: %d <- Should be true\n",wildcard("Hello World","He?lo*"));
    
    return 0;
	
}

