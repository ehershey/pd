inherit "/std/barkeep";

void create() {
    ::create();
    set_name("rocko");
    set_id( ({ "rocko", "barkeep" }) );
    set_short("Rocko, the barkeep");
    set("aggressive", 0);
    set_level(12);
    set_long("He will sell you a drink, but he won't put up with your crap. Rocko is "
      "huge, even for a half-orc. He is strong, but quite ugly.");
    set_gender("male");
    set_alignment(-232);
    set("race", "half-orc");
    set_hp(480);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
set_menu( ([
  "whiskey" : ([
    "type" : "alcoholic",
    "strength" : 35,
    "my_mess" : "The whiskey burns your throat!",
    "short" : "whiskey",
    "long" : "A shot of whiskey from the Brigand's Pub.",
  ]),
  "ale" : ([
    "type" : "alcoholic",
    "strength" : 25,
    "short" : "Assassin's ale",
    "long" : "A tasty looking glass of assassin's ale.",
    "my_mess" : "Mmmmm good.",
  ]),
  "pretzel" : ([
    "type" : "food",
    "strength" : 11,
    "my_mess" : "Munchin' on a pretzel.",
    "long" : "A huge, salty pretzel.",
  ]),
]) );
    new("/d/nopk/standard/obj/weapon/warblade.c")->move(this_object());
    command("wield warblade");
}
