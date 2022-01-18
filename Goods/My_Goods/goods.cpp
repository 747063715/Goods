/*
 * @Author: your name
 * @Date: 2022-01-14 19:55:28
 * @LastEditTime: 2022-01-14 20:18:22
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Software Development\Test\Test12\goods.cpp
 */
#include <bits/stdc++.h>
#include "goods.h"
using namespace std;

//��Ʒ��Ĭ�Ϲ��캯��
ele::ele() : sh()
{
    name = "xxx"; //��Ʒ��
    price = 0.0;  //�۸�
    count = 0;    //��Ʒ����
}

//�ֿ������Ĭ�Ϲ��캯��
shelf::shelf() : men()
{
    storeNo = "xxx"; //�ֿ���
    kinds = "xxx";   //��������
    shelfNo = "xxx";
    ; //���ܺ�
}

//�ֿ����Ա��
admin::admin()
{
    name = "xxx";
}

//������Ĭ�Ϲ��캯��
mana::mana() : aele(), ashelf(), abs()
{
}

//��ҳ
char mana::first_face()
{
    char select, option;
    cout << endl;
    cout << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t                    ��Ʒ����ϵͳ                     " << endl
        << "\t\t " << endl
        << "\t\t " << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t " << endl
        << "\t\t               1. ��Ʒ��� 3. ��ѯͳ�� " << endl
        << "\t\t " << endl
        << "\t\t               2. ��Ʒ���� 4. ��Ʒ���� " << endl
        << "\t\t " << endl
        << "\t\t                         5. �˳�ϵͳ  " << endl
        << endl
        << endl
        << endl
        << "��ѡ��" << endl;
    cin >> option;
    select = option;
    return select;            //getch(): �������ַ���ʱ��,��Ļ�ϲ�������������ַ�
}

//���
void mana::in_storage()
{

    string name;    //��Ʒ��
    double price;   //�۸�
    string storeNo; //�ֿ���
    string kinds;   //��������
    string shelfNo; //���ܺ�
    long count = 0; //��Ʒ������

    cout << endl
        << "��Ʒ��⣬�����������Ϣ : " << endl
        << endl;
    cout << "\t��Ʒ���� : ";
    cin >> name;
    cout << endl
        << "\t��Ʒ�۸� : ";
    cin >> price;
    cout << endl
        << "\t��Ʒ���� : ";
    cin >> count;
    cout << endl
        << "\t�ֿ��� : ";
    cin >> storeNo;
    cout << endl
        << "\t�������� : ";
    cin >> kinds;
    cout << endl
        << "\t���ܱ�� : ";
    cin >> shelfNo;

    ofstream storeFile("infile.txt", ios::app);
    storeFile << setiosflags(ios::left) << setw(20) << name << " "
        << setw(15) << price << " " << setw(10) << count << " "
        << setw(10) << storeNo << " " << setw(20) << kinds << " "
        << shelfNo << endl;
    storeFile.close();
    cout << endl<< endl<< "\t����Ʒ�Ѿ����......." << endl<< endl<< "\t";
    system("cls");
}

// ����
void mana::out_storage()
{

    string name; //��Ʒ��

    cout << endl
        << "\t��Ʒ���⣬���������Ʒ��Ϣ : " << endl
        << endl;
    cout << "\t��Ʒ���� : ";
    cin >> name;

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        ofstream storeFile1("infile.txt");
        storeFile1.close();
        cout << endl
            << endl
            << "\t�ִ�Ϊ��!!!!" << endl
            << endl
            << "\t";
        system("cls");
        return;
    }
    bool flag = false;
    string name1;    //��Ʒ��
    double price1;   //�۸�
    string storeNo1; //�ֿ���
    string kinds1;   //��������
    string shelfNo1; //���ܺ�
    long count1 = 0; //��Ʒ����

    ofstream tempFile("temp.txt");

    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (name1 == name)
            flag = true;
        else
        {
            tempFile << setiosflags(ios::left) << setw(20) << name1 << " "
                << setw(15) << price1 << " " << setw(10) << count1 << " "
                << setw(10) << storeNo1 << " " << setw(20) << kinds1 << " "
                << shelfNo1 << endl;
        }
    }
    tempFile.close();
    storeFile.close();

    if (!flag)
    {
        cout << endl
            << endl
            << "\t�ֿ���û��������Ʒ!!!" << endl
            << endl
            << "\t";
        system("cls");
        return;
    }

    ofstream storeFile1("infile.txt");
    ifstream tempFile1("temp.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();

    cout << endl
        << "\t��Щ��Ʒ�Ѿ�����, ����ϸ���!!!" << endl
        << endl
        << "\t";
}

//��ѯ
void mana::select_ele()
{
    while (1)
    {

        cout << endl
            << endl;
        cout << "\t=============================================================" << endl
            << "\t|| ||" << endl
            << "\t|| �� Ʒ �� ѯ ||" << endl
            << "\t|| ||" << endl
            << "\t|| 1. ����Ʒ���Ʋ�ѯ ||" << endl
            << "\t|| ||" << endl
            << "\t|| 2. ����Ʒ�۸��ѯ ||" << endl
            << "\t|| ||" << endl
            << "\t|| 3. �����ز�ѯ ||" << endl
            << "\t|| ||" << endl
            << "\t|| 4. ���� ||" << endl
            << "\t|| ||" << endl
            << "\t=============================================================" << endl
            << endl
            << "\t\t";
        char select;
        cin >> select;
        switch (select)
        {
        case '1':
            select_name();
            break;
        case '2':
            select_price();
            break;
        case '3':
            select_kind();
            break;
        case '4':
            return;
        default:
            break;
        }
    }
}

//����Ʒ���Ʋ�ѯ
void mana::select_name()
{
    cout << endl
        << "\t����Ʒ����ѯ : " << endl
        << endl;
    cout << "\t������Ʒ�� : ";
    string name;
    cin >> name;

    string name1;    //��Ʒ��
    double price1;   //�۸�
    string storeNo1; //�ֿ���
    string kinds1;   //��������
    string shelfNo1; //���ܺ�
    long count1 = 0; //��Ʒ����

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        cout << endl
            << endl
            << "\t�Բ�����Ŀ��Ϊ��!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    cout << endl
        << "��Ʒ�� "
        << "�۸� "
        << "��Ʒ���� "
        << "�ֿ��� "
        << "�������� "
        << "���ܺ�" << endl
        << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (name1 == name)
        {
            flag = true;
            cout << setiosflags(ios::left) << setw(15) << name1 << " "
                << setw(10) << price1 << " " << setw(10) << count1 << " "
                << setw(10) << storeNo1 << " " << setw(15) << kinds1 << " "
                << shelfNo1 << endl;
        }
    }
    storeFile.close();

    if (!flag)
        cout << endl
        << endl
        << "�Բ��𣬿����û��������Ʒ!!!";
    cout << endl
        << endl;
}
//����Ʒ�۸��ѯ
void mana::select_price()
{

    cout << endl
        << "\t����Ʒ�۸��ѯ : " << endl
        << endl;
    cout << "\t����۸� : ";
    double price;
    cin >> price;

    string name1;    //��Ʒ��
    double price1;   //�۸�
    string storeNo1; //�ֿ���
    string kinds1;   //��������
    string shelfNo1; //���ܺ�
    long count1 = 0; //��Ʒ����

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        cout << endl
            << endl
            << "\t�Բ�����Ŀ��Ϊ��!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    cout << endl
        << "��Ʒ�� "
        << "�۸� "
        << "��Ʒ���� "
        << "�ֿ��� "
        << "�������� "
        << "���ܺ�" << endl
        << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (price1 == price)
        {
            flag = true;
            cout << setiosflags(ios::left) << setw(15) << name1 << " "
                << setw(10) << price1 << " " << setw(10) << count1 << " "
                << setw(10) << storeNo1 << " " << setw(15) << kinds1 << " "
                << shelfNo1 << endl;
        }
    }
    storeFile.close();

    if (!flag)
        cout << endl
        << endl
        << "�Բ��𣬿����û������۸����Ʒ!!!";
    cout << endl
        << endl;
}

//�����ز�ѯ
void mana::select_kind()
{

    cout << endl
        << "\t���������ز�ѯ : " << endl
        << endl;
    cout << "\t��������� : ";
    string kinds;
    cin >> kinds;

    string name1;    //��Ʒ��
    double price1;   //�۸�
    string storeNo1; //�ֿ���
    string kinds1;   //��������
    string shelfNo1; //���ܺ�
    long count1 = 0; //��Ʒ����

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        cout << endl
            << endl
            << "\t�Բ�����Ŀ��Ϊ��!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    cout << endl
        << "��Ʒ�� "
        << "�۸� "
        << "��Ʒ���� "
        << "�ֿ��� "
        << "�������� "
        << "���ܺ�" << endl
        << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (kinds1 == kinds)
        {
            flag = true;
            cout << setiosflags(ios::left) << setw(15) << name1 << " "
                << setw(10) << price1 << " " << setw(10) << count1 << " "
                << setw(10) << storeNo1 << " " << setw(15) << kinds1 << " "
                << shelfNo1 << endl;
        }
    }
    storeFile.close();

    if (!flag)
        cout << endl
        << endl
        << "�Բ��𣬿����û��������Ʒ!!!";
    cout << endl
        << endl;
}

//��Ʒ����
void mana::call_break()
{

    string name; //��Ʒ��

    cout << endl
        << "\t��Ʒ����������Ҫ������Ʒ��Ϣ : " << endl
        << endl;
    cout << "\t��Ʒ���� : ";
    cin >> name;

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        ofstream storeFile1("infile.txt");
        storeFile1.close();
        cout << endl
            << endl
            << "\t�ִ�Ϊ��!!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    string name1;    //��Ʒ��
    double price1;   //�۸�
    string kinds1;   //��������
    string shelfNo1; //���ܺ�
    long count1 = 0; //��Ʒ����

    ofstream tempFile("temp.txt");
    string storeNo1; //�ֿ���
    cout << endl
        << endl
        << "���뱨����Ʒ��Ϣ���� : " << endl
        << endl;
    cout << endl
        << "��Ʒ�� "
        << "�۸� "
        << "��Ʒ���� "
        << "�ֿ��� "
        << "�������� "
        << "���ܺ�" << endl
        << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (name1 == name)
        {
            flag = true;
            cout << setiosflags(ios::left) << setw(15) << name1 << " "
                << setw(10) << price1 << " " << setw(10) << count1 << " "
                << setw(10) << storeNo1 << " " << setw(15) << kinds1 << " "
                << shelfNo1 << endl;
            shelfNo1 += "(����)";
        }
        tempFile << setiosflags(ios::left) << setw(20) << name1 << " "
            << setw(15) << price1 << " " << setw(10) << count1 << " "
            << setw(10) << storeNo1 << " " << setw(20) << kinds1 << " "
            << shelfNo1 << endl;
    }
    tempFile.close();
    storeFile.close();

    if (!flag)
    {
        cout << endl
            << endl
            << "�Բ��𣬲ֿ���û��������Ʒ!!!" << endl
            << endl;

        return;
    }
    ofstream storeFile1("infile.txt");
    ifstream tempFile1("temp.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();

    cout << endl
        << endl
        << "��Щ��Ʒ�Ѿ��𻵣��뾡��Ӳֿ���ȡ��!!!" << endl
        << endl;
    cout << "����ɹ�����¼�Ѿ�����!!!" << endl
        << endl;
}
