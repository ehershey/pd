#include <std.h>
#include <venenum.h>
inherit ROOM;

int solved = 0;
int random=random(5);
string answer;

void create() {
    ::create();
    set_short("A long corridor");
    set_long("A long rectangular corridor stretches out north to south, constructed of grey stone bricks packed together with grey mortar. Clumps of mold dot the floor, walls and ceiling here, although their growth appears to be hampered by the lack of light. The corridor is perfectly straight with little apparent purpose and the end is impossible to see. A shimmering field appears to be blocking the exit to the north. There is writing engraved on the wall here.");
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
	set_items((["writing" : " My second is performed by my first, \n A thief by the marks of my whole might be caught. \n For always the more you take, \n Ihe more you leave behind. \n What am I?",]));
	answer = "footstep";
    }
    if (random==1)
    {
	set_items((["writing" : " My first is in the ocean but never in the sea, \n My second is in wasp but alas never in bee, \n My third is in glider and also in flight, \n My whole is a creature that comes out at night. \n What am I?",])); 
	answer = "owl";
    }
    if (random==2)
    {
	set_items((["writing" : " I have an iron roof, \n My walls are the clearest glass, \n I burn fiercely and bright, \n But never am I consumed. \n What am I?",])); 
	answer = "lantern";
    }
    if (random==3)
    {
	set_items((["writing" : " The greatest man never sees me, \n The king might once, \n A duke sees me frequently, \n The common man often does. \n What am I?",])); 
	answer = "equal";
    }
    if (random==4)
    {
	set_items((["writing" : " You may hear me but never catch me. \n You may make me but never see me. \n What am I?",])); 
	answer = "remark";
    }
    set_exits(([
	"south" : ROOMS"riddles2.c",
	"north" : ROOMS"riddles4.c",
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
