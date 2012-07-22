#include <std.h>
inherit VAULT;

//int hell_check();

void create() {
::create();
    set_short("Entrance to Gehenna");
    set_day_long("You stand before the gates of Gehenna. All light and "
		"existence seems to end here, while another dark and "
		"%^RED%^sinister%^RESET%^ dimension fills the inner gates.");
    set_night_long("Blending within the night, the gates of Gehenna seem "
		"almost invisible. The %^GREEN%^eerie glow %^RESET%^of the moon radiates "
		"%^RED%^fear%^RESET%^ and %^RED%^evil%^RESET%^ off the dark gates.");
    set_property ("town",1);
    set_items(([
	"gates" : "The gates hold all the %^RED%^evil%^RESET%^ in %^RED%^chaos %^RESET%^within Gehenna.",
	"moon" : "The moon casts an %^GREEN%^eerie glow %^RESET%^over the gates.",
    ]));
    set_properties(([
        "light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
     "gate" : "/wizards/marduk/gehenna/room2.c",
    ]));
    set_door("gate", "/wizards/marduk/gehenna/room2.c", "gate", "skull key");
    set_string("gate", "open", "The gates silently creep open.\n");  
    set_locked("gate", 1);
}

void reset() {
  ::reset();
    if(!present("elf"))
        new("/wizards/marduk/gehenna/p_guard.c")->move(this_object());
        new("/wizards/marduk/gehenna/p_guard2.c")->move(this_object());

}
