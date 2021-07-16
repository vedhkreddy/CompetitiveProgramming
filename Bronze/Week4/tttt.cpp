#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool checkCell(char i, char j, char cell){
    bool b = (i == cell || j == cell);
    return i == cell || j == cell;
}

int main(){
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");
    vector<vector<char>> board;;
    for(int i = 0; i < 3; i++){
        board.push_back({});
        for(int j = 0; j < 3; j++){
            char a;
            fin >> a;
            board[i].push_back(a);
        }
        cout << endl;
    }
    int singlecount = 0;
    int doublecount = 0;

    for(char i = 'A'; i <= 'Z'; i++){
        for(int j = 0; j < 3; j++){
            if (board[j][0] == i && board[j][1] == i && board[j][2] == i){
                singlecount++;
            }
            else if(board[0][j] == i && board[1][j] == i && board[2][j] == i){
                singlecount++;
            }
        }
        if (board[0][0] == i && board[1][1] == i && board[2][2] == i){
            singlecount++;
        }
        else if (board[0][2] == i && board[1][1] == i && board[2][0] == i){
            singlecount++;
        }
        else{}
    }

    for(char i = 'A'; i <= 'Z'; i++){
        for(char j = i+1; j <= 'Z'; j++){
            for(int k = 0; k < 3; k++){
                if (checkCell(i, j, board[k][0]) == 1 && checkCell(i, j, board[k][1]) == 1 && checkCell(i, j, board[k][2]) == 1){
                    if (board[k][0] == board[k][1] && board[k][1] == board[k][2]) {
                    }
                    else{
                        doublecount++;
                    }
                }
                else if(checkCell(i, j, board[0][k]) == 1 && checkCell(i, j, board[1][k]) == 1 && checkCell(i, j, board[2][k]) == 1){
                    if (board[0][k] == board[1][k] && board[1][k] == board[2][k]) {
                    }
                    else{
                        doublecount++;
                    }
                }
            }
            if (checkCell(i, j, board[0][0]) == 1 && checkCell(i, j, board[1][1]) == 1 && checkCell(i, j, board[1][1]) == 1){
                if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                }
                else{
                    doublecount++;
                }
            }
            else if (checkCell(i, j, board[0][2]) == 1 && checkCell(i, j, board[1][1]) == 1 && checkCell(i, j, board[2][0]) == 1){
                if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                }
                else{
                    doublecount++;
                }
            }
            else{}
            }
    }

    fout << singlecount << endl << doublecount << endl;
}