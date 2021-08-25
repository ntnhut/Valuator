#include "Expression.h"
#include "Valuator.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <filesystem>

namespace pt = boost::property_tree;
namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
    
    const fs::path inputFolder(argv[1]); 
    const fs::path outputFolder(argv[2]); 
    if (!fs::exists(outputFolder)) {
        fs::create_directory(outputFolder);
    }

    for (auto const& dirEntry : fs::directory_iterator{inputFolder}) {
    
        pt::ptree inputTree;
        pt::read_xml(dirEntry.path().string(), inputTree);

        pt::ptree outputTree;
        for (pt::ptree::value_type &v : inputTree.get_child("expressions")) {
    
            std::string id = v.second.get_child("<xmlattr>.id").data();
            Expression* e = Valuator::createExpression(v);
            if (e != nullptr) {
                pt::ptree& result = outputTree.add("expressions.result", e->value());
                result.put("<xmlattr>.id", id);
            }  
            delete e;
        }
        fs::path outputFileName(dirEntry.path().stem());
        outputFileName += "_result.xml";
        fs::path output = outputFolder / outputFileName;

        pt::write_xml(output.string(), outputTree);
    }
}
