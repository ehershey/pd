#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {


  object otherroom;

  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : RED "d10",
    ]) );

  set_no_clean(1);
  if(random(2) == 0)
    otherroom = load_object(RED "b3");
  else
    otherroom = load_object(RED "b17");
  add_exit(base_name(otherroom), "east");
  otherroom->set_no_clean(1);
  otherroom->add_exit(base_name(this_object()), "west");
}

