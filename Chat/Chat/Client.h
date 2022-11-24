#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

const char g_pass[] = "Pass: ";
const char g_nick[] = "Login: ";
const char g_file[] = "Users.txt";
const char g_nickname[] = "Nick: ";

using namespace std;
typedef vector <string> Companions;

class Client
{
private:
	const char* m_pass[20];                                                 //pass
	string m_login;                                                         //login
public:
	string m_nickname;                                                      //nickname
    Client();
    Client(string nickname, string login, string pass);
    bool FileIsExist(string filePath);                                      //проверка, есть ли такой файл вообще

    void record_file(string nickname, string login, string pass);           //запись в файл
    bool check_nick(string nickname);                                       //проверка ника
    bool check_login(string nickname, string login);                        //проверка логина
    bool check_pass(string nickname, string pass);                          //проверка пароля
    string get_nickname();                                   //получение ника
    void set_nickname(const char* nick);                                   // setter of ника

};
class CHat:public Client
{
    Companions m_comp;
public:
    //string m_ch_nick;                                                       //ник отправителя   
    string m_message;                                                       //сообщение
    string m_companion;                                                     //получатель    
    CHat(const Client& nick);
    CHat(string nick);
    CHat(string nick, string message, string companion);
    string get_message();                                                   //отправка сообщения
    bool check_companion(string companion);                                 //проверка, есть ли такой получатель
    void list_companions();
    void chat_message(string companion);                                    //вывод в консоль сообщений
    int sent_message(string companion, string message);
    int get_message(string& message);
};

