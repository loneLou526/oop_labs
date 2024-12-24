#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;  // Title of the book or record
    float price;   // Price

public:
    // Метод для ввода данных (название и цена)
    virtual void getdata() {
        cout << "Enter title: ";
        cin.ignore(); // Очистка буфера для корректного ввода строки
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
    }

    // Метод для вывода данных (название и цена)
    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << " rub." << endl;
    }
};

// Базовый класс Sales
class Sales {
protected:
    float sales[3]; // Массив для хранения продаж за последние три месяца

public:
    // Метод для ввода данных о продажах
    void getsales() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << (i + 1) << ": ";
            cin >> sales[i];
        }
    }

    // Метод для вывода данных о продажах
    void putsales() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Sales for month " << (i + 1) << ": " << sales[i] << " rub." << endl;
        }
    }
};

// Класс Book, наследуемый от Publication и Sales
class Book : public Publication, public Sales {
private:
    int pageCount;

public:
    // Переопределенный метод для ввода данных (включая страницы)
    void getdata() override {
        Publication::getdata(); // Вызов базового метода для ввода названия и цены
        Sales::getsales();      // Ввод данных о продажах

        cout << "Enter number of pages: ";
        cin >> pageCount;
    }

    // Переопределенный метод для вывода данных (включая страницы)
    void putdata() const override {
        Publication::putdata(); // Вызов базового метода для вывода названия и цены
        Sales::putsales();      // Вывод данных о продажах

        cout << "Number of pages: " << pageCount << endl;
    }
};

// Класс Type, наследуемый от Publication и Sales
class Type : public Publication, public Sales {
private:
    float recordTime;

public:
    // Переопределенный метод для ввода данных (включая время записи)
    void getdata() override {
        Publication::getdata(); // Вызов базового метода для ввода названия и цены
        Sales::getsales();      // Ввод данных о продажах

        cout << "Enter recording time (in minutes): ";
        cin >> recordTime;
    }

    // Переопределенный метод для вывода данных (включая время записи)
    void putdata() const override {
        Publication::putdata(); // Вызов базового метода для вывода названия и цены
        Sales::putsales();      // Вывод данных о продажах

        cout << "Recording time: " << recordTime << " minutes" << endl;
    }
};

int main() {
    // Создаем экземпляры книг и аудиозаписей
    Book myBook;
    Type myAudio;

    cout << "Enter data for the book:\n";
    myBook.getdata();  // Ввод данных для книги
    cout << "\nEnter data for the audio record:\n";
    myAudio.getdata(); // Ввод данных для аудиозаписи

    // Вывод введенных данных
    cout << "\nBook data:\n";
    myBook.putdata();

    cout << "\nAudio record data:\n";
    myAudio.putdata();

    return 0;
}
