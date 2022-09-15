#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int power[n];
    for(int i = 0; i < n; i++){
        cin >> power[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        bool check[200000] = {0};
        int min = power[i];
        for(int j = i; j < n; j++){
            check[power[i]+power[j]] = true;
            if(power[i] >= power[j])
                check[power[i]-power[j]] = true;
            if(power[j] < min)
                min = power[j];
            if(check[power[j]] && abs(power[i]-power[j]) == min){
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}