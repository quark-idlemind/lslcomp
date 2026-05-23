/**
 * @file lscript_tree.cpp
 * @brief implements methods for lscript_tree.h classes
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

// TO DO: Move print functionality from .h file to here

#include "linden_common.h"

#include "lscript_tree.h"
#include "lscript_typecheck.h"
//#include "lscript_bytecode.h"
//#include "lscript_heap.h"
#include "lscript_library.h"
//#include "lscript_alloc.h"

//#define LSL_INCLUDE_DEBUG_INFO


void LLScriptType::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		type = mType;
		break;
	default:
		break;
	}
}

S32 LLScriptType::getSize()
{
	return LSCRIPTDataSize[mType];
}

void LLScriptConstant::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		break;
	}
}

S32 LLScriptConstant::getSize()
{
	printf("Script Constant Base class -- should never get here!\n");
	return 0;
}



void LLScriptConstantInteger::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		type = mType;
		break;
	default:
		break;
	}
}

S32 LLScriptConstantInteger::getSize()
{
	return LSCRIPTDataSize[LST_INTEGER];
}

void LLScriptConstantFloat::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		type = mType;
		break;
	default:
		break;
	}
}

S32 LLScriptConstantFloat::getSize()
{
	return LSCRIPTDataSize[LST_FLOATINGPOINT];
}

void LLScriptConstantString::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		type = mType;
		break;
	default:
		break;
	}
}

S32 LLScriptConstantString::getSize()
{
	return (S32)strlen(mValue) + 1;
}

void LLScriptIdentifier::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mScopeEntry)
			type = mScopeEntry->mType;
		else
			type = LST_NULL;
		break;
	default:
		break;
	}
}

S32 LLScriptIdentifier::getSize()
{

	return 0;
}



void LLScriptSimpleAssignable::addAssignable(LLScriptSimpleAssignable *assign)
{
	if (mNextp)
	{
		assign->mNextp = mNextp;
	}
	mNextp = assign;
}

void LLScriptSimpleAssignable::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	fprintf(fp, "Simple Assignable Base Class -- should never get here!\n");
}

S32 LLScriptSimpleAssignable::getSize()
{

	printf("Simple Assignable Base Class -- should never get here!\n");
	return 0;
}

void LLScriptSAIdentifier::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		{
			LLScriptScopeEntry *entry = scope->findEntry(mIdentifier->mName);
			if (!entry)
			{
				gErrorToText.writeError(fp, this, LSERROR_UNDEFINED_NAME);
			}
			else
			{
				// if we did find it, make sure this identifier is associated with the correct scope entry
				mIdentifier->mScopeEntry = entry;
			}
			if (mNextp)
			{
				mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			}
		}
		break;

	default:
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptSAIdentifier::getSize()
{
	return mIdentifier->getSize();
}

void LLScriptSAConstant::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		mConstant->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptSAConstant::getSize()
{
	return mConstant->getSize();
}


// HACK! Babbage: should be converted to virtual on LSCRIPTSimpleAssignableType to avoid downcasts.
void LLScriptSAVector::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		// vector's take floats
		mEntry3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mEntry2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mEntry1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		type = LST_VECTOR;
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		mEntry3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mEntry2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mEntry1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptSAVector::getSize()
{
	return mEntry1->getSize() + mEntry2->getSize() + mEntry3->getSize();
}

void LLScriptSAQuaternion::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		// vector's take floats
		mEntry4->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mEntry3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mEntry2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mEntry1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		type = LST_QUATERNION;
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		mEntry4->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mEntry3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mEntry2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mEntry1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptSAQuaternion::getSize()
{
	return mEntry1->getSize() + mEntry2->getSize() + mEntry3->getSize() + mEntry4->getSize();
}

void LLScriptSAList::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mEntryList)
			mEntryList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		type = LST_LIST;
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		if (mEntryList)
			mEntryList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, ldata);
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, ldata);
		}
		break;
	}
}

S32 LLScriptSAList::getSize()
{
	return mEntryList->getSize();
}

void LLScriptGlobalVariable::addGlobal(LLScriptGlobalVariable *global)
{
	if (mNextp)
	{
		global->mNextp = mNextp;
	}
	mNextp = global;
}

void LLScriptGlobalVariable::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

// Push initialised variable of type on to stack.
void LLScriptGlobalVariable::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		if (scope->checkEntry(mIdentifier->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			if (mAssignable)
			{
				mAssignable->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			}
			// this needs to go after expression decent to make sure that we don't add ourselves or something silly
			mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_GLOBAL, mType->mType);
			if (mIdentifier->mScopeEntry && mAssignable)
					mIdentifier->mScopeEntry->mAssignable = mAssignable;
		}
		break;
	case LSCP_TYPE:
		// if the variable has an assignable, it must assignable to the variable's type
		if (mAssignable)
		{
			mAssignable->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mAssignableType = type;
			if (!legal_assignment(mType->mType, mAssignableType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
		}
		break;
	default:
		mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mAssignable)
		{
			mAssignable->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptGlobalVariable::getSize()
{
	S32 return_size;

	return_size = mType->getSize();
	return return_size;
}

void LLScriptEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	fprintf(fp, "Event Base Class -- should never get here!\n");
}

S32 LLScriptEvent::getSize()
{
	printf("Event Base Class -- should never get here!\n");
	return 0;
}
static void checkForDuplicateHandler(LLFILE *fp, LLScriptFilePosition *pos,
				     LLScriptScope *scope,
				     const char* name)
{
    LLScriptScope *parent = scope->mParentScope;
    if (parent->checkEntry((char*)name))
    {
        gErrorToText.writeError(fp, pos, LSERROR_DUPLICATE_NAME);
    }
    else
    {
        parent->addEntry(((char*)name), LIT_HANDLER, LST_NULL);
    }
}

void LLScriptStateEntryEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "state_entry");
	        break;
	default:
		break;
	}
}

S32 LLScriptStateEntryEvent::getSize()
{
	return 0;
}

void LLScriptStateExitEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
        case LSCP_SCOPE_PASS1:
                checkForDuplicateHandler(fp, this, scope, "state_exit");
	        break;
	default:
		break;
	}
}

S32 LLScriptStateExitEvent::getSize()
{
	return 0;
}

void LLScriptTouchStartEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
		break;
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "touch_start");
		if (scope->checkEntry(mCount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
		break;
	default:
		mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptTouchStartEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptTouchEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
		break;
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "touch");
		if (scope->checkEntry(mCount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
		break;
	default:
		mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptTouchEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptTouchEndEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
		break;
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "touch_end");
		if (scope->checkEntry(mCount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
		break;
	default:
		mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptTouchEndEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptCollisionStartEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
		break;
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "collision_start");
		if (scope->checkEntry(mCount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptCollisionStartEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptCollisionEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
		break;
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "collision");
		if (scope->checkEntry(mCount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptCollisionEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptCollisionEndEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
		break;
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "collision_end");
		if (scope->checkEntry(mCount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mCount->mScopeEntry = scope->addEntry(mCount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mCount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptCollisionEndEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptLandCollisionStartEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "land_collision_start");
		if (scope->checkEntry(mPosition->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mPosition->mScopeEntry = scope->addEntry(mPosition->mName, LIT_VARIABLE, LST_VECTOR);
		}
		break;
	default:
		mPosition->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptLandCollisionStartEvent::getSize()
{
	// vector = 12
	return 12;
}



void LLScriptLandCollisionEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "land_collision");
		if (scope->checkEntry(mPosition->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mPosition->mScopeEntry = scope->addEntry(mPosition->mName, LIT_VARIABLE, LST_VECTOR);
		}
		break;
	default:
		mPosition->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptLandCollisionEvent::getSize()
{
	// vector = 12
	return 12;
}


void LLScriptLandCollisionEndEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "land_collision_end");
		if (scope->checkEntry(mPosition->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mPosition->mScopeEntry = scope->addEntry(mPosition->mName, LIT_VARIABLE, LST_VECTOR);
		}
		break;
	default:
		mPosition->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptLandCollisionEndEvent::getSize()
{
	// vector = 12
	return 12;
}


void LLScriptInventoryEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "changed");
		if (scope->checkEntry(mChange->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mChange->mScopeEntry = scope->addEntry(mChange->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mChange->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptInventoryEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptAttachEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "attach");
		if (scope->checkEntry(mAttach->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mAttach->mScopeEntry = scope->addEntry(mAttach->mName, LIT_VARIABLE, LST_KEY);
		}
		break;
	default:
		mAttach->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptAttachEvent::getSize()
{
	// key = 4
	return 4;
}

void LLScriptDataserverEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "dataserver");
		if (scope->checkEntry(mID->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mID->mScopeEntry = scope->addEntry(mID->mName, LIT_VARIABLE, LST_KEY);
		}
		if (scope->checkEntry(mData->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mData->mScopeEntry = scope->addEntry(mData->mName, LIT_VARIABLE, LST_STRING);
		}
		break;
	default:
		mID->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mData->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptDataserverEvent::getSize()
{
	// key + string = 8
	return 8;
}

void LLScriptTimerEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "timer");
		break;

	default:
		break;
	}
}

S32 LLScriptTimerEvent::getSize()
{
	return 0;
}

void LLScriptMovingStartEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "moving_start");
		break;

	default:
		break;
	}
}

S32 LLScriptMovingStartEvent::getSize()
{
	return 0;
}

void LLScriptMovingEndEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "moving_end");
		break;

	default:
		break;
	}
}

S32 LLScriptMovingEndEvent::getSize()
{
	return 0;
}

void LLScriptRTPEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "run_time_perms");
		if (scope->checkEntry(mRTPermissions->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mRTPermissions->mScopeEntry = scope->addEntry(mRTPermissions->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mRTPermissions->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptRTPEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptChatEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "listen"); // note: this is actually listen in lsl source
		if (scope->checkEntry(mChannel->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mChannel->mScopeEntry = scope->addEntry(mChannel->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mName->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mName->mScopeEntry = scope->addEntry(mName->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mID->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mID->mScopeEntry = scope->addEntry(mID->mName, LIT_VARIABLE, LST_KEY);
		}
		if (scope->checkEntry(mMessage->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mMessage->mScopeEntry = scope->addEntry(mMessage->mName, LIT_VARIABLE, LST_STRING);
		}
		break;
	default:
		mChannel->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mName->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mID->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mMessage->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptChatEvent::getSize()
{
	// integer + key + string + string = 16
	return 16;
}

void LLScriptSensorEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "sensor");
		if (scope->checkEntry(mNumber->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mNumber->mScopeEntry = scope->addEntry(mNumber->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mNumber->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptSensorEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptObjectRezEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "object_rez");
		if (scope->checkEntry(mID->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mID->mScopeEntry = scope->addEntry(mID->mName, LIT_VARIABLE, LST_KEY);
		}
		break;
	default:
		mID->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptObjectRezEvent::getSize()
{
	// key = 4
	return 4;
}

void LLScriptControlEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "control");
		if (scope->checkEntry(mName->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mName->mScopeEntry = scope->addEntry(mName->mName, LIT_VARIABLE, LST_KEY);
		}
		if (scope->checkEntry(mLevels->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mLevels->mScopeEntry = scope->addEntry(mLevels->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mEdges->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mEdges->mScopeEntry = scope->addEntry(mEdges->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mName->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mLevels->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mEdges->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptControlEvent::getSize()
{
	// key + integer + integer = 12
	return 12;
}

void LLScriptLinkMessageEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "link_message");
		if (scope->checkEntry(mSender->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mSender->mScopeEntry = scope->addEntry(mSender->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mNum->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mNum->mScopeEntry = scope->addEntry(mNum->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mStr->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mStr->mScopeEntry = scope->addEntry(mStr->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mID->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mID->mScopeEntry = scope->addEntry(mID->mName, LIT_VARIABLE, LST_KEY);
		}
		break;
	default:
		mSender->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mNum->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStr->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mID->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptLinkMessageEvent::getSize()
{
	// integer + key + integer + string = 16
	return 16;
}

void LLScriptRemoteEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "remote_event");
		if (scope->checkEntry(mType->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mType->mScopeEntry = scope->addEntry(mType->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mChannel->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mChannel->mScopeEntry = scope->addEntry(mChannel->mName, LIT_VARIABLE, LST_KEY);
		}
		if (scope->checkEntry(mMessageID->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mMessageID->mScopeEntry = scope->addEntry(mMessageID->mName, LIT_VARIABLE, LST_KEY);
		}
		if (scope->checkEntry(mSender->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mSender->mScopeEntry = scope->addEntry(mSender->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mIntVal->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mIntVal->mScopeEntry = scope->addEntry(mIntVal->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mStrVal->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mStrVal->mScopeEntry = scope->addEntry(mStrVal->mName, LIT_VARIABLE, LST_STRING);
		}
		break;
	default:
		mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mChannel->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mMessageID->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mSender->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mIntVal->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStrVal->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptRemoteEvent::getSize()
{
	// integer + key + key + string + integer + string = 24
	return 24;
}

void LLScriptHTTPResponseEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{

	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "http_response");
		if (scope->checkEntry(mRequestId->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mRequestId->mScopeEntry = scope->addEntry(mRequestId->mName, LIT_VARIABLE, LST_KEY);
		}

		if (scope->checkEntry(mStatus->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mStatus->mScopeEntry = scope->addEntry(mStatus->mName, LIT_VARIABLE, LST_INTEGER);
		}

		if (scope->checkEntry(mMetadata->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mMetadata->mScopeEntry = scope->addEntry(mMetadata->mName, LIT_VARIABLE, LST_LIST);
		}

		if (scope->checkEntry(mBody->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mBody->mScopeEntry = scope->addEntry(mBody->mName, LIT_VARIABLE, LST_STRING);
		}
		break;


	default:
		mRequestId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStatus->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mMetadata->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mBody->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptHTTPResponseEvent::getSize()
{
	// key + integer + list + string = 16
	return 16;
}

void LLScriptHTTPRequestEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{

	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "http_request");
		if (scope->checkEntry(mRequestId->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mRequestId->mScopeEntry = scope->addEntry(mRequestId->mName, LIT_VARIABLE, LST_KEY);
		}

		if (scope->checkEntry(mMethod->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mMethod->mScopeEntry = scope->addEntry(mMethod->mName, LIT_VARIABLE, LST_STRING);
		}

		if (scope->checkEntry(mBody->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mBody->mScopeEntry = scope->addEntry(mBody->mName, LIT_VARIABLE, LST_STRING);
		}
		break;


	default:
		mRequestId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mMethod->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mBody->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptHTTPRequestEvent::getSize()
{
	// key + string + string = 12
	return 12;
}

void LLScriptTransactionResultEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{

	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "transaction_result");
		if (scope->checkEntry(mRequestId->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mRequestId->mScopeEntry = scope->addEntry(mRequestId->mName, LIT_VARIABLE, LST_KEY);
		}

		if (scope->checkEntry(mSuccess->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mSuccess->mScopeEntry = scope->addEntry(mSuccess->mName, LIT_VARIABLE, LST_INTEGER);
		}

		if (scope->checkEntry(mData->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mData->mScopeEntry = scope->addEntry(mData->mName, LIT_VARIABLE, LST_STRING);
		}
		break;


	default:
		mRequestId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mSuccess->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mData->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptTransactionResultEvent::getSize()
{
	// key + integer + string = 12
	return 12;
}

void LLScriptPathUpdateEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{

	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "path_update");
		if (scope->checkEntry(mTyp->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mTyp->mScopeEntry = scope->addEntry(mTyp->mName, LIT_VARIABLE, LST_INTEGER);
		}

		if (scope->checkEntry(mReserved->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mReserved->mScopeEntry = scope->addEntry(mReserved->mName, LIT_VARIABLE, LST_LIST);
		}


	default:
		mTyp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mReserved->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptPathUpdateEvent::getSize()
{
	// integer + list = 8
	return 8;
}

void LLScriptExperiencePermissionsEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{

	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "experience_permissions");
		if (scope->checkEntry(mAgentId->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mAgentId->mScopeEntry = scope->addEntry(mAgentId->mName, LIT_VARIABLE, LST_INTEGER);
		}


	default:
		mAgentId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptExperiencePermissionsEvent::getSize()
{
	// key = 4
	return 4;
}

void LLScriptExperiencePermissionsDeniedEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{

	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "experience_permissions_denied");
		if (scope->checkEntry(mAgentId->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mAgentId->mScopeEntry = scope->addEntry(mAgentId->mName, LIT_VARIABLE, LST_INTEGER);
		}

		if (scope->checkEntry(mReason->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mReason->mScopeEntry = scope->addEntry(mReason->mName, LIT_VARIABLE, LST_LIST);
		}


	default:
		mAgentId->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mReason->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptExperiencePermissionsDeniedEvent::getSize()
{
	// key + integer = 8
	return 8;
}

void LLScriptMoneyEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "money");
		if (scope->checkEntry(mName->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mName->mScopeEntry = scope->addEntry(mName->mName, LIT_VARIABLE, LST_KEY);
		}
		if (scope->checkEntry(mAmount->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mAmount->mScopeEntry = scope->addEntry(mAmount->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mName->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mAmount->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptMoneyEvent::getSize()
{
	// key + integer = 8
	return 8;
}

void LLScriptEmailEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "email");
		if (scope->checkEntry(mTime->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mTime->mScopeEntry = scope->addEntry(mTime->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mAddress->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mAddress->mScopeEntry = scope->addEntry(mAddress->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mSubject->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mSubject->mScopeEntry = scope->addEntry(mSubject->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mBody->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mBody->mScopeEntry = scope->addEntry(mBody->mName, LIT_VARIABLE, LST_STRING);
		}
		if (scope->checkEntry(mNumber->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mNumber->mScopeEntry = scope->addEntry(mNumber->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mTime->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mAddress->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mSubject->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mBody->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mNumber->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptEmailEvent::getSize()
{
	// string + string + string + string + integer = 16
	return 20;
}

void LLScriptRezEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "on_rez");
		if (scope->checkEntry(mStartParam->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mStartParam->mScopeEntry = scope->addEntry(mStartParam->mName, LIT_VARIABLE, LST_INTEGER);
		}
		break;
	default:
		mStartParam->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptRezEvent::getSize()
{
	// integer = 4
	return 4;
}

void LLScriptNoSensorEvent::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
        case LSCP_SCOPE_PASS1:
     	        checkForDuplicateHandler(fp, this, scope, "no_sensor");
	        break;
	default:
		break;
	}
}

S32 LLScriptNoSensorEvent::getSize()
{
	return 0;
}

void LLScriptAtTarget::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "at_target");
		if (scope->checkEntry(mTargetNumber->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mTargetNumber->mScopeEntry = scope->addEntry(mTargetNumber->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mTargetPosition->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mTargetPosition->mScopeEntry = scope->addEntry(mTargetPosition->mName, LIT_VARIABLE, LST_VECTOR);
		}
		if (scope->checkEntry(mOurPosition->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mOurPosition->mScopeEntry = scope->addEntry(mOurPosition->mName, LIT_VARIABLE, LST_VECTOR);
		}
		break;
	default:
		mTargetNumber->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mTargetPosition->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mOurPosition->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptAtTarget::getSize()
{
	// integer + vector + vector = 28
	return 28;
}



void LLScriptNotAtTarget::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
        case LSCP_SCOPE_PASS1:
	        checkForDuplicateHandler(fp, this, scope, "not_at_target");
	        break;

	default:
		break;
	}
}

S32 LLScriptNotAtTarget::getSize()
{
	return 0;
}

void LLScriptAtRotTarget::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		checkForDuplicateHandler(fp, this, scope, "at_rot_target");
		if (scope->checkEntry(mTargetNumber->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mTargetNumber->mScopeEntry = scope->addEntry(mTargetNumber->mName, LIT_VARIABLE, LST_INTEGER);
		}
		if (scope->checkEntry(mTargetRotation->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mTargetRotation->mScopeEntry = scope->addEntry(mTargetRotation->mName, LIT_VARIABLE, LST_QUATERNION);
		}
		if (scope->checkEntry(mOurRotation->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mOurRotation->mScopeEntry = scope->addEntry(mOurRotation->mName, LIT_VARIABLE, LST_QUATERNION);
		}
		break;
	default:
		mTargetNumber->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mTargetRotation->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mOurRotation->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}

S32 LLScriptAtRotTarget::getSize()
{
	// integer + quaternion + quaternion = 36
	return 36;
}



void LLScriptNotAtRotTarget::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
        case LSCP_SCOPE_PASS1:
	  checkForDuplicateHandler(fp, this, scope, "not_at_rot_target");
	  break;

	default:
		break;
	}
}

S32 LLScriptNotAtRotTarget::getSize()
{
	return 0;
}



void LLScriptExpression::addExpression(LLScriptExpression *expression)
{
	if (mNextp)
	{
		expression->mNextp = mNextp;
	}
	mNextp = expression;
}

void LLScriptExpression::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	fprintf(fp, "Expression Base Class -- should never get here!\n");
}

S32 LLScriptExpression::getSize()
{
	printf("Expression Base Class -- should never get here!\n");
	return 0;
}

void LLScriptExpression::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

void LLScriptForExpressionList::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mSecondp)
		{
			mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptForExpressionList::getSize()
{
	return 0;
}

// CIL code generation requires both caller and callee scope entries, so cannot use normal recurse signature.
// TODO: Refactor general purpose recurse calls in to pass specific virtuals using visitor pattern to select method by pass and node type.
void LLScriptFuncExpressionList::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!entry->mFunctionArgs.getType(entrycount))
			{
				gErrorToText.writeError(fp, this, LSERROR_FUNCTION_TYPE_ERROR);
			}
			if (!legal_assignment(entry->mFunctionArgs.getType(entrycount), mFirstp->mReturnType))
			{
				gErrorToText.writeError(fp, this, LSERROR_FUNCTION_TYPE_ERROR);
			}
			count++;
			entrycount++;
			if (mSecondp)
			{
				mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
				if (mSecondp->mReturnType)
				{
					count++;
					if (!entry->mFunctionArgs.getType(entrycount))
					{
						gErrorToText.writeError(fp, this, LSERROR_FUNCTION_TYPE_ERROR);
					}
					if (!legal_assignment(entry->mFunctionArgs.getType(entrycount), mSecondp->mReturnType))
					{
						gErrorToText.writeError(fp, this, LSERROR_FUNCTION_TYPE_ERROR);
					}
				}
			}
		}
		break;
	default:
		mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mSecondp)
		{
			mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptFuncExpressionList::getSize()
{
	return 0;
}

void LLScriptListExpressionList::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mSecondp)
		{
			mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptListExpressionList::getSize()
{
	return 0;
}

// Returns true if identifier is a parameter and false if identifier is a local variable within function_scope.
// If assignment is to global variable, pushes this pointer on to stack.
void LLScriptLValue::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		{
			LLScriptScopeEntry *entry = scope->findEntry(mIdentifier->mName);
			if (!entry || (  (entry->mIDType != LIT_GLOBAL) && (entry->mIDType != LIT_VARIABLE)))
			{
				gErrorToText.writeError(fp, this, LSERROR_UNDEFINED_NAME);
			}
			else
			{
				// if we did find it, make sure this identifier is associated with the correct scope entry
				mIdentifier->mScopeEntry = entry;
			}
		}
		break;
	case LSCP_TYPE:
		// if we have an accessor, we need to change what type our identifier returns and set our offset value
		if (mIdentifier->mScopeEntry)
		{
			if (mAccessor)
			{
				BOOL b_ok = FALSE;
				if (mIdentifier->mScopeEntry->mIDType == LIT_VARIABLE)
				{
					if (mIdentifier->mScopeEntry->mType == LST_VECTOR)
					{
						if (!strcmp("x", mAccessor->mName))
						{
							mOffset = 0;
							b_ok = TRUE;
						}
						else if (!strcmp("y", mAccessor->mName))
						{
							mOffset = 4;
							b_ok = TRUE;
						}
						else if (!strcmp("z", mAccessor->mName))
						{
							mOffset = 8;
							b_ok = TRUE;
						}
					}
					else if (mIdentifier->mScopeEntry->mType == LST_QUATERNION)
					{
						if (!strcmp("x", mAccessor->mName))
						{
							mOffset = 0;
							b_ok = TRUE;
						}
						else if (!strcmp("y", mAccessor->mName))
						{
							mOffset = 4;
							b_ok = TRUE;
						}
						else if (!strcmp("z", mAccessor->mName))
						{
							mOffset = 8;
							b_ok = TRUE;
						}
						else if (!strcmp("s", mAccessor->mName))
						{
							mOffset = 12;
							b_ok = TRUE;
						}
					}
				}
				else
				{
					if (mIdentifier->mScopeEntry->mType == LST_VECTOR)
					{
						if (!strcmp("x", mAccessor->mName))
						{
							mOffset = 8;
							b_ok = TRUE;
						}
						else if (!strcmp("y", mAccessor->mName))
						{
							mOffset = 4;
							b_ok = TRUE;
						}
						else if (!strcmp("z", mAccessor->mName))
						{
							mOffset = 0;
							b_ok = TRUE;
						}
					}
					else if (mIdentifier->mScopeEntry->mType == LST_QUATERNION)
					{
						if (!strcmp("x", mAccessor->mName))
						{
							mOffset = 12;
							b_ok = TRUE;
						}
						else if (!strcmp("y", mAccessor->mName))
						{
							mOffset = 8;
							b_ok = TRUE;
						}
						else if (!strcmp("z", mAccessor->mName))
						{
							mOffset = 4;
							b_ok = TRUE;
						}
						else if (!strcmp("s", mAccessor->mName))
						{
							mOffset = 0;
							b_ok = TRUE;
						}
					}
				}
				if (b_ok)
				{
					mReturnType = type =  LST_FLOATINGPOINT;
				}
				else
				{
					gErrorToText.writeError(fp, this, LSERROR_VECTOR_METHOD_ERROR);
				}
			}
			else
			{
				mReturnType = type = mIdentifier->mScopeEntry->mType;
			}
		}
		else
		{
			mReturnType = type = LST_UNDEFINED;
		}
		break;
	default:
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptLValue::getSize()
{
	return 0;
}

void LLScriptAssignment::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_assignment(mLeftType, mRightType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType = mLeftType;
		}
		break;
	default:
		mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptAssignment::getSize()
{
	return 0;
}

void LLScriptAddAssignment::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptAddAssignment::getSize()
{
	return 0;
}

void LLScriptSubAssignment::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptSubAssignment::getSize()
{
	return 0;
}

void LLScriptMulAssignment::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType) /*|| !legal_assignment(mLValue->mReturnType, mReturnType)*/)
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptMulAssignment::getSize()
{
	return 0;
}

void LLScriptDivAssignment::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptDivAssignment::getSize()
{
	return 0;
}

void LLScriptModAssignment::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLValue->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptModAssignment::getSize()
{
	return 0;
}

void LLScriptEquality::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptEquality::getSize()
{
	return 0;
}

void LLScriptNotEquals::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptNotEquals::getSize()
{
	return 0;
}

void LLScriptLessEquals::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptLessEquals::getSize()
{
	return 0;
}

void LLScriptGreaterEquals::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptGreaterEquals::getSize()
{
	return 0;
}

void LLScriptLessThan::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptLessThan::getSize()
{
	return 0;
}

void LLScriptGreaterThan::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptGreaterThan::getSize()
{
	return 0;
}

void LLScriptPlus::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptPlus::getSize()
{
	return 0;
}

void LLScriptMinus::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptMinus::getSize()
{
	return 0;
}

void LLScriptTimes::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptTimes::getSize()
{
	return 0;
}

void LLScriptDivide::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptDivide::getSize()
{
	return 0;
}

void LLScriptMod::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptMod::getSize()
{
	return 0;
}

void LLScriptBitAnd::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBitAnd::getSize()
{
	return 0;
}

void LLScriptBitOr::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBitOr::getSize()
{
	return 0;
}

void LLScriptBitXor::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBitXor::getSize()
{
	return 0;
}

void LLScriptBooleanAnd::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBooleanAnd::getSize()
{
	return 0;
}

void LLScriptBooleanOr::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBooleanOr::getSize()
{
	return 0;
}

void LLScriptShiftLeft::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptShiftLeft::getSize()
{
	return 0;
}


void LLScriptShiftRight::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		{
			mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mLeftType = type;
			mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mRightType = type;
			if (!legal_binary_expression(mReturnType, mLeftType, mRightType, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			type = mReturnType;
		}
		break;
	default:
		mLeftSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightSide->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptShiftRight::getSize()
{
	return 0;
}

void LLScriptParenthesis::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mReturnType = mLeftType = type;
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptParenthesis::getSize()
{
	return 0;
}

void LLScriptUnaryMinus::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_unary_expression(type, type, mType))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		else
		{
			mReturnType = mLeftType = type;
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptUnaryMinus::getSize()
{
	return 0;
}

void LLScriptBooleanNot::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_unary_expression(type, type, mType))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		else
		{
			mReturnType = mLeftType = type;
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBooleanNot::getSize()
{
	return 0;
}

void LLScriptBitNot::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_unary_expression(type, type, mType))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		else
		{
			mReturnType = mLeftType = type;
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptBitNot::getSize()
{
	return 0;
}

void LLScriptPreIncrement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mExpression->mType != LET_LVALUE)
		{
			gErrorToText.writeError(fp, this, LSERROR_EXPRESSION_ON_LVALUE);
		}
		else
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!legal_unary_expression(type, type, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			else
			{
				mReturnType = mLeftType = type;
			}
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptPreIncrement::getSize()
{
	return 0;
}

void LLScriptPreDecrement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mExpression->mType != LET_LVALUE)
		{
			gErrorToText.writeError(fp, this, LSERROR_EXPRESSION_ON_LVALUE);
		}
		else
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!legal_unary_expression(type, type, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			else
			{
				mReturnType = mLeftType = type;
			}
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptPreDecrement::getSize()
{
	return 0;
}

void LLScriptTypeCast::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mRightType = type;
		if (!legal_casts(mType->mType, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		type = mType->mType;
		mReturnType = mLeftType = type;
		break;
	default:
		mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptTypeCast::getSize()
{
	return 0;
}

void LLScriptVectorInitializer::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		// vector's take floats
		mExpression1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mExpression2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mExpression3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mReturnType = type = LST_VECTOR;
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		mExpression1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptVectorInitializer::getSize()
{
	return 0;
}

void LLScriptQuaternionInitializer::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		// vector's take floats
		mExpression1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mExpression2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mExpression3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mExpression4->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!legal_assignment(LST_FLOATINGPOINT, type))
		{
			gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		mReturnType = type = LST_QUATERNION;
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		mExpression1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression3->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression4->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptQuaternionInitializer::getSize()
{
	return 0;
}

void LLScriptListInitializer::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mExpressionList)
		{
			mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mReturnType = type = LST_LIST;
		}
		mReturnType = type = LST_LIST;
		break;
	default:
		if (mExpressionList)
		{
			mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptListInitializer::getSize()
{
	return 0;
}

void LLScriptPostIncrement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mExpression->mType != LET_LVALUE)
		{
			gErrorToText.writeError(fp, this, LSERROR_EXPRESSION_ON_LVALUE);
		}
		else
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!legal_unary_expression(type, type, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			else
			{
				mReturnType = mLeftType = type;
			}
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptPostIncrement::getSize()
{
	return 0;
}

void LLScriptPostDecrement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		if (mExpression->mType != LET_LVALUE)
		{
			gErrorToText.writeError(fp, this, LSERROR_EXPRESSION_ON_LVALUE);
		}
		else
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!legal_unary_expression(type, type, mType))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			else
			{
				mReturnType = mLeftType = type;
			}
		}
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptPostDecrement::getSize()
{
	return 0;
}

// Generate arg list.
void LLScriptFunctionCall::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		if (mExpressionList)
			mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_SCOPE_PASS2:
		{
			LLScriptScopeEntry *entry = scope->findEntryTyped(mIdentifier->mName, LIT_FUNCTION);
			if (!entry)
			{
				gErrorToText.writeError(fp, this, LSERROR_UNDEFINED_NAME);
			}
			else
			{
				// if we did find it, make sure this identifier is associated with the correct scope entry
				mIdentifier->mScopeEntry = entry;
			}
			if (mExpressionList)
				mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	case LSCP_TYPE:
		if (mIdentifier->mScopeEntry)
		{
			U64 argcount = 0;
			if (mExpressionList)
				mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, argcount, chunk, heap, stacksize, mIdentifier->mScopeEntry, 0, NULL);

			if (!mIdentifier->mScopeEntry->mFunctionArgs.mString)
			{
				if (argcount)
				{
					gErrorToText.writeError(fp, this, LSERROR_FUNCTION_TYPE_ERROR);
				}
			}
			else if (argcount != strlen(mIdentifier->mScopeEntry->mFunctionArgs.mString))
			{
				gErrorToText.writeError(fp, this, LSERROR_FUNCTION_TYPE_ERROR);
			}
		}

		if (mIdentifier->mScopeEntry)
			type = mIdentifier->mScopeEntry->mType;
		else
			type = LST_NULL;
		mReturnType = type;
		break;
	default:
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mExpressionList)
			mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptFunctionCall::getSize()
{
	return 0;
}

void LLScriptPrint::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mLeftType = type;
		mReturnType = LST_NULL;
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptPrint::getSize()
{
	return 0;
}

void LLScriptConstantExpression::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_TYPE:
		mConstant->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mReturnType = type;
		break;
	default:
		mConstant->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptConstantExpression::getSize()
{
	return 0;
}

void LLScriptStatement::addStatement(LLScriptStatement *event)
{
	if (mNextp)
	{
		event->mNextp = mNextp;
	}
	mNextp = event;
}

void LLScriptStatement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	fprintf(fp, "Statement Base Class -- should never get here!\n");
}

S32 LLScriptStatement::getSize()
{
	printf("Statement Base Class -- should never get here!\n");
	return 0;
}

void LLScriptStatement::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptStatementSequence::getSize()
{
	return 0;
}

void LLScriptStatementSequence::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (prunearg)
		{
			// Dead code beyond a return is silently accepted -- no warning.
			// Set LSPRUNE_DEAD_CODE to suppress further prune checks inside
			// the dead block, and reset prunearg so the function-level
			// NO_RETURN check still works correctly.
			ptype = LSPRUNE_DEAD_CODE;
			prunearg = FALSE;
		}
		mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_TYPE:
		// pass the return type into all statements so we can check returns
		{
			LSCRIPTType	return_type = type;
			mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, return_type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			return_type = type;
			mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, return_type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		mFirstp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mSecondp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptNOOP::getSize()
{
	return 0;
}

void LLScriptNOOP::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	default:
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptStateChange::getSize()
{
	return 0;
}

void LLScriptStateChange::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		if (  (ptype == LSPRUNE_GLOBAL_VOIDS)
			||(ptype == LSPRUNE_GLOBAL_NON_VOIDS))
		{
			gErrorToText.writeError(fp, this, LSERROR_STATE_CHANGE_IN_GLOBAL);
		}
		prunearg = FALSE;
		break;
	case LSCP_SCOPE_PASS2:
		{
			LLScriptScopeEntry *entry = scope->findEntryTyped(mIdentifier->mName, LIT_STATE);
			if (!entry)
			{
				gErrorToText.writeError(fp, this, LSERROR_UNDEFINED_NAME);
			}
			else
			{
				// if we did find it, make sure this identifier is associated with the correct scope entry
				mIdentifier->mScopeEntry = entry;
			}
		}
		break;
	case LSCP_TYPE:
		mReturnType = basetype;
		break;
	default:
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptJump::getSize()
{
	return 0;
}

void LLScriptJump::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	case LSCP_SCOPE_PASS2:
		{
			LLScriptScopeEntry *entry = scope->findEntryTyped(mIdentifier->mName, LIT_LABEL);
			if (!entry)
			{
				gErrorToText.writeError(fp, this, LSERROR_UNDEFINED_NAME);
			}
			else
			{
				// if we did find it, make sure this identifier is associated with the correct scope entry
				mIdentifier->mScopeEntry = entry;
			}
		}
		break;
	default:
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptLabel::getSize()
{
	return 0;
}

void LLScriptLabel::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		// Always clear this flag, to stop pruning after return statements.  A jump
		// might start up code at this label, so we need to stop pruning.
		prunearg = FALSE;
		break;
	case LSCP_SCOPE_PASS1:
		// add labels to scope
		if (scope->checkEntry(mIdentifier->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_LABEL, LST_NULL);
		}
		break;
	default:
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptReturn::getSize()
{
	return 0;
}

void LLScriptReturn::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		if (  (ptype == LSPRUNE_GLOBAL_VOIDS)
			||(ptype == LSPRUNE_EVENTS))
		{
			if (mExpression)
			{
				gErrorToText.writeError(fp, this, LSERROR_INVALID_RETURN);
			}
		}
		else if (ptype == LSPRUNE_GLOBAL_NON_VOIDS)
		{
			if (!mExpression)
			{
				gErrorToText.writeError(fp, this, LSERROR_INVALID_VOID_RETURN);
			}
		}
		prunearg = TRUE;
	case LSCP_TYPE:
		// if there is a return expression, it must be promotable to the return type of the function
		if (mExpression)
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!legal_assignment(basetype, type))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
			else
			{
				mType = basetype;
			}
		}
		else if (basetype != LST_NULL)
		{
		        gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
		}
		break;
	default:
		if (mExpression)
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptExpressionStatement::getSize()
{
	return 0;
}

void LLScriptExpressionStatement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptIf::getSize()
{
	return 0;
}

void LLScriptIf::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (type == LST_NULL)
		{
			gErrorToText.writeError(fp, mExpression, LSERROR_TYPE_MISMATCH);
		}
		mType = type;
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptIfElse::getSize()
{
	return 0;
}

void LLScriptIfElse::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		{
			BOOL arg1 = TRUE, arg2 = TRUE;
			mStatement1->recurse(fp, tabs, tabsize, pass, ptype, arg1, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mStatement2->recurse(fp, tabs, tabsize, pass, ptype, arg2, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			prunearg = arg1 && arg2;
		}
		break;
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (type == LST_NULL)
		{
			gErrorToText.writeError(fp, mExpression, LSERROR_TYPE_MISMATCH);
		}
		mType = type;
		mStatement1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStatement2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStatement1->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStatement2->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	};
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptFor::getSize()
{
	return 0;
}

void LLScriptFor::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	case LSCP_TYPE:
		if(mSequence)
			mSequence->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (type == LST_NULL)
		{
			gErrorToText.writeError(fp, mExpression, LSERROR_TYPE_MISMATCH);
		}
		mType = type;
		if(mExpressionList)
			mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if(mStatement)
			mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	default:
		if(mSequence)
			mSequence->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if(mExpressionList)
			mExpressionList->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if(mStatement)
			mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptDoWhile::getSize()
{
	return 0;
}

void LLScriptDoWhile::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	case LSCP_TYPE:
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (type == LST_NULL)
		{
			gErrorToText.writeError(fp, mExpression, LSERROR_TYPE_MISMATCH);
		}
		mType = type;
		break;
	default:
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptWhile::getSize()
{
	return 0;
}

void LLScriptWhile::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	case LSCP_TYPE:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (type == LST_NULL)
		{
			gErrorToText.writeError(fp, mExpression, LSERROR_TYPE_MISMATCH);
		}
		mType = type;
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	default:
		mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptDeclaration::getSize()
{
	return mType->getSize();
}

void LLScriptDeclaration::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		prunearg = FALSE;
		break;
	case LSCP_SCOPE_PASS1:
		// Check to see if a declaration is valid here.
		if (!mAllowDeclarations)
		{
			gErrorToText.writeError(fp, this, LSERROR_NEED_NEW_SCOPE);
		}
		// add labels to scope
		else if (scope->checkEntry(mIdentifier->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			if (mExpression)
			{
				mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			}
			// this needs to go after expression decent to make sure that we don't add ourselves or something silly
			// check expression if it exists
			mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_VARIABLE, mType->mType);
		}
		break;
	case LSCP_TYPE:
		// if there is an expression, it must be promotable to variable type
		if (mExpression && mIdentifier->mScopeEntry)
		{
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!legal_assignment(mIdentifier->mScopeEntry->mType, type))
			{
				gErrorToText.writeError(fp, this, LSERROR_TYPE_MISMATCH);
			}
		}
		break;
	default:
		if (mExpression)
		{
			mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mExpression->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		else
		{
			mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

S32 LLScriptCompoundStatement::getSize()
{
	return 0;
}

void LLScriptCompoundStatement::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		if (mStatement)
		{
			mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		else
		{
			prunearg = FALSE;
		}
		break;
	case LSCP_SCOPE_PASS1:
		// compound statements create a new scope
		if (mStatement)
		{
			mStatementScope = new LLScriptScope(gScopeStringTable);
			mStatementScope->addParentScope(scope);
			mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mStatementScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	case LSCP_SCOPE_PASS2:
		// compound statements create a new scope
		if (mStatement)
		{
			mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mStatementScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		if (mStatement)
		{
			mStatement->recurse(fp, tabs + 1, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

void LLScriptEventHandler::addEvent(LLScriptEventHandler *event)
{
	if (mNextp)
	{
		event->mNextp = mNextp;
	}
	mNextp = event;
}

void LLScriptEventHandler::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptEventHandler::getSize()
{
	return mStackSpace;
}

U64 gCurrentHandler = 0;

void LLScriptEventHandler::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		mbNeedTrailingReturn = FALSE;
		prunearg = TRUE;
		mStatement->recurse(fp, tabs, tabsize, pass, LSPRUNE_EVENTS, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (!prunearg)
		{
			// this means that we didn't end with a return statement, need to add one
			mbNeedTrailingReturn = TRUE;
		}
		break;
	case LSCP_SCOPE_PASS1:
		// create event level scope
		mEventScope = new LLScriptScope(gScopeStringTable);
		mEventScope->addParentScope(scope);

		// add event parameters
		mEventp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mEventScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);

		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mEventScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_SCOPE_PASS2:
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mEventScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_TYPE:
		mScopeEntry = new LLScriptScopeEntry("Event", LIT_HANDLER, LST_NULL);
		switch(mEventp->mType)
		{
		case LSTT_STATE_ENTRY:
			break;
		case LSTT_STATE_EXIT:
			break;
		case LSTT_TOUCH_START:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_TOUCH:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_TOUCH_END:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_COLLISION_START:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_COLLISION:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_COLLISION_END:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_LAND_COLLISION_START:
			mScopeEntry->mFunctionArgs.addType(LST_VECTOR);
			break;
		case LSTT_LAND_COLLISION:
			mScopeEntry->mFunctionArgs.addType(LST_VECTOR);
			break;
		case LSTT_LAND_COLLISION_END:
			mScopeEntry->mFunctionArgs.addType(LST_VECTOR);
			break;
		case LSTT_INVENTORY:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_ATTACH:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			break;
		case LSTT_DATASERVER:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			break;
		case LSTT_TIMER:
			break;
		case LSTT_MOVING_START:
			break;
		case LSTT_MOVING_END:
			break;
		case LSTT_OBJECT_REZ:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			break;
		case LSTT_REMOTE_DATA:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			break;
		case LSTT_CHAT:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			break;
		case LSTT_SENSOR:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_CONTROL:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_LINK_MESSAGE:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			break;
		case LSTT_MONEY:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_EMAIL:
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_REZ:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_NO_SENSOR:
			break;
		case LSTT_AT_TARGET:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_VECTOR);
			mScopeEntry->mFunctionArgs.addType(LST_VECTOR);
			break;
		case LSTT_NOT_AT_TARGET:
			break;
		case LSTT_AT_ROT_TARGET:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_QUATERNION);
			mScopeEntry->mFunctionArgs.addType(LST_QUATERNION);
			break;
		case LSTT_NOT_AT_ROT_TARGET:
			break;
		case LSTT_RTPERMISSIONS:
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			break;
		case LSTT_HTTP_RESPONSE:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_INTEGER);
			mScopeEntry->mFunctionArgs.addType(LST_LIST);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			break;
		case LSTT_HTTP_REQUEST:
			mScopeEntry->mFunctionArgs.addType(LST_KEY);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			mScopeEntry->mFunctionArgs.addType(LST_STRING);
			break;

		default:
			break;
		}
		mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	default:
		mEventp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mStatement)
		{
			mStatement->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

void LLScriptFunctionDec::addFunctionParameter(LLScriptFunctionDec *dec)
{
	if (mNextp)
	{
		dec->mNextp = mNextp;
	}
	mNextp = dec;
}

void LLScriptFunctionDec::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}

}

S32 LLScriptFunctionDec::getSize()
{
	return 0;
}

void LLScriptFunctionDec::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		// add function names into global scope
		if (scope->checkEntry(mIdentifier->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_VARIABLE, mType->mType);
		}
		break;
	case LSCP_BUILD_FUNCTION_ARGS:
		{
			entry->mFunctionArgs.addType(mType->mType);
		}
		break;
	default:
		mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

void LLScriptGlobalFunctions::addGlobalFunction(LLScriptGlobalFunctions *global)
{
	if (mNextp)
	{
		global->mNextp = mNextp;
	}
	mNextp = global;
}

void LLScriptGlobalFunctions::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptGlobalFunctions::getSize()
{
	return 0;
}

void LLScriptGlobalFunctions::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		mbNeedTrailingReturn = FALSE;
		if (mType)
		{
			prunearg = TRUE;
			mStatements->recurse(fp, tabs, tabsize, pass, LSPRUNE_GLOBAL_NON_VOIDS, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!prunearg)
			{
				gErrorToText.writeError(fp, this, LSERROR_NO_RETURN);
			}
		}
		else
		{
			prunearg = TRUE;
			mStatements->recurse(fp, tabs, tabsize, pass, LSPRUNE_GLOBAL_VOIDS, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			if (!prunearg)
			{
				// this means that we didn't end with a return statement, need to add one
				mbNeedTrailingReturn = TRUE;
			}
		}
		break;
	case LSCP_SCOPE_PASS1:
		// add function names into global scope
		if (scope->checkEntry(mIdentifier->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			if (mType)
			{
				mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_FUNCTION, mType->mType);
			}
			else
			{
				mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_FUNCTION, LST_NULL);
			}
		}

		// create function level scope
		mFunctionScope = new LLScriptScope(gScopeStringTable);
		mFunctionScope->addParentScope(scope);

		// function parameters
		if (mParameters)
		{
			mParameters->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mFunctionScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}

		mStatements->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mFunctionScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_SCOPE_PASS2:
		mStatements->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mFunctionScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);

		if (mParameters)
		{
			if (mIdentifier->mScopeEntry)
			{
				mParameters->recurse(fp, tabs, tabsize, LSCP_BUILD_FUNCTION_ARGS, ptype, prunearg, mFunctionScope, type, basetype, count, chunk, heap, stacksize, mIdentifier->mScopeEntry, 0, NULL);
			}
		}
		break;
	case LSCP_TYPE:
		if (mType)
		{
			mStatements->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, mType->mType, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		else
		{
			type = LST_NULL;
			mStatements->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		if (mType)
		{
			mType->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mParameters)
		{
			mParameters->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		if (mStatements)
		{
			mStatements->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

void LLScriptState::addState(LLScriptState *state)
{
	if (mNextp)
	{
		state->mNextp = mNextp;
	}
	mNextp = state;
}

void LLScriptState::gonext(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	default:
		if (mNextp)
		{
			mNextp->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
}

S32 LLScriptState::getSize()
{
	return 0;
}

void LLScriptState::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_SCOPE_PASS1:
		// add state name
		if (scope->checkEntry(mIdentifier->mName))
		{
			gErrorToText.writeError(fp, this, LSERROR_DUPLICATE_NAME);
		}
		else
		{
			mIdentifier->mScopeEntry = scope->addEntry(mIdentifier->mName, LIT_STATE, LST_NULL);
		}
		mStateScope = new LLScriptScope(gScopeStringTable);
		mStateScope->addParentScope(scope);
		// now do the events
		if (mEvent)
		{
			mEvent->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mStateScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	case LSCP_SCOPE_PASS2:
		if (mEvent)
		{
			mEvent->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	case LSCP_TYPE:
		if (mEvent)
		{
			mEvent->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	default:
		if (mType == LSSTYPE_DEFAULT)
		{
		}
		else
		{
			mIdentifier->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		if (mEvent)
		{
			mEvent->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		break;
	}
	gonext(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
}

// Converts string to a valid CIL class name and stores the result
// in the supplied buffer, which should be at least 32 chars long.
// If the string starts with a UUID, all characters in the UUID are included
// in the generated name.
S32 LLScriptScript::getSize()
{
	return 0;
}

LLScriptScript::LLScriptScript(LLScritpGlobalStorage *globals,
							   LLScriptState *states) :
    LLScriptFilePosition(0, 0),
	mStates(states), mGlobalScope(NULL), mGlobals(NULL), mGlobalFunctions(NULL), mGodLike(FALSE)
{
	const char DEFAULT_BYTECODE_FILENAME[] = "lscript.lso";

	mBytecodeDest = DEFAULT_BYTECODE_FILENAME;
	LLScriptGlobalVariable	*tvar;
	LLScriptGlobalFunctions	*tfunc;
	LLScritpGlobalStorage *temp;

	temp = globals;
	while(temp)
	{
		if (temp->mbGlobalFunction)
		{
			if (!mGlobalFunctions)
			{
				mGlobalFunctions = (LLScriptGlobalFunctions *)temp->mGlobal;
			}
			else
			{
				tfunc = mGlobalFunctions;
				while(tfunc->mNextp)
				{
					tfunc = tfunc->mNextp;
				}
				tfunc->mNextp = (LLScriptGlobalFunctions *)temp->mGlobal;
			}
		}
		else
		{
			if (!mGlobals)
			{
				mGlobals = (LLScriptGlobalVariable *)temp->mGlobal;
			}
			else
			{
				tvar = mGlobals;
				while(tvar->mNextp)
				{
					tvar = tvar->mNextp;
				}
				tvar->mNextp = (LLScriptGlobalVariable *)temp->mGlobal;
			}
		}
		temp = temp->mNextp;
	}

	mClassName[0] = '\0';
}

void LLScriptScript::recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype, BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count, LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize, LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata)
{
	if (gErrorToText.getErrors())
	{
		return;
	}
	switch(pass)
	{
	case LSCP_PRUNE:
		if (mGlobalFunctions)
		{
			mGlobalFunctions->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		}
		mStates->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_SCOPE_PASS1:
		{
			mGlobalScope = new LLScriptScope(gScopeStringTable);
			// zeroth, add library functions to global scope
			U16 function_index = 0;
			const char *arg;
			LLScriptScopeEntry *sentry;
			for (std::vector<LLScriptLibraryFunction>::const_iterator i = gScriptLibrary.mFunctions.begin();
				 i != gScriptLibrary.mFunctions.end(); ++i)
			{
				// First, check to make sure this isn't a god only function, or that the viewer's agent is a god.
				if (!i->mGodOnly || mGodLike)
				{
					if (i->mReturnType)
						sentry = mGlobalScope->addEntry(i->mName, LIT_LIBRARY_FUNCTION, char2type(*i->mReturnType));
					else
						sentry = mGlobalScope->addEntry(i->mName, LIT_LIBRARY_FUNCTION, LST_NULL);
					sentry->mLibraryNumber = function_index;
					arg = i->mArgs;
					if (arg)
					{
						while (*arg)
						{
							sentry->mFunctionArgs.addType(char2type(*arg));
							sentry->mSize += LSCRIPTDataSize[char2type(*arg)];
							sentry->mOffset += LSCRIPTDataSize[char2type(*arg)];
							arg++;
						}
					}
				}
				function_index++;
			}
			// first go and collect all the global variables
			if (mGlobals)
				mGlobals->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mGlobalScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			// second, do the global functions
			if (mGlobalFunctions)
				mGlobalFunctions->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mGlobalScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			// now do states
			mStates->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mGlobalScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
			break;
		}
	case LSCP_SCOPE_PASS2:
		// now we're checking jumps, function calls, and state transitions
		if (mGlobalFunctions)
			mGlobalFunctions->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mGlobalScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStates->recurse(fp, tabs, tabsize, pass, ptype, prunearg, mGlobalScope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	case LSCP_TYPE:
		// first we need to check global variables
		if (mGlobals)
			mGlobals->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		// now do global functions and states
		if (mGlobalFunctions)
			mGlobalFunctions->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStates->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	default:
		if (mGlobals)
			mGlobals->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		if (mGlobalFunctions)
			mGlobalFunctions->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		mStates->recurse(fp, tabs, tabsize, pass, ptype, prunearg, scope, type, basetype, count, chunk, heap, stacksize, entry, entrycount, NULL);
		break;
	}
}
