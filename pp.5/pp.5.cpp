#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Car {
protected:
    string brand;
    string model;
public:
    Car(string brand, string model) {
        this->brand = brand;
        this->model = model;
    }

    void Start() {
        cout << brand << " " << model << " запускает двигатель." << endl;
    }

    void Accelerate() {
        cout << brand << " " << model << " ускоряется." << endl;
    }

    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    void displayInfo() const {
        cout << "Машина: " << brand << " " << model << endl;
    }
};

class Garage {
protected:
    string name;
public:
    Garage(string name) {
        this->name = name;
    }

    void OpenGarage() {
        cout << "Открытие гаража под названием " << name << endl;
    }

    void CloseGarage() {
        cout << "Закрытие гаража под названием " << name << endl;
    }
};

class Mechanic {
protected:
    string name;
public:
    Mechanic(string name) {
        this->name = name;
    }

    void FixCar() {
        cout << name << " чинит машину." << endl;
    }

    void ServiceCar() {
        cout << name << " занимается обслуживанием автомобиля." << endl;
    }
};

class Workshop : public Car, public Garage {
public:
    Workshop(string carBrand, string carModel, string garageName) : Car(carBrand, carModel), Garage(garageName) {}

    void VisitWorkshop() {
        cout << "Посещение мастерской по адресу " << name << endl;
        OpenGarage();
    }

    void CarAction() {
        cout << "Этот " << brand << " " << model << " становится предметом обслуживания. " << endl;
    }
};

int main() {
    srand(time(0));

    setlocale(LC_ALL, "Russian");

    int action;
    string carBrand;
    string mechanicName;
    bool carCreated = false;
    Car car("", "");
    Mechanic mechanic("");

    Workshop workshop("", "", "");

    do {
        cout << "Выберите действие: \n1. Создайте автомобиль \n2. Посетите мастерскую\n3. Выйти\n\n";
        cin >> action;

        switch (action) {
        case 1: {
            cout << "Укажите марку автомобиля: ";
            cin >> carBrand;
            car = Car(carBrand, "Внедорожник");
            carCreated = true;
            break;
        }
        case 2: {
            if (carCreated) {
                mechanic = Mechanic("Джон"); // Assign a mechanic
                workshop = Workshop(car.getBrand(), car.getModel(), "Мастерская быстрого ремонта"); // Initialize the workshop

                workshop.VisitWorkshop();
                workshop.CarAction();

                // Additional actions
                mechanic.FixCar();
                mechanic.ServiceCar();
            }
            else {
                cout << "Автомобиль не создан! Создайте автомобиль перед посещением мастерской." << endl;
            }
            break;
        }
        default:
            cout << "Неверный ввод! Пожалуйста, попробуйте снова." << endl;
            break;
        }
    } while (action != 3);

    cout << "Выход из программы. До свидания!" << endl;

    return 0;
}

