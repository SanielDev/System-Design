#include <iostream>
#include <string>

using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    
    public:
        Car(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        // Common methods for all car
        void startEngine(){
            isEngineOn = true;
            cout<< brand << " " << model << " : Engine starts with a roar" << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Engine turned off."<<endl;
        }

        virtual void accelerate() = 0; // abstract method for dynamic polymorphism
        virtual void brake() = 0; // abstract method for dynamic polymorphism
        virtual ~Car() {}


};

class ManualCar : public Car{
    protected:
        int currentGear;
    
    public:
        ManualCar(string b, string m) : Car(b, m){
            this->currentGear = 0;
        }

        // Specialized method for ManualCar
        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
        }

        // Overriding accelerate - Dynamic Polymorphism
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

};

class ElectricCar : public Car{
    protected:
        int batteryLevel;

    public: 
        ElectricCar(string b, string m) : Car(b, m) {
            batteryLevel = 100;
        }
    
        // Specialized method for Electric Car
        void chargeBattery(){
            batteryLevel = 100;
            cout << brand << " " << model << " : Battery fully charged " << endl;
        }

        // Overriding accelerate - Dynamic Polymorphism
        void accelerate(){
            if (!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate."<<endl;
                return;
            }
            if (batteryLevel <= 0){
                cout<<brand<<" "<<model<<" : Battery dead! Cannot accelerate"<<endl;
                return;
            }
            batteryLevel -= 10;
            currentSpeed += 15;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" Km/hr. Battery at " << batteryLevel <<"%" << endl;
        }

        void brake(){
            currentSpeed -= 15;
            if (currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Regenerative Braking! Speed is now  "<<currentSpeed<<" Km/hr"<<endl;
        }
};

int main(){

    Car* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    delete myManualCar;

    cout<<"---------------------------------------" << endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myElectricCar;

    return 0;
}