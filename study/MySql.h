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

//数据库对象
MYSQL mysql;

//结果集结构体
MYSQL_RES* res;

//记录
MYSQL_ROW row;

/*---------------------------------------------------------------------*/

//连接配置
const char* DataBase_UserName = "root";		//用户名
const char* DataBase_Password = "000913";		//密码
const char* DataBase_Host = "localhost";		//ip地址
const char* DataBase_Name = "sys";		//数据库名
unsigned int DataBase_port = 3306;				//端口号

/*---------------------------------------------------------------------*/

//函数声明

//连接
bool ConnectDataBase();

//断开
void FreeConnect();

//查找
void MySql_Select(const char* str);

//实现

bool ConnectDataBase()
{
	//初始化
	mysql_init(&mysql);
	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_port, NULL, 0))) {
		cout << "Error connecting to database:" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		MessageBoxA(NULL, "连接mysql成功", "消息", MB_OK);
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
	//执行sql语句
	mysql_query(&mysql, str);
	//获取结果集
	res = mysql_store_result(&mysql);
	//显示数据，给row赋值
	while (row = mysql_fetch_row(res)) {
		cout << row[1] << row[2] << endl;
	}
	getchar();
	FreeConnect();
}

#endif

