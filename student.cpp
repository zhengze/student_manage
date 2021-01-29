#include<iostream>
#include "student.h"

using namespace std;

void displayStudent(Student *stu_head) {
    Student *curNode = stu_head;
    cout << "学号\t\t姓名\t\t性别\t年龄\t成绩" << endl;
    while(curNode != NULL) {
         cout << curNode->no << "\t\t" << curNode->name << "\t\t" << curNode->sex << "\t" << curNode->age << "\t" << curNode->score << endl;
         curNode = curNode->next;
    }
}

Student* searchStudent(Student *stu_head) {
    string sno;
    cout << "please input student no:" << endl;
    cin >> sno;
    Student *curNode = stu_head;
    cout << "学号\t\t姓名\t\t性别\t年龄\t成绩" << endl;
    while(curNode != NULL) {
        if(curNode->no == sno) {
             cout << curNode->no << "\t\t" << curNode->name << "\t\t" << curNode->sex << "\t" << curNode->age << "\t" << curNode->score << endl;
             break;
        } else {
            if(curNode->next != NULL){
                curNode = curNode->next;
            } else {
                break;
            }
        }
    }
    return curNode;
}

Student* addStudent(Student *stu_head) {
    Student *student = new Student;
    cout << "input no:" << endl;
    cin >> student->no;
    cout << "input name:" << endl;
    cin >> student->name;
    cout << "input age:" << endl;
    cin >> student->age;
    cout << "input sex:" << endl;
    cin >> student->sex;
    cout << "input score:" << endl;
    cin >> student->score;

    student->next = NULL;

    if (stu_head == NULL){
        stu_head = student;
    } else {
        student->next = stu_head->next;
        stu_head->next = student;
    }
    return stu_head;
}

void modStudent(Student *stu_head) {
    Student *curNode = searchStudent(stu_head);
    if(curNode != NULL) {
        cout << "input your modify select:" << endl;
        cout << "1)name" << endl;
        cout << "2)sex" << endl;
        cout << "3)age" << endl;
        cout << "4)score" << endl;
        int key;
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "input name:" << endl;
            cin >> curNode->name;
            break;
        case 2:
            cout << "input sex:" << endl;
            cin >> curNode->sex;
            break;
        case 3:
            cout << "input age:" << endl;
            cin >> curNode->age;
            break;
        case 4:
            cout << "input score:" << endl;
            cin >> curNode->score;
            break;
        default:
            break;
        }
        cout << "学号\t\t姓名\t\t性别\t年龄\t成绩" << endl;
        cout << curNode->no << "\t\t" << curNode->name << "\t\t" << curNode->sex << "\t" << curNode->age << "\t" << curNode->score << endl;
    }

}

Student* delStudentByNo(Student *stu_head, string sno) {
    Student *curNode = stu_head;
    if(stu_head != NULL && stu_head->no == sno) {
        if(stu_head->next != NULL) {
            Student* delNode = stu_head;
            stu_head = stu_head->next;
            delNode = NULL;
        } else {
            stu_head = NULL;
        }
        
    }

    while(curNode != NULL && curNode->next != NULL){
        if(curNode->next->no == sno){
            Student *delNode = NULL;
            delNode = curNode->next;
            curNode->next = curNode->next->next;
            delNode = NULL;  
            break;
        } else {
            curNode = curNode->next;
        }
        // displayStudent(stu_head);
    }
    return stu_head;
}

