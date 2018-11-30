//使用方法： 定义一个Class对象: Class c;
//           调用函数 c.GetSelect();

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


struct Student         //定义学生结构体Student
{
    int Num;           //学号
    char Name[20];     //姓名
    int Math;          //各科成绩
    int English;
    int Physical;
    int Sum;           //总分
    int Average;       //平均分
};


class Class            //班级类，由学生组成
{
public:
    void GetSelect();   //获得用户输入并执行相应的动作

private:
    void Operate1();    //添加学生信息
    void Operate2();    //修改学生信息
    void Operate4();    //按学号查询学生信息
    void Operate5();    //按姓名查询学生信息

    void AddStudent(int, const char *, double, double, double);     //用函数参数添加一个学生的信息
    void ModifyStudent(int, const char*, double, double, double);   //用函数参数修改学生信息

    void SearchByNum(int);               //函数参数为学号，找出该学号的学生信息
    void SearchByName(const char*);      //函数参数为姓名，按姓名查询学生信息

    void display();      //显示全部学生信息

    void SortByNum();    //按学号排序
    void SortBySum();    //按总分排序

private:
    vector<Student> Arr;   //类的数据为学生组成的vector数组
};


void Intruction();         //显示使用说明

#endif // STUDENT_H_INCLUDED
