#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
     ::create();
     set_name("wife");
     set_id(({ "wife", "farmer's wife" }));
     set_short("The farmer's wife");
     set_long("This is the farmer's wife. She hums happily as she picks flowers.");
     set_gender("female");
     set_race("human");
     set_body_type("human");
     set_level(15);
}
