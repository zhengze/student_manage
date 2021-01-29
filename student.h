#include<iostream>
#include<string>

using namespace std;

struct Student {
    string no;
    string name;
    string sex;
    int age;
    int score;
    Student *next;

};

void displayStudent(Student *stu_head);
Student* searchStudent(Student *stu_head);
Student* addStudent(Student *stu_head);
void modStudent(Student *stu_head);
Student* delStudentByNo(Student *stu_head, string sno);
