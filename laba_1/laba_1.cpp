#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Enter len list: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " integer numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "List content: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Address of the beginning of the array: " << arr << endl;

    cout << "The distance of elements from the beginning of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i << " located at the address " << (arr + i)
             << ", distance: " << (arr + i) - arr << " elements" << endl;
    }

    delete[] arr;

    return 0;
}

*/
// Класс для представления книги
class Book {
private:
    string author;
    string title;
    bool isFiction; // true - художественная, false - техническая

public:
    // Конструктор
    Book(const string& author, const string& title, bool isFiction)
            : author(author), title(title), isFiction(isFiction) {}

    // Получение типа книги
    bool getIsFiction() const {
        return isFiction;
    }

    // Вывод информации о книге
    void printInfo() const {
        cout << "Author: " << author << ", Label: " << title
             << ", Type: " << (isFiction ? "Fiction" : "Technical") << endl;
    }
};

// Класс для представления библиотеки
class Library {
private:
    vector<Book*> books; // Вектор указателей на книги для динамического управления

public:
    // Добавление книги в библиотеку
    void addBook(const string& author, const string& title, bool isFiction) {
        books.push_back(new Book(author, title, isFiction));
    }

    // Вывод количества книг каждого типа с использованием оператора switch
    void countBooksUsingSwitch() const {
        int fictionCount = 0, technicalCount = 0;

        for (const auto& book : books) {
            switch (book->getIsFiction()) {
                case true:
                    fictionCount++;
                    break;
                case false:
                    technicalCount++;
                    break;
            }
        }

        cout << "Number of fiction books: " << fictionCount << endl;
        cout << "Number of technical books: " << technicalCount << endl;
    }

    // Вывод количества книг каждого типа без оператора switch
    void countBooksWithoutSwitch() const {
        int fictionCount = 0, technicalCount = 0;

        for (const auto& book : books) {
            if (book->getIsFiction()) {
                fictionCount++;
            } else {
                technicalCount++;
            }
        }

        cout << "Number of fiction books: " << fictionCount << endl;
        cout << "Number of technical books: " << technicalCount << endl;
    }

    // Освобождение памяти
    ~Library() {
        for (auto& book : books) {
            delete book;
        }
        books.clear();
    }
};

int main() {
    Library library;

    // Наполнение библиотеки книгами
    library.addBook("Me", "My life", true);
    library.addBook("Lev Tolstoy", "War and peace", true);
    library.addBook("Donald Knuth", "The art of programming", false);
    library.addBook("Bjorn Stroustrup", "The C++ programming language", false);

    // Вывод количества книг с использованием switch
    cout << "With switch:" << endl;
    library.countBooksUsingSwitch();

    // Вывод количества книг без использования switch
    cout << "\nWithout switch:" << endl;
    library.countBooksWithoutSwitch();

    return 0;
}

