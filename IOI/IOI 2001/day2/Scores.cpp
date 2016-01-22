    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
    #include <vector>
    #define FOR(i,a,b) for(i=a; i<=b; i++)
    #define FOR2(i,n) FOR(i,0,n-1)
    #define MAXN 1005
    using namespace std;
    vector < int > G[MAXN];
    int N;
    int B[MAXN] , V[MAXN];
    int MAX1[MAXN] , MAX2[MAXN];
    void rec(int x,int s)
    {
    if(x == 1 && s == 1) return;
     
    vector < int > :: iterator it;
    for(it = G[x].begin(); it != G[x].end(); ++it)
    rec(*it,1);
     
    int a(0),b,c,d(123123123);
     
    for(it = G[x].begin(); it != G[x].end(); ++it)
    {
    if(MAX1[*it] > MAX2[*it] && (MAX1[*it] > a))
    {
    a = MAX1[*it];
    b = MAX2[*it];
    }
    if(MAX2[*it] < d)
    {
    d = MAX2[*it];
    c = MAX1[*it];
    }
    }
    if(a)
    {
    if(B[x] == 1)
    {
    MAX1[x] = max( a , V[x] );
    MAX2[x] = b;
    }
    else
    {
    MAX1[x] = a;
    MAX2[x] = max( b , V[x] );
    }
    }
    else
    {
    if(B[x] == 1)
    {
    MAX1[x] = max( c , V[x] );
    MAX2[x] = d;
    }
    else
    {
    MAX1[x] = c;
    MAX2[x] = max( d , V[x] );
    }
    }
    }
    int find(int x)
    {
    int maxi(0),a,i,mini(123123123),b,t;
     
    FOR2(i,(int)G[x].size())
    {
    t = G[x][i];
     
    if(MAX1[t] > MAX2[t] && MAX1[t] > maxi)
    {
    maxi = MAX1[t];
    a = i;
    }
    if(MAX2[t] < mini)
    {
    mini = MAX2[t];
    b = i;
    }
    }
     
    return maxi ? G[x][a] : G[x][b];
     
    }
    void solve()
    {
    int a,i,j;
    scanf("%d",&N);
    FOR(i,1,N)
    FOR(j,1,N)
    {
    scanf("%d",&a);
    if(a) G[i].push_back(j);
    }
     
    FOR(i,1,N) scanf("%d",B+i);
    FOR(i,1,N) scanf("%d",V+i);
     
    rec(1,0);
     
    int cur(1);
     
    while(1)
    {
    if(B[cur] == 1)
    {
    cur = find(cur);
    cout << cur << endl << flush;
    }
    else
    cin >> cur;
    if(cur == 1) exit(0);
    }
     
    }
    int main()
    {
    solve();
    return 0;
    }
