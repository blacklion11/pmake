#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef map<string, string> Map;
typedef map<string, Node> Rules;


/* Node struct for storing rules */
typedef struct 
{
    string target;
    set<string> sources;
    string command;
    time_t timestamp;
} Node;


/* get and returns variables from the makefile */
Map get_variables(ifstream file)
{
    Map variables;

    string line;

    while( getline(file, line))
    {
        if(line.find("=") != string::npos)
        {
            /* Read in and assign variables into map */
            string value = line.substr(line.find("="), string::npos);
            value = value.substr(1, string::npos);

            string name = line.substr(0, line.find("=") - 1);

            variables[name] = value;

        }
    }

    return variables;
}

/* Get rules */
Rules get_rules(ifstream file)
{
    Rules rules;

    string line;

    while( getline(file, line))
    {
        if(line.find(":") != string::npos)
        {
            /* Read in and assign rules */
            string target = line.substr(0, line.find(":") - 1);
            
            set<string> sources;
            string sources_string = line.substring(line.find(":") + 1, string::npos);
            /* split string into the set of sources */
        }
    }

}




int main(int argc, char **argv)
{
    
    ifstream file;
    file.open("Makefile");

    Map vars = get_variables(file);
    Rules rules = get_rules(file);

    file.close();

    cout << "-----Variables-----" << endl;
    for (auto it = vars.begin(); it != vars.end(); it++)
    {
        cout <<  it->first << " = " << it->second << endl;
    }

    return 0;
}


