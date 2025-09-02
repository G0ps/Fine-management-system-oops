#pragma once

// #include ""
#include "./Db.h"
#include "./User.h"


class Register{
    private:
    Db databaseInstance;
    protected:
    
    public:
    Register(){

        string Option = "0";
        do {
            cout << "case 0 : Exit\ncase 1 : Cashier\ncase 2 : Student\n";

            getline(cin , Option , '\n');
            if(Option == "0") {break;}

            if(Option == "1")
            {
                Cashier *c = new Cashier();
                databaseInstance.addNewUser(c);
            }
            else{
                Student* s = new Student();
                databaseInstance.addNewUser(s);
            }
        }while(Option != "0");
        // User * u1 = new User();
        // databaseInstance.addNewUser(u1);
    }
};