#include <std.h>
#include <illuminati.h>

inherit ILOBJ"halls.c";

void create() {
     object ob;
   ::create();
     set_type("rogue");
     set_properties(([ "light" : 3, "no scry" : 1, "no teleport" : 0, "indoors" : 1 ]));
     set_short("Illuminati Tower");
     set_long("%^BOLD%^WHITE%^Rogue Hall\n%^RESET%^CYAN%^Rogues of the Illuminati come here to train their skills, improve their innate abilities, and generally advance in power. The room is filled with all manner of traps and locks for use in training.%^RESET%^");
     set_exits(([
                "up" : ILROOM"newhall.c",
		"northwest" : ILROOM"floor5"
		]));

	ob = new(OBJECT);
	ob->set_short("%^BOLD%^WHITE%^Door of Locks%^RESET%^");
	ob->set_long("This door stands in the middle of the room and has a dozen locks of varying difficulty down the side of it. It is often used by the rogues to hone lockpicking skills.");
	ob->set_prevent_get("The door is set into the ground");
	ob->set_id(({ "door", "door of locks"}));
	ob->set_weight(1);
	ob->move(this_object());
}
