#include <iostream>
#include <iomanip>
#include <fstream>
#include "Goods.h"
using namespace std;
//���˵�
void menu()
{
    Goods goods;
    //�û���������
    long long admin;
    long long passwd;
    int option = 1;
    //��¼����ϵͳ
    cout << "��ӭ��½��Ʒ����ϵͳ��" << endl;
    while (1)
    {
        cout << "�������û�����";
        cin >> admin;
        cout << "���������룺";
        cin >> passwd;
        if ((admin == 747063715) && (passwd == 123456789))
        {
            cout << "��¼�ɹ���" << endl;
            break;
        }
        else
            cout << "�û���������������������룺" << endl;
    }
    cout << endl;
    cout << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t                    ��Ʒ����ϵͳ                     " << endl
        << "\t\t " << endl
        << "\t\t " << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t " << endl
        << "\t\t               1. �����Ʒ 4. �޸���Ϣ " << endl
        << "\t\t " << endl
        << "\t\t               2. ɾ����Ʒ 5. ���ۼ۲�ѯ " << endl
        << "\t\t " << endl
        << "\t\t               3. ��ʾ��Ʒ  0. �˳�      "<< endl
        << endl
        << endl;
    while (option)
    {
        cout << endl;
        cout << "\t\t\t\tѡ��";
        cin >> option;
        switch (option)
        {
        case 1:
            goods.Add();
            break;
        case 2:
            goods.Delete();
            break;
        case 3:
            goods.Showall();
            break;
        case 4:
            goods.ReviseInfo();
            break;
        case 5:
            goods.SelectInprice();
            break;
        case 0:
            cout << "\t\t\t\t��ӭ�´�ʹ�ã�";
            break;
        default:
            cout << "\t\t\t\t����������������룺";
        }
    }
}
Goods::Goods() {}
Goods::Goods(string Name, string Type, string Manufecter, int Storage, string Brand, float In_price, float Out_price)
{
    this->name = Name;
    this->type = Type;
    this->manufecter = Manufecter;
    this->storage = Storage;
    this->brand = Brand;
    this->in_price = In_price;
    this->out_price = Out_price;
}
Goods::~Goods() {}
void Goods::Showall()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);
    if (!ifp2)
    {
        cout << "�޷��ҵ��ļ�" << endl;
        return;
    }
    //����һ����־�������ж��Ƿ��ȡ�����һ��
    bool flag = true;
    string record;
    cout << "����" << setw(15)<<"����" << setw(15) << "������" << setw(15) << "�����" << setw(15) << "Ʒ��" << setw(15) << "����" << setw(15) << "�ۼ�" << endl;
    while (getline(ifp2, record))
    {
        cout << record << endl;
        flag = false;
    }
    if (flag)
    {
        cout << endl << "��ļ�¼��û����Ʒ" << endl << endl;
    }
    else
    {
        cout << endl << "������Ʒ�Ѿ�ȫ����ʾ����" << endl << endl;
    }
}
void Goods::Add()
{
    cout << "��������Ʒ����Ϣ��";
    cin >>  name >> type >> manufecter >> storage >> brand >> in_price >> out_price;
    ofstream ofp("D:\\Desktop\\Project\\Goods Lists.txt", ios::app);
    if (!ofp)
    {
        cout << "�޷����ļ���" << endl;
        return;
    }
    ofp << setiosflags(ios::left) <<  setw(15) << name << setw(15) << type << setw(15) << manufecter << setw(15) << storage << setw(15) << brand << setw(15) << in_price << setw(15) << out_price << endl;
    ofp.close();
}
void Goods::Delete()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);                         //ԭ�ļ�
    ofstream ofp("D:\\Desktop\\Project\\temp.txt", ios::out);                                //��ʱ�ļ�
    if (!ifp2 || !ofp)
    {
        cout << "�޷��ҵ��ļ�" << endl;
        getchar();
        cin.sync();
        return;
    }
    string  sign;
    cout << "������Ҫɾ������Ʒ����";
    cin >> sign;
    string list;
    bool flag = true;
    string str;
    while (ifp2 >> name)
    {
        getline(ifp2, str);
        if (sign == name)
        {
            cout << "����ɾ������Ʒ��" << endl;
            cout << setiosflags(ios::left)<< setw(20) << name << setw(10) << str << endl;
            int p;
            cout << "�밴1ȷ��ɾ����";
            cin >> p;
            if (p == 1)
            {
                flag = false;
            }
                break;
        }
        ofp<< setiosflags(ios::left) << setw(18) << name << setw(10) << str << endl;          //�����Լ�ɾ������Ʒ�Ž�temp.txt
    }
    if (flag)
    {
        cout << endl << "ɾ��ʧ��!" << endl << endl;
    }
    else
    {
        while (getline(ifp2, str))
        {
            ofp << str << endl;
            getchar;
        }
        ofp.close();
        ifp2.close();

        ofstream out("D:\\Desktop\\Project\\Goods Lists.txt", ios::out);
        ifstream in("D:\\Desktop\\Project\\temp.txt", ios::in);
        if (!out || !in)
        {
            cout << endl<<"�޷����ļ�" << endl << endl;

            return;
        }
        while (getline(in, str))
        {
            out << str << endl;
        }
        out.close();
        in.close();
        cout << endl << "����Ʒ����Ϣ�Ѿ��Ӽ�¼��ɾ��" << endl << endl;
        getchar();
    }
    getchar();
    cin.sync();
}

//���ۼ۽��в�ѯ
void Goods::SelectInprice()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::app);
    if (!ifp2)
    {
        cout << "�޷����ļ���" << endl << endl;
        getchar();
        return;
    }
    double sign(0);
    cout << "��������Ҫ��ѯ���ۼۣ�";
    cin >> sign;
    cin.clear();
    cin.sync();
    string list;
    bool flag = true;
    string str;
    while (ifp2 >> name >> type >> manufecter >> storage >> brand >> in_price >> out_price)
    {
        getline(ifp2, str);
        if (sign == out_price)                 //���ۼ�һ��һ�еĲ���
        {
            cout << list << endl;
            cout << setiosflags(ios::left) << setw(20) << name << setw(23) << type << setw(15) << manufecter << setw(15) << storage << setw(10) << brand << setw(10) << in_price << setw(10) << out_price << endl;
        }
    }
    cout << "��0�������˵�" << endl;
    int k = 1;
    cin >> k;
    for (k; k == 0;)
    {
        flag = false;
        break;
    }
}
//�޸���Ϣ
void Goods::ReviseInfo()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);
    ofstream ofp("D:\\Desktop\\Project\\temp.txt", ios::out);
    if (!ifp2 || !ofp)
    {
        cout << "�޷����ļ�" << endl << endl;
        getchar();
        return;
    }
    string sign;
    cout << endl << "������Ҫ�޸ĵ���Ʒ�� :";
    cin >> sign;
    string list;
    bool flag = true;
    string str;
    while (ifp2 >> name)
    {
        getline(ifp2, str);
        if (sign == name)
        {
            cout << endl << "�����޸ĵ���Ʒ:" << endl;
            cout << list << endl;
            cout << setiosflags(ios::left) << setw(20) << name << setw(23) << type << setw(15) << manufecter << setw(15) << storage << setw(10) << brand << setw(10) << in_price << setw(10) << out_price << endl;
            flag = false;
            break;

        }
        ofp << setiosflags(ios::left) << setw(18) << name << setw(10) << str << endl;

    }
    if (flag)
    {
        cout << endl << "�޷��ҵ�����Ʒ" << endl;
        return;
    }
    else
    {
        while (getline(ifp2, str))
        {
            ofp << str << endl;
        }
        ofp.close();
        ifp2.close();

        ofstream out("D:\\Desktop\\Project\\Goods Lists.txt", ios::out);
        ifstream in("D:\\Desktop\\Project\\temp.txt", ios::in);
        if (!out || !in)
        {
            cout << endl << "���� �޷����ļ�" << endl << endl;
            getchar();
            return;
        }
        while (getline(in, str))
        {
            out << str << endl;
        }
        out.close();
        in.close();
    }
    cout << endl << "�밴���²��������޸ģ�" << endl;
    Add();
    cout << endl << endl << "����Ʒ��Ϣ�Ѿ�����" << endl << endl;
}
void Goods::select()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);
    if (!ifp2)
    {
        cout << endl << "���޷����ļ�" << endl << endl;
        getchar();
        return;
    }
    string sign;
    cout << endl << "����������ҵ�����Ʒ�� : ";
    cin >> sign;
    cin.clear(); cin.sync();
    string str;
    bool flag = true;
    while (ifp2 >> name)
    {
        getline(ifp2, str);
        if (name == sign)
        {
            cout << endl << "��Ҫ���ҵ���Ʒ��: " << endl;
            cout << "����" << setw(18) << "����" << setw(20) << "������" << setw(15) << "�����" << setw(15) << "Ʒ��" << setw(9) << "����" << setw(10) << "�ۼ�" << endl;
            cout << setiosflags(ios::left) << setw(20) << name << setw(23) << type << setw(15) << manufecter << setw(15) << storage << setw(10) << brand << setw(10) << in_price << setw(10) << out_price << endl;

            cout << "��0�������˵�" << endl;
            int k = 1;
            cin >> k;
            for (k; k == 0;)
            {
                flag = false;
                break;

            }
        }
        else
        {
            cout << endl << "û����¼����Ʒ ���س��������˵�";
            break;
        }
    }
}

