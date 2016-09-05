#include <iostream>
#include <exception> 
#include <stdexcept>
#include <cstdint>

//can insert max SIZE elements 
//can be extended to max capacity easily
template <typename T, size_t SIZE=100>
class versioned_queue
{
	struct version
	{
		size_t read_idx;
		size_t numElements;
	};

public:
	versioned_queue()
	{
		max_versions_ = 1024;
		versions_ = new version[max_versions_];
		read_index_ = write_index_  = 0;
		current_version_ = 0;
	}

    ~versioned_queue()
    {
        delete []versions_;
    }

	void record_version()
	{
		if (current_version_ == max_versions_)
		{
			version* new_version = new version[max_versions_*2];
			for (uint32_t idx = 0; idx < max_versions_; ++idx)
			{
				new_version[idx] = versions_[idx];
			}
			max_versions_ *= 2;
            delete [] versions_;
			versions_ = new_version;
		}
		
		versions_[current_version_].read_idx = read_index_;
		versions_[current_version_].numElements = (write_index_ - read_index_);
		current_version_++;
	}

	void Enqueue(const T& t)
	{
		if (SIZE == write_index_)
		{
			throw (std::overflow_error("no space in queue"));
		}
		queue_[write_index_++] = t;

		record_version();
	}

	//safe to return reference, as will be valid always
	T& Dequeue()
	{
		if (read_index_ == write_index_)
		{
			throw (std::underflow_error("no space in queue"));
		}

		T& element = queue_[read_index_++];
		record_version();
		return element;
	}

	void Print(size_t version)
	{
		if ((version > current_version_) ||
            (version == 0))
		{
			return;
		}

		for (uint32_t idx = 0; idx < versions_[version-1].numElements; ++idx)
		{
			std::cout << queue_[versions_[version-1].read_idx + idx] << " ";
		}
		std::cout << std::endl;
	}

private:
	T queue_[SIZE];
	version* versions_;
	size_t read_index_;
	size_t write_index_;
	size_t current_version_;
	size_t max_versions_;

};

int main()
{
	versioned_queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(11);
	queue.Enqueue(12);
	queue.Enqueue(13);
	queue.Dequeue();

	queue.Enqueue(13);

	queue.Print(1);
	queue.Print(0);
	queue.Print(2);
	queue.Print(6);

	return 0;
}
