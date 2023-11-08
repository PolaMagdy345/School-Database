#include <stdio.h>
#include"string.h"
#include"school.h"
#include "stack.h"

void string_scan(char* str,int maxsize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(; str[i]!='\n' && i<maxsize-1;)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}

void student_scanByAddress(std_t* ps)
{
    printf("Enter the name of student:");
    string_scan((*ps).name,30);
    fflush(stdin);
    printf("Enter the age of student:");
    scanf("%d",&ps->age);
    printf("Choose the Grade:\n(a)Excellent.\n(b)very Good.\n(c)Good.\n(d)Acceptable.\n(f)Failed!\n");
    scanf(" %c",&ps->grade);
    if((ps->grade)>='a' && (ps->grade)<='z')
    {
        return;
    }
    else
    {
        while(1)
        {

            printf("Invalid grade!\n\n");
            printf("Choose the Grade:\n(a)Excellent.\n(b)very Good.\n(c)Good.\n(d)Acceptable.\n(f)Failed!\n");
            scanf(" %c",&ps->grade);
            if((ps->grade)>='a' && (ps->grade)<='z')
            {
                return;
            }
        }
    }
}


int string_compare(char *str1,char*str2)
{
    int i;
    for(i=0; str2[i]||str1[i]; i++)
    {
        if(str1[i]>str2[i])
        {
            return 1;
        }
        else if (str1[i]<str2[i])
        {
            return -1;
        }

    }
    return 0;

}
void Names_selectionSort(std_t* sp,int size)
{
    int i,j,last=size-1,index_m;
    for(i=0; i<size; i++)
    {
        index_m=0;
        for(j=0; j<=last; j++)
        {
            if(string_compare((sp+j)->name,(sp+index_m)->name)==1)
            {
                index_m=j;
            }
        }
        student_swap(&sp[index_m],&sp[last]);
        last--;

    }

}
