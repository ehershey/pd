#include <std.h>
#include <daemons.h>
inherit MONSTER;

#include <kwike.h>

void
create()
{
    ::create();
    set_name("Apu");
    set_id(({ "apu", "clerk" }));
    set_short("Apu the hindu clerk");
    set_long("Apu is wearing a badge that reads:\n\nWe I.D. under 30");
    set_race("hindu");
    set_gender("male");
    set_body_type("human");
}

void
init()
{
    ::init();
    add_action("cmd_buy", "buy");
    add_action("cmd_list", "list");
}

int
cmd_buy(string what) {
    int flavnum, itemnum;
    string flavor, name;
    object item;

    if (!what) {
        force_me("say "+this_player()->query_name()+", what is it you would like to buy?");
        return 1;
    }
    if (strsrch(what, " ") == -1) {
        switch ((itemnum = member_array(what, items))) {
            case -1:
                force_me("say I'm sorry, "+this_player()->query_name()+", we do not sell that.");
                return 1;
            case 0:
                force_me("say "+this_player()->query_name()+", what flavor of squishie do you want?");
                return 1;
        }     
    } else {
        if (sscanf(what, "%s %s", flavor, name) != 2 || (itemnum = member_array(name, items)) == -1) {
            force_me("say I'm sorry, "+this_player()->query_name()+", we do not sell that.");
            return 1;
        }
        if ((flavnum = member_array(flavor, flavors)) == -1 || flavnum > 4) {
            force_me("say "+this_player()->query_name()+", type <list> to see our squishie flavors.");
            return 1;
        }
    }
    if (this_player()->query_money("gold") < prices[itemnum]) {
        force_me("say "+this_player()->query_name()+", you do not have enough money to buy that!");
        return 1;
    }

    write("You give "+prices[itemnum]+" gold coins to Apu.");
    this_player()->add_money("gold", -prices[itemnum]);
    item = new(KWIKE_ITEM+"/"+items[itemnum]);
    if (name == "squishie" && flavnum != -1)
        item->set_flavor(flavnum);
    item->move(this_object());
    force_me("give "+item->query_short()+" to "+this_player()->query_name());

    return 1;
}

int
cmd_list(string stuff)
{
    int i;

    if (stuff)
        return 0;

    printf("nachos [20 gold]\n");
    printf("    Freshly baked tortilla chips and hot cheese.\n");
    for (i = 0; flavors[i] != "nachos"; i++)
        printf("%s squishie [50 gold]\n    %s\n", flavors[i], flavor_descriptions[i]);
    return 1;
}
void catch_tell(string str) {
    object ob, obbit, obbofoo;
    string abba, bobo, cats;
    int foo1, foo2, foo3, foo4, foo5, foo6;
    if(sscanf(str, "%s gives you %spackage%s", abba, bobo ,cats) == 3) {
        if(!(ob=present((abba=lower_case(abba)), environment(this_object()))))
return;
        if(!present("package_apu", this_object())) return;
        obbit = present("package_apu", this_object());
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
