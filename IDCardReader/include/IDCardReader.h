#ifndef IDCARD_READER_H
#define IDCARD_READER_H

#define WIN32_LEAN_AND_MEAN 
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif
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

	int WINAPI ReadIDCard(const char* port, IDCARD * idcard);


#ifdef __cplusplus
}
#endif

#endif
