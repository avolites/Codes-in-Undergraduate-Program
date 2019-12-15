//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#include "data_access.h"

Student stu[STUNUM];       //store all the records during running
int len = 0;               //current number of records

int readFromFile(char *file) {
    FILE *fp;
    len = 0;
    if((fp = fopen(file, "rb")) != NULL){
        while(fread(stu + len, sizeof(Student), 1, fp)){
            len++;
        }
        fclose(fp);
        return len;
    }
    return -1;
}

int writeToFile(char *file) {
    FILE *fp;
    if((fp = fopen(file, "wb")) != NULL){
        for(int i = 0; i < len; i++){
            fwrite(stu + i, sizeof(Student), 1, fp);
        }
        fclose(fp);
        return len;
    }
    return -1;
}
