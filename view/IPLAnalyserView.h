#ifndef IPLANALYSERVIEW_H
#define IPLANALYSERVIEW_H

#include <iostream>
#include <vector>
#include <list>
//#include "../model/IPLAnalyser.h"
#include "../model/MostRuns.h"

using namespace std;

class IPLAnalyserView {
public:

    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayTopBattingAveragePlayers(list<MostRuns> batsmanData);
    void displayTopStrikingRatePlayers(list<MostRuns> batsmanDat);
};
#endif

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome to IPL Analyser" << endl;
}

void IPLAnalyserView::displayTopBattingAveragePlayers(list<MostRuns> batsmanData) {
    int count = 0;
    for(auto playerNum = batsmanData.begin(); count < 5; playerNum++, count++) {
        cout << "Player Name: " << playerNum->player << " Batting Average: " << playerNum->average << endl;
    }
}

void IPLAnalyserView::displayTopStrikingRatePlayers(list<MostRuns> batsmanData) {
    int count = 0;
    for(auto playerNum = batsmanData.begin(); count < 5; playerNum++, count++) {
        cout << "Player Name: " << playerNum->player << " Strike Rate: " << playerNum->strikeRate << endl;
    }
}