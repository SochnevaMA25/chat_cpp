1. Выполнила Сочнева Марина
2. Тимлида не было :)
3. Идея 



--------------         
  регистрация          
--------------         
        (1)------------|
     |                 |
--------------         |
получение              |
сообщений              |
--------------         |
      |                |                 
--------------         |
отправка               |
сообщений              |
--------------         |
      |                |
      (1) -------------|

      РЕГИСТРАЦИЯ

    При регистрации пользователя идет запись в файл "Users.txt" в формате: 
  "Nick:....., Login:....., Pass:.......;". 
  Проверка на уже наличие такого пользователя в базе происходит на основе 
  поиска в файле ника и сравнения логина, и пароля. Если ник и логин совпали, 
  но не совпал пароль, то пользователю объявляется о неправильном вводе. 
  Если совпадает ник, но не совпадает логин, то считается, что логин неверный. 
  Если же такого ника вообще нет, то заводится новая строчка и пользователь регистрируется. 

  ПОЛУЧЕНИЕ СООБЩЕНИЙ

    После инициализации пользователя проверяется есть ли сообщения для пользователя. 
  Если есть, то выводятся на экран. 

  ОТПРАВКА СООБЩЕНИЙ

    У пользователя спрашивают кому он хочет отправить сообщение. Если "ALL", то всем.
  Далее пользователь вводит сообщение и возвращается на ПОЛУЧЕНИЕ СООБЩЕНИЙ.

  4.
  
typedef vector <string> Companions;                                          //все зарегистрированные пользователи

class Client                                                                //хранит информацию о клиенте
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
    string get_nickname();                                                  //получение ника
    void set_nickname(const char* nick);                                    //запись ника

};
class CHat:public Client
{
    Companions m_comp;
public:
    //string m_ch_nick;                                                      //ник отправителя   
    string m_message;                                                        //сообщение
    string m_companion;                                                      //получатель    
    CHat(const Client& nick);
    CHat(string nick);
    CHat(string nick, string message, string companion);
    string get_message();                                                   //отправка сообщения
    bool check_companion(string companion);                                 //проверка, есть ли такой получатель
    void list_companions();                                                 //вывод зарегистрированных пользователей
    void chat_message(string companion);                                    //вывод в консоль сообщений
    int sent_message(string companion, string message);                     //отправка сообщений
    int get_message(string& message);                                       //получение сообщений
};



Class History: public Vector<Message>                                        //история чата
{
}

Class Message: public Stream                                                 //входящие и исходящие
{
String m_nick;
String m_message;
String m_date;
}

Последние 2 класса ожидают реализации, не хватило времени.