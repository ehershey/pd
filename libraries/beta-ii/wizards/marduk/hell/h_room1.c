#include <std.h>
inherit VAULT;

int hell_check();

void create() {
::create();
    set_short("gate of hell");
    set_long("You stand before the entrance of %^RED%^Gehenna%^RESET%^. "
                "A large iron gate sits imbedded into the ground "
                " before you. The gate %^GREEN%^glows %^RESET%^ "
                "with a %^RED%^deep hatred.");
    set_items(([
        "gate" : "a gate to hell"
    ]));
    set_properties(([
        "light" : 2,
    ]));
    set_exits(([
        "gate" : "/wizards/marduk/hell/h_room2.c",
    ]));
    set_door("gate", "/wizards/marduk/hell/h_room2.c", "gate", "fire key");
    set_string("gate", "open", "The iron gate suddenly dissapears revealing a long set of stairs.\n");  
    set_locked("gate", 1);
}


void reset() {
  ::reset();
     ("/wizards/marduk/hell/down.c")->set_locked("gate", 1);

     if(!present("guard"))
        {
        new("/wizards/marduk/hell/crim_guard.c")->move(this_object());
        new("/wizards/marduk/hell/crim_guard2.c")->move(this_object());
             }

}
