#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_short("A sign. It will explode if you read it.");
  set_long("A wooden sign.");
  set_weight(1);
  set_id( ({"sign"}) );
  set_name("sign");
  set_prevent_get("You can't take it.");
}

void init() {
  ::init();
  add_action("read_sign", "read");
}

int read_sign(string str) {
  if (str != "sign") return 0;
  message("info", "This message will self-destruct in 10 seconds.", this_player());
  call_out("explode_sign", 10);
  return 1;
}

void explode_sign() {
  message("info", "The sign explodes into a thousand pieces!", environment(this_object()));
  this_object()->remove();
}
