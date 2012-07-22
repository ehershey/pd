#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Mountain Pass");
    set_long("The wind howls past, nearly knocking you over with its tremendous force. "
      "Your legs sink knee-deep into freezing white snow and your eyes begin to water "
      "from the blinding sting of the wind. A path can barely be made out leading south "
      "down the side of the mountain. A small cave lies a short way down the "
      "western path. A large cabin lies just to the north. Dark smoke rolls out of "
      "the chimney, only to be whisked rapidly away by the prevailing wind. "
    );
    set_exits(([ "west": ROOMS "mountaint_w01.c", 
      "south": ROOMS "mountaint_s01.c", 
      "north": ROOMS "cabin.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Nothing is audible over the high-pitched whine of the wind.");
}
