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
	set_items((["writing" : " A window I am, \n A lamp too, \n Maybe dark, \n Maybe clear, \n I live in white, \n I speak volumes, \n But no words will I say. \n What am I? \n",]));
	answer = "eye";
    }
    if (random==1)
    {
	set_items((["writing" : " I am a warrior in the flowers, \n My arm is a thrusting lance, \n I use it only when I must, \n To defend my golden treasure and my leader, \n But I go to the battle knowing I will certainly die. \n What am I?",])); 
	answer = "bee";
    }
    if (random==2)
    {
	set_items((["writing" : " I am a white bird, \n But no feathers have I, \n Flying from the heavens, \n Travelling miles only to die in your hand. \n What am I?",])); 
	answer = "snowflake";
    }
    if (random==3)
    {
	set_items((["writing" : " I am part of you, and then replaced. \n I flee your bodies, to a better place. \n Surrounded by me you will die, \n Have me and live, \n But lack me completely and you will die. \n What am I?",]));
	answer = "water";
    }
    if (random==4)
    {
	set_items((["writing" : " If chased by a dragon, \n I am the best thing to make, \n If made in important decisions, \n I will oft-times cause dispair. \n What am I?",])); 
	answer = "haste";
    }
    set_exits(([
	"south" : ROOMS"riddles4.c",
	"north" : ROOMS"riddles6.c",
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
