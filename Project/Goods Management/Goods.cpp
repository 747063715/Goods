#include <iostream>
#include <iomanip>
#include <fstream>
#include "Goods.h"
using namespace std;
//主菜单
void menu()
{
    Goods goods;
    //用户名和密码
    long long admin;
    long long passwd;
    int option = 1;
    //登录管理系统
    cout << "欢迎登陆商品管理系统！" << endl;
    while (1)
    {
        cout << "请输入用户名：";
        cin >> admin;
        cout << "请输入密码：";
        cin >> passwd;
        if ((admin == 747063715) && (passwd == 123456789))
        {
            cout << "登录成功！" << endl;
            break;
        }
        else
            cout << "用户名或密码错误，请重新输入：" << endl;
    }
    cout << endl;
    cout << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t                    商品管理系统                     " << endl
        << "\t\t " << endl
        << "\t\t " << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t----------------------------------------------------" << endl
        << "\t\t " << endl
        << "\t\t               1. 添加商品 4. 修改信息 " << endl
        << "\t\t " << endl
        << "\t\t               2. 删除商品 5. 按售价查询 " << endl
        << "\t\t " << endl
        << "\t\t               3. 显示商品  0. 退出      "<< endl
        << endl
        << endl;
    while (option)
    {
        cout << endl;
        cout << "\t\t\t\t选择：";
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
            cout << "\t\t\t\t欢迎下次使用！";
            break;
        default:
            cout << "\t\t\t\t输入错误，请重新输入：";
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
        cout << "无法找到文件" << endl;
        return;
    }
    //定义一个标志，用来判断是否读取到最后一行
    bool flag = true;
    string record;
    cout << "名称" << setw(15)<<"类型" << setw(15) << "生产商" << setw(15) << "库存量" << setw(15) << "品牌" << setw(15) << "进价" << setw(15) << "售价" << endl;
    while (getline(ifp2, record))
    {
        cout << record << endl;
        flag = false;
    }
    if (flag)
    {
        cout << endl << "你的记录中没有商品" << endl << endl;
    }
    else
    {
        cout << endl << "所有商品已经全部显示出来" << endl << endl;
    }
}
void Goods::Add()
{
    cout << "请输入商品的信息：";
    cin >>  name >> type >> manufecter >> storage >> brand >> in_price >> out_price;
    ofstream ofp("D:\\Desktop\\Project\\Goods Lists.txt", ios::app);
    if (!ofp)
    {
        cout << "无法打开文件！" << endl;
        return;
    }
    ofp << setiosflags(ios::left) <<  setw(15) << name << setw(15) << type << setw(15) << manufecter << setw(15) << storage << setw(15) << brand << setw(15) << in_price << setw(15) << out_price << endl;
    ofp.close();
}
void Goods::Delete()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);                         //原文件
    ofstream ofp("D:\\Desktop\\Project\\temp.txt", ios::out);                                //临时文件
    if (!ifp2 || !ofp)
    {
        cout << "无法找到文件" << endl;
        getchar();
        cin.sync();
        return;
    }
    string  sign;
    cout << "请输入要删除的商品名：";
    cin >> sign;
    string list;
    bool flag = true;
    string str;
    while (ifp2 >> name)
    {
        getline(ifp2, str);
        if (sign == name)
        {
            cout << "你想删除的商品：" << endl;
            cout << setiosflags(ios::left)<< setw(20) << name << setw(10) << str << endl;
            int p;
            cout << "请按1确认删除：";
            cin >> p;
            if (p == 1)
            {
                flag = false;
            }
                break;
        }
        ofp<< setiosflags(ios::left) << setw(18) << name << setw(10) << str << endl;          //不是自己删除的商品放进temp.txt
    }
    if (flag)
    {
        cout << endl << "删除失败!" << endl << endl;
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
            cout << endl<<"无法打开文件" << endl << endl;

            return;
        }
        while (getline(in, str))
        {
            out << str << endl;
        }
        out.close();
        in.close();
        cout << endl << "该商品的信息已经从记录中删除" << endl << endl;
        getchar();
    }
    getchar();
    cin.sync();
}

//按售价进行查询
void Goods::SelectInprice()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::app);
    if (!ifp2)
    {
        cout << "无法打开文件！" << endl << endl;
        getchar();
        return;
    }
    double sign(0);
    cout << "请输入你要查询的售价：";
    cin >> sign;
    cin.clear();
    cin.sync();
    string list;
    bool flag = true;
    string str;
    while (ifp2 >> name >> type >> manufecter >> storage >> brand >> in_price >> out_price)
    {
        getline(ifp2, str);
        if (sign == out_price)                 //按售价一行一行的查找
        {
            cout << list << endl;
            cout << setiosflags(ios::left) << setw(20) << name << setw(23) << type << setw(15) << manufecter << setw(15) << storage << setw(10) << brand << setw(10) << in_price << setw(10) << out_price << endl;
        }
    }
    cout << "按0返回主菜单" << endl;
    int k = 1;
    cin >> k;
    for (k; k == 0;)
    {
        flag = false;
        break;
    }
}
//修改信息
void Goods::ReviseInfo()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);
    ofstream ofp("D:\\Desktop\\Project\\temp.txt", ios::out);
    if (!ifp2 || !ofp)
    {
        cout << "无法打开文件" << endl << endl;
        getchar();
        return;
    }
    string sign;
    cout << endl << "输入你要修改的商品名 :";
    cin >> sign;
    string list;
    bool flag = true;
    string str;
    while (ifp2 >> name)
    {
        getline(ifp2, str);
        if (sign == name)
        {
            cout << endl << "你想修改的商品:" << endl;
            cout << list << endl;
            cout << setiosflags(ios::left) << setw(20) << name << setw(23) << type << setw(15) << manufecter << setw(15) << storage << setw(10) << brand << setw(10) << in_price << setw(10) << out_price << endl;
            flag = false;
            break;

        }
        ofp << setiosflags(ios::left) << setw(18) << name << setw(10) << str << endl;

    }
    if (flag)
    {
        cout << endl << "无法找到该商品" << endl;
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
            cout << endl << "错误 无法打开文件" << endl << endl;
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
    cout << endl << "请按以下步骤输入修改：" << endl;
    Add();
    cout << endl << endl << "新商品信息已经保存" << endl << endl;
}
void Goods::select()
{
    ifstream ifp2("D:\\Desktop\\Project\\Goods Lists.txt", ios::in);
    if (!ifp2)
    {
        cout << endl << "误无法打开文件" << endl << endl;
        getchar();
        return;
    }
    string sign;
    cout << endl << "输入你想查找的商商品名 : ";
    cin >> sign;
    cin.clear(); cin.sync();
    string str;
    bool flag = true;
    while (ifp2 >> name)
    {
        getline(ifp2, str);
        if (name == sign)
        {
            cout << endl << "你要查找的商品是: " << endl;
            cout << "名称" << setw(18) << "类型" << setw(20) << "生产商" << setw(15) << "库存量" << setw(15) << "品牌" << setw(9) << "进价" << setw(10) << "售价" << endl;
            cout << setiosflags(ios::left) << setw(20) << name << setw(23) << type << setw(15) << manufecter << setw(15) << storage << setw(10) << brand << setw(10) << in_price << setw(10) << out_price << endl;

            cout << "按0返回主菜单" << endl;
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
            cout << endl << "没有收录该商品 按回车返回主菜单";
            break;
        }
    }
}

