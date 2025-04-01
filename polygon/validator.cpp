#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int testCaseCount = inf.readInt(1, 100, "t");

    inf.readEoln();

    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        setTestCase(testCase);
        inf.readInt(1, 1'000'000'000, "n");
        inf.readSpace();
        inf.readInt(1, 1'000, "k");
        inf.readEoln();
    }

    inf.readEof();
}