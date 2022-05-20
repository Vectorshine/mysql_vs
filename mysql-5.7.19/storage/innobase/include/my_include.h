#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include<stdlib.h>
#define MAX_LINE 1024
#include<vector>
using namespace std;
 
static int hash_num = 3;
/************************************
 		读取指定行数据           
************************************/
inline void ReadLineData(char* fileName, int lineNum, char* data)
{
	ifstream in;
	in.open(fileName);
 
	int line = 1;
	while (in.getline(data, 1024))
	{
		if (lineNum == line)
		{
			break;
		}
		line ++ ;
	}
 
	in.close();
}
 
/************************************
 		字符串转string类型            
************************************/
inline string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
 
 
/************************************
        修改行数据
************************************/
inline void ModifyLineData(char* fileName, int lineNum, char* lineData)
{
	ifstream in;
	in.open(fileName);
 
	string strFileData = "";
	int line = 1;
	char tmpLineData[1024] = {0};
	while(in.getline(tmpLineData, sizeof(tmpLineData)))
	{
		if (line == lineNum)
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(tmpLineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
 
	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}
inline void fp_init(char *fileName)
{
	FILE *fp = NULL;
	fp = fopen(fileName, "w");
//	fwrite(0, sizeof(0), 1, fp);
	char c[3] = {"0\n"};
	fwrite(&c, 2, 1, fp);
	fclose(fp);
}
inline int update_total_num(char *fileName)
{
	char st[16] = {0};
	char total_num[16] = {0};
	ReadLineData(fileName, 1, total_num);
	int now_total_num = 0;
	now_total_num = atoi(total_num) + 1;
	itoa(now_total_num,st,10);
	ModifyLineData(fileName, 1, st);
	return now_total_num;
}
inline int write_fp(char *fileName, vector<bool> bf_array)//返回值是当前总行数（除了第一行）。 
{
	FILE *fp = NULL;
	fp = fopen(fileName, "r+b");
  
    fseek(fp, 0, SEEK_END);
	//bool yy = true;
	//fprintf(fp, "%d\n", yy);
	for (int i = 0; i < bf_array.size(); i++)
	{
		if (bf_array[i])
			fprintf(fp, "1");
		else
			fprintf(fp, "0");
	}
	fprintf(fp, "\n");
	fclose(fp);
	return update_total_num(fileName);
}


