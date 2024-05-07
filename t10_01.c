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
    int i = 0;

    char masukan[100], *argument, *token;
    int h = 0;

    FILE *op = fopen("./storage/student-repository.txt", "r");

    char line[200];
    while (fgets(line, sizeof(line), op) != NULL) {
       token = strtok(line, "|");

        strcpy(student[i].id, token);

        token = strtok(NULL, "|");
        strcpy(student[i].name, token);

        token = strtok(NULL, "|");
        strcpy(student[i].year, token);

        token = strtok(NULL, "|");

        if(strcmp(token,"female\n")==0){
            student[i].gender = GENDER_FEMALE;
        }else{
            student[i].gender = GENDER_MALE;
        }
        student[i] = create_student(student[i].id,student[i].name,student[i].year,student[i].gender);
        i++;
    }
    fclose(op);

    FILE *ap = fopen("./storage/dorm-repository.txt", "r");

    while (fgets(line, sizeof(line), ap) != NULL) {
        token = strtok(line, "|");

        strcpy(dorm[h].name, token);

        token = strtok(NULL, "|");
        dorm[h].capacity = atoi(token);

        token = strtok(NULL, "|");
        dorm[h].gender = (strcmp(token, "female\n") == 0) ? GENDER_FEMALE : GENDER_MALE;

         dorm[h] = create_dorm(dorm[h].name,dorm[h].capacity, dorm[h].gender);
        h++;
    }
    fclose(ap);

    while (1) {
        fgets(masukan, 100, stdin);
        masukan[strcspn(masukan, "\n")] = 0;
        if (strcmp(masukan, "---") == 0) {
            break;
        } else if (strcmp(masukan, "dorm-print-all") == 0) {
            print_dorms(dorm, h);
            continue;
        }
        else if (strcmp(masukan, "student-print-all") == 0) {
            print_stu(student, i);
            continue;
        }
        else if(strcmp(masukan, "student-print-all-detail") == 0) {
            student_print_all_detail(student, i);
            continue;
        }
        else if(strcmp(masukan, "dorm-print-all-detail") == 0) {
            dorm_print_all_detail(dorm, h);
            continue;
        }
        argument = strtok(masukan, "#");
        if (strcmp(argument, "dorm-add") == 0) {
            token = strtok(NULL, "#");
            strcpy(dorm[h].name, token);
            token = strtok(NULL, "#");
            dorm[h].capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0) {
                dorm[h].gender = GENDER_MALE;
            } else {
                dorm[h].gender = GENDER_FEMALE;
            }
            
            dorm[h] = create_dorm(dorm[h].name, dorm[h].capacity, dorm[h].gender);

            h++;
        }
         else if (strcmp(argument, "student-add") == 0){
            token = strtok(NULL, "#");
            strcpy(student[i].id, token);
            token = strtok(NULL, "#");
            strcpy(student[i].name, token);
            token = strtok(NULL, "#");
            strcpy(student[i].year, token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0) {
                 student[i].gender = GENDER_MALE;
            } else {
                student[i].gender = GENDER_FEMALE;
            }
             student[i] = create_student(student[i].id, student[i].name, student[i].year, student[i].gender);

            i++;
    }
    }
    free(dorm);
    free(student);
    return 0;
}