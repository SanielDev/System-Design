#include <iostream>

using namespace std;

/*
This implementation of Singleton Design Pattern is known as Eager Initialization.
Here what we are doing is: even before the execution of main() function we are initializing the static variable instance with
and object of the Singleton class. This way we dont even need to check a single if-condition in the getInstance() method.

Now the issue with this implementation is:
=> Suppose we have a singleton class which is very memory extensive. And here we are creating an object of this class even 
before out application runs i.e. even before main() is running. Suppose that object is not used anywhere else in the code
(meaning the method of that class is not called anywhere in the code) then it would just occupy the memory.
Thus, Eager Initialization is not that practical and not used that often.

*/

class Singleton {
    private:
        static Singleton* instance;

        Singleton () {
            cout << "Singleton Constructor called!" << endl;
        }
    
    public:
        static Singleton* getInstance(){
            return instance;
        }
};

Singleton* Singleton :: instance = new Singleton();

int main() {
    Singleton* s1 = Singleton :: getInstance();
    Singleton* s2 = Singleton :: getInstance();

    cout << (s1 == s2) << endl;

    return 0;

}