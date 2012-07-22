#include <std.h>
#include <zolenia.h>
inherit ROOM;

void hurt_player();

void create() {
  ::create();
  set_properties( ([ "light" : 4, "night light" : 4, "indoors" : 1]) );
  set_smell("default", "A strong, earthy smell fills the air");
  set_listen("default", "Small rocks can be heard falling toward the ground.");
  set_short("climbing down the rocky slope");
  set_long("It appears as if the ground is finally stable, although definitely not flat.  Rocky cliffs surround your ledge, falling a shorter distance than before to what appears to be some stable ground.  This ledge, strangely, is made of some sort of crystal, a change from the constant onyx.");
  set_items(([
    ({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
   ]));
  set_exits(([ "down" : ROOMS "4.c"]));
  add_post_exit_function("down", "hurt_player");
}
void reset() {
  ::reset();
  if(!present("unicorn"))
  {
    new(MOB"unicorn")->move(this_object());
  }
}
void hurt_player() {
  object tp = this_player();
  message("info",
   "%^BOLD%^%^RED%^You fall, finally, to some solid ground. Oh, the adventures that await!%^RESET%^",
   tp);
  message("info",
   tp->query_cap_name()+" falls from above, landing with a loud thud.",
   environment(tp), tp);
  tp->do_damage("torso", 50+random(100));
}
