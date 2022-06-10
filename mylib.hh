#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;
const int LEN = 50;

class User{
    char full_name[LEN];
    char email[LEN];
    char passwd[LEN];
    char username[LEN];
    char phone_no[LEN];
public:
    void set_data(char *full_name, char *email, char *passwd, char *username, char *phone_no);
    void print_data();
    void generate_username();
};

void User::set_data(char *full_name, char *email, char *passwd, char *username, char *phone_no){
    strcpy(this->full_name, full_name);
    strcpy(this->email, email);
    strcpy(this->passwd, passwd);
    strcpy(this->username, username);
    strcpy(this->phone_no, phone_no);
};

void User::generate_username(){
    // abc123@gmail.com
    for(int i = 0; i<strlen(this->email); i++){
        if (this->email[i] == '@')  break;
        else this->username[i] = this->email[i];
    }
}


void print_home_screen();