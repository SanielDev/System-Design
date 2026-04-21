#include <iostream>
#include <mutex>

using namespace std;

/*
If instance is nullptr then it wont initiate the locking mechanism and directly return the instance.
The inner if condition is used cause: if 2 threads T1 and T2 check the outer condition simultaneously then both will satisfy
the condition and then go inside the if-block. But only one thread is going to go inside the critical section(assume its T1).
Since instance is nullptr right now so it will create a new instance and come out and the critical section gets unlocked.
Now if the inner if-condition was not there then, T2 which was waiting for the critical section to be available would have
initialized a new object which would have resulted in crashing the gist of this design pattern.

But since there is inner if-condition, the T1 has already created an instance so for T2 when the inner if-condition is checked
instance is not nullptr so it comes out and just returns the instance initialized by the thread T1.
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
            if(instance == nullptr){
                lock_guard<mutex> lock(mtx); // lock for thread safety
                if(instance == nullptr){
                    instance = new Singleton();
                }
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