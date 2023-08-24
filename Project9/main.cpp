//HM_ex_1_24.03.2023_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// Клас, що представляє співробітника
class Employee {
public:
    string surname;
    string name;
    int age;
    Employee(const string& surname, const string& name, int age)
        : surname(surname), name(name), age(age) {}
};
// Клас, що представляє базу даних співробітників
class EmployeeDatabase 
{
private:
    vector<Employee> employees;
    string filename;
public:
    EmployeeDatabase(const string& filename)
        : filename(filename) {}
    // Додавання співробітника до бази даних
    void addEmployee(const Employee& employee) 
    {
        employees.push_back(employee);
    }
    // Видалення співробітника з бази даних за прізвищем
    void removeEmployee(const string& surname) 
    {
        employees.erase(remove_if(employees.begin(), employees.end(),
            [&](const Employee& employee) { return employee.surname == surname; }), employees.end());
    }
    // Пошук співробітників за прізвищем
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
    // Пошук співробітників за віком
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
    // Пошук співробітників за першою літерою прізвища
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
    // Завантаження списку співробітників з файлу
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
    // Збереження списку співробітників у файл
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
    // Завантаження списку співробітників з файлу
    database.loadFromFile();
    int choice;
    do {
        cout << "=== ІНФОРМАЦІЙНА СИСТЕМА \"СПІВРОБІТНИКИ\" ===" << endl;
        cout << "1. Додати співробітника" << endl;
        cout << "2. Видалити співробітника" << endl;
        cout << "3. Пошук за прізвищем" << endl;
        cout << "4. Пошук за віком" << endl;
        cout << "5. Пошук за першою літерою прізвища" << endl;
        cout << "6. Зберегти список співробітників у файл" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice)
        {
        case 1: 
        {
            string surname, name;
            int ag
            cout << "Введіть прізвище: ";
            cin >> surname;
            cout << "Введіть ім'я: ";
            cin >> name;
            cout << "Введіть вік: ";
            cin >> age;
            database.addEmployee(Employee(surname, name, age));
            cout << "Співробітник успішно доданий!" << endl;
            break;
        }
        case 2:
        {
            string surname;
            cout << "Введіть прізвище співробітника, якого бажаєте видалити: ";
            cin >> surname;
            database.removeEmployee(surname);
            cout << "Співробітник успішно видалений!" << endl;
            break;
        }
        case 3: 
        {
            string surname;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            vector<Employee> result = database.searchBySurname(surname);
            if (result.empty()) {
                cout << "Співробітників з таким прізвищем не знайдено." << endl;
            }
            else
            {
                cout << "Результати пошуку:" << endl;
                for (const Employee& employee : result) {
                    cout << "Прізвище: " << employee.surname << ", Ім'я: " << employee.name << ", Вік: " << employee.age << endl;
                }
            }
            break;
        }
        case 4:
        {
            int age;
            cout << "Введіть вік для пошуку: ";
            cin >> age;
            vector<Employee> result = database.searchByAge(age);
            if (result.empty()) 
            {
                cout << "Співробітників з таким віком не знайдено." << endl;
            }
            else 
            {
                cout << "Результати пошуку:" << endl;
                for (const Employee& employee : result) 
                {
                    cout << "Прізвище: " << employee.surname << ", Ім'я: " << employee.name << ", Вік: " << employee.age << endl;
                }
            }
            break;
        }
        case 5: 
        {
            char letter;
            cout << "Введіть літеру для пошуку: ";
            cin >> letter;
            vector<Employee> result = database.searchByFirstLetter(letter);
            if (result.empty()) 
            {
                cout << "Співробітників з прізвищами, що починаються на задану літеру, не знайдено." << endl;
            }
            else 
            {
                cout << "Результати пошуку:" << endl;
                for (const Employee& employee : result)
                {
                    cout << "Прізвище: " << employee.surname << ", Ім'я: " << employee.name << ", Вік: " << employee.age << endl;
                }
            }
            break;
        }
        case 6: 
        {
            database.saveToFile();
            cout << "Список співробітників успішно збережений у файл!" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}
