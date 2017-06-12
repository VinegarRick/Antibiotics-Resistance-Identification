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
	ofstream outfile ("concatenated_strains.fna");
	string line;
	int i;

	for ( i = 0 ; i < argc - 1 ; ++i ) {
		ifstream strainFile (argv[i + 1]);
		if ( strainFile.is_open() ) {
			while ( getline(strainFile, line) ) {
				outfile << line << endl;
			}
		}
		else {
			cout << "Could not open file(s)" << endl;
			return 0;
		}
		strainFile.close();
	}

	outfile.close();

	return 1;
}