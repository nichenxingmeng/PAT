#include<iostream>
#include<vector>
using namespace std;

int num[1010], n;
vector<int> path;

int flag = 0, ans;

void BFS(int s){
	if(s * 2 >= n){
        path.push_back(num[s]);
        printf("%d", path[0]);
        int temp = path[0];
        ans += path.size() - 1;
		for(int i = 1; i < path.size(); i++){
			printf(" %d", path[i]);
            if(path[i] >= temp){
                flag++;
            }else if(path[i] <= temp){
                flag += 2;
            }
            temp = path[i];
		}
		printf("\n");
        path.pop_back();
		return;
	}
	path.push_back(num[s]);
	if(s * 2 + 2 < n) BFS(s * 2 + 2);
	if(s * 2 + 1 < n) BFS(s * 2 + 1);
	path.pop_back();
}

int main(){
	scanf("%d", &n);
    fill(num, num + n, -1);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	BFS(0);
    if(ans == flag) printf("Min Heap");
    else if(ans * 2 == flag) printf("Max Heap");
    else printf("Not Heap");

	return 0;
}