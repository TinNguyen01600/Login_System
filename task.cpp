#include "mylib.hh"

void print_home_screen(){
    system("cls");
    cout << endl << "========== Welcome to authentication system ==========" << endl << endl;
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
}

void generate_username(char *email, char *username){
    // abc123@gmail.com
    for(int i = 0; i<strlen(email); i++){
        if (email[i] == '@')  break;
        else username[i] = email[i];
    }
}

void loop(User *user, int count){
    print_home_screen();
    cout << "Select an operation: ";
    char ch; cin >> ch;
    while(int(ch) < 49 || int(ch)>51){
        cout << "Invalid input!!! Please try again." << endl;
        cout << "Select an operation: ";cin >> ch;
    }
    int choice = int(ch) - 48;
    switch (choice)
    {
        case 1:{
            system("cls");
            char full_name[LEN], email[LEN], passwd[LEN];
            char username[LEN], phone_no[LEN];

            cout << "Enter your full name: ";
            cin.getline(full_name, LEN);
            cin.getline(full_name, LEN);
            cout << "Enter your email: ";
            cin.getline(email, LEN);
            cout << "Enter your telephone number: ";
            cin.getline(phone_no, LEN);
            break;
        }
        case 2:{
            break;
        }
        case 3:{
            delete user;
            cout << "\t\t\tGood Bye =))" << endl << endl;
            exit(0);
            break;
        }
    }
}