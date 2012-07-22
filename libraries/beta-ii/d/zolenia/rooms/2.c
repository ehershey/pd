#include <std.h>
#include <zolenia.h>
inherit ROOM;

void hurt_player();

void create() {
    ::create();
    set_properties( ([ "light" : 4, "night light" : 4, "indoors" : 1]) );
    set_smell("default", "A strong, earthy smell fills the air");
    set_listen("default", "Small rocks can be heard falling toward the ground.");
    set_short("climbing down the rocky slope");
    set_long("Although the fall from above was quite far, the cliffs still go farther than you can see.  The standing point above can't quite be seen, and there doesn't appear to be a way to get back up.  Perhaps a few more jumps down will resolve in solid ground.");
    set_items(([
	({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
      ]));
    set_exits(([ "down" : ROOMS "3.c"]));
    add_post_exit_function("down", "hurt_player");
}
void reset() {
    ::reset();
    if(!present("burningrat"))
    {
	new(MOB"burningrat")->move(this_object());
	new(MOB"burningrat")->move(this_object());
    }
    if(!present("laughingrat"))
    {
	new(MOB"laughingrat")->move(this_object());
	new(MOB"laughingrat")->move(this_object());
    }
}
void hurt_player() {
	object tp = this_player();
	message("info",
	  "%^BOLD%^%^RED%^You fall to the ground quite painfully.. the jump was higher than it looked.%^RESET%^",
	  tp);
	message("info",
	  tp->query_cap_name()+" falls from above, landing with a loud thud.",
	  environment(tp), tp);
	tp->do_damage("torso", 50+random(150));
}
