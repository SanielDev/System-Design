#include <iostream>
#include <string>

using namespace std;

// Abstract class for burger
class Burger {
    public:
        virtual void prepare () = 0;
};

// Concrete Implementation of Basic, Standard and Premium
class BasicBurger : public Burger {
    public:
        void prepare () override {
            cout << "Preparing Basic Burger" << endl;
        }
};

class StandardBurger : public Burger {
    public:
        void prepare () override {
            cout << "Preparing Standard Burger" << endl;
        }
};

class PremiumBurger : public Burger {
    public:
        void prepare () override {
            cout << "Preparing Premium Burger" << endl;
        }
};

// Factory class
class BurgerFactory {

    public:
        Burger* createBurger(string type){
            if (type == "basic"){
                return new BasicBurger();
            }
            else if (type == "standard"){
                return new StandardBurger();
            }
            else if ( type == "premium"){
                return new PremiumBurger();
            }
            else{
                cout << "Invalid Burger Type!" << endl;
                return nullptr;
            }
        }
};

int main(){
    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();
    


    return 0;
}