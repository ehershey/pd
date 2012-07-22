#include <std.h>
#include <daemons.h>
#define DE_BUG
inherit MONSTER;

string owner;

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
    //  for citrin quest
    string name, blah;
    //  end
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
	if(!(ob=present((abba=lower_case(abba)), environment(this_object())))) return;
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
	    force_me("say Why, you're late!  I shall not pay you for such "
	      "vile service!");
	    say(this_object()->query_cap_name()+" hands "
	      +this_player()->query_cap_name()+" a receipt.");
	    write(this_object()->query_cap_name()+" hands you a receipt.");
	    obbofoo = new("/std/object.c");
	    obbofoo->set_name("receipt");
	    obbofoo->set_id(({ "receipt_deliv", "delivery receipt", "receipt" }));
	    obbofoo->set_short("a delivery receipt");
	    obbofoo->set_long("A delivery receipt.  It is marked LATE.  It must "
	      "be returned to the headmaster before any more deliveries can be made.");
	    obbofoo->set_property("late", 1);
	    obbofoo->move(this_player());
	    return;
	}
	if(foo6>0){
	    force_me("say Oooh..my delivery!  Thanks!");
	    say(this_object()->query_cap_name()+" hands "
	      +this_player()->query_cap_name()+" some cash and a receipt.");
	    obbofoo = new("/std/object.c");
	    obbofoo->set_name("receipt");
	    obbofoo->set_id(({ "receipt_deliv", "delivery receipt", "receipt" }));
	    obbofoo->set_short("a delivery receipt");
	    obbofoo->set_long("A delivery receipt.  It is marked ON TIME.  It "
	      "must be returned to the headmaster before any more deliveries can be made.");
	    obbofoo->set_property("late", 0);
	    obbofoo->move(this_player());
	    write(this_object()->query_cap_name()+" hands you some cash and "
	      "a receipt.");
	    this_player()->add_exp(foo5+(foo6/5));
	    this_player()->add_money("gold", foo4+(foo6/5));
	    return;
	}
    }
    if(sscanf(str, "%s gives you%s", name, blah) == 2) {
	if(strsrch(blah, "plain note")!=-1)
	    if(ob = present("citrin_quest_ob")) {
		if(owner) return;
		force_me("think");
		call_out("citrin_quest_one", 2);
		owner = this_player()->query_name();
		return;
	    }
	if(strsrch(blah, "odd looking book")!=-1)
	    if(ob = present("citrin_quest_ob_2")) {
		if(!this_player()->query("citrin")) return;
		if(!present("citrin_quest_ob")) return;
		force_me("smile");
		force_me("say It will take awhile for me decipher this.  I "
		  "will call you when its time to pick up the information.");
#ifdef DE_BUG
		call_out("citrin_quest_two", random(10));
#else   
		call_out("citrin_quest_two", random(300));
#endif
		if(this_player()->query("citrin") < 2)
		    this_player()->set("citrin", 2);
		return;
	    }
    }
    if(owner) {
	if(present(owner)) {
	    call_out("citrin_quest_three", 2);
	}     
    }
}

int citrin_quest_one() {
    force_me("say It has been long since i have seen this ancient text.  Alone "
      "I cannot decipher it.  I will need the aid of a book.  Bring me this "
      "book and then I will tell you what this stands for.");
    if(this_player()->query("citrin") > 1) return;
    this_player()->set("citrin", 1);
    return 1;
}

int citrin_quest_two() {
    if(owner)
	if(present(owner)) {
	    force_me("say Why thank you for waiting.  Here is your note.");
	    new("/d/citrin/obj/quest/dnote.c")->move(this_object());
	    force_me("give citrin_quest_ob_4 to "+owner);
	    owner = 0;
	    return;
	} else {
	    force_me("tell "+owner+" I have finished deciphering your note.  Come back "
	      "to me to pick it up.");
	    new("/d/citrin/obj/quest/dnote.c")->move(this_object());
	    return 1;
	}
}

int citrin_quest_three() {
    if(!present(this_player())) return;
    if(this_player()->query("citrin") >= 2) {
	force_me("say Ahh,  there you are.  Here is a note that was deciphered from "
	  "the note you gave me.");
	force_me("give citrin_quest_ob_4 to "+owner);
	if(this_player()->query("citrin") > 3) return;
	this_player()->set("citrin", 3);
	owner=0;
	return 1;
    }
}

