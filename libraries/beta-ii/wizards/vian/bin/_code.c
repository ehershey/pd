#include <std.h>

inherit DAEMON;

int cmd_code() {

    object *ob;
    object tp = this_player();

    ob = users();

    for (int i=0; i<sizeof(ob); i++) {
	if (wizardp(ob[i]) || archp(ob[i])) {
	    if (in_edit(ob[i])) {
		message("info", ob[i]->query_cap_name()+ " " + 
		  in_edit(ob[i]), tp);
	    }
	}
    }
    return 1;
}
