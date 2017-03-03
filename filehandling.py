fd = open('hello.txt','r')
a=e=i=o=u=0
x=0
space=0
c=0
char=0
word=0
line=0
sp=0
while(fd.read(1)!=""):
	char = char + 1
	fd.seek(x)
	c=ord(fd.read(1))
	
	if(c==65 or c==97):
		a+=1
	if(c==69 or c==101):
		e+=1
	if(c==73 or c==105):
		i+=1
	if(c==79 or c==111):
		o+=1
	if(c==85 or c==117):
		u+=1
	if(c==32):
		space+=1
	if(c==10 or c==32):
		word+=1
	if(c==10):
		line+=1
	if c in range(33,47):
		sp+=1
	x+=1
fd.close()
f=open("hello2.txt",'w')
f.write("a count is= " +str(a)+"\n")
f.write("e count is= " +str(e)+"\n")
f.write("i count is= " +str(i)+"\n")
f.write("o count is= " +str(o)+"\n")
f.write("u count is= " +str(u)+"\n")
f.write("count of special characters is= " +str(sp)+"\n")
f.write("spaces count is= " +str(space)+"\n")
f.write("word count is= " +str(word)+"\n")
f.write("line count is= " +str(line)+"\n")


		
	
