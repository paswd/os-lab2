#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
	int pipedes[2];
	pid_t pid;
	pipe(pipedes);
	pid = fork();

	if (pid > 0) {
		int sym;
		string in = "";
		while ((sym = getchar()) != EOF) {
			in += (char) sym;
		}

		string filename = "out.txt";
		close(pipedes[0]);
		filename += '\t';
		write(pipedes[1], (void *) (filename.c_str()), filename.size());
		write(pipedes[1], (void *) in.c_str(), in.size());
		close(pipedes[1]);
	} else {
		char tmp;
		string str = "";
		string filename = "";
		close(pipedes[1]);
		bool mode = false;
		bool lspace = false;

		while (read(pipedes[0], &tmp, 1) != 0) {
			if (!mode) {
				if (tmp == '\t') {
					mode = true;
					continue;
				}
				filename += tmp;
			} else {
				if (tmp == ' ' && lspace) {
					continue;
				}

				str += tmp;

				if (tmp == ' ') {
					lspace = true;
				} else {
					lspace = false;
				}
			}
		}

		ofstream out(filename.c_str());
		out << str << endl;
		out.close();
	}

	return 0;
}
