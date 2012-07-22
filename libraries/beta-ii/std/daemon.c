// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam    (91-01-19)
// Modifed by Buddha   (92-02-18)
// Updated by Pallando (93-05-25)
// Updated by Inferno  (00-05-14)

static private int no_clean;

void set_no_clean(int x);
// Clear unused command objects from memory.
void clean_up() { if (!no_clean) destruct( this_object() ); }

// Prevent shadowing of commands.
int query_prevent_shadow() { return 1; }

// Needed for commands that read, write or load files.
void create() { seteuid( getuid() ); }

void set_no_clean(int x) { no_clean = x; }
int query_no_clean() { return no_clean; }
