#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string a_title;       // 图书名称
    string a_isbn;        // ISBN
    string a_publisher;   // 出版社
    double a_price;       // 价格
    int a_pages;          // 页数
    bool a_isAvailable;   // 是否可借阅

public:
    Book();
    Book(string t, string i, string p, double pr, int pg, bool av);

    bool setIsbn(string i);     
    bool setPrice(double pr);     
    bool setPages(int pg);       

    string getTitle();
    string getIsbn();
    string getPublisher();
    double getPrice();
    int getPages();
    bool getAvailable();

    bool borrowBook();      
    bool returnBook();      
    void showInfo();         
    static bool isValidIsbn(string i);
};