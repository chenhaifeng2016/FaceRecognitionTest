#include "../include/FaceRecognition.h"




int WINAPI CAM_Open(char *pIn, char* pOut) {
	return 1;
}

int CAM_Close(char * pIn, char * pOut) {
	return 1;
}

int CAM_Status(char* pIn, char* pOut) {
	return 1;
}

int CAM_Notify(int iFlag, char *pIn, char* pOut) {
	return 1;
}

int CAM_GetPhotoInfo(char* pIn, char* pOut, int iDelay) {
	return 1;
}

int WINAPI CAM_Reset(char * pIn, char* pOut) {
	return 1;
}

void WINAPI CAM_FreePhotoInfo(char* pIn)
{

}