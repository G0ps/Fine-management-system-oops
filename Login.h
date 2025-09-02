#pragma once

// #include "./"
#include "./Db.h"
#include "./User.h"

class Login{
    private:
    Db databaseInstance;
    protected:
    
    public:
    Login(){
    }

    string logUserIn(string userId , string password)
    {
        if(userId == databaseInstance.getAdminUser())
        {
            if(password != databaseInstance.getAdminPassword()) return "-1";
            return "admin";
        }
        User * u = databaseInstance.getUserById(userId);
        if(u == NULL)
        {
            return "-1";
        }
        if(u->matchPassword(password))
        {
            return u->getType();
        }
        else{
            cout << "Wrong password\n";
            return "-1";
        }

        return "-1";
    }
};