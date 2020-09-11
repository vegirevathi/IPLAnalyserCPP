#include <list>
#include<vector>
#include "../CSVLibrary/CsvFileoperations.h"
#include "MostWkts.h"
#include "SortByBowlingFields.h"

class IPLAnalyserBowlingModel {
    list <MostWkts> bowlerList;
    SortByBowlingField sortByField;

    public:
    void loadIPLData(string filePath);
    list<MostWkts> getSortedField(int sortByField);
};

void IPLAnalyserBowlingModel::loadIPLData(string filePath) {
    CSVFileOperations csvFileOperations;
    list<vector<string>> mostWktsCsvList = csvFileOperations.readFile(filePath);

    for (auto playerNum = mostWktsCsvList.begin(); playerNum != mostWktsCsvList.end(); playerNum++) {
        MostWkts mostWktsData;
        mostWktsData.player = playerNum->at(1);
        mostWktsData.matches = stoi(playerNum->at(2));
        mostWktsData.innings = stoi(playerNum->at(3));
        mostWktsData.overs = stod(playerNum->at(4));
        mostWktsData.runs = stoi(playerNum->at(5));
        mostWktsData.wkts = stoi(playerNum->at(6));
        mostWktsData.average = (playerNum->at(8));
        mostWktsData.strikeRate = (playerNum->at(10));
        mostWktsData.fourWickets = stoi(playerNum->at(11));
        mostWktsData.fiveWickets = stoi(playerNum->at(12));

        bowlerList.push_back(mostWktsData);
    }
}

list<MostWkts> IPLAnalyserBowlingModel::getSortedField(int sortByField) {
    switch(sortByField) {
        case BOWLING_AVERAGE:
            bowlerList.sort([] (const MostWkts firstPlayer, const MostWkts secondPlayer) {
                return firstPlayer.average == secondPlayer.average ? &firstPlayer > &secondPlayer : firstPlayer.average > secondPlayer.average;});
            break;
    }
    return bowlerList;
}
