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

};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter{
    private:
        ShoppingCart *cart;
    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart = cart;
        }
    void printInvoice(){
        cout<<"Shopping cart invoice:\n";
        for(auto p: cart->getProducts()){
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

// 3. SaveToDB: Only responsible for saving cart to DB
class SaveToDB{
    private:
        ShoppingCart* cart;
    public:
        SaveToDB(ShoppingCart* cart){
            this->cart = cart;
        }

        
        void saveToDatabase(){
            cout << "Saving shopping cart to database..." << endl;
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 30));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    SaveToDB* db = new SaveToDB(cart);
    db->saveToDatabase();


    return 0;
}