#pragma once
#include "IInputDataStream.h"
#include <vector>

class CMemoryInputStream : public IInputDataStream
{
public:
	CMemoryInputStream(std::vector<uint8_t> && buffer) :m_buffer(std::move(buffer)) {}
	// Inherited via IInputDataStream
	virtual bool IsEOF() const override;
	virtual uint8_t ReadByte() override;
	virtual std::streamsize ReadBlock(void * dstBuffer, std::streamsize size) override;

private:
	std::vector<uint8_t> m_buffer;
};

