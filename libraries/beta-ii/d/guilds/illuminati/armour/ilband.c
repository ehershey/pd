#include <std.h>
#include <daemons.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("Illuminati band");
    set_short("Member's Band");
    set_long("If you are a Hero, Legend, or Immortal, you may wear this as a show of rank.");
    set_id(({ "bronze band", "silver band", "gold band", "band"}));
    set_ac(1);
    set_weight(2);
    set_curr_value("gold", 150);
    set_type("bracelet");
    set_limbs(({"right hand", "left hand"}));
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati") return 1;
    return 0;
}

void init() {
    ::init();
    if(environment(this_object())->is_player()) {
	if(this_player()->query_guild() != "illuminati") {
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
	set_name("Metal band");
	set_short("Metal Band");
	set_long("This metallic band signifies your rank as a Mortal in the Illuminati.");
	break;
    case "member" :
	set_name("bronze band");
	set_short("%^ORANGE%^Br%^RESET%^on%^ORANGE%^ze B%^RESET%^an%^ORANGE%^d%^RESET%^");
	set_long("This bronze band signifies your rank as a Hero in the Illuminati.");
	break;
    case "council" :
	set_name("silver band");
	set_short("%^BOLD%^WHITE%^S%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r %^BOLD%^b%^RESET%^a%^BOLD%^n%^RESET%^d");
	set_long("This silver band signifies your rank as a Legend in the Illuminati.");
	break;
    case "leader" : case "main" :
	set_name("gold band");
	set_short("%^ORANGE%^G%^YELLOW%^ol%^WHITE%^d b%^YELLOW%^an%^RESET%^ORANGE%^d%^RESET%^");
	set_long("This gold band signifies your rank as an Immortal in the Illuminati.");
	break;
    }
}

void removeme() {
    this_object()->remove();
}

int report_posts() {
    int tot, unread, read;
    tot = BBOARD_D->get_num_posts("Illuminati_Tower_Board");
    read = BBOARD_D->get_num_read("Illuminati_Tower_Board", this_player()->query_name());
    if(read == -1) {
	tot = 0;
	read = 0;
    }
    unread = (tot - read);
    if(unread == 1)
	message("info", "\n                  %^YELLOW%^< %^WHITE%^"+unread+" unread post of "+tot+" on Illuminati board %^YELLOW%^>%^RESET%^\n", this_player());
    else
	message("info", "\n                  %^YELLOW%^< %^WHITE%^"+unread+" unread posts of "+tot+" on Illuminati board %^YELLOW%^>%^RESET%^\n", this_player());
    return 1;
}

int read_board(string str) {
    int number;
    mapping msg;
    string *lines;

    if(!str)
	number = 1 + BBOARD_D->get_new_post("Illuminati_Tower_Board", this_player()->query_name());
    else if(sscanf(str, "%d", number) != 1)
	return notify_fail("Invalid message number.\n");
    msg = BBOARD_D->get_message("Illuminati_Tower_Board", number-1);
    if(!msg)
	return notify_fail("Invalid message number.\n");

    lines = ({ "\nMessage "+number+" by "+capitalize(msg["owner"])+": \""+TERMINAL_D->no_colours(msg["title"])+"\""
      "\n%^RESET%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^" });
    lines += explode(msg["message"], "\n");
    lines += ({ "%^RESET%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n%^RESET%^" });
    this_player()->more(lines);
    BBOARD_D->set_read("Illuminati_Tower_Board", this_player()->query_name(), number-1);
    return 1;
}

int give() { write("You may not give this away."); return 1; }

int drop() { write("Whatever for?"); return 1; }
