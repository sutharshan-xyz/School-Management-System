#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Step 1 : Defining the Student Struct

typedef struct student {
    char name[20];
    unsigned int id;
}Student;

// Step 2 : Defining the Course Struct

typedef struct course{
    char name[30];
    double averageGrade;
    unsigned int totalStudents;
    Student* studentArray;
}Course;

// Step 3 : Defining the School Struct

typedef struct school {
    char name[30];
    unsigned int totalCourses;
    Course* courseArray;
}School;


// Step 4 : Creating a student

Student* createStudent(){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter student name : ");
    scanf("%s", newStudent->name);
    printf("Enter student ID : ");
    scanf("%u", &(newStudent->id));
    return newStudent;
}

// Step 5 : Creating a Course

Course* createCourse(){
    Course* newCourse = (Course*)malloc(sizeof(Course));
    printf("Enter Course name : ");
    scanf("%s", newCourse->name);
    printf("Enter number of students : ");
    scanf("%u", &(newCourse->totalStudents));
    newCourse->studentArray = (Student*)malloc(sizeof(Student)* newCourse->totalStudents);

    for (int i=0; i < newCourse->totalStudents; i++){
        printf("Enter details for student #%d\n", i+1);
        Student* newStudent = createStudent();
        newCourse->studentArray[i] = *newStudent;
        free(newStudent);   // Free the temp student memory allocated by "createStudent" function
    }
    return newCourse;
}

