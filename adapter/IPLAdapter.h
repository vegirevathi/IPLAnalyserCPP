#ifndef IPLADAPTER_H
#define IPLADAPTER_H
#include <list>
#include "../model/IPLDao.h"

class IPLAdapter {

public:
    virtual list<IPLDao> loadIPLData(string filePath) = 0;
};
#endif