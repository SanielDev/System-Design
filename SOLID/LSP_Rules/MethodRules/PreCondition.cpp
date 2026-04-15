#include <iostream>

using namespace std;

// A precondition must be satisfied before a method is executed
// The child class can loosen the precondition but cannot strengthen it.

class Users{
    public:
        // Precondition: Password must be atleast 8 character long
        virtual void setPassword(string password){
            if (password.length() < 8){
                throw invalid_argument("Password must be 8 characters long!");
            }
            cout << "Password set successfully" << endl;
        }
};

class AdminUser : public Users{
    public:
        // Precondition: Password must be atleast 6 character long
        void setPassword(string password) override {
            if (password.length() < 6){
                throw invalid_argument("Password must be 6 characters long!");
            }
            cout << "Password set successfully" << endl;
        }
};

int main() {
    Users* users = new AdminUser();
    users->setPassword("Admin1");
    return 0;
}