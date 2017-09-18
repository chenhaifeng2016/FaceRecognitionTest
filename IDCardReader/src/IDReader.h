#ifndef _IDREADER_H_
#define _IDREADER_H_

#include "SerialCom.h"
#include "../include/IDCardReader.h"


class IDReader
{
public:
	IDReader();
	~IDReader();

	bool Init(std::string port);
	bool ReadIDNo(char* idno, int* len);
	bool ReadIDCard(IDCARD* id);
	void UnInit();

private:
	SerialCom com;
	unsigned char calc_lrc(unsigned char * data, int data_len);
	const int pkglen = 5;
};

#endif
