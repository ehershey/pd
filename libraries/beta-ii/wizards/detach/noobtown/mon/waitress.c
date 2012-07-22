#include <std.h>
#include <radyne.h>
inherit "/std/barkeep";

void create() {
 ::create();
   set_name("waitress");
   set_id( ({"waitress","bunny waitress"}) );
   set_short("A Bunny Waitress");
   set("aggressive", 0);
   set_level(12);
   set_long(
     "A friendly waitress hired to serve with a smile. She is wearing "
     "sleek bunny outfit to ammuse the customers."
   );
   set_gender("female");
   set_alignment(164);
   set("race", "nymph");
   set_body_type("human");
   add_money("gold", random(40));
   new(ARM"b_suit.c")->move(this_object());
   new(ARM"b_ears.c")->move(this_object());
   force_me("wear all");
   set_skill("melee", 90);
   set_hp(300);
   set_currency("gold");
   set_menu(
	({
        "fillet","drumstick","soup","salad","peaches"
	}),
	({ "food", "food", "food", "food", "food" }),
	({ 25, 15, 20, 3, 10 })
    );
    set_my_mess(
	({
        "Red meat served rare, eaten with your hands. Yum!\n",
        "You suck the meat away and toss away the bone.\n",
       "Mmm. Nothing like soup to warm your soul.\n",
        "You delight in the leafy green vegetables.\n",
        "You slurp down your cubed peaches in thick syrup.\n"
	})
    );
    set_your_mess(
	({
        "eats some red meat with his hands.\n",
        "chews off the last bit of meat from a drumstick and tosses away the bone.\n",
        "enjoys some warm soup.\n",
        "delights in some leafy green veggies.\n",
       "sucks down some peaches in thick syrup.\n"
    	})
    );
    set_menu_short(
	({
        "rare fillet",
        "turkey drumstick",
        "veggie soup",
        "nova salad",
         "peaches in thick syrup"
	})
    );
    set_menu_long(
	({
     "A slab of red, rare meat, it looks good enough to eat.\n",
      "The leg of an unfortunate turkey, the meal of a happy customer.\n",
     "Vegetable broth with extra seasoning.\n",
     "Vegetarian Special: It's so green and tempting.\n",
     "Ripe peaches drenched in thick, sweet syrup.\n"
   	})
    );
}
