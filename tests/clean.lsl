// EXPECT CLEAN
// A syntactically and semantically correct script: no errors, no warnings.
// Used to confirm the compiler accepts valid scripts without complaint.
integer add(integer a, integer b)
{
    return a + b;
}

default
{
    state_entry()
    {
        integer result = add(3, 4);
    }
}
