#include<iostream>
#include<string>
using namespace std;
//定义商品类
class Goods
{
private:
    /* data */
    long id;
    string name;
    string type;
    string manufecter;
    int storage;
    string brand;
    float in_price;
    float out_price;
public:
    Goods();
    Goods(string Name, string Type, string Manufecter, int Storage, string Brand, float In_price, float Out_price);
    ~Goods();
    void Showall();
    void Add();
    void Delete();
    void ReviseInfo();
    void SelectInprice();
    void select();
};
//主菜单
void menu();

