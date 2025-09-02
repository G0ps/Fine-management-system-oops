#pragma once

// #include "./"

class Date{
    private:
    
    

    protected:
    
    public:
    int day;
    int month;
    int year;
    string date;
    int numFormat;
    Date(){ 
        getDateInfo();
        numFormat = this->day*this->month*this->year;
        date = to_string(day)+"/"+to_string(month) +"/"+to_string(year); 
    }

    void getDateInfo()
    {
        cout << "Enter Day : ";
        string day;
        getline(cin , day , '\n');
        this->day = stoi(day);
        cout << "Enter Month : ";
        string month;
        getline(cin , month , '\n');
        this->month = stoi(month);
        cout << "Enter Year : ";
        string year;
        getline(cin , year , '\n');
        this->year = stoi(year);
    }
};