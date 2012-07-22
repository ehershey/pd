#include <std.h>
#include <venenum.h>
inherit ROOM;

int solved = 0;
int random=random(5);
string answer;

void create() {
    ::create();
    set_short("A long corridor");
    set_long("A long rectangular corridor stretches out north to south, constructed of grey stone bricks packed together with grey mortar. Clumps of mold dot the floor, walls and ceiling here, although their growth appears to be hampered by the lack of light. The corridor is perfectly straight with little apparent purpose and the end is impossible to see. There is writing engraved on the wall here.");
    set_smell("default", "It smells musty and dank here.");
    set_listen("default", "There are no sounds here.");
    set_no_clean(1);

    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
	"no_clean" : 1,
	"no clean" : 1,
      ]));

    if (random==0)
    {
	set_items((["writing" : " If you look, I cannot be seen. \n If you see me, you can see naught else. \n I can make you fly if you cannot. \n I can be true or I can be false. \n If I lie, I am close to the truth. \n What am I?",]));
	answer = "dreams";
    }
    if (random==1)
    {
	set_items((["writing" : " I am sable when you purchase me. \n I am crimson when you use me. \n When my purpose is done, I am grey. \n What am I?",])); 
	answer = "charcoal";
    }
    if (random==2)
    {
	set_items((["writing" : " Treasures yellow I contain, \n My guardians are many, \n Kept in a labyrinth where no human walks, \n Yet so often come to seize my gold. \n With smoke I am robbed, \n Left to build my riches anew. \n What am I?",])); 
	answer = "beehive";
    }
    if (random==3)
    {
	set_items((["writing" : " While a mirror reflects without speaking, \n I speak without reflecting. \n More fiction then fact, \n Some people will swear by me. \n What am I?",])); 
	answer = "gossip";
    }
    if (random==4)
    {
	set_items((["writing" : " I am a ship to be sure, \n with sailing both smooth and rough, \n Although I have no captain, \n I have two mates. \n What am I?",])); 
	answer = "courtship";
    }
    set_exits(([
	"south" : ROOMS"riddles.c",
	"north" : ROOMS"riddles2.c",
      ]));
    set_pre_exit_functions( ({"north"}), ({"check_riddle"}) );
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
    add_action("answer_riddle", answer);
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}

int check_riddle()
{
    if (solved == 1) {return 1;}
    else
    {
	write("A flash of light stop you from advancing further.");
    }
}

int close_exit()
{
    message("info", "A twinkling field winks into existance to the north.", this_object());
    set_long("A long rectangular corridor stretches out north to south, constructed of grey stone bricks packed together with grey mortar. Clumps of mold dot the floor, walls and ceiling here, although their growth appears to be hampered by the lack of light. The corridor is perfectly straight, with little apparent purpose, the end is impossible to see. A shimmering field appears to be blocking the exit to the north. There is writing engraved on the wall here.");
    solved = 0;
    return 1;
}

int answer_riddle()
{
    message("info", "The twinkling field to the north winks out of existance.", this_object());
    set_long("A long rectangular corridor stretches out north to south, constructed of grey stone bricks packed together with grey mortar. Clumps of mold dot the floor, walls and ceiling here, although their growth appears to be hampered by the lack of light. The corridor is perfectly straight, with little apparent purpose, the end is impossible to see. There is writing engraved on the wall here.");
    solved = 1;
    call_out("close_exit", 10);
    return 1;
}
