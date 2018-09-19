#include<iostream>
#include<cstdio>
using namespace std;
const int enf = 1000010;
int room_table[enf];
int order_table_0[enf];
int order_table_1[enf];
int order_table_2[enf];
long long room;
long long sum;
int n;
int c[enf];
int ans;

bool okok(int mid){
    //cout << "iiinit mid: " << mid << endl;
    for(int i = 0; i<n+1; i++){
        c[i] = 0;
    }
    
    for(int i = 0; i<=mid; i++){
        //cout <<"L: " << L <<" R: " << R <<" add: "<< order_table_0[i] << endl;
        c[order_table_1[i] - 1] += order_table_0[i];
        c[order_table_2[i]] -= order_table_0[i];  
    }
    /*
    cout << "middle: "<< mid << endl;  
    for(int i = 0; i<n+1; i++){
        cout <<" c[" <<i<<"]: " << c[i] << endl;
    }*/
    long sum[n];
    sum[0] = c[0];
    for(int i = 1; i<n; i++){
        sum[i] = sum[i-1] + c[i];
    }

    for(int i = 0; i<n; i++){
        if(sum[i] > room_table[i]){
            return false;
        }
    }
    /*
    for(int i = 0; i<n; i++){
        room = 0;
        sum = 0;
        for(int j = 0; j<=i; j++){
            //cout << "sum: " << sum << " c[" <<j<<"]: " << c[j] << endl;
            sum += c[j];
        }
        room = room_table[i] - sum;
        //cout << "roomL : " << room  <<" sum: "<< sum  << endl;
        
        if(room<0){
            return false;
        }
    }*/

    return true;
}

int solve(int l,int r){
    int mid = 0;

    while(l <= r){
        mid = (l + r)/2;
        bool ook = okok(mid);
        if(ook == false) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
}  


int main(){
    //std::ios::sync_with_stdio(false);

    while(cin >> n){
        int m;
        scanf("%d", &m);
        //cout << "init: " << m << endl;
        for(int i = 0; i<n; i++) scanf("%d", room_table+i);
        
        for(int i = 0; i<m; i++) scanf("%d%d%d", order_table_0+i, order_table_1+i, order_table_2+i);
        
        int ans = solve(0,m-1);

        if(ans == m) printf("%d\n",0);
        else printf("%d\n%d\n",-1,ans+2);  
        
    }

    return 0;
}


