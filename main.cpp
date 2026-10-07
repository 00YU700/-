#include "book.h"
#include "Student.h"
#include <cstdlib>

int main()
{
    // 创建两本书
    Book b1("C++ Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true);
    Book b2("Data Structures", "9780133401892", "Pearson", 89.0, 720, true);

    // 创建一个学生，最多借 2 本
    Student s("2024001", "张三", 2);

    cout << "=== 初始状态 ===" << endl;
    s.showInfo();
    b1.showInfo();
    b2.showInfo();

    cout << "\n=== 学生借书 ===" << endl;
    s.borrowBook(b1);   // 借第一本
    s.borrowBook(b2);   // 借第二本

    cout << "\n=== 借书后 ===" << endl;
    s.showInfo();
    b1.showInfo();
    b2.showInfo();

    cout << "\n=== 再借一本（应该失败）===" << endl;
    Book b3("Effective C++", "9780321334879", "Addison-Wesley", 99.0, 320, true);
    s.borrowBook(b3);   // 已到最大数量，失败

    cout << "\n=== 还书 ===" << endl;
    s.returnBook(b1);   // 还第一本

    cout << "\n=== 还书后 ===" << endl;
    s.showInfo();
    b1.showInfo();

    system("pause");
    return 0;
}