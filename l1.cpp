#include <iostream>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

void setupRussianConsole()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

class Student
{
private:
    string name;
    int age;
    int grades[5];

public:
    // Конструктор по умолчанию
    Student()
    {
        name = "";
        age = 0;
        for (int i = 0; i < 5; i++)
        {
            grades[i] = 0;
        }
    }

    // Конструктор с параметрами
    Student(string studentName, int studentAge, int studentGrades[5])
    {
        name = studentName;
        age = studentAge;
        for (int i = 0; i < 5; i++)
        {
            grades[i] = studentGrades[i];
        }
    }

    // Конструктор копирования
    Student(const Student &other)
    {
        name = other.name;
        age = other.age;
        for (int i = 0; i < 5; i++)
        {
            grades[i] = other.grades[i];
        }
    }

    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            name = other.name;
            age = other.age;
            for (int i = 0; i < 5; i++)
            {
                grades[i] = other.grades[i];
            }
        }
        return *this;
    }

    Student operator+(const Student &other)
    {
        Student result;
        result.name = this->name + " & " + other.name;
        result.age = this->age;

        for (int i = 0; i < 5; i++)
        {
            result.grades[i] = this->grades[i] + other.grades[i];
        }

        return result;
    }

    Student &operator++()
    {
        for (int i = 0; i < 5; i++)
        {
            grades[i]++;
        }
        return *this;
    }

    void TO_SHOW()
    {
        cout << "Student info:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grades: ";
        for (int i = 0; i < 5; i++)
        {
            cout << grades[i];
            if (i < 4)
                cout << ", ";
        }
        cout << endl;
    }

    string TO_GET_name()
    {
        return name;
    }

    int TO_GET_age()
    {
        return age;
    }

    int *TO_GET_grades()
    {
        return grades;
    }

    int TO_GET_grade_at_index(int index)
    {
        if (index >= 0 && index < 5)
            return grades[index];
        return -1;
    }

    void TO_SET_name(string newName)
    {
        name = newName;
    }

    void TO_SET_age(int newAge)
    {
        age = newAge;
    }

    void TO_SET_grades(int newGrades[5])
    {
        for (int i = 0; i < 5; i++)
        {
            grades[i] = newGrades[i];
        }
    }

    void TO_SET_grade_at_index(int index, int value)
    {
        if (index >= 0 && index < 5)
            grades[index] = value;
    }
};

int main()
{
    setupRussianConsole();

    cout << "Creating objects:" << endl;

    Student obj1;
    cout << "Obj1:" << endl;
    obj1.TO_SHOW();

    obj1.TO_SET_name("Alice");
    obj1.TO_SET_age(20);
    int grades1[5] = {85, 90, 78, 92, 88};
    obj1.TO_SET_grades(grades1);

    int paramGrades[5] = {75, 80, 85, 90, 95};
    Student obj2("Bob", 21, paramGrades);
    cout << "\nObj2:" << endl;
    obj2.TO_SHOW();

    Student obj3(obj2);
    cout << "\nObj3:" << endl;
    obj3.TO_SHOW();

    cout << "\nMethods demo:" << endl;

    cout << "Values from obj1:" << endl;
    cout << "Name: " << obj1.TO_GET_name() << endl;
    cout << "Age: " << obj1.TO_GET_age() << endl;
    cout << "Grade at index 0: " << obj1.TO_GET_grade_at_index(0) << endl;

    obj3.TO_SET_name("Charlie");
    obj3.TO_SET_age(22);
    cout << "\nAfter setting new values for obj3:" << endl;
    obj3.TO_SHOW();

    cout << "\nAll objects after changes:" << endl;
    cout << "\nObj1:" << endl;
    obj1.TO_SHOW();
    cout << "\nObj2:" << endl;
    obj2.TO_SHOW();
    cout << "\nObj3:" << endl;
    obj3.TO_SHOW();

    cout << "\nOperator overloading demo:" << endl;

    cout << "Assignment (obj1 = obj2):" << endl;
    obj1 = obj2;
    cout << "After assignment, obj1:" << endl;
    obj1.TO_SHOW();

    cout << "\nBinary operation (obj1 + obj2):" << endl;
    Student objSum = obj1 + obj2;
    objSum.TO_SHOW();

    cout << "\nUnary operation (++obj1):" << endl;
    ++obj1;
    cout << "After increment:" << endl;
    obj1.TO_SHOW();

    return 0;
}