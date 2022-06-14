#include "mylib.hh"

void print_home_screen(){
    system("cls");
    cout << endl << "========== Welcome to authentication system ==========" << endl << endl;
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
}

void get_string(char string[], int len){
    cin.getline(string, len);
    cin.getline(string, len);
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

            cout << "Enter the customer's name: ";
            get_string(full_name, LEN);
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