/* 
 * File:   wildcard_search.h
 * Author: AntonioCS
 *
 * Created on 25 de Agosto de 2013, 21:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef WILDCARD_SEARCH_H
#define	WILDCARD_SEARCH_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MULTICHAR '*'    
#define ONECHAR '?'

bool wildcard(char *,char *);



#ifdef	__cplusplus
}
#endif

#endif	/* WILDCARD_SEARCH_H */

