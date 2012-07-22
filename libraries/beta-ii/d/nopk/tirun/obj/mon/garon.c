#include <std.h>
#include <daemons.h>
inherit "/std/vendor";
void create() {
    ::create();
    set_name("garon");
    set_id(({ "garon", "shopkeeper", "keeper", "tanner" }));
    set_short("Garon, the Master Tanner.");
    set_level(25);
    set_long(
      "A mountain man if ever there was one, Garon stands well over six foot "
      "tall, has a full beard, and has a sour look on his face all the time.  "
      "As a master tanner, he is second to none in the craft of skins and hides."
    );
    set_languages(({ "selunian" }));
    set_type(({ "skin" }));
    set_gender("male");
    set_alignment(0);
    set("race", "eternal");
    add_money("silver", random(450));
    set_body_type("human");
    set_currency("silver");
set_storage_room("/d/nopk/tirun/skinstorage");
    set_skill("melee", 100);
    set_skill("bargaining", 85);
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
	if(!present("package_tanner", this_object())) return;
	obbit = present("package_tanner", this_object());
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
