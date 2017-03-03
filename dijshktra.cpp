//dijshktra
//mandeep singh @msdeep14
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
struct vec
{
	int wt;
	int src;
	int dest;
	int track;
};

class dijshktra
{
	vector <vector <vec> > g;
	public:
	void creategraph(int v);
	void calpathcost(int strtver,int v);
};
void dijshktra :: creategraph(int v)
{
	int src,dest,ch,cost;
	g.resize(v);
	vec temp;
	do
	{
		cout<<"enter src and dest and cost for connecting edge: "<<endl;
		cin>>src>>dest>>cost;
		temp.dest=dest;
		temp.src=src;
		temp.wt=cost;
		temp.track=INT_MAX;
		g[src].push_back(temp);
		vec temp1;
		temp1.dest=src;
		temp1.src=dest;
		temp1.wt=cost;
		temp1.track=INT_MAX;
		g[dest].push_back(temp1);
		cout<<"enter 1 for adding more edges: "<<endl;
		cin>>ch;
	}while(ch==1);
}

int check(int visited[], int i)
{
	int flag;
	if(i==visited[i])
		flag=0;
	else
		flag=1;
	return flag;
}

void dijshktra :: calpathcost(int strtver,int v)
{
	int mindis[3000];
	int store[3000];
	int visited[3000];
	int i,j,newvertex;
	int temp=strtver;
	visited[strtver]=strtver;
	for(i=0;i<v;i++)
	{
		visited[i]=INT_MAX;
	}
	for(i=0;i<v;i++)
	{
		store[i]=0;
	}
	for(i=0;i<v;i++)
	{
		mindis[i]=INT_MAX;
	}
	int x=0;
	mindis[strtver]=0;
	int mark=0;
	while(mark<(v))
	{
		for(i=0;i<g[strtver].size() ;i++)
		{
			if(mindis[g[strtver][i].dest]>(g[strtver][i].wt + x)&& check(visited,g[strtver][i].dest))
			{
				mindis[g[strtver][i].dest]=g[strtver][i].wt + x;
			}
		}
		int min=INT_MAX;
		for(j=0;j<v;j++)
		{
			if(min>mindis[j] && j!=strtver && check(visited,j))
			{
				min=mindis[j];
				newvertex=j;
			}
		}
		visited[newvertex]=newvertex;
		store[temp]=mindis[newvertex];
		x=min;
		temp=strtver;
		strtver=newvertex;
		mark++;
	}
	cout<<endl;
	for(i=0;i<v;i++)
	{
		cout<<mindis[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n,m;
	int strtver,v;
	dijshktra dj;
	cout<<"enter no. of vertex: "<<endl;
	cin>>v;
	dj.creategraph(v);
	cout<<"enter the starting vertex: "<<endl;
	cin>>strtver;
	dj.calpathcost(strtver,v);
	return 0;
}
