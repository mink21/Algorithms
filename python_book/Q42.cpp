#include <iostream>
using namespace std;

int g, p, cnt;
int decks[100000];

int findParent(int start){
    if(decks[start] != start)
        decks[start] = findParent(decks[start]);
    return decks[start];
}

void unionDecks(int deckOne, int deckTwo){
    int a = findParent(deckOne);
    int b = findParent(deckTwo);
    if(a<b)
        decks[b] = a;
    else
        decks[a] = b;
}

void printDeck(){
    for(int i = 0; i<=g; i++)
        cout<<decks[i] <<" ";
    cout<<"\n";
}

void solve(void){
    int deckNum, parent;
    cnt = 0; 
    for(int i = 0; i < p; i++){
        cin>>deckNum;
        parent = findParent(deckNum);
        if(parent == 0)
            break;
        unionDecks(parent, parent-1);
        cnt++;
    }
    cout<< cnt<<"\n";
}

int main (void){
    cin>>g>>p;
    for(int i = 0; i<=g; i++){
        decks[i] = i;
    }
    solve();
    return 0;
}