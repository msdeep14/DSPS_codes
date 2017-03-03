#various sorting techniques
#bubblesort
def bubblesort(list,size):
	i=size-1;
	while(i>0):
		j=0;
		count=1;
		while(j<i):
			if(list[j]>list[j+1]):
				list[j],list[j+1]=list[j+1],list[j];
				print "pass",count
				print list;
			j=j+1;
		i=i-1;
	return

#insertionsort
def insertionsort(list,size):
	i=1;
	while(i<size):
		current=list[i];
		j=i-1;
		count=1;
		while(j>=0):
			if(list[j]>current):
				list[j+1]=list[j];
			else:
				break;
			j=j-1;
			print "pass",count;
			print list;
			count=count+1;
		list[j+1]=current;		
		i=i+1;


#selectionsort
def selectionsort(list,size):
	for i in xrange(size-1):
		min=i;
		count=1
		for j in xrange(i+1,size):
			if(list[min]>list[j]):
				min=j;
		if(min!=list[i]):
			list[min],list[i]=list[i],list[min];
			print "pass",count
			print list;

#shellsort
def shellsort(list):
	count=len(list)//2
	while count>0:
		for startpos in range(count):
			gapinsertionsort(list,startpos,count)
			print list;
		count=count//2

def gapinsertionsort(list,start,gap):
	i=start+gap
	while(i<len(list)):
		current=list[i]
		position=i
		i=i+gap
		while position>=gap and list[position-gap]>current:
			list[position]=list[position-gap]
			position=position-gap
		list[position]=current


#mergesort
def merge(list,l,m,r):
	n1=m-l+1;
	n2=r-m;
	L=[];
	R=[];
	for x in xrange(n1):
		L.append(0);
	for y in xrange(n2):
		R.append(0);
	for i in xrange(n1):
		L[i]=list[l+i];
	for j in xrange(n2):
		R[j]=list[m+1+j];

	i=0;
	j=0;
	k=l;
	while(i<n1 and j<n2):
		if(L[i]<=R[j]):
			list[k]=L[i];
			i=i+1;
		else:
			list[k]=R[j];
			j=j+1;
		k=k+1;
	while(i<n1):
		list[k]=L[i];
		i=i+1;
		k=k+1;
	while(j<n2):
		list[k]=R[j];
		j=j+1;
		k=k+1;
	print list;

def mergesort(list,l,r):
	m=(l+r)//2;
	if(l<r):
		mergesort(list,l,m);
		mergesort(list,m+1,r);
		merge(list,l,m,r);

#quicksort
def partition(list,start,end):
	pivot=list[end];
	pindex=start;
	count=1;
	for i in xrange(start,end):
		if(list[i]<=pivot):
			list[i],list[pindex]=list[pindex],list[i];
			pindex=pindex+1;
	list[pindex],list[end]=list[end],list[pindex];
	print "pass",count;
	print list
	return pindex;

def quicksort(list,start,end):
	if(start<end):
		pindex=partition(list,start,end);
		quicksort(list ,start,pindex-1);
		quicksort(list,pindex+1,end);


#radixsort
def radixsort(arr):
    lenarr = len(arr)
    modulus = 10
    div = 1
    while 1:
        newarr = [[], [], [], [], [], [], [], [], [], []]
        for val in arr:
            least = val % modulus
            least /= div
            newarr[least].append(val)
        modulus = modulus * 10
        div = div * 10

        if len(newarr[0]) == lenarr:
            return newarr[0]
        arr=[]
        rd = arr.append
       
        for x in newarr:
            for y in x:
                rd(y)   
                
        print(newarr)

list=[]
print "enter the size of list you want to create: "
size=input()
print "enter the list elements: "
count=0;
while(count<size):
	num=input();
	list.append(num);
	count=count+1;
print "enter the choice, by which method you want to do sorting?"
print "1.bubblesort"
print "2.insertionsort"
print "3.selectionsort"
print "4.shellsort"
print "5.mergesort"
print "6.quicksort"
print "7.radixsort"

choice = input();
if(choice==1):
	bubblesort(list,size);
elif(choice==2):
	insertionsort(list,size);
elif(choice==3):
	selectionsort(list,size);
elif(choice==4):
	shellsort(list);
elif(choice==5):
	mergesort(list,0,size-1);
elif(choice==6):
	quicksort(list,0,size-1);
elif(choice==7):
	radixsort(list);
else:
	print "you entered wrong choice";

print "sorted list is: ";
print list
