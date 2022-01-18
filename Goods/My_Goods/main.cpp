/*
 * @Author: your name
 * @Date: 2022-01-14 19:52:30
 * @LastEditTime: 2022-01-14 20:20:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Software Development\Test\Test12\01.cpp
 */
 // main.cpp
#include <iostream>
#include "goods.h"
using namespace std;
int main()
{
//用户名和密码，输错三次密码，直接退出系统
//使用者分为普通用户和管理员，普通用户账号：747063715 密码：123456789
//                                                 管理员账号： root   密码：root

string Admin;
string Passwd;
int option = 1;
int k = 0;
//登录管理系统
cout << "欢迎登陆商品管理系统！" << endl;
while (k!=3)
{
    cout << "请输入用户名：";
    cin >> Admin;
    cout << "请输入密码：";
    cin >> Passwd;
    if ((Admin == "747063715") && (Passwd == "123456789") || (Admin == "root") && (Passwd == "root"))
    {
        cout << "登录成功！" << endl;
        break;
    }
    else
        k++;
        cout << "用户名或密码错误，请重新输入：" << endl;
}
if (k == 3)
{
    exit(-1);                      //输错三次密码，直接退出系统
}


    char select;
    mana men;//对象

    while (select = men.first_face())
    {
        switch (select)
        {
        case '1':
            men.in_storage();
            break;
        case '2':
            men.out_storage();
            break;
        case '3':
            if ((Admin == "root") && (Passwd == "root"))
            {
                men.select_ele();                                                                                               //管理员权限才可以查询
            }
            else
            {
                cout << "权限不够！" << endl;
            }
            break;
        case '4':
            if ((Admin == "root") && (Passwd == "root"))                                                   //管理员权限才可以报损
            {
                men.call_break();
            }
            else
            {
                cout << "权限不够！" << endl;
            }
            break;
        case '5':
            cout << "\t"
                << "谢谢使用!!!!" << endl
                << endl
                << "\t\t";
            exit(-1);
            break;
        default:
            break;
        }
    }
    return 0;
}
