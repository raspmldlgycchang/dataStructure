#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef unsigned int HANDLE;
struct HandleData {
	HANDLE h;
	char* p_string;
};
class HandleManager {
private:
	HandleData** mp_users;
	unsigned int m_len, m_max_count, m_max_user_cnt,m_gen_value;
public:
	HandleManager(unsigned int a_max_user_cnt, unsigned int a_max_count);
	~HandleManager();
	HANDLE SetString(const char* ap_string);
	void printString(HANDLE h_str);
};
HandleManager::HandleManager(unsigned int a_max_user_cnt, unsigned int a_max_count)
{
	m_gen_value = 1;
	m_max_count = a_max_count, m_max_user_cnt = a_max_user_cnt;
	mp_users = new HandleData * [m_max_user_cnt];
	for (unsigned int j = 0; j < m_max_user_cnt; j++) {
		for (unsigned int i = 0; i < m_max_count; i++) {
			mp_users[j] = new HandleData[m_max_count];
		}
	}
	for(unsigned int j=0;j<)
}