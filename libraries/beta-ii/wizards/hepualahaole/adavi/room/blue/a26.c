#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {

  object otherroom;

  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : BLUE "a37",
"northeast" : BLUE "a38",
"southeast" : BLUE "a16",
"south" : BLUE "a15",
"southwest" : BLUE "a14",
"northwest" : BLUE "a36",
    ]) );

  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(BLUE "b3");
  else
    otherroom = load_object(BLUE "c29");
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
