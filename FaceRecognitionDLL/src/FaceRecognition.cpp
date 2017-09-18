#include "../include/FaceRecognition.h"

//json
#include "../third_party/rapidjson/include/rapidjson/document.h"
#include "../third_party/rapidjson/include/rapidjson/stringbuffer.h"

//libcurl
#include "../third_party/curl-7.55.1/include/curl/curl.h"


int WINAPI CAM_Open(char *pIn, char* pOut) {
	
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";

	rapidjson::Document doc;
	doc.Parse(json);

	rapidjson::Value& s = doc["project"];
	
	s.IsString();
	OutputDebugString(s.GetString());

	// libcurl
	curl_global_init(CURL_GLOBAL_ALL);

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