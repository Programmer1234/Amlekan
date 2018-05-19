#include <string>
#include <iostream>

#include "BasicDefs.h"
#include "Buffer.h"


Buffer::Buffer()
	: m_size(0)
	, m_buffer(0)
{ }

Buffer::Buffer(std::string str)
	: m_size (str.length())
	, m_buffer(str.cbegin(), str.cend())
{ }

void Buffer::print()
{
	for (std::vector<char>::const_iterator it = m_buffer.cbegin(); it != m_buffer.cend(); ++it){
		std::cout << *it;
	}
	std::cout << std::endl;
}


Buffer::~Buffer()
{
	try {

	} CATCH_ALL();
}
