#include <std.h>
#include <aziraphale.h>
inherit ROOM;
int searchable;
void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "indoors" : 1, "no attack" : 1]));
     set_short("Rhondale");
     set_long("This place is obviously the home of an adventuring scholar. Books line the walls and are stacked upon each other all over the floor, maps of places are tossed about the place and many traveller's items adorn the room.");
     set_exits(([
                "west"                  : KEEPROOM"zvillage/inner02.c"
                ]));
	new(KEEPMOB"zvillage/smitherman.c")->move(this_object());
	searchable = 1;
}

void init() {
   ::init();
	add_action("searchin", "search");
}

int searchin(string str) {
	object ob;
	if(str != "for map") {
	  write("You could search for days in this mess and find nothing.");
	  return 1;
	  }
	if(searchable != 1) {
	  write("You dig through the junk but find nothing");
	  return 1;
	  }
	new(KEEPARMOUR"zvillage/map.c")->move(this_player());
	message("search", "Searching through the room you manage to find an interesting map bound with a leather cord.", this_player(), );
	message("search", this_player()->query_cap_name()+" finds something interesting amongst the junk.", this_object(), this_player());
	ob = present("smithxzor");
	ob->force_me("say Hey that's the map I was looking for! Please, give it to me.");
	message("info", "The man holds out his hand for the map.", this_object(), );
	searchable = 0;
	return 1;
}
