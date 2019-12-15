//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#include <string.h>
#include "logic.h"
#include "type.h"

extern int len;
extern Student stu[STUNUM];

int addRecord(StuPtr record) {
    if(len < STUNUM){
        strcpy(stu[len].id, record->id);
        strcpy(stu[len].name, record->name);
        strcpy(stu[len].major, record->major);
        stu[len].gender = record->gender;
        stu[len].s1 = record->s1;
        stu[len].s2 = record->s2;
        stu[len].s3 = record->s3;
        len++;
        return 1;
    }
    return 0;
}

int searchReocrd(char *id) {
    for(int i = 0; i < len; i++){
        if(strcmp(id, stu[i].id) == 0) {
            return i;
        }
    }
    return -1;
}

StuPtr getRecord(int pos) {
    if(pos < len) {
        return stu + pos;
    }
    return NULL;
}

float getTotalScore(int pos) {
    if(pos >= 0 && pos < len) {
        return stu[pos].s1 + stu[pos].s2 + stu[pos].s3;
    }
    return 0;
}

float getAverageScore(int pos) {
    if(pos >= 0 && pos < len) {
        return (stu[pos].s1 + stu[pos].s2 + stu[pos].s3) / 3;
    }
    return 0;
}

int delRecord(int pos) {
    if(pos >= 0 && pos < len){
        for(int i = pos + 1; i < len; i++) {
            stu[i - 1] = stu[i];
        }
        len--;
        return 1;
    }
    return 0;
}

int updateRecord(int pos, StuPtr record) {
    if(pos >= 0 && pos < len){
        stu[pos] = *record;
        return 1;
    }
    return 0;
}

void ascBySum() {
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(getTotalScore(j) > getTotalScore(j + 1)){
                Student t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
        }
    }
}

void descBySum() {
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(getTotalScore(j) < getTotalScore(j + 1)){
                Student t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
        }
    }
}

void ascById() {
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(strcmp(stu[j].id, stu[j + 1].id) > 0){
                Student t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
        }
    }
}

void descById() {
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(strcmp(stu[j].id, stu[j + 1].id) < 0){
                Student t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
        }
    }
}


