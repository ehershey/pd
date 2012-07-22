#include <std.h>
#include <illuminati.h>

inherit ILOBJ"halls.c";

void create() {
     object ob;
   ::create();
     set_type("clergy");
     set_properties(([ "light" : 3, "no scry" : 1, "no teleport" : 0, "indoors" : 1 ]));
     set_short("Illuminati Tower");
     set_long("%^BOLD%^WHITE%^Clergy Hall\n%^RESET%^CYAN%^Clergy of the Illuminati come here to train their skills, improve their innate abilities and generally advance in power. Various holy symbols and shrines adorn the room for use in prayer.%^RESET%^");
     set_exits(([
                "up" : ILROOM"newhall.c",
                "northeast" : ILROOM"floor5"
                ]));

        ob = new(OBJECT);
        ob->set_short("%^BOLD%^WHITE%^Altar of Life%^RESET%^");
        ob->set_long("A simple altar of wood, freely given by the forest gods, to serve as a place of prayer for all clergy of the Illuminati.");
        ob->set_prevent_get("The altar cannot be removed.");
        ob->set_id(({ "altar", "altar of life" }));
        ob->set_weight(1);
        ob->move(this_object());
}
