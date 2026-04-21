#include <iostream>
#include <string>

using namespace std;
/*
Factory Method :
- Creation Logic is spread across sub-classes
- Factory is abstract
- Factory method solves the problem that Simple Factory couldn't solve which is:
"Adding new type of product without modifying the existing code"

Idea of Factory Method:
- Instead of (one factory + conditionals)
- We do: 
        -> One factory interface
        -> one concrete factory per product

The below implementation is Factory Method at the high level but Simple Factory at low level.
This implementation obeys OCP partially.
-- To add a new factory(restaurant)
class VeganBurgerFactory : public BurgerFactory {
    Burger* createBurger (string type) override {
        // same if-else implementation
    }
};

Suppose if we have to add a new product, say a burger type, "double-cheese"
Then, we will have to add a new condition in both the createBurger() method in the SinghBurger and KingBurger class
This violates the OCP at the product level/

In the purest Factory Method style:
- No if-else 
- One factory per product
So SinghBurger has to be divided into --> BasicSinghBurgerFactory
                                          StandardSinghBurgerFactory
                                          PremiumSinghBurgerFactory

Same goes to KingBurger. This way we have one concrete factory per product.
So now when we have to add a new product, we can just create a concrete factory which inherits the BurgerFactory which doesn't
violate the OCP

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

// Abstract Factory class
class BurgerFactory {

    public:
        virtual Burger* createBurger() = 0;
};

class SinghBasicBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger() override {
            return new BasicBurger();
        }
};

class SinghStandardBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger() override {
            return new StandardBurger();
        }
};

class SinghPremiumBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger() override {
            return new PremiumBurger();
        }
};

class KingBasicBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger() override {
            return new BasicWheatBurger();
        }
};

class KingStandardBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger() override {
            return new StandardWheatBurger();
        }
};

class KingPremiumBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger() override {
            return new PremiumWheatBurger();
        }
};

int main(){
    // string type = "basic";
    BurgerFactory* myBurgerFactory = new SinghBasicBurgerFactory();
    Burger* burger = myBurgerFactory->createBurger();

    burger->prepare();

    cout << "-------------------------------------------------------" << endl;

    BurgerFactory* myBurgerFactory1 = new KingPremiumBurgerFactory();
    Burger* burger1 = myBurgerFactory1->createBurger();

    burger1->prepare();

    delete myBurgerFactory;
    delete burger;
    delete myBurgerFactory1;
    delete burger1;

    return 0;
}