#pragma once
#ifndef MySql
#define MySql

#include <stdio.h>
#include <WinSock.h>
#include <Windows.h>
#include <mysql.h>
#include <string>
#include<iostream>

using namespace std;

//���ݿ����
MYSQL mysql;

//������ṹ��
MYSQL_RES* res;

//��¼
MYSQL_ROW row;

/*---------------------------------------------------------------------*/

//��������
const char* DataBase_UserName = "root";		//�û���
const char* DataBase_Password = "000913";		//����
const char* DataBase_Host = "localhost";		//ip��ַ
const char* DataBase_Name = "sys";		//���ݿ���
unsigned int DataBase_port = 3306;				//�˿ں�

/*---------------------------------------------------------------------*/

//��������

//����
bool ConnectDataBase();

//�Ͽ�
void FreeConnect();

//����
void MySql_Select(const char* str);

//ʵ��

bool ConnectDataBase()
{
	//��ʼ��
	mysql_init(&mysql);
	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_port, NULL, 0))) {
		cout << "Error connecting to database:" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		MessageBoxA(NULL, "����mysql�ɹ�", "��Ϣ", MB_OK);
		cout << "Connected..." << endl;
		return true;
	}

}

void FreeConnect()
{
	mysql_close(&mysql);
}

void MySql_Select(const char* str)
{
	ConnectDataBase();
	//ִ��sql���
	mysql_query(&mysql, str);
	//��ȡ�����
	res = mysql_store_result(&mysql);
	//��ʾ���ݣ���row��ֵ
	while (row = mysql_fetch_row(res)) {
		cout << row[1] << row[2] << endl;
	}
	getchar();
	FreeConnect();
}

#endif

