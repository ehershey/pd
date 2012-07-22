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

}
