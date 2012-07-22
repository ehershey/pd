#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "indoors" : 1, "no teleport" : 1]));
  set_short("a cardboard box");
  set_long("This is a very large cardboard box. It's about tall enough "
    "for a person to stand up in. The bottom is a bit damp and dirty, "
    "but the rest of it is a shiny new cardboard-brown. A couple milk crates "
    "serve as seats, and a plank on the ground seems to be a bed.");
  set_smell("default","Wet cardboard.");
  set_listen("default","Wind whistles through the flaps.");
  set_exits( ([
    "square" : "/d/nopk/tirun/square",
    "east" : "/wizards/nulvect/workroom2",
  ]) );
}

void reset() {
  object b;
  ::reset();
  if (!present("nulvect_board")) {
    b = new("/std/bboard");
    b->set_name("nulvect board");
    b->set_id( ({"board","nulvect_board","nulvect's board"}) );
    b->set_board_id("nulvect_board");
    b->set_max_posts(500);
    b->set_edit_ok( ({ "nulvect", "nultest" }) );
    b->set_location("/wizards/nulvect/workroom");
    b->set_short("Nulvect's board");
    b->set_long("A black painted plank with scribblings in white chalk.\n");
  }
}

