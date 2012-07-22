#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("kaldir");
 set_level(30);
 set_short("Kaldir, the healer");
 set_long("He runs the hospital.");
 set_race("human");
 set_gender("male");
 set_id( ({ "kaldir", "healer" }) );
}
int is_invincible() {return 1;}
void init()
{
 ::init();
 add_action("fBuy", "buy");
}
int fBuy(string str) {
  int numba;
  object oil;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="ointment") {
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -200);
    write("Kaldir hands you a vial of ointment.");
    say("Kaldir hands "+this_player()->query_cap_name()+" a vial of ointment.");
    new("/std/obj/ointment")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "ointment") {
    write("Buy what?\n");
    return 1;
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(numba > 1000) {
    this_object()->force_me("say I dont have that many right now!");
    return 1;
  }
  if(this_player()->query_money("gold") < 200*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -200*numba);
  write("Kaldir hands you "+(string)numba+" vials of ointment.");
  say("Kaldir hands "+this_player()->query_cap_name()+" "+(string)numba+" vials of ointment.");
  while(numba--)
    new("/std/obj/ointment")->move(this_player()); 
  return 1;
}
void catch_tell(string str) {
    object ob, obbit, obbofoo;
    string abba, bobo, cats;
    int foo1, foo2, foo3, foo4, foo5, foo6;
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
        if(!(ob=present((abba=lower_case(abba)), environment(this_object()))))
return;
        if(!present("package_ointment", this_object())) return;
        obbit = present("package_oil", this_object());
        foo1 = obbit->query_devtimestart(); 
        foo2 = obbit->query_devtimeperiod();
        foo3 = foo1 + foo2;
        foo4 = obbit->query_dev_value();
        foo5 = obbit->query_dev_exp();
        foo6 = foo3 - time();
        obbit->remove();
   if(foo6<0){
        force_me("say Why, you're late!  I shall not pay you for such vile service!");
        say(this_object()->query_cap_name()+" hands "+this_player()->query_cap_name()+" a receipt.");
        write(this_object()->query_cap_name()+" hands you a receipt.");
        obbofoo = new("/std/object.c");
        obbofoo->set_name("receipt");
        obbofoo->set_id(({ "receipt_deliv", "delivery receipt", "receipt" }));
        obbofoo->set_short("a delivery receipt");
        obbofoo->set_long("A delivery receipt.  It is marked LATE.  It must be returned to the headmaster before any more deliveries can be made.");
        obbofoo->set_property("late", 1);
        obbofoo->move(this_player());
        return;
        }
   if(foo6>0){
        force_me("say Oooh..my delivery!  Thanks!");
        say(this_object()->query_cap_name()+" hands "+this_player()->query_cap_name()+" some cash and a receipt.");
        obbofoo = new("/std/object.c");
        obbofoo->set_name("receipt");
        obbofoo->set_id(({ "receipt_deliv", "delivery receipt", "receipt" }));
        obbofoo->set_short("a delivery receipt");
        obbofoo->set_long("A delivery receipt.  It is marked ON TIME.  It must be returned to the headmaster before any more deliveries can be made.");
        obbofoo->set_property("late", 0);
        obbofoo->move(this_player());
        write(this_object()->query_cap_name()+" hands you some cash and a receipt.");
        this_player()->add_exp(foo5+(foo6/5));
        this_player()->add_money("gold", foo4+(foo6/5));
        return;
}
    }
}
