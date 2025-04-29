#pragma once
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
        void setName(string name);
        Player(string name) : nickname(name){}
        string getName();
};


