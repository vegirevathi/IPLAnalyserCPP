#ifndef IPLANALYSER_H
#define IPLANALYSER_H

#include <list>
#include<vector>
#include "../CSVLibrary/CsvFileoperations.h"
#include "MostRuns.h"
#include "SortByFields.h"

using namespace std;

class IPLAnalyser {
    list <MostRuns> batsmanList;
    SortByField sortByField;

    public:
    void loadIPLData(string filePath);
    list<MostRuns> getSortedField(int sortByField);
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

list<MostRuns> IPLAnalyser::getSortedField(int sortByField) {
    switch(sortByField) {
        case BATTING_AVERAGE:
            batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer) {
                return firstPlayer.average == secondPlayer.average ? &firstPlayer > &secondPlayer : firstPlayer.average > secondPlayer.average;});
            break;
        case STRIKE_RATE:
            batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer) {
                return firstPlayer.strikeRate == secondPlayer.strikeRate ? &firstPlayer > &secondPlayer : firstPlayer.strikeRate > secondPlayer.strikeRate;});
            break;
        case MAXIMUM_FOURS_SIXES:
            batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer) {
                return (firstPlayer.fours + firstPlayer.sixes) > (secondPlayer.fours + secondPlayer.sixes);});
            break;
        case STRIKE_RATE_AND_MAX_FOURS_SIXES:
            batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer) {
                return firstPlayer.strikeRate > secondPlayer.strikeRate && (firstPlayer.fours + firstPlayer.sixes) > (secondPlayer.fours + secondPlayer.sixes);});
            break;
        case STRIKE_RATE_AND_BATTING_AVERAGE:
            batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer) {
                return firstPlayer.strikeRate > secondPlayer.strikeRate && firstPlayer.average > secondPlayer.average;});
            break;
        case BATTING_AVERAGE_AND_MAXIMUM_RUNS:
            batsmanList.sort([] (const MostRuns firstPlayer, const MostRuns secondPlayer) {
                return firstPlayer.runs > secondPlayer.runs && firstPlayer.average > secondPlayer.average;});
            break;
    }
    return batsmanList;
}
