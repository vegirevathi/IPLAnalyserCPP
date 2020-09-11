#include <vector>
#include <list>
#include "../model/MostRuns.h"

using namespace std;

class IPLAnalyserBattingView {
public:

    IPLAnalyserBattingView() {}

    void displayWelcomeMessage();
    int displayPlayerCount();
    void displayMenu();
    void displayPlayersData(list<MostRuns> batsmanData);
};

void IPLAnalyserBattingView::displayWelcomeMessage() {
    cout << "Welcome to IPL Analyser" << endl;
}

int IPLAnalyserBattingView::displayPlayerCount() {
    cout << "Enter num of players to display" << endl;
    int playerCount;
    cin >> playerCount;
    return playerCount;
}

void IPLAnalyserBattingView::displayMenu() {
    cout << endl;
    cout << "Enter 1 to get top batting averages data" << endl;
    cout << "Enter 2 to get top striking rate data" << endl;
    cout << "Enter 3 to get cricketers who hit maximum 4's and 6's" << endl;
    cout << "Enter 4 to get cricketers with best strike rate and maximum 4's and 6's" << endl;
    cout << "Enter 5 to get cricketers with best strike rate and batting average" << endl;
    cout << "Enter 6 to get cricketers with best batting average and maximum runs" << endl;
    cout << "Enter 7 to get cricketers with maximum hundreds and best batting averages" << endl;
    cout << "Enter 8 to quit" << endl;
    cout << "Enter choice" << endl;
}

void IPLAnalyserBattingView::displayPlayersData(list<MostRuns> batsmanData) {
    int count = 0;
    int playerCount = displayPlayerCount();
    for(auto playerNum = batsmanData.begin(); count < playerCount; playerNum++, count++) {
        cout << " Player Name: " << playerNum->player << endl;
        cout << " Batting Average: " << playerNum->average << endl;
        cout << " Strike rate: " << playerNum->strikeRate << endl;
        cout << " Maximum runs: " << playerNum->runs << endl;
        cout << " total fours: " << playerNum->fours << endl;
        cout << " total sixes: " << playerNum->sixes << endl;
        cout << " total hunderds: " << playerNum->centuries << endl;
        cout << endl;
    }
}
