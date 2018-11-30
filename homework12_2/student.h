//ʹ�÷����� ����һ��Class����: Class c;
//           ���ú��� c.GetSelect();

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


struct Student         //����ѧ���ṹ��Student
{
    int Num;           //ѧ��
    char Name[20];     //����
    int Math;          //���Ƴɼ�
    int English;
    int Physical;
    int Sum;           //�ܷ�
    int Average;       //ƽ����
};


class Class            //�༶�࣬��ѧ�����
{
public:
    void GetSelect();   //����û����벢ִ����Ӧ�Ķ���

private:
    void Operate1();    //���ѧ����Ϣ
    void Operate2();    //�޸�ѧ����Ϣ
    void Operate4();    //��ѧ�Ų�ѯѧ����Ϣ
    void Operate5();    //��������ѯѧ����Ϣ

    void AddStudent(int, const char *, double, double, double);     //�ú����������һ��ѧ������Ϣ
    void ModifyStudent(int, const char*, double, double, double);   //�ú��������޸�ѧ����Ϣ

    void SearchByNum(int);               //��������Ϊѧ�ţ��ҳ���ѧ�ŵ�ѧ����Ϣ
    void SearchByName(const char*);      //��������Ϊ��������������ѯѧ����Ϣ

    void display();      //��ʾȫ��ѧ����Ϣ

    void SortByNum();    //��ѧ������
    void SortBySum();    //���ܷ�����

private:
    vector<Student> Arr;   //�������Ϊѧ����ɵ�vector����
};


void Intruction();         //��ʾʹ��˵��

#endif // STUDENT_H_INCLUDED
