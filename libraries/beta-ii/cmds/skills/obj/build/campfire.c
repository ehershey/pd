#include <std.h>
inherit OBJECT;
int lit, fuel, light_time;
int amt;
void light(int time);
void setup(int nat) {
  amt = nat;
}
void init() {
 ::init();
      add_action("get_it", "get");
    add_action("goWarm", "warm");
    add_action("extinguish","extinguish");
}
void create() {
 ::create();
    set_name("fire");
    set_id( ({ "build_fire_ob","fire", "a fire", "the fire", "campfire" }) );
    set_short("a %^RED%^campfire%^RESET%^");
    set_long("A warm crackling fire. You should warm yourself beside it.\n");
    set_property("no get all", 1);
    set_prevent_get( "%^RED%^The fire is to hot!%^RESET%^\n" );
    fuel = 3000;
    lit = 1;
    amt = 0;
    call_out("go_dark",fuel);
    }
void light(int time)
{
    light_time = time;
    environment(this_object())->set_property("light", 2);
    call_out("go_dark", fuel);
}
int get_it(string str) {
   if (present(str, environment(this_player())) != this_object())
     return 0;
    write("The fire %^BOLD%^%^RED%^burns%^RESET%^ you!\n");
    say(this_player()->query_cap_name()+" burns "+this_player()->query_possessive()+" hand in the fire!",this_player());
    this_player()->add_hp(-(random(20)));
    return 1;
}
int goWarm(string str) {
  string gen;
      if ((string)this_player()->query_gender() == "male") gen = "him";
      else
       gen = "her";
   if (this_player()->query_disable())
   {
    write("You can not get closer to the fire.");
    return 1;
   }
 
 this_player()->set_disable();
 this_player()->heal(10+amt);
      
 write("%^RED%^%^BOLD%^The warmth from the fire makes you feel better.");
 say(this_player()->query_cap_name()+" warms "+gen+"self by the fire.", this_player());
 return 1;
}
int extinguish(string str) {
    if(!id(str)) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
    if(!lit) {
        notify_fail("The fire is not lit!\n");
        return 0;
    }
    write("You extinguish the fire.\n");
    say(this_player()->query_cap_name()+" extinguishes the fire.\n",
        this_player());
    environment(this_object())->set_property("light", -2);
    fuel -= (light_time - time());
    remove_call_out("go_dark");
    lit = 0;
    this_object()->remove();
    return 1;
}
 
void go_dark() {
//    environment(this_object())->set_property("light", -2);
    fuel = 0;
if(environment(this_object()))
    message("info", "The fire burns out.", environment(this_object()));
    lit = 0;
    this_object()->remove();
}
int query_lit() { return lit; }
int query_fuel() { return fuel; }
