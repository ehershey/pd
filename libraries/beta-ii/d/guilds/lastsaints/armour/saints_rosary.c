#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Saints Rosary");
    set_short("%^RESET%^%^ORANGE%^S%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^ints R%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^sary%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^If you are a Throne, Power, Dominion or Principality, you may wear this as a show of rank.%^RESET%^");
    set_id(({ "Saints Rosary","rosary"}));
    set_ac(1);
    set_weight(2);
    set_curr_value("gold", 150);
    set_type("necklace");
    set_limbs(({"torso"}));
}

int query_auto_load() {
    if(this_player()->query_original_guild() == "lastsaints") return 1;
    return 0;
}
void init() {
    ::init();
    if(environment(this_object())->is_player()) {
	if(this_player()->query_guild() != "Last Saints") {
	    this_object()->move("/d/nopk/standard/void.c");
	    call_out("removeme", 1);
	}
	else
	    this_object()->changeme(this_player()->query_guild_position());
	this_object()->report_posts();
	add_action("report_posts", "posts");
	add_action("read_board", "read");
    }
    this_object()->changeme("default");
}

void changeme(string posi) {
    switch(posi) {
    case "squire" :
	set_name("Saints Rosary");
	set_short("%^RESET%^%^ORANGE%^S%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^ints R%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^sary%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^If you are a Throne, Power, Dominion or Principality, you may wear this as a show of rank.%^RESET%^");
	break;
    case "member" :
	set_name("Saints Rosary");
	set_short("%^RESET%^%^ORANGE%^S%^WHITE%^ai%^ORANGE%^nts R%^WHITE%^o%^ORANGE%^s%^WHITE%^a%^ORANGE%^ry%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This rosary signifies your rank as a Dominion within the Last Saints.%^RESET%^");
	break;
    case "council" :
	set_name("Saints Rosary");
	set_short("%^RESET%^%^WHITE%^S%^BOLD%^%^WHITE%^ai%^RESET%^%^WHITE%^nts R%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^s%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^ry%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This rosary signifies your rank as a Power within the Last Saints.%^RESET%^");
	break;
    case "leader" : case "main" :
	set_name("Saints Rosary");
	set_short("%^BOLD%^%^YELLOW%^S%^RESET%^%^ORANGE%^ai%^BOLD%^%^YELLOW%^nts R%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^ry%^RESET%^");
	set_long("%^BOLD%^%^YELLOW%^This rosary signifies your rank as a Throne within the Last Saints.%^RESET%^");
	break;
    }
}
