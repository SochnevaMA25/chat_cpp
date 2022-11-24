#include "Client.h"
#include <fstream>
#include <string>
using namespace std;

Client::Client() {};
CHat::CHat(string nick, string message, string companion)
    :  m_message(message), m_companion(companion)
{
    chat_message(m_companion);
}

CHat::CHat(string nick)
{
    set_nickname(nick.c_str());
}
Client::Client(string nickname, string login, string pass)
    : m_nickname(nickname), m_login(login), m_pass()
{
    if (check_nick(m_nickname) == true)
    {
        if (check_login(m_nickname, login) == true)
        {
            if (check_pass(m_nickname, pass) == true)
            {
                cout << "Вы уже зарегестрированы! " << endl;
                cout << "Выполнен вход в аккаунт " << get_nickname() << endl;
            }
            else
            {
                cout << "Неверный пароль! " << endl;
            }
        }
        else
        {
            cout << "Неверный логин! " << endl;
        }
    }
    else
    {
        record_file(m_nickname, login, pass);
    }
}
bool Client::FileIsExist(string filePath)
{
    bool isExist = false;
    ifstream fin(filePath.c_str());

    if (fin.is_open())
        isExist = true;

    fin.close();
    return isExist;
}
void Client::record_file(string nickname, string login, string pass)
{
    ofstream fout;
    fout.open(g_file,ios::app); //
    fout << g_nickname << nickname << ",";
    fout << g_nick << login << ",";
    fout << g_pass << pass << ";" << endl; // 
    fout.close(); // 
}
bool Client::check_nick(string nickname)
{
    ifstream fin(g_file);
    char line[60] = "";
    char c_nick[15];
    int size = 0;

    while (fin.getline(line, 60))
    {
        const char* type_str = strstr(line,g_nickname);
        const char* type_str1 = strstr(type_str, ",");
        if (type_str && type_str1)
        {
            type_str = type_str + strlen(g_nickname);
            size = strlen(type_str) - strlen(type_str1);
            strncpy_s(c_nick, type_str, size);
            c_nick[size] = 0;
            break;
        }
    }
    const char* p1 = nickname.c_str();
    if (strcmp(c_nick, p1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    fin.close();
}
bool Client::check_login(string nickname, string login)
{
    ifstream fin(g_file);
    char line[60] = "";
    char c_login[15];
    int size = 0;
   
    while (fin.getline(line, 60))
    {
        const char* type_str = strstr(line, nickname.c_str());
        if (type_str)
        {
            const char* type_str2 = strstr(type_str, g_nick);
            type_str2 = type_str2 + strlen(g_nick);
            const char* type_str3 = strstr(type_str2,",");
            size = strlen(type_str2) - strlen(type_str3);
            strncpy_s(c_login, type_str2, size);
            c_login[size] = 0;
            break;
        }
    }

    const char* p1 = login.c_str();
        
    if (strcmp(c_login, p1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    fin.close();
}

bool Client::check_pass(string nickname, string parol)
{
    char line[60] = "";
    ifstream fin(g_file);
    char c_pass[15];
    int size = 0;

    while (fin.getline(line, 60))
    {
        const char* type_str = strstr(line, nickname.c_str());
        if (type_str)
        {
            const char* type_str2 = strstr(type_str, g_pass);
            type_str2 = type_str2 + strlen(g_pass);
            const char* type_str1 = strstr(type_str2, ";");
            size = strlen(type_str2) - strlen(type_str1);
            strncpy_s(c_pass, type_str2, size);
            c_pass[size] = 0;
            break;
        }
    }
    const char* p1 = parol.c_str();
    fin.close();
    if (strcmp(c_pass, p1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

    fin.close(); // закрываем файл

}

void Client::set_nickname(const char* nick)
{
    m_nickname = nick;
}

string Client::get_nickname()
{
    return m_nickname;
}
string CHat::get_message()
{
    return m_message;
}
bool CHat::check_companion(string companion)
{
    ifstream fin(g_file);
    char line[60] = "";
    while (fin.getline(line, 60))
    {
        const char* type_str = strstr(line, companion.c_str());
        if (type_str)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}
void CHat::list_companions()
{
    ifstream fin(g_file);
    char c_nick[15];
    int size = 0;
    char line[60] = "";
    while (fin.getline(line, 60))
    {
        const char* type_str = strstr(line, g_nickname);
        const char* type_str1 = strstr(type_str, ",");
        if (type_str && type_str1)
        {
            type_str = type_str + strlen(g_nickname);
            size = strlen(type_str) - strlen(type_str1);
            strncpy_s(c_nick, type_str, size);
            c_nick[size] = 0;
            m_comp.push_back(c_nick);
            memset(c_nick, 0, 15);
        }
    }
}
int CHat::sent_message(string companion, string message)
{
    ofstream fin(companion);
    if (fin.is_open()) 
    {
        fin << get_nickname() << " : " << message << endl;
        fin.close();
        return 1;
    }
    else
    {
        return -1;
    }
    
}
int CHat::get_message(string& message)
{
    string companion = get_nickname();
    ifstream fin(companion);
    char line[60] = "";
    
    if (fin.is_open())
    {
        while (fin.getline(line, 60))
        {
            message  += line;
        }
        fin.close();
        remove(companion.c_str());
        return 1;
    }
    else
    {
        return -1;
    }

}
void CHat::chat_message(string companion)
{
    if (companion == "ALL")
    {
        list_companions();
        cout << "Сообщение для участников чата ";
        for (int i = 0; i < m_comp.size(); i++)
        {
            cout << m_comp[i] << " ";
        }
        cout << " " << get_message() << endl;
    }
    else
    {
        if (check_companion(companion) == true)
        {
            cout << "Пользователь " << companion << " найден!" << endl;
            cout << "Сообщение для пользвателя " << companion << " : " << get_message() << endl;
        }
        else
        {
            cout << "Такого пользователя не существует! " << endl;
        }
    }
}
