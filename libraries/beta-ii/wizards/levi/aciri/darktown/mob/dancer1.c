#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
::create();
    set_name("dancer");
    set_short("%^RESET%^%^BOLD%^A beautiful Dancer");
    set_long("This dancer dances in perfect harmony "
           "with the organ's music.");
    set_id(({"dancer", "vampire" }));
    set_level(40);
    set_race("vampire");
    set_body_type("human");
    set_gender("female");

}
