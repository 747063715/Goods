/*
 * @Author: your name
 * @Date: 2022-01-14 19:55:38
 * @LastEditTime: 2022-01-14 20:10:28
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Software Development\Test\Test12\goods.h
 */
#include <iostream>
using namespace std;
//����Ա��
class admin
{
public:
    admin();

private:
    string name;
};

//�ֿ������
class shelf
{
public:
    shelf();

private:
    admin men;      //����Ա
    string storeNo; //�ֿ���
    string kinds;   //��������
    string shelfNo; //���ܺ�
};

//��Ʒ��
class ele
{
public:
    ele();

private:
    string name;  //��Ʒ��
    double price; //�۸�
    shelf sh;     //��������
    long count;   //��Ʒ����
};
//����
class mana
{
public:
    mana();                       //���캯��
    char first_face();         //��ҳ
    void in_storage();       //���
    void out_storage();    // ����
    void select_ele();       //��ѯ
    void select_name();  //����Ʒ���Ʋ�ѯ
    void select_price();   //����Ʒ�۸��ѯ
    void select_kind();    //�����ز�ѯ
    void call_break();      //��Ʒ����
private:
    ele aele;                      //��Ʒ
    shelf ashelf;                //����
    admin abs;                  //����Ա
};

