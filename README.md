# dqueue
C++实现的基础双端队列

Queue类
```c++
class Queue
{
private:
	ArrayList list; //a list to store data element
public:
	Queue(int size = 0); //constructor
	Queue(const Queue& Queue); //copy constructor
	~Queue(); //destructor
	int size() const; //returns the size of data elements in the Queue
	void f_push(ElemType e); //pushes an element to the Queue
	//pops an element from the Queue
	ElemType f_pop();
	//removes all of the elements from the Queue
	void r_push(ElemType e); //pushes an element to the Queue
//pops an element from the Queue
	ElemType r_pop();
	//removes all of the elements from the Queue
	void clear();
	//assigns values of other Queue to this Queue
	Queue& operator=(const Queue& Queue);
	//outputs the Queue to a stream
	friend ostream& operator<<(ostream& os, const Queue& Queue);
};

```

