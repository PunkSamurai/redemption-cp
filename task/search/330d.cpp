#include <bits/stdc++.h>

using namespace std;

char v[1001][1001];
queue<pair<int,int> > q;
int tr,tc,x,y,r,c;
int v2[1001][1001];
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
 
void bfs(){
	for(int i=0; i<r; ++i)
		for(int j=0;j<c;j++)
			v2[i][j]=-1;
	v2[x][y]=0;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int nx=q.front().first;
		int ny=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nnx=nx+dr[i];
			int nny=ny+dc[i];
			if(nnx>=0&&nnx<r&&nny>=0&&nny<c&&v2[nnx][nny]==-1&&v[nnx][nny]!='T'){
				q.push(make_pair(nnx,nny));
				v2[nnx][nny]=v2[nx][ny]+1;
			}
		}
	}
}
int main() {
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>v[i][j];
			if(v[i][j]=='E'){
				x=i;y=j;
			}
			if(v[i][j]=='S'){
				tr=i;tc=j;
			}
		}
	}
	bfs();
	int count=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(v2[i][j]!=-1&&v2[i][j]<=v2[tr][tc]&&v[i][j]!='0'&&v[i][j]!='S'&&v[i][j]!='E'){
				//cout<<count<<endl;
				count+=v[i][j]-'0';
				//cout<<v[i][j]<<" ";
			}
		}
	}
	cout<<count;
	
	
	return 0;
}