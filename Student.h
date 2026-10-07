#pragma once
#include<iostream>
#include<string>
#include"book.h"
using namespace std;
class Student
{
    private:
        string id;
        string name;
        int maxBooks;
        int borrowedCount;
public:
    Student();
    Student(string i, string n, int max);
    bool borrowBook(Book &b);
    bool returnBook(Book &b);
    void showInfo();
};