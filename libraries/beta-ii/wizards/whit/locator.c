//  Object Locator

#include <std.h>

inherit OBJECT;
mapping dat;
void create() {
    ::create();
    set_name("object locator");
    set_short("object locator");
    set_id(({ "locator" }));
    set_long("This is an object locator.  You program it and it saves the filenames "
      "of certain weapons/objects/rooms.  Made for use by Whit only.\n\n"
      "<program [name]:[file]> : Programs a file.\n"
      "<delete [name]> : Deletes a program entry.\n"
      "<view [{name}/all]> : Displays a list of entrys."
    );
    dat=([]);
    restore_object("/wizards/whit/locations");
}

void init() {
    ::init();
    add_action("program", "program");
    add_action("delete", "delete");
    add_action("view", "view");
}

int program(string s) {
    string f, n;
    if(!s || s=="") return notify_fail("Syntax: <program [name]:[file]>\n");
    if(sscanf(s, "%s:%s", n, f)!=2) return notify_fail("Syntax: <program [name]:[file]>\n");
    dat[n]=f;
    save_object("/wizards/whit/locations");
    write("Done.");
    return 1;
}

int delete(string s) {
    if(!s || s=="") return notify_fail("Syntax: <program [name]:[file]>\n");
    if(!dat[s]) return notify_fail("No such record.\n");
    map_delete(dat, s);
    save_object("/wizards/whit/locations");
    write("Record deleted.");
    return 1;
}

int view(string s) {
    int i, x;
    if(!s || s=="") return notify_fail("Syntax: <program [name]:[file]>\n");
    if(s=="all") {
	i=sizeof(keys(dat));
	while(i--) 
	    if(file_exists(keys(dat)[i]) || file_exists( keys(dat)[i]+".c" )) x++;
	write(format_page(keys(dat))+"\n"+sizeof(keys(dat))+" entrys.  "+x+" entrys exist.\n");
	return 1;
    }
    if(!dat[s]) return notify_fail("No such record.\n");
    write(s+" : "+dat[s]);
    return 1;
}

