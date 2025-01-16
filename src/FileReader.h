#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>

class FileReader {
    public:
    virtual std::vector<std::map<std::string, std::string>> read(std::string filename) = 0;
};

#endif // FILEREADER_H