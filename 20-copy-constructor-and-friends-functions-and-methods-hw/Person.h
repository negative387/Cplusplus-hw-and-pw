#pragma once
#include <iostream>

class Person {
private:
    char *fullName = nullptr;
    int age = 0;
    std::string gender = "Undefined";
    std::string phoneNumber = "Undefined";

public:
    Person();

    Person(const char *fullName, const int &age, const std::string &gender, const std::string &phoneNumber);

    ~Person();

    Person(const Person& other);

    Person& operator=(const Person& other);

    const char* getFullName() const;
    const int& getAge() const;
    const std::string& getGender() const;
    const std::string& getPhoneNumber() const;

    void setFullName(const char *fullName);
    void setAge(const int &age);
    void setGender(const std::string &gender);
    void setPhoneNumber(const std::string &phoneNumber);

    void print();
};
