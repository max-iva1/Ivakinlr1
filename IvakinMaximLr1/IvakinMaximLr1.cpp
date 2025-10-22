#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define INPUT_LINE(in, str) getline(in>>std::ws, str); \
      std::cerr << str << std::endl

#define PRINT_PARAM(out, x) out<< #x << "=" << x << std::endl


template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail() 
        || std::cin.peek() != '\n' 
        || x < min || x > max)  
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Type number (" << min << "-" << max << "):";
    }
    std::cerr << x << std::endl;
    return x;
}

class Pipes {
public:
    void add() {
        cout << "Введите название трубы: ";
        INPUT_LINE(cin, _name);
        cout << "Введите размеры трубы (длину): ";
        _length = GetCorrectNumber(0, 100000);
        cout << "Введите размеры трубы (ширину): ";
        _width = GetCorrectNumber(0, 100000);
        cout << "Введите работает ли труба(1 - работает, 0 - в ремонте): ";
        _properties = GetCorrectNumber(0, 1);
    }
    void View() {
        if (_name.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            cout << "Название: " << _name << ", длина: " << _length << " ширина: " << _width << " работает ли труба (1 - работает, 0 - в ремонте): " << _properties << endl;
        }
    }
    void Edit() {
        if (_name.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            cout << "Введите работает ли труба(1 - работает, 0 - в ремонте)" << endl;
            _properties = GetCorrectNumber(0, 1); 
        }
    }
    void output_file() {
        if (_name.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            ofstream out;
            out.open("data_pipes_ks.txt");
            if (out.is_open()) {
                out << "Название: " << _name << ", длина: " << _length << " ширина: " << _width << " работает ли труба (1 - работает, 0 - в ремонте): " << _properties << endl;
                out.close();
            }
        }
    }
    void input_file() {
        ifstream in;
        in.open("data_pipes_ks.txt");
        string line;
        if (in.is_open()) {
            while (getline(in, line)) {
                cout << line << " ";
            }
            cout << endl;
            in.close();
        }
    }
private:
    string _name;
    int _length;
    int _width;
    bool _properties;
};

class KS {
public:
    void add() {
        cout << "Введите название КС: ";
        INPUT_LINE(cin, _name);
        cout << "Введите количество цехов: ";
        _quantity = GetCorrectNumber(0, 100000);
        cout << "Введите количество цехов в работе: ";
        _count_work = GetCorrectNumber(0, _quantity); 
        cout << "Введите запуск КС(1 - запустить, 0 - остановка): ";
        _station_class = GetCorrectNumber(0, 1);
    }
    void View() {
        if (_name.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            cout << "Название: " << _name << ", количество цехов: " << _quantity << " количество цехов в работе: " << _count_work << " класс станции: " << _station_class << endl;
        }
    }
    void Edit() {
        if (_name.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            cout << "Введите запуск КС(1 - запустить, 0 - остановка)" << endl;
            _station_class = GetCorrectNumber(0, 1); 
        }
    }
    void output_file() {
        if (_name.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            ofstream out("data_pipes_ks.txt", ios::app);
            if (out.is_open()) {
                out << "Название: " << _name << ", количество цехов: " << _quantity << " количество цехов в работе: " << _count_work << " класс станции: " << _station_class << '\n';
                out.close();
            }
        }
    }
private:
    string _name;
    int _quantity;
    int _count_work;
    bool _station_class;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Pipes pipe_;
    KS KS_;
    while (true) {
        cout << "\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр\n4. Редактировать трубу\n"
            << "5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\nВыберете : ";
        switch (GetCorrectNumber(0, 7)) {
        case 0:
            cout << "Вы закончили цикл" << endl;
            exit(0);
        case 1:
            pipe_.add();
            break;
        case 2:
            KS_.add();
            break;
        case 3:
            pipe_.View();
            KS_.View();
            break;
        case 4:
            pipe_.Edit();
            break;
        case 5:
            KS_.Edit();
            break;
        case 6:
            pipe_.output_file();
            KS_.output_file();
            break;
        case 7:
            pipe_.input_file();
            break;
        }
    }
    return 0;
}