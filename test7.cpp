#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n, available_lockers;
string date_mark = "0";
vector<string> q;
vector<vector<string>> menu;

void shower(string line)
{
    //find user id
    string delimiter = " ";
    size_t pos = line.find(delimiter);
    string user_id;
    user_id = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    //shower: already accepted
    for (int i = 0; i < q.size(); i++)
    {
        string my_front = q.front();
        if (user_id == my_front)
        {
            cout << "shower: already accepted\n";
            return;
        }
    }
    q.pop_back(user_id);

    //shower: accept
    int age = stoi(line);
    int bill;
    if (age < 12)
        bill = 700;
    else if (age < 15)
        bill = 1000;
    else if (age < 18)
        bill = 1200;
    else
        bill = 1500;
    cout << "shower: " << user_id << " " << bill << "\n";
}

void locker(string date, string time, string line)
{
    //find user id
    string delimiter = " ";
    size_t pos = line.find(delimiter);
    string user_id;
    user_id = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    //locker: lack of lockers
    int lockers = stoi(line);
    if (lockers > available_lockers)
    {
        cout << "locker: lack of lockers\n";
        return;
    }

    //locker: accept
    available_lockers -= lockers;
    int bills;
    if (time[0] == 0 || (time[0] == 1 && time[1] < 6))
        bills = 500;
    else
        bills = 400;
    cout << "locker: " << user_id << " " << bills << " " << available_lockers << "\n";
}

void lock(string date, string time, string line)
{
    cout << "lock"
         << "\n";
}

void order(string date, string time, string line)
{
    cout << "order"
         << "\n";
}

void add(string date, string time, string line)
{
    int index = menu.size() + 1;
    //find menu
    string delimiter = " ";
    size_t pos = line.find(delimiter);
    string name;
    name = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());
    menu[index].pop_back(name);

    //find price
    pos = line.find(delimiter);
    string price;
    price = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());
    menu[index].pop_back(price);

    //find special price
    pos = line.find(delimiter);
    string special_price;
    special_price = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());
    menu[index].pop_back(special_price);

    //find stock
    pos = line.find(delimiter);
    string stock;
    stock = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());
    menu[index].pop_back(stock);

    cout << "add"
         << "\n";
}

void change(string date, string time, string line)
{
    cout << "change"
         << "\n";
}

int main(int argc, char *argv[])
{
    cin >> n;
    available_lockers = n;
    string line;
    while (getline(cin, line))
    {
        //find command
        string delimiter = ": ";
        size_t pos = line.find(delimiter);
        string command;
        command = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        //find date
        delimiter = " ";
        pos = line.find(delimiter);
        string date;
        date = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        if (date_mark != date)
        {
            date_mark = date;
            q.clear();
        }

        //find time
        pos = line.find(delimiter);
        string time;
        time = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        if ((time[0] == '0' && time[1] < '9') || (time[0] == '2' && time[1] > '0'))
        {
            cout << command << ": closed\n";
        }
        else
        {
            if (command == "shower")
                shower(line);
            else if (command == "locker")
                locker(date, time, line);
            else if (command == "locker")
                locker(date, time, line);
            else if (command == "lock")
                lock(date, time, line);
            else if (command == "order")
                order(date, time, line);
            else if (command == "add")
                add(date, time, line);
            else if (command == "change")
                change(date, time, line);
        }
    }
    return 0;
}
