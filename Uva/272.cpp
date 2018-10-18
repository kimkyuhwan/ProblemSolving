#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string str;
int main() {
	int idx = 0;
	while (getline(cin, str)) {
		string sol = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '"') {
				if (idx == 0) sol += "``";
				else sol += "''";
				idx = (idx + 1) % 2;
			}
			else {
				sol.push_back(str[i]);
			}
		}
		cout << sol << endl;
	}
	return 0;
}