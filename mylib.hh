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
#include <fcntl.h>  
#include <io.h>
#include <locale>
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
    void print_data();
};


void print_home_screen();
void loop(User *user, int count);
void generate_username(char *email, char *username);
void get_password(char *passwd);    // this function is used to encode passwd to *