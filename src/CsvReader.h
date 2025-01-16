#ifndef CSVREADER_H
#define CSVREADER_H

#include <map>
#include <vector>
#include <iostream>

#include "FileReader.h"

class CsvReader: public FileReader {
    public:
    std::vector<std::map<std::string, std::string>> read(std::string filename) override;
};

#endif // FILEREADER_H