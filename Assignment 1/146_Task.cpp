#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
    string regNo;
    string brand;
    double size;

public:
    Vehicle(string reg, string brd, double sz)
        : regNo(reg), brand(brd), size(sz) {}

    virtual void doService() = 0;

    virtual void printDetails()
    {
        cout << "Registration Number: " << regNo
             << "\nBrand: " << brand
             << "\nSize: " << size << " cubic meters" << endl;
    }

    double getSize()
    {
        return size;
    }

    virtual ~Vehicle() {}
};

class Gasoline : virtual public Vehicle
{
protected:
    double tankSize;
    string fuelKind;

public:
    Gasoline(string reg, string brd, double sz, string fuel, double tank)
        : Vehicle(reg, brd, sz), tankSize(tank), fuelKind(fuel) {}

    virtual double calcFuelUsage(double distance)
    {
        return tankSize / distance;
    }

    void doService() override
    {
        cout << "Gasoline - Service performed" << endl;
    }

    void printDetails() override
    {
        Vehicle::printDetails();
        cout << "Fuel Type: " << fuelKind
             << "\nTank Size: " << tankSize << " liters" << endl;
    }
};

class Electric : virtual public Vehicle
{
protected:
    double batteryPower;
    double chargeDuration;

public:
    Electric(string reg, string brd, double sz, double battery, double charge)
        : Vehicle(reg, brd, sz), batteryPower(battery), chargeDuration(charge) {}

    void doService() override
    {
        cout << "Electric - Service performed" << endl;
    }

    double calcFuelUsage(double distance)
    {
        return batteryPower / distance;
    }

    void printDetails() override
    {
        Vehicle::printDetails();
        cout << "Battery Power: " << batteryPower << " kWh"
             << "\nCharge Duration: " << chargeDuration << " hours" << endl;
    }
};

class Motorcycle : public Gasoline
{
public:
    Motorcycle(string reg, string brd, double sz, double tank, string fuel)
        : Vehicle(reg, brd, sz), Gasoline(reg, brd, sz, fuel, tank) {}

    void doService() override
    {
        cout << "Motorcycle - Service performed" << endl;
    }

    double calcFuelUsage(double distance) override
    {
        return (tankSize / distance) * 100;
    }
};

class Car : public Gasoline
{
protected:
    int seatingCapacity;

public:
    Car(string reg, string brd, double sz, double tank, string fuel, int seats)
        : Vehicle(reg, brd, sz), Gasoline(reg, brd, sz, fuel, tank), seatingCapacity(seats) {}

    void doService() override
    {
        cout << "Car - Service performed" << endl;
    }

    void printDetails() override
    {
        Gasoline::printDetails();
        cout << "Seating Capacity: " << seatingCapacity << " persons" << endl;
    }

    double calcFuelUsage(double distance) override
    {
        return (tankSize / distance) * 100;
    }
};

class Truck : public Gasoline
{
protected:
    double maxCargo;

public:
    Truck(string reg, string brd, double sz, double tank, string fuel, double cargo)
        : Vehicle(reg, brd, sz), Gasoline(reg, brd, sz, fuel, tank), maxCargo(cargo) {}

    void doService() override
    {
        cout << "Truck - Service performed" << endl;
    }

    void printDetails() override
    {
        Gasoline::printDetails();
        cout << "Max Cargo: " << maxCargo << " tons" << endl;
    }

    double calcFuelUsage(double distance) override
    {
        return (tankSize / distance) * 100;
    }
};

class Hybrid : public Gasoline, public Electric
{
protected:
    double regenEfficiency;

public:
    Hybrid(string reg, string brd, double sz, double tank, string fuel,
           double battery, double charge, double regen)
        : Vehicle(reg, brd, sz), Gasoline(reg, brd, sz, fuel, tank),
          Electric(reg, brd, sz, battery, charge), regenEfficiency(regen) {}

    void doService() override
    {
        cout << "Hybrid - Service performed" << endl;
    }

    void printDetails() override
    {
        Vehicle::printDetails();
        cout << "Fuel Type: " << fuelKind
             << "\nTank Size: " << tankSize
             << "\nBattery Power: " << batteryPower
             << "\nCharge Time: " << chargeDuration
             << "\nRegeneration Efficiency: " << regenEfficiency << "%" << endl;
    }
};

class Employee
{
protected:
    string empName;
    int empId;

public:
    Employee(string name, int id) : empName(name), empId(id) {}

    virtual void introduceSelf() = 0;

    virtual ~Employee() {}
};

class Manager : public Employee
{
public:
    Manager(string name, int id) : Employee(name, id) {}

    void introduceSelf() override
    {
        cout << "Manager: " << empName << endl;
    }
};

class Driver : public Employee
{
public:
    Driver(string name, int id) : Employee(name, id) {}

    void introduceSelf() override
    {
        cout << "Driver: " << empName << endl;
    }
};

class Branch
{
    vector<Vehicle *> fleet;
    vector<Employee *> staff;

public:
    void addVehicle(Vehicle *v)
    {
        fleet.push_back(v);
    }

    void addEmployee(Employee *e)
    {
        staff.push_back(e);
    }

    void performServiceOnFleet()
    {
        for (auto &vehicle : fleet)
        {
            vehicle->doService();
        }
    }

    void introduceStaff()
    {
        for (auto &person : staff)
        {
            person->introduceSelf();
        }
    }

    ~Branch()
    {
        for (auto &vehicle : fleet)
        {
            delete vehicle;
        }
        for (auto &person : staff)
        {
            delete person;
        }
    }
};

int main()
{
    Branch depot;

    depot.addVehicle(new Car("1234", "Toyota", 5.0, 45, "Petrol", 4));
    depot.addVehicle(new Motorcycle("5678", "Yamaha", 2.5, 15, "Petrol"));
    depot.addVehicle(new Truck("9012", "Volvo", 10.0, 120, "Diesel", 25));
    depot.addVehicle(new Hybrid("3456", "Tesla", 8.0, 30, "Petrol", 80, 3, 85));

    depot.addEmployee(new Manager("Alice", 1001));
    depot.addEmployee(new Driver("Bob", 2002));

    depot.introduceStaff();
    depot.performServiceOnFleet();

    return 0;
}
