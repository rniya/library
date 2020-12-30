/**
 * @brief geometry
 * @docs docs/geometry/geometry.md
 */

#pragma once

#include "../base.hpp"

#pragma region Geometry
const double EPS=1e-8,PI=acos(-1);
inline bool EQ(double a,double b){return fabs(b-a)<EPS;}

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator-() const {return Point(-x,-y);}
    Point operator+(Point p) const {return Point(x+p.x,y+p.y);}
    Point operator-(Point p) const {return Point(x-p.x,y-p.y);}
    Point operator*(double t) const {return Point(x*t,y*t);}
    Point operator*(Point p) const {return Point(x*p.x-y*p.y,x*p.y+y*p.x);}
    Point operator/(double t) const {return Point(x/t,y/t);}
    bool operator<(const Point &p) const {return x!=p.x?x<p.x:y<p.y;}
    bool operator==(const Point &p) const {return EQ(x,p.x)&&EQ(y,p.y);}
    friend istream &operator>>(istream &is,Point &p){
        is >> p.x >> p.y;
        return is;
    }
    friend ostream &operator<<(ostream &os,Point p){
        os << fixed << setprecision(10) << p.x << ' ' << p.y;
        return os;
    }
};

struct Line{
    Point a,b;
    Line(){}
    Line(Point a,Point b):a(a),b(b){}
    friend istream &operator>>(istream &is,Line &l){
        is >> l.a >> l.b;
        return is;
    }
    friend ostream &operator<<(ostream &os,Line l){
        os << l.a << " to " << l.b;
        return os;
    }
};

struct Segment:Line{
    Segment(){}
    Segment(Point a,Point b):Line(a,b){}
};

struct Circle{
    Point c;
    double r;
    Circle(){}
    Circle(Point c,double r):c(c),r(r){}
    friend istream &operator>> (istream &is,Circle &c){
        is >> c.c >> c.r;
        return is;
    }
    friend ostream &operator<<(ostream &os,Circle &c){
        os << c.c << ' ' << c.r;
        return os;
    }
};

using Polygon=vector<Point>;

double dot(const Point &,const Point &);
double cross(const Point &,const Point &);
double norm(const Point &);
double abs(const Point &);
Point projection(const Line &,const Point &);
Point reflection(const Line &,const Point &);
double arg(const Point &);
double radian_to_degree(const double &);
double degree_to_radian(const double &);
Point polar(const double &,const double &);
Point rotate(const Point &,const double &);
double get_angle(const Point &,const Point &,const Point &);
enum{COUNTER_CLOCKWISE=1,CLOCKWISE=-1,ONLINE_BACK=2,ONLINE_FRONT=-2,ON_SEGMENT=0};
int ccw(const Point &,Point,Point);
bool orthogonal(const Point &,const Point &);
bool orthogonal(const Point &,const Point &,const Point &,const Point &);
bool orthogonal(const Line &,const Line &);
bool parallel(const Point &,const Point &);
bool parallel(const Point &,const Point &);
bool parallel(const Point &,const Point &,const Point &,const Point &);
bool parallel(const Line &,const Line &);
bool intersect(const Line &,const Point &);
bool intersect(const Line &,const Line &);
bool intersect(const Line &,const Segment &);
bool intersect(const Segment &,const Point &);
bool intersect(const Segment &,const Segment &);
bool intersect(const Circle &,const Line &);
int intersect(const Circle &,const Segment &);
bool intersect(Circle,Circle);
int count_tangent(Circle,Circle);
double distance(const Point &,const Point &);
double distance(const Line &,const Point &);
double distance(const Line &,const Line &);
double distance(const Segment &,const Point &);
double distance(const Segment &,const Segment &);
double distance(const Line &,const Segment &);
Point crosspoint(const Line &,const Line &);
Point crosspoint(const Segment &,const Segment &);
pair<Point,Point> crosspoint(const Circle &,const Line &);
pair<Point,Point> crosspoint(const Circle &,const Segment &);
pair<Point,Point> crosspoint(const Circle &,const Circle &);
Circle circumcenter(Point,Point,const Point &);
pair<Point,Point> center_given_radius(const Point &,const Point &,const double &);
pair<Point,Point> tangent(const Circle &,const Point &);
vector<Line> common_tangent(Circle,Circle);
double area(const Polygon &);
enum{OUT,ON,IN};
int contain(const Polygon &,const Point &);
int contain(const Circle &,const Point &);
bool is_convex(const Polygon &);
Polygon convex_hull(Polygon,bool);
double convex_diameter(Polygon);
Polygon convex_cut(const Polygon &,const Line &);



double dot(const Point &a,const Point &b){return a.x*b.x+a.y*b.y;}
double cross(const Point &a,const Point &b){return a.x*b.y-a.y*b.x;}
double norm(const Point &p){return p.x*p.x+p.y*p.y;}
double abs(const Point &p){return sqrt(norm(p));}

Point projection(const Line &l,const Point &p){
    double t=dot(p-l.a,l.b-l.a)/norm(l.b-l.a);
    return l.a+(l.b-l.a)*t;
}
Point reflection(const Line &l,const Point &p){
    return p+(projection(l,p)-p)*2.0;
}

double arg(const Point &p){return atan2(p.y,p.x);}
double radian_to_degree(const double &r){return r*180.0/PI;}
double degree_to_radian(const double &d){return d*PI/180.0;}
Point polar(const double &r,const double &theta){return Point(cos(theta),sin(theta))*r;}
Point rotate(const Point &p,const double &theta){
    return Point(cos(theta)*p.x-sin(theta)*p.y,sin(theta)*p.x+cos(theta)*p.y);
}
double get_angle(const Point &a,const Point &b,const Point &c){
    const Point v=b-a,w=c-b;
    double alpha=arg(v),beta=arg(w);
    if (alpha>beta) swap(alpha,beta);
    double theta=beta-alpha;
    return min(theta,2*PI-theta);
}

int ccw(const Point &a,Point b,Point c){
    b=b-a,c=c-a;
    if (cross(b,c)>EPS) return COUNTER_CLOCKWISE;
    if (cross(b,c)<-EPS) return CLOCKWISE;
    if (dot(b,c)<0) return ONLINE_BACK;
    if (norm(b)<norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool orthogonal(const Point &a,const Point &b){return EQ(dot(a,b),0.0);}
bool orthogonal(const Point &a,const Point &b,const Point &c,const Point &d){return orthogonal(b-a,d-c);}
bool orthogonal(const Line &l,const Line &m){return EQ(dot(l.b-l.a,m.b-m.a),0.0);}
bool parallel(const Point &a,const Point &b){return EQ(cross(a,b),0.0);}
bool parallel(const Point &a,const Point &b,const Point &c,const Point &d){return parallel(b-a,d-c);}
bool parallel(const Line &l,const Line &m){return EQ(cross(l.b-l.a,m.b-m.a),0.0);}

bool intersect(const Line &l,const Point &p){return abs(ccw(l.a,l.b,p))!=COUNTER_CLOCKWISE;}
bool intersect(const Line &l,const Line &m){return abs(cross(l.b-l.a,m.b-m.a))>EPS||abs(cross(l.b-l.a,m.b-l.a))<EPS;}
bool intersect(const Line &l,const Segment &s){return cross(l.b-l.a,s.a-l.a)*cross(l.b-l.a,s.b-l.a)<EPS;}
bool intersect(const Segment &s,const Point &p){return ccw(s.a,s.b,p)==ON_SEGMENT;}
bool intersect(const Segment &s,const Segment &t){return ccw(s.a,s.b,t.a)*ccw(s.a,s.b,t.b)<=0&&ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b)<=0;}
bool intersect(const Circle &c,const Line &l){return distance(l,c.c)<=c.r+EPS;}
int intersect(const Circle &c,const Segment &s){
    Point h=projection(s,c.c);
    double d1=abs(c.c-s.a),d2=abs(c.c-s.b);
    if (norm(h-c.c)-c.r*c.r>EPS) return 0;
    if (d1<c.r+EPS&&d2<c.r+EPS) return 0;
    if ((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;
    if (dot(s.a-h,s.b-h)<0) return 2;
    return 0;
}
bool intersect(Circle a,Circle b){
    int c=count_tangent(a,b);
    return 1<=c&&c<=3;
}
int count_tangent(Circle a,Circle b){
    if (a.r<b.r) swap(a,b);
    double d=abs(a.c-b.c);
    if (a.r+b.r<d) return 4;
    if (EQ(a.r+b.r,d)) return 3;
    if (a.r-b.r<d) return 2;
    if (EQ(a.r-b.r,d)) return 1;
    return 0;
}

double distance(const Point &a,const Point &b){return abs(b-a);}
double distance(const Line &l,const Point &p){return distance(p,projection(l,p));}
double distance(const Line &l,const Line &m){return intersect(l,m)?0:distance(l,m.a);}
double distance(const Segment &s,const Point &p){
    Point h=projection(s,p);
    return intersect(s,h)?distance(p,h):min(distance(p,s.a),distance(p,s.b));
}
double distance(const Segment &s,const Segment &t){
    return intersect(s,t)?0:min({distance(s,t.a),distance(s,t.b),distance(t,s.a),distance(t,s.b)});
}
double distance(const Line &l,const Segment &s){
    return intersect(l,s)?0:min(distance(l,s.a),distance(l,s.b));
}

Point crosspoint(const Line &l,const Line &m){
    assert(intersect(l,m));
    double d1=cross(l.b-l.a,m.b-m.a),d2=cross(l.b-l.a,l.b-m.a);
    if (EQ(abs(d1),0.0)&&EQ(abs(d2),0.0)) return m.a;
    return m.a+(m.b-m.a)*d2/d1;
}
Point crosspoint(const Segment &s,const Segment &t){
    assert(intersect(s,t));
    return crosspoint(Line(s),Line(t));
}
pair<Point,Point> crosspoint(const Circle &c,const Line &l){
    assert(intersect(c,l));
    Point h=projection(l,c.c);
    Point e=(l.b-l.a)/abs(l.b-l.a)*sqrt(c.r*c.r-norm(h-c.c));
    return minmax(h-e,h+e);
}
pair<Point,Point> crosspoint(const Circle &c,const Segment &s){
    assert(intersect(c,s));
    auto res=crosspoint(c,Line(s));
    if (intersect(c,s)==2) return res;
    return intersect(s,res.first)?make_pair(res.first,res.first):make_pair(res.second,res.second);
}
pair<Point,Point> crosspoint(const Circle &a,const Circle &b){
    assert(intersect(a,b));
    double d=distance(a.c,b.c);
    double alpha=acos((a.r*a.r+d*d-b.r*b.r)/(2*a.r*d));
    double theta=arg(b.c-a.c);
    return minmax(a.c+polar(a.r,theta+alpha),a.c+polar(a.r,theta-alpha));
}

Circle circumcenter(Point a,Point b,const Point &c){
    a=(a-c)*0.5; b=(b-c)*0.5;
    Point center=c+crosspoint(Line(a,a*Point(1.0,1.0)),Line{b,b*Point(1.0,1.0)});
    return Circle{center,abs(c-center)};
}
pair<Point,Point> center_given_radius(const Point &a,const Point &b,const double &r){
    Point m=(b-a)*0.5;
    double d1=abs(m);
    assert(!(EQ(d1,0.0)||d1>r));
    double d2=sqrt(r*r-d1*d1);
    Point n=m*Point(0.0,1.0)*d2/d1;
    return minmax(a+m-n,a+m+n);
}
pair<Point,Point> tangent(const Circle &c,const Point &p){
    return crosspoint(c,Circle(p,sqrt(norm(c.c-p)-c.r*c.r)));
}
vector<Line> common_tangent(Circle a,Circle b){
    vector<Line> res;
    if (a.r<b.r) swap(a,b);
    double g=distance(a.c,b.c);
    if (EQ(g,0.0)) return res;
    Point u=(b.c-a.c)/g;
    Point v=rotate(u,PI*0.5);
    for (int s:{-1,1}){
        double h=(a.r+s*b.r)/g;
        if (EQ(1.0-h*h,0.0)) res.emplace_back(a.c+u*a.r,a.c+(u+v)*a.r);
        else if (1.0-h*h>0.0){
            Point U=u*h,V=v*sqrt(1-h*h);
            res.emplace_back(a.c+(U+V)*a.r,b.c-(U+V)*b.r*s);
            res.emplace_back(a.c+(U-V)*a.r,b.c-(U-V)*b.r*s);
        }
    }
    return res;
}

double area(const Polygon &P){
    int n=P.size();
    double res=0;
    for (int i=0;i<n;++i) res+=cross(P[i],P[(i+1)%n]);
    return res*0.5;
}

int contain(const Polygon &P,const Point &p){
    int n=P.size();
    bool in=false;
    for (int i=0;i<n;++i){
        Point a=P[i]-p,b=P[(i+1)%n]-p;
        if (a.y>b.y) swap(a,b);
        if (a.y<=0&&0<b.y&&cross(a,b)<0) in=!in;
        if (cross(a,b)==0&&dot(a,b)<=0) return ON;
    }
    return in?IN:OUT;
}
int contain(const Circle &c,const Point &p){
    double d=distance(c.c,p);
    return EQ(d,c.r)?ON:d<c.r?IN:OUT;
}

bool is_convex(const Polygon &P){
    int n=P.size();
    for (int i=0;i<n;++i){
        if (ccw(P[(i+n-1)%n],P[i],P[(i+1)%n])==CLOCKWISE){
            return false;
        }
    }
    return true;
}
Polygon convex_hull(Polygon P,bool ONSEG){
    int n=P.size(),k=0;
    if (n<=2) return P;
    sort(P.begin(),P.end());
    Polygon ch(2*n);
    for (int i=0;i<n;ch[k++]=P[i++]){
        if (ONSEG) while (k>=2&&ccw(ch[k-2],ch[k-1],P[i])==CLOCKWISE) --k;
        else while (k>=2&&ccw(ch[k-2],ch[k-1],P[i])!=COUNTER_CLOCKWISE) --k;
    }
    for (int i=n-2,t=k+1;i>=0;ch[k++]=P[i--]){
        if (ONSEG) while (k>=t&&ccw(ch[k-2],ch[k-1],P[i])==CLOCKWISE) --k;
        else while (k>=t&&ccw(ch[k-2],ch[k-1],P[i])!=COUNTER_CLOCKWISE) --k;
    }
    ch.resize(k-1);
    int start=0;
    for (int i=1;i<k-1;++i){
        if (EQ(ch[i].y,ch[start].y)?ch[i].x<ch[start].x:ch[i].y<ch[start].y) start=i;
    }
    rotate(ch.begin(),ch.begin()+start,ch.end());
    return ch;
}

double convex_diameter(Polygon P){
    if (!is_convex(P)) P=convex_hull(P,false);
    int n=P.size();
    int is=0,js=0;
    for (int i=1;i<n;++i){
        if (P[i].y>P[is].y) is=i;
        if (P[i].y<P[js].y) js=i;
    }
    double maxd=norm(P[is]-P[js]);
    int i,maxi,j,maxj;
    i=maxi=is; j=maxj=js;
    do {
        if (cross(P[(i+1)%n]-P[i],P[(j+1)%n]-P[j])>=0) j=(j+1)%n;
        else i=(i+1)%n;
        if (maxd<norm(P[i]-P[j])){
            maxd=norm(P[i]-P[j]);
            maxi=i; maxj=j;
        }
    } while (i!=is||j!=js);
    return sqrt(maxd);
}

Polygon convex_cut(const Polygon &P,const Line &l){
    int n=P.size();
    Polygon res;
    for (int i=0;i<n;++i){
        Point cur=P[i],nxt=P[(i+1)%n];
        if (ccw(l.a,l.b,cur)!=CLOCKWISE) res.emplace_back(cur);
        if (ccw(l.a,l.b,cur)*ccw(l.a,l.b,nxt)<0) res.emplace_back(crosspoint(Segment(cur,nxt),l));
    }
    return res;
}

#pragma endregion