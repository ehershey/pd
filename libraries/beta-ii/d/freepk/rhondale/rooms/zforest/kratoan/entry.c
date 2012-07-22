#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1]));
     set_short("Kra'Toa'Kathor");
     set_long("The trees here a very densely packed with just a small clearing where there is merely grass. Almost no light breaches the forest canopy a hundred metres or more in the air. Directly to the east of this space stands are large stone monolith, with paths going around it.");
     set_exits(([
                "west"                  : KEEPROOM"zforest/x12y31.c",
		"northeast"		: KEEPROOM"zforest/kratoan/pathne.c",
		"southeast"		: KEEPROOM"zforest/kratoan/pathse.c"
                ]));
     set_items(([
		"monolith"	: "The monolith has had something carved into the surface, perhaps you should read it."
		]));
     set_pre_exit_functions( ({"northeast", "southeast"}), ({"block_me", "block_me"}) );

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
	}
}

void init() {
   ::init();
	add_action("readin", "read");
}

int readin(string str) {
	if(str != "monolith") return 0;
	message("read", "\n\n%^BOLD%^WHITE%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n\n                   %^RESET%^Kra'Toa'Kathor - Home of the Lizard Heart.\n\nOur land is sacred to us. If you wish to enter, you must prove yourself worthy.\n\n\n               %^ORANGE%^'The stone of the golden sun shall show the way,\n                without it death is the price you must pay.'\n\n               'In the land of shadows there lies a ring,\n                bring it here to pass within.'\n\n\n%^BOLD%^WHITE%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^RESET%^\n", this_player(), );
	message("read", this_player()->query_cap_name()+" reads the writing on the monolith.", this_object(), this_player());
	return 1;
}

int block_me() {
    object sentry, tp, ring;
    tp = this_player();
    if(present("worthmark", tp)) return 1;
    if(sentry = present("sentry")) {
      if(ring = present("kratoanring", tp)) {
	new(KEEPARMOUR"/zforest/kratoan/worthmark.c")->move(tp);
	// add a deed to char
	return 1;
	}
      sentry->force_me("say Only those who are proven shall enter.");
      return 0;
      }
}
