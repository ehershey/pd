#include <std.h>
#include <waterworld.h>

inherit "std/barkeep";

void toss_out(object tp);

void create() {
    ::create();

    /// standard info
    set_name("Pelican Pete");
    set_id(({"pelican pete","pelican","pete"}));
    set_race("pelican");
    set_level(25);
    set_short("%^WHITE%^%^BOLD%^Pelican Pete%^RESET%^%^RED%^, Tirun Bay's Feathered bartender...");
    set_long("A stocky looking Pelican perched on the side of the bar. He bears the tattoo of the '%^ORANGE%^%^BOLD%^Screaming Pelicans%^RESET%^', a gang from this area.\nHe is busy mixing drinks for his clients.");
    set_gender("male");
    set_class("fighter");
    set_subclass("ranger");
    set_body_type("bird");
    set_exp(100);
    set_property("passive", 1);

    set_emotes(3,({
	"Pelican Pete cuts some coconuts in half for the %^YELLOW%^Pina Coladas.%^RESET%^",
	"Pete carfully prepares some pelican egg shells for the %^RED%^BOLD%^Flaming Pelicans.%^RESET%^",
	"Pete clears the bar of empty glasses."
      }),0);

    new(ARMOR1"apron.c")->move(this_object());
    force_me("wear all");

    ///// bar routines
set_menu( ([
  "pina colada" : ([
    "type" : "alcoholic",
    "strength" : 22,
    "servings" : 3,
    "long" : "%^BOLD%^WHITE%^%^B_BLUE%^A Pina colada%^RESET%^ "
      "in a coconut shell.",
    "my_mess" : "You slowly sip on your pina colada.",
    "your_mess" : "sips slowly on a pina colada.",
    "empty" : "coconut shell",
  ]),
  "margarita" : ([
    "type" : "alcoholic",
    "strength" : 13,
    "servings" : 3,
    "long" : "A %^RED%^margarita%^RESET%^ freshly mixed by Pelican Pete.",
    "my_mess" : "You chug your margarita in one shot.",
    "your_mess" : "chugs a margarita in one shot.",
    "empty" : "shot glass",
  ]),
  "flaming pelican" : ([
    "type" : "alcoholic",
    "strength" : 39,
    "servings" : 1,
    "long" : "A world famous %^RED%^%^BOLD%^Flaming Pelican%^RESET%^ "
      "straight from Pelican Pete in Tirun Bay.",
    "my_mess" : "The potent drink makes you hallucinate... "
      "You feel like you're flying...",
    "your_mess" : "drinks a flaming pelican and seems to hallucinate.",
    "empty" : "pelican egg shell",
  ]),
  "speedy tourtoise" : ([
    "type" : "alcoholic",
    "strength" : 80,
    "servings" : 1,
    "long" : "A custom shot made for Quessalaz from Pelican Pete.",
    "my_mess" : "Everything around you slows to a "
      "%^GREEN%^turtle's speed%^RESET%^...",
    "your_mess" : "drinks a speedy tourtoise and zones out.",
    "empty" : "shot glass",
    "hidden" : 1,
    "price" : 150,
  ]),
]) );
    set_currency("gold");
}

int is_invincible() {
    object TP;
    string cap_TP;
    TP=previous_object();
    cap_TP=TP->query_cap_name();

    message("info","\nPelican Paul crashes into YOU!!\nYou are hurled outta the bar!!",TP);
    message("info","\nPelican Paul crashes into "+cap_TP+"!!\n"+cap_TP+" is hurled outta the bar!!",environment(TP),TP);
    call_out("toss_out", 0, TP);
    message("info",(TP->query_cap_name())+" falls into the water before you with a big %^BLUE%^%^BOLD%^SPLASH!!%^RESET%^",environment(TP),TP);
    message("info","You fall into the water north of the bar with a big %^BLUE%^%^BOLD%^SPLASH!!%^RESET%^",TP);
    TP->set_paralyzed(2, "You are stunned from the landing.", "You splash your way back to your feet.");
    return 1;
}
void toss_out(object tp) { tp->move(ROOMS1"room-1d3"); }
