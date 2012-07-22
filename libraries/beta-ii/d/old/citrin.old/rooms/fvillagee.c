// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

int knock(string str);

void init() {
::init();
add_action("knock", "knock");
}
void create() {
::create();
set_name("Faerie Village");
set_long("The faeries that inhabit the treetops have the forest "
"have taken over the walkway.  Small houses sit on the walkway "
"making it hard to get through without knocking one down.  This "
"is the housing district of the faerie village.");
set_listen("default", "The sound of fluttering fill the air.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1, ]));
set_items(([
("house", "houses") : "There are many small houses linging "
"the path making the path small.  I bet those faeries "
"would be very pissed off if you were to knock there "
"house down.",
]));
set_exits(([
"southwest" : ROOMS"treetop7.c",
"northeast" : ROOMS"fvillage1.c",
]));

}

int knock(string str) {
if (str != "house") {
write("Knock what down?");
return 1;
} 
write("You have angered the faerie people.  A huge group of faeries "
"flood out of there houses.");
new(MON"faeriev.c")->move(this_object());
new(MON"faeriev.c")->move(this_object());
new(MON"faeriev2.c")->move(this_object());
new(MON"faeriev2.c")->move(this_object());
new(MON"faeriev2.c")->move(this_object());
new(MON"faeriev2.c")->move(this_object());
new(MON"faeriev2.c")->move(this_object());
new(MON"faeriev3.c")->move(this_object());
new(MON"faeriev3.c")->move(this_object());
new(MON"faeriev3.c")->move(this_object());
new(MON"faeriev3.c")->move(this_object());
new(MON"faeriev3.c")->move(this_object());
new(MON"faeriev4.c")->move(this_object());
return 1;
}
