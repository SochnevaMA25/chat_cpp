
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include <conio.h>


using namespace std;

int main()
{

    setlocale(LC_ALL, "rus");
    string nick = "";
    
    string login = "";
    string pass = "";
    cout << "Введите ник: ";
    cin >> nick;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> pass;
    Client cl(nick, login, pass);
    CHat chat(nick);
    string s = "";    
    bool isBreak = false;
    while (!isBreak)
    {
        string s = "";
        cout << "Для остановки чата введите <stop>, а для продолжения нажмите любую букву " << endl;
        cin >> s;
        if (s == "stop")
        {
            isBreak = false;
        }
        string message = "";
        if (chat.get_message(message) == 1)
        {
            cout << "Вам пришли сообщения! " << endl;
            cout << message << endl;
        }
        cout << "Введите кому отправить сообщение (для отправки всем пользователям введите ALL): ";
        string comp = "";
        cin >> comp;
        cout << "Введите сообщение: ";
        string message_1 = "";
        string message_2 = "";
        cin >> message_1;

        getline(cin, message_2);
        string message_3 = message_1 + message_2;
        chat.sent_message(comp, message_3);
    }

    system("pause");
    return 0;
}