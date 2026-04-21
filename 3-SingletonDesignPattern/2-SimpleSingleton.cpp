#include <iostream>

using namespace std;

/*
Simple Singleton Implementation but its not thread safe.
*/

class SimpleSingleton {
    private:
        static SimpleSingleton* instance;
        SimpleSingleton() {
            cout << "Singleton Constructor called. New Object created. " << endl;
        }
    public:
        static SimpleSingleton* getSingleton() {
            if(instance == nullptr){
                instance = new SimpleSingleton();
            }
            return instance;
        }
};

SimpleSingleton* SimpleSingleton :: instance = nullptr;

int main() {
    SimpleSingleton* s1 = SimpleSingleton :: getSingleton();
    SimpleSingleton* s2 = SimpleSingleton :: getSingleton();

    cout << (s1 == s2) << endl;

    return 0;

}