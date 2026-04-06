#include <iostream>
#include <string>

using namespace std;

// Encapsulation focuses on data security

class SportsCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        string tire;

    public:
        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            tire = "MRF";
        }

        // getters and setters
        int getCurrentSpeed(){
            return this->currentSpeed;
        }

        string getTire(){
            return this->tire;
        }

        void setTire(string tire){
            this->tire = tire;
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

    SportsCar* mySportsCar = new SportsCar("Ford", "Mustang");

    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    // mySportsCar->currentSpeed = 500;

    // cout<<"Current speed of my sports car is set to: "<<mySportsCar->currentSpeed<<endl;

    cout<<mySportsCar->getCurrentSpeed();

    delete mySportsCar;

    return 0;
}