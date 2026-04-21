#include <iostream>
#include <mutex>

using namespace std;

/*
Thread safe Singleton implementation but the locking mechanism happens regardless of instance being a nullptr or not.
If instance is not a nullptr then it should directly return instance without starting the locking mechanism.
*/

class Singleton {
    private:
        static Singleton* instance;
        static mutex mtx;

        Singleton () {
            cout << "Singleton Constructor called!" << endl;
        }
    
    public:
        static Singleton* getInstance(){
            lock_guard<mutex> lock(mtx); // lock for thread safety
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }
};

Singleton* Singleton :: instance = nullptr;
mutex Singleton :: mtx;

int main() {
    Singleton* s1 = Singleton :: getInstance();
    Singleton* s2 = Singleton :: getInstance();

    cout << (s1 == s2) << endl;

    return 0;

}