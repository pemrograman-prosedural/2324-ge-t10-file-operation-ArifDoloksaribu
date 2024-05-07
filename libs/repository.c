#include "repository.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender){

    struct student_t students;
        strcpy(students.id, _id);
        strcpy(students.name, _name);
        strcpy(students.year, _year);
        students.gender = _gender;
        students.dorm = NULL;

        return students;
}

void print_stu(struct student_t *_student, int size){
    for(int a=0; a<size; a++){
        if(_student[a].gender == GENDER_MALE){
            printf("%s|%s|%s|male\n", _student[a].id, _student[a].name, _student[a].year);
        }
        else if(_student[a].gender == GENDER_FEMALE){
            printf("%s|%s|%s|female\n", _student[a].id, _student[a].name, _student[a].year);
        }         
    }
}


void student_print_all_detail(struct student_t *_student, int size){
    int a = 0;
    for(a=0; a<size; a++){
       if(_student[a].dorm == NULL){
           if(_student[a].gender == GENDER_MALE){
             printf("%s|%s|%s|male|unassigned\n", _student[a].id, _student[a].name, _student[a].year);
           }
           else if(_student[a].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|unassigned\n", _student[a].id, _student[a].name, _student[a].year);
           }
        }
        else{
            if(_student[a].gender == GENDER_MALE){
                printf("%s|%s|%s|male|%s\n", _student[a].id, _student[a].name, _student[a].year, _student[a].dorm->name);
            }
            else if(_student[a].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|%s\n", _student[a].id, _student[a].name, _student[a].year, _student[a].dorm->name);
            }
            }
        }
}

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
   struct dorm_t dorm;
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;
    return dorm;
    }

void print_dorms(struct dorm_t *_dorm, int size){
      for(int a=0; a<size; a++){
        if(_dorm[a].gender == GENDER_MALE){
            printf("%s|%d|male\n", _dorm[a].name, _dorm[a].capacity);
        }
        else if(_dorm[a].gender == GENDER_FEMALE){
            printf("%s|%d|female\n", _dorm[a].name, _dorm[a].capacity);
        }         
    }
}

void dorm_print_all_detail(struct dorm_t *_dorm, int size){
    int a = 0;
    for(a=0; a<size; a++){
        if(_dorm[a].gender == GENDER_FEMALE){
        printf("%s|%d|female|%d\n", _dorm[a].name, _dorm[a].capacity, _dorm[a].residents_num);
        }
        else{
            printf("%s|%d|male|%d\n", _dorm[a].name, _dorm[a].capacity, _dorm[a].residents_num);
        }
    }
}
