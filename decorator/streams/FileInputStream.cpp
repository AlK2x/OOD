#include "FileInputStream.h"

CFileInputStream::CFileInputStream(std::ifstream & fstream)
	:m_fstream(fstream)
{
}

CFileInputStream::~CFileInputStream()
{
}

bool CFileInputStream::IsEOF() const
{
	if (m_fstream.bad())
	{
		throw std::ios_base::failure("File stream bad state");
	}	
	return m_fstream.eof();
}

uint8_t CFileInputStream::ReadByte()
{
	if (!m_fstream.good())
	{
		throw std::ios_base::failure("Stream not in good state");
	}
	
	uint8_t data;
	m_fstream >> data;
	return data;
}

std::streamsize CFileInputStream::ReadBlock(void * dstBuffer, std::streamsize size)
{
	if (!m_fstream.good())
	{
		throw std::ios_base::failure("Stream not in good state");
	}

	m_fstream.read((char*) dstBuffer, size);

	return m_fstream.gcount();
}
		