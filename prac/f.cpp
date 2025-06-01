#include <bits/stdc++.h>
using namespace std;

bool validString(string s){
	for (char c : s){
		if (!islower(c) && !isdigit(c)) {
			return false;
		}
	}
	return true;
}	

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;	
		string s; cin >> s;
		bool good = true;
		if (!validString(s)) {cout << "NO"; continue;}
		int lastdig = 0; int lastchar = 'a';
		for (int i = 0; i < n; i++){
			if (i != 0){
				if (isdigit(s[i]) && islower(s[i-1])){
					good = false;
				}
			}
			if ((isdigit(s[i]) && s[i] < lastdig)){
				good = false;
			}
			else{
				if (s[i] < lastchar && islower(s[i])){
					good = false;
				}
			}
			if (isdigit(s[i])) lastdig = s[i];
			else {lastchar = s[i];}
						
		}
		if (good == false) cout << "NO" << endl;
		else{cout << "YES" << endl;}
	}
}
			
