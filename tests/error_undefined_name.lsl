// EXPECT ERROR: Name not defined within scope
// Referencing a variable that was never declared triggers
// LSERROR_UNDEFINED_NAME in LLScriptLValue::recurse
// (lscript_tree.cpp near line 412 area) during LSCP_SCOPE_PASS2.
default
{
    state_entry()
    {
        integer y = undeclaredVar;
    }
}
