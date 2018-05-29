#pragma once

#include <vector>

/**
	Buffer of data
*/
class Buffer {

public:

	Buffer();

	Buffer(std::string str);

	size_t size() {
		return m_size;
	}

	void print();

	~Buffer();

private:

	size_t m_size;
	std::vector<char> m_buffer;
};