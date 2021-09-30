#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int flowers[N];
    int count = 0;
	for(int i = 0; i < N; i++){
		cin >> flowers[i];
	}
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            int petalcount = 0;
            for(int z = i; z <= j; z++){
                petalcount += flowers[z];
            }
            for(int z = i; z <= j; z++){
                if (float(flowers[z]) == float(float(petalcount) / (float(j) - float(i) + 1.0))){
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
}