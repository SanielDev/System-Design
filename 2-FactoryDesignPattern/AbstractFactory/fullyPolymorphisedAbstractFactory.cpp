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

-> One concrete factory per product family

######### LIMITATION OF ABSTRACT FACTORY:
-> If we have to add, suppose SanielBurgerFactory, then I can just create a subclass for MealFactory and then override the 
virtual functions inside the MealFactory. So, on the factory level the OCP is satisfied.
-> But when we have to add a new product like Pizza. Then the SinghBurger and KingBurger will have to create:
    Pizza* createBasicPizza() and Pizza* createPremiumPizza() inside both the factory, assuming basic and premium pizza are there.
So in this case, we are making changes in the existing code, which means we are violating the OCP.


=> Abstract Factory is designed to be open for new product families.
=> Real issue is when we add new products like Pizza. Here OCP gets violated.
This is not accidental -- it is by design

**** Why Abstract Factory violates OCP for new products?
=> The abstract factory interface is a closed contract. So if you add a new product then every single concrete factory must change.
That means: SinghBurger, KingBurger, and any future factories. This is a known limitation


This doesnt mean Abstract Factory is a "bad design".
Abstract Factory assumes: 
    1. Product typess are fixed
    2. Product families will grow

So, if changes is expected in the family like addition of SanielBurgerFactory and DanielBurgerFactory then use Abstract Factory
if product types are going to change frequently then dont use this method.

#### ABSTRACT FACTORY IS CLOSED TO NEW PRODUCTS BUT OPEN TO NEW FAMILIES

=> Abstract Factory sacrifices:
    - OCP for new product types
In order to gain:
    - Strong product compatibility
    - Compile time safety
    - Family-wide consistency

So, if your system really needs frequent new products then Abstract Factory is the wrong pattern.

ABSTRACT FACTORY IS INTENTIONALLY DESIGNED TO BE OPEN FOR EXTENSION ALONG THE FAMILY AXIS, AND NOT THE PRODUCT AXIS.


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
        virtual Burger* createBasicBurger() = 0;
        virtual Burger* createStandardBurger() = 0;
        virtual Burger* createPremiumBurger() = 0;

        virtual GarlicBread* createBasicGarlicBread() = 0;
        virtual GarlicBread* createCheeseGarlicBread() = 0;
};

class SinghBurger : public MealFactory {
    public:
        Burger* createBasicBurger() override {
            return new BasicBurger();
        }
        Burger* createStandardBurger() override {
            return new StandardBurger();
        }
        Burger* createPremiumBurger() override {
            return new PremiumBurger();
        }

        GarlicBread* createBasicGarlicBread() override {
            return new BasicGarlicBread();
        }
        GarlicBread* createCheeseGarlicBread() override {
            return new CheeseGarlicBread();
        }
};

class KingBurger : public MealFactory {
    public:
        Burger* createBasicBurger() override {
            return new BasicWheatBurger();
        }
        Burger* createStandardBurger() override {
            return new StandardWheatBurger();
        }
        Burger* createPremiumBurger() override {
            return new PremiumWheatBurger();
        }

        GarlicBread* createBasicGarlicBread() override {
            return new BasicWheatGarlicBread();
        }
        GarlicBread* createCheeseGarlicBread() override {
            return new CheeseWheatGarlicBread();
        }
};

int main(){
    // string burgerType = "basic";
    // string garlicBreadType = "cheese";
    MealFactory* myBurgerFactory = new SinghBurger();
    Burger* burger = myBurgerFactory->createBasicBurger(); // obj of BasicBurger is returned (goes to line 126)
    GarlicBread* garlicBread = myBurgerFactory->createCheeseGarlicBread(); // obj of CheeseGarlicBread is returned (goes to line 139)

    burger->prepare();
    garlicBread->prepare();

    cout << "-------------------------------------------------------" << endl;

    // string burgerType1 = "premium";
    // string garlicBreadType1 = "cheese";
    MealFactory* myBurgerFactory1 = new KingBurger();
    Burger* burger1 = myBurgerFactory1->createPremiumBurger(); // obj of PremiumWheatBurger is returned (goes to line 152)
    GarlicBread* garlicBread1 = myBurgerFactory1->createBasicGarlicBread(); // obj of BasicWheatGarlicBread is returned (goes to line 156)

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