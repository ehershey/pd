#include <std.h>

inherit "/wizards/rull/a";

void create() {
  ::create();
  set_short("a test object");
  set_long("a test object");
  set_id( ({"test", "object", "test object"}) );
  set_name("test object");
}
