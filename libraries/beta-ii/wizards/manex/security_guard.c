#include <std.h>
inherit MONSTER;

void create() {
::create();
   set_name("security guard");
   set_short("security guard");
   set_long("this security guard is here to protect the innocent.  Sadly, "
	"you are not all that innocent.");
   set_id(({"guard", "security guard"}));
   set_level(10);
set_race("human");
set_body_type("human");
   set_gender("neuter");
   if(!present("baton"))
	new("/wizards/manex/baton.c")->move(this_object());
   add_money("gold",200);
}
