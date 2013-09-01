/* 
 * File:   main.c
 * Author: AntonioCS
 *
 * Created on 4 de Julho de 2012, 21:21
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "wildcards.h"

/*
 * 
 */
int main(int argc, char** argv) {

    
    /*
    printf("Result: %d <- Should be true\n",wildcard("Hello World","Hello*"));
    printf("Result: %d <- Should be true\n",wildcard("Hello World","*Hello*"));
    printf("Result: %d <- Should be true\n",wildcard("Hello World","He?lo*"));
    printf("Result: %d <- Should be true\n",wildcard("Hello World","Hello World"));
    printf("Result: %d <- Should be false\n",wildcard("Hello World","Hello"));
    */
    //positive tests
    printf("Result: %d <- Should be true\n",wildcard("a","?"));  
    printf("Result: %d <- Should be true\n",wildcard("ab","a?"));  
    //printf("Result: %d <- Should be true\n",wildcard("ba","?a"));  
    //printf("Result: %d <- Should be true\n",wildcard("Hello","*Hello"));
    
    
    //printf("Result: %d <- Should be false\n",wildcard("","?")); 
    //printf("Result: %d <- Should be false\n",wildcard("Hello World","*Hello"));
    //printf("Result: %d <- Should be true\n",wildcard("","*"));
    /*
    printf("Result: %d <- Should be true\n",wildcard(" ","?"));
    printf("Result: %d <- Should be true\n",wildcard("a","*"));   
    printf("Result: %d <- Should be true\n",wildcard("ab","*"));    
    
    printf("Result: %d <- Should be true\n",wildcard("abc","*?"));
    printf("Result: %d <- Should be true\n",wildcard("abc","?*"));  
    printf("Result: %d <- Should be true\n",wildcard("abc","*abc"));
    printf("Result: %d <- Should be true\n",wildcard("abc","*abc*"));
    printf("Result: %d <- Should be true\n",wildcard("aXXXbc","*a*bc*"));
    //*/
    // Negative Tests
    /*
    printf("Result: %d <- Should be false\n",wildcard("","*a"));
    printf("Result: %d <- Should be false\n",wildcard("","a*"));
    printf("Result: %d <- Should be false\n",wildcard("","?")); 
    printf("Result: %d <- Should be false\n",wildcard("a","*b*"));   
    printf("Result: %d <- Should be false\n",wildcard("ab","b*a"));   
    printf("Result: %d <- Should be false\n",wildcard("a","??"));
    printf("Result: %d <- Should be false\n",wildcard("","*?"));
    printf("Result: %d <- Should be false\n",wildcard("a","??*"));
    printf("Result: %d <- Should be false\n",wildcard("abX","*abc"));
    printf("Result: %d <- Should be false\n",wildcard("Xbc","*abc*"));
    printf("Result: %d <- Should be false\n",wildcard("ac","*a*bc*"));
    //*/
    
    return 0;	
}

