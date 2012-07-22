#include <guild.h>
#include "ether.h"
inherit ETHERSTD;
int uncovered;
void init() {
     ::init();
     add_action("cmd_push", "push");
     add_action("cmd_lift", "lift");
     add_action("cmd_tattoo","tattoo");
}
void create() {
  ::create();
    set_short("Kumi's Room");
    set_day_long(
      "%^BOLD%^%^WHITE%^Kumi's Room%^RESET%^\n"
      "%^RESET%^%^WHITE%^A spectacular array of delicate %^RESET%^%^BOLD%^vanilla "
      "orchids%^RESET%^ %^WHITE%^adorn the room. The cream colored marble walls are "
      "garnished with exquisite %^RESET%^%^BOLD%^stephanotis%^RESET%^%^WHITE%^ blossoms. "
      "Brilliant rays of%^YELLOW%^s%^RESET%^%^ORANGE%^u%^RESET%^n%^BOLD%^l"
      "i%^RESET%^g%^ORANGE%^h%^YELLOW%^t%^RESET%^%^WHITE%^ beam down onto the room through "
      "the crystal ceiling. A tall ornate mirror stands alone in the corner of the room."
    );
    set_night_long( "%^BOLD%^%^WHITE%^Kumi's Room%^RESET%^\n"
                    "%^RESET%^%^WHITE%^A spectacular array of delicate %^RESET%^%^BOLD%^vanilla "
                    "orchids%^RESET%^ %^WHITE%^adorn the room. The cream colored marble walls are "
                    "garnished with exquisite %^RESET%^%^BOLD%^stephanotis%^RESET%^%^WHITE%^ blossoms. "
                    "%^BOLD%^Moonbeams%^RESET%^%^WHITE%^ and %^ORANGE%^starlights%^WHITE%^ cast a "
                    "beautiful glow in the room through the crystal ceiling. A tall ornate mirror "
                    "stands alone in the corner of the room." 
    );
    set_items(([
        "room" : "Can't you read the main description?",
        "mirror" : "A tall mirror that seems to be covering something.",
        "stephanotis" : "Beautiful white flowers that cover the walls.",
        "orchids" : "Tiny cream colored orchids which fill the room with the scent of vanilla.",
        "ceiling" : "A beautiful crystal ceiling",
    ]) );
    set_smell("default", "The soft smell of vanilla wafts pleasantly through the air.");
    set_listen("default", "Angelic chanting echoes through the room.");
    set_exits( ([
        "south" :  ROOMS "4-1.c",
    ]) );
    set_pre_exit_functions( ({"passage"}), ({"hidden_room_pre"}) );
}
void reset()

{

    if (!present("stuart")) {
new(MOB"stuart")->move(this_object());
         }
}
 int cmd_push(string str) {
     if(str != "mirror") {
         notify_fail("Look, unless you are going to push the mirror, go away.\n");
         return 0;
     }
     if(uncovered) {
         write("You push the mirror to the side and discover a hidden passage.");
         say((string)this_player()->query_cap_name()+" pushes the "+
           "mirror to the side.");
         remove_exit("passage");
         remove_item("passage");
         uncovered = 0;
         return 1;
     }
     else {
         write("You uncover a secret passage!");
         say((string)this_player()->query_cap_name()+" uncovers "+
           "a secret passage behind the mirror!");
         add_exit(ROOMS"4-2.2.c","passage");
         add_item("passage" , "It is really dark in there.", );
         uncovered = 1;
         return 1;
     }
 }    
int cmd_lift(string str) {
	if (str == "picture") {
		write("A drawer in the desk begins to open.\n"
			"%^BOLD%^%^WHITE%^A silk kimono climbs out of the drawer and floats in the air.%^RESET%^\n"
			"%^BOLD%^%^CYAN%^The kimono floats down toward you and wraps itself around your body.%^RESET%^\n"
		);
		say(""+this_player()->query_cap_name()+ " finds a silk kimono.\n");
		new(ARM"kimono")->move(this_player());
		this_player()->force_me("wear kimono");
        
		return 1;
	}
	return 0;
}

int hidden_room_pre() {
	write("%^BOLD%^%^WHITE%^You crawl through the tiny passageway into a small room. "
		"The mirror that you pushed falls back into place, nearly knocking you over.%^RESET%^");
	say("%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+ " crawls through a tiny hole. The mirror "
		"moves back into place.%^RESET%^");
	remove_exit("passage");
	remove_item("passage");
	this_player()->move(ROOMS"4-2.2");
	this_player()->describe_current_room(1);
        message(
		"environment", this_player()->query_cap_name()+
		" appears from nowhere.",environment(this_player()), 
		({ this_player()})
	);
	uncovered = 0;
	return 0;
}
int cmd_tattoo() {
   write("You find a strange tattoo on the floor.  You pick it up!\n");
   say(""+this_player()->query_cap_name()+" picks up something from the ground.\n");
   new(OBJ"tahn_tat")->move(this_player());
   this_player()->force_me("wear tattoo");
   return 1;
}
