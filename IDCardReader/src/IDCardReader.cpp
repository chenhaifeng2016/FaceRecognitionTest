#include "../include/IDCardReader.h"
#include "IDReader.h"

IDReader reader;

int WINAPI ReadIDCard(const char* port, IDCARD * idcard) {
	if (!reader.Init(port))
		return 0;

	if (!reader.ReadIDCard(idcard)) {
		reader.UnInit();
		return 0;
	}
		

	return 1;
}