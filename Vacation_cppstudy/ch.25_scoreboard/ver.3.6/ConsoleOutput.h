#pragma once
#include"BaseOutput.h"
#include<string>
#include<iostream>

class ConsoleOutput : public BaseOutput
{
public:
	virtual void BeginTable(STR title);
	virtual void PutHeader(string headers[], int number);
	virtual void PutRecord(string record[]);
	virtual void EndTable();
	virtual void Write(STR text);
	ConsoleOutput();
	virtual ~ConsoleOutput();
protected:
	int columns;		//헤더의 개수

	virtual ostream& StdOut();
 };