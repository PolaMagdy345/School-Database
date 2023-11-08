#include <stdio.h>
#include <stdlib.h>
#include "school.h"
#include "string.h"
#include "stack.h"



int main()
{
    int select,n=1;
        printf("|-----------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                 |\n");
        printf("|============================= WELCOME TO SCHOOL DATABASE ((MADE BY ENG\\PAULA MAGDY)) ============================|\n");
        printf("|                                                                                                                 |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------|\n");
    while(n!=0)
    {
        if(sp>=0)
        {
            printf("\nSelect from the below numbers: \n1.Add Student Data.\
           \n2.Edit Student Data.\n3.Sorting.\n4.Delete A student.\
            \n5.Search.\n6.Print DataBase of School.\n7.Exit.\n");
            scanf("%d",&select);
            fflush(stdin);
            if(select>='a' && select<='z')
            {
                printf("\nPlease enter a number from the list:\n");
            }

            else
            {

                if(select==ADD_STUDENT)
                {
                    system("cls");
                    Student_AddtoSchool();
                }
                if(select==EDIT_STUDENT)
                {
                    Student_Edit_School(school);
                }
                if(select==SORT)
                {
                    School_Sorting(school,sp);
                }
                if(select==DELETE_STUDENT)
                {
                    Student_DeleteFromSchool(school,sp);

                }
                if(select==PRINT_DATABASE)
                {
                    system("cls");
                    school_PrintByAddress(school,sp);
                }
                if(select==SEARCH)
                {
                    system("cls");
                    Student_Search(school,sp);
                }
                if(select==EXIT)
                    n=0;
                else
                    printf("\nPlease enter a number from the list!\n");
            }
        }
    }

        printf("|----------------------------------------------------------------------------------------|\n");
        printf("|                                                                                        |\n");

    printf("|=====================ENG\\PAULA MAGDY IS WHISHING YOU A GREAT DAY :)=====================|\n|                                                                                        |\n|======================================BYE BYE===========================================|");
          printf("\n|                                                                                        |");
        printf("\n|----------------------------------------------------------------------------------------|\n");
    while(1)
    {

    }
}
