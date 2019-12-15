//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#ifndef SCOREMANAGEMENT_DATA_ACCESS_H
#define SCOREMANAGEMENT_DATA_ACCESS_H

#include <stdio.h>
#include "type.h"

//operation: read data from a file
//pre-condition: file is the target file's path
//post-condition: return the quantity of successful reading, 0 if no records, -1 if file error
//                current records in memory will be cleared
int readFromFile(char *file);

//operation: write data to a file
//pre-condition: file is the target file's path
//post-condition: return the quantity of successful writing, 0 if no records, -1 if file error
int writeToFile(char *file);

#endif //SCOREMANAGEMENT_DATA_ACCESS_H
