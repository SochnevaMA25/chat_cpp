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
    bool FileIsExist(string filePath);                                      //��������, ���� �� ����� ���� ������

    void record_file(string nickname, string login, string pass);           //������ � ����
    bool check_nick(string nickname);                                       //�������� ����
    bool check_login(string nickname, string login);                        //�������� ������
    bool check_pass(string nickname, string pass);                          //�������� ������
    string get_nickname();                                   //��������� ����
    void set_nickname(const char* nick);                                   // setter of ����

};
class CHat:public Client
{
    Companions m_comp;
public:
    //string m_ch_nick;                                                       //��� �����������   
    string m_message;                                                       //���������
    string m_companion;                                                     //����������    
    CHat(const Client& nick);
    CHat(string nick);
    CHat(string nick, string message, string companion);
    string get_message();                                                   //�������� ���������
    bool check_companion(string companion);                                 //��������, ���� �� ����� ����������
    void list_companions();
    void chat_message(string companion);                                    //����� � ������� ���������
    int sent_message(string companion, string message);
    int get_message(string& message);
};

