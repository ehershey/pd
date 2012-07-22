#include <std.h>

inherit "/wizards/pyro/personal/micmob.c";
#include "/wizards/pyro/personal/mic.h"

void create() {
  ::create();
  set_id( ({ "microphone" }) );
  micName = "*";
  noInvis = 0;
}
