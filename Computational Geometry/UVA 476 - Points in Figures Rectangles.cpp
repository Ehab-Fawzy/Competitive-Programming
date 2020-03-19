#include <bits/stdc++.h>

#define F first
#define S second
#define X real()
#define Y imag()
#define pb push_back
#define ll long long
#define all(x) x.begin() , x.end()
#define mod(x,m) ((x%m + m )%m)
using namespace std;
void OJ();

typedef complex<double> point;
struct rec{
    point a, b;
    bool contain( point& p ){
        return (p.X > a.X && p.Y < a.Y && p.X < b.X && p.Y > b.Y);
    }
};

point getPoint(){
    point p; double x , y;
    cin >> x >> y;
    p.real(x); p.imag(y);
    return p;
}
rec getRec(){
    rec ret;
    ret.a = getPoint();
    ret.b = getPoint();
    return ret;
}

vector<rec> vec;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char c;
    while ( cin >> c && c != '*' ){
        rec r = getRec();
        vec.pb(r);
    }

   // for ( auto i : vec )
     //   cout << i.a << " " << i.b << "\n";


    int cnt = 1;
    while ( true ){
        point p = getPoint();
        if ( p.X == 9999.9 && p.Y == 9999.9 ){
            break;
        }

        bool flag = true;
        for ( int i = 0; i < vec.size(); ++i ){
            if ( vec[i].contain(p) ){
                flag = false;
                cout << "Point " << cnt << " is contained in figure " << i + 1 << "\n";
            }
        }
        if ( flag )
            cout << "Point " << cnt << " is not contained in any figure\n";
        cnt++;
    }
    return  0;
}

void OJ(){
#ifndef ONLINE_JUDGE
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\in.txt" , "r" , stdin  );
   // freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\out.txt", "w" , stdout );
#endif // ONLINE_JUDGE
}

