#include <list>
#include "../adapter/BatsmanAdapter.h"
#include "../adapter/BowlerAdapter.h"
#include "../model/IPLDao.h"
#include "../model/enumFields/playerType.h"
#include <string>

using namespace std;

class AdapterFactory {

public:
    list<IPLDao> getIPLAdapter(string filePath, int playerType) {
        if (playerType == BATSMAN)
            return (new BatsmanAdapter)->loadIPLData(filePath);
        return (new BowlerAdapter)->loadIPLData(filePath);
    }
};
