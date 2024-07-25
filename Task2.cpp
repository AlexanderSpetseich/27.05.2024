#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

// Функция для добавления нового контакта
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Введите имя: ";
    cin >> newContact.name;
    cout << "Введите телефон: ";
    cin >> newContact.phone;

    contacts.push_back(newContact);
}

// Функция для поиска контакта по имени
void searchByName(const vector<Contact>& contacts) {
    string name;
    cout << "Введите имя для поиска: ";
    cin >> name;

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Найден контакт: " << contact.name << ", Телефон: " << contact.phone << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Контакт с именем " << name << " не найден." << endl;
    }
}

// Функция для поиска контакта по номеру телефона
void searchByPhone(const vector<Contact>& contacts) {
    string phone;
    cout << "Введите номер телефона для поиска: ";
    cin >> phone;

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.phone == phone) {
            cout << "Найден контакт: " << contact.name << ", Телефон: " << contact.phone << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Контакт с номером телефона " << phone << " не найден." << endl;
    }
}

// Функция для изменения данных контакта
void editContact(vector<Contact>& contacts) {
    string name;
    cout << "Введите имя контакта для изменения: ";
    cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Введите новый телефон для " << contact.name << ": ";
            cin >> contact.phone;
            cout << "Данные успешно изменены." << endl;
            return;
        }
    }

    cout << "Контакт с именем " << name << " не найден." << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Поиск по имени\n";
        cout << "3. Поиск по номеру телефона\n";
        cout << "4. Изменить данные контакта\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            searchByName(contacts);
            break;
        case 3:
            searchByPhone(contacts);
            break;
        case 4:
            editContact(contacts);
            break;
        case 5:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}