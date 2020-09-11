#ifndef IPLANALYSER_H
#define IPLANALYSER_H

#include <iostream>
#include <list>
#include<vector>
#include "../CSVLibrary/CsvFileoperations.h"
#include "MostRuns.h"

using namespace std;

class IPLAnalyser {
    list <MostRuns> batsmanList;

    public:
    void loadIPLData(string filePath);
    list<MostRuns> getSortedBattingAvgData();
};
#endif

void IPLAnalyser::loadIPLData(string filePath) {
    CSVFileOperations csvFileOperations;
    list<vector<string>> mostRunsCsvList = csvFileOperations.readFile(filePath);

    for (auto playerNum = mostRunsCsvList.begin(); playerNum != mostRunsCsvList.end(); playerNum++) {
        MostRuns mostRunsData;
        mostRunsData.player = playerNum -> at(1);
        mostRunsData.matches = stoi(playerNum -> at(2));
        mostRunsData.innings = stoi(playerNum -> at(3));
        mostRunsData.runs = playerNum -> at(5);
        mostRunsData.highScore = playerNum -> at(6);
        mostRunsData.average = stod(playerNum -> at(7));
        mostRunsData.strikeRate = stod( playerNum -> at(9));
        mostRunsData.centuries = stoi(playerNum -> at(10));
        mostRunsData.halfCenturies = stoi(playerNum -> at(11));
        mostRunsData.fours = stoi(playerNum -> at(12));
        mostRunsData.sixes = stoi(playerNum -> at(13));

        batsmanList.push_back(mostRunsData);
    }
}

list<MostRuns> IPLAnalyser::getSortedBattingAvgData() {
    batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer)
    {
        if(firstPlayer.average == secondPlayer.average)
            return &firstPlayer > &secondPlayer;
        return firstPlayer.average > secondPlayer.average;
    });
}