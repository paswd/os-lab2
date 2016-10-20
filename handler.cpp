#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string str = "";
	bool lspace = false;
	for (size_t i = 0; argv[0][i] != '\0'; i++) {
		if (argv[0][i] == ' ' && lspace) {
			continue;
		}

		str += argv[0][i];

		if (argv[0][i] == ' ') {
			lspace = true;
		} else {
			lspace = false;
		}
	}

	string filename = "";
	for (size_t i = 0; argv[1][i] != '\0'; i++) {
		filename += argv[1][i];
	}

	ofstream out(filename.c_str());
	out << str << endl;
	out.close();

	return 0;
}
