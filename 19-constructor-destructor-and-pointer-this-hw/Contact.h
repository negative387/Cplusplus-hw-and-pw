#pragma once
#include <iostream>

class Contact {

private:
    char *fullName;
    std::string homePhone = "Undefined";
    std::string workPhone = "Undefined";
    std::string cellPhone = "Undefined";
    std::string addInfo = "Undefined";

public:
    Contact();

    Contact(const char *fullNameInput, const std::string &homePhoneInput,
            const std::string &workPhoneInput, const std::string &cellPhoneInput, const std::string &addInfoInput);

    ~Contact();

    const char* getFullName() const;
    const std::string &getHomePhone() const;
    const std::string &getWorkPhone() const;
    const std::string &getCellPhone() const;
    const std::string &getAddInfo() const;

    void setFullName(const char *fullNameInput);
    void setHomePhone(const std::string &homePhoneInput);
    void setWorkPhone(const std::string &workPhoneInput);
    void setCellPhone(const std::string &cellPhoneInput);
    void setAddInfo(const std::string &addInfoInput);

    void print() const;
};