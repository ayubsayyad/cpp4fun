#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <sstream>
#include <atomic>

std::vector<std::thread> threads;

std::atomic<int> curr_idx;

std::string str;
uint32_t numChars;

uint32_t print_next_word(
	std::string& threadName,
	const uint32_t startIdx)
{
	std::cout << threadName << ": ";
	for (uint32_t idx = 0; idx < numChars; ++idx)
	{
		std::cout << str[(startIdx + idx) % str.size()];
	}
	std::cout << std::endl;

	return 0;
}

void thread_func(int idx, int threadCount)
{
	std::ostringstream oss;
	oss << "Thread" << idx + 1;
	std::string threadName = oss.str();

	uint32_t startIdx = (idx*numChars) % str.size();
	while (true)
	{
		while (curr_idx.load(std::memory_order_acquire) != idx)
        {
            std::this_thread::yield();
        }

		print_next_word(threadName, startIdx);
		startIdx = (startIdx + threadCount*numChars) % str.size();
		curr_idx.store((idx + 1) % threadCount, std::memory_order_release);
		//std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}


int main(int arc, char **argv)
{
    if(arc != 4)
    {
        std::cout << "usage: " << argv[0] << " <string> <numChars> <numThreads>" <<std::endl;
        return -1;
    }
	str = argv[1];
	numChars = atoi(argv[2]);

	uint32_t threadCount = atoi(argv[3]);

	for (uint32_t idx = 0; idx < threadCount; ++idx)
	{
		threads.emplace_back(std::bind(thread_func, idx, threadCount));
	}

	for (int idx = 0; idx < threads.size(); ++idx)
	{
		threads[idx].join();
	}

	return 0;
}

