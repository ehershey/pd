#include <std.h>
#include <daemons.h>
inherit "/std/vendor";

void create() {
 ::create();
   set_name("xor");
   set_id(({ "xor", "xor the old", "shopkeeper", "keeper" }));
   set_short("Xor, the old");
   set("aggressive", 0);
   set_level(30);
   set_long(
     "By far the oldest living creature in this part of the world. Despite any "
     "other claims, Xor is by far older than any. He was around for the birth of "
     "the first dragon. Xor was old when the world was still young. After having "
     "lived many lives, he has settled to run this weapon shop, for now at "
     "least.."
   );
   set_languages(({ "selunian" }));
   set_type(({ "weapon" }));
   set_gender("male");
   set_alignment(0);
    set_exp(1);
   set("race", "eternal");
   add_money("silver", random(450));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/nopk/tirun/wstorage");
   set_skill("melee", 100);
   set_skill("bargaining", 75);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in selunian Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
void catch_tell(string str) {
    object ob, obbit, obbofoo;
    string abba, bobo, cats;
    int foo1, foo2, foo3, foo4, foo5, foo6;
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
        if(!(ob=present((abba=lower_case(abba)), environment(this_object()))))
return;
        if(!present("package_weapon", this_object())) return;
        obbit = present("package_weapon", this_object());
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
