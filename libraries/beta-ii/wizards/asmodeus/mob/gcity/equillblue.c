#include <std.h>
#include <mjungle.h>
#include <gcity.h>
inherit MOUNT;

void create() {
    ::create();
set_name("equill");
set_id(({"horse", "equill", "beast", "lizard"}));
set_short("a %^BLUE%^blue%^RED%^ equill");
set_level(24);
set_long("The equill is a strange cross between a horse and lizard.  The equill is well adapted to the hot humid climate of the Merkkirri region.");
    set_body_type("equine");
    set_race("horse");
   set_gender("male");
}
