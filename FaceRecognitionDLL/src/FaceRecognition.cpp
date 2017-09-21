#include "../include/FaceRecognition.h"

//json
#include "../third_party/rapidjson/include/rapidjson/document.h"
#include "../third_party/rapidjson/include/rapidjson/stringbuffer.h"

//poco
#include "Poco/StreamCopier.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPSession.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/FilePartSource.h"

int WINAPI CAM_Open(char *pIn, char* pOut) {
	
	


	return 1;
}

int __stdcall CAM_Close(char * pIn, char * pOut) {
	return 1;
}

int __stdcall CAM_Status(char* pIn, char* pOut) {
	return 1;
}

int __stdcall CAM_Notify(int iFlag, char *pIn, char* pOut) {
	return 1;
}

int __stdcall CAM_GetPhotoInfo(char* pIn, char* pOut, int iDelay) {
	return 1;
}

int __stdcall CAM_Reset(char * pIn, char* pOut) {
	return 1;
}

void __stdcall CAM_FreePhotoInfo(char* pIn)
{

}

int __stdcall FaceRecognition(const char* id, const char* camera, int* confidence) {
	std::string temp = "{\"request_id\": \"1387489868,5bcc08bc-5765-406c-aa70-73ce5bb8846f\",	\"result_idcard\": {	\"index1\": 0,	\"index2\": 0,	\"confidence\": 84.52791,	\"thresholds\": {	\"1e-3\": 65.3,	\"1e-4\": 71.8,	\"1e-5\": 76.5,	\"1e-6\": 79.9	}	},	\"time_used\": 907	}";
	

	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, "/faceid/v1/verify", Poco::Net::HTTPMessage::HTTP_1_1);

	Poco::Net::HTMLForm form;
	form.setEncoding(Poco::Net::HTMLForm::ENCODING_MULTIPART);

	form.addPart("image_idcard", new Poco::Net::FilePartSource(id));
	form.addPart("image_best", new Poco::Net::FilePartSource(camera));
	form.prepareSubmit(request);

	Poco::Net::HTTPClientSession *httpSession = new Poco::Net::HTTPClientSession("172.16.2.146", 9000);
	//httpSession->setTimeout(Poco::Timespan(20, 0));
	form.write(httpSession->sendRequest(request));

	Poco::Net::HTTPResponse res;
	std::istream &is = httpSession->receiveResponse(res);

	std::istreambuf_iterator<char> eos;
	std::string jsonResult(std::istreambuf_iterator<char>(is), eos);

	
	rapidjson::Document doc;
	doc.Parse(jsonResult.c_str());

	rapidjson::Value& request_id_val = doc["request_id"];
	std::string request_id = request_id_val.GetString();

	//这里需要处理如何取子节点的数据
	rapidjson::Value& s = doc["result_idcard"];


	*confidence = s.GetObject()["confidence"].GetDouble();
	

	return 1;
}