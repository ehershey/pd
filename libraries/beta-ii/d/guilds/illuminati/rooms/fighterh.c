#include <std.h>
#include <illuminati.h>

inherit ILOBJ"halls.c";

void create() {
    object ob;
    ::create();
    set_type("fighter");
    set_properties(([ "light" : 3, "no scry" : 1, "no teleport" : 0, "indoors" : 1 ]));
    set_short("Illuminati Tower");
    set_long("%^BOLD%^WHITE%^Fighter Hall\n%^RESET%^CYAN%^All the fighters, skilled in physical combat, come here to train their skills, improve their innate abilities, and generally advance in power. The room is filled with all manner of weaponry for use in training.%^RESET%^");
    set_exits(([
	"up" : ILROOM"newhall",
	"east" : ILROOM"floor5"
      ]));

    ob = new(OBJECT);
    ob->set_short("%^BOLD%^WHITE%^Weapons Rack%^RESET%^");
    ob->set_long("A steel rack with dozens of training weapons hung on it. Broadswords, Scimitars, Quarterstaffs, Bows, Daggers, Warhammers and Flails.");
    ob->set_prevent_get("The rack cannot be removed.");
    ob->set_id(({ "rack", "weapons rack" }));
    ob->set_weight(1);
    ob->move(this_object());
}
