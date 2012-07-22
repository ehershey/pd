#include <std.h>
#include <daemons.h>

inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("lars");
    set_id( ({ "lars", "barkeep" }) );
    set_short("Lars, the proprietor");
    set("aggressive", 0);
    set_level(10);
    set_long("He tends bar and he listens to the stories of soldiers, citizens, and any "
      "others that venture into his bar. Lars would be an excellent source of information "
      "and gossip if he would chat with anyone for once.");
    set_gender("male");
    set_alignment(122);
    set("race", "human");
    add_money("gold", random(60));
    set_body_type("human");
    set_currency("gold");
  set_menu_header("The following drinks are served at the Drowning Fish:");
  set_menu_footer("<buy drink_name> gets you a drink.");
  set_menu( ([
    "firebreather" : ([
      "type" : "alcoholic",
      "strength" : 50,
      "long" : "A firebreather from the Drowning Fish.",
      "my_mess" : "The firebreather burns your throat!",
      "your_mess" : "winces from the burning of a firebreather."
    ]),
    "quickening" : ([
      "type" : "alcoholic",
      "strength" : 75,
      "my_mess" : "The shot of quickening burns like no other drink!",
      "your_mess" : "screams at the horrible burning of the quickening.",
      "short" : "A %^BOLD%^%^WHITE%^sho%^CYAN%^t of%^BLUE%^ Qu%^BOLD%^%^BLUE%^i%^CYAN%^cke%^WHITE%^ning%^RESET%^",
      "long" :
	"A shot of a pale blue alcoholic beverage called quickening. Quickening burns "
	"like nothing else you'll ever feel. A strong mixture, the pride of the Drowning Fish.",
    ]),
    "special" : ([
      "type" : "alcoholic",
      "strength" : 20,
      "servings" : 3,
      "short" : "a special of the house",
      "long" : "A classic special of the house from the Drowning Fish.",
    ]),
    "ale" : ([
      "type" : "alcoholic",
      "strength" : 7,
      "servings" : 4,
      "short" : "a pale ale",
      "long" : "A pale ale brewed in the farming fields outside Tirun.",
    ]),
  ]) );
}
void catch_tell(string str) {
    object ob, obbit, obbofoo;
    string abba, bobo, cats;
    int foo1, foo2, foo3, foo4, foo5, foo6;
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
	if(!(ob=present((abba=lower_case(abba)), environment(this_object()))))
	    return;
	if(!present("package_lars", this_object())) return;
	obbit = present("package_lars", this_object());
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
