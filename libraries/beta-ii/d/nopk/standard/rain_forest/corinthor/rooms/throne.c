//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;
int king;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Throne Room");
     set_day_long("The throne room of Corinthor is where the King and his council spend the day ruling the forest. The throne is at the very back of the room, with the floor around it worn smooth by the shuffling of the council. The sky can plainly be seen above through the tops of the trees, the sun shining bright.");
     set_night_long("The throne room of Corinthor is where the King and his council spend the day ruling the forest. They are often here working well into the night, with the moon and stars shining down through the open treetops. The throne is set at the back of the room and is made of carved wood.");
     set_exits(([
		"south"		: ELFROOM"palacem5.c",
		"southwest"	: ELFROOM"palacew4.c",
		"southeast"	: ELFROOM"palacee4.c"
                ]));
     set_items(([
        ]));
     new(ELFOBJ"throne.c")->move(this_object());
}

void reset() {
   ::reset();
     if(!present("knight"))
       new(ELFMOB"knight.c")->move(this_object());
     if(!present("council"))
       new(ELFMOB"council.c")->move(this_object());
     if(!present("council 2"))
       new(ELFMOB"council.c")->move(this_object());
     if(!present("council 3"))
       new(ELFMOB"council.c")->move(this_object());
     if(!present("king"))
       new(ELFMOB"king.c")->move(this_object());
}

void init() {
   ::init();
     add_action("kingme", "wield");
}

int kingme(string str) {
    string kq;
    if(king == 1) return 0;
    if(str != "moonblade") return 0;
    if(!present("moonblade", this_player())) return 0;
    if(!present("council", this_object())) return 0;
    if(this_player()->query_gender() == "male") kq = "Lord";
    else kq = "Lady";
    message("info", "The council declare you "+kq+" of the Forest.", this_player(), );
    message("info", capitalize(this_player()->query_name())+" is declared "+kq+" of the Forest.", users(), this_player());
    return 0;
}
