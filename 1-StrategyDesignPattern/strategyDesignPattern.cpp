#include <iostream>
#include <string> 

using namespace std;

// Abstract class for talkable
class Talkable{
    public:
        virtual void talk () = 0;
};

// Concrete Implementation
class NormalTalk : public Talkable {
    public: 
        void talk () override {
            cout << "Normal Taking Robot" << endl;
        }
};

class NoTalk : public Talkable {
    public: 
        void talk () override {
            cout << "No Taking Robot" << endl;
        }
};

// Abstract class for walkable
class Walkable {
    public:
        virtual void walk () = 0;
};

// Concrete Implementation
class NormalWalk : public Walkable {
    public:
        void walk () override {
            cout << "Normally Walking Robot" << endl;
        }
};

class NoWalk : public Walkable {
    public:
        void walk () override {
            cout << "No walking Robot" << endl;
        }
};

// Abstract class for flyable
class Flyable {
    public:
        virtual void fly () = 0;
};

// Concrete Implementation
class NormalFly : public Flyable {
    public:
        void fly () override {
            cout << "Normally flying Robot" << endl;
        }
};

class NoFly : public Flyable {
    public:
        void fly () override {
            cout << "No flying Robot" << endl;
        }
};

// ----------------- Robot Base class ---------------------------
class Robot {
    protected: 
        Talkable* talkBehavior;
        Walkable* walkBehavior;
        Flyable* flyBehavior;
    public:
        // We can do Constructor Injection (type of dependency injection)
        Robot(Talkable* t, Walkable* w, Flyable* f){
            this->talkBehavior = t;
            this->walkBehavior = w;
            this->flyBehavior = f;
        }
        void talk(){
            talkBehavior->talk();
        }
        void walk(){
            walkBehavior->walk();
        }
        void fly(){
            flyBehavior->fly();
        }

        virtual void projection () = 0; // abstract method for subclasses
};

class CompanionR : public Robot{
    public:
        CompanionR(Talkable* t, Walkable* w, Flyable* f) : Robot(t, w, f) {}

        void projection () {
            cout << "Displaying Companion Robot's projection" << endl;
        }
};

class WorkerR : public Robot{
    public:
        WorkerR(Talkable* t, Walkable* w, Flyable* f) : Robot(t, w, f) {}

        void projection () {
            cout << "Displaying Worker Robot's projection" << endl;
        }
};

// --------- Main Function ---------------------
int main(){

    Robot* companionRobot = new CompanionR(new NormalTalk(), new NoWalk(), new NoFly());
    companionRobot->talk();
    companionRobot->walk();
    companionRobot->fly();
    companionRobot->projection();
    cout << "-------------------------------------------------" << endl;
    Robot* workerRobot = new WorkerR(new NoTalk(), new NormalWalk(), new NormalFly());
    workerRobot->talk();
    workerRobot->walk();
    workerRobot->fly();
    workerRobot->projection();

    return 0;
}