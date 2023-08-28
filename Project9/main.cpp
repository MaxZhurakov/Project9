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
    cout << "Назва: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Видавництво: " << book.publisher << endl;
    cout << "Жанр: " << book.genre << endl;
    cout << endl;
}

void editBook(Book& book) 
{
    cout << "Введіть нову назву: ";
    getline(cin >> ws, book.title);
    cout << "Введіть нового автора: ";
    getline(cin >> ws, book.author);
    cout << "Введіть нове видавництво: ";
    getline(cin >> ws, book.publisher);
    cout << "Введіть новий жанр: ";
    getline(cin >> ws, book.genre);
}

void printAllBooks(const Book library[], int size)
{
    cout << "Книги в бібліотеці:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Книга " << i + 1 << ":" << endl;
        printBook(library[i]);
    }
}
void searchByAuthor(const Book library[], int size, const std::string& author) 
{
    cout << "Книги автора " << author << ":" << endl;
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
        cout << "Книги даного автора відсутні." << endl;
    }

}

void searchByTitle(const Book library[], int size, const string& title) 
{
    cout << "Книги з назвою \"" << title << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (library[i].title == title) {
            printBook(library[i]);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Книги з такою назвою відсутні." << endl;
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
    cout << "Видалено " << removedCount << " книг(и) за вказаним критерієм." << endl;
}
void addNewBook(Book library[], int& size) 
{
    if (size >= 10)
    {
       cout << "Бібліотека заповнена. Неможливо додати нову книгу." << endl;
        return;
    Book newBook;
    cout << "Введіть назву нової книги: ";
    getline(cin >> ws, newBook.title);
    cout << "Введіть автора нової книги: ";
    getline(cin >> ws, newBook.author);
    cout << "Введіть видавництво нової книги: ";
    getline(cin >> ws, newBook.publisher);
    cout << "Введіть жанр нової книги: ";
    getline(cin >> ws, newBook.genre);
    library[size] = newBook;
    size++;
    cout << "Нова книга успішно додана до бібліотеки." << endl;
}
int main() 
{
    Book library[10];
    int size = 0;
    // Додавання початкових книг до бібліотеки (для прикладу)
    Book book1 = { "Книга 1", "Автор 1", "Видавництво 1", "Жанр 1" };
    Book book2 = { "Книга 2", "Автор 2", "Видавництво 2", "Жанр 2" };
    library[size++] = book1;
    library[size++] = book2;
    // Взаємодія з бібліотекою
    addNewBook(library, size);
    editBook(library[0]);
    printAllBooks(library, size);
    searchByAuthor(library, size, "Автор 1");
    searchByTitle(library, size, "Книга 2");
    sortBooksByTitle(library, size);
    sortBooksByAuthor(library, size);
    sortBooksByPublisher(library, size);
    removeBookByCriteria(library, size, "Жанр 2");
    printAllBooks(library, size);
    return 0;
}