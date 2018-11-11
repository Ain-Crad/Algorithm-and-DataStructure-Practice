/*
 *
 * Author : Aincrad
 *
 * Date : Wed  7 Nov 09:43:18 CST 2018
 *`
 */
 
#include <bits/stdc++.h>

using namespace std;

struct Degree{
	int in;
	int out;
};
int G[30][30];
Degree d[30];
int T, n;

void dfs(int x){
	for(int i = 0; i < 26; i++){
		if(G[x][i]){
			G[x][i] = G[i][0] = 0;
			dfs(i);
		}
	}
}

bool JudgeEulr(){
	vector<int> vec;
	for(int i = 0; i < 26; i++){
		if(d[i].in != d[i].out){
			vec.push_back(i);
		} 
	}
	int len = vec.size();
	if(len == 0) 
		return true;
	else if(len == 2){
		if((d[vec[0]].in - 1 == d[vec[0]].out && d[vec[1]].out - 1 == d[vec[1]].in) || (d[vec[0]].out - 1 == d[vec[0]].in && d[vec[1]].in - 1 == d[vec[1]].out))
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	cin >> T;
	while(T--){
		cin >> n;
		memset(G, 0, sizeof(G));
		memset(d, 0, sizeof(d));
		string s;
		int a, b;
		for(int i = 0; i < n; i++){
			cin >> s;
			int len = s.length();
			a = s[0] - 'a', b = s[len - 1] - 'a';
			G[a][b] = 1, G[b][a] = 1;
			d[a].out++, d[b].in++;
		}
		int cnt = 0;
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				if(G[i][j]){
					dfs(i);
					cnt++;
				}
			}
		}
		//cout << cnt << endl;
		if(cnt > 1){
			cout << "The door cannot be opened." << endl;
		}
		else{
			if(JudgeEulr())
				cout << "Ordering is possible." << endl;
			else
				cout << "The door cannot be opened." << endl;
		}
	}

	return 0;
}
