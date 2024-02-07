#pragma once

#include"DocWriter.h"

class HTMLWriter : public DocWriter
{
public:
	HTMLWriter();
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();
	
	// 텍스트를 파일로 저장시킨다. 
	virtual void Write();

	//폰트를 지정한다.
	void SetFont(const string& fileName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;

};