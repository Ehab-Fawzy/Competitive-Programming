#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ll long long
#define all(x) x.begin() , x.end()
#define mod(x,m) ((x%m + m )%m)
using namespace std;
void OJ();

typedef complex<double> point;
#define X real()
#define Y imag()

#define vec(a,b)            (b - a)
#define dot(a,b)            ((conj(a)*b).X)
#define cross(a,b)          ((conj(a)*b).Y)
#define polar(r,t)          (r*exp(point(0,t)))
#define angle(v)            atan2(v.X , v.Y)
#define length(v)           hypot(v.X , v.Y)
#define lengthSqr(v)        dot(v,v)
#define normalize(v)        (v/length(v))
#define rotate(v,t)         polar(v,t)
#define rotateAbout(v,t,a)  (rotate(vec(a,v),t) + a)
#define reflect(p,m)        (conj(p/m)*m)
#define mid(a,b)            (a+b/point(2,0))
#define perp(a)             (point(-a.Y,a.X))

point getPoint(){
    point ret;
    double x, y;
    cin >> x >> y;
    ret.real(x);
    ret.imag(y);
    return ret;
}

point a,b,c,d;
double x,y;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //OJ();

    while ( cin >> x >> y ){
        a.real(x); a.imag(y); b = getPoint(); c = getPoint(); d = getPoint();
        point ret;

        if      ( a == c ) ret = b + d - a;
        else if ( a == d ) ret = b + c - a;
        else if ( b == c ) ret = a + d - b;
        else if ( b == d ) ret = a + c - b;
        cout << fixed << setprecision(3) << ret.X << " " << ret.Y << "\n";
    }
    return  0;
}

void OJ(){
#ifndef ONLINE_JUDGE
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\in.txt" , "r" , stdin  );
   // freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\out.txt", "w" , stdout );
#endif // ONLINE_JUDGE
}

