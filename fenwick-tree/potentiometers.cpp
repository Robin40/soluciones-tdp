#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;++i)

template<class T> class FenwickTree {
	vector<T> arr;
	
public:
	FenwickTree(int n) {arr.assign(n+1, 0);}
	
	T query(int i) {
		T sum = 0;
		for (; i; i -= i&-i) sum += arr[i];
		return sum;
	}
	
	T query(int a, int b) {
		return query(b) - (a<=1 ? 0 : query(a-1));
	}
	
	void update(int i, T value) {
		for (; i < (int)arr.size(); i += i&-i)
			arr[i] += value;
	}
	
	T get(int i) {
		return query(i, i);
	}
	
	void set(int i, T value) {
		update(i, -get(i) + value);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	while (true) {
		int n;
		cin>>n;
		if (n == 0) break;
		FenwickTree<int> ft(n);
		rep(i,n) {
			int x;
			cin>>x;
			ft.update(i+1, x);
		}
		if (t != 1) cout<<endl;
		cout<<"Case "<<t++<<":"<<endl;
		while (true) {
			string cmd; int x, r, y;
			cin>>cmd;
			if (cmd == "S") {
				cin>>x>>r;
				ft.set(x, r);
			} else if (cmd == "M") {
				cin>>x>>y;
				cout<<ft.query(x, y)<<endl;
			} else if (cmd == "END") {
				break;
			} else {
				assert(false);
			}
		}
	}
	
	return 0;
}
