#include <iostream>

using namespace std;
struct Student
{
    char *name;
    int age;
    char *sex;
    Student(char *name,int age,char *sex)
    :name(name),age(age),sex(sex){}
    void print_info()
    {
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"sex: "<<sex<<endl;
    }
};
int main()
{
    Student stu = Student("张三",18,"男");
    stu.print_info();
    return 0;
}
