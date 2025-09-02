#pragma once

// #include "./"
#include "./Db.h"
#include "./User.h"
#include "./Fine.h"

class StudentUi{
    private:
    string userId;
    Student* StudentData;

    Db databaseInstance;
    protected:
    
    public:
    StudentUi(){
        
    }
    StudentUi(string userId){
        this->userId = userId;
        this->StudentData = static_cast<Student*>(databaseInstance.getUserById(userId));

        string Option = "0";
        do {
            cout << "case 0 : Exit\ncase 1 : View profile\ncase 2 : Edit profile\ncase 3 : View personal transactions\ncase 4 : View current balance in the fund\nOption 5 : PayFine\n";
            getline(cin , Option , '\n');
            if(Option == "0") break;

            if(Option == "1")
            {
                StudentData->viewProfile();
            }
            else if(Option == "2")
            {
                StudentData->editProfile();
                cout << "SUCESSFULLY EDITED\n";
            }

            else if(Option == "3")
            {
                cout << "Transaction : \n";
                hr();
                pair<vector<Fine*>,vector<Fine*>> ans = databaseInstance.getStudentFineDetails(userId);
                for(auto it : ans.first)
                {
                    it->explainSelf();
                }
                hr();
            }
            else if(Option == "4")
            {
                int total = 0;
                cout << "Transaction Pending: \n";
                hr();
                pair<vector<Fine*>,vector<Fine*>> ans = databaseInstance.getStudentFineDetails(userId);
                for(auto it : ans.second)
                {
                    it->explainSelf();
                    total += it->getFineAmount();
                }
                hr();

                cout << "TOTAL PENDING : " << total << "\n";
            }
            else if(Option == "5")
            {
                cout << "Transaction Pending: \n";
                hr();
                pair<vector<Fine*>,vector<Fine*>> ans = databaseInstance.getStudentFineDetails(userId);
                int size = ans.second.size();
                for(int i=0; i<size; i++)
                {
                    cout << "ID : "<<i << "\n";
                    ans.second[i]->explainSelf();
                }
                hr();

                string ind_str;
                cout << "Enter Id to pay : ";
                getline(cin , ind_str , '\n');

                int ind = stoi(ind_str);
                cout << "Enter Date\n";
                Date *d = new Date();
                ans.second[ind]->finishFine(d);
            }
        }while(Option != "0");
    }

    void hr()
    {
        cout << "--------------------------------------------------------------------\n";
    }
    void ahr(string str)
    {
        cout << "********************" << (str) << "**************************\n";
}
};