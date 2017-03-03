#dfs traversal of graph
graph={'a':set(['b','c']),'b':set(['a','d','e']),'c':set(['a','f']),'d':set(['b']),'e':set(['b','f']),'f':set(['c','e'])}

def dfs(graph,start):
	visited,stack=set(),[start]
	while stack:
		vertex=stack.pop(-1)
		if vertex not in visited:
			visited.add(vertex)
			stack.extend(graph[vertex]-visited)
	return visited







'''
def dfs(graph,start,path=[]):
	q=[start]
	while q:
		v=q.pop(0)
		if v not in path:
			path=path+[v]
			q=graph[v]+q
	return path
'''
#bfs traversal
def bfs(graph,start,path=[]):
	q=set(),[start]
	
	while q:
		v=q.pop(0)
		if v not in path:
			path=path+[v]
			q=q+graph[v]
	return path
'''
graph={'a':['b','c'],'b':['d','e'],'c':['d','e'],'d':['e'],'e':['a']}
print "dfs traversal of graph"
path=dfs(graph,'a')
print path
print "bfs traversal for graph"
path=bfs(graph,'a')
print path
'''

visited=dfs(graph,'a')
print visited

path=bfs(graph,'a')
print path

