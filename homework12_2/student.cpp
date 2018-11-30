#include "student.h"

void Intruction()    //显示使用说明
{
    cout << "欢迎使用成绩管理系统！" << endl;
    cout << "1--添加学生信息" << endl;
    cout << "2--修改学生信息" << endl;
    cout << "3--显示全部学生信息" << endl;
    cout << "4--按学号查询学生信息" << endl;
    cout << "5--按姓名查询学生信息" << endl;
    cout << "6--按学号升序排序" << endl;
    cout << "7--按总分降序排序" << endl;
    cout << "0--退出" << endl;
    cout << endl;
}

void Class::GetSelect()   //获得用户输入并执行相应的动作
{
    int select;
    cout << "请输入操作选择：";
    cin >> select;

    while(select != 0)
    {
        switch(select)
        {
            case 1: Operate1();  cout << endl; break;
            case 2: Operate2();  cout << endl; break;
            case 3: display();   cout << endl; break;   //显示全部学生信息
            case 4: Operate4();  cout << endl; break;
            case 5: Operate5();  cout << endl; break;
            case 6: SortByNum(); cout << endl; break;   //按学号排序
            case 7: SortBySum(); cout << endl; break;   //按总分排序
            default: cout << "无效操作选择" << endl;
        }
        cout << "请输入操作选择：";
        cin >> select;
    }

    cout << "退出成功" << endl;
}

void Class::Operate1()    //添加学生信息
{
    int n, m, e, p;
    char name[20];
    cout << "请输入学生的信息（学号，姓名，数学，英语，物理）：";
    cin >> n >> name >> m >> e >> p;   //依次获取学号姓名成绩
    AddStudent(n, name, m, e, p);
}

void Class::Operate2()    //修改学生信息
{
    int n, m, e, p;
    char name[20];
    cout << "请输入要修改信息的学生的学号：";
    cin >> n;

    cout << "请输入新的信息（姓名，数学，英语，物理）：";
    cin >> name >> m >> e >> p;
    ModifyStudent(n, name, m, e, p);
}

void Class::Operate4()     //按学号查询学生信息
{
    int n;
    cout << "请输入要查找的学生学号：";
    cin >> n;
    SearchByNum(n);
}

void Class::Operate5()     //按学号查询学生信息
{
    char name[20];
    cout << "请输入要查找的学生姓名：";
    cin >> name;
    SearchByName(name);
}


void Class::AddStudent(int num, const char *name, double m, double e, double p) //用函数参数添加一个学生的信息
{
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(Arr[i].Num == num)
        {
            cout << "系统中已有该学号的学生信息" << endl;
            return;
        }
    }
    Student stu;
    stu.Num = num;
    strcpy(stu.Name, name);
    stu.Math = m;
    stu.English = e;
    stu.Physical = p;
    stu.Sum = m + e + p;
    stu.Average = stu.Sum / 3;

    Arr.push_back(stu);        //将stu存入Arr数组
}

void Class::ModifyStudent(int num, const char *name, double m, double e, double p)  //用参数修改学生信息
{
    bool flag = false;
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(Arr[i].Num == num)    //匹配学生学号
        {
            strcpy(Arr[i].Name, name);
            Arr[i].Math = m;
            Arr[i].English = e;
            Arr[i].Physical = p;
            Arr[i].Sum = m + e + p;
            Arr[i].Average = Arr[i].Sum / 3;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "系统中没有该学生信息" << endl;
}

void Class::SearchByNum(int num)     //按输入的学号查询学生信息
{
    bool flag = false;
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(Arr[i].Num == num)
        {
            cout << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "英语" << '\t' <<
                    "物理" << '\t' << "总分" << '\t' << "平均分" << endl;
            cout << Arr[i].Num << '\t' << Arr[i].Name << '\t' << Arr[i].Math << '\t' <<
                Arr[i].English << '\t' << Arr[i].Physical << '\t' << Arr[i].Sum << '\t' << Arr[i].Average << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "系统中没有该学生信息" << endl;
}

void Class::SearchByName(const char *name)   //按输入的姓名查询学生信息
{
    bool flag = false;
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(!strcmp(Arr[i].Name, name))
        {
            cout << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "英语" << '\t' <<
                    "物理" << '\t' << "总分" << '\t' << "平均分" << endl;
            cout << Arr[i].Num << '\t' << Arr[i].Name << '\t' << Arr[i].Math << '\t' <<
                Arr[i].English << '\t' << Arr[i].Physical << '\t' << Arr[i].Sum << '\t' << Arr[i].Average << endl;
            flag = true;
        }
    }
    if(!flag)
        cout << "系统中没有该学生信息" << endl;
}

void Class::SortByNum()    //按学号排序
{
    int n = Arr.size();
    int i, j;
    Student tmp;
    bool flag;
    for(i=1; i<n; i++)    //冒泡排序
    {
        flag = false;
        for(j=0; j<n-i; j++)
        {
            if(Arr[j+1].Num < Arr[j].Num)
            {
                tmp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = tmp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}

void Class::SortBySum()    //按总分排序
{
    int n = Arr.size();
    int i, j;
    Student tmp;
    bool flag;
    for(i=1; i<n; i++)
    {
        flag = false;
        for(j=0; j<n-i; j++)
        {
            if(Arr[j+1].Sum > Arr[j].Sum)
            {
                tmp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = tmp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}

void Class::display()    //显示全部学生信息
{
    int n = Arr.size();
    if(n == 0)
    {
        cout << "系统中没有任何学生信息" << endl;
        return;
    }

    cout << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "英语" << '\t' <<
            "物理" << '\t' << "总分" << '\t' << "平均分" << endl;
    for(int i=0; i<n; i++)
    {
        cout << Arr[i].Num << '\t' << Arr[i].Name << '\t' << Arr[i].Math << '\t' <<
                Arr[i].English << '\t' << Arr[i].Physical << '\t' << Arr[i].Sum << '\t' << Arr[i].Average << endl;
    }
}
