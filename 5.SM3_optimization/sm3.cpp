#include<iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include"sm3.h"

#define u_char unsigned char



using namespace std;


int main()
{
	int batch;
	cout << "��������Թ�ģ��";
	cin >> batch;

	clock_t begin, end;
	string msg = "hello world";
	u_char* c_msg = (u_char*)msg.c_str();
	unsigned char res[32];
	
	begin = clock();
	for (int i = 0; i < batch; i++) {
		sm3(c_msg, msg.size(), res);
	}
	end = clock();

	cout << "Hashֵ:";
	for (int i = 0; i < 32; i++)
	{
		printf("%02x", res[i]);
		if (((i + 1) % 4) == 0) printf(" ");
	}
	
	cout << "\n���Դ�����" << batch << endl;
	cout << "Ч����ʱ��" << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
