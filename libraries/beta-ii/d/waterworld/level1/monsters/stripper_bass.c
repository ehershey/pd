#include <std.h>
#include <waterworld.h>
inherit MONSTER;
int x;
int y;

void create()  {
    ::create();

    set_name("stripper bass");
    set_id(({"bass","stripper bass","stripper","fish"}));
    set_short("A hefty looking stripper bass swims hastily through the area");
    set_long("It's a fairly large bass, probably in the 50 to 75 pound range. It has a hard muscular body and a powerful tail for swimming in the ocean currents.");
    set_level(20);
    set_max_hp(1000);
    set_hp(1000);
    set_body_type("fish");
    set_gender("male");
    set_race("fish");
    set_class("fighter");
    set_subclass("ranger");
    set_spell_chance(25);
    set_spells(({"whip","whirl"}));
    set_money("gold",random(60));
    new(WEP1"tail.c")->move(this_object());           
    force_me("wield tail");
    ///    fillet loader

    x=random(6);
    for(y;y<x;y++)
    {
	new(ITEMS1"fillet.c")->move(this_object());
    }
}
