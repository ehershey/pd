#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":2, "indoors":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^ORANGE%^This room is completely bare, with nothing at all on the floor or ceiling, or three of the walls. The fourth wall is completely covered with a huge glass wall.%^RESET%^");
     set_exits(([
		"east"          : ILROOM"floor3.c"
		]));
}


void reset() {
   ::reset();
     if(!present("glass"))
       new(ILOBJ"glass.c")->move(this_object());
}

void init() {
   ::init();
     add_action("view", "find");
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

int view(string str) {
    mixed strr;
    object env;
    if(!str || str == "")
      return notify_fail("Find who?");
    if(!find_player(str))
      return notify_fail("Cannot find "+capitalize(str)+".\n");
    strr = find_player(str);
    env = environment(strr);
    if(env->query_property("no scry") || wizardp(strr))
      return notify_fail("The glass reveals nothing.\n");
    write("\nThe glass reveals nothing.\n");
    return 1;
}
