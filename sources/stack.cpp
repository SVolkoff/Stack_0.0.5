
#include "stack.hpp"
#include <string>
#include <chrono>
#include <thread>

void produser (stack<int> &st)
{
   for (;;)
    {
      st.push(rand()%10);
      std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 1));
    }
}

void consumer (stack<int> &st)
{
   for (;;)
    {
       st.pop();
       std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) +2 ));
    }
}

int main()
{
	stack<int> st1;
	std::thread t1(consumer, std::ref(st1));
	std::thread t2(producer, std::ref(st1));
	t1.join();
	t2.join();
	return 0;
};
