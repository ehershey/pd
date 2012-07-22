
#include <std.h>

inherit BARKEEP;

void create() {
  ::create();
  set_property("no bump", 1);
  set_property("passive", 1);
  set_id( ({ "man", "vendor", "cart vendor", "cart" }) );
  set_name("cart vendor");
  set_short("A man pushing a cart around town");
  set_long(
    "This street vendor pushes his cart back and forth, selling some "
    "exotic food and drink to anyone who will buy it. A sign on the cart "
    "lists the things for sale."
  );
  set_aggressive(0);
  set_level(20);
  set_patrol(16, ({
    "west", "west", "west", "west", "west", "west", "west", "west", "west",
    "east", "east", "east", "east", "east", "east", "east", "east", "east",
    "east", "east", "east", "east", "east", "east", "east", "east",
    "west", "west", "west", "west", "west", "west", "west", "west",
  }) );
  set_emotes(4, ({ "A bell rings on the cart." }), 0);
  set_speech(1, "mexican", ({ "Hey, you want to buy something?" }), 0);
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_languages( ({ "mexican" }) );
  set_currency("gold");
  set_read( ({ "sign", "cart", "default" }), query_read("menu") );
  set_automenu( ({ "sign", "cart" }) );
  set_menu_header("Bienvenidos!");
  set_menu_footer("Muchas delicias!");
  set_menu(  ([
    "horchata" : ([
      "type" : "soft drink",
      "strength" : 40,
      "long" : "A sweet, milky drink with cinnamon in it.",
      "short" : "A cup of horchata",
      "my_mess" : "Mmm, just sweet enough.",
      "empty_name" : "cup",
    ]),
    "cerveza" : ([
      "type" : "alcoholic",
      "strength" : 25,
      "long" : "A bottle of beer.",
      "my_mess" : "You enjoy the light flavor of the cerveza.",
      "your_mess" : "enjoys a cerveza.",
    ]),
    "tequila" : ([
      "type" : "alcoholic",
      "strength" : 85,
      "long" : "An ominous looking shot of pale alcohol.",
      "short" : "A shot of tequila",
      "my_mess" : "You down the tequila, then dance around like an idiot for everyone to see!",
      "your_mess" : "downs some tequila, then dances around like an idiot for everyone to see!",
      "empty_name" : "shot glass",
    ]),
    "taco" : ([
      "type" : "food",
      "strength" : 16,
      "long" : "A crunchy little tortilla filled with lettuce, beans, rice, cheese, and beef.",
      "short" : "crunchy taco",
    ]),
    "burrito" : ([
      "type" : "food",
      "strength" : 42,
      "long" : "Piping hot, this is a soft tortilla wrapped up and filled with rices, beans, "
        "and other delicious extras.",
    ]),
    "chile relleno" : ([
      "type" : "food",
      "strength" : 30,
      "long" : "A chile filled with cheese, covered in batter, and fried.",
      "my_mess" : "The cheese oozes out as you much on the chile relleno.",
      "your_mess" : "munches on a chile relleno as cheese oozes out of it.",
    ]),
    "enchilada" : ([
      "type" : "food",
      "strength" : 23,
      "long" : "This filled corn tortilla has been drenched in chile sauce.",
    ]),
    "paleta" : ([
      "type" : "food",
      "strength" : 11,
      "long" : "A sort of frozen fruit ice pop, it's a wonder it doesn't melt.",
      "my_mess" : "You slurp on the paleta until it's all gone.",
      "your_mess" : "slurps on a paleta until it's all gone.",
    ]),
  ]) );
}

