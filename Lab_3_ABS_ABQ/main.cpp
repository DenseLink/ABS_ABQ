#include "ABS.h"
#include "ABQ.h"
#include <iostream>
#include <chrono>
using namespace std;

void ABSTest();
void ABQTest();

int main() {
	int choice;

	cin >> choice;

	if (choice == 1)
		ABSTest();
	else if (choice == 2)
		ABQTest();

	return 0;
}

void ABSTest() {
	auto start = chrono::steady_clock::now();
	cout << "Making integer ABS...\n";
	ABS<int> intABS;
	cout << "Size: " << intABS.getSize() << endl;
	cout << "Max Capacity: " << intABS.getMaxCapacity() << endl;
	cout << "\nPushing items...\n";
	for (int i = 1; i < 15000; i++) {
		intABS.push(i);
		cout << "\nPushed " << intABS.peek() << endl;
		cout << "New Size: " << intABS.getSize() << endl;
		cout << "New Max Capacity: " << intABS.getMaxCapacity() << endl;
	}
	auto end = chrono::steady_clock::now();
	double elapsed_time = double(chrono::duration_cast <chrono::nanoseconds> (end - start).count());
	


	auto start1 = chrono::steady_clock::now();
	cout << "\nPopping items...\n";
	for (int i = 1; i < 15000; i++) {
		cout << "\nPopped " << intABS.pop() << endl;
		cout << "New Size: " << intABS.getSize() << endl;
		cout << "New Max Capacity: " << intABS.getMaxCapacity() << endl;
	}
	auto end1 = chrono::steady_clock::now();
	double elapsed_time1 = double(chrono::duration_cast <chrono::nanoseconds> (end1 - start1).count());
	cout << "Elapsed time (s) for pushing: " << elapsed_time / 1e9 << endl;
	cout << "This is the number of resizes: " << intABS.getTotalResizes() << endl;
	cout << "Elapsed time (s) for popping: " << elapsed_time1 / 1e9 << endl;
	cout << "This is the number of resizes: " << intABS.getTotalResizes() << endl;

	/*cout << "\nMaking float ABS...\n";
	ABS<float> floatABS(1);
	cout << "Size: " << floatABS.getSize() << endl;
	cout << "Max Capacity: " << floatABS.getMaxCapacity() << endl;
	cout << "\nPushing items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		floatABS.push(i);
		cout << "\nPushed " << floatABS.peek() << endl;
		cout << "New Size: " << floatABS.getSize() << endl;
		cout << "New Max Capacity: " << floatABS.getMaxCapacity() << endl;
	}

	cout << "\nPopping items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		cout << "\nPopped " << floatABS.pop() << endl;
		cout << "New Size: " << floatABS.getSize() << endl;
		cout << "New Max Capacity: " << floatABS.getMaxCapacity() << endl;
	}*/
	
}

void ABQTest() {
	auto start2 = chrono::steady_clock::now();
	cout << "Making integer ABQ...\n";
	ABQ<int> intABQ;
	cout << "Size: " << intABQ.getSize() << endl;
	cout << "Max Capacity: " << intABQ.getMaxCapacity() << endl;
	cout << "\nEnqueueing items...\n";
	for (int i = 1; i < 15000; i++) {
		intABQ.enqueue(i);
		cout << "\nEnqueued " << i << endl;
		cout << "New Size: " << intABQ.getSize() << endl;
		cout << "New Max Capacity: " << intABQ.getMaxCapacity() << endl;
	}
	auto end2 = chrono::steady_clock::now();
	double elapsed_time2 = double(chrono::duration_cast <chrono::nanoseconds> (end2 - start2).count());
	

	auto start3 = chrono::steady_clock::now();
	cout << "\nDequeueing items...\n";
	for (int i = 1; i < 15000; i++) {
		cout << "\nDequeued " << intABQ.dequeue() << endl;
		cout << "New Size: " << intABQ.getSize() << endl;
		cout << "New Max Capacity: " << intABQ.getMaxCapacity() << endl;
	}
auto end3 = chrono::steady_clock::now();
	double elapsed_time3 = double(chrono::duration_cast <chrono::nanoseconds> (end3 - start3).count());
	cout << "Elapsed time (s): for enqueueing " << elapsed_time2 / 1e9 << endl;
	cout << "This is the number of resizes: " << intABQ.getTotalResizes() << endl;
	cout << "Elapsed time (s) for dequeueing: " << elapsed_time3 / 1e9 << endl;
	cout << "This is the number of resizes: " << intABQ.getTotalResizes() << endl;

	//cout << "\nMaking float ABQ...\n";
	//ABQ<float> floatABQ(1);
	//cout << "Size: " << floatABQ.getSize() << endl;
	//cout << "Max Capacity: " << floatABQ.getMaxCapacity() << endl;
	//cout << "\nEnqueueing items...\n";
	//for (float i = 1; i < 5; i += 0.5f) {
	//	floatABQ.enqueue(i);
	//	cout << "\nEnqueued " << i << endl;
	//	cout << "New Size: " << floatABQ.getSize() << endl;
	//	cout << "New Max Capacity: " << floatABQ.getMaxCapacity() << endl;
	//}

	//cout << "\nDequeueing items...\n";
	//for (float i = 1; i < 5; i += 0.5f) {
	//	cout << "\nDequeued " << floatABQ.dequeue() << endl;
	//	cout << "New Size: " << floatABQ.getSize() << endl;
	//	cout << "New Max Capacity: " << floatABQ.getMaxCapacity() << endl;
	//}
	
}