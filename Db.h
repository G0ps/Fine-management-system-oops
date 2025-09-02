#pragma once

// #include "./"
#include "./User.h"
#include "./Fine.h"

class Db{
    private:
    string AdminUserId = "gopinath";
    string AdminPassword = "123";
    protected:
    
    public:
    
    static map<string , User*> userData;
    static map<string , vector<Fine*>> userToFine;

    Db(){
    }

    void addNewUser(User * u1)
    {
        userData[u1->getUserId()] = u1;
        cout << "User added sucessfully\n";
    }

    User* getUserById(string id)
    {
        if(userData.find(id) == userData.end())
        {
            cout << "Not a valid UId\n";
            return NULL;
        }
        return userData[id];
    }

    string getAdminUser(){
        return this->AdminUserId;
    }
    string getAdminPassword(){
        return this->AdminPassword;
    }

    vector<Fine*> fineOfStudentId(string Id)
    {
        return userToFine[Id];
    }

    vector<Student*> getStudents()
    {
        vector<Student*> ans;
        for(auto it : userData)
        {
            if(it.second->getType() == "student")
            {
                ans.push_back(static_cast<Student*>(it.second));
            }
        }
        return ans;
    }

    pair<vector<Fine*> , vector<Fine*>> getStudentFineDetails(string id){
        vector<Fine*> paid;
        vector<Fine*> pending;

        for(auto it : userToFine[id])
        {
            if(it->getStatus())
            {
                paid.push_back(it);
            }
            else pending.push_back(it);
        }

        return {paid , pending};
    }
    vector<Fine*> getStudentFineDetailsSecond(string id){
        vector<Fine*> ans;
        for(auto it : userToFine[id])
        {
            if(!it->getStatus())
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
    void deleteFine(string Id , int index)
    {
        vector<Fine*> ans;
        int size = userToFine[Id].size();
        for(int i=0; i<size; i++)
        {
            if(i == index) continue;
            ans.push_back(userToFine[Id][i]);
        }

        userToFine[Id] = ans;
    }
    void addFineToStudent(string id , Fine* f)
    {
        userToFine[id].push_back(f);
    }
    void addFineToStudent(string id , Fine* f , string cashierId)
    {
        userToFine[id].push_back(f);
        f->setCashierId(cashierId);
    }
    

    vector<Fine*> fromToDate(int start , int end)
    {
        vector<Fine*> ans;
        for(auto it : userToFine)
        {
            for(auto it2 : it.second)
            {
                if(it2->getDateAssigned() >= start && it2->getDateAssigned() <= end)
                {
                    ans.push_back(it2);
                }
            }
        }

        return ans;
    }
     vector<Fine*> getFineByType(string type)
    {
        vector<Fine*> ans;
        for(auto it : userToFine)
        {
            for(auto it2 : it.second)
            {
                if(type == it2->getFineType())
                {
                    ans.push_back(it2);
                }
            }
        }

        return ans;
    }
};

map<string, User*> Db::userData;
map<string , vector<Fine*>> Db::userToFine;