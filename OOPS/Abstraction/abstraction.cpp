#include <iostream>
#include <string>

using namespace std;

// Abstraction focuses on data hiding

class Car{
    public:
        virtual void startEngine() = 0; // here we are just declaring the function and the child class will define what the function actually does
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}
};
// Since the above class has virtual method, the Class Car is an abstract class.

class SportsCar : public Car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout<< brand << " " << model << " : Engine starts with a roar" << endl;
        }

        void shiftGear(int gear){
            if (!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot shift gear."<<endl;
                return;
            }
            currentGear = gear;
            cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
        }

        void accelerate(){
            if (!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate."<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" Km/hr"<<endl;
        }

        void brake(){
            currentSpeed -= 20;
            if (currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Braking! Speed is now  "<<currentSpeed<<" Km/hr"<<endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Engine turned off."<<endl;
        }
};

int main(){
    // Parent class ka pointer child class k object ko point karsakta hai
    // A pointer of the parent class can point to the object of the child class
    Car* myCar = new SportsCar("Ford", "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;

    return 0;

}