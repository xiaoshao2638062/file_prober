#include <iostream>
#include <string>
#include <vector>

#include "reader.hpp"
#include "writer.hpp"

using namespace std;

void printUsage();

int main(int argc, char **argv) {
    if (argc != 5 && argc != 6) {
        printUsage();
        return -1;
    } else {
        vector<string> argvs(argv, argv + argc);
        switch (argc)
        {
            case 5:  if (readFile(argvs) == -1)  printUsage(); break;
            case 6:  if (writeFile(argvs) == -1) printUsage(); break;
            default:                                           break;
        }
    }
    return 0;
}

void printUsage() {
    cout << "Usage:" << endl;
    cout << "./run read  filename offset length" << endl;
    cout << "./run write filename offset size char_to_write" << endl;
}