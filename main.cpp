#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct User {
    string username;
    string password;
};

bool usernameExist(const vector<User>& users, string username) {

    for(const User& user : users){

        if(user.username == username){
            return true;
        }
    }
    return false;
}

bool loginUser(const vector<User>& users, string username, string password) {
    for (const User& user : users){

        if(user.username == username &&
            user.password == password) {
                return true;
            }
    }
    return false;
}

void registerUser(vector<User>& users){
                string username;
                string password;

                cout<<"\nEnter username: ";
                cin>> username;
                cout<<"Enter password: ";
                cin>> password;

                if(usernameExist(users, username)) {
                   cout<<"\nUsername already exists!"<<endl;     
                }else{
                    
                    User newUser;

                    newUser.username = username;
                    newUser.password =password;
                    
                    users.push_back(newUser);
                    cout<<"\nRegistration successfull"<<endl;
                }
}

void viewUsers(const vector<User>& users){

    cout << "\n================================";
    cout << "\n        REGISTERED USERS";
    cout << "\n================================\n";
    if(users.empty()){

        cout<<"No users registered yet!"<<endl;
    }else{
        
        int count = 1;

        for(const User& user : users) {

            cout << count << ". "<< user.username <<endl;

            count ++;
        }
        cout<<"\nTotal registered users: "<<users.size() <<endl;
    }
}

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
            case 1: {
                registerUser(users);
                break;
            }
                
            case 2:{
                string username;
                string password;

                cout<<"\nEnter username: ";
                cin >> username;

                cout<<"Enter password: ";
                cin>>password;
                if(loginUser(users, username, password)){
                    cout<<"\nLogin Successfull"<<endl;
                }else{

                    cout<<"\nInvalid usrname or password!"<<endl;
                }break;
            }
                
            case 3:
                viewUsers(users);
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