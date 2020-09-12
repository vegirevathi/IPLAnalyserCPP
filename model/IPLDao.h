#ifndef IPLDAO_H
#define IPLDAO_H
#include <iostream>
using namespace std;

class IPLDao {
public:
    string player;
    int matches;
    int innings;
    string runs;
    string highScore;
    double battingAverage;
    double battingStrikeRate;
    int centuries;
    int halfCenturies;
    int fours;
    int sixes;
    double overs;
    int wkts;
    string bowlingAverage;
    double economyRate;
    string bowlingStrikeRate;
    int fourWickets;
    int fiveWickets;

public:
    IPLDao() {}
};
#endif
