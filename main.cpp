#include"Queue.h"

int main() {
	Queue s1;
	s1.r_push(1);
	s1.r_push(2);
	s1.r_push(3);
	s1.f_push(4);
	cout << "s1: " << s1 << endl;
	ElemType last = s1.r_pop();
	cout << "Pop the last elem" <<endl;
	cout << "last element of s1:" << last << endl;
	cout << "s1: " << s1 << endl;
	ElemType first = s1.f_pop();
	cout << "Pop the first elem" << endl;
	cout << "first element of s1:" << first << endl;
	cout << "s1: " << s1 << endl;
	Queue s2(s1);
	s2.f_push(5);
	cout << "s2: " << s2 << endl;
	Queue s3 = s2;
	s3.r_pop();
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;


}