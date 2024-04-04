#include <bits/stdc++.h>
using namespace std;

typedef struct node node;
struct node{
    struct node *below[26];
    bool marker;
    long long end = 0;
};

// returns null initialized trie node
struct node *get(void){
    struct node *empty =  new node;
    empty->marker = false;
    for (long long i = 0; i < 26; i++){
        empty->below[i] = NULL;
    }
    return empty;
}

void add(struct node *root, string key){
    struct node *create = root;
    for(long long i = 0; i < size(key); i++){
        long long ind = key[i] - 'a';
        if (!create->below[ind]) create->below[ind] = get();
        create = create->below[ind];
        create->end++;
    }
    create->marker = true;
}

long long upd(struct node *root, string key){
    long long res = 0;
    struct node *traverse = root;
    for(long long i = 0; i < size(key); i++){
        long long ind = key[i] - 'a';
        if (!traverse->below[ind]) break;
        traverse = traverse->below[ind];
        res += traverse->end;
    }   
    return res;
}

int main(){
    long long n; cin >> n;
    node *root = get();
    long long res = 2 * n;
    long long sum = 0;
    vector<string> v;
    for(long long i = 0; i < n; i++){
        string s; cin >> s; sum += size(s);
        add(root, s);
        v.push_back(s);
    }
    res *= sum;
    long long take = 0;
    for(long long i = 0; i < n; i++){
        string s = v[i]; reverse(s.begin(), s.end());
        take += upd(root, s);
    }
    //create erase function, then reverse it, then implement the update functions simulatneously
    //we don't have to erase the same root, we just assign the root to a null node

    res -= 2*take;
    cout << res << endl;
}
