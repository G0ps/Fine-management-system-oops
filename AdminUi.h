#pragma once

// #include "./"
#include "./Db.h"
#include "./User.h"


class AdminUi{
    private:
    Db databaseInstance;
    protected:
    
    public:
    AdminUi(){
        

        string Option = "0";
        do {
            cout << "case 0 : Exit\ncase 1 : View StudentPayments\ncase 2 : Add fine\ncase 3 : update Fine\ncase 4 : Delete Payment\ncase 5 : filter\n";
            getline(cin , Option , '\n');
            if(Option == "0") break;

            if(Option == "1")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                cout << "Students List : \n";
                hr();
                ahr("STUDENT LIST");
                for(auto it : studentData)
                {
                    cout << it->getUserId() << "\n";
                }
                hr();
                cout << "Enter StudentId : ";
                string studId;
                getline(cin , studId , '\n');

                
                pair<vector<Fine*> , vector<Fine*>> data;
                for(auto it : studentData)
                {
                    if(it->getUserId() == studId)
                    {
                        data = databaseInstance.getStudentFineDetails(studId);
                        break;
                    }
                }
                hr();
                ahr("PENDING DETAILS");
                for(auto it : data.second)
                {
                    it->explainSelf();
                }
                cout << "\n";
                ahr("Finished DETAILS");
                for(auto it : data.first)
                {
                    it->explainSelf();
                }
                hr();
            }
            else if(Option == "2")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                cout << "Students List : \n";
                hr();
                ahr("STUDENT DETAIL")
                for(auto it : studentData)
                {
                    cout << it->getUserId() << "\n";
                }
                hr();
                cout << "Enter StudentId : ";
                string studId;
                getline(cin , studId , '\n');


                Fine* fine = new Fine(studId);
                databaseInstance.addFineToStudent(studId , fine);

                hr();
                cout << "Fine Added sucessfully\n";
                hr();
            }

            else if(Option == "3")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                cout << "Students List : \n";
                hr();
                ahr("STUDENT DETAIL")
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
                hr();
                int size = data.size();
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
                
                data[id_int]->getFineDataSecond();
                hr();
                cout << "Fine Updated Sucessfully\n";
                hr();
            }
            else if(Option == "4")
            {
                vector<Student*> studentData = databaseInstance.getStudents();
                cout << "Students List : \n";
                hr();
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
                hr();
                ahr("FINE DETAILS")
                int size = data.size();
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
            else if(Option == "5")
            {
                getFilter();
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
                    ahr("FINE DETAILS")
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
                    hr();
                    ahr("FINE DETAILS");
                    int size = data.size();
                    for(int i=0; i<size; i++)
                    {
                        cout << "ID : "<<i << "\n";
                        data[i]->explainSelf();
                    }
                    hr();
                }
                else if(Option == "3")
                {
                    cout << "Enter start Date : ";
                    Date *d = new Date();
                    int start = d->numFormat;
                    cout << "Enter End date : ";
                    Date *d2 = new Date();
                    int end = d2->numFormat;

                    auto ans = databaseInstance.fromToDate(start , end);
                    // cout << "START : "<<start << " END : "<<end << "\n";
                    hr();
                    ahr("FINE DETAILS");
                    for(auto it : ans)
                    {   
                        it->explainSelf();
                    }
                    hr();
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
                    int end = d2->numFormat;

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