#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main ( int argc, char * argv[] )
{
	ifstream results_table ("results_table.txt");
	vector<string> vulnerabilities, resistances;
	string line, antibiotic;

	if ( results_table.is_open() ) {
		getline(results_table, antibiotic);
		while ( getline(results_table, line) ) {
			if ( line == "No resistance genes found." ) {
				vulnerabilities.push_back(antibiotic);
				getline(results_table, line);
				getline(results_table, antibiotic);
			}
			else if ( line.substr(0, 10) == "Resistance" ) {
				resistances.push_back(antibiotic);
			}
			else if ( line == "" ) {
				getline(results_table, antibiotic);
			}
		}
	}
	else {
		cout << "Could not open file" << endl;
		return 0;
	}
	results_table.close();

	if ( !vulnerabilities.empty() ) {
		cout << "Vulnerabilities:" << endl;
		for ( string vulnerability : vulnerabilities ) {
			cout << vulnerability << endl;
		}
	}
	else {
		cout << "No known vulnerabilities" << endl;
	}

	cout << endl;

	if ( !resistances.empty() ) {
		cout << "Resistances:" << endl;
		for ( string resistance : resistances ) {
			cout << resistance << endl;
		}
	}
	else {
		cout << "No known resistances" << endl;
	}

	return 1;
}