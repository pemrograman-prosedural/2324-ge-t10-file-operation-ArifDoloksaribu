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
    // Alokasi memori
    struct dorm_t *dorm = malloc(100 * sizeof(struct dorm_t));
    struct student_t *student = malloc(100 * sizeof(struct student_t));

    int i = 0;
    int sj = 0;

    FILE *op = fopen("./storage/student-repository.txt", "r");

    char line[200];
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, "|");

        strcpy(student[sj].id, token);

        token = strtok(NULL, "|");
        strcpy(student[sj].name, token);

        token = strtok(NULL, "|");
        strcpy(student[sj].year, token);

        token = strtok(NULL, "|");
        student[sj].gender = (strcmp(token, "female") == 0) ? GENDER_FEMALE : GENDER_MALE;

        student[sj] = create_student(
            student[sj].id,
            student[sj].name,
            student[sj].year,
            student[sj].gender);

        sj++;
    }
    fclose(op);

    FILE *ap = fopen("./storage/dorm-repository.txt", "r");

    while (fgets(line, sizeof(line), ap) != NULL) {
        char *token = strtok(line, "|");

        strcpy(dorm[i].name, token);

        token = strtok(NULL, "|");
        dorm[i].capacity = atoi(token);

        token = strtok(NULL, "|");
        dorm[i].gender = (strcmp(token, "female") == 0) ? GENDER_FEMALE : GENDER_MALE;

        dorm[i] = create_dorm(
            dorm[i].name,
            dorm[i].capacity,
            dorm[i].gender);

        i++;
    }
    fclose(ap);

    
    char masukan[100];
    while (1) {
        fgets(masukan, sizeof(masukan), stdin);
        masukan[strcspn(masukan, "\n")] = '\0'; 

        if (strcmp(masukan, "---") == 0) {
            break;
        } else if (strcmp(masukan, "student-print-all-detail") == 0) {
            student_print_all_detail(student, sj);
        } else if (strcmp(masukan, "dorm-print-all-detail") == 0) {
            dorm_print_all_detail(dorm, i);
        } 
    }

    free(dorm);
    free(student);

    return 0;
}

