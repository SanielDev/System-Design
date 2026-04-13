#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product{
    public:
        string name;
        double price;

        Product(string name, double price){
            this->name = name;
            this->price = price;
        }
};

// Violating SRP: Shopping cart is handling multiple responsibilities.
class ShoppingCart{
    private:
        vector<Product*> products;
    public:
        // setter for products
        void addProduct(Product* p){
            products.push_back(p);
        }
        // getter for products
        const vector<Product*>& getProducts(){
            return products;
        }

        // 1. Calculate total price in cart
        double calculateTotal(){
            double total = 0;
            for(auto p: products){
                total += p->price;
            }
            return total;
        }

        // 2. Violating SRP - Prints invoice (Should be in a separate class)
        void printInvoice(){
            cout<<"Shopping cart invoice:\n";
            for(auto p: products){
                cout << p->name << " - $" << p->price << endl;
            }
            cout << "Total: $" << calculateTotal() << endl;
        }

        // 3. Violating SRP - Saves to DB (Should be in a separate class)
        void saveToDatabase(){
            cout << "Saving shopping cart to database..." << endl;
        }

};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 30));

    cart->printInvoice();
    cart->saveToDatabase();


    return 0;
}