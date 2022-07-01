#ifndef mylib_DEFINED
#define mylib_DEFINED
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <Windows.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;
const int LEN = 50;

#define ENTER 13
#define TAB 9
#define BCKSPC 8

class User{
    char full_name[LEN];
    char email[LEN];
    char passwd[LEN];
    char username[LEN];
    char phone_no[LEN];
public:
    void set_data(char *full_name, char *email, char *passwd, char *username, char *phone_no){
        strcpy(this->full_name, full_name);
        strcpy(this->email, email);
        strcpy(this->passwd, passwd);
        strcpy(this->username, username);
        strcpy(this->phone_no, phone_no);
    }
    void write_file(){
        ofstream file;
        file.open ("user.dat", ios_base::app);
        file.write((char*)this, sizeof(User));
        file.close();
    }
    User *search(char *username, char *passwd){
        return((strcmp(this->username, username) == 0) && (strcmp(this->passwd, passwd) == 0))?this : NULL;
    }
};


void print_home_screen();
void loop(User *user, int count);
void generate_username(char *email, char *username);
void get_password(char *passwd);    // this function is used to encode passwd to *
void check(char *string, int n);           // check if email is valid

#endif  // mylib_DEFINED