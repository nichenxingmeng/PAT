#include<iostream>
#include<string>
using namespace std;
const int INF = 1000000000;

int main(){
	int m, st = INF, ed = 0, ho, mi, se, temp;
	string idst, ided, id;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		cin >> id;
		scanf("%d:%d:%d", &ho, &mi, &se);
		temp = ho * 3600 + mi * 60 + se;
		if(temp < st){
			st = temp;
			idst = id;
		}
		scanf("%d:%d:%d", &ho, &mi, &se);
		temp = ho * 3600 + mi * 60 + se;
		if(temp > ed){
			ed = temp;
			ided = id;
		}
	}
	cout << idst << " " << ided;

	system("pause");
	return 0;
}