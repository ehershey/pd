#include <std.h>
#include <wildfire.h>

inherit OBJECT;

int youdie();

void create() {
  ::create();
  set_name("");
  set_short("");
  set_long("");
  set_id(({ "uwtrb" }));
  set_prevent_get("");
}
int drop() { return 0; }
void init() {
  ::init();
  add_action("go_surface", "surface");
  add_action("go_swim", "swim");
  if(this_player()->query_subclass() == "blue") {
    //do nothing, but keep the item here so that blue dragons can still surface
  }
  else {
    call_out("b1", 1);
  }
}
int b1() {
  this_player()->move(ROOMS"uwtr");
  write("%^BLUE%^You dive into the water. Don't forget to <surface> if you run out of air!");
  say("%^BOLD%^%^BLUE%^"+this_player()->query_name()+" dives into the water.", this_player());
  call_out("b2", 10);
}
int b2() {
  write("%^CYAN%^A small stream of water comes forth from your mouth.");
  write("%^CYAN%^A small stream of air bubbles comes forth from your mouth.");
  call_out("breath", 20);
}
int breath() {
  say("%^RED%^%^BOLD%^"+this_player()->query_cap_name()+" begins to thrash about.");
  write("%^BOLD%^%^RED%^Your lunges start to burn as you run out of air.");
  call_out("harm1", 9);
}
int harm1() {
  write("%^RED%^You run out of air and start drowning!");
  this_player()->add_hp(-20);
  this_player()->force_me("hp");
  if (this_player()->query_hp() <= 0) {
    youdie();
  }
  else call_out("harm2", 9);
}
int harm2() {
  write("%^RED%^Your lunges burn and you get dizzy!");
  this_player()->add_hp(-60);
  this_player()->force_me("hp");
  if (this_player()->query_hp() <= 0) {
    youdie();
  }
  else call_out("harm3", 9);
}
int harm3() {
  write("%^RED%^You start to sink!");
  this_player()->add_hp(-260);
  this_player()->force_me("hp");
  if (this_player()->query_hp() <= 0) {
    youdie();
  }
  else call_out("harm4", 9);
}
int harm4() {
  write("%^RED%^You get very dizzy and vomit!");
  say("%^RED%^"+this_player()->query_name()+" vomits!", this_player());
  this_player()->add_hp(-300);
  this_player()->force_me("hp");
  if (this_player()->query_hp() <= 0) {
    youdie();
  }
  else call_out("harm5", 9);
}
int harm5() {
  write("%^RED%^You start inhaling water!");
  this_player()->add_hp(-400);
  this_player()->force_me("hp");
  if (this_player()->query_hp() <= 0) {
    youdie();
  }
  else call_out("harm6", 9);
}
int harm6() {
  write("%^RED%^Your eyes roll into the back of your head!");
  this_player()->add_hp(-500);
  this_player()->force_me("hp");
  if (this_player()->query_hp() <= 0) {
    youdie();
  }
  else call_out("youdie", 5);
}
int youdie() {
  write("%^RED%^You drown!");
  say("%^RED%^"+this_player()->query_name()+" drowns!", this_player());
  this_player()->set_hp(-99);
  this_player()->die();
  this_object()->remove();
}
int go_surface(string str) {
  write("%^BOLD%^%^BLUE%^You swim for the surface.");
  say("%^BOLD%^%^BLUE%^"+this_player()->query_cap_name()+" swims towards the surface of the water.", this_player());
  this_player()->move(ROOMS"farm22");
  write("%^BOLD%^%^BLUE%^You swim out of the water and start breathing heavily.");
  say("%^BOLD%^%^BLUE%^"+this_player()->query_cap_name()+" breaks the surface of the water, breathing heavily.", this_player());
  this_object()->remove();
  return 1;
}

int go_swim(string str) {
  if(str != "down") return 0;
  write("You squeeze through the crevice.");
  this_player()->move_player(ROOMS"cave", "through a small hole in the ground.");
  write("You pop through the hole and find yourself, strangely, on solid ground.");
  say("A rush of water flows out of the hole in the ceiling. "
     +"As the water washes away, you notice "
     +this_player()->query_name()+" picking "
     +this_player()->query_objective()+"self up off of "
     +"the ground.", this_player());
  this_object()->remove();
  return 1;
}
