#ifndef BARCODE_H
#define BARCODE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct {
		char UUID[36]; // Ψһʶ����
		char IDPhoto[1024]; //���֤��Ƭ��ŵľ���·����
	}tContrastInfo;

	typedef struct {
		int iResult; //���ƶ�0-100
		char UUID[36]; // Ψһʶ����

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
		int value; //�����ȶԷ�ֵ 0-100
		int iCollect; // ����ͷ�ɼ�ͼƬ��ʽ 0 : �̲�, 1 : Ԥ��
		int iTimeout; // ����ʶ���㷨�ĳ�ʱʱ�䣬��λΪ��
	} T_REGION, *P_T_REGION;

	/*
	�������ܣ�
	���豸��
	���������
	pIn��P_T_REGIONָ�롣��Ƶ��ʾ����������ȶԷ�ֵ
	���������
	pOut��8λ�ַ�������ʾ���������(3λ���Ҵ���+5λ������)��
	����ֵ��
	int    
	0���ɹ�
	1��ʧ��
	*/
	int WINAPI CAM_Open(char *pIn, char* pOut);

	/*
	�������ܣ�

	���������
	pIn��������

	���������
	pOut��8λ�ַ�������ʾ���������(3λ���Ҵ���+5λ������)
	����ֵ��
	int    
	0���ɹ�
	1��ʧ��
	*/
	int CAM_Close(char * pIn, char * pOut);

	/*
	�������ܣ�
	
	���������
	pIn��������
	���������
			pOut��
	����ֵ��
	int    
	0������
	1���豸������
	������������
	*/
	int CAM_Status(char* pIn, char* pOut);

	/*
	�������ܣ�
	֪ͨ�豸ִ��ĳ����������ȴ�ִ�н����
	���������
	iFlag  1:�ȶ����֤��Ƭ
			 2:�豸��ͣ����
 			 3:�豸��������
	pIn����iFlag=1ʱ���ǽṹ��tContrastInfo��iFlagΪ����ֵʱ����˼��
	���������
	pOut������
	����ֵ��
	int    
	0���ɹ�
	1��ʧ��
	*/
	int CAM_Notify(int iFlag, char *pIn, char* pOut);


	/*
	�������ܣ�
	��ȡ���֤��Ƭ�ıȶԽ����
	���������
	pIn:Ψһʶ���루UUID��
	iDelay:��ʱʱ��(��)��������������ʱ��iDelayʱ�䵽�󷵻�
	���������
	pOut���豸���ص�ͼƬ��Ϣ���ṹ��tIDPhotoInfo
	����ֵ��
	int          
	0���ɹ�
	1��ʧ��
	*/
	int CAM_GetPhotoInfo(char* pIn, char* pOut, int iDelay);

	/*
	�������ܣ�

	���������
	pIn������
	���������
	pOut: 8λ�ַ�������ʾ���������(3λ���Ҵ���+5λ������)��
	����ֵ��
	int          
	0���ɹ�
	1��ʧ��
	*/
	int WINAPI CAM_Reset(char * pIn, char* pOut);

	/*
	�������ܣ�
	�ͷ�2.8�ӿ�������Ķ�̬�ڴ档
	���������
	pIn:ָ�룬�ṹ��tIDPhotoInfo��
	���������
	��
	����ֵ��
	��
	*/
	void WINAPI CAM_FreePhotoInfo(char* pIn);
	

#ifdef __cplusplus
}
#endif

#endif
