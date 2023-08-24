//HM_ex_1_24.03.2023_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// ����, �� ����������� �����������
class Employee {
public:
    string surname;
    string name;
    int age;
    Employee(const string& surname, const string& name, int age)
        : surname(surname), name(name), age(age) {}
};
// ����, �� ����������� ���� ����� �����������
class EmployeeDatabase 
{
private:
    vector<Employee> employees;
    string filename;
public:
    EmployeeDatabase(const string& filename)
        : filename(filename) {}
    // ��������� ����������� �� ���� �����
    void addEmployee(const Employee& employee) 
    {
        employees.push_back(employee);
    }
    // ��������� ����������� � ���� ����� �� ��������
    void removeEmployee(const string& surname) 
    {
        employees.erase(remove_if(employees.begin(), employees.end(),
            [&](const Employee& employee) { return employee.surname == surname; }), employees.end());
    }
    // ����� ����������� �� ��������
    vector<Employee> searchBySurname(const string& surname) const 
    {
        vector<Employee> result;
        for (const Employee& employee : employees) 
        {
            if (employee.surname == surname) 
            {
                result.push_back(employee);
            }
        }
        return result;
    }
    // ����� ����������� �� ����
    vector<Employee> searchByAge(int age) const 
    {
        vector<Employee> result;
        for (const Employee& employee : employees) 
        {
            if (employee.age == age) {
                result.push_back(employee);
            }
        }
        return result;
    }
    // ����� ����������� �� ������ ������ �������
    vector<Employee> searchByFirstLetter(char letter) const 
    {
        vector<Employee> result;
        for (const Employee& employee : employees) 
        {
            if (employee.surname[0] == letter) 
            {
                result.push_back(employee);
            }
        }
        return result;
    }
    // ������������ ������ ����������� � �����
    void loadFromFile() 
    {
        ifstream file(filename);
        if (file.is_open()) 
        {
            employees.clear();
            string surname, name;
            int age;
            while (file >> surname >> name >> age) 
            {
                employees.emplace_back(surname, name, age);
            }
            file.close();
        }
    }
    // ���������� ������ ����������� � ����
    void saveToFile() const 
    {
        ofstream file(filename);
        if (file.is_open()) 
        {
            for (const Employee& employee : employees)
            {
                file << employee.surname << " " << employee.name << " " << employee.age << endl;
            }
            file.close();
        }
    }
};
int main() 
{
    string filename = "employees.txt";
    EmployeeDatabase database(filename);
    // ������������ ������ ����������� � �����
    database.loadFromFile();
    int choice;
    do {
        cout << "=== �������ֲ��� ������� \"�ϲ����������\" ===" << endl;
        cout << "1. ������ �����������" << endl;
        cout << "2. �������� �����������" << endl;
        cout << "3. ����� �� ��������" << endl;
        cout << "4. ����� �� ����" << endl;
        cout << "5. ����� �� ������ ������ �������" << endl;
        cout << "6. �������� ������ ����������� � ����" << endl;
        cout << "0. �����" << endl;
        cout << "��� ����: ";
        cin >> choice;
        switch (choice)
        {
        case 1: 
        {
            string surname, name;
            int ag
            cout << "������ �������: ";
            cin >> surname;
            cout << "������ ��'�: ";
            cin >> name;
            cout << "������ ��: ";
            cin >> age;
            database.addEmployee(Employee(surname, name, age));
            cout << "���������� ������ �������!" << endl;
            break;
        }
        case 2:
        {
            string surname;
            cout << "������ ������� �����������, ����� ������ ��������: ";
            cin >> surname;
            database.removeEmployee(surname);
            cout << "���������� ������ ���������!" << endl;
            break;
        }
        case 3: 
        {
            string surname;
            cout << "������ ������� ��� ������: ";
            cin >> surname;
            vector<Employee> result = database.searchBySurname(surname);
            if (result.empty()) {
                cout << "����������� � ����� �������� �� ��������." << endl;
            }
            else
            {
                cout << "���������� ������:" << endl;
                for (const Employee& employee : result) {
                    cout << "�������: " << employee.surname << ", ��'�: " << employee.name << ", ³�: " << employee.age << endl;
                }
            }
            break;
        }
        case 4:
        {
            int age;
            cout << "������ �� ��� ������: ";
            cin >> age;
            vector<Employee> result = database.searchByAge(age);
            if (result.empty()) 
            {
                cout << "����������� � ����� ���� �� ��������." << endl;
            }
            else 
            {
                cout << "���������� ������:" << endl;
                for (const Employee& employee : result) 
                {
                    cout << "�������: " << employee.surname << ", ��'�: " << employee.name << ", ³�: " << employee.age << endl;
                }
            }
            break;
        }
        case 5: 
        {
            char letter;
            cout << "������ ����� ��� ������: ";
            cin >> letter;
            vector<Employee> result = database.searchByFirstLetter(letter);
            if (result.empty()) 
            {
                cout << "����������� � ���������, �� ����������� �� ������ �����, �� ��������." << endl;
            }
            else 
            {
                cout << "���������� ������:" << endl;
                for (const Employee& employee : result)
                {
                    cout << "�������: " << employee.surname << ", ��'�: " << employee.name << ", ³�: " << employee.age << endl;
                }
            }
            break;
        }
        case 6: 
        {
            database.saveToFile();
            cout << "������ ����������� ������ ���������� � ����!" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}
