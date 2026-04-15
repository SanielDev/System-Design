#include <iostream>
using namespace std;

// Abstraction (Interface)
class Database {
public:
    virtual void save(string data) = 0; // Pure virtual function
};

// MySQL implementation (Low-level module)
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

// MongoDB implementation (Low-level module)
class MongoDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

// High-level module (Now loosely coupled)
class UserService {
private:
    Database* db;  // Dependency Injection
    // Dependency Injection means: "don't create dependencies yourself — let someone from outside give it to you"

public:
    UserService(Database* database) {  
        db = database;
    }
    
    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    // Memory is automatically freed when it goes out of scope
    MySQLDatabase mysql; // lives on the stack
    MongoDBDatabase mongodb; // lives on the stack

    UserService service1(&mysql);
    service1.storeUser("Aditya");

    UserService service2(&mongodb);
    service2.storeUser("Rohit");


    // In the below approach memory needs to be freed
    // Database* db1 = new MySQLDatabase(); // lives on the heap
    // Database* db2 = new MongoDBDatabase(); // lives on the heap
    // UserService* service1 = new UserService(db1);
    // service1->storeUser("Saniel");

    // UserService* service2 = new UserService(db2);
    // service2->storeUser("Bhattarai");

    // good practice
    // delete service1;
    // delete service2;
    // delete db1;
    // delete db2;
}