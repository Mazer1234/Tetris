#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Player{
    private:
        string nickname;
        int score;
        string data;
        vector<pair<string, int>> history;
        void setData();
    public:
        //void setScore();
        void addToHistory();
        void getHistory();
        void setName();
        Player(string name) : nickname(name) {}
};


void Player::setName(){
    string name;
    cout << "Enter your nickname: ";
    getline(cin, name);
    this->nickname = name;
    cout << "Successfull record nickname" << endl;
}

void Player::setData(){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    this->data += to_string(ltm->tm_mday) + '.' + to_string(ltm->tm_mon) + '.' + to_string(ltm->tm_year);
}

void Player::addToHistory(){
    setData();
    this->history.push_back(make_pair(this->data, this->score));
}

void Player::getHistory(){
    cout << "----History of games----" << endl;
    for (int i = 0; i < this->history.size(); i++){
        cout << i + 1 << ")" << endl;
        cout << "Data: " << this->history[i].first << endl;
        cout << "Score: " << this->history[i].second <<endl;
    }
}





