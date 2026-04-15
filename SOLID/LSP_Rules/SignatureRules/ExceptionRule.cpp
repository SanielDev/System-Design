#include <iostream>

using namespace std;

// Exception Rule:
// A subclass should throw fewer or narrower exceptions 
// (but not additional or broader exceptions) than the parent.
// C++ does not enforces this. Hence no compilation error.

class Parent {
public:
    virtual void getValue() noexcept(false) { // Parent throws logic_error exception
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
public:
    void getValue() noexcept(false)  override { // Child throws out_of_range exception
        throw out_of_range("Child error");
        // throw runtime_error("Child Error"); // This is Wrong
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeValue() {
        try {
            p->getValue();
        }
        catch(const logic_error& e) {
            cout << "Logic error exception occured : " << e.what() << endl;
        }
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    //Client* client = new Client(child);

    client->takeValue();

    return 0;
}