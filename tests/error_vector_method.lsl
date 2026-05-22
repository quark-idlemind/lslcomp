// EXPECT ERROR: Use of vector or quaternion method on incorrect type
// Accessing component .x on a variable whose type is integer (not vector
// or quaternion) triggers LSERROR_VECTOR_METHOD_ERROR in
// LLScriptLValue::recurse (lscript_tree.cpp near line 4148) during
// LSCP_TYPE.  The accessor lookup sets b_ok=FALSE for non-vector types.
default
{
    state_entry()
    {
        integer n = 5;
        float f = n.x;
    }
}
