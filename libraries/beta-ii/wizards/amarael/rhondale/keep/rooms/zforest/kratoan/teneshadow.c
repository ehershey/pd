#include <std.h>
#include <aziraphale.h>
#include <shadow.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": -1, "night light" : -2, "indoors" : 0]));
     set_short("House of Shadow");
     set_long("%^BOLD%^BLACK%^It is far too dark to see anything in great detail, the light just seems to be being sucked out of the room. The best that can be made out in the darkness is that there are four walls, a floor and a roof.%^RESET%^");
     set_exits(([
                "up"             : KEEPROOM"zforest/kratoan/tenehouse.c"
                ]));
     set_items(([
		]));
}

void init() {
   ::init();
     add_action("leave", "up");
     if(!present("worthmark", this_player()) && !present("demon", this_object()) && member_array("kratoan", this_player()->query_quests()) == -1)
     new(KEEPMOB"zforest/kratoan/tenedemon.c")->move(this_object());
}

int leave() {
    object env;
    message("info", "The trapdoor swings open at the lightest touch, and closes behind you.", this_player(), );
    env = find_object(KEEPROOM"zforest/kratoan/tenehouse.c");
    if(env)
    message("info", "The trapdoor swings open for a moment as "+this_player()->query_cap_name()+" exits the basement.", env, );
    return 0;
}
