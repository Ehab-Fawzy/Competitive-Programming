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

typedef complex<int> point;
struct rectangel{
    point a , b;
    int area(){
        return abs(a.X - b.X) * abs(a.Y - b.Y);
    }
};

void getPoint( point& p ){
    int in;
    cin >> in; p.real(in);
    cin >> in; p.imag(in);
}

void getRec( rectangel& rec ){
    getPoint(rec.a); getPoint(rec.b);
}

rectangel getIntersection( rectangel& x , rectangel& y ){
    rectangel ret;
    ret.a.real( max(x.a.X , y.a.X) );
    ret.a.imag( max(x.a.Y , y.a.Y) );
    ret.b.real( min(x.b.X , y.b.X) );
    ret.b.imag( min(x.b.Y , y.b.Y) );
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //OJ();

    int t;
    cin >> t;
    while ( t-- ){
        rectangel a , b , c;
        getRec(a);
        getRec(b);
        c = getIntersection(a , b);

        if ( c.a.X < c.b.X && c.a.Y < c.b.Y ){
            cout << c.a.X << " " << c.a.Y << " " << c.b.X << " " << c.b.Y << "\n";
        }
        else{
            cout << "No Overlap\n";
        }

        if ( t ) cout << "\n";
    }
    return  0;
}

void OJ(){
#ifndef ONLINE_JUDGE
    freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\in.txt" , "r" , stdin  );
    //freopen( "C:\\Users\\ehab\\Desktop\\Code Forces\\CF\\out.txt", "w" , stdout );
#endif // ONLINE_JUDGE
}

