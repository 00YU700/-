#include "book.h"
#include <iomanip>
#include<cctype>

Book::Book()
{
    a_title = "";
    a_isbn = "";
    a_publisher = "";
    a_price = 0.0;
    a_pages = 0;
    a_isAvailable = true;
}
Book::Book(string t, string i, string p, double pr, int pg, bool av)
{
    a_title = t;
    a_publisher = p;
    a_isAvailable = av;
    a_pages = pg;
    a_price = pr;
    if (isValidIsbn(i))
        a_isbn = i;
    else
        a_isbn = "";
}

bool Book::setIsbn(string i)//改ISBN，带验证
{
    if(isValidIsbn(i))
    {
        a_isbn = i;
        return true;
    }
    else
        return false;
}
bool Book::setPrice(double pr)//改价格，带验证
{
    if (pr >= 0)
    {
        a_price = pr;
        return true;
    }
    else
        return false;
}
bool Book::setPages(int pg)//改页数，带验证
{
    if (pg > 0)
    {
        a_pages = pg;
        return true;
    }
    else
        return false;
}
string Book::getTitle(){return a_title;}
string Book::getIsbn(){return a_isbn;}
string Book::getPublisher(){return a_publisher;}
double Book::getPrice(){return a_price;}
int Book::getPages(){return a_pages;}
bool Book::getAvailable(){return a_isAvailable;}

bool Book::borrowBook()//借书
{
    if (a_isAvailable)
    {
        a_isAvailable = false;
        return true;
    }
    else
        return false;
}
bool Book::returnBook()//还书
{
    if (!a_isAvailable)
    {
        a_isAvailable = true;
        return true;
    }
    else
        return false;
}
void Book::showInfo()//输出
{
    cout << "书名：" << a_title << endl;
    cout << "ISBN：" << a_isbn << endl;
    cout << "出版社：" << a_publisher << endl;
    cout << "价格：" << fixed << setprecision(2) << a_price << endl;
    cout << "页数：" << a_pages << endl;
    cout << "是否可借阅：" << (a_isAvailable ? "是" : "否") << endl;
}
bool Book::isValidIsbn(string i)//验证ISBN
{
    if (i.length() != 13)
        return false;
    for (char c : i)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}