#include<bits/stdc++.h>
using namespace std;
int count(int left, int right, int *power){
    if(left >= right)
        return 0;
    int min = INT_MAX, min_index = -1, cnt = 0;
    for(int i = left; i <= right; i++){
        if(power[i] < min){
            min = power[i];
            min_index = i;
        }
    }
    bool check[200000] = {0};
    for(int i = left; i <= right; i++){
        if(i >= min_index){
            if(check[power[i]-min])
                cnt++;
            if(check[power[i]+min])
                cnt++;
        }
        if(i <= min_index){
            check[power[i]] = true;
        }
    }
    return cnt + count(left, min_index-1, power) + count(min_index+1, right, power);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int power[n];
    for(int i = 0; i < n; i++){
        cin >> power[i];
    }
    cout << count(0, n-1, power) << endl;
    return 0;
}