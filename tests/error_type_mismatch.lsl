// EXPECT ERROR: Type mismatch
// Assigning a string literal to an integer variable triggers
// LSERROR_TYPE_MISMATCH in LLScriptDeclaration::recurse
// (lscript_tree.cpp near line 7948) during LSCP_TYPE.
// legal_assignment(LST_INTEGER, LST_STRING) returns FALSE.
default
{
    state_entry()
    {
        integer x = "hello";
    }
}
