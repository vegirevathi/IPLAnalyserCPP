#ifndef MOSTWKTS_H
#define MOSTWKTS_H

#include <iostream>
using namespace std;

class MostWkts
{
public:
    string POS;
    string player;
    int matches;
    int innings;
    double overs;
    int runs;
    int wkts;
    string average;
    string strikeRate;
    int fourWickets;
    int fiveWickets;

public:
    MostWkts() {}
};
#endif