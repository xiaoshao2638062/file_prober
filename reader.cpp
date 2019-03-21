#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "reader.hpp"

using namespace std;

int readFile(vector<string> &argvs) {
    if (argvs[1] != "read")
        return -1;
    int in = open(argvs[2].c_str(), O_RDONLY);
    if (in == -1) {
        cout << "Cannot open " << argvs[2] << endl;
        return -1;
    }
    int result = -1;
    long offset = stol(argvs[3]);
    unsigned long size = stoul(argvs[4]);
    long filesize = lseek(in, 0, SEEK_END);
    cout << "File size = " << filesize << endl;
    if (offset > filesize || offset < 0) {
        cout << "Invalid offset " << offset << endl;
    } else if (size == 0) {
        cout << "Invalid length " << size << endl;
    } else {
        lseek(in, offset, SEEK_SET);
        char *readin = new char[size];
        auto readsize = read(in, readin, size);
        cout << "Read in " << readsize << " bytes:\n[";
        for (auto i = 0; i < readsize; i++) 
            printf("%#X", readin[i]);
        cout << "]" << endl;
        result = 0;
        if (readin) delete [] readin;
    }
    close(in);
    return result;
}