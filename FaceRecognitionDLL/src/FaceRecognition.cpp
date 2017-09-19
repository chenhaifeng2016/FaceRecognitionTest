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
	
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";

	rapidjson::Document doc;
	doc.Parse(json);

	rapidjson::Value& s = doc["project"];
	
	s.IsString();
	std::string str = s.GetString();


	/*
	POST / faceid / v1 / verify HTTP / 1.1
	Host: 172.16.2.146 : 9000
	Cache - Control : no - cache
	Postman - Token : 25251790 - a2db - 8a6d - 5247 - be6cd79fd997
	Content - Type : multipart / form - data; boundary = ----WebKitFormBoundary7MA4YWxkTrZu0gW

	------WebKitFormBoundary7MA4YWxkTrZu0gW
	Content - Disposition: form - data; name = "image_best"; filename = "camera.jpg"
	Content - Type: image / jpeg


	------WebKitFormBoundary7MA4YWxkTrZu0gW
	Content - Disposition : form - data; name = "image_idcard"; filename = "id.bmp"
	Content - Type: image / bmp


	------WebKitFormBoundary7MA4YWxkTrZu0gW--*/
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, "/faceid/v1/verify", Poco::Net::HTTPMessage::HTTP_1_1);
	Poco::Net::HTMLForm form;
	form.setEncoding(Poco::Net::HTMLForm::ENCODING_MULTIPART);
	form.set("entry1", "value1");
	form.set("entry2", "value2");
	form.addPart("file", new Poco::Net::FilePartSource("/home/abc/Pictures/sample.png"));
	form.prepareSubmit(request);

	Poco::Net::HTTPClientSession *httpSession = new Poco::Net::HTTPClientSession("172.16.2.146", 9000);
	httpSession->setTimeout(Poco::Timespan(20, 0));
	form.write(httpSession->sendRequest(request));

	Poco::Net::HTTPResponse res;
	std::istream &is = httpSession->receiveResponse(res);
	Poco::StreamCopier::copyStream(is, std::cout);
	

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