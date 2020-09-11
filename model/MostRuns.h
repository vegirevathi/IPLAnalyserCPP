#ifndef MOSTRUNS_H
#define MOSTRUNS_H

#include <iostream>
using namespace std;

class MostRuns
{
public:

    string player;
    int matches;
    int innings;
    string runs;
    string highScore;
    double average;
    double strikeRate;
    int centuries;
    int halfCenturies;
    int fours;
    int sixes;

public:
    MostRuns() {}
};
#endif