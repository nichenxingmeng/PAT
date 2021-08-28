#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;

	char a, b;
	int a1 = 0, a2 = 0, a3 = 0;
	int b1 = 0, b2 = 0, b3 = 0;
	int awin = 0, alose = 0, aping = 0;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(a == b) aping++;
		else if(a == 'C' && b == 'J'){
			a1++;
			awin++;
		} else if(a == 'C' && b == 'B'){
			b3++;
			alose++;
		} else if(a == 'J' && b == 'C'){
			alose++;
			b1++;
		} else if(a == 'J' && b == 'B'){
			awin++;
			a2++;
		} else if(a == 'B' && b == 'C'){
			awin++;
			a3++;
		} else if(a == 'B' && b == 'J'){
			alose++;
			b2++;
		}
	}
	printf("%d %d %d\n", awin, aping, alose);
	printf("%d %d %d\n", alose, aping, awin);

	if(max(max(a1, a2), a3) == a3) printf("B ");
	else if(max(max(a1, a2), a3) == a1) printf("C ");
	else printf("J ");

	if(max(max(b1, b2), b3) == b3) printf("B");
	else if(max(max(b1, b2), b3) == b1) printf("C");
	else printf("J");
	
	system("pause");
	return 0;
}