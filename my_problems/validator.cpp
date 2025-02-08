#include<bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 100, "tc");

    for (int i = 0; i < tc; i++) {
        inf.readSpace();
        inf.readLong(1, 1000000000, "n");
        inf.readSpace();
        inf.readLong(1, 1000, "k");
    }

    inf.readEoln();
    
    inf.readEof();
}