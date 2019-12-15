//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#ifndef SCOREMANAGEMENT_TYPE_H
#define SCOREMANAGEMENT_TYPE_H

#define STUNUM 1000
#define RECORD_PER_PAGE 20

typedef struct {
    char id[20];
    char name[50];
    char gender;
    char major[50];
    float s1, s2, s3;   // three scores
} Student, *StuPtr;

#endif //SCOREMANAGEMENT_TYPE_H
