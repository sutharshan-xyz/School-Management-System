#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Step 1 : Defining the Student Struct

typedef struct student {
    char name[20];
    unsigned int id;
    unsigned int grade;
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
    printf("Enter student Grade : ");
    scanf("%u", &(newStudent->grade ));
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

// Step 6 : Creating a school

School* createSchool(){
    School* newSchool = (School*)malloc(sizeof(School));
    printf("Enter School name : ");
    scanf("%s", newSchool->name);
    printf("Enter number of courses : ");
    scanf("%u", &(newSchool->totalCourses ));
    newSchool->courseArray = (Course*)malloc(sizeof(Course)* newSchool->totalCourses);

    for (int i=0; i < newSchool->totalCourses; i++){
        printf("Enter details for student #%d\n", i+1);
        Course* newCourse = createCourse();
        newSchool->courseArray[i] = *newCourse;
        free(newCourse);   
    }
    return newSchool;
}

// Step 7 : Printing students Details

void printStudentDetails(Student* student){
    printf("Course name : %s\n", student->name);
    printf("Student ID :c%u\n",student->id);
    printf("Student Grade : %u\n",student->grade)
}

// Step 8 : Printing course Details


void printCourseDetails(Course* course){
    printf("Course name : %s\n", course->name);
    printf("Course Average Grade : %1f\n",course->averageGrade);
    printf("Course total students : %u\n", course->totalStudents);

    for(int i=0;i< course->totalStudents ; i++){
        printf("Details for student #%d:\n", i+1);
        printStudentDetails(&(course->studentArray[i]));
    }
}

// Step 9 : Printing All student's courses

void printStudentCourses(School* school, int studentID){
    printf("Courses for student with ID %d :\n", studentID);
    
    for(int i=0 ; i < school->totalCourses ;i++){

        for(int j=0 ; j < school->courseArray[i].totalStudents ;j++ ){
            if (school->courseArray[i].studentArray[j.id]==studentID){
                printf(" - %s\n",school->courseArray[i].name);
                break;  // If student was found no need to keep tracking this course anymore
            }
        }
     }
    
}


// Step 10 : Printing Students who failed a Course

void printStudentWhoFailedCourse(Course* course, double cutOffGrade){
    printf ("Students who failed in %s : \n", course->name);
    for (int i =0 ; i < course->totalStudents ; i++){
        if(course->studentArray[i].grade < cutOffGrade)
            printCourseDetails(&(course->studentArray[i]));
    }
}

// Step 11 : Printing students who passed a course

void printStudentWhoPasses(Course* course, double cutOffGrade){
    printf ("Students who passed in %s : \n", course->name);
    for (int i =0 ; i < course->totalStudents ; i++){
        if(course->studentArray[i].grade >= cutOffGrade)
            printCourseDetails(&(course->studentArray[i]));
    }
}

// Step 12 : Printing All courses with Pass Average Grade

void printCoursesWithPassAvgGrade(School* school, double cutOffGrade){
    printf ("Courses with pass average grade : \n");
    for (int i =0 ; i < school->totalCourses  ; i++){
        if(school->courseArray[i].averageGrade>= cutOffGrade)
            printCourseDetails(&(school->courseArray[i]));
    }
}