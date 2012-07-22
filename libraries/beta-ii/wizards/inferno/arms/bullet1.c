#include <std.h>
inherit OBJECT;

static int bullets;

void set_bullets(int x) { bullets = x;    }

void add_bullets(int x) { bullets += x; if (bullets < 1)
                                          this_object()->remove();  }

int query_bullets()    { return bullets; }

string query_long() { return "A box of "+bullets+" bullets."; }

void create() {
 ::create();
   set_name("bullets");
   set_short("a box of bullets");
   set_value(0);
   set_id(({ "bullets", "box", "box of bullets" }));
   set_bullets(25); 
}


