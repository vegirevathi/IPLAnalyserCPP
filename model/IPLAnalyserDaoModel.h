#include <list>
#include <vector>
#include "../CSVLibrary/CsvFileoperations.h"
#include "IPLDao.h"
#include "enumFields/SortType.h"
#include "enumFields/playerType.h"
#include "../adapter/AdapterFactory.h"

class IPLAnalyserDaoModel {
    list <IPLDao> batsmanList;
    list <IPLDao> bowlerList;
    SortType sortByField;

    public:
    void loadIPLData(string filePath, int playerType);
    list<IPLDao> getSortedField(int sortByField);
};

void IPLAnalyserDaoModel::loadIPLData(string filePath, int playerType) {
    AdapterFactory iplAdapterFactory;
    switch (playerType)
    {
        case BATSMAN:
            batsmanList = iplAdapterFactory.getIPLAdapter(filePath, BATSMAN);
            break;
        case BOWLER:
            bowlerList = iplAdapterFactory.getIPLAdapter(filePath, BOWLER);
            break;
    }
}

list<IPLDao> IPLAnalyserDaoModel::getSortedField(int sortByField) {
    list <IPLDao> playersList;
    switch(sortByField) {
        case BATTING_AVERAGE:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.battingAverage == secondPlayer.battingAverage ? &firstPlayer > &secondPlayer : firstPlayer.battingAverage > secondPlayer.battingAverage;});
            break;
        case STRIKE_RATE:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.battingAverage == secondPlayer.battingAverage ? &firstPlayer > &secondPlayer : firstPlayer.battingAverage > secondPlayer.battingAverage;});
            break;
        case MAXIMUM_FOURS_SIXES:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return (firstPlayer.fours + firstPlayer.sixes) > (secondPlayer.fours + secondPlayer.sixes);});
            break;
        case STRIKE_RATE_AND_MAX_FOURS_SIXES:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.battingStrikeRate > secondPlayer.battingStrikeRate && (firstPlayer.fours + firstPlayer.sixes) > (secondPlayer.fours + secondPlayer.sixes);});
            break;
        case STRIKE_RATE_AND_BATTING_AVERAGE:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.battingStrikeRate > secondPlayer.battingStrikeRate && firstPlayer.battingAverage > secondPlayer.battingAverage;});
            break;
        case BATTING_AVERAGE_AND_MAXIMUM_RUNS:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.runs > secondPlayer.runs && firstPlayer.battingAverage > secondPlayer.battingAverage;});
            break;
        case BATTING_AVERAGE_AND_MAXIMUM_HUNDERDS:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.centuries > secondPlayer.centuries && firstPlayer.battingAverage > secondPlayer.battingAverage;});
            break;
        case ZERO_HALF_CENTURIES_AND_ZERO_CENTURIES_MAXIMUM_BATTING_AVERAGE:
            playersList = batsmanList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return (firstPlayer.centuries == 0) && (secondPlayer.centuries == 0) && firstPlayer.battingAverage > secondPlayer.battingAverage;});
            break;
        case BOWLING_AVERAGE:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.bowlingAverage > secondPlayer.bowlingAverage; });
            break;
        case STRIKING_RATE:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.bowlingStrikeRate > secondPlayer.bowlingStrikeRate; });
            break;
        case ECONOMY_RATE:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.economyRate > secondPlayer.economyRate; });
            break;
        case STRIKING_RATE_WITH_4WKTS_5WKTS:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.bowlingStrikeRate > secondPlayer.bowlingStrikeRate && firstPlayer.fourWickets > secondPlayer.fourWickets
                        && firstPlayer.fiveWickets > secondPlayer.fiveWickets; });
            break;
        case STRIKING_RATE_AND_BOWLING_AVERAGE:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.bowlingStrikeRate > secondPlayer.bowlingStrikeRate && firstPlayer.bowlingAverage > secondPlayer.bowlingAverage; });
            break;
        case BOWLING_AVERAGE_AND_MAXIMUM_WICKETS:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.bowlingAverage > secondPlayer.bowlingAverage && ((firstPlayer.fourWickets * 4) + (firstPlayer.fiveWickets * 5)) >
                                                                        ((secondPlayer.fourWickets * 4) + (secondPlayer.fiveWickets * 5)); });
            break;
        case BATTING_AND_BOWLING_AVERAGE:
            playersList = bowlerList;
            playersList.sort([] (const IPLDao firstPlayer, const IPLDao secondPlayer) {
                return firstPlayer.battingAverage > secondPlayer.battingAverage && firstPlayer.bowlingAverage > secondPlayer.bowlingAverage; });
            break;
    }
    return playersList;
}
