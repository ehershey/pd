#include <std.h>


inherit OBJECT;
void init() {
    ::init();

add_action("kill_pumpkin" , "kill");
}
void create()
{
 ::create();

 set_name("pumpkin");
 set_short("A BIG ASS pumpkin");
 set_long("This is a huge ass pumpkin");
 set_id( ({ "pumpkin" }) );
 set_mass(1000000);
 set_value(100000);
}

int kill_pumpkin(string what) {
  if (what != "pumpkin") return 1;
write("%^BOLD%^%^RED%^You attack a Big Ass Pumpkin.");
new("/wizards/detach/wff.c")->move(environment(this_object()));
 this_object()->remove();
 return 1;
 }




