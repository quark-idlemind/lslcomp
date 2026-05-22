// EXPECT ERROR: Global functions can't change state
// A user-defined global function that contains "state <name>;" triggers
// LSERROR_STATE_CHANGE_IN_GLOBAL in LLScriptStateChange::recurse
// (lscript_tree.cpp near line 7182) during LSCP_PRUNE.
// ptype == LSPRUNE_GLOBAL_VOIDS at that point.
doStateChange()
{
    state default;
}

default
{
    state_entry() {}
}
