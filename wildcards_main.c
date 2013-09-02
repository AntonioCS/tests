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

    
    char positiveTests[][2][20] = {
        {"",""},
        {"a","?"},  
        {"ab","a?"},  
        {"ab","?b"},  
        {"ba","?a"},  
        {"Hello","*Hello"},
        {"","*"},    
        {" ","?"},
        {"a","*"},   
        {"ab","*"},
        {"abc","*?"},
        {"abc","?*"},  
        {"abc","*abc"},
        {"abc","*abc*"},
        {"aXXXbc","*a*bc*"}
    };
    
    char negativeTests[][2][20] = {
        {"","*a"},
        ///*
        {"","a*"},
        {"","?"}, 
        {"a","*b*"},           
        {"ab","b*a"},   
        {"a","??"},
        {"","*?"},
        {"a","??*"},
        {"abX","*abc"},
        {"Xbc","*abc*"},
        {"ac","*a*bc*"},
        {"Hello World","Hello"}
         //*/ 
    };
    ///*
    printf("Postive tests\n");
    for (int i = 0, t = (sizeof(positiveTests)/sizeof(positiveTests[0]));i<t;i++) {
        printf("String %s - Pattern %s - Result -> %d (should be true)\n",positiveTests[i][0],positiveTests[i][1],wildcard(positiveTests[i][0],positiveTests[i][1]));        
    }        
    //*/
    printf("\nNegative tests\n");
    for (int i = 0, t = (sizeof(negativeTests)/sizeof(negativeTests[0]));i<t;i++) {
        printf("String %s - Pattern %s - Result -> %d (should be false)\n",negativeTests[i][0],negativeTests[i][1],wildcard(negativeTests[i][0],negativeTests[i][1]));
    }        
    
    return 0;	
}

