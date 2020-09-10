#include <iostream>
using namespace std;

class MostRuns
{
private:

    string POS;
    string player;
    string matches;
    string innings;
    string NO;
    string runs;
    string highScore;
    string average;
    string BF;
    string strikeRate;
    string centuries;
    string halfCenturies;
    string fours;
    string sixes;

public:
    MostRuns() {}
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

    string getNO() {
        return NO;
    }

    string getRuns() {
        return runs;
    }

    string getHighScore() {
        return highScore;
    }

    string getAverage() {
        return average;
    }

    string getBF() {
        return BF;
    }

    string getStrikeRate() {
        return strikeRate;
    }

    string getCenturies() {
        return centuries;
    }

    string getHalfCenturies() {
        return halfCenturies;
    }

    string getFours() {
        return fours;
    }

    string getSixes() {
        return sixes;
    }

    string* getPosition() {
        return &POS;
    }
};