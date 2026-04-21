#include <iostream>
#include <string>

using namespace std;
/*
Abstract Factory:
- Having more than 1 product is mandatory for Abstract Factory. Here we have Burger and GarlicBread
- Family1: 
    SinghBurger = Normal Burger variants + Normal GarlicBread variant
- Family2:
    KingBurger = Wheat Burger variants + Wheat GarlicBread variant

- This matters cause, wheat burger would never come up with normal garlicbread. Abstract Factory guarantees this consistency
- Both product must come from same factory. (either SinghBurger or KingBurger)


MealFactory (abstract)
-----------
    |
    |- SingBurger (Normal Burger + Normal GarlicBread) => Family 1
    |- KingBurger (Wheat Burger + Wheat GarlicBread) => Family 2

In Factory Method => Typically deals with one abstract product at a time
In Abstract Factory => Deals with multiple abstract product

*/

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

class BasicWheatBurger : public Burger {
    public:
        void prepare () override {
            cout << "Preparing Basic Wheat Burger" << endl;
        }
};

class StandardWheatBurger : public Burger {
    public:
        void prepare () override {
            cout << "Preparing Standard Wheat Burger" << endl;
        }
};

class PremiumWheatBurger : public Burger {
    public:
        void prepare () override {
            cout << "Preparing Premium Wheat Burger" << endl;
        }
};

// Abstract GarlicBread class
class GarlicBread {
    public:
        virtual void prepare() = 0;
};

// Concrete class for GarlicBread
class BasicGarlicBread : public GarlicBread {
    public: 
        void prepare() override {
            cout << "Preparing Basic Garlic Bread" << endl;
        }
};

class CheeseGarlicBread : public GarlicBread {
    public: 
        void prepare() override {
            cout << "Preparing Cheese Garlic Bread" << endl;
        }
};

class BasicWheatGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "Preparing Wheat Garlic Bread" << endl;
        }
};

class CheeseWheatGarlicBread : public GarlicBread {
    public: 
        void prepare() override {
            cout << "Preparing Cheese Wheat Garlic Bread" << endl;
        }
};

// Abstract Factory class
class MealFactory {

    public:
        virtual Burger* createBurger(string type) = 0;
        virtual GarlicBread* createGarlicBread(string type) = 0;
};

class SinghBurger : public MealFactory {
    public:
        Burger* createBurger(string type) override {
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

        GarlicBread* createGarlicBread(string type) override {
            if (type == "basic"){
                return new BasicGarlicBread();
            }
            else if (type == "cheese"){
                return new CheeseGarlicBread();
            }
            else{
                cout << "Invalid Burger Type!" << endl;
                return nullptr;
            }
        }
};

class KingBurger : public MealFactory {
    public:
        Burger* createBurger(string type) override {
            if (type == "basic"){
                return new BasicWheatBurger();
            }
            else if (type == "standard"){
                return new StandardWheatBurger();
            }
            else if ( type == "premium"){
                return new PremiumWheatBurger();
            }
            else{
                cout << "Invalid Burger Type!" << endl;
                return nullptr;
            }
        }

        GarlicBread* createGarlicBread(string type) override {
            if (type == "basic"){
                return new BasicWheatGarlicBread();
            }
            else if (type == "cheese"){
                return new CheeseWheatGarlicBread();
            }
            else{
                cout << "Invalid Burger Type!" << endl;
                return nullptr;
            }
        }
};

int main(){
    string burgerType = "basic";
    string garlicBreadType = "cheese";
    MealFactory* myBurgerFactory = new SinghBurger();
    Burger* burger = myBurgerFactory->createBurger(burgerType);
    GarlicBread* garlicBread = myBurgerFactory->createGarlicBread(garlicBreadType);

    burger->prepare();
    garlicBread->prepare();

    cout << "-------------------------------------------------------" << endl;

    string burgerType1 = "premium";
    string garlicBreadType1 = "cheese";
    MealFactory* myBurgerFactory1 = new KingBurger();
    Burger* burger1 = myBurgerFactory1->createBurger(burgerType1);
    GarlicBread* garlicBread1 = myBurgerFactory1->createGarlicBread(garlicBreadType1);

    burger1->prepare();
    garlicBread1->prepare();

    delete myBurgerFactory;
    delete myBurgerFactory1;
    delete burger;
    delete burger1;
    delete garlicBread;
    delete garlicBread1;

    return 0;
}