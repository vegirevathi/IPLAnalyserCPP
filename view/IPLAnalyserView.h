#ifndef IPLANALYSERVIEW_H
#define IPLANALYSERVIEW_H

#include <iostream>
#include <vector>
#include <list>
#include "../model/MostRuns.h"

using namespace std;

class IPLAnalyserView {
public:

    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayTopBattingAveragePlayers(list<MostRuns> batsmanData);
};
#endif

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome to IPL Analyser" << endl;
}

void displayTopBattingAveragePlayers(list<MostRuns> batsmanData) {
    int count = 0;
    for(auto playerNum = batsmanData.begin(); count < 5; playerNum++, count++) {
        cout << "Player Name: " << playerNum->player << " Batting Average: " << playerNum->average << endl;
    }
}
