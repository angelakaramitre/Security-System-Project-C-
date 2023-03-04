#include <iostream>
#include <fstream> //this librery allows us to wrok in/with files
#include <sstream> // this libraby provides templates and types that enable interoperation between stream buffers and string object
#include <string> //

using namespace std;

int main() 
{
    int a, i=0;
    string text, old, password0, password1, password2, pass, username, age, word, word1;
    string creds[2], cp[2];

    cout <<"         Secutiry System " << endl;
    cout <<" ______________________________"<<endl<<endl;
    cout <<"|        1. Register           |"<<endl;
    cout <<"|        2. Login              |"<<endl;
    cout <<"|        3. Change password    |"<<endl;
    cout <<"|________4. End Program _______|"<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout <<" ______________________________"<<endl<<endl;
                cout <<"|        1. Register           |"<<endl;
                cout <<"|______________________________|"<<endl<<endl;
                cout <<"Please enter username: "; cin >>username;
                cout <<"Please enter password: "; cin >>password0;
                cout <<"Please enter age: "; cin >>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()) {
                    of1<<username<<"\n";
                    of1<<password0;
                    cout<<"Registration successful"<<endl;
                }

                break;
            }
            case 2:
            {
                i=0;
                cout <<" ______________________________"<<endl<<endl;
                cout <<"|         2. Login             |"<<endl;
                cout <<"|______________________________|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout <<"Please enter username: "; cin >>username;
                cout <<"Please enter password: "; cin >>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2, text)) {
                            istringstream iss(text);
                            iss>>word; 
                            creds[i]=word;
                            i++;
                        }
                        if(username==creds[0] && pass==creds[1])
                        {
                            cout<<endl<<endl;
                            cout<<"---Log in successful!---";
                            cout<<endl<<endl;

                            cout<<" Details: "<<endl;

                            cout<<"Username: "+ username<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout <<"|    1. Press 2 to Login              |"<<endl;
                            cout <<"|    2. Press 3 to change password    |"<<endl;
                            break;
                        }
                    
                    }
                }
                break;
            }
            case 3:{
                i=0;
                cout<<"------Change Pasaword------"<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password: ";
                cin>>old;
                if(of0.is_open()){
                    while(!of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        if(old==cp[1])
                        {
                            of0.close();
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open())
                            {
                                cout<<"Enter your new password: ";
                                cin>>password1;
                                cout<<"Enter your new password again: ";
                                cin>>password2;

                                if(password1==password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed succesfully."<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Passwords do not match."<<endl;
                                }

                            }
                        }
                        else{
                            cout<<"Please enter a valid password."<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:{
                cout<<"_______Thank  you!_______";
                break;
            }
            default:
            cout<<"Enter a valid choice";
        }
        
    }
    while(a!=4); 
    return 0;
}