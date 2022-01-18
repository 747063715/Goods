/*
 * @Author: your name
 * @Date: 2022-01-14 19:55:38
 * @LastEditTime: 2022-01-14 20:10:28
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Software Development\Test\Test12\goods.h
 */
#include <iostream>
using namespace std;
//管理员类
class admin
{
public:
    admin();

private:
    string name;
};

//仓库货架类
class shelf
{
public:
    shelf();

private:
    admin men;      //管理员
    string storeNo; //仓库编号
    string kinds;   //生产产地
    string shelfNo; //货架号
};

//商品类
class ele
{
public:
    ele();

private:
    string name;  //商品名
    double price; //价格
    shelf sh;     //所属货架
    long count;   //商品数量
};
//管理
class mana
{
public:
    mana();                       //构造函数
    char first_face();         //首页
    void in_storage();       //入库
    void out_storage();    // 出库
    void select_ele();       //查询
    void select_name();  //按商品名称查询
    void select_price();   //按商品价格查询
    void select_kind();    //按产地查询
    void call_break();      //商品报损
private:
    ele aele;                      //商品
    shelf ashelf;                //货架
    admin abs;                  //管理员
};

