#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z(const string &s);

int main(){
	string s;
  cin >> s;
  vector<int> Z = z(s);

  for(auto e : Z)
    cout << e << " ";

	cout << endl;
	return 0;
}

vector<int> z(const string &s){
	int n = s.size(), L = 0, R = 0;
	vector<int> zs(n, 0);

	for(int i=1; i<n; i++){
		if(i <= R)
			zs[i] = min(zs[i - L], R - i +1);

		while (zs[i] + i < n and s[zs[i]] == s[i + zs[i]])
			zs[i]++;

		if(R < i + zs[i] - 1)
			L = i, R = i + zs[i] - 1;
	}

return zs;
}
