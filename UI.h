
#pragma once

#include "./Register.h"
#include "./Login.h"
#include "./AdminUi.h"
#include "./CashierUi.h"
#include "./StudentUi.h"

class UI{
    private:
    
    protected:
    
    public:
    UI(){
        string Option = "0";
        do {

            cout << "case 1 : Register\ncase 2 : Login\ncase 0 : Exit\n";

            getline(cin , Option , '\n');
            if(Option == "0") break;

            if(Option == "1")
            {
                Register r;
            }
            else{
                Login l;

                string UserId = "0";
                cout << "0 in userId to break\n";

                string type = "-1";

                do {
                    cout << "Enter User Id : ";
                    getline(cin , UserId , '\n');
                    if(UserId == "0") break;
                    string password;
                    cout << "Enter PassWord : ";
                    getline(cin , password , '\n');

                    type = l.logUserIn(UserId , password);

                    if(type != "-1") break;
                }while(Option != "0");

                if(type == "admin")
                {
                    AdminUi u;
                }
                else{
                    if(type == "cashier")
                    {
                        CashierUi c(UserId); 
                    }
                    else if(type == "student"){
                        StudentUi st(UserId);

                    }
                }

            }

        }while(Option != "0");
    }
};