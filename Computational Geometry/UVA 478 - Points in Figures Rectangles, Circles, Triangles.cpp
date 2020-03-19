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
double distance( point& x , point& y ){
    return sqrt( (x.X - y.X)*(x.X - y.X) + (x.Y - y.Y)*(x.Y - y.Y) );
}
struct rec{
    point a, b;
    bool contain( point& p ){
        return (p.X > a.X && p.Y < a.Y && p.X < b.X && p.Y > b.Y);
    }
};
struct circle{
    point center; double r;
    bool contain( point& p ){
        double dist = distance(p , center);
        return dist < r;
    }
};

struct triangel{
    point a , b, c;
    bool contain( point& p ){
        bool ret = abs(area(a,b,p) + area(a,c,p) + area(b,c,p) - area(a,b,c)) < 1e-6;
        ret &= !point_on_line(p,a,b);
        ret &= !point_on_line(p,a,c);
        ret &= !point_on_line(p,c,b);
        return ret;
    }
    double area( point& A, point& B, point& C ){
        double ret = A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y);
        return abs( 0.5 * ret );
    }
    bool point_on_line( point& p, point& x , point& y ){
        return abs( distance(p,x) + distance(p,y) - distance(x,y) ) < 1e-6;
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

circle getCircle(){
    circle c;
    c.center = getPoint();
    cin >> c.r;
    return c;
};
triangel getTriangel(){
    triangel ret;
    ret.a = getPoint();
    ret.b = getPoint();
    ret.c = getPoint();
    return ret;
};

struct fig{
    char type; int idx;
    fig( char _type , int _idx ){
        type = _type; idx = _idx;
    }
};

vector<rec> r;
vector<circle>c;
vector<triangel>t;
vector<fig> vec;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //OJ();

    char chr; int rcnt = 0 , ccnt = 0 , tcnt = 0;
    while ( cin >> chr && chr != '*' ){
        if ( chr == 'r' ){
            rec rc = getRec(); r.pb(rc);
            vec.pb({chr , rcnt++});
        }
        if ( chr == 'c' ){
            circle cr = getCircle(); c.pb(cr);
            vec.pb({chr , ccnt++});
        }
        if ( chr == 't' ){
            triangel tr = getTriangel(); t.pb(tr);
            vec.pb({chr , tcnt++});
        }
    }


    int cnt = 1;
    while ( true ){
        point p = getPoint();
        if ( p.X == 9999.9 && p.Y == 9999.9 ){
            break;
        }

        bool flag = true;
        for ( int i = 0; i < vec.size(); ++i ){
            if ( vec[i].type == 'r'){
                if ( r[ vec[i].idx ].contain(p) ){
                    flag = false;
                    cout << "Point " << cnt << " is contained in figure " << i + 1 << "\n";
                }
            }
            if ( vec[i].type == 'c'){
                if ( c[ vec[i].idx ].contain(p) ){
                    flag = false;
                    cout << "Point " << cnt << " is contained in figure " << i + 1 << "\n";
                }
            }
            if ( vec[i].type == 't'){
                if ( t[ vec[i].idx ].contain(p) ){
                    flag = false;
                    cout << "Point " << cnt << " is contained in figure " << i + 1 << "\n";
                }
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

