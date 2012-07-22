#include <std.h>
#include <tirun.h>
#include <locations.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("potion");
    set_short("%^RESET%^%^BOLD%^Strange potion%^RESET%^");
    set_long(
        "The bottle has a large label on it:\n\n\n\t\t WARNING!!!\n\t"
        " Do NOT drink this liquid!\n\tIt is highly dangerous, and\n\twill likely result in death!");
    set_weight(2);
    set_id(({"potion","strange potion","bad_potion_QO"}));
}

void init() {
  ::init();
  add_action("drink", "drink");
}

int drink(string str) {
  if(!str) return 0;

  if(this_object() != present(str, this_player()))
    return notify_fail("Drink what?\n");

  write("You throw your head back and down the potion with the warning on it.");
  say(this_player()->query_cap_name()+" drinks a potion.");
  write("%^BOLD%^%^RED%^YOU CAN FEEL IT BURNING INSIDE YOU!!!%^RESET%^");
  say(this_player()->query_cap_name()+" grimaces in pain.");
  call_out("second", 4, this_player());
  return 1;
}

void second(object tp) {
  message("info","%^BOLD%^%^RED%^T%^YELLOW%^h%^RED%^e%^YELLOW%^ p%^RED%^a%^YELLOW%^i%^RED%^n %^YELLOW%^i%^RED%^s %^YELLOW%^j%^RED%^u%^YELLOW%^s%^RED%^t%^YELLOW%^ t%^RED%^o%^YELLOW%^o %^RED%^m%^YELLOW%^u%^RED%^c%^YELLOW%^h %^RED%^t%^YELLOW%^o %^RED%^b%^YELLOW%^e%^RED%^a%^YELLOW%^r%^RED%^!", tp);
  tp->die();
  this_object()->move(TEMP_LOC);
  /*
  if(tp->query_class() == "child" && tp->query_level() == 1)
    call_out("do_dragon", 2, tp);
  else */
    this_object()->remove();
}

void do_dragon(object tp) {
  tp->move("/d/quests/dragon/one");
  message("info","You find yourself in a place that seems quite close to reality...", tp);
  this_object()->remove();
}
