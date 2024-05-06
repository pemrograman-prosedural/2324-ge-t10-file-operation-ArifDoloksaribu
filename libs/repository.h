#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */
struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
void print_stu(struct student_t *_student, int size);
void student_print_all_detail(struct student_t *_student, int size);

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorms(struct dorm_t *_dorm, int size);
void dorm_print_all_detail(struct dorm_t *_dorm, int size);
#endif
