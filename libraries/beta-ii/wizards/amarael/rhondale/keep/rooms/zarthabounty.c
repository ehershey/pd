#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1]));
     set_name("Zartha City Hunter's hall");
     set_short("Zartha Hunter's Hall");
     set_long("The Zartha Hunter's Hall. This place has been set up to aid those who patrol the dangerous streets at night. The floorboards look very worn and the furniture is well used. Many posters hand up around the walls and the there is a sign on the wall.");
     set_items(([
		"sign"		: "The sign describes the services available. Perhaps you should read it?",
                "posters"	: "The posters detail various forms of undead - Skeletons, Zombies, Shades, Vampires and Liches.",
                "furniture"	: "Many chairs and a few tables placed around the room for the comfort of those coming back from patrol."
                ]));
     set_exits(([
                "northeast"	: KEEPROOM"[]southwest.c"
                ]));
}

void reset() {
   ::reset();
     if (!present("aldurin"))
        new(KEEPMOB"hunterguy.c")->move(this_object());
}

void init() {
   ::init();
     add_action("reading", "read");
     add_action("returning", "return");
}

int reading(string str) {
    if (str == "sign") {
       write("----------------------------------------------------------------\n"
             "The hall of hunter's offers a bounty on the skulls of undead.\n\n"
             "If you manage to collect any, come back here and %^CYAN%^<return skulls>%^RESET%^\n"
             "----------------------------------------------------------------");
       return 1;
       }
    write("Read what?");
    return 1;
}

int returning(string str) {
    object tp;
    int money, numba;
    tp = this_player();
    money = 0;
    numba = 0;
    if (str == "skulls") {
       if (!present("skulltulamonz0r", tp)) {
          write("Skulls need to be in your inventory.");
          return 1;
          }
       while (present("skulltulamonz0r", tp)) {
             present("skulltulamonz0r", tp)->remove();
             money = (money + 20);
             numba = (numba +  1);
             }
       write("You turn in "+numba+" skulls for "+money+" gold pieces.");
       message("info", ""+tp->query_cap_name()+" turns in "+numba+" skulls for "+money+" gold pieces.", environment(tp), tp);
       tp->add_money("gold", money);
       }
    return 0;
}
