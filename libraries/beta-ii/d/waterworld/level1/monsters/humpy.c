#include <std.h>
#include <waterworld.h>

inherit MONSTER;

int counter,x;

void create() {
    ::create();
    set_name("Humpy");
    set_id(({"humpy","humback whale","whale"}));
    set_short("%^BLACK%^%^BOLD%^Humpy%^RESET%^, the humpback whale.");
    set_long("This is %^BLACK%^BOLD%^Humpy%^RESET%^, the humpback whale. He is patiently awaiting his turn to get his skin cleaned of barnacles and oil.");
    set_level(60);
    set_body_type("fish");
    set_race("humpback whale");
    set_gender("male");
    set_class("clergy");
    set_subclass("monk");
    set_emotes(1,({
	"%^BLACK%^%^BOLD%^Humpy%^RESET%^ tilts his head to one side to listen to the dispatcher to see if his name has been called.",
	"%^BLACK%^%^BOLD%^Humpy%^RESET%^ exhales through his blowhole, spraying everyone in the cavern!!",
	"%^BLACK%^%^BOLD%^Humpy%^RESET%^ shifts his weight at the dock, causing a moderate wave to ripple through the cavern."
      }),0);
    // blubberr loader
    counter=(1+(random(random(5))) );
    for(x;x<counter;x++) {
	new(ITEMS1+"blubber.c")->move(this_object());
    }
}
