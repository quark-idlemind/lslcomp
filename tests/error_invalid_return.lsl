// EXPECT ERROR: Return statement type doesn't match function return type
// A void function (no return type) containing "return value;" triggers
// LSERROR_INVALID_RETURN in LLScriptReturn::recurse
// (lscript_tree.cpp near line 7373) during LSCP_PRUNE.
// ptype == LSPRUNE_GLOBAL_VOIDS and mExpression != NULL.
voidFunc()
{
    return 1;
}

default
{
    state_entry() {}
}
