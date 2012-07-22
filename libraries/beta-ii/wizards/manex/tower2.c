#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("another room of the tower");
set_day_long("This is really strange, you seem to feel warm air coming from "
"the stairway leading up. What is up there? you start to feel kind of tired "
"as you realize that you have been climing these steps for some time.");
set_night_long("It is nearly completely dark. you are sweating, partly "
"of the heat eminating from upstairs, and partly because you're tired from "
"climing all those previous stairs.");
set_items(([
"stairs" : "the stairs are really tall, and narrow, you should be careful.",
]));
set_properties(([
"light" : 3,
"night light" : 1,
]));
set_exits(([
"up" : "wizards/manex/tower3.c",
"down" : "/wizards/manex/tower1",
]));
}
