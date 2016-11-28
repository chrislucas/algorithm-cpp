#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Point2D {
public:
    ll x, y;

    Point2D(ll, ll);

    ll euclidianDist(const Point2D & point) {
        ll diffX = abs(x - point.x), diffY = abs(y - point.y);
        return (ll)sqrt(diffX*diffX-diffY*diffY);
    }
};

Point2D::Point2D(ll x, ll y) : x(x), y(y) {}


class Edge {
public:
    ll xs, ys, xe, ye;
    Edge(ll xs, ll ys, ll xe, ll ye) : xs(xs), ys(ys), xe(xe), ye(ye) {}
    ll euclidianDistance() {
        return (xs-xe)*(xs-xe) + (ys-ye)*(ys-ye);
    }
};

/*
    Input
    N: numero de pontos
    X, Y: ponto no plano cartesiano
    Output
    Numero de subconjuntos de 3 pontos que formam um
    triangulo isosceles
*/

int main()
{
    int qPoints;
    vector<Point2D> points;
    while(scanf("%d", &qPoints) && qPoints > 0) {
        ll x, y;
        for(int i=0; i<qPoints; i++){
            scanf("%lld %lld", &x, &y);
            Point2D point2D(x, y);
            points.push_back(point2D);
        }
        ll distances [1111], answer = 0;
        for(int i=0; i<qPoints; i++) {
            for(int j=0; j<qPoints; j++) {
                Edge edge(points[i].x, points[i].y, points[j].x, points[j].y);
                distances[j] = edge.euclidianDistance();
            }
            sort(distances, distances+qPoints);
            long long counter = 1;
            distances[qPoints] = -1;
            for(int j=1; j<=qPoints; j++) {
                if(distances[j] != distances[j-1]) {
                    /*
                        A combinacao de pontos ABC, BCA, CBA ... formam o mesmo triangulo
                        A aresta AB e BA sao as mesmas, para evitar que seja contada 2x fazemos a conta abaixo
                    */
                    answer += counter*(counter-1)/2;
                    counter = 1;
                }
                else {
                    counter++;
                }
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}

void solver2Test() {
    int qPoints;
    while(scanf("%d", &qPoints) && qPoints > 0) {
        ll p2Dx[1024], p2Dy[1024];
        for(int i=0; i<qPoints; i++) {
            scanf("%lld %lld", p2Dx[i], p2Dy[i]);
        }
        ll distances [1024], answer = 0;
        for(int i=0; i<qPoints; i++) {
            for(int j=i+1; j<qPoints; j++) {
                Edge edge(p2Dx[i], p2Dy[i], p2Dx[j], p2Dy[j]);
                distances[j] = edge.euclidianDistance();
            }
            sort(distances/*+i*/, distances+qPoints);
            long long counter = 0;
            distances[qPoints] = -1;
            for(int j=0; j<qPoints-4; j++) {
                if(distances[j+1] != distances[j]) {

                }
                else {

                }
            }
        }
    }
    return;
}
