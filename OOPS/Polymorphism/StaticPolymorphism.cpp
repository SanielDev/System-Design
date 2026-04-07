#include <iostream>
#include <string>

using namespace std;

// Method Overloading
class ManualCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
    
    public:
        ManualCar(string b, string m){
            this->brand = b;
            this->model = m;
            this->isEngineOn = false;
            this->currentSpeed = 0;
            this->currentGear = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout<< brand << " " << model << " : Engine starts with a roar" << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Engine turned off."<<endl;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
        }

        // Overloading accelerate - Static Polymorphism
        void accelerate(){
            if (!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate."<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" Km/hr"<<endl;
        }

        void accelerate(int speed){
            if (!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate."<<endl;
                return;
            }
            currentSpeed += speed;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" Km/hr"<<endl;
        }

        void brake(){
            currentSpeed -= 20;
            if (currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Braking! Speed is now  "<<currentSpeed<<" Km/hr"<<endl;
        }

};

int main(){

    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate(40);
    myManualCar->brake();
    myManualCar->stopEngine();

    delete myManualCar;

    cout<<"---------------------------------------" << endl;

    return 0;
}