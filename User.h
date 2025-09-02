#pragma once

// #include "./"

class User{
    private:

    protected:
    //creds
    string userId;
    string password;
    //data
    string name;
    string type;
    
    static int userCounter;

    public:
    User(){
        // this->userId = ("USER_" + to_string(userCounter++));
        getDetails();
    }
    User(string userId , string type)
    {
        this->userId = userId;
        getDetails();
        this->type = type;
    }


    //getter setter
    string getUserId(){
        return this->userId;
    }
    string getName(){
        return this->name;
    }
    bool matchPassword(string pass)
    {
        return password == pass;
    }
    string getType(){
        return this->type;
    }

    //worker
    void getDetails(){
        try{
            cout << "Enter Name : ";
            getline(cin ,this->name , '\n');
            while(this->name == "")
            {
                cout << "Enter correct Name : ";
            }
            string confirmPassword = "-1-1-1-1-1-1-1-1-";
            while(password != confirmPassword)
            {
                cout << "Enter Password : ";
                getline(cin , this->password , '\n');
                cout << "Re-enter Password : ";
                getline(cin , confirmPassword , '\n');

                if(password == confirmPassword) break;

                else {
                    cout << "Password did not match\n";
                }
            }
            this->password = confirmPassword;
            hr();
            cout << "User Id : " << this->userId << "\n";
            hr();
            
        }catch(...){
            cout << "Unknown error occured\n";
        }

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

int User::userCounter = 1;


class Student : public User{
    static int studentCounter;
    public:
    Student():User(makeId() , "student"){
    }
    void viewProfile(){
        hr();
        ahr("Student Profile");
        cout << "Name : " << this->name << "\n";
        cout << "UserId : " <<this->userId << "\n";
        cout << "Type : " << this->type << "\n";
        hr();
    }
    void editProfile(){
        this->getDetails();
    }
    string makeId()
    {
        return ("STUDENT_"+to_string(studentCounter++));
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

int Student::studentCounter = 1;


class Cashier : public User{
    static int CashierCounter;
    public:
    Cashier():User(makeId() , "cashier"){
    }
    void viewProfile(){
        hr();
        ahr("Student Profile");
        cout << "Name : " << this->name << "\n";
        cout << "UserId : " <<this->userId << "\n";
        cout << "Type : " << this->type << "\n";
        hr();
    }
    void editProfile(){
        this->getDetails();
    }
    string makeId()
    {
        return ("CASHIER_"+to_string(CashierCounter++));
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

int Cashier::CashierCounter = 1;