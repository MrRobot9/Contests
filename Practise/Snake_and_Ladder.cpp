#include <bits/stdc++.h>

#define ff first
#define mp make_pair
#define ss second
#define pb push_back


using namespace std;
typedef long long LL;


int bfsPath(int source, int dest, int* const dx, const map<int,int> &snakes, const map<int,int> &ladder)
{


    queue<pair<int,int> > Que;
    map<int, bool> visited;

    Que.push(mp(source, 0));

    while (!Que.empty()) {

        pair<int, int> temp = Que.front();
        Que.pop();
        if (temp.ff == dest)
            return temp.ss;
        int x = temp.ff;
        
        int dis = temp.ss + 1;

        if (visited.count(x))
            continue;
        visited[x] = true;
        
        
 
        for (int i = 0; i < 6; ++i) {

            int x1 = x + dx[i];
  
                if(ladder.count(x1)> 0){
                     x1 = ladder.at(x1);
                }else if(snakes.count(x1)> 0){
                      x1 =  snakes.at(x1);
                 }
               
                Que.push(mp(x1, dis));
        }
    }

    return -1;
}

void snakeAndLadder(int x1, int y1, const map<int,int> &snakes, const map<int,int> &ladder)
{

    int source;
    source = x1;
 
    int dest;
   dest = y1;
  
    int dx[6] = { 1,2,3,4,5,6};
    
    int ans = bfsPath(source, dest, dx,snakes , ladder);
  cout << ans << " ";
        
    cout << endl;
    
}

int main()
{
    int n;
    cin >> n;
    while(n!=0){
        int s,l;
        cin >> l;
        map<int,int> snakes;
        map<int,int> ladder;
         snakes.clear();
         ladder.clear();
        
        for(int i= 0; i < l; i ++){
            int l1,l2;
            cin >> l1;
            cin >> l2;
         ladder.insert ( pair<int,int>(l1,l2));
            
        }
        cin >> s;
          for(int i= 0; i < s; i ++){
            int s1,s2;
            cin >> s1;
            cin >> s2;
         snakes.insert ( pair<int,int>(s1,s2));
            
        }
    snakeAndLadder(1, 100,snakes,ladder );
        n--;
    }
    return 0;
}