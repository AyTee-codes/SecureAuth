#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct User {
    string username;
    string password;
};

int main(){

    vector<User> users;

    int choice;
     
    do{

        cout<<"\n================================";
        cout<<"\n           SECUREAUTH           ";
        cout<<"\n================================";

        cout<<"\n1. Register"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. View Users"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>> choice;

        switch(choice) {
            case 1:
                cout<<"Registration selected."<<endl;
                break;
            case 2:
                cout<<"Login Successfull."<<endl;
                break;
            case 3:
                cout<<"View Users Selected."<<endl;
                break;
            case 4:
                cout<<"Exiting SecureAuth..."<<endl;
                break;

            default:
            cout<<"Invalid choice. Try again."<< endl;
        }
    }while(choice !=4);
    return 0;
}