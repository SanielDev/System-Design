#include <iostream>

using namespace std;

// Method Argument Rule:
// Subtype method's arguments can be identical or wider than the supertype 

class Parent{
    public:
        virtual void print(string text){
            cout << "Parent: " << text << endl;
        }
};

class Child : public Parent{
    public: 
        void print (string text) override {
            cout << "Child: " << text << endl;
        }
};

// Client that passes string as message as client expects
class Client{
    private:
        Parent* p;
    
    public:
        Client(Parent* p){
            this->p = p;
        }
        void printMsg(){
            p->print("Saniel");
        }
};

int main(){

    Parent* parent = new Parent();
    Parent* child = new Child();

    Client* client = new Client(parent);
    Client* client1 = new Client(child);

    client->printMsg();
    client1->printMsg();


    return 0;
}