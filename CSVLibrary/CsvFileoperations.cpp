#include<iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class CsvFileOperation
{
public:
    vector<T*> readDataFromFile( string filePath )
    {
        vector<T*> List;
        ifstream theFile( filePath );
        string line;
        while (getline(theFile, line))
        {
            string column_value;
            T* t = new T();
            int index = 0;
            string* position = t->getPosition();
            stringstream ss(line);
            while (getline(ss, column_value, ','))
            {
                position[index++] = column_value;
            }
            List.emplace_back(t);
            
        }
        return List;
    }

    void writeToFile( string fileName, vector<T*> list , int numberOfFields )
    {
        fstream fileStream;
        fileStream.open(fileName, ios::out | ios::trunc);
        if (fileStream.is_open()) {
            for (auto i = list.begin(); i != list.end(); ++i) {
                int index = 0;
                string* position = (*i)->getPosition();
                for( int j = 0; j < numberOfFields - 1; j++ ) {
                    fileStream << position[index++] << ",";
                }
                fileStream << position[index] <<"\n";
            }
            fileStream.close();
        }
    }
};



