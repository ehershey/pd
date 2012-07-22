#include <std.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "indoors" : 1, "light" : 2, "no teleport" : 1, "no attack" : 1, "no steal" : 1, "no scry" : 1, "no bump" : 1 ]) );
  set_short("a blank room");
  set_long("This room is quite empty.");
}
