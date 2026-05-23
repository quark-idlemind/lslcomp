/** 
 * @file lscript_error.cpp
 * @brief error reporting class and strings
 *
 * $LicenseInfo:firstyear=2002&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#include "linden_common.h"

#include "lscript_error.h"

S32 gColumn = 0;
S32 gLine = 0;
S32 gInternalColumn = 0;
S32 gInternalLine = 0;

LLScriptGenerateErrorText gErrorToText;

void LLScriptFilePosition::fdotabs(LLFILE *fp, S32 tabs, S32 tabsize)
{
	S32 i;
	for (i = 0; i < tabs * tabsize; i++)
	{
		fprintf(fp, " ");
	}
}

const char* gWarningText[LSWARN_EOF] = 	 	/*Flawfinder: ignore*/
{
	"INVALID",
	"Dead code found beyond return statement"
};

const char* gErrorText[LSERROR_EOF] = 	/*Flawfinder: ignore*/
{
	"INVALID",
	"Syntax error",
	"Not all code paths return a value",
	"Function returns a value but return statement doesn't",
	"Return statement type doesn't match function return type",
	"Global functions can't change state",
	"Name previously declared within scope",
	"Name not defined within scope",
	"Type mismatch",
	"Expression must act on LValue",
	"Byte code assembly failed -- out of memory",
	"Function call mismatches type or number of arguments",
	"Use of vector or quaternion method on incorrect type",
	"Lists can't be included in lists",
	"Unitialized variables can't be included in lists",
	"Declaration requires a new scope -- use { and }",
	"CIL assembler failed",
	"Bytecode transformer failed",
	"Bytecode verification failed"
};

// Internal helper: append one diagnostic to the list.
static void collect(std::vector<LLScriptDiagnostic>& diags,
                    S32 line, S32 col, bool is_error, const char* text)
{
	LLScriptDiagnostic d;
	d.mLine    = line;
	d.mColumn  = col;
	d.mIsError = is_error;
	d.mText    = text;
	diags.push_back(d);
}

void LLScriptGenerateErrorText::writeWarning(LLFILE *fp, LLScriptFilePosition *pos, LSCRIPTWarnings warning)
{
	collect(mDiagnostics, pos->mLineNumber, pos->mColumnNumber, false, gWarningText[warning]);
	mTotalWarnings++;
}

void LLScriptGenerateErrorText::writeWarning(LLFILE *fp, S32 line, S32 col, LSCRIPTWarnings warning)
{
	collect(mDiagnostics, line, col, false, gWarningText[warning]);
	mTotalWarnings++;
}

void LLScriptGenerateErrorText::writeError(LLFILE *fp, LLScriptFilePosition *pos, LSCRIPTErrors error)
{
	collect(mDiagnostics, pos->mLineNumber, pos->mColumnNumber, true, gErrorText[error]);
	mTotalErrors++;
}

void LLScriptGenerateErrorText::writeError(LLFILE *fp, S32 line, S32 col, LSCRIPTErrors error)
{
	collect(mDiagnostics, line, col, true, gErrorText[error]);
	mTotalErrors++;
}

void LLScriptGenerateErrorText::printDiagnostics(FILE *fp) const
{
	for (const LLScriptDiagnostic& d : mDiagnostics)
	{
		fprintf(fp, "(%d, %d) : %s : %s\n",
		        d.mLine, d.mColumn,
		        d.mIsError ? "ERROR" : "WARNING",
		        d.mText.c_str());
	}
}

std::string getLScriptErrorString(LSCRIPTErrors error)
{
	return gErrorText[error];
}
