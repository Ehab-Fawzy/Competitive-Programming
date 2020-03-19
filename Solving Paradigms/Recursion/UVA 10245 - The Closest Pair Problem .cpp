#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<ll>
#define all(x) x.begin() , x.end()
#define mod(x,m) ((x%m + m )%m)

using namespace std;
void OJ();

#define ld long double

const int N = 5e4 + 90;

int n;
vector<pair<ld,ld>> vec;

ld dist( pair<ld,ld> a , pair<ld,ld> b ){
    return sqrtl( (a.F - b.F)*(a.F - b.F) + (a.S - b.S)*(a.S - b.S) );
}

ld go( int l , int r ){
    if ( l == r ){
        return 1e18;
    }
    if ( l + 1 == r ){
        return dist(vec[l] , vec[r]);
    }

    ld ret = 1e18;
    int mid = (l + r) >> 1;
    ret = min(ret , go(l , mid));
    ret = min(ret , go(mid , r));

    for ( int i = l; i <= r; ++i ){
        for ( int j = i + 1; j <= r; ++j ){
            if ( abs( vec[j].F - vec[i].F ) < ret ){
                ret = min(ret , dist(vec[i] , vec[j]));
            }
            else break;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //OJ();

    while ( cin >> n && n > 0 ){
        vec.clear(); vec.resize(n);
        for ( auto& i : vec ) cin >> i.F >> i.S;
        sort( all(vec) );

        ld ret = go(0 , vec.size() - 1);
        if ( ret >= 1e4 ){
            cout << "INFINITY\n";
        }
        else{
            cout << fixed << setprecision(4) << ret << "\n";
        }
    }
    return  0;
}

void OJ(){
#ifndef ONLINE_JUDGE
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\in.txt" , "r" , stdin  );
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\out.txt", "w" , stdout );
#endif // ONLINE_JUDGE
}

