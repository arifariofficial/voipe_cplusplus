#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    int weight;
    int top_speed;
    long driven_km;

    Vehicle(int weight, int top_speed, long driven_km);

    void Drive(int journey);

    int InputWeight();

    int InputTopSpeed();

    long InputDrivenKm();
};

Vehicle::Vehicle(int Aw, int Ats, long Akm) {
    weight = Aw;
    top_speed = Ats;
    driven_km = Akm;
}

void Vehicle::Drive(int journey) {
    driven_km += journey;
}

int Vehicle::InputWeight() {
    return weight;
}

int Vehicle::InputTopSpeed() {
    return top_speed;
}

long Vehicle::InputDrivenKm() {
    return driven_km;
}

class Car : public Vehicle {
public:
    string brand, model, license;
    bool running;

    Car(int vehicle_weight, int vehicle_top_speed, long vehicle_driven_km, string car_brand, string car_model,
        string car_license, bool car_running
    );

    void check_up();

    void turn_on();

};

Car::Car(int vehicle_weight, int vehicle_top_speed, long vehicle_driven_km, string car_brand, string car_model,
         string car_license, bool car_running
) : Vehicle(vehicle_weight, vehicle_top_speed,
            vehicle_driven_km) {
    brand = car_brand;
    model = car_model;
    license = car_license;
    running = car_running;
}

void Car::check_up() {
    cout << "Car info:" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Kilometres: " << driven_km << endl;
    cout << "Weight: " << weight << endl;
    cout << "Top speed: " << top_speed << endl;
    cout << "License plate: " << license << endl;

    if (running == 0)
        cout << "Car is not running." << endl;
    if (running == 1)
        cout << "Car is running." << endl;
}

void Car::turn_on() {
    running = 1;
}

int inheritance_class_car() {
    int weight, speed;
    long km;
    string brand, model, license;

    // Ask for car information
    cout << "Input car brand: ";
    cin >> brand;

    cout << "Input car model: ";
    cin >> model;

    cout << "Input car license plate number: ";
    cin >> license;

    cout << "Input car weight: ";
    cin >> weight;

    cout << "Input car top speed: ";
    cin >> speed;

    cout << "Input distance traveled by car: ";
    cin >> km;
    cout << endl;
    Car carX(weight, speed, km, brand, model, license, 0);

    carX.check_up();
    carX.turn_on();
    carX.Drive(95);
    cout << endl;
    carX.check_up();
}
