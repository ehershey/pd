#include <dquest.h>
#include <std.h>
inherit ARMOUR;

void init() {
  ::init();
add_action("open_rift", "open");
add_action("regenerate", "regenerate");
add_action("focus_hate", "focus");
}

void create() {
    ::create();
set_name("amulet");
set_short("%^RED%^A%^BOLD%^mulet %^RESET%^BOLD%^BLACK%^%^of the %^RESET%^RED%^N%^BOLD%^ether%^RESET%^RED%^ D%^BOLD%^emon%^RESET%^");
set_long("You gaze upon the amulet of the Nether Demon--a symbol worn by demons in reverence of their god.  It appears as an onyx ram's skull with a pentagram etched into the forehead.  The amulet has incredible powers and is a highly sacred artifact.");
set_id(({"holy symbol", "amulet", "amulet of the nether demon", "symbol"}));
set_ac(1);
set_weight(2);
set_value(0);
set_type("necklace");
set_limbs(({"torso"}));
}
int open_rift(string what) {
if (what!="rift")return 0;
write("%^BOLD%^RED%^You open a rift into the underworld.%^RESET%^");
this_player()->move_player(DQUEST "dquest115.c");
return 1;
}

int regenerate(string what) {
if (what!="body")return 0;
write("%^BOLD%^BLUE%^You concentrate on regenerating your body.%^RESET%^");
this_player()->add_hp((random(40))+(((this_player()->query_level()))/3)*3);
this_player()->set_paralyzed((random(4))+6);
return 1;
}

int focus_hate(string what) {
if (what!= "hate")return 0;
write("%^BOLD%^BLACK%^You summon your hatred.%^RESET%^");
this_player()->add_alignment(-10);
this_player()->set_paralyzed((random(4))+2);
return 1;
}

int query_auto_load() {return 1; }
