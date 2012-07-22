#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":2, "indoors":1]));
set_name("Illuminati Scry Room");
set_short("Illuminati Scry Room");
set_long("%^RESET%^%^ORANGE%^A large square of glass is set into the west wall of this room. The "
"Illuminati use it to find people that are particularly difficult to track.");
set_exits(([
"east"          : ROOMS"illuminati/new/floor3.c"
]));
}


void reset() {
::reset();
if(!present("glass"))
{new(ROOMS"illuminati/new/glass.c")->move(this_object());}
}

void init() {
    ::init();
add_action("view", "find");
}
int view(string str) {
mixed strr;
    object env;
    if(!str) return notify_fail("Find who?\n");
    if(!find_player(str)) return notify_fail("That person does not exist..\n");
    strr = find_player(str);
    env = environment(strr);
    if(env->query_property("no scry") || env->query_property("no teleport"))
        return notify_fail("The glass reveals nothing.\n");
    if(wizardp(strr)) { notify_fail("Immortals and Admins cannot be found.\n");
        return 0;
    }
write("%^BOLD%^%^WHITE%^The glass reveals "+capitalize(str)+" is in "+env->query_short()+"%^RESET%^\n");
    return 1;
}
