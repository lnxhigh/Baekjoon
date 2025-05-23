#include <bits/stdc++.h>
using namespace std;
int n,m;//세로,가로.
int rx,ry;
int bx,by;
int vis[10][10][10][10];
int arr[10][10];
queue<array<int,5>> q;
//진짜 값만 넣음.
int chkx(int x)
{
  if(x<0||x>=m) return 1;
  else return 0;
}
int chky(int y)
{
  if(y<0||y>=n) return 1;
  else return 0;
}
void push(int y1,int x1,int y2,int x2,int t)
{
  if(t>10) return;
  if(x1<0||x1>=m||x2<0||x2>=m) return;
  if(y1<0||y1>=n||y2<0||y2>=n) return;
  if(vis[y1][x1][y2][x2]) return;
  if(y1==y2&&x1==x2) return;
  vis[y1][x1][y2][x2]=1;
  //cout<<"         "<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<" "<<t<<endl;
  q.push({y1,x1,y2,x2,t});
}
void bfs()
{
  push(ry,rx,by,bx,0);
  while(!q.empty()){
    int y1=q.front()[0];
    int x1=q.front()[1];
    int y2=q.front()[2];
    int x2=q.front()[3];
    int t=q.front()[4];
    //cout<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<" "<<t<<endl;
    q.pop();
    if(arr[y2][x2]==2) continue;
    if(arr[y1][x1]==2){
      cout<<t;
      return;
    }
    for(int i=0;i<4;i++)// 우 하 상 좌.
    {
      int y1p=y1,y2p=y2,x1p=x1,x2p=x2;
      if(i==0){
        if(x1p<x2p){
          while(true){
            if(arr[y2p][x2p+1]==1) break;
            x2p++;
            if(arr[y2p][x2p]==2) break;
          }
          while(true){
            if(arr[y1p][x1p+1]==1||((y1p==y2p&&x1p+1==x2p)&&arr[y2p][x2p]!=2)) break;
            x1p++;
            if(arr[y1p][x1p]==2||((y1p==y2p&&x1p==x2p)&&arr[y2p][x2p]!=2)) break;
          }
        }
        else{
          while(true){
            if(arr[y1p][x1p+1]==1) break;
            x1p++;
            if(arr[y1p][x1p]==2) break;
          }
          while(true){
            if(arr[y2p][x2p+1]==1||((y1p==y2p&&x2p+1==x1p)&&arr[y1p][x1p]!=2)) break;
            x2p++;
            if(arr[y2p][x2p]==2||((y1p==y2p&&x2p==x1p)&&arr[y1p][x1p]!=2)) break;
          }
        }
      }
      else if(i==1){
        if(y1p>y2p){
          while(true){
            if(arr[y1p+1][x1p]==1) break;
            y1p++;
            if(arr[y1p][x1p]==2) break;
          }
          while(true){
            if(arr[y2p+1][x2p]==1||((x1p==x2p&&y2p+1==y1p)&&arr[y1p][x1p]!=2)) break;
            y2p++;
            if(arr[y2p][x2p]==2||((x1p==x2p&&y2p==y1p)&&arr[y1p][x1p]!=2)) break;
          }
        }
        else{
           while(true){
            if(arr[y2p+1][x2p]==1) break;
            y2p++;
            if(arr[y2p][x2p]==2) break;
          }
          while(true){
            if(arr[y1p+1][x1p]==1||((x1p==x2p&&y1p+1==y2p)&&arr[y2p][x2p]!=2)) break;
            y1p++;
            if(arr[y1p][x1p]==2||((x1p==x2p&&y1p==y2p)&&arr[y2p][x2p]!=2)) break;
          }
        }
      }
      else if(i==2){
        if(y1p>y2p){
          while(true){
            if(arr[y2p-1][x2p]==1) break;
            y2p--;
            if(arr[y2p][x2p]==2) break;
          }
          while(true){
            if(arr[y1p-1][x1p]==1||((y1p-1==y2p&&x1p==x2p)&&arr[y2p][x2p]!=2)) break;
            y1p--;
            if(arr[y1p][x1p]==2||((y1p==y2p&&x1p==x2p)&&arr[y2p][x2p]!=2)) break;
          }
        }
        else{
          while(true){
            if(arr[y1p-1][x1p]==1) break;
            y1p--;
            if(arr[y1p][x1p]==2) break;
          }
          while(true){
            if(arr[y2p-1][x2p]==1||((y1p==y2p-1&&x2p==x1p)&&arr[y1p][x1p]!=2)) break;
            y2p--;
            if(arr[y2p][x2p]==2||((y1p==y2p&&x2p==x1p)&&arr[y1p][x1p]!=2)) break;
          }
        }
      }
      else if(i==3){
        if(x1p<x2p){
          while(true){
            if(arr[y1p][x1p-1]==1) break;
            x1p--;
            if(arr[y1p][x1p]==2) break;
          }
          while(true){
            if(arr[y2p][x2p-1]==1||((x1p==x2p-1&&y2p==y1p)&&arr[y1p][x1p]!=2)) break;
            x2p--;
            if(arr[y2p][x2p]==2||((x1p==x2p&&y2p==y1p)&&arr[y1p][x1p]!=2)) break;
          }
        }
        else{
           while(true){
            if(arr[y2p][x2p-1]==1) break;
            x2p--;
            if(arr[y2p][x2p]==2) break;
          }
          while(true){
            if(arr[y1p][x1p-1]==1||((x1p-1==x2p&&y1p==y2p)&&arr[y2p][x2p]!=2)) break;
            x1p--;
            if(arr[y1p][x1p]==2||((x1p==x2p&&y1p==y2p)&&arr[y2p][x2p]!=2)) break;
          }
        }
      }
      push(y1p,x1p,y2p,x2p,t+1);
    }
  }
  cout<<-1;
}
signed main()
{
  cin>>n>>m;
  for(int y=0;y<n;y++){
    for(int x=0;x<m;x++){
      char a;
      scanf(" %c",&a);
      if(a=='#') arr[y][x]=1;
      if(a=='.') arr[y][x]=0;
      if(a=='O') arr[y][x]=2;
      if(a=='R'){
        rx=x;
        ry=y;
      }
      if(a=='B'){
        bx=x;
        by=y;
      }
    }
  }
  bfs();
}