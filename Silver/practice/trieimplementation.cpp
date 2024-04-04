#include <bits/stdc++.h>
using namespace std;
int n;

//replace 26 with problem alphabet size
typedef struct node node;
struct node{
    struct node *below[26];
    bool marker;
};

// returns null initialized trie node
struct node *get(void){
    struct node *empty =  new node;
    empty->marker = false;
    for (int i = 0; i < 26; i++){
        empty->below[i] = NULL;
    }
    return empty;
}

void add(struct node *root, string key){
    struct node *create = root;
    for(int i = 0; i < size(key); i++){
        int ind = key[i] - 'a';
        if (!create->below[ind]) create->below[ind] = get();
        create = create->below[ind];
    }
    create->marker = true;
}

//create own search function for problem, traverse like the add function

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
       // add(s);
    }
}