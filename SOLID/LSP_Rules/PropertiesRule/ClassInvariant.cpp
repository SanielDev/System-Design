#include <iostream>

using namespace std;

// Class Invariant of a parent class shouldnt be broken by child class object.
// Child class can either maintain or strengthen the invariant but never narrow it down(loosen it).

class BankAccount{
    protected:
        double balance;
    public:
        BankAccount(double b){
            if(b < 0) throw invalid_argument("Balance cannot be negative!");
            balance = b;
        }

        virtual void withdraw(double amount){
            if(balance - amount < 0) throw runtime_error("Insufficient Funds!");
            balance -= amount;
            cout << "Amount withdrawn. Remaining amount is: " << balance << endl;
        }
};

class CheatAccount : public BankAccount{
    public:
        CheatAccount(double b) : BankAccount(b) {}

        void withdraw(double amount){
            balance -= amount; // LSP breaks.... Negative balance allowed
            cout << "Amount withdrawn. Remaining amount is: " << balance << endl;
        }
};

int main(){
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(50);

    BankAccount* cheatAccount = new CheatAccount(100);
    cheatAccount->withdraw(200);

    return 0;
}