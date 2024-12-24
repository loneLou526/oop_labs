#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

// Базовый класс
class Base {
public:
    virtual void showBehavior() const {
        std::cout << "Behavior of Base class" << std::endl;
    }

    virtual ~Base() {
        std::cout << "Destructor of Base" << std::endl;
    }
};

// Производный класс
class Derived : public Base {
public:
    void showBehavior() const override {
        std::cout << "Behavior of Derived class" << std::endl;
    }

    ~Derived() override {
        std::cout << "Destructor of Derived" << std::endl;
    }
};

// Функция добавления объектов в хранилище
void add(std::vector<std::shared_ptr<Base>>& storage, std::shared_ptr<Base> obj) {
    storage.push_back(obj);
}

int main() {
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(0)));

    // Хранилище для объектов
    std::vector<std::shared_ptr<Base>> storage;

    // Создание объектов случайным образом
    for (int i = 0; i < 10; ++i) {
        int randomValue = std::rand();
        if (randomValue % 2 == 0) {
            std::shared_ptr<Base> obj = std::make_shared<Base>();
            add(storage, obj);
        } else {
            std::shared_ptr<Base> obj = std::make_shared<Derived>();
            add(storage, obj);
        }
    }

    // Демонстрация поведения объектов из хранилища
    for (const auto& obj : storage) {
        obj->showBehavior();
    }

    // Хранилище автоматически освободит память благодаря shared_ptr
    return 0;
}
