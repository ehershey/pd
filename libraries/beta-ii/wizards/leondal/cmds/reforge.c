/******************************
 *
 * reforge.c
 *
 * Leondal - 09/2009
 *
 * Allows me to edit my ring
 * without desting and recloning
 * every time.
 *
 *******************************/

#include <std.h>

status main() {

  object nring,
         ring = present("leondal's ring",this_player());

  if(ring) {
    this_player()->force_me("remove leondal's ring");
    destruct(ring);
  }

  nring=clone_object("/wizards/leondal/obj/ring.c");
  nring->move(this_player());
  write("You reforge your ring with your diabolical magic.\n");
  this_player()->force_me("wear leondal's ring");

  return 1;
}
