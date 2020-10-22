#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.hpp"
#include "Indexer.h"

int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}

int main(int argc, char** argv) {

    if(argc == 1)
    {
        return runCatchTests(argc, argv);
    }

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(argv[1]); //opens files
    outputFile.open(argv[2]);

    runIndexer(inputFile, outputFile); //runs the indexer

    inputFile.close(); //closes files
    outputFile.close();
}
