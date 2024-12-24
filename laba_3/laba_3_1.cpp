#include <iostream>
#include <vector>
#include <memory> // Для std::shared_ptr

// Базовый класс "Деталь"
class Detail {
protected:
    Detail(const std::string& name) : name_(name) {}

public:
    virtual ~Detail() = default;

    // Виртуальный метод для отображения информации о детали
    virtual void display() const {
        std::cout << "Detail: " << name_ << std::endl;
    }

    // Фабричный метод для создания объекта
    static std::shared_ptr<Detail> create(const std::string& name) {
        return std::shared_ptr<Detail>(new Detail(name));
    }

protected:
    std::string name_;
};

// Производный класс "Сборка"
class Assembly : public Detail {
protected:
    // Конструктор доступен только друзьям
    Assembly(const std::string& name, int components)
            : Detail(name), components_(components) {}

public:
    void display() const override {
        std::cout << "Assembling: " << name_ << ", number of components: " << components_ << std::endl;
    }

    static std::shared_ptr<Assembly> create(const std::string& name, int components) {
        return std::shared_ptr<Assembly>(new Assembly(name, components));
    }

private:
    int components_;
};

// Функция для добавления деталей в хранилище
void addToStorage(std::vector<std::shared_ptr<Detail>>& storage, const std::shared_ptr<Detail>& detail) {
    storage.push_back(detail);
}

int main() {
    std::vector<std::shared_ptr<Detail>> storage;

    // Создание деталей и сборок через фабричные методы
    auto detail1 = Detail::create("Gear wheel");
    auto assembly1 = Assembly::create("Reducer", 5);
    auto assembly2 = Assembly::create("Corpus", 3);

    // Добавление в хранилище
    addToStorage(storage, detail1);
    addToStorage(storage, assembly1);
    addToStorage(storage, assembly2);

    // Отображение информации о содержимом хранилища
    for (const auto& item : storage) {
        item->display();
    }
    return 0;
}
