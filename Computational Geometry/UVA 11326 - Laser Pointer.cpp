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

#define ld long double
ld l,w,t;

ld distance( point& a , point& b ){
    return sqrtl( (a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y) );
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); //OJ();

    int cse;
    cin >> cse;
    while ( cse-- ){
        cin >> l >> w >> t;
        t *= acos(-1) / 180.0;
        ld len = w / sin(t);
        ld bas = len * cos(t);
        ld sum = 0.0 , dist = 0.0;

        while ( sum + 2*bas <= l ){
            sum += 2*bas; dist += 2*len;
        }

        if ( sum + bas <= l ){
            sum += bas;
            dist += len;

            ld rem = l - sum;
            ld tal = rem * tan(t);

            point org(0,0);
            point a(sum,w);
            point b(l,w - tal);

            dist += distance(a , b);
            cout << fixed << setprecision(3) << dist / distance(org,b) << "\n";
        }
        else{
            ld rem = l - sum;
            ld tal = rem * tan(t);

            point org(0,0);
            point a(sum,0);
            point b(l,tal);

            dist += distance(a , b);
            cout << fixed << setprecision(3) << dist / distance(org,b) << "\n";
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

