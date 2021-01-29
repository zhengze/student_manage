#include<iostream>
#include "student.h"

using namespace std;

void printMenu() {
    cout << "**********************************" << endl;
    cout << "*\t0.退出" << endl;
    cout << "*\t1.打印学生信息" << endl;
    cout << "*\t2.添加学生信息" << endl;
    cout << "*\t3.通过学号查询学生信息" << endl;
    cout << "*\t4.修改学生信息" << endl;
    cout << "*\t5.删除学生信息" << endl;
    cout << "*\t6.清屏" << endl;
    cout << "**********************************" << endl;
    cout<< "please select:" << endl;
}

void keyDown() {
    Student *stu_head = NULL;

    int key;
    string sno;
    while(1) {
        printMenu();
        cin >> key;
        switch(key){
        case 0:
            exit(0);
        case 1:
            displayStudent(stu_head);
            break;
        case 2:
            stu_head = addStudent(stu_head);
            displayStudent(stu_head);
            break;
        case 3:
            searchStudent(stu_head);
            break;
        case 4:
            modStudent(stu_head);
            break;
        case 5:
            cout << "please input student no:" << endl;
            cin >> sno;
            stu_head = delStudentByNo(stu_head, sno);
            break;
        case 6:
            system("clear");
            break;
        default:
            cout << "not expected select" << endl;
            break;
        }

    }
}

int main() {
    keyDown();
    return 0;
}
