#pragma once
#include"BaseOutput.h"
#include<string>
#include<iostream>

class ConsoleOutput : public BaseOutput
{
public:
	void PutHeader(string headers[], int number);
	void PutRecord(string record[]);
	ConsoleOutput();
protected:
	int columns;
 };