//newspaper vendor;
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
struct vec
{
	int dest;
	int src;
	int wt;
};
class newspaper
{
	vector< vector <vec> > g;
	int keeptrack[3000];
	public:
	int visited[3000];
	void creategraph(int v);
	int prim(int strtver, int n);
	void calculatemin(vector <int> costpath);
};

int check(int visited[],int dest,int n)
{
    int flag=0,c=0;
    if(dest==visited[dest])
    {
		c=0;
        flag=1;
    }
    if(flag==0)
       c=1;
    return c;
}

void newspaper :: creategraph(int v)
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
		g[src-1].push_back(temp);
		cout<<"enter 1 for adding more edges: "<<endl;
		cin>>ch;
	}while(ch==1);
}

int newspaper :: prim(int strtver,int n)
{
	int sumwt=0;
	int temp=strtver;
	int min=INT_MAX;
	int node1;
	int k=0,j,i,x;
	int node;
	for(i=0;i<=n;i++)
	{
		visited[i]=-1;
	}
	
	keeptrack[k]=strtver;
	k++;
	int size=k;
	visited[strtver]=strtver;
	while(size!=n)
	{
	for(j=0;j<size;j++)
	{
		strtver=keeptrack[j]-1;
		for(i=0;i<g[strtver].size();i++)
		{
			if(min>g[strtver][i].wt)
			{
			    if(check(visited,g[strtver][i].dest,n) )
                {
                    min=g[strtver][i].wt;
                    node=g[strtver][i].dest;
                    node1=strtver;
                    x=i;
                }
                else if(check(visited,g[strtver][i].src,n))
                {
                    min=g[strtver][i].wt;
                    node=g[strtver][i].src;
                    node1=strtver;
                    x=i;
                }
			}
		}
	}
		visited[node]=node;
		sumwt=sumwt+g[node1][x].wt;
		keeptrack[k]=node;
		k++;
		min=INT_MAX;
		size=k;
	}
	int flag=0;
	for(int t=0;t<(k-1);t++)
	{
		int a=keeptrack[t];
		int b=keeptrack[t+1];
		flag=0;
		for(int n=0;n<g[a-1].size();n++)
		{
			if(b==g[a-1][n].dest)
			{	
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	{
		cout<<"travelling sequence starting with vertex "<<temp<<" : "<<endl;
		for(int m=0;m<k;m++)
		{
			cout<<keeptrack[m]<<"->";
		}
		cout<<endl;
		cout<<"total cost of visiting is: "<<sumwt<<endl;
	}
	if(flag==0)
	{
		sumwt=0;
	}
	return sumwt;
}

void newspaper :: calculatemin(vector <int> costpath)
{
	int min=costpath[0];
	for(int i=0;i<costpath.size();i++)
	{	
		if(min>costpath[i])
			min=costpath[i];
	}
	cout<<endl;
	cout<<"minimum cost for travelling is "<<min<<endl;
}

int main()
{
	int i;
	newspaper np;
	vector <int > costpath;
	int ch,v,strtver;
	cout<<"enter 1 for creating graph: "<<endl;
	cin>>ch;
	if(ch==1)
	{
		cout<<"enter no. of vertices of graph: "<<endl;
		cin>>v;
		np.creategraph(v);
	}
	int minwt;
	for(i=1;i<=v;i++)
	{
		strtver=i;
		minwt=np.prim(i,v);
		if(minwt!=0)
			costpath.push_back(minwt);
	}
	np.calculatemin(costpath);
	return 0;
 }
