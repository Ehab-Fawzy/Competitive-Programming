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

typedef complex<long double> point;
#define X real()
#define Y imag()
#define vec(a,b)            (b - a)
#define polar(r,theta)      (r*exp(point(0,theta)))
#define rotate(v,theta)     polar(v,theta)
#define rotateAbout(v,t,a)  (rotate(vec(a,v),t) + a)
#define angel(v)            atan2(v.Y , v.X)
#define length(v)           hypot(v.Y , v.X)
#define EPS                 1e-6

struct info{
    point pos , home;
    void read(){
        long double a,b,c,d; cin >> a >> b >> c >> d;
        pos.real(a); pos.imag(b); home.real(c); home.imag(d);
    }
    point polarToCartesian( point polarPoint ){
        point ret;
        ret.real( length(polarPoint) * cos( angel(polarPoint) ) );
        ret.imag( length(polarPoint) * sin( angel(polarPoint) ) );
        return ret;
    }
    void move(){
        point polarPoint = polar( length(pos) , angel(pos) );
        point newP = rotateAbout(polarPoint, (90*acos(-1)/180.0), home);
        pos = polarToCartesian(newP);
    }
};

double dist( pair<long double,long double> a , pair<long double,long double> b ){
    return  (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

int go( int i , vector<info> v ){
    if ( i >= 4 ){
        vector<pair<long double,long double>> ans;
        for ( auto i : v ){
            ans.pb( {i.pos.X , i.pos.Y} );
        }
        for ( int j = 0; j < 4; ++j ){
            for ( int k = j + 1; k < 4; ++k ){
                if ( sqrt( dist( ans[j] , ans[k] ) ) < EPS ){
                    return 1e9;
                }
            }
        }
        long double d2 = dist(ans[0],ans[1]);
        long double d3 = dist(ans[0],ans[2]);
        long double d4 = dist(ans[0],ans[3]);

        if ( abs( d2 - d3 ) < EPS && abs( 2.0 * d2 - d4 ) < EPS && abs( 2.0 * dist(ans[1],ans[3]) - dist(ans[1],ans[2]) ) < EPS ) return 0;
        if ( abs( d3 - d4 ) < EPS && abs( 2.0 * d3 - d2 ) < EPS && abs( 2.0 * dist(ans[2],ans[1]) - dist(ans[2],ans[3]) ) < EPS ) return 0;
        if ( abs( d2 - d4 ) < EPS && abs( 2.0 * d2 - d3 ) < EPS && abs( 2.0 * dist(ans[1],ans[2]) - dist(ans[1],ans[3]) ) < EPS ) return 0;
        return 1e9;
    }

    int ret = 1e9;
    for ( int j = 0; j < 4; ++j ){
        ret = min(ret , go(i + 1 , v) + j);
        v[i].move();
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); OJ();

    int t;
    cin >> t;
    while ( t-- ){
        vector<info> v(4);
        for ( auto& i : v ) i.read();

        int ret = go(0,v);
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
 