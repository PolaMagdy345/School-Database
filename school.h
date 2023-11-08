#include <stdio.h>
#ifndef SCHOOL_H_
#define SCHOOL_H_

extern int no;


typedef enum
{
    ADD_STUDENT=1,
    EDIT_STUDENT,
    SORT,
    DELETE_STUDENT,
    SEARCH,
    PRINT_DATABASE,
    EXIT,
    EDIT_BY_AGE=1,
    EDIT_BY_GRADE,
    SEARCH_BY_NAME=1,
    SEARCH_BY_GRADE
}List_Selection;

typedef enum
{
    NAMES_SORT=1,
    GRADES_SORT
}sorting_selection;

typedef struct student
{
    char name[30];
    int age;
    char grade;
} std_t;

void student_swap(std_t* s1,std_t* s2);

void student_printByAddress( std_t *ps);

void student_SchoolPrint(struct student *ps,int size);

void school_PrintByAddress(std_t *ps,int size);

void school_SortingSmallestToBiggestAge(std_t *ps,int size);

void printing_SameGrade(std_t *ps,int size);

void Student_AddtoSchool(void);

void Student_Edit_School(std_t* data);

void School_Sorting(std_t* s,int size);

void Grades_selectionSort(std_t* sp,int size);

void Student_DeleteFromSchool(std_t* s,int size);

void Student_Search(std_t* s,int size);
#endif // SCHOOL_H_
