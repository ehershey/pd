#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("The road here is well maintained and clean, having no debris or "
      "feces floating about in the gutters. Finely crafted stone steps to the south lead to "
      "an extraordinay looking tavern, boasting a grand oak sign engraved with the depiction "
      "of a white stallion. " );
    add_item("sign", "The White Horse Tavern");
    set_exits( ([ "west" : ROOMS "marketrd_e03.c",
      "east" : ROOMS "marketrd_e05.c",
      "south" : ROOMS "tavern_whitehorse.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The obnoxious laughter eminates from the nearby saloon.");

}
