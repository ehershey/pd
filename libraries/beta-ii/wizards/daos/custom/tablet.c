#include <std.h>

inherit OBJECT;

mapping all_names;

void create() {
    ::create();
    set_id( ({ "tablet", "obsidian tablet" }) );
    set_name("tablet");
    set_short("%^BOLD%^BLACK%^Obsidian Tablet%^RESET%^");
    set_long("%^BOLD%^BLACK%^The glassy black surface of the tablet has names etched into it.\nThey read as follows:%^RESET%^");
    set_weight(0);
    set_value(0);
}

void init() {
    ::init();
    add_action("add_name", "add");
    add_action("remove_name", "remove");
}

int add_name(string str) {
    string rlname, charname;

    if(!str || str == "" || sscanf(str, "name %s character %s", rlname, charname) != 2)
	return notify_fail("Syntax is: <add name [real name] character [character name]>.\n");

    if(!all_names)
	all_names = ([ ]);

    rlname = lower_case(rlname);
    charname = lower_case(charname);

    if(!all_names[rlname])
	all_names[rlname] = ({ charname });
    else if(member_array(charname, all_names[rlname]) != -1)
	return notify_fail("'"+capitalize(charname)+"' is already in "+capitalize(rlname)+"'s list of alts.\n");
    else
	all_names[rlname] += ({ charname });

    write(capitalize(rlname)+" has '"+capitalize(charname)+"' added to his list of alts.");
    return 1;
}

int remove_name(string str) {
    string rlname, charname;

    if(!all_names)
	return notify_fail("No list of names to edit.\n");

    if(!str || str == "" || sscanf(str, "name %s character %s", rlname, charname) != 2 )
	return notify_fail("Syntax is: <remove name [real name] character [character name]>.\n");

    rlname = lower_case(rlname);
    charname = lower_case(charname);

    if(!all_names[rlname])
	return notify_fail("There is no such name in the list.\n");

    if(member_array(charname, all_names[rlname]) == -1)
	return notify_fail("'"+capitalize(charname)+"' is not in "+capitalize(rlname)+"'s list of alts.\n");

    all_names[rlname] -= ({ charname });

    write("'"+capitalize(charname)+"' removed from "+capitalize(rlname)+"'s list of alts.");
    if(!sizeof(all_names[rlname])) {
	map_delete(all_names, rlname);
	write(capitalize(rlname)+" has no more entries, and is removed.");
    }
    return 1;
}

string query_long() {
    string desc, tmp, *rlnames, *charnames;
    int i, x;

    if(!all_names)
	return ::query_long();

    desc = ::query_long()+"\n";
    rlnames = keys(all_names);
    i = sizeof(rlnames);

    while(i--) {
	charnames = all_names[rlnames[i]];
	tmp = "%^BOLD%^GREEN%^"+arrange_string(capitalize(rlnames[i]), 10)+"%^RESET%^";

	x = sizeof(charnames);

	while(x--) {
	    if(!x)
		tmp = tmp + ("%^GREEN%^"+capitalize(charnames[x])+"%^RESET%^.");
	    else
		tmp = tmp + ("%^GREEN%^"+capitalize(charnames[x])+"%^RESET%^, ");
	}
	desc = desc + tmp + "\n";
    }
    return desc;
}

mixed *query_auto_load() {
    if (this_player()->query_name() == "scourge")
	return ({ "/wizards/daos/custom/tablet.c", all_names });
    else
	return 0;
}


void init_arg(mapping stuff) {
    all_names = stuff;
}

int give() { return 1; }
int drop() { return 1; }
