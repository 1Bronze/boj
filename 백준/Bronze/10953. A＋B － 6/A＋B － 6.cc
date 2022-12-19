#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int num;
	cin >> num;
    
	for(int i=0; i<num; i++) {
	    string input;
	    int result[2];
	    
		cin >> input;
		istringstream iss(input);

		string tmp;
		int k = 0;
		while(getline(iss, tmp, ',')) {
			result[k] = stoi(tmp);
			k++;
		}		

		cout << result[0] + result[1] << endl;
	}
}