#include<bits/stdc++.h>
using namespace std;

struct SP{
	long double thuc;
	long double ao;
	void nhap(){
		cin >> thuc >> ao;
	}
};
void in(SP a){
	if(a.thuc == 0 && a.ao == 0){
		cout << "0" << endl;
	}
	else{
		if(a.thuc != 0){
			cout << a.thuc;
			if(a.ao > 0){
				cout << " + ";
			}
			else{
				if(a.ao < 0){
					cout << " - ";
				}
				else{
					cout << endl;
				}
			}
		}
		if(a.ao != 0){
			if(a.thuc != 0){
				if(a.ao == 1 || a.ao == -1){
					cout << "i" << endl;
				}
				else{
					cout << abs(a.ao) << "i" << endl;
				}
			}
			else{
				if(a.ao == 1){
					cout << "i" << endl;
				}
				else{
					if(a.ao == -1){
						cout << "-i" << endl;
					}
					else{
						cout << a.ao << "i" << endl;
					}
				}
			}
		}
	}
}
void cong(SP a, SP b){
	SP c;
	c.thuc = a.thuc + b.thuc;
	c.ao = a.ao + b.ao;
	in(c);
}
void tru(SP a, SP b){
	SP c;
	c.thuc = a.thuc - b.thuc;
	c.ao = a.ao - b.ao;
	in(c);
}
void nhan(SP a, SP b){
	SP c;
	c.thuc = a.thuc * b.thuc - a.ao * b.ao;
	c.ao = a.thuc * b.ao + a.ao * b.thuc;
	in(c);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		SP a, b;
		a.nhap();
		b.nhap();
		cong(a, b);
		tru(a, b);
		nhan(a, b);
	}
}