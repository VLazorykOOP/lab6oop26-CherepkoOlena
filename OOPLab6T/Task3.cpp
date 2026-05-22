//
// Created by acer_ on 21.05.2026.
//

#include <iostream>

using namespace std;

class Car {
public:
    Car() {
        cout << "Created Car" << endl;
    }
    virtual ~Car() {
        cout << "Destroyed Car" << endl;
    }

    virtual void startEngine() = 0;
};

class PassengerTransport {
public:
    PassengerTransport() {
        cout << "Created Transport" << endl;
    }
    virtual ~PassengerTransport() {
        cout << "Destroyed Transport" << endl;
    }

    virtual void boardPassengers() = 0;
};

class Bus : public Car, public PassengerTransport {
public:
    Bus() {
        cout << "Created Bus" << endl;
    }
    ~Bus() override {
        cout << "Destroyed Bus" << endl;
    }

    void startEngine() override
    {
        cout << "Bus started engine" << endl;
    }

    void boardPassengers() override
    {
        cout << "Passengers enter Bus" << endl;
    }

    void driveOnRoute() {
        cout << "Driving" << endl;
    }
};

void task3() {
    Bus myBus;

    myBus.startEngine();
    myBus.boardPassengers();
    myBus.driveOnRoute();
}