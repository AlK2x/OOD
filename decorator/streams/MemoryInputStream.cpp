#include "MemoryInputStream.h"


bool CMemoryInputStream::IsEOF() const
{
	return m_buffer.empty();
}

uint8_t CMemoryInputStream::ReadByte()
{
	uint8_t data = m_buffer.front();
	m_buffer.erase(m_buffer.begin());
	return data;
}

std::streamsize CMemoryInputStream::ReadBlock(void * dstBuffer, std::streamsize size)
{
	std::streamsize actualSizse = m_buffer.size() < size ? m_buffer.size() : size;
	memcpy(dstBuffer, &m_buffer[0], actualSizse);
	if (actualSizse > 0)
	{
		m_buffer.erase(m_buffer.begin(), m_buffer.begin() + actualSizse);
	}
	return actualSizse;
}
