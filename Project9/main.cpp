//HM_ex_1_7.05.2023
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Book 
{
    string title;
    string author;
    string publisher;
    string genre;
};

void printBook(const Book& book) 
{
    cout << "�����: " << book.title << endl;
    cout << "�����: " << book.author << endl;
    cout << "�����������: " << book.publisher << endl;
    cout << "����: " << book.genre << endl;
    cout << endl;
}

void editBook(Book& book) 
{
    cout << "������ ���� �����: ";
    getline(cin >> ws, book.title);
    cout << "������ ������ ������: ";
    getline(cin >> ws, book.author);
    cout << "������ ���� �����������: ";
    getline(cin >> ws, book.publisher);
    cout << "������ ����� ����: ";
    getline(cin >> ws, book.genre);
}

void printAllBooks(const Book library[], int size)
{
    cout << "����� � ��������:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "����� " << i + 1 << ":" << endl;
        printBook(library[i]);
    }
}
void searchByAuthor(const Book library[], int size, const std::string& author) 
{
    cout << "����� ������ " << author << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) 
    {
        if (library[i].author == author) 
        {
            printBook(library[i]);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "����� ������ ������ ������." << endl;
    }

}

void searchByTitle(const Book library[], int size, const string& title) 
{
    cout << "����� � ������ \"" << title << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (library[i].title == title) {
            printBook(library[i]);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "����� � ����� ������ ������." << endl;
    }
}
bool compareByTitle(const Book& book1, const Book& book2)
{
    return book1.title < book2.title;
}
bool compareByAuthor(const Book& book1, const Book& book2) 
{
    return book1.author < book2.author;
}
bool compareByPublisher(const Book& book1, const Book& book2) 
{
    return book1.publisher < book2.publisher;
}
void sortBooksByTitle(Book library[], int size) 
{
    sort(library, library + size, compareByTitle);
}

void sortBooksByAuthor(Book library[], int size)
{
    sort(library, library + size, compareByAuthor);
}
void sortBooksByPublisher(Book library[], int size) 
{
    sort(library, library + size, compareByPublisher);
}
void removeBookByCriteria(Book library[], int& size, const std::string& criteria)
{
    int removedCount = 0;
    for (int i = 0; i < size; i++) 
    {
        if (library[i].title == criteria || library[i].author == criteria ||
            library[i].publisher == criteria || library[i].genre == criteria) {
            removedCount++;
        }
        else 
        {
            library[i - removedCount] = library[i];
        }
    }
    size -= removedCount;
    cout << "�������� " << removedCount << " ����(�) �� �������� �������." << endl;
}
void addNewBook(Book library[], int& size) 
{
    if (size >= 10)
    {
       cout << "��������� ���������. ��������� ������ ���� �����." << endl;
        return;
    Book newBook;
    cout << "������ ����� ���� �����: ";
    getline(cin >> ws, newBook.title);
    cout << "������ ������ ���� �����: ";
    getline(cin >> ws, newBook.author);
    cout << "������ ����������� ���� �����: ";
    getline(cin >> ws, newBook.publisher);
    cout << "������ ���� ���� �����: ";
    getline(cin >> ws, newBook.genre);
    library[size] = newBook;
    size++;
    cout << "���� ����� ������ ������ �� ��������." << endl;
}
int main() 
{
    Book library[10];
    int size = 0;
    // ��������� ���������� ���� �� �������� (��� ��������)
    Book book1 = { "����� 1", "����� 1", "����������� 1", "���� 1" };
    Book book2 = { "����� 2", "����� 2", "����������� 2", "���� 2" };
    library[size++] = book1;
    library[size++] = book2;
    // ������� � ���������
    addNewBook(library, size);
    editBook(library[0]);
    printAllBooks(library, size);
    searchByAuthor(library, size, "����� 1");
    searchByTitle(library, size, "����� 2");
    sortBooksByTitle(library, size);
    sortBooksByAuthor(library, size);
    sortBooksByPublisher(library, size);
    removeBookByCriteria(library, size, "���� 2");
    printAllBooks(library, size);
    return 0;
}