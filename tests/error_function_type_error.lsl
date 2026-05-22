// EXPECT ERROR: Function call mismatches type or number of arguments
// Calling a function with more arguments than it declares triggers
// LSERROR_FUNCTION_TYPE_ERROR in LLScriptFunctionCall::recurse
// (lscript_tree.cpp near line 6859) during LSCP_TYPE.
// argcount (3) != strlen(mFunctionArgs.mString) (2).
integer add(integer a, integer b)
{
    return a + b;
}

default
{
    state_entry()
    {
        integer result = add(1, 2, 3);
    }
}
