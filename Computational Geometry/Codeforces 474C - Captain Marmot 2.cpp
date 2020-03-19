// https://codeforces.com/contest/474/problem/C
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ll long long
#define all(x) x.begin() , x.end()
#define mod(x,m) ((x%m + m )%m)
using namespace std;
void OJ();

typedef long double ld;
typedef complex<ld> point;
#define X real()
#define Y imag()
#define EPS 1e-6

point read(){
    ld x, y; cin >> x >> y; point ret(x,y);
    return ret;
}
ld dist( point a, point b ){
    return (a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y);
}

bool isSquare(vector<point> vec){
    sort( all(vec) , [](point a, point b){
        if ( a.X == b.X ) return a.Y < b.Y;
        return a.X < b.X;
    } );

    vector<ld> t;
    t.pb( dist(vec[0] , vec[1]) );
    t.pb( dist(vec[0] , vec[2]) );
    t.pb( dist(vec[1] , vec[3]) );
    t.pb( dist(vec[2] , vec[3]) );

    ld diag1 = dist(vec[1],vec[2]);
    ld diag2 = dist(vec[0],vec[3]);

    for ( int i = 0; i < 4; ++i )
        for ( int j = i + 1; j < 4; ++j )
            if ( sqrt(dist(vec[i] , vec[j])) < EPS || abs(t[i] - t[j]) > EPS )
                return false;
    return (abs(t[0]+t[1]-diag2) < EPS && abs(t[2]+t[3]-diag1) < EPS);
}

vector<point> home;
int go( int i , vector<point> vec ){
    if ( i >= 4 ){
        return isSquare(vec) ? 0 : 1e9;
    }

    int ret = 1e9;
    for ( int j = 0; j < 4; ++j ){
        ret = min(ret , go(i + 1 , vec) + j);
        vec[i] -= home[i];
        point r( -vec[i].Y , vec[i].X );
        vec[i] = r + home[i];
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); OJ();
    home.resize(4);

    int t;
    cin >> t;
    while ( t-- ){
        vector<point> vec(4);
        for ( int i = 0; i < 4; ++i ){
            vec[i] = read(); home[i] = read();
        }
        int ret = go(0,vec);
        cout << (ret > 1e8 ? -1 : ret) << "\n";
    }
    return  0;
}

void OJ(){
#ifndef ONLINE_JUDGE
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\in.txt" , "r" , stdin  );
    //freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\out.txt", "w" , stdout );
#endif // ONLINE_JUDGE
}
 