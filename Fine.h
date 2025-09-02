#pragma once

// #include "./"
#include "./Date.h"

class Fine{
    private:
    
    int fineAmount;
    string fineType;
    Date *dateAsigned;
    Date *dateOfPayment;
    string cashierId;

    string StudentId;

    bool paymentStatus; //true paid

    protected:
    
    public:
    
    Fine(string Id){
        this->cashierId = "ADMIN";
        this->StudentId = Id;
        this->paymentStatus = false;
        getFineData();
    }
    void getFineData()
    {
        try{
            cout << "Enter date : ";
            this->dateAsigned = new Date();
            cout << "Enter Fine Amount : ";
            string use;
            getline(cin , use , '\n');
            this->fineAmount = stoi(use);
            cout << "Enter Type :";
            getline(cin , this->fineType , '\n');
        }catch(...)
        {
            cout << "Error\n";
        }
        
    }
    void setCashierId(string id)
    {
        this->cashierId = id;
    }
    void getFineDataSecond()
    {
        try{
            cout << "Enter Fine Amount : ";
            string use;
            getline(cin , use , '\n');
            this->fineAmount = stoi(use);
            cout << "Enter Type :";
            getline(cin , this->fineType , '\n');
        }catch(...)
        {
            cout << "Error \n";
        }
    }
    int getFineAmount()
    {
        return this->fineAmount;
    }
    void getFineDataSecond(string id)
    {
        this->cashierId = id;
        try{
            cout << "Enter Fine Amount : ";
            string use;
            getline(cin , use , '\n');
            this->fineAmount = stoi(use);
            cout << "Enter Type :";
            getline(cin , this->fineType , '\n');
        }catch(...)
        {
            cout << "Error \n";
        }
    }
    void finishFine(Date* d)
    {
        this->paymentStatus = true;
        dateOfPayment = d;
        ahr("FINE FINISHED");
    }

    bool getStatus()
    {
        return this->paymentStatus;
    }

    void explainSelf(){
        if(this->paymentStatus) cout << StudentId << " : " <<fineType <<", dateAsigned : " <<dateAsigned->date << ", datePaid : "<< this->dateOfPayment->date <<" Casshier : "<<this->cashierId <<"\n";
        else {
            cout << StudentId << " : " <<fineType <<", dateAsigned : " <<dateAsigned->date <<" Casshier : "<<this->cashierId <<"\n";
        }
    }

    int getDateAssigned()
    {
        return this->dateAsigned->numFormat;
    }
    string getFineType()
    {
        return this->fineType;
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