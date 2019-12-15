//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#include <stdio.h>
#include <string.h>
#include "util.h"

void dispose() {
    while(getchar() != '\n')
        continue;
}

int isStringEmpty(char *s) {
    if(strlen(s) == 0)
        return 1;
    return 0;
}
