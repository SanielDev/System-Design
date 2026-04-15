#include <iostream>
#include <string>

using namespace std;

// For Fixed Deposit accounts
class depositOnlyAccount{
    public:
        virtual void deposit(double amount) = 0; 
};

class FixedDeposit : public depositOnlyAccount{
    private:
        double balance;
    public:
        FixedDeposit(){
            balance = 0;
        }
        void deposit (double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Fixed Deposit. New Balance: " << balance << endl;
        }
};

class withDrawableAccount : public depositOnlyAccount{
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public withDrawableAccount{
    private:
        double balance;
    public:
        SavingsAccount(){
            balance = 0;
        }
        void deposit (double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
        }
        void withdraw (double amount) {
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
            }
            else{
                cout << "Insufficient funds in Savings Account!\n";
            }
        }
};

class CurrentAccount : public withDrawableAccount{
    private:
        double balance;
    public:
        CurrentAccount(){
            balance = 0;
        }
        void deposit (double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            }
            else{
                cout << "Insufficient funds in Current Account!\n";
            }
        }
};


class BankClient{
    private:
        vector<withDrawableAccount*> withDrawableAccounts;
        vector<depositOnlyAccount*> depositOnlyAccounts;
    
    public: 
        BankClient(vector<withDrawableAccount*> withDrawableAccounts, vector<depositOnlyAccount*> depositOnlyAccounts){
            this->withDrawableAccounts = withDrawableAccounts;
            this->depositOnlyAccounts = depositOnlyAccounts;
        }


    void processTransactions(){
        for(withDrawableAccount* acc : withDrawableAccounts){
            acc->deposit(1000); // All accounts allow deposit
            acc->withdraw(500);
        }
        for(depositOnlyAccount* acc : depositOnlyAccounts){
            acc->deposit(1000);
        }
    }
};

int main(){
    vector<withDrawableAccount*> withDrawableAccounts;
    vector<depositOnlyAccount*> depositOnlyAccounts;
    
    withDrawableAccounts.push_back(new SavingsAccount());
    withDrawableAccounts.push_back(new CurrentAccount());
    depositOnlyAccounts.push_back(new FixedDeposit());

    BankClient* client = new BankClient(withDrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}