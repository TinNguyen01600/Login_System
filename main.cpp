#include "mylib.hh"

int main(void){
    SetConsoleOutputCP(65001);  // cmd to display utf-8 characters
    User *user = new User [LEN];
    loop(user, 0);
}