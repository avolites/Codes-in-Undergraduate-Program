//
// Created by Gaoxiang on 11/30/2019.
// Project for assignment of Introduction of Program Design (re-take)
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "views.h"
#include "type.h"
#include "util.h"
#include "logic.h"
#include "data_access.h"

extern int len;
extern Student stu[STUNUM];

void mainMenuUI() {
    char c;
    int flag = 0;
    while (1) {
        system("cls");
        system("color 0a");
        flag = 0;
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|           Management for Students' scores           |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|                   by Gaoxiang Liu                   |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|                 [1] List records                    |");
        puts("\t\t|                 [2] Append a record                 |");
        puts("\t\t|                 [3] Delete a record                 |");
        puts("\t\t|                 [4] Modify a record                 |");
        puts("\t\t|                 [5] Search a record                 |");
        puts("\t\t|                 [6] Sort records                    |");
        puts("\t\t|                 [7] Load & save records             |");
        puts("\t\t|                 [0] Exit                            |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|   Please make a choice by hitting numeric button.   |");
        puts("\t\t|-----------------------------------------------------|");
        c = (char) _getch();
        switch (c) {
            case '1':
                displayAllRecordUI();
                break;
            case '2':
                addRecordUI();
                break;
            case '3':
                delRecordUI();
                break;
            case '4':
                updateRecordUI();
                break;
            case '5':
                searchRecordUI();
                break;
            case '6':
                sortRecordUI();
                break;
            case '7':
                readOrWriteDateUI();
                break;
            case '0':
                flag = exitUI();
                break;
            default:
                break;
        }
        if (flag)
            break;
    }
}

void static displayAllRecordUI() {
    system("cls");
    system("color 0e");
    puts("------------All Students------------");
    if (len > 0) {
        char c = 0;
        int currentPage = 0;
        int totalPages = len / RECORD_PER_PAGE;
        if(len % RECORD_PER_PAGE == 0)
            totalPages--;
        while(1) {
            system("cls");
            displayRecordsByPage(currentPage);
            printf("Total: %d %s\n", len, (len > 1) ? "records" : "record");
            c = (char) _getch();
            if(c == 27)     //ESC
                return;
            else if(c == 'p' && currentPage > 0)
                currentPage--;
            else if(c == 'n' && currentPage < totalPages)
                currentPage++;
        }
    } else
        puts("No records");
    promptPressAnyKey();
    _getch();
}

void static displayRecordsByPage(int currentPage) {
    int baseNum = currentPage * RECORD_PER_PAGE;
    int i;
    int offset = len % RECORD_PER_PAGE;
    int totalPages = len / RECORD_PER_PAGE;
    if(len % RECORD_PER_PAGE == 0)
        totalPages--;
    if(offset == 0)
        offset = 20;
    if(currentPage < totalPages)
        offset = 20;
    printTableHead();
    for (i = baseNum; i < baseNum + offset; i++) {
        printRecordItem(i);
    }
    for(; i < baseNum + RECORD_PER_PAGE; i++){
        puts("");
    }
    puts("-------------------------------------------------------------------------------------");
    printf("Page: %d of %d\t\t\tPage turning: n (next) / p (previous); Exit: ESC\n",
           currentPage + 1, totalPages + 1);
}


void static addRecordUI() {
    system("cls");
    system("color 0e");
    Student s;
    puts("------------Add a new student------------");
    createStudent(&s, -1);
    if (addRecord(&s)) {
        puts("DONE!");
    } else
        puts("Failed.");
    promptPressAnyKey();
    _getch();
}

void static delRecordUI() {
    system("cls");
    system("color 0e");
    puts("------------Delete a student------------");
    char id[20];
    printf("Student's ID: ");
    gets(id);
    int pos = searchReocrd(id);
    if (pos >= 0) {
        printTableHead();
        printRecordItem(pos);
        puts("Please make sure the above information before removing this record.");
        puts("Type Y to remove, other keys to back to previous menu.");
        if (getchar() == 'Y') {
            delRecord(pos);
            puts("DONE!");
            dispose();
        } else {
            dispose();
            return;
        }
    } else
        puts("No such a student.");
    promptPressAnyKey();
    _getch();
}

void static updateRecordUI() {
    system("cls");
    system("color 0e");
    puts("------------Modify a student------------");
    char id[20];
    printf("Student's ID: ");
    gets(id);
    int pos = searchReocrd(id);
    if (pos >= 0) {
        puts("Original Data:");
        printTableHead();
        printRecordItem(pos);
        puts("\nNow, input new data:");
        Student s;
        createStudent(&s, pos);
        if (updateRecord(pos, &s))
            puts("DONE!");
    } else
        puts("No such as student.");
    promptPressAnyKey();
    _getch();
}

void static searchRecordUI() {
    system("cls");
    system("color 0e");
    puts("------------Search a student------------");
    char id[20];
    printf("Student's ID: ");
    gets(id);
    int pos = searchReocrd(id);
    if (pos >= 0) {
        printTableHead();
        printRecordItem(pos);
    } else
        puts("No such a student.");
    promptPressAnyKey();
    _getch();
}

void static createStudent(StuPtr s, int pos) {
    if (pos == -1) {       //add
        while (1) {
            printf("ID: ");
            gets(s->id);
            if (isStringEmpty(s->id) || searchReocrd(s->id) != -1)
                puts("Error - ID exists, or your input is empty.");
            else
                break;
        }
    } else {               //update
        strcpy(s->id, stu[pos].id);
        printf("ID: %s\n", s->id);
    }
    printf("Name: ");
    gets(s->name);
    printf("Gender: (m/f)");
    s->gender = (char) getchar();
    dispose();
    while (s->gender != 'm' && s->gender != 'f') {
        printf("Error: invalid, please type m or f.\n");
        s->gender = (char) getchar();
        dispose();
    }
    printf("Major: ");
    gets(s->major);
    printf("Score 1: ");
    while (!scanf("%f", &s->s1)) {
        puts("Error - Invalid input, please input a decimal or an integer.");
        dispose();
    }
    dispose();
    printf("Score 2: ");
    while (!scanf("%f", &s->s2)) {
        puts("Error - Invalid input, please input a decimal or an integer.");
        dispose();
    }
    dispose();
    printf("Score 3: ");
    while (!scanf("%f", &s->s3)) {
        puts("Error - Invalid input, please input a decimal or an integer.");
        dispose();
    }
    dispose();
}


void static sortRecordUI() {
    while (1) {
        system("cls");
        system("color 0b");
        int flag = 1;
        char c;
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|                   Sort records                      |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|          [1]  Ascending by total score              |");
        puts("\t\t|          [2]  Descending by total score             |");
        puts("\t\t|          [3]  Ascending by student's ID             |");
        puts("\t\t|          [4]  Descending by student's ID            |");
        puts("\t\t|          [0]  Back to previous menu                 |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|   Please make a choice by hitting numeric button.   |");
        puts("\t\t|-----------------------------------------------------|");
        c = (char) _getch();
        switch (c) {
            case '1':
                ascBySum();
                puts("Records have been sort to ascending order by total score.");
                break;
            case '2':
                descBySum();
                puts("Records have been sort to descending order by total score.");
                break;
            case '3':
                ascById();
                puts("Records have been sort to ascending order by ID.");
                break;
            case '4':
                descById();
                puts("Records have been sort to descending order by ID.");
                break;
            case '0':
                return;
            default:
                flag = 0;
                break;
        }
        if (flag) {
            promptPressAnyKey();
            _getch();
            break;
        }
    }

}

void static readOrWriteDateUI() {
    while (1) {
        system("cls");
        system("color 0b");
        int flag = 1;
        char c;
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|                Load & save records                  |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|          [1] Load records from a file               |");
        puts("\t\t|          [2] Save records to a file                 |");
        puts("\t\t|          [0] Back to previous menu                  |");
        puts("\t\t|-----------------------------------------------------|");
        puts("\t\t|   Please make a choice by hitting numeric button.   |");
        puts("\t\t|-----------------------------------------------------|");
        c = (char) _getch();
        switch (c) {
            case '1':
                loadUI();
                break;
            case '2':
                saveUI();
                break;
            case '0':
                break;
            default:
                flag = 0;
                break;
        }
        if (flag) {
            break;
        }
    }
}

int static exitUI() {
    system("cls");
    system("color 0c");
    puts("Please make sure to save data to a file before exit.");
    puts("If you are sure to exit, press Y.");
    if (getchar() == 'Y') {
        return 1;
    }
    dispose();
    return 0;
}

void static printTableHead() {
    printf("ID\tName\t\tSex\tMajor\t\tScore1\tScore2\tScore3\tTotal\tAverage\n");
    puts("-------------------------------------------------------------------------------------");

}

void static printRecordItem(int pos) {
    printf("%s\t%s\t\t%s\t%s\t\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", stu[pos].id, stu[pos].name,
           (stu[pos].gender =='m') ? "Male" : "Female", stu[pos].major,
           stu[pos].s1, stu[pos].s2, stu[pos].s3, getTotalScore(pos), getAverageScore(pos));
}

void static promptPressAnyKey() {
    puts("Press any key to back to previous menu.");
}

void static loadUI() {
    system("cls");
    system("color 0e");
    puts("------------Load records from a file------------");
    puts("WARNING: current records in memory will be cleared.");
    puts("File's path: (blank for default file)");
    char path[500];
    int n;
    gets(path);
    if (isStringEmpty(path))
        n = readFromFile("stu.dat");
    else
        n = readFromFile(path);
    if (n == -1)
        puts("Error - No such a file or directory.");
    else if (n == 0)
        puts("No records");
    else
        puts("DONE!");
    promptPressAnyKey();
    _getch();
}

void static saveUI() {
    system("cls");
    system("color 0e");
    puts("------------Save records from a file------------");
    puts("File's path: (blank for default file)");
    char path[500];
    int n;
    gets(path);
    if (isStringEmpty(path))
        n = writeToFile("stu.dat");
    else
        n = writeToFile(path);
    if (n == -1)
        puts("Error - No such a file or directory.");
    else if (n == 0)
        puts("No records");
    else
        puts("DONE!");
    promptPressAnyKey();
    _getch();
}

