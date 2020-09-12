#include <list>
#include "../adapter/IPLAdapter.h"
#include "../CSVLibrary/CsvFileoperations.h"
#include "../model/IPLDao.h"

using namespace std;

class BowlerAdapter : IPLAdapter {

public:
    list<IPLDao> loadIPLData(string filePath) {
    CSVFileOperations csvFileOperations;
    list<IPLDao> playersList;
     list<vector<string>> mostWktsCsvList = csvFileOperations.readFile(filePath);

    for (auto playerNum = mostWktsCsvList.begin(); playerNum != mostWktsCsvList.end(); playerNum++) {
        IPLDao mostWktsData;
        mostWktsData.player = playerNum->at(1);
        mostWktsData.matches = stoi(playerNum->at(2));
        mostWktsData.innings = stoi(playerNum->at(3));
        mostWktsData.overs = stod(playerNum->at(4));
        mostWktsData.runs = stoi(playerNum->at(5));
        mostWktsData.wkts = stoi(playerNum->at(6));
        mostWktsData.bowlingAverage = (playerNum->at(8));
        mostWktsData.economyRate = stod(playerNum->at(9));
        mostWktsData.bowlingStrikeRate = (playerNum->at(10));
        mostWktsData.fourWickets = stoi(playerNum->at(11));
        mostWktsData.fiveWickets = stoi(playerNum->at(12));

        playersList.push_back(mostWktsData);
        }
        return playersList;    
    }
};