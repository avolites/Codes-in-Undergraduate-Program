//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#ifndef SCOREMANAGEMENT_VIEWS_H
#define SCOREMANAGEMENT_VIEWS_H

#include "type.h"

void mainMenuUI();

void static displayAllRecordUI();

void static displayRecordsByPage(int currentPage);

void static addRecordUI();

void static delRecordUI();

void static updateRecordUI();

void static searchRecordUI();

//pre-condition: s is the pointer to Student Struct
//               status: -1:add, if update, status should be the existing record's position
void static createStudent(StuPtr s, int pos);

void static sortRecordUI();

void static readOrWriteDateUI();

void static printTableHead();

void static printRecordItem(int pos);

void static loadUI();

void static saveUI();

//post-condition: return 1 if user wanna to quit, 0 otherwise
int static exitUI();

void static promptPressAnyKey();

#endif //SCOREMANAGEMENT_VIEWS_H
