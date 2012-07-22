#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no magic", 1);
    set_property("no attack", 1);
    set_property("no castle", 1);
    set_property("indoors", 1);
    set_property("no steal", 1);
    set_property("no teleport", 1);
    set_property("no scry", 1);
    set_short("The Vorticon Shop");
    set_long("The room is filled with %^BOLD%^po%^RED%^wer%^WHITE%^ful%^RESET%^ artifacts all over the world, they clutter the floor and line the shelves. Most were created by powerful %^ORANGE%^fo%^RED%^rg%^ORANGE%^ers%^RESET%^ and magicians of the old world, their %^YELLOW%^p%^MAGENTA%^owe%^YELLOW%^r%^RESET%^ that they hold is almost incomprehensible to even the most knowledgable. The walls of this room appear to be %^BLUE%^ali%^MAGENTA%^v%^BLUE%^e%^RESET%^, they call out, luring others to join them in their doomed fate. In the southwestern corner of the room a lone figure mutters.");
    set_listen("default","%^MAGENTA%^The souls banished into the walls call out for someone to join them!");
    set_items(([
	"artifacts": "Too numerous to list. They clutter the room like children clutter the future.",
	"floor": "Artifacts cover the floor and shelves.",
	"shelves": "Artifacts cover the floor and shelves.",
	"walls": "Banished souls of the damned, forever stuck to their fate. Their only pleasure is to lure others to their doom.",
	"figure": "It is Dra'tatt the Eternal."]));
    set_exits(([
	"south": VORTICON "hall",
	"north": VORTICON "storage"]));
    set_invis_exits(({ "north" }));
    set_pre_exit_functions( ({"north"}), ({"north"}) );
    set_items(([
      ]));
}
void reset() {
    ::reset();
    if (!present("dratatt")) {
	new(VORTICON "dratatt.c")->move(this_object());
    }
}

int north() {
    if(!wizardp(this_player())) return 0;
    return 1;
}

