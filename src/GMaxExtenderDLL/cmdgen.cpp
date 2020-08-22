///////////////////////////////////////////////////////////////////////////////
// Name:        cmdgen.cpp
// Purpose:     Executing commands getted from the gmax "MAXScript Listener" window
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "cmdgen.h"
#include "doscommand.h"
#include "binfile.h"
#include "textfile.h"

// Get the specified number of characters from string, moves position after this symbol
tstring ParseChars(int numChars, const tstring& strText, int& nPos)
{
	// skip spaces
	TCHAR ch = strText[nPos];
	while(ch == _T(' ') || ch == _T('\t') || ch == _T('\r') || ch == _T('\n'))
	{
		ch = strText[++nPos];
	}

	// scan characters
	int nStartPos = nPos;
	while(ch != 0 && numChars > 0)
	{
		--numChars;
		ch = strText[++nPos];
	}

	// the result
	tstring strChars = strText.substr(nStartPos, nPos - nStartPos);
	return strChars;
}


// Get symbol from string, moves position after this symbol
tstring ParseSymbol(const tstring& strText, int& nPos)
{
	// skip spaces
	TCHAR ch = strText[nPos];
	while(ch == _T(' ') || ch == _T('\t') || ch == _T('\r') || ch == _T('\n'))
	{
		ch = strText[++nPos];
	}

	// check if this is a symbol
	if(!_istalpha(ch) && ch != _T('_'))
		return _T("");
	
	int nStartPos = nPos;
	ch = strText[++nPos];

	// scan the symbol
	while(_istalpha(ch) || _istdigit(ch) || ch == _T('_'))
	{
		ch = strText[++nPos];
	}

	// the result
	tstring strSymbol = strText.substr(nStartPos, nPos - nStartPos);
	return strSymbol;
}

// Get a symbol starting with number sign (#) from string, moves position after this symbol
tstring ParseSymbolNumSign(const tstring& strText, int& nPos)
{
	// skip spaces
	TCHAR ch = strText[nPos];
	while(ch == _T(' ') || ch == _T('\t') || ch == _T('\r') || ch == _T('\n'))
	{
		ch = strText[++nPos];
	}

	// check if this is started with a number sign
	if(ch != _T('#'))
		return _T("");
	
	int nStartPos = nPos;
	ch = strText[++nPos];

	// scan the symbol
	while(_istalpha(ch) || _istdigit(ch) || ch == _T('_'))
	{
		ch = strText[++nPos];
	}

	// the result
	tstring strSymbol = strText.substr(nStartPos, nPos - nStartPos);
	return strSymbol;
}

// Get quoted string from string, moves position after this string
tstring ParseString(const tstring& strText, int& nPos)
{
	// skip spaces
	TCHAR ch = strText[nPos];
	while(ch == _T(' ') || ch == _T('\t') || ch == _T('\r') || ch == _T('\n'))
	{
		ch = strText[++nPos];
	}

	// check if this is a string
	if(ch != _T('\"'))
		return _T("");

	tstring strString;
	ch = strText[++nPos];
	while(ch != _T('\"'))
	{
		if(ch == 0) return _T("");
		BOOL bSkipNext = FALSE;
		if(ch == _T('\\'))
		{
			TCHAR chNext = strText[nPos + 1];
			switch(chNext)
			{
				case _T('\"'): ch = _T('\"'); bSkipNext = TRUE; break;
				case _T('n'):  ch = _T('\n'); bSkipNext = TRUE; break;
				case _T('r'):  ch = _T('\r'); bSkipNext = TRUE; break;
				case _T('t'):  ch = _T('\t'); bSkipNext = TRUE; break;
				case _T('*'):  ch = _T('*');  bSkipNext = TRUE; break;
				case _T('?'):  ch = _T('?');  bSkipNext = TRUE; break;
				case _T('\\'): ch = _T('\\'); bSkipNext = TRUE; break;
				case _T('%'):  ch = _T('%');  bSkipNext = TRUE; break;
			}
		}
		strString += ch;
		ch = strText[++nPos];
		if(bSkipNext)
			ch = strText[++nPos];
	}

	// skip the last quote
	++nPos;

	// the result
	return strString;
}

// Get an integer from string, moves position after this string
int ParseInteger(const tstring& strText, int& nPos)
{
	// skip spaces
	TCHAR ch = strText[nPos];
	while(ch == _T(' ') || ch == _T('\t') || ch == _T('\r') || ch == _T('\n'))
	{
		ch = strText[++nPos];
	}

	// scan a sign
	int nSign = 1;
	if(ch == _T('+') || ch == _T('-'))
	{
		nSign = (ch == _T('-') ? -1 : 1);
		ch = strText[++nPos];
	}

	// scan digits
	int nInteger = 0;
	int nNumDigits = 0;
	while(_istdigit(ch))
	{
		nInteger = nInteger * 10 + (ch - _T('0'));
		nNumDigits++;
		ch = strText[++nPos];
	}
	
	// error if no digits
	if(nNumDigits == 0)
		return 0;

	// the result
	return nInteger * nSign;
}
 
// Get a float from string, moves position after this float
float ParseFloat(const tstring& strText, int& nPos)
{
	LPTSTR endptr;
	float f = (float) _tcstod(strText.c_str() + nPos, &endptr);
	nPos += endptr - strText.c_str();
	return f;
}

// Run agent command (general procedure)
void RunAgentCommand(const tstring& strText)
{
	int nPos = 0;
	tstring strSymbol = ParseSymbol(strText, nPos);
	if(strSymbol.empty()) return;

	if(_tcsicmp(strSymbol.c_str(), _T("DOSCommand")) == 0)
	{
		tstring strCommandLine = ParseString(strText, nPos);
		if(strCommandLine.empty()) return;
		DOSCommand(strCommandLine);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("FOpen")) == 0)
	{
		tstring strFileName = ParseString(strText, nPos);
		tstring strMode = ParseString(strText, nPos);
		if(strFileName.empty() || strMode.empty()) return;
		FOpen(strFileName, strMode);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("FClose")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		FClose(nHandle);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("FTell")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		FTell(nHandle);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("FSeek")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		long nOffset = ParseInteger(strText, nPos);
		tstring strOrigin = ParseSymbolNumSign(strText, nPos);
		if(nHandle == 0) return;
		FSeek(nHandle, nOffset, strOrigin);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("WriteByte")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		char nByte = (char) ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		WriteByte(nHandle, nByte);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("WriteShort")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		short nShort = (short) ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		WriteShort(nHandle, nShort);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("WriteLong")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		long nLong = ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		WriteLong(nHandle, nLong);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("WriteFloat")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		float fFloat = ParseFloat(strText, nPos);
		if(nHandle == 0) return;
		WriteFloat(nHandle, fFloat);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("WriteString")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		tstring str = ParseString(strText, nPos);
		if(nHandle == 0) return;
		WriteString(nHandle, str);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("createFile")) == 0)
	{
		tstring strFileName = ParseString(strText, nPos);
		if(strFileName.empty()) return;
		createFile(strFileName);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("openFile")) == 0)
	{
		tstring strFileName = ParseString(strText, nPos);
		tstring strMode = ParseString(strText, nPos);
		if(strFileName.empty() || strMode.empty()) return;
		openFile(strFileName, strMode);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("close")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		close(nHandle);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("filePos")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		filePos(nHandle);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("seek")) == 0)
	{
		long nHandle = ParseInteger(strText, nPos);
		long nOffset = ParseInteger(strText, nPos);
		if(nHandle == 0) return;
		seek(nHandle, nOffset);
	}
	else if(_tcsicmp(strSymbol.c_str(), _T("format")) == 0)
	{
		tstring str = ParseString(strText, nPos);
		tstring strTo = ParseChars(3, strText, nPos);
		long nHandle = ParseInteger(strText, nPos);
		if(nHandle == 0 || _tcsicmp(strTo.c_str(), _T("to:")) != 0) return;
		format(nHandle, str);
	}
}
