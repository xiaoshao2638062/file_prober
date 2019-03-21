#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "writer.hpp"

using namespace std;

int writeFile(vector<string> &argvs) {
    if (argvs[1] != "write")
        return -1;
    int in = open(argvs[2].c_str(), O_WRONLY);
    if (in == -1) {
        cout << "Cannot open " << argvs[2] << endl;
        return -1;
    }
    int result = -1;
    long offset = stol(argvs[3]);
    unsigned long size = stoul(argvs[4]);
    char c = argvs[5][0];
    long filesize = lseek(in, 0, SEEK_END);
    cout << "File size = " << filesize << endl;
    if (offset + (long)size > filesize || offset < 0) {
        cout << "Invalid offset " << offset << endl;
    } else if (size == 0) {
        cout << "Invalid length " << size << endl;
    } else {
        lseek(in, offset, SEEK_SET);
        char *writeout = new char[size];
        for (unsigned long i = 0; i < size; i++) {
            writeout[i] = c;
        }
        auto writesize = write(in, writeout, size);
        cout << "Write out " << writesize << " bytes" << endl;
        result = 0;
        if (writeout) delete [] writeout;
    }
    close(in);
    return result;
}