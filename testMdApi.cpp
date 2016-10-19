// testTraderApi.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include ".\ThostTraderApi\ThostFtdcMdApi.h"
#include "MdSpi.h"
#include <string>
using namespace std;
// UserApi����
CThostFtdcMdApi* pUserApi;

char  FRONT_ADDR[] = "tcp://180.168.146.187:10010";		// ǰ�õ�ַ
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "032488";			// ע�������������Լ���Ͷ���ߴ���
TThostFtdcPasswordType  PASSWORD = "is7moren";			// ע�������������Լ����û�����
const char *pszFlowPath = INVESTOR_ID; //���ļ����·��	
char *ppInstrumentID[] = {"m1701", "m1705"};			// ���鶩���б�ע�⣬�����ԼID���ʱ�ģ�ע����ʱ����޸�
int iInstrumentID = 2;									// ���鶩������


// ������
int iRequestID = 0;

void main(void)
{
	// ��ʼ��UserApi
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath);			// ����UserApi
	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	pUserApi->RegisterSpi(pUserSpi);						// ע���¼���
	pUserApi->RegisterFront(FRONT_ADDR);					// connect
	pUserApi->Init();

	pUserApi->Join();
	//pUserApi->Release();
}