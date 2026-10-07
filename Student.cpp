#include"Student.h"
Student ::Student()
{
    id = "";
    name = "";
    maxBooks = 3;
    borrowedCount = 0;
}
Student ::Student(string i, string n,int max)
{
    id = i;
    name = n;
    if(max > 0)
        maxBooks = max;
    else
        maxBooks = 3;
    borrowedCount = 0;
}
bool Student::borrowBook(Book& b)//借书
{
    if(borrowedCount>=maxBooks)
    {
        cout<<"借书失败：已达到最大借书数量"<<endl;
        return false;
    }
    if(!b.getAvailable())
    {
        cout<<"借书失败：该书已被借出"<<endl;
        return false;
    }
    if(b.borrowBook())
    {
        borrowedCount++;
        cout<<"借书成功："<<name<<"借阅了《"<<b.getTitle()<<"》"<<endl;
        return true;
    }
    return false;
}
bool Student::returnBook(Book& b)//还书
{
    if(b.returnBook())
    {
        borrowedCount--;
        cout<<"还书成功："<<b.getTitle()<<endl;
        return true;
    }
    cout<<"还书失败"<<endl;
    return false;
}
void Student::showInfo()
{
    cout << "学号：" << id << endl;
    cout << "姓名：" << name << endl;
    cout << "最多可借：" << maxBooks << endl;
    cout << "当前已借：" << borrowedCount << endl;
}