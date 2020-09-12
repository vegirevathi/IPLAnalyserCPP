#include <vector>
#include <list>
#include <string>
#include "../model/IPLDao.h"

using namespace std;

class IPLAnalyserDaoView {
public:

    IPLAnalyserDaoView() {}

    void displayWelcomeMessage();
    int displayPlayerCount();
    void displayMenu();
    void displayBatsmanData(list<IPLDao> playersData);
    void displayBowlersData(list<IPLDao> playersData);
};

void IPLAnalyserDaoView::displayWelcomeMessage() {
    cout << "Welcome to IPL Analyser" << endl;
}

int IPLAnalyserDaoView::displayPlayerCount() {
    cout << "Enter num of players to display" << endl;
    int playerCount;
    cin >> playerCount;
    return playerCount;
}

void IPLAnalyserDaoView::displayMenu() {
    cout << endl;
    cout << "Enter 1 to get top batting averages data" << endl;
    cout << "Enter 2 to get top striking rate data" << endl;
    cout << "Enter 3 to get cricketers who hit maximum 4's and 6's" << endl;
    cout << "Enter 4 to get cricketers with best strike rate and maximum 4's and 6's" << endl;
    cout << "Enter 5 to get cricketers with best strike rate and batting average" << endl;
    cout << "Enter 6 to get cricketers with best batting average and maximum runs" << endl;
    cout << "Enter 7 to get cricketers with maximum hundreds and best batting averages" << endl;
    cout << "Enter 8 to get cricketers with zero half centuries and zero centuries but with best batting averages" << endl;
    cout << "Enter 9 to get top bowling averages data" << endl;
    cout << "Enter 10 to get top striking average data" << endl;
    cout << "Enter 11 to get top economy rate data" << endl;
    cout << "Enter 12 to get top striking rate with highest 4 wickets and 5 wickets" << endl;
    cout << "Enter 13 to get top striking rate and bowling average players" << endl;
    cout << "Enter 14 to get top bowling average and maximum wickets" << endl;
    cout << "Enter 15 to quit" << endl;
    cout << "Enter choice" << endl;
}

void IPLAnalyserDaoView::displayBatsmanData(list<IPLDao> playersData) {
    int count = 0;
    int playerCount = displayPlayerCount();
    for(auto playerNum = playersData.begin(); count < playerCount; playerNum++, count++) {
        cout << " Player Name: " << playerNum->player << endl;
        cout << " Batting Average: " << playerNum->battingAverage << endl;
        cout << " Strike rate: " << playerNum->battingStrikeRate << endl;
        cout << " Maximum runs: " << playerNum->runs << endl;
        cout << " total fours: " << playerNum->fours << endl;
        cout << " total sixes: " << playerNum->sixes << endl;
        cout << " total centuries: " << playerNum->centuries << endl;
        cout << " total half centuries: " << playerNum->halfCenturies << endl;
        cout << endl;
    }
}

void IPLAnalyserDaoView::displayBowlersData(list<IPLDao> playersData) {
    int count = 0;
    int playerCount = displayPlayerCount();
    for(auto playerNum = playersData.begin(); count < playerCount; playerNum++, count++) {
        cout << endl;
        cout << "Player Name: " << playerNum->player << endl;
        cout << "Bowling Average: " << playerNum->bowlingAverage << endl;
        cout << "Striking Rate: " << playerNum->bowlingStrikeRate << endl;
        cout << "Economy rate: " << playerNum->economyRate << endl;
        cout << "Four Wickets: " << playerNum->fourWickets << endl;
        cout << "Five Wickets: " << playerNum->fiveWickets << endl;
        cout << endl;
    }
}
