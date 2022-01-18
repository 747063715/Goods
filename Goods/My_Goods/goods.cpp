/*
 * @Author: your name
 * @Date: 2022-01-14 19:55:28
 * @LastEditTime: 2022-01-14 20:18:22
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Software Development\Test\Test12\goods.cpp
 */
#include <bits/stdc++.h>
#include "goods.h"
using namespace std;

//商品类默认构造函数
ele::ele() : sh()
{
    name = "xxx"; //商品名
    price = 0.0;  //价格
    count = 0;    //商品数量
}

//仓库货架类默认构造函数
shelf::shelf() : men()
{
    storeNo = "xxx"; //仓库编号
    kinds = "xxx";   //生产产地
    shelfNo = "xxx";
    ; //货架号
}

//仓库管理员类
admin::admin()
{
    name = "xxx";
}

//管理类默认构造函数
mana::mana() : aele(), ashelf(), abs()
{
}

//首页
char mana::first_face()
{
    char select, option;
    cout << endl;
    cout << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t                    商品管理系统                     " << endl
        << "\t\t " << endl
        << "\t\t " << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t " << endl
        << "\t\t               1. 商品入库 3. 查询统计 " << endl
        << "\t\t " << endl
        << "\t\t               2. 商品出库 4. 商品报损 " << endl
        << "\t\t " << endl
        << "\t\t                         5. 退出系统  " << endl
        << endl
        << endl
        << endl
        << "请选择：" << endl;
    cin >> option;
    select = option;
    return select;            //getch(): 在输入字符的时候,屏幕上并看不到输入的字符
}

//入库
void mana::in_storage()
{

    string name;    //商品名
    double price;   //价格
    string storeNo; //仓库编号
    string kinds;   //生产产地
    string shelfNo; //货架号
    long count = 0; //商品的数量

    cout << endl
        << "商品入库，请输入相关信息 : " << endl
        << endl;
    cout << "\t商品名称 : ";
    cin >> name;
    cout << endl
        << "\t商品价格 : ";
    cin >> price;
    cout << endl
        << "\t商品数量 : ";
    cin >> count;
    cout << endl
        << "\t仓库编号 : ";
    cin >> storeNo;
    cout << endl
        << "\t生产产地 : ";
    cin >> kinds;
    cout << endl
        << "\t货架编号 : ";
    cin >> shelfNo;

    ofstream storeFile("infile.txt", ios::app);
    storeFile << setiosflags(ios::left) << setw(20) << name << " "
        << setw(15) << price << " " << setw(10) << count << " "
        << setw(10) << storeNo << " " << setw(20) << kinds << " "
        << shelfNo << endl;
    storeFile.close();
    cout << endl<< endl<< "\t该商品已经入库......." << endl<< endl<< "\t";
    system("cls");
}

// 出库
void mana::out_storage()
{

    string name; //商品名

    cout << endl
        << "\t商品出库，输入出库商品信息 : " << endl
        << endl;
    cout << "\t商品名称 : ";
    cin >> name;

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        ofstream storeFile1("infile.txt");
        storeFile1.close();
        cout << endl
            << endl
            << "\t仓存为空!!!!" << endl
            << endl
            << "\t";
        system("cls");
        return;
    }
    bool flag = false;
    string name1;    //商品名
    double price1;   //价格
    string storeNo1; //仓库编号
    string kinds1;   //生产产地
    string shelfNo1; //货架号
    long count1 = 0; //商品数量

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
            << "\t仓库中没有这种商品!!!" << endl
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
        << "\t这些商品已经出库, 请仔细检查!!!" << endl
        << endl
        << "\t";
}

//查询
void mana::select_ele()
{
    while (1)
    {

        cout << endl
            << endl;
        cout << "\t=============================================================" << endl
            << "\t|| ||" << endl
            << "\t|| 商 品 查 询 ||" << endl
            << "\t|| ||" << endl
            << "\t|| 1. 按商品名称查询 ||" << endl
            << "\t|| ||" << endl
            << "\t|| 2. 按商品价格查询 ||" << endl
            << "\t|| ||" << endl
            << "\t|| 3. 按产地查询 ||" << endl
            << "\t|| ||" << endl
            << "\t|| 4. 返回 ||" << endl
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

//按商品名称查询
void mana::select_name()
{
    cout << endl
        << "\t按商品名查询 : " << endl
        << endl;
    cout << "\t输入商品名 : ";
    string name;
    cin >> name;

    string name1;    //商品名
    double price1;   //价格
    string storeNo1; //仓库编号
    string kinds1;   //生产产地
    string shelfNo1; //货架号
    long count1 = 0; //商品数量

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        cout << endl
            << endl
            << "\t对不起，你的库存为空!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    cout << endl
        << "商品名 "
        << "价格 "
        << "商品数量 "
        << "仓库编号 "
        << "生产产地 "
        << "货架号" << endl
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
        << "对不起，库存中没有这种商品!!!";
    cout << endl
        << endl;
}
//按商品价格查询
void mana::select_price()
{

    cout << endl
        << "\t按商品价格查询 : " << endl
        << endl;
    cout << "\t输入价格 : ";
    double price;
    cin >> price;

    string name1;    //商品名
    double price1;   //价格
    string storeNo1; //仓库编号
    string kinds1;   //生产产地
    string shelfNo1; //货架号
    long count1 = 0; //商品数量

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        cout << endl
            << endl
            << "\t对不起，你的库存为空!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    cout << endl
        << "商品名 "
        << "价格 "
        << "商品数量 "
        << "仓库编号 "
        << "生产产地 "
        << "货架号" << endl
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
        << "对不起，库存中没有这个价格的商品!!!";
    cout << endl
        << endl;
}

//按产地查询
void mana::select_kind()
{

    cout << endl
        << "\t按生产产地查询 : " << endl
        << endl;
    cout << "\t输入产地名 : ";
    string kinds;
    cin >> kinds;

    string name1;    //商品名
    double price1;   //价格
    string storeNo1; //仓库编号
    string kinds1;   //生产产地
    string shelfNo1; //货架号
    long count1 = 0; //商品数量

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        cout << endl
            << endl
            << "\t对不起，你的库存为空!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    cout << endl
        << "商品名 "
        << "价格 "
        << "商品数量 "
        << "仓库编号 "
        << "生产产地 "
        << "货架号" << endl
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
        << "对不起，库存中没有这类商品!!!";
    cout << endl
        << endl;
}

//商品报损
void mana::call_break()
{

    string name; //商品名

    cout << endl
        << "\t商品报损，请输入要报损商品信息 : " << endl
        << endl;
    cout << "\t商品名称 : ";
    cin >> name;

    ifstream storeFile("infile.txt");
    if (!storeFile)
    {
        ofstream storeFile1("infile.txt");
        storeFile1.close();
        cout << endl
            << endl
            << "\t仓存为空!!!!" << endl
            << endl
            << "\t";

        return;
    }

    bool flag = false;
    string name1;    //商品名
    double price1;   //价格
    string kinds1;   //生产产地
    string shelfNo1; //货架号
    long count1 = 0; //商品数量

    ofstream tempFile("temp.txt");
    string storeNo1; //仓库编号
    cout << endl
        << endl
        << "你想报损商品信息如下 : " << endl
        << endl;
    cout << endl
        << "商品名 "
        << "价格 "
        << "商品数量 "
        << "仓库编号 "
        << "生产产地 "
        << "货架号" << endl
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
            shelfNo1 += "(已损坏)";
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
            << "对不起，仓库中没有这种商品!!!" << endl
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
        << "这些商品已经损坏，请尽快从仓库中取出!!!" << endl
        << endl;
    cout << "报损成功，记录已经更改!!!" << endl
        << endl;
}
