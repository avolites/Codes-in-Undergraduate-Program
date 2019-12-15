//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#ifndef SCOREMANAGEMENT_LOGIC_H
#define SCOREMANAGEMENT_LOGIC_H

#include "type.h"

//operation: add a new record
//pre-condition: record is the right record needed to be added
//post-condition: return 1 if succeed, 0 otherwise
int addRecord(StuPtr record);

//operation: delete an extant record
//pre-condition: pos is the target position of array
//post-condition: return 1 if succeed, 0 otherwise
int delRecord(int pos);

//operation: modify a extant record
//pre-condition: pos is the target position of array
//               record is the new record
//post-condition: return 1 if succeed, 0 otherwise
int updateRecord(int pos, StuPtr record);

//operation: search a record accroding to student's id
//pre-condition: id is the student's id, query condition
//post-conditon: return the position of target record in array, -1 if record does not exist
int searchReocrd(char *id);

//operation: get a record according to position
//pre-condition:  pos is the target position of array
//post-condition: return the target record if pos is valid, NULL otherwise
StuPtr getRecord(int pos);

//operation: sort records in ascending order by total score
//post-condition: elements' order in array will be changed
void ascBySum();

//operation: sort records in descending order by total score
//post-condition: elements' order in array will be changed
void descBySum();

//operation: sort records in ascending order by id
//post-condition: elements' order in array will be changed
void ascById();

//operation: sort records in descending order by id
//post-condition: elements' order in array will be changed
void descById();

//operation: get a student's total score
//pre-condition:  pos is the target position of array
//post-condition: return the total score;
float getTotalScore(int pos);

//operation: get a student's average socre
//pre-condition:  pos is the target position of array
//post-condition: return the average score;
float getAverageScore(int pos);



#endif //SCOREMANAGEMENT_LOGIC_H
