#ifndef BARCODE_H
#define BARCODE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct {
		char UUID[36]; // 唯一识别码
		char IDPhoto[1024]; //身份证照片存放的绝对路径名
	}tContrastInfo;

	typedef struct {
		int iResult; //相似度0-100
		char UUID[36]; // 唯一识别码

		int iPhotoLen1; 
		char* Photo1;
		int iPhotoLen2;
		char * Photo2;
		int iPhotoLen3;
		char* Photo3;
	} tIDPhotoInfo;

	typedef struct tagRegion {
		int x;
		int y;
		int cx;
		int cy;
		int value; //人脸比对阀值 0-100
		int iCollect; // 摄像头采集图片方式 0 : 固采, 1 : 预采
		int iTimeout; // 人脸识别算法的超时时间，单位为秒
	} T_REGION, *P_T_REGION;

	/*
	函数功能：
	打开设备。
	输入参数：
	pIn：P_T_REGION指针。视频显示区域和人脸比对阀值
	输出参数：
	pOut：8位字符串，表示物理错误码(3位厂家代码+5位错误码)。
	返回值：
	int    
	0：成功
	1：失败
	*/
	int WINAPI CAM_Open(char *pIn, char* pOut);

	/*
	函数功能：

	输入参数：
	pIn：保留。

	输出参数：
	pOut：8位字符串，表示物理错误码(3位厂家代码+5位错误码)
	返回值：
	int    
	0：成功
	1：失败
	*/
	int CAM_Close(char * pIn, char * pOut);

	/*
	函数功能：
	
	输入参数：
	pIn：保留。
	输出参数：
			pOut：
	返回值：
	int    
	0：正常
	1：设备启动中
	其它：错误码
	*/
	int CAM_Status(char* pIn, char* pOut);

	/*
	函数功能：
	通知设备执行某项操作，不等待执行结果。
	输入参数：
	iFlag  1:比对身份证照片
			 2:设备暂停照相
 			 3:设备继续照相
	pIn：当iFlag=1时，是结构体tContrastInfo；iFlag为其它值时无意思。
	输出参数：
	pOut：保留
	返回值：
	int    
	0：成功
	1：失败
	*/
	int CAM_Notify(int iFlag, char *pIn, char* pOut);


	/*
	函数功能：
	获取身份证照片的比对结果。
	输入参数：
	pIn:唯一识别码（UUID）
	iDelay:延时时间(秒)，函数必须在延时到iDelay时间到后返回
	输出参数：
	pOut：设备返回的图片信息，结构体tIDPhotoInfo
	返回值：
	int          
	0：成功
	1：失败
	*/
	int CAM_GetPhotoInfo(char* pIn, char* pOut, int iDelay);

	/*
	函数功能：

	输入参数：
	pIn：保留
	输出参数：
	pOut: 8位字符串，表示物理错误码(3位厂家代码+5位错误码)。
	返回值：
	int          
	0：成功
	1：失败
	*/
	int WINAPI CAM_Reset(char * pIn, char* pOut);

	/*
	函数功能：
	释放2.8接口中申请的动态内存。
	输入参数：
	pIn:指针，结构体tIDPhotoInfo。
	输出参数：
	。
	返回值：
	无
	*/
	void WINAPI CAM_FreePhotoInfo(char* pIn);
	

#ifdef __cplusplus
}
#endif

#endif
