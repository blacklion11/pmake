#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <regex>

#include "pmake.h"

typedef map<string, string> Map;
typedef map<string, Map> Mom; // Make Object Model

static Mom OM;

/* ifstream's deconstructor (which is called when the scope is exited
 * takes care of file closure. So parsing can be wholly subroutined. */
bool parse_makefile(Mom &om,  string path)
{
    ifstream file (path);
    bool file_opened = file.good();
    if (file_opened) {

        // Iterate over file lines.
        for (string line; getline(file, line);) {
            size_t pos;
            if ((pos = line.find("=")) != string::npos
                    && isspace(line[0])) {
                om["variables"][line.substr(0, pos - 1)]
                    = line.substr(pos + 1, string::npos);
            } else if ((pos = line.find(":")) != string::npos) {
                // rule has a dependency list and an execution string
            }
        }
        for (auto it = om["rules"].begin(); it != om["rules"].end(); it++) {
            cout << it->second << endl;
        }
    }

    // If the file failed to open we want to know.
    return file_opened;
}

int main(int argc, char **argv)
{
    parse_makefile(OM, "Makefile");

    return 0;
}


