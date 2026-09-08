#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Dynamic centering function based on line width
void printCentered(const string &text, int width = 52)
{
    int pad = (width - text.length()) / 2;
    if (pad > 0)
        cout << string(pad, ' ') << text << endl;
    else
        cout << text << endl;
}

// MenuItem Class
class MenuItem
{
private:
    int id;
    string name;
    string category;
    double price;

public:
    MenuItem() : id(0), name(""), category(""), price(0.0) {}

    MenuItem(int i, string n, string c, double p)
        : id(i), name(n), category(c), price(p) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }

    void display() const
    {
        cout << left
             << setw(5) << id
             << setw(20) << name
             << setw(15) << category
             << "Rs. " << price << endl;
    }
};

// Customer Class
class Customer
{
protected:
    string name;
    string phone;

public:
    Customer(string n = "", string p = "") : name(n), phone(p) {}
    virtual ~Customer() {}

    virtual double getDiscount() const { return 0; }
    virtual string getCustomerType() const { return "Regular Customer"; }

    string getName() const { return name; }
    string getPhone() const { return phone; }
};

// PremiumCustomer Class
class PremiumCustomer : public Customer
{
public:
    PremiumCustomer(string n = "", string p = "") : Customer(n, p) {}

    double getDiscount() const override { return 10; }
    string getCustomerType() const override { return "Premium Customer"; }
};

// Order Class
class Order
{
private:
    MenuItem items[50];
    int itemCount;

public:
    Order() : itemCount(0) {}

    void addItem(const MenuItem &item)
    {
        if (itemCount < 50)
        {
            items[itemCount] = item;
            itemCount++;
            cout << "\n>> " << item.getName() << " added to your order successfully.\n";
        }
        else
        {
            cout << "\nOrder is full!\n";
        }
    }

    double calculateSubtotal() const
    {
        double total = 0;
        for (int i = 0; i < itemCount; i++)
        {
            total += items[i].getPrice();
        }
        return total;
    }

    bool isEmpty() const { return itemCount == 0; }
    int getItemCount() const { return itemCount; }
    MenuItem getItem(int index) const { return items[index]; }
};

// Cafe Class
class Cafe
{
private:
    MenuItem menu[8];
    int menuSize;

public:
    Cafe()
    {
        menuSize = 8;
        menu[0] = MenuItem(1, "Coffee", "Beverage", 350);
        menu[1] = MenuItem(2, "Cappuccino", "Beverage", 450);
        menu[2] = MenuItem(3, "Burger", "Fast Food", 500);
        menu[3] = MenuItem(4, "Fries", "Fast Food", 250);
        menu[4] = MenuItem(5, "Pizza", "Fast Food", 800);
        menu[5] = MenuItem(6, "Cake", "Dessert", 300);
        menu[6] = MenuItem(7, "Brownie", "Dessert", 350);
        menu[7] = MenuItem(8, "Cold Drink", "Beverage", 180);
    }

    void displayMenu() const
    {
        cout << "\n====================================================\n";
        printCentered("BREW & BITE", 52);
        printCentered("MENU", 52);
        cout << "====================================================\n";

        cout << left
             << setw(5) << "ID"
             << setw(20) << "Item"
             << setw(15) << "Category"
             << "Price\n";

        cout << "----------------------------------------------------\n";

        for (int i = 0; i < menuSize; i++)
        {
            menu[i].display();
        }

        cout << "====================================================\n";
    }

    MenuItem getMenuItem(int id) const { return menu[id - 1]; }
    bool validId(int id) const { return id >= 1 && id <= menuSize; }
};

// Generate Receipt
void generateReceipt(const Order &order, const Customer &customer)
{
    double subtotal = order.calculateSubtotal();
    double discountPercentage = customer.getDiscount();
    double discountAmount = subtotal * discountPercentage / 100.0;
    double finalTotal = subtotal - discountAmount;

    // Screen Output
    cout << "\n\n====================================================\n";
    printCentered("BREW & BITE RECEIPT", 52);
    cout << "====================================================\n";
    cout << "Customer Name: " << customer.getName() << endl;
    cout << "Phone Number:  " << customer.getPhone() << endl;
    cout << "Type:          " << customer.getCustomerType() << endl;
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < order.getItemCount(); i++)
    {
        MenuItem item = order.getItem(i);
        cout << left << setw(25) << item.getName() << "Rs. " << item.getPrice() << endl;
    }

    cout << "----------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Subtotal:        Rs. " << subtotal << endl;
    cout << "Discount (" << (int)discountPercentage << "%):  Rs. " << discountAmount << endl;
    cout << "TOTAL BILL:      Rs. " << finalTotal << endl;
    cout << "====================================================\n";
    printCentered("THANK YOU FOR VISITING!", 52);
    cout << "====================================================\n";

    // File Output
    ofstream file("receipt.txt");
    if (file.is_open())
    {
        file << "====================================================\n";
        file << "                BREW & BITE RECEIPT                 \n";
        file << "====================================================\n";
        file << "Customer Name: " << customer.getName() << endl;
        file << "Phone Number:  " << customer.getPhone() << endl;
        file << "Type:          " << customer.getCustomerType() << endl;
        file << "----------------------------------------------------\n";

        for (int i = 0; i < order.getItemCount(); i++)
        {
            MenuItem item = order.getItem(i);
            file << item.getName() << " - Rs. " << item.getPrice() << endl;
        }

        file << "----------------------------------------------------\n";
        file << fixed << setprecision(2);
        file << "Subtotal:        Rs. " << subtotal << endl;
        file << "Discount:        Rs. " << discountAmount << endl;
        file << "TOTAL BILL:      Rs. " << finalTotal << endl;
        file << "====================================================\n";
        file.close();

        cout << "\nReceipt saved to 'receipt.txt' successfully!\n";
    }
}

// MAIN
int main()
{
    Cafe cafe;
    Order order;
    int startChoice;

    cout << "====================================================\n";
    printCentered("WELCOME TO BREW & BITE", 52);
    cout << "====================================================\n";

    // Menu Display
    cafe.displayMenu();

    // Initial Prompt
    cout << "\nWhat would you like to do?\n";
    cout << "1. Place an Order\n";
    cout << "2. Exit\n";
    cout << "Enter choice (1 or 2): ";
    cin >> startChoice;

    if (startChoice == 2)
    {
        cout << "\nThank you for visiting Brew & Bite! Goodbye.\n";
        return 0;
    }
    else if (startChoice != 1)
    {
        cout << "\nInvalid choice. Program exiting...\n";
        return 0;
    }

    // Continuous Order Loop
    string addMore = "yes";
    while (addMore == "yes" || addMore == "YES" || addMore == "Yes" || addMore == "y" || addMore == "Y")
    {
        int itemID;
        cout << "\nEnter Item ID to order: ";
        cin >> itemID;

        if (cafe.validId(itemID))
        {
            order.addItem(cafe.getMenuItem(itemID));
        }
        else
        {
            cout << "Invalid Item ID! Try again.\n";
            continue;
        }

        cout << "\nDo you want to add another item? (yes/no): ";
        cin >> addMore;
    }

    if (order.isEmpty())
    {
        cout << "\nNo items ordered. Exiting program...\n";
        return 0;
    }

    // Customer Details
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name, phone;
    int typeChoice;

    cout << "\n----------------------------------------------------\n";
    printCentered("CUSTOMER DETAILS", 52);
    cout << "----------------------------------------------------\n";
    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Select Customer Type (1. Regular | 2. Premium): ";
    cin >> typeChoice;

    Customer *customer = nullptr;
    if (typeChoice == 2)
        customer = new PremiumCustomer(name, phone);
    else
        customer = new Customer(name, phone);

    // Bill and Receipt Generation
    generateReceipt(order, *customer);

    delete customer;
    return 0;
}