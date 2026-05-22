// EXPECT ERROR: Name previously declared within scope
// Declaring the same variable name twice in the same block scope triggers
// LSERROR_DUPLICATE_NAME in LLScriptDeclaration::recurse
// (lscript_tree.cpp near line 7928) during LSCP_SCOPE_PASS1.
default
{
    state_entry()
    {
        integer x = 1;
        integer x = 2;
    }
}
