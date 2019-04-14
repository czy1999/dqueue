#include "Queue.h"

Queue::Queue(int size):list(size)
{
}

Queue::Queue(const Queue& queue)
{
	//calls operator= of the ArrayList
	list = queue.list;

}

Queue::~Queue()
{
	//do nothing

}

int Queue::size() const
{
	return list.size();

}

void Queue::f_push(ElemType e)
{
	list.add(0, e);
}

ElemType Queue::f_pop()
{
	ElemType last = list[0];
	list.remove(0);
	return last;
}

void Queue::r_push(ElemType e)
{
	list.add(e);
}

ElemType Queue::r_pop()
{
	int index = list.size() - 1;
	ElemType last = list[index];
	list.remove(index);
	return last;
}

void Queue::clear()
{
	list.clear();
}

Queue& Queue::operator=(const Queue& queue)
{
	//calls operator= of the ArrayList
	list = queue.list;
	return *this;
}

ostream& operator<<(ostream& os, const Queue& queue)
{
	//calls operator<< of the ArrayList
	os << queue.list;
	return os;

}
