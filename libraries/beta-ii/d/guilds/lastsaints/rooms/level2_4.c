#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Last Saints");
    set("long","%^%^BOLD%^%^WHITE%^This room is full of open windows allowing the sky to shine through. Marble columns line the wall opposite the windows allowing the light, whether night or day, to shine upon them.%^RESET%^\n");
    set_exits( ([ "northwest" : GUILDROOM+"last_saints_board" ]) );
}
void reset() {
    ::reset();
    if(!present("pool"))
        new("/d/guilds/common/obj/scry_pool.c")->move(this_object());
}
void init() {
    ::init();
    //add_action("view", "find");
}
int view(string str) {
    mixed strr;
    object env;
    if(!str || str == "")
	return notify_fail("Find who?");
    strr = find_player(str);
    if(!find_player(str) && !interactive(strr))
	return notify_fail("Cannot find "+capitalize(str)+".\n");
    if(wizardp(strr)) 
        return notify_fail("Cannot find "+capitalize(str)+".\n");
    env = environment(strr);
    if(env->query_property("no scry") || wizardp(strr))
	return notify_fail("The fountain reveals nothing.\n");
    write("The fountain reveals nothing.\n");
    return 1;
}
