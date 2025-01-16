#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include <cstdlib>

#include "CsvReader.h"

std::vector<std::map<std::string, std::string>> CsvReader::read(std::string filename) {
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        std::cout << "file not open" << std::endl;
        exit(0);
    }

    // Load header line
    std::string headerLine;
    std::getline(ifs, headerLine);
    std::stringstream headerLineStream(headerLine);

    // Split header line
    std::vector<std::string> headers;
    std::string header;
    while (std::getline(headerLineStream, header, ';')) {
        headers.push_back(header);
    }

    // Parse remaining lines
    std::vector<std::map<std::string, std::string>> lines;
    std::string line;
    while (std::getline(ifs, line)) {
        std::stringstream lineStream(line);
        std::map<std::string, std::string> lineMap;
        for (auto& header: headers) {
            std::getline(lineStream, lineMap[header], ';');
        }
        lines.push_back(lineMap);
    }

    return lines;
}
