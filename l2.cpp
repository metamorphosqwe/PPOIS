#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int age;
    int grades[5];

public:
    Student(string name, int age, int grade[5])
    {
        this->name = name;
        this->age = age;
        for (int i = 0; i < 5; i++)
        {
            this->grades[i] = grades[i];
        }
    }
    string to_GET_name()
    {
        return name;
    }
    string to_GET_name(string prefix)
    {
        return prefix + " " + name;
    }

    int to_GET_age()
    {
        return age;
    }
    string to_GET_age(bool ageBriefly)
    {
        if (ageBriefly)
        {
            return to_string(age);
        }
        else
        {
            return "I am " + to_string(age) + " years old.";
        }
    }
    int to_GET_grade_at_index_and_add_points(int index, int amount)
    {
        if (index >= 0 && index < sizeof(grades) / sizeof(grades[0]))
        {
            return grades[index] + amount;
        }
    }
    string to_GET_grade_at_index_like_string(int index, string type)
    {
        if (type == "string")
        {
            if (grades[index] >= 90)
            {
                return "A";
            }
            else if (grades[index] >= 80)
            {
                return "B";
            }
            else if (grades[index] >= 70)
            {
                return "C";
            }
            else if (grades[index] >= 60)
            {
                return "D";
            }
            else
            {
                return "F";
            }
        }
    }
};