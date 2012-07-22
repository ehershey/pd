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
	set_items((["writing" : " To some I am pure gold, \n I am every prisoner's right, \n No amount of me will hurt you, \n But answer and I am gone. \n What am I? \n",]));
	answer = "silence";
    }
    if (random==1)
    {
	set_items((["writing" : " My call is loud and clear, \n For I make sound with my tongue, \n But never will I draw a breath, \n For to do so I would need a lung. \n What am I?",])); 
	answer = "bell";
    }
    if (random==2)
    {
	set_items((["writing" : " I am never at rest, I can never be stopped. \n Fast I move, but never will I make a sound. \n I can never fly, swim or gallop, \n And I am invisible... unless you have help! \n What am I?",])); 
	answer = "sunlight";
    }
    if (random==3)
    {
	set_items((["writing" : " I am born round, yet no shape have I. \n If I draw breath, I am soured. \n My power comes from my age. \n Gone are your problems with me. \n What am I?",]));
	answer = "wine";
    }
    if (random==4)
    {
	set_items((["writing" : " Anywhere on this planet you can see me, \n But never can I be felt, \n I cannot move, but if you advance to me, \n I will retreat for evermore. \n What am I?",])); 
	answer = "horizon";
    }
    set_exits(([
	"south" : ROOMS"riddles5.c",
	"north" : ROOMS"endriddles.c",
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
