#include<iostream>
using namespace std;

struct student{
	long long zhun;
	int kao;
}stu[1010];

int main(){
	int n, m, temp;
	scanf("%d", &n);
	long long a;
	int b, c;
	for(int i = 0; i < n; i++){
		scanf("%lld %d %d", &a, &b, &c);
		cout << a << endl;
		stu[b].zhun = a;
		stu[b].kao = c;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		cin >> temp;
		cout << stu[temp].zhun << " " << stu[temp].kao << endl;
	}

	system("pause");
	return 0;
}