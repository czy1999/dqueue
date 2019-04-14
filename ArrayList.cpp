#include"ArrayList.h"

ArrayList::ArrayList(int size)
{
	elems=new ElemType[size];
	sizeOfElems=0;
	sizeOfAllocatedMemory=size;
}

ArrayList::ArrayList( const ArrayList& list )
{
	elems=new ElemType[list.sizeOfAllocatedMemory];
	sizeOfAllocatedMemory=list.sizeOfAllocatedMemory;
	sizeOfElems=list.sizeOfElems;
	for(int i=0;i<list.sizeOfElems;i++)
		elems[i]=list.elems[i];
}
ArrayList::~ArrayList()
{ 
	delete[] elems;
}
int ArrayList::size() const
{
	return sizeOfElems;
}
void ArrayList::reallocate()
{
	int newSizeOfAllocatedMemory=sizeOfAllocatedMemory+INC;
	ElemType *newElems=new ElemType[newSizeOfAllocatedMemory];
	for(int i=0;i<sizeOfElems;i++)
	{
		newElems[i]=elems[i];    
	}
	delete []elems; 
	elems=newElems;
	sizeOfAllocatedMemory=newSizeOfAllocatedMemory;
}

void ArrayList::add( int index, ElemType e )
{
	int newSizeOfArray=sizeOfElems+1;
	if(sizeOfAllocatedMemory<newSizeOfArray)
	{
		reallocate(); 
	}
	for(int i=sizeOfElems-1;i>=index;i--)
	{
		elems[i+1]=elems[i]; 
	}
	elems[index]=e;
	sizeOfElems=newSizeOfArray;
}
	
void ArrayList::add( ElemType e )
{
	add(this->sizeOfElems,e);
}

void ArrayList::remove( int index )
{
	int newSizeOfElems=sizeOfElems-1;
	if(index>newSizeOfElems || index<0)
	{
		throw string("index out of bounds!");
	}
	if(sizeOfElems==0)
	{
		throw string("There is no element to remove!");
	}
	for(int i=index;i<newSizeOfElems;i++)
	{
		elems[i]=elems[i+1]; 
	}
	sizeOfElems=newSizeOfElems;
}

void ArrayList::remove() 
{
	remove(0);
}

void ArrayList::clear()
{
	sizeOfElems=0;
}

ElemType& ArrayList::operator[]( int index ) 
{
	if(index>sizeOfElems-1 || index<0)
	{
		throw string("Index out of bounds");
	}
	return elems[index];
}

ArrayList& ArrayList::operator=( const ArrayList& list ) 
{
	delete []elems;
	elems=new ElemType[list.sizeOfAllocatedMemory];
	sizeOfAllocatedMemory=list.sizeOfAllocatedMemory;
	sizeOfElems=list.sizeOfElems;
	for(int i=0;i<list.sizeOfElems;i++)
		elems[i]=list.elems[i];
	return *this;
}

ostream& operator<<(ostream& os, const ArrayList& list)
{
	for(int i=0;i<list.size();i++)
		os<<list.elems[i]<<"\t";
	return os;
}
