#include <iostream>
#include <string>
#include "Deque.hpp"

bool testPushBack()
{
	Deque<int> deque;
	deque.pushBack(10);
	deque.pushBack(20);
	deque.pushBack(30);

	return deque.size() == 3 && deque[0] == 10 && deque[1] == 20 && deque[2] == 30;
}

bool testPushFront()
{
	Deque<int> deque;
	deque.pushFront(10);
	deque.pushFront(20);
	deque.pushFront(30);

	return deque.size() == 3 && deque[0] == 30 && deque[1] == 20 && deque[2] == 10;
}

bool testPopBack()
{
	Deque<int> deque;
	deque.pushBack(10);
	deque.pushBack(20);
	deque.pushBack(30);
	deque.popBack();

	return deque.size() == 2 && deque[0] == 10 && deque[1] == 20;
}

bool testPopFront()
{
	Deque<int> deque;
	deque.pushBack(10);
	deque.pushBack(20);
	deque.pushBack(30);
	deque.popFront();

	return deque.size() == 2 && deque[0] == 20 && deque[1] == 30;
}

bool testEmplaceBack()
{
	Deque<std::string> deque;
	deque.emplaceBack(3, 'a'); // Adds "aaa" to the back

	return deque.size() == 1 && deque[0] == "aaa";
}

bool testEmplaceFront()
{
	Deque<std::string> deque;
	deque.emplaceFront(3, 'b'); // Adds "bbb" to the front

	return deque.size() == 1 && deque[0] == "bbb";
}

bool testFrontBackAccess()
{
	Deque<int> deque;
	deque.pushBack(10);
	deque.pushBack(20);
	deque.pushFront(5);

	return deque.front() == 5 && deque.back() == 20;
}

bool testIsEmpty()
{
	Deque<int> deque;
	return deque.isEmpty();
}

bool testResize()
{
	Deque<int> deque;
	for (int i = 0; i < 20; ++i)
	{
		deque.pushBack(i);
	}
	bool success = true;
	for (int i = 0; i < 20; ++i)
	{
		success = success && deque[i] == i;
	}
	return success && deque.size() == 20;
}
bool testShrinkToFit()
{
	Deque<int> deque;

	// Step 1: Add elements to exceed the initial currCapacity and trigger resize
	for (int i = 0; i < 20; ++i)
	{
		deque.pushBack(i);
	}

	// Step 2: Remove a few elements to create extra currCapacity
	for (int i = 0; i < 10; ++i)
	{
		deque.popFront();
	}

	// Step 3: Call shrinkToFit to reduce currCapacity to match the current size
	size_t sizeBeforeShrink = deque.size();
	deque.shrinkToFit();

	// Step 4: Check if the currCapacity matches the current size
	bool capacityMatchesSize = (deque.size() == sizeBeforeShrink && deque.capacity() == deque.size());

	// Step 5: Verify elements are in the correct order after shrinking
	bool elementsIntact = true;
	for (size_t i = 0; i < deque.size(); ++i)
	{
		if (deque[i] != i + 10) // Elements should be [10, 11, ..., 19] after popping
		{
			elementsIntact = false;
			break;
		}
	}

	return capacityMatchesSize && elementsIntact;
}


bool testIteratorIncrement() {
	Deque<int> deque;
	deque.pushBack(1);
	deque.pushBack(2);
	deque.pushBack(3);

	auto it = deque.begin();
	if (*it != 1) return false;

	it++;
	if (*it != 2) return false;

	++it;
	if (*it != 3) return false;

	return it == deque.end() - 1;
}

bool testIteratorDecrement() {
	Deque<int> deque;
	deque.pushBack(1);
	deque.pushBack(2);
	deque.pushBack(3);

	auto it = deque.end() - 1;
	if (*it != 3) return false;

	it--;
	if (*it != 2) return false;

	--it;
	if (*it != 1) return false;

	return it == deque.begin();
}

bool testIteratorEquality() {
	Deque<int> deque;
	deque.pushBack(10);
	deque.pushBack(20);

	auto it1 = deque.begin();
	auto it2 = deque.begin();
	if (it1 != it2) return false;

	++it2;
	if (it1 == it2) return false;

	return true;
}

bool testConstIterator() {
	Deque<int> deque;
	deque.pushBack(5);
	deque.pushBack(15);
	deque.pushBack(25);

	const Deque<int>& constDeque = deque;
	auto it = constDeque.begin();

	if (*it != 5) return false;
	++it;
	if (*it != 15) return false;
	++it;
	if (*it != 25) return false;

	return it == constDeque.end() - 1;
}

bool testIteratorDereference() {
	Deque<int> deque;
	deque.pushBack(100);
	deque.pushBack(200);
	deque.pushBack(300);

	auto it = deque.begin();
	if (*it != 100) return false;

	++it;
	if (*it != 200) return false;

	it++;
	if (*it != 300) return false;

	return true;
}

int main()
{
	std::cout << "Test Push Back: " << (testPushBack() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Push Front: " << (testPushFront() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Pop Back: " << (testPopBack() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Pop Front: " << (testPopFront() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Emplace Back: " << (testEmplaceBack() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Emplace Front: " << (testEmplaceFront() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Front and Back Access: " << (testFrontBackAccess() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Is Empty: " << (testIsEmpty() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Resize: " << (testResize() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Shrink To Fit: " << (testShrinkToFit() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Iterator Increment: " << (testIteratorIncrement() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Iterator Decrement: " << (testIteratorDecrement() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Iterator Equality: " << (testIteratorEquality() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Const Iterator: " << (testConstIterator() ? "PASSED" : "FAILED") << "\n";
	std::cout << "Test Iterator Dereference: " << (testIteratorDereference() ? "PASSED" : "FAILED") << "\n";

	return 0;
}
