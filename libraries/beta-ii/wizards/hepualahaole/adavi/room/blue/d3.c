#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : BLUE "d5",
"southeast" : BLUE "d2",
"southwest" : BLUE "d",
"northwest" : BLUE "d4",
"dive" : BLUE "a10",
    ]) );

    add_invis_exit("dive");
}
void init()
{
 ::init();
 add_action("Fdive", "dive");
}

int Fdive()
{
 write("%^BOLD%^YELLOW%^As you dive into the pool, a dark form grabs you mid-air and drags you
through the water.  Just as you think you are ready to pass out, you get tossed
out of the water and land with a loud thump.%^RESET%^");
 return 0;
}
void reset() {
 ::reset();
   if (!present("pool", this_object()))
     new( ITEMS "pool.c" )->move(this_object());
}
