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
        if (email[i] == '@')  {username[i] = '\0'; break;}
        else username[i] = email[i];
    }
}

void get_password(char* passwd){
    char ch;
    int i = 0;
    while(1){
        ch = getch();
        if(ch == ENTER || ch == TAB){
            passwd[i] = '\0';
            break;
        }
        else if(ch == BCKSPC){
            if(i > 0){
                i--;
                cout << "\b \b"; 
                // for ex: abc|
                // \b moves the cursor to the left ab|c
                // space char replaces 'c' (ab |)
                // \b moves the cursor ab|
            }
        }
        else {
            passwd[i++] = ch;
            cout << "*";
        }
    }
}

void check(char *string, int n){
    if (n == 1){
        auto x = std::string(string);
        bool found1 = x.find("@") != std::string::npos;
        bool found2 = x.find(".") != std::string::npos;
        while(found1 == false || found2 == false){
            cout << "\t х Invalid Email х";
            cout << "\nRe-enter your email:\t\t";
            cin.getline(string, LEN);
            x = std::string(string);
            found1 = x.find("@") != std::string::npos;
            found2 = x.find(".") != std::string::npos;
        }
    }
    else if (n == 2){
        int valid = 1;
        for (int i = 0; i<strlen(string); i++){
            if((int(string[i]) < 48) || (int(string[i]) > 57))  {valid = 0; break;}
        }
        if(valid == 0){
            cout << "\t х Invalid Phone Number х ";
            cout << "\nRe-enter your telephone number:\t";
            cin.getline(string, LEN);
            check(string, 2);
        }
    }
}

int check_continue(){
    char ch;
    cout << endl << endl << "Do you want to continue? [y/n]: "; cin >> ch;
    while(int(ch)!=121 && int(ch)!=110){
        cout << "Invalid input!!! Please try again." << endl;
        cout << "Do you want to continue? [y/n]: ";cin >> ch;
    }
    if(ch == 'y')   return 1;
    else{
        cout << "\t\t\tGood Bye =))" << endl << endl; 
        exit(0);
        return 0;
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

            cout << "Enter your full name:\t\t";
            cin.getline(full_name, LEN);
            cin.getline(full_name, LEN);

            cout << "Enter your email:\t\t";
            cin.getline(email, LEN);
            check(email, 1);

            generate_username(email, username);

            cout << "Enter your telephone number:\t";
            cin.getline(phone_no, LEN);
            check(phone_no, 2);
            

            cout << "Enter your password:\t\t";
            get_password(passwd);
            char passwd2[LEN] = "";
            while(strcmp(passwd, passwd2) != 0){
                cout << "\nConfirm your password:\t\t";
                get_password(passwd2);
                if (strcmp(passwd, passwd2) != 0)   {cout << "\tх";  Beep(750, 300);}
                else break;
            }
            user[count].set_data(full_name, email, passwd, username, phone_no);
            cout << "\n\nUser registration success. Your user name is " << username;
            user[count].write_file();
            cout << "\nUser data saved in file 'user.dat'.\n";

            break;
        }
        case 2:{
            system("cls");
            int userFound = 0;
            ifstream file;
            file.open ("user.dat", ios_base::app);
            while(userFound == 0){
                char username[LEN], passwd[LEN];
                cout << "Enter your username:\t\t";
                cin.getline(username, LEN);
                cin.getline(username, LEN);
                cout << "Enter your password:\t\t";
                get_password(passwd);
                
                User temp, *temp1;
                while(file.read((char*)&temp, sizeof(User))){
                    temp1 = temp.search(username, passwd);
                    if (temp1 != NULL){
                        temp1->print_data();
                        userFound = 1;
                        break;
                    }
                }
                if (userFound) break;
                else{
                    char ch;
                    cout << "\nNo user found. Try again? [y/n]: "; cin >> ch;
                    while(int(ch)!=121 && int(ch)!=110){
                        cout << "Invalid input!!! Please try again." << endl;
                        cout << "Try again? [y/n]: ";cin >> ch;
                    }
                    if(ch == 'n')   break;   
                }
            }    
            file.close();
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