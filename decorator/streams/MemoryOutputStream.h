#pragma once
#include "IOutputDataStream.h"

class CMemoryOutputStream : public IOutputDataStream
{
public:
	CMemoryOutputStream();
	~CMemoryOutputStream();

	// Inherited via IOutputDataStream
	virtual void WriteByte(uint8_t data) override;
	virtual void WriteBlock(const void * srcData, std::streamsize size) override;

private:
	std::vector<uint8_t> m_buffer;
};

