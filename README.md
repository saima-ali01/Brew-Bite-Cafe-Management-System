# ☕ Brew & Bite Cafe Management System
A console-based Cafe Management System created in C++ using Object-Oriented Programming (OOP).
## 📌 About the Project
Brew & Bite is a C++ console application designed to simulate a simple cafe management system.
The system allows users to:
- View the cafe menu
- Place orders
- Add multiple items to an order
- View ordered items in the generated receipt
- Calculate the total bill
- Generate a formatted receipt
- Save the generated receipt to a text file
## 🛠️ Technologies Used
- C++
- Object-Oriented Programming (OOP)
- File Handling
- Standard C++ Libraries
- Input/Output Formatting
## 🎯 Features
### ☕ Cafe Menu
Displays available food and beverages with their:
- Item ID
- Name
- Category
- Price
### 🛒 Order Management
Customers can select items using their Item IDs and add multiple items to their order.
### 👤 Customer Management
The system collects:
- Customer name
- Phone number
- Customer type
Customers can choose between:
- Regular Customer
- Premium Customer
### 💰 Billing System
The system automatically calculates:
- Subtotal
- Discount
- Final bill
Premium customers receive a 10% discount.
### 🧾 Receipt Generation
A formatted receipt is displayed on the screen after the order is completed.
The receipt includes:
- Customer information
- Ordered items
- Subtotal
- Discount
- Total bill
### 📁 File Handling
The generated receipt is saved to a text file named:
`receipt.txt`
## 📚 OOP Concepts Used
This project demonstrates the following Object-Oriented Programming concepts:
- **Classes and Objects**
- **Encapsulation**
- **Inheritance**
- **Polymorphism**
- **Constructors**
- **Virtual Functions**
- **Function Overriding**
### Classes Used
The project contains the following classes:
- `MenuItem` - Stores menu item information.
- `Customer` - Stores customer information and provides customer-related functionality.
- `PremiumCustomer` - Inherits from `Customer` and provides a 10% discount.
- `Order` - Manages ordered menu items and calculates the subtotal.
- `Cafe` - Manages the cafe menu and validates menu selections.
## 🚀 How to Run
- Download or clone this repository.
- Open `CafeManagementProject.cpp` in a C++ IDE.
- Compile the program.
- Run the executable.
## 👩‍💻 Author
**Saima Ali**

Computer Science Student
