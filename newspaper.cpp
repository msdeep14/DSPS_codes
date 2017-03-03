//newspaper vendor path finding
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct vec
{
	int info;
	int wt;
};
class newspaper
{
	public:
	vector< vector <vec> > g;
	stack <int> s;
	void creategraph(int v);
	int dfs(int strtver, int v);
};
void newspaper :: creategraph(int v)
{
	int ch;
	g.resize(v);
	cout<<"ch==1 for entering edges: "<<endl;
	cin>>ch;
	int src,dest;
	while(ch==1)
	{
		cout<<"enter source to destination of the edge to be connected: "<<endl;
		cin>>src>>dest;
		vec temp;
		int wtt;
		temp.info=dest;
		cout<<"enter the cost: "<<endl;
		cin>>wtt;
		temp.wt=wtt;
		g[src].push_back(temp);
		cout<<"enter choice to add more edges: "<<endl;
		cin>>ch;
	}
	cout<<"\n";
}

int newspaper :: dfs(int strtver, int v)
{
	vector <int> vis;
	vector <int> visited;
	vis.resize(v);
	int cost=0;
	for(int i=0;i<v;i++)
    {
        vis[i]=0;
    }
	s.push(strtver);
	while(!s.empty())
    {
        int u=s.top();
        visited.push_back(u);
        vis[u]=1;
        s.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int z=g[u][i].info;
            if(vis[z]==0)
            {
                s.push(z);
				break;
            }
        }
    }
	cout<<endl;
	int flag=0;
	//print the visited graph;
	cout<<"for starting house as "<<strtver<<", path is: ";
	for(int j=0;j<v;j++)
	{
		flag=0;
		if(j>0)
		{
			int a=visited[j-1];
			int b=visited[j];
			for(int l=0;l<g[a].size();l++)
			{
				if(g[a][l].info==b)
				{
					cost=cost+g[a][l].wt;
					flag=1;
				}
			}
		}
	}
	if(flag==1)
	{
		for(int m=0;m<v;m++)
		{
			cout<<visited[m]<<" ";	
		}
	cout<<endl;
	cout<<"cost of path is : "<<cost<<endl;
	}
	else
	{
		cout<<"You cannot travel all houses by starting from this house!"<<endl;
		cost=0;
	}
	return cost;
}
int main()
{
	//create graph;
	newspaper np;
	vector <int> costpath;
	int v,strtver;
	cout<<"enter total no of houses: "<<endl;
	cin>>v;
	int cost;
	np.creategraph(v);
	//dfs traversal of graph for various vertices;
	for(int i=0;i<v;i++)
	{
		strtver=i;
		cost=np.dfs(strtver,v);
		if(cost!=0)
			costpath.push_back(cost);
	}
	int min=costpath[0];
	for(int j=0;j<costpath.size();j++)
	{
		if(min>costpath[j])
			min=costpath[j];
	}
	cout<<endl;
	cout<<"min cost of path travelling is "<<min<<endl;
	return 0;
}
