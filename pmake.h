#ifndef _pmake_h
#define _pmake_h

#include <string>
#include <set>

using namespace std;

/* Node struct for sorting rules. */
typedef struct
{
    string target;
    set<string> sources;
    string command;
    time_t timestamp;
} Node;

#endif
