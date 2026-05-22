// EXPECT ERROR: Declaration requires a new scope -- use { and }
// Declaring a variable as the sole (braceless) body of an if statement
// triggers LSERROR_NEED_NEW_SCOPE in LLScriptDeclaration::recurse
// (lscript_tree.cpp near line 7923) during LSCP_SCOPE_PASS1.
// mAllowDeclarations is FALSE when there is no enclosing compound statement.
default
{
    state_entry()
    {
        if (TRUE)
            integer x = 1;
    }
}
