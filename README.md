Fine Management System (OOPs Project)

> ⏱ Built in just **3 hours** — this project gave me solid hands-on experience with **Object Oriented Programming** and its principles (encapsulation, inheritance, polymorphism).

📌 Requirements

- [g++ Compiler](https://gcc.gnu.org/) (C++17 or higher recommended)  
- A terminal/command line interface (Linux, macOS, or Windows with MinGW/WSL)  

To compile and run:

bash
g++ main.cpp -o fine_mgmt
./fine_mgmt


🚀 Flow of the Program

The system is menu-driven and proceeds in the following order:

UI Layer (UI.h)

Start with options to Register or Login.

Register / Login

Registration creates new users (Admin, Cashier, Student).

Login validates user credentials.

Role-Specific Dashboards

Admin (AdminUi.h)

View all student payments

Add / Update / Delete fines

Apply filters (by type, student, date ranges, etc.)

Cashier (CashierUi.h)

Add fines to students

Update fines

Delete payments

Student (StudentUi.h)

View and edit profile

View transactions (pending/finished)

Pay fines

📂 Project Structure

UI.h → Entry point for register/login flow

User.h → Base class (User) with derived classes (Student, Cashier)

AdminUi.h → Admin dashboard and controls

CashierUi.h → Cashier dashboard and controls

StudentUi.h → Student dashboard and controls

Other helpers: Db.h, Fine.h, Date.h (database simulation, fines, date handling)

✨ Key OOP Principles Practiced

Encapsulation → Private/protected members with controlled access

Inheritance → User as base class; Student and Cashier extend it

Polymorphism → Overriding methods like viewProfile, editProfile

Abstraction → Separate UI logic for different roles

📝 Notes

Built quickly as a hands-on OOPs project (~3 hours).

Strengthened my understanding of class design, role-based separation, and interactive CLI menus.

Can be extended into a DB-backed full application.
