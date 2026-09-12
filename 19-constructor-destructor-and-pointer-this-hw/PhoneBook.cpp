#include "PhoneBook.h"
#include <cstring>
#include <fstream>


PhoneBook::PhoneBook() : contacts(nullptr), contactsCount(0) {}

PhoneBook::~PhoneBook() { delete[] contacts; }

void PhoneBook::addContact(const Contact &contactInput) {
    Contact *tempArray = new Contact[contactsCount + 1];

    for (int count = 0; count < contactsCount; ++count) {
        tempArray[count].setFullName(contacts[count].getFullName());
        tempArray[count].setHomePhone(contacts[count].getHomePhone());
        tempArray[count].setWorkPhone(contacts[count].getWorkPhone());
        tempArray[count].setCellPhone(contacts[count].getCellPhone());
        tempArray[count].setAddInfo(contacts[count].getAddInfo());
    }
    tempArray[contactsCount].setFullName(contactInput.getFullName());
    tempArray[contactsCount].setHomePhone(contactInput.getHomePhone());
    tempArray[contactsCount].setWorkPhone(contactInput.getWorkPhone());
    tempArray[contactsCount].setCellPhone(contactInput.getCellPhone());
    tempArray[contactsCount].setAddInfo(contactInput.getAddInfo());
    delete[] contacts;
    contacts = tempArray;
    contactsCount++;
}

void PhoneBook::deleteContact(const char *fullNameInput) {
    int indexToRemove = -1;

    for (int count = 0; count < contactsCount; ++count) {
        if (strcmp(contacts[count].getFullName(), fullNameInput) == 0) {
            indexToRemove = count;
            break;
        }
    }
    if (indexToRemove == -1) {
        std::cout << "Абонента з ПІБ: \"" << fullNameInput << "\" НЕ ЗНАЙДЕНО\n\n";
        return;
    }
    Contact* tempArray = new Contact[contactsCount - 1];
    int tempIndex = 0;

    for (int count = 0; count < contactsCount; ++count) {
        if (count != indexToRemove) {
            tempArray[tempIndex].setFullName(contacts[count].getFullName());
            tempArray[tempIndex].setHomePhone(contacts[count].getHomePhone());
            tempArray[tempIndex].setWorkPhone(contacts[count].getWorkPhone());
            tempArray[tempIndex].setCellPhone(contacts[count].getCellPhone());
            tempArray[tempIndex].setAddInfo(contacts[count].getAddInfo());
            tempIndex++;
        }
    }
    delete[] contacts;
    contacts = tempArray;
    contactsCount--;
    std::cout << "Абонента \"" << fullNameInput << "\" успiшно видалено!\n\n";
}

void PhoneBook::searchContact(const char* fullNameInput) {
    bool isFound = false;

    for (int count = 0; count < contactsCount; ++count) {
        if (strcmp(contacts[count].getFullName(), fullNameInput) == 0) {
            contacts[count].print();
            isFound = true;
        }
    }
    if (!isFound) { std::cout << "Нічого не знайдено :(\n\n"; }
}

void PhoneBook::printAll() const {
    if (contactsCount == 0) {
        std::cout << "Телефонна книга порожня :(\n\n";
        return;
    }
    std::cout << "    ===УСІ АБОНЕНТИ (" << contactsCount << ")===\n";
    for (int count = 0; count < contactsCount; ++count) {
        contacts[count].print();
    }
}

void PhoneBook::saveToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Помилка вiдкриття файлу для запису :(\n\n";
        return;
    }

    file << contactsCount << '\n';
    for (int count = 0; count < contactsCount; ++count) {

        file << contacts[count].getFullName() << '\n'
             << contacts[count].getHomePhone() << '\n'
             << contacts[count].getWorkPhone() << '\n'
             << contacts[count].getCellPhone() << '\n'
             << contacts[count].getAddInfo() << '\n';
    }
    file.close();
    std::cout << "Телефонна книга у файлі \"" << filename << "\" успішно збережена!\n\n";
}

void PhoneBook::loadFromFile(const std::string& filename) {
    int countInFile = 0;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Помилка вiдкриття файлу для читання :(\n\n";
        return;
    }
    delete[] contacts;
    contacts = nullptr;
    contactsCount = 0;
    file >> countInFile;
    file.ignore();
    std::string fullNameSave, homePhoneSave, workPhoneSave, cellPhoneSave, addInfoSave;

    for (int count = 0; count < countInFile; ++count) {
        std::getline(file, fullNameSave);
        std::getline(file, homePhoneSave);
        std::getline(file, workPhoneSave);
        std::getline(file, cellPhoneSave);
        std::getline(file, addInfoSave);
        Contact tempArray(fullNameSave.c_str(), homePhoneSave, workPhoneSave, cellPhoneSave, addInfoSave);
        addContact(tempArray);
    }
    file.close();
}
