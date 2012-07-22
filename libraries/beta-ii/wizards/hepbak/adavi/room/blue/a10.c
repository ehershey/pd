#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {

  object otherroom;

  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : BLUE "a24",
"east" : BLUE "a11",
"south" : BLUE "a2",
"west" : BLUE "a9",
"northeast" : BLUE "a25",
"southeast" : BLUE "a3",
"southwest" : BLUE "a",
"northwest" : BLUE "a23",
    ]) );

  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(BLUE "b2");
  else
    otherroom = load_object(BLUE "c27");
  add_exit(base_name(otherroom), "dive");
    add_invis_exit("dive");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "dive");
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
