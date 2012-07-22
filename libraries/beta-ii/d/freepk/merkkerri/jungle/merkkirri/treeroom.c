#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
    ::create();
    set_short("Warlock's Home");
    set_long("You have entered a home of a Merkkirri Warlock.  Her home is filled with books, vials, arcane artifacts and is quite a mess.  Strange orbs of light luminate the room with a soft %^MAGENTA%^violet%^RESET%^ glow. The only exit appears to be out through the door you entered.");
    set_listen("default", "The sounds of boiling liquids and steam fill the room.");
    set_smell("default", "The home smells of strange elixers and sulfur.");
    set_properties((["light" : 3, "indoors" : 3,]));
    set_exits(([
	"out" : MJUNGLE "tree2.c"
      ]));
    //add_invis_exit("trace_runes");
    set_door("door", MJUNGLE "tree2.c", "out", "crystalline key");
}

void hidden_note() {
    message("my_action", "You find a note stuck within the pages of the journal.", this_player());
    message("other_action", this_player()->query_cap_name()+" finds a note hidden inside the journal.", this_object(), ({ this_player() }));
    new(MOB "note")->move(this_object());
    remove_search("journal");
}

void hidden_necklace() {
    message("my_action", "You find a beautiful piece of jewelry hidden in her home..", this_player());
    message("other_action", this_player()->query_cap_name()+" finds a necklace hidden in the shadows.", this_object(), ({ this_player() }));
    new(MJUNGLE "necklace")->move(this_object());
    remove_search("shadows");
}

void reset() {
    ::reset();
    set_search("books", "There are some interesting books here.  An atlas, a bestiary, various books on alchemy, a journal and works on magic.");
    set_search("journal", (: hidden_note :));
    if (random(10) < 2)
	set_search("shadows", (: hidden_necklace :));
    set_open("door", 0);
    set_locked("door", 1);
    MJUNGLE "tree2"->set_open("door", 0);
    MJUNGLE "tree2"->set_locked("door", 1);
    if(!present("warlock"))
	new(MOB "warlock")->move(this_object());
}
