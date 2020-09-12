#include <list>
#include "../adapter/IPLAdapter.h"
#include "../CSVLibrary/CsvFileoperations.h"
#include "../model/IPLDao.h"

using namespace std;

class BatsmanAdapter : IPLAdapter {

public:
    list<IPLDao> loadIPLData(string filePath) {
    CSVFileOperations csvFileOperations;
    list<IPLDao> playersList;
    list<vector<string>> mostRunsCsvList = csvFileOperations.readFile(filePath);

    for (auto playerNum = mostRunsCsvList.begin(); playerNum != mostRunsCsvList.end(); playerNum++) {
        IPLDao mostRunsData;
        mostRunsData.player = playerNum -> at(1);
        mostRunsData.matches = stoi(playerNum -> at(2));
        mostRunsData.innings = stoi(playerNum -> at(3));
        mostRunsData.runs = playerNum -> at(5);
        mostRunsData.highScore = playerNum -> at(6);
        mostRunsData.battingAverage = stod(playerNum -> at(7));
        mostRunsData.battingStrikeRate = stod( playerNum -> at(9));
        mostRunsData.centuries = stoi(playerNum -> at(10));
        mostRunsData.halfCenturies = stoi(playerNum -> at(11));
        mostRunsData.fours = stoi(playerNum -> at(12));
        mostRunsData.sixes = stoi(playerNum -> at(13));

        playersList.push_back(mostRunsData);
        }
    return playersList;    
    }
};