#pragma once
#include "IInputDataStream.h"
#include <iostream>
#include <fstream>

class CFileInputStream : public IInputDataStream
{
public:
	CFileInputStream(std::ifstream & fstream);
	~CFileInputStream();

	// Inherited via IInputDataStream
	virtual bool IsEOF() const override;
	virtual uint8_t ReadByte() override;
	virtual std::streamsize ReadBlock(void * dstBuffer, std::streamsize size) override;

private:
	std::ifstream & m_fstream;
};

