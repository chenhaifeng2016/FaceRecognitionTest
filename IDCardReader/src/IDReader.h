#ifndef _IDREADER_H_
#define _IDREADER_H_

#include "SerialCom.h"

//һ�ֽڶ��룬ע��˳��
typedef struct idcard {
	char name[30];
	char gender[2];
	char nationality[4];
	char birthday[16];
	char address[70];
	char idno[36];
	char issuer[30];
	char expire_begin[16];
	char expire_end[16];
	//char address_new[70];
	char reserved[36];
	//���ϱ�����256�ֽ�

	char image[1024];
}IDCARD;

class IDReader
{
public:
	IDReader();
	~IDReader();

	bool Init(std::string port);
	bool ReadIDNo(char* idno, int* len);
	bool ReadIDCard(IDCARD* id);

private:
	SerialCom com;
	unsigned char calc_lrc(unsigned char * data, int data_len);
	const int pkglen = 5;
};

#endif
