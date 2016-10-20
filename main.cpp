#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <unistd.h>

using namespace std;

int main()
{
	int sym;
	string in = "";

	while ((sym = getchar()) != EOF) {
		in += (char) sym;
	}

	execl("handler", in.c_str(), "out.txt", NULL);

	return 0;
}
