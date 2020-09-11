#include <vector>
#include <list>
#include "../model/MostWkts.h"

using namespace std;

class IPLAnalyserBowlingView {
public:

    IPLAnalyserBowlingView() {}

    void displayWelcomeMessage();
    int displayPlayerCount();
    void displayMenu();
    void displayPlayersData(list<MostWkts> bowlersData);
};

void IPLAnalyserBowlingView::displayWelcomeMessage() {
    cout << "Welcome to IPL Analyser for Bowling" << endl;
}

int IPLAnalyserBowlingView::displayPlayerCount() {
    cout << "Enter num of players to display" << endl;
    int playerCount;
    cin >> playerCount;
    return playerCount;
}

void IPLAnalyserBowlingView::displayMenu() {
    cout << endl;
    cout << "Enter 1 to get top bowling averages data" << endl;
    cout << "Enter 2 to get top striking average data" << endl;
    cout << "Enter 3 to get top economy rate data" << endl;
    cout << "Enter 4 to quit" << endl;
    cout << "Enter choice" << endl;
}

void IPLAnalyserBowlingView::displayPlayersData(list<MostWkts> bowlersData) {
    int count = 0;
    int playerCount = displayPlayerCount();
    for(auto playerNum = bowlersData.begin(); count < playerCount; playerNum++, count++) {
        cout << endl;
        cout << "Player Name: " << playerNum->player << endl;
        cout << "Bowling Average: " << playerNum->average << endl;
        cout << "Striking Rate: " << playerNum->strikeRate << endl;
        cout << "Economy rate: " << playerNum->economyRate << endl;
    }
}
