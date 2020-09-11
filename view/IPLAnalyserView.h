#ifndef IPLANALYSERVIEW_H
#define IPLANALYSERVIEW_H

//#include <iostream>
#include <vector>
#include <list>
#include "../model/MostRuns.h"

using namespace std;

class IPLAnalyserView {
public:

    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayMenu();
    void displayPlayersData(list<MostRuns> batsmanData);
};
#endif

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome to IPL Analyser" << endl;
}

void IPLAnalyserView::displayMenu() {
    cout << endl;
    cout << "Enter 1 to get top batting averages data" << endl;
    cout << "Enter 2 to get top striking rate data" << endl;
    cout << "Enter 3 to get cricketers who hit maximum 4's and 6's" << endl;
    cout << "Enter 4 to get cricketers with best strike rate and maximum 4's and 6's" << endl;
    cout << "Enter 5 to quit" << endl;
    cout << "Enter choice" << endl;
}

void IPLAnalyserView::displayPlayersData(list<MostRuns> batsmanData) {
    int count = 0;
    for(auto playerNum = batsmanData.begin(); count < 5; playerNum++, count++) {
        cout << " Player Name: " << playerNum->player << endl;
        cout << " Batting Average: " << playerNum->average << endl;
        cout << " Strike rate: " << playerNum->strikeRate << endl;
        cout << " total fours: " << playerNum->fours << " total sixes: " << playerNum->sixes << endl;
        cout << endl;
    }
}
