#include "Expression.h"
#include "Valuator.h"
#include <boost/property_tree/ptree.hpp>
#include <filesystem>
#include <thread>

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
    
    const fs::path inputFolder(argv[1]); 
    const fs::path outputFolder(argv[2]); 
    if (!fs::exists(outputFolder)) {
        fs::create_directory(outputFolder);
    }

    std::vector<std::thread> threads;
    Valuator v;
    for (auto const& dirEntry : fs::directory_iterator{inputFolder}) {
    
        const std::string inputFileName = dirEntry.path().string();
        fs::path outputFilePath(dirEntry.path().stem());
        outputFilePath += "_result.xml";
        fs::path output = outputFolder / outputFilePath;
        const std::string outputFileName = output.string();
        threads.push_back(std::thread(&Valuator::evaluate, &v, inputFileName, outputFileName));
        
    }
    for (std::thread& t: threads) {
        t.join();
    }
}
