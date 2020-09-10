#include <iostream>
using namespace std;

class MostWkts {

private:
    string POS;
    string player;
    string matches;
    string innings;
    string overs;
    string runs;
    string wkts;
    string BBI;
    string average;
    string ECON;
    string strikeRate;
    string fourWickets;
    string fiveWickets;

public:
    string getPOS() {
        return POS;
    }

    string getPlayer() {
        return player;
    }

    string getMatches() {
        return matches;
    }

    string getInnings() {
        return innings;
    }

    string getOvers() {
        return overs;
    }

    string getRuns() {
        return runs;
    }

    string getWkts() {
        return wkts;
    }

    string getBBI() {
        return BBI;
    }

    string getAverage() {
        return average;
    }

    string getStrikeRate() {
        return strikeRate;
    }

    string getFourWickets() {
        return fourWickets;
    }

    string getFiveWickets() {
        return fiveWickets;
    }

    string* getPosition() {
        return &POS;
    }
};