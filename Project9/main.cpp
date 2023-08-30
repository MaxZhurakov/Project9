//HM_ex_1_14.05.2023
#include <iostream>
#include <string> 
using namespace std;

struct Surname
{
    string name;
    string lastName;
};

struct Group
{
    string group;
};

struct Marks
{
    string marks;
};

struct Student
{
    string surname;
    string group;
    int marks[5];
};

void print_honor_Students(Student* arr, int size) 
{
    cout << "List of honors students (>70% exccellent marks):\n";
    for (int i = 0; i < size; i++) 
    {
        int count = 0;
        for (int j = 0; j < 5; j++) 
        {
            if (arr[i].marks[j] >= 90) 
            {
                count++;
            }
        }
        if (count >= 4) {
            cout << arr[i].surname << "(" << arr[i].group << ")\n";
        }
    }
}

void print_poor_Students(Student* arr, int size) 
{
    cout << "List of poor students (>50% marks 2 and 3):\n";
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) 
        {
            if (arr[i].marks[j] <= 60) 
            {
                count++;
            }
        }
        if (count >= 3) 
        {
            cout << arr[i].surname << "(" << arr[i].group << ")\n";
        }
    }
}

int main() {
    int size = 3;
    Student* arr = new Student[size];
    arr[0] = { "Zhurakovsyi","Group1",{80,95,85,90,80} };
    arr[1] = { "Stasenko","Group2",{75,85,70,90,95} };
    arr[2] = { "Vanat","Group3",{100,90,95,80,75} };
    print_honor_Students(arr, size);
    print_poor_Students(arr, size);
    size = 4;
    Student* new_arr = new Student[size];
    for (int i = 0; i < size - 1; i++) 
    {
        new_arr[i] = arr[i];
    }
    new_arr[size - 1] = { "Vivcharenko","Group4",{70,60,80,75,55} };
    delete[]arr;
    arr = new_arr;
    print_honor_Students(arr, size);
    print_poor_Students(arr, size);
    delete[]arr;
    return 0;
}
//HM_ex_2_14.05.2023
#include <iostream> 
#include <string> 
#include <algorithm> 

using namespace std;

struct Surname
{
    string surnamename;
};

struct name
{
    string name;
};

struct age
{
    string age;
};

struct birthdate
{
    string birthdate;
};

struct Man {
    string surname;
    string name;
    int age;
    string birthdate;
};

int main() {
    Man people[11] = 
    {
        {"Zinchenko", "Oleksandr", 28, "1995-02-15"},
        {"Yarmolenko", "Andriy", 30, "1993-05-22"},
        {"Mudryk", "Michailo", 23, "2000-08-03"},
        {"Симоненко", "Ivan", 45, "1978-03-26"},
        {"Protsenko", "Bogdan", 34, "1989-11-05"},
        {"Zhurakovskyi", "Maksim", 26, "1 997-01-27"},
        {"Mudryk", "Michailo", 23, "2000-08-03"},
        {"Buschcan", "Georgiy", 24, "1999-04-30"},
        {"Yaremchuk", "Roman", 32, "1991-07-13"},
        {"Mykolenko", "Vitaliy", 33, "1989-12-23"},
        {"Malinovskiy", "Ruslan", 31, "1992-06-16"},
    };

    sort(people, people + 11, [](Man a, Man b) {
        return a.surname < b.surname || (a.surname == b.surname && a.name < b.name);
        });

    cout << "Sorted by surname or name:" << endl;
    for (int i = 0; i < 11; i++) 
    {
        cout << people[i].surname << " " << people[i].name << ", "
            << people[i].age << " years old, "
            << "birthdate: " << people[i].birthdate << endl;
    }

    string search_surname, search_name;
    cout << "Enter surname and name to search: ";
    cin >> search_surname >> search_name;

    bool found = false;
    for (int i = 0; i < 11; i++) 
    {
        if (people[i].surname == search_surname && people[i].name == search_name) 
        {
            cout << "Found: " << people[i].surname << " " << people[i].name << ", "
                << people[i].age << " years old, "
                << "birthdate: " << people[i].birthdate << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Person not found" << endl;
    }

    return 0;
}