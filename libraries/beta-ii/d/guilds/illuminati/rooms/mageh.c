#include <std.h>
#include <illuminati.h>

inherit ILOBJ"halls.c";

void create() {
     object ob;
   ::create();
     set_type("mage");
     set_properties(([ "light" : 3, "no scry" : 1, "no teleport" : 0, "indoors" : 1 ]));
     set_short("Illuminati Tower");
     set_long("%^BOLD%^WHITE%^Mage Hall\n%^RESET%^CYAN%^Here the great mages of the Illuminati come to train their skills, improve their innate abilities, and generally advance in power. The room is filled with all manner of arcane relics for use in honing magical skills.%^RESET%^");
     set_exits(([
                "up" : ILROOM"newhall.c",
		"north" : ILROOM"floor5"
		]));

	ob = new(OBJECT);
	ob->set_short("%^BOLD%^WHITE%^Book of Arcana%^RESET%^");
	ob->set_long("The book is a great asset of the Illuminati. It has been enchanted to reveal the texts of any book in any open library of the realms, and is a great add in training.");
	ob->set_prevent_get("The book is magically held.");
	ob->set_id(({ "book", "book of arcana" }));
	ob->set_weight(1);
	ob->move(this_object());
}
