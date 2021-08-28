#include<iostream>
#include<cstring>
using namespace std;

bool panduan(char s[]){
	bool flag = true;
	int num_p = 0, num_t = 0, p_place = -3, t_place = -3;
	for(int j = 0; j < strlen(s); j++){
		if(s[j] != 'P' && s[j] != 'A' && s[j] != 'T'){
			flag = false;
			break;
		} else if(s[j] == 'P'){
			num_p++;
			if(num_p > 1){
				flag = false;
				break;
			}
			p_place = j;
		} else if(s[j] == 'T'){
			num_t++;
			if(num_t > 1){
				flag = false;
				break;
			}
			t_place = j;
			if(t_place - p_place == 2 && p_place != strlen(s) - t_place - 1){
				flag = false;
				break;
			} else if(t_place - p_place < 2){
				flag = false;
				break;
			} else if(t_place - p_place != 2 && strlen(s) - t_place - 1 != p_place * (t_place - p_place - 1)){

				flag = false;
				break;
			}
		}
	}
	if(num_t == 0){
		flag = false;
	}
	return flag;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		char s[105];
		scanf("%s", s);

		bool flag = panduan(s);

		if(flag){
			if(i != n - 1){
				printf("YES\n");
			} else{
				printf("YES");
			}
		} else{
			if(i != n - 1){
				printf("NO\n");
			} else{
				printf("NO");
			}
		}
	}

	return 0;
}