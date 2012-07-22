#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("sage");
   set_id( ({ "wise man", "sage" }) );
   set_short("A wise old sage");
  set_level(30);
   set_long("The wise old sage of Tirun teaches people "
            "many languages. He is older than the village of Tirun itself. "
            "His back is bent and he has a very long beard, though his "
            "hair has all fallen out.");
    set_body_type("human");
   set_race("human");
   set_gender("male");
}
void catch_tell(string str) {
    object ob, obbit, obbofoo;
    string abba, bobo, cats;
    int foo1, foo2, foo3, foo4, foo5, foo6;
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
        if(!(ob=present((abba=lower_case(abba)), environment(this_object()))))
return;
        if(!present("package_sage", this_object())) return;
        obbit = present("package_sage", this_object());
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
