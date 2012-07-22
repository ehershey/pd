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
    set_long("The hole leads you through a very narrow tunnel, ending at a large %^BOLD%^%^BLACK%^onyx%^RESET%^ flat top to a very steep cliff.  Although scary, it definitely looks scalable, and there's even a large rock not too far which looks like it can be jumped to.");
    set_items(([
	({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
      ]));
    set_exits(([ "down" : ROOMS "2.c"]));
	add_post_exit_function("down", "hurt_player");
}
void reset() {
    ::reset();
    if(!present("angryspider"))
    {
	new(MOB"angryspider")->move(this_object());
	new(MOB"angryspider")->move(this_object());
    }
    if(!present("sneakyspider"))
    {
	new(MOB"sneakyspider")->move(this_object());
	new(MOB"sneakyspider")->move(this_object());
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
	tp->do_damage("torso", 50+random(200));
}
