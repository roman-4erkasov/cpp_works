#include <fstream>
#include <string>
#include "log_duration.hpp"

using namespace std;

int main() {
    {
        LOG_DURATION("with endl");
        ofstream out_file("test1.txt"s);
        for (int i = 0; i < 10; ++i) out_file << "test"s << endl;
    }
    {
        LOG_DURATION("with \\n");
        ofstream out_file("test2.txt"s);
        for (int i = 0; i < 10; ++i) out_file << "test\n"s;
    }

    return 0;
} 