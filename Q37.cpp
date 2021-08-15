#include <iostream>
using namespace std;

int n, m, a, b, c;
int cities[100][100];

void printArr(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<cities[i][j] <<" ";
        }
        cout<<"\n";
    }
}

int main(void){
    cin>>n>>m;

    //initialize
    for(int i = 0; i<100; i++){
        for(int j=0; j<100; j++){
            if(i==j)
                cities[i][j] = 0;
            else
                cities[i][j] = 1000000000;
        }
    }

    //read input
    for(int i = 0; i<m; i++){
        cin>>a>>b>>c;
        if(c<cities[a-1][b-1])
            cities[a-1][b-1] = c;
    }

    //floyd-warshall
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int temp = cities[i][k] + cities[k][j];
                if(cities[i][j]>temp)
                    cities[i][j] = temp;
            }
        }
    }

    //output
    printArr();

    return 0;
}