#include "Player.h"

/**
 * Запись никнейма
 */
void Player::setName(string name){
    this->nickname = name;
    //cout << "Successfull record nickname" << endl;
}

/**
 * Запись даты игры
 */
void Player::setData(){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    this->data += to_string(ltm->tm_mday) + '.' + to_string(ltm->tm_mon) + '.' + to_string(ltm->tm_year);
}

/**
 * Добавление игры в историю игр пользователя
 */
void Player::addToHistory(){
    setData();
    this->history.push_back(make_pair(this->data, this->score));
}

/**
 * Получить историю игр пользователя
 */
void Player::getHistory(){
    cout << "----History of games----" << endl;
    for (int i = 0; i < this->history.size(); i++){
        cout << i + 1 << ")" << endl;
        cout << "Data: " << this->history[i].first << endl;
        cout << "Score: " << this->history[i].second <<endl;
    }
}

/**
 * Получить никнейм игрока
 */
string Player::getName(){
    return this->nickname;
}