#include <std.h>
#include <waterworld.h>
inherit MONSTER;
void create()  {
    ::create();
    set_name("cod");
    set_short("a moderate-sized cod");

    set_long("This moderate sized Tirun Cod grows as long as 7 feet and can become up to 30 pounds. Due to the beautiful long silver body that contains one red streak down the side, cods usually have short lives. Most every monster in the water that can get any limb on them eats them.");

    set_level(15);
    set_body_type("fish");
    set_gender("female");
    set_race("fish");
    set_id(({"cod","fish"}));
    set_class("fighter");
    set_subclass("warrior");
    set_money("gold",10);
    new(ITEMS1"fillet.c")->move(this_object());
}
