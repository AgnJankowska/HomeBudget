#include "User.h"

void User::setId (int newId) {
    id = newId;
}

void User::setFirstName (string newFirstName) {
    firstName = newFirstName;
}

void User::setSecondName (string newSecondName) {
    secondName = newSecondName;
}

void User::setLogin (string newLogin) {
    login = newLogin;
}

void User::setPassword (string newPassword) {
    password = newPassword;
}

int User::getId() {
    return id;
}

string User::getFirstName() {
    return firstName;
}

string User::getSecondName () {
    return secondName;
}

string User::getLogin() {
    return login;
}

string User::getPassword () {
    return password;
}
