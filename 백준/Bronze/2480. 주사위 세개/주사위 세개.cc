#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;
int result;
int maxValue;

int main() {
	scanf("%d %d %d", &a, &b, &c);

	if (a == b && a == c)
		result = 10000 + a * 1000;
	else if (a == b || a == c)
		result = 1000 + a * 100;
	else if (b == c)
		result = 1000 + b * 100;
	else {
		maxValue = max(a, b);
		maxValue = max(maxValue, c);
		result = maxValue * 100;
	}

	printf("%d\n", result);

	return 0;
}