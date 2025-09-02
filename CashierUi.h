#pragma once

// #include "./"
#include "./Db.h"
#include "./User.h"


class CashierUi{
    private:
    Db databaseInstance;
    string cashierId;
    protected:
    
    public:
    CashierUi(string id){
        this->cashierId = id;

        string Option = "0";
        do {
            cout << "case 0 : Exit\ncase 2 : Add fine\ncase 3 : update Fine\ncase 4 : Delete Payment\n";
            getline(cin , Option , '\n');
            if(Option == "0") break;

            // if(Option == "1")
            // {
            //     vector<Student*> studentData = databaseInstance.getStudents();
            //     cout << "Students List : \n";
            //     for(auto it : studentData)
            //     {
            //         cout << it->getUserId() << "\n";
            //     }
            //     cout << "Enter StudentId : ";
            //     string studId;
            //     getline(cin , studId , '\n');

                
            //     pair<vector<Fine*> , vector<Fine*>> data;
            //     for(auto it : studentData)
            //     {
            //         if(it->getUserId() == studId)
            //         {
            //             data = databaseInstance.getStudentFineDetails(studId);
            //             break;
            //         }
            //     }
            //     hr();
            //     ahr("PENDING DETAILS");
            //     for(auto it : data.second)
            //     {
            //         it->explainSelf();
            //     }
            //     ahr("Finished DETAILS");
            //     for(auto it : data.first)
            //     {
            //         it->explainSelf();
            //     }
            //     hr();
            // }
            if(Option == "2")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                cout << "Students List : \n";
                hr();
                ahr("USER DETAILS");
                for(auto it : studentData)
                {
                    cout << it->getUserId() << "\n";
                }
                hr();
                cout << "Enter StudentId : ";
                string studId;
                getline(cin , studId , '\n');


                Fine* fine = new Fine(studId);
                databaseInstance.addFineToStudent(studId , fine , cashierId);


                cout << "Fine Added sucessfully\n";
            }

            else if(Option == "3")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                cout << "Students List : \n";
                hr();
                ahr("USER DETAILS");
                for(auto it : studentData)
                {
                    cout << it->getUserId() << "\n";
                }
                hr();
                cout << "Enter StudentId : ";
                string studId;
                getline(cin , studId , '\n');

                vector<Fine*> data;
                for(auto it : studentData)
                {
                    if(it->getUserId() == studId)
                    {
                        data = databaseInstance.getStudentFineDetailsSecond(studId);
                        break;
                    }
                }
                int size = data.size();
                hr();
                ahr("FINE DETAILS");
                for(int i=0; i<size; i++)
                {
                    cout << "ID : "<<i << "\n";
                    data[i]->explainSelf();
                }
                hr();

                string id;
                cout << "Enter Id to edit : ";
                getline(cin , id , '\n');
                int id_int = stoi(id);
                
                data[id_int]->getFineDataSecond(cashierId);
                hr();
                cout << "Fine Updated Sucessfully\n";
                hr();
            }
            else if(Option == "4")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                hr();
                ahr("Students List ");
                for(auto it : studentData)
                {
                    cout << it->getUserId() << "\n";
                }
                hr();
                cout << "Enter StudentId : ";
                string studId;
                getline(cin , studId , '\n');

                vector<Fine*> data;
                for(auto it : studentData)
                {
                    if(it->getUserId() == studId)
                    {
                        data = databaseInstance.getStudentFineDetailsSecond(studId);
                        break;
                    }
                }
                int size = data.size();
                hr();
                for(int i=0; i<size; i++)
                {
                    cout << "ID : "<<i << "\n";
                    data[i]->explainSelf();
                }
                hr();

                string id;
                cout << "Enter Id to edit : ";
                getline(cin , id , '\n');
                int id_int = stoi(id);

                databaseInstance.deleteFine(studId , id_int);
                hr();
                cout << "Fine Deleted Sucessfully\n";
                hr();
            }
            // else if(Option == "5")
            // {
            //     getFilter();
            // }
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

    void getFilter(){
        try{
            string Option = "0";
            do {
                cout << "case 1 : fine type\ncase 2 : student\ncase 3 : payments by date\ncase 4 : Filter specific fine type within date range\ncase 0 : Exit\n";

                getline(cin , Option , '\n');
                if(Option == "0") break;

                if(Option == "1")
                {
                    string type;
                    cout << "Enter Type :";
                    getline(cin , type , '\n');

                    vector<Fine*> ans = databaseInstance.getFineByType(type);
                    cout << "Data \n";
                    hr();
                    for(auto it : ans)
                    {
                        it->explainSelf();
                    }
                    hr();
                }
                else if(Option == "2")
                {
                    vector<Student*> studentData = databaseInstance.getStudents();
                    cout << "Students List : \n";
                    for(auto it : studentData)
                    {
                        cout << it->getUserId() << "\n";
                    }
                    cout << "Enter StudentId : ";
                    string studId;
                    getline(cin , studId , '\n');

                    vector<Fine*> data;
                    for(auto it : studentData)
                    {
                        if(it->getUserId() == studId)
                        {
                            data = databaseInstance.getStudentFineDetailsSecond(studId);
                            break;
                        }
                    }
                    int size = data.size();
                    for(int i=0; i<size; i++)
                    {
                        cout << "ID : "<<i << "\n";
                        data[i]->explainSelf();
                    }
                }
                else if(Option == "3")
                {
                    cout << "Enter start Date : ";
                    Date *d = new Date();
                    int start = d->numFormat;
                    cout << "Enter End date : ";
                    Date *d2 = new Date();
                    int end = d->numFormat;

                    auto ans = databaseInstance.fromToDate(start , end);

                    for(auto it : ans)
                    {   
                        it->explainSelf();
                    }
                }
                else{
                    string type;
                    cout << "Enter Type :";
                    getline(cin , type , '\n');

                    cout << "Enter start Date : ";
                    Date *d = new Date();
                    int start = d->numFormat;
                    cout << "Enter End date : ";
                    Date *d2 = new Date();
                    int end = d->numFormat;

                    vector<Fine*> ans = databaseInstance.getFineByType(type);
                    cout << "Data \n";
                    vector<Fine*> ans_2;
                    for(auto it : ans)
                    {
                        if(it->getDateAssigned() >= start && it->getDateAssigned() <= end){
                            ans_2.push_back(it);
                        }
                    }

                    hr();
                    ahr("FINE DETAILS");
                    for(auto it : ans_2)
                    {
                        it->explainSelf();
                    }
                    hr();
                }
            }while(Option != "0");
        }catch(...) 
        {
            cout << "Error \n";
        }
    }
};