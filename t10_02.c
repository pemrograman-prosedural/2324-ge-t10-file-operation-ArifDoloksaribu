// 12S23026 - Arif M. Doloksaribu
// 12S23051 - Theresia Silaban

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    // codes
    struct dorm_t *dorm = malloc(100 * sizeof(struct dorm_t));
    struct student_t *student = malloc(100 * sizeof(struct student_t));

    char *token;
    char masukan[100];
    int i = 0;

    while(1){
        fgets(masukan, 100, stdin);
        if(strcmp(masukan, "---\n") == 0){
            break;
        }
        else if(strcmp(masukan,"student-add")==0){
            token = strtok(masukan, "#");

            token = strtok(NULL, "#");
            strcpy(student->id, token);
            token = strtok(NULL, "#");
            strcpy(student->name, token);
            token = strtok(NULL, "#");
            strcpy(student->year, token);
            token = strtok(NULL, "#");
            if(strcmp(token,"female")==0){
                student->gender = GENDER_FEMALE;
            }else{
                student->gender = GENDER_MALE;
            }
                student[i] = create_student(student->id, student->name, student->year, student->gender);
        }
        else if (strcmp(masukan,"student-print")==0){
            print_stu(student, i);
        }
        else if(strcmp(masukan,"student-print-all-detail")==0){
            student_print_all_detail(student, i);
        }
        else if(strcmp(masukan,"dorm-add")==0){
            token = strtok(masukan, "#");

            token = strtok(NULL, "#");
            strcpy(dorm->name, token);
            token = strtok(NULL, "#");
            dorm->capacity = atoi(token);
            token = strtok(NULL, "#");
            if(strcmp(token,"female")==0){
                dorm->gender = GENDER_FEMALE;
            }else{
                dorm->gender = GENDER_MALE;
            }
            dorm[i] = create_dorm(dorm->name, dorm->capacity, dorm->gender);
        }
        else if(strcmp(masukan,"dorm-print")==0){
            print_dorms(dorm, i);
        }
        else if(strcmp(masukan,"dorm-print-all-detail")==0){
            dorm_print_all_detail(dorm, i);
        }
    }

    return 0;

}
