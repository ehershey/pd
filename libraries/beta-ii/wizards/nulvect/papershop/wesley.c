#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create()
{
    ::create();
    set_name("patrick");
    set_level(30);
    set_short("Patrick, the healer shop owner");
    set_long("He's hard at work making oils and different "
      "types of objects.");
    set_race("human");
    set_gender("male");
    set_id( ({ "patrick", "owner" }) );
}
void init()
{
    ::init();
    add_action("fBuy", "buy");
    add_action("fRead", "read");
    // set_heart_beat(10);
}
int fRead(string str)
{
    if (!str || str!="sign")
	return notify_fail("Read what?\n");
    say (this_player()->query_cap_name()+" reads over the sign.");
    write("The sign reads:
-----------------------------------------
           --Items For Sale--
-----------------------------------------
 [ A vial of healing oil ]
     A magical blend of different oils from plants and herbs mixed
     togeather to make a healing oil. ( 20 gold pieces )
     You can <buy '#' oil> to buy a specific number of oils.
 
 [ A magical stone ] 
     The stone found deep in the Sindarii ocean has been found to
     emits a green light that carrys mana that is absorbed by the
     user to regain mana power. ( 30 gold peices )
     You can <buy '#' stones> to buy a specific number of stones.
-----------------------------------------");
 return 1;
}

int fBuy(string str) {
  int numba, enc, maxenc, over;
  object oil;

  enc = this_player()->query_internal_encumbrance();
  maxenc = this_player()->query_max_internal_encumbrance();

  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  /*
  if(str=="stone" || str=="magical stone") {
    this_object()->force_me("say I no longer sell stones here, my good "
      "friend in Arlon opened his own shop. If you need to purchase stones, "
      "goto him and buy them.");
    return 1;
  }
  */
  if(str=="oil") {
    if(enc + 2 > maxenc) {
      this_object()->force_me("say You can't hold another oil!");
      return 1;
    }
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Patrick hands you a vial of healing oil.");
    say("Patrick hands "+this_player()->query_cap_name()+" a vial of healing oil.");
    new("/std/obj/oil")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    /*
    write("Buy what?\n");
    return 1;
    */
    return notify_fail("Buy what?\n");
  }
  if(str != "oil") {
    /*
    write("Buy what?\n");
    return 1;
    */
    return notify_fail("Buy what?\n");
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(numba > 1000) {
    this_object()->force_me("say I dont have that many right now!");
    return 1;
  }

  // If they try to buy too many...

  over = enc + ((numba / 15) * 2) - maxenc;
  if(over > 0) {
    numba = numba - ((over * 15)/2);
    numba -= numba % 15;
    if(numba == 0) {
      this_object()->force_me("say You can't hold any more oils!");
      return 1;
    }
    this_object()->force_me("say I'd say you could only hold "+numba+" more oils.");
    return 1;
  }
  if(this_player()->query_money("gold") < 20*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -20*numba);
  write("Patrick hands you "+(string)numba+" vials of healing oil.");
  say("Patrick hands "+this_player()->query_cap_name()+" "+(string)numba+" vials of healing oil.");

  while(numba > 0) {
    oil = new("/std/obj/oil");
    if(numba >= 15)
      oil->set_uses(15);
    else
      oil->set_uses(numba);
    numba -= 15;
    oil->move(this_player());
  } 
  return 1;
}

void catch_tell(string str) {
    object ob, obbit, obbofoo;
    string abba, bobo, cats;
    int foo1, foo2, foo3, foo4, foo5, foo6;
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
        if(!(ob=present((abba=lower_case(abba)), environment(this_object()))))
return;
        if(!present("package_oil", this_object())) return;
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
/* void heart_beat()
{
 if (random(50) > 25)
  {
 this_object()->force_me("say if you want to buy some healing oil type,
<buy oil>");
}
*/
