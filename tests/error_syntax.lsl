// EXPECT ERROR: Syntax error
// Missing semicolon after the assignment triggers LSERROR_SYNTAX_ERROR
// from yyerror() in indra.l.in:234.
default
{
    state_entry()
    {
        integer x = 5
    }
}
