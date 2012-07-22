#include <std.h>
#include <illuminati.h>

inherit ILOBJ"halls.c";

void create() {
     object ob;
   ::create();
     set_type("wanderer");
     set_properties(([ "light" : 3, "no scry" : 1, "no teleport" : 0, "indoors" : 1 ]));
     set_short("Illuminati Tower");
     set_long("%^BOLD%^WHITE%^Wanderer Hall\n%^RESET%^CYAN%^The Wanderers of the Illuminati come here to train their skills, improve their innate abilities, and generally advance in power. The room is set up as a small concert hall to practice singing and dancing.%^RESET%^");
     set_exits(([
                "up" : ILROOM"newhall.c",
		"west" : ILROOM"floor5"
		]));

	ob = new(OBJECT);
	ob->set_short("%^BOLD%^WHITE%^Performing Stage%^RESET%^");
	ob->set_long("This stage has been set up in the hall so that all wanderers may practice their performing skills, especially singing and dancing.");
	ob->set_prevent_get("Yeah, right, you're fuckin nuts.");
	ob->set_id(({ "stage", "performing stage"}));
	ob->set_weight(1);
	ob->move(this_object());
}
