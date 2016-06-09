#include "MemoryOutputStream.h"

void CMemoryOutputStream::WriteByte(uint8_t data)
{
	m_buffer.push_back(data);
}

void CMemoryOutputStream::WriteBlock(const void * srcData, std::streamsize size)
{
	uint8_t * buf = (uint8_t *)srcData;
	try
	{
		std::vector<uint8_t> buffer(buf, buf + size);
		m_buffer.insert(m_buffer.end(), buffer.begin(), buffer.end());
	}
	catch (...)
	{
		throw std::ios_base::failure("Output Stream Exception");
	}
}
