#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int solve(int N, int stalls[]){
    bool already_placed_first = false;
    restart:
    int big1 = 0;
    int big2 = 0;
    int min = 100001;       //one greater than max size of string
    //find largest two holes of zeros and the min hole of zero
    for(int i = 0; i < N; i++){
        int tmp = i;
        int count = 0;
        if (stalls[i] == 0){
            int indexposition = i;
            while (stalls[indexposition] == 0 && indexposition != N){
                count++;
                indexposition++;
            }
            i = indexposition - 1;
        }
        if (count > big1){
            big2 = big1;
            big1 = count;

        }
        else if(count > big2){
            big2 = count;
        }
        //holes in beginning and end don't count for min
        if (count < min && count != 0 && tmp != 0 && tmp != N-1){
            min = count;
        }
    }
    //zeros at start and end are special cases
    //find how many zeros there are at the start
    int startzeros = 0;
    if (stalls[0] == 0){
        int indexposition = 0;
        while (stalls[indexposition] == 0 && indexposition != N){
            startzeros++;
            indexposition++;
        }
    }
    //find how many zeros at end
    int endzeros = 0;
    if (stalls[N-1] == 0){
        int indexposition = N - 1;
        while (stalls[indexposition] == 0 && indexposition != -1){
            endzeros++;
            indexposition--;
        }
    }
    /*
    if starting zeros are greater than the max / 2 
    (that's what the max will be when insert a cow into the middle of the big string of zeros), 
    we can insert the cow at the first position giving us all instead of half space after it
    */
    if (float(big1) / 2 < startzeros){
        stalls[0] = 1;
        //stop is a boolean tracking whether we go around once more to place the second cow or not
        //already_placed_first is a boolean that makes the next round go into a specific case
        if (already_placed_first == false){
            already_placed_first = true;
            goto restart;
        }
        if (big1 > min + 1){
            return min + 1;
        }
        return big1;
    }
    //same thing as above except with end zeros
    else if(float(big1) / 2 < endzeros){
        stalls[N-1] = 1;
        if (already_placed_first == false){
            already_placed_first = true;
            goto restart;
        }
        if (big1 > min + 1){
            return min + 1;
        }
        return big1;
    }
    else{
         //if only placing 1, we place it in the biggest account for min
        if (already_placed_first == true){
            //if odd it is same as next even number
            if (big1 % 2 == 1){
                big1++;
            }
            int newbigsize = (big1/2) - 1;
            if (min < newbigsize){
                return min + 1;
            }
            return newbigsize + 1;
        }                                                                                                                                                                                                
        //if we can place both in the biggest string optimally, do it
        if (floor(float(big1) / 2) > big2){
            cout << big1;
            return ceil(float(big1) / 3);
        }
        //if not
        else{
            //place the cows in largest and second largest account for the min
            //we only care about big2 here because we want minimum, the first cow will go in big1
            
            //if odd it is same as next even number
            if (big2 % 2 == 1){
                big2++;
            }
            int newbigsize = (big2/2) - 1;
            if (newbigsize > min){
                return min + 1;
            }
            return newbigsize + 1;
        }
    }
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1035
    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out"); 
    int N;
    fin >> N;
    int stalls[N];
    for(int i = 0; i < N; i++){
        char a;
        fin >> a;
        int b = int(a) - 48;
        stalls[i] = b;
    }
    int solution = solve(N, stalls);
    fout << solution;
}