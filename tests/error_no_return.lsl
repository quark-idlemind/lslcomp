// EXPECT ERROR: Not all code paths return a value
// A non-void function whose if-without-else branch may not execute
// triggers LSERROR_NO_RETURN in LLScriptGlobalFunctions::recurse
// (lscript_tree.cpp near line 8595) during LSCP_PRUNE.
// LLScriptIf::recurse sets prunearg=FALSE unconditionally in LSCP_PRUNE,
// so the function body is never guaranteed to return.
integer mayReturn(integer cond)
{
    if (cond)
    {
        return 1;
    }
}

default
{
    state_entry() {}
}
