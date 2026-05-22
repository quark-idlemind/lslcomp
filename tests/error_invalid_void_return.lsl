// EXPECT ERROR: Function returns a value but return statement doesn't
// A non-void function (return type integer) with a bare "return;" (no value)
// triggers LSERROR_INVALID_VOID_RETURN in LLScriptReturn::recurse
// (lscript_tree.cpp near line 7380) during LSCP_PRUNE.
// ptype == LSPRUNE_GLOBAL_NON_VOIDS and mExpression == NULL.
integer emptyReturn()
{
    return;
}

default
{
    state_entry() {}
}
