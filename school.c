#include <stdio.h>
#include <stdlib.h>
#include "school.h"
#include "string.h"
#include "stack.h"

int no=1;

void student_printByAddress(std_t *ps)
{
    printf("no.%d",no);
    printf("%20s",ps->name);

    printf("%10d %8c\n",ps->age,ps->grade);
}


void school_PrintByAddress(std_t *ps,int size)
{
    if(size==0)
    {
        printf("No Students to Print, the database is empty!\n");
    }
    else
    {
    printf("\n-------------------------------------------------------------------------------\n\n\n");
    printf("\n=================================Your DataBase=================================\n\n\n");
    printf("\n-------------------------------------------------------------------------------\n\n\n");

        no=1;
        printf("\t\tName    \tAge    \tGrade\n");
        for(int i=0; i<size; i++)
        {

            student_printByAddress(&ps[i]);
            no++;
        }
    }
}

void printing_SameGrade(std_t *ps,int size)
{
    char n;
    if(size==0)
    {
        printf("The list is empty!\n");
        return;
    }
    printf("Please enter the grade you need to find students by:");
    scanf(" %c",&n);
    if(n>='a' && n<='z')
    {
        system("cls");
        printf("The Students Details:\n");
        printf("\t\tName    \tAge    \tGrade\n");
        no=1;
        for(int i=0; i<size; i++)
        {

            if(ps[i].grade==n)
            {
                student_printByAddress(&ps[i]);
            }
            no++;
        }
    }
    else
        printf("Not Found!");
}

void Student_AddtoSchool(void)
{
    if(push()==STACK_DONE)
    {
            system("cls");
            printf("Student is added successfully!\n");
    }

    else if(push()==STACK_FULL)
        printf("List is Full, please empty a place!\n");
}
void Student_Edit_School(std_t* data)
{
    int select1,select2;
    system("cls");
    printf("Please write no. of student: ");
    while(1)
    {
        scanf("%d",&select1);
        if(select1>0 && select1<=no)
        {

            printf("1.Edit the age of student.\n2.Edit the grade of student.\n");
            scanf("%d",&select2);
            if(select2==EDIT_BY_AGE)
            {
                printf("Please write the new age:");
                scanf("%d",&data[select1-1].age);
                system("cls");
                printf("Age is changed successfuly!\n");
                return ;

            }
            else if(select2==EDIT_BY_GRADE)
            {
                printf("Please Choose the new grade:\n");
                printf("(a)Excellent.\n(b)very Good.\n(c)Good.\n(d)Acceptable.\n(f)Failed!\n");
                scanf(" %c",&data[select1-1].grade);
                system("cls");
                printf("Grade is changed successfuly!\n");
                return ;

            }
            else
            {
                printf("You entered an invalid number..!\nPlease write a valid number !\n");
            }

        }

    }
}


void Grades_selectionSort(std_t* sp,int size)
{
    int i,j,last=size-1,index_m;
    for(i=0; i<size; i++)
    {
        index_m=0;
        for(j=0; j<=last; j++)
        {
            if(((sp+j)->grade)>((sp+index_m)->grade))
            {
                index_m=j;
            }
        }
        student_swap(&sp[index_m],&sp[last]);
        last--;

    }
}

void student_swap(std_t* s1,std_t* s2)
{
    std_t temp;
    temp=*s1;
    *s1=*s2;
    *s2=temp;
}

void School_Sorting(std_t* s,int size)
{
    system("cls");
    int select;
    printf("Which method do you need to select?\n1.Names Sorting.\n2.Grades Sorting\n");
    while(1)
    {
        scanf("%d",&select);
        if(select==NAMES_SORT)
        {
            Names_selectionSort(school,sp);
            system("cls");

            printf("- Names Sorting is Done!\n");
            return ;
        }
        else if(select==GRADES_SORT)
        {
            Grades_selectionSort(school,sp);
            system("cls");
            printf("- Grades Sorting is Done!\n");

            return;
        }
        else
            printf("You entered an invalid number..!\nPlease write a valid number !\n");

    }
}

void Student_DeleteFromSchool(std_t* s,int size)
{
    int select;
    system("cls");
    school_PrintByAddress(school,size);
    printf("Enter the number of student you need to delete:");
    scanf("%d",&select);
    if(select==size)
    {
        if(pop()==STACK_DONE)
            printf("Student is Deleted successfully!\n");

    }
    else if(select==(size+1))
    {
        printf("List is Empty, you can add students in list!\n");
        return;
    }
    else if(select>size)
    {
                    printf("You entered an invalid number..!\nPlease write a valid number up to %d !\n",size);
            return;
    }

    else if(select<size)
    {
        for(;select<size;select++)
        {
            s[select-1]=s[select];

        }
        pop();
            printf("Student is Deleted successfully!\n");
    }
}
void Student_Search(std_t* s,int size)
{
    int select,n;
    char str[30]={0};
    while(1)
    {
        printf("How do you need to search by ?!\n1.Search a student by name.\n2.Search for students with same grade.\n");
            scanf("%d",&select);
    if(select==SEARCH_BY_NAME)
    {
        printf("Enter the name you need to search for: ");
        string_scan(str,30);
        no=1;
        for(int i=0;i<size;i++)
        {
            if(string_compare(str,s[i].name)==0)
            {
                system("cls");
                student_printByAddress(&s[i]);
                return;
            }
            no++;
        }
            printf("The name you entered is not found! \n");
    }
    else if(select==SEARCH_BY_GRADE)
    {
        system("cls");
        printing_SameGrade(s,size);
        return;
    }
    else
        printf("You entered an invalid number!\n");
    }

}

