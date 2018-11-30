#include "student.h"

void Intruction()    //��ʾʹ��˵��
{
    cout << "��ӭʹ�óɼ�����ϵͳ��" << endl;
    cout << "1--���ѧ����Ϣ" << endl;
    cout << "2--�޸�ѧ����Ϣ" << endl;
    cout << "3--��ʾȫ��ѧ����Ϣ" << endl;
    cout << "4--��ѧ�Ų�ѯѧ����Ϣ" << endl;
    cout << "5--��������ѯѧ����Ϣ" << endl;
    cout << "6--��ѧ����������" << endl;
    cout << "7--���ֽܷ�������" << endl;
    cout << "0--�˳�" << endl;
    cout << endl;
}

void Class::GetSelect()   //����û����벢ִ����Ӧ�Ķ���
{
    int select;
    cout << "���������ѡ��";
    cin >> select;

    while(select != 0)
    {
        switch(select)
        {
            case 1: Operate1();  cout << endl; break;
            case 2: Operate2();  cout << endl; break;
            case 3: display();   cout << endl; break;   //��ʾȫ��ѧ����Ϣ
            case 4: Operate4();  cout << endl; break;
            case 5: Operate5();  cout << endl; break;
            case 6: SortByNum(); cout << endl; break;   //��ѧ������
            case 7: SortBySum(); cout << endl; break;   //���ܷ�����
            default: cout << "��Ч����ѡ��" << endl;
        }
        cout << "���������ѡ��";
        cin >> select;
    }

    cout << "�˳��ɹ�" << endl;
}

void Class::Operate1()    //���ѧ����Ϣ
{
    int n, m, e, p;
    char name[20];
    cout << "������ѧ������Ϣ��ѧ�ţ���������ѧ��Ӣ�������";
    cin >> n >> name >> m >> e >> p;   //���λ�ȡѧ�������ɼ�
    AddStudent(n, name, m, e, p);
}

void Class::Operate2()    //�޸�ѧ����Ϣ
{
    int n, m, e, p;
    char name[20];
    cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
    cin >> n;

    cout << "�������µ���Ϣ����������ѧ��Ӣ�������";
    cin >> name >> m >> e >> p;
    ModifyStudent(n, name, m, e, p);
}

void Class::Operate4()     //��ѧ�Ų�ѯѧ����Ϣ
{
    int n;
    cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�";
    cin >> n;
    SearchByNum(n);
}

void Class::Operate5()     //��ѧ�Ų�ѯѧ����Ϣ
{
    char name[20];
    cout << "������Ҫ���ҵ�ѧ��������";
    cin >> name;
    SearchByName(name);
}


void Class::AddStudent(int num, const char *name, double m, double e, double p) //�ú����������һ��ѧ������Ϣ
{
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(Arr[i].Num == num)
        {
            cout << "ϵͳ�����и�ѧ�ŵ�ѧ����Ϣ" << endl;
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

    Arr.push_back(stu);        //��stu����Arr����
}

void Class::ModifyStudent(int num, const char *name, double m, double e, double p)  //�ò����޸�ѧ����Ϣ
{
    bool flag = false;
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(Arr[i].Num == num)    //ƥ��ѧ��ѧ��
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
        cout << "ϵͳ��û�и�ѧ����Ϣ" << endl;
}

void Class::SearchByNum(int num)     //�������ѧ�Ų�ѯѧ����Ϣ
{
    bool flag = false;
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(Arr[i].Num == num)
        {
            cout << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' <<
                    "����" << '\t' << "�ܷ�" << '\t' << "ƽ����" << endl;
            cout << Arr[i].Num << '\t' << Arr[i].Name << '\t' << Arr[i].Math << '\t' <<
                Arr[i].English << '\t' << Arr[i].Physical << '\t' << Arr[i].Sum << '\t' << Arr[i].Average << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "ϵͳ��û�и�ѧ����Ϣ" << endl;
}

void Class::SearchByName(const char *name)   //�������������ѯѧ����Ϣ
{
    bool flag = false;
    int n = Arr.size();
    for(int i=0; i<n; i++)
    {
        if(!strcmp(Arr[i].Name, name))
        {
            cout << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' <<
                    "����" << '\t' << "�ܷ�" << '\t' << "ƽ����" << endl;
            cout << Arr[i].Num << '\t' << Arr[i].Name << '\t' << Arr[i].Math << '\t' <<
                Arr[i].English << '\t' << Arr[i].Physical << '\t' << Arr[i].Sum << '\t' << Arr[i].Average << endl;
            flag = true;
        }
    }
    if(!flag)
        cout << "ϵͳ��û�и�ѧ����Ϣ" << endl;
}

void Class::SortByNum()    //��ѧ������
{
    int n = Arr.size();
    int i, j;
    Student tmp;
    bool flag;
    for(i=1; i<n; i++)    //ð������
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

void Class::SortBySum()    //���ܷ�����
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

void Class::display()    //��ʾȫ��ѧ����Ϣ
{
    int n = Arr.size();
    if(n == 0)
    {
        cout << "ϵͳ��û���κ�ѧ����Ϣ" << endl;
        return;
    }

    cout << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' <<
            "����" << '\t' << "�ܷ�" << '\t' << "ƽ����" << endl;
    for(int i=0; i<n; i++)
    {
        cout << Arr[i].Num << '\t' << Arr[i].Name << '\t' << Arr[i].Math << '\t' <<
                Arr[i].English << '\t' << Arr[i].Physical << '\t' << Arr[i].Sum << '\t' << Arr[i].Average << endl;
    }
}
