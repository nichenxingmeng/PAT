#include<iostream>
#include<string>
using namespace std;

const double INF = 1000000000;
const int maxn = 1020;
int n, m, k, D;
double G[maxn][maxn], d[maxn];
bool vis[maxn] = {false};

int change(string str){
	if(str[0] >= '0' && str[0] <= '9'){
		int cnt = 1, ans = 0;
		for(int i = str.length() - 1; i >= 0; i--){
			ans += (str[i] - '0') * cnt;
			cnt *= 10;
		}
		return ans;
	}else{
		str.erase(str.begin());
		int cnt = 1, ans = 0;
		for(int i = str.length() - 1; i >= 0; i--){
			ans += (str[i] - '0') * cnt;
			cnt *= 10;
		}
		return ans + n;
	}
}

void Dijkstra(int s){
	d[s] = 0;
	for(int i = 1; i <= n + m; i++){
		int u = -1, MIN = INF;
		for(int j = 1; j <= n + m; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 1; v <= n + m; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
	return;
}


int main(){
	string str1, str2;
    int st, ed;
	scanf("%d%d%d%d", &n, &m, &k, &D);
	fill(G[0], G[0] + maxn * maxn, INF);
	for(int i = 0; i < k; i++){
		cin >> str1 >> str2;
		st = change(str1);
		ed = change(str2);
		scanf("%lf", &G[st][ed]);
		G[ed][st] = G[st][ed];
	}

	int temp;
	double max = -1;
	double av = 0;
	for(int i = n + 1; i <= n + m; i++){
		fill(d, d + maxn, INF);
        fill(vis, vis + maxn, false);
		Dijkstra(i);
		bool flag = false;
		double min = INF;
		for(int j = 1; j <= n; j++){
			if(d[j] == INF || d[j] > D){
				flag = true;
				break;
			}
			if(d[j] < min){
				min = d[j];
			}
		}
		if(flag) continue;
		if(min > max){
			max = min;
			temp = i;
			double ans = 0;
			for(int j = 1; j <= n; j++){
				ans += d[j];
			}
			av = ans / n;
		}else if(min == max){
            double ans = 0;
			for(int j = 1; j <= n; j++){
				ans += d[j];
			}
            if(ans / n < av){
                temp = i;
                av = ans / n;
            }
        }
	}
	if(max != -1){
		cout << "G" << temp - n << endl;
		printf("%.1lf %.1lf", max, av);
	}else{
		cout << "No Solution";
	}

	return 0;
}