
#include "stack.hpp"
#include <string>
#include "stack.hpp"
#include <thread>

template<typename T>
void producer(stack<T> &st)
{
	for (;;)
	{
		st.push(rand());
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 1));
	}
}
template<typename T>
void consumer(stack<T>& st)
{
	for (;;)
	{
		st.pop();
		std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 2));
	}
}
int main()
{
	stack<int> st1;
	std::thread t1(consumer, std::ref(st1));
	std::thread t2(producer, std::ref(st1));
	t1.join();
	t2.join();
};
