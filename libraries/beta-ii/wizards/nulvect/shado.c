
#include <std.h>

inherit OBJECT;

object do_sh(string str) {
  object o=present(str, find_player("nulvect"));
  return shadow(o);
}
void create() {
  ::create();
  set_long("blah");
  set_short("blah");
  set_weight(0);
  set_id( ({"blah"}) );
  set_name("blah");
}

string query_long() { return "this is a test"; }
