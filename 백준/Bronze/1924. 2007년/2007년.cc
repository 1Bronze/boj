#include <iostream>
using namespace std;

int main() {
	int m, d;
	int days = 0;
	int maxDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d %d", &m, &d);

	for(int i=1; i<m; i++)
		days += maxDays[i];
	days += d;

	if(days%7==1) printf("MON");
	else if(days%7==2) printf("TUE");
	else if(days%7==3) printf("WED");
	else if(days%7==4) printf("THU");
	else if(days%7==5) printf("FRI");
	else if(days%7==6) printf("SAT");
	else printf("SUN");
}