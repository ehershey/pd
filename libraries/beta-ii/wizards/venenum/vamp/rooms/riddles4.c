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
	set_items((["writing" : " Weight inside my belly, \n Trees upon on my back, \n Nails driven into my flanks, \n But feet I do not have. \n What am I?",]));
	answer = "boat";
    }
    if (random==1)
    {
	set_items((["writing" : " Some people will abuse me, \n Meanwhile other people will not, \n Some people remembered me, \n Some people have forgot. \n For boon or woe, \n I'm the greatest tool you will ever own, \n Yet I can't be held or touched. \n What am I?",])); 
	answer = "knowledge";
    }
    if (random==2)
    {
	set_items((["writing" : " When employed I'm useless, \n Once given in plenty, I am quick to annoy. \n Used oft in desperation, \n I am the false man's escape. \n What am I?",])); 
	answer = "excuses";
    }
    if (random==3)
    {
	set_items((["writing" : " When I am white I am acceptable, \n When I am used in malice my creator is scorned, \n I have broken hearts and broken minds, \n I am the tool of the weak man. \n What am I?",])); 
	answer = "lies";
    }
    if (random==4)
    {
	set_items((["writing" : " Alone I cannot move, \n I live with others of my kind, \n A tool of war, a tool of hunting, \n If I piece your heart you will be happy, \n If I piece your head you will not. \n What am I?",])); 
	answer = "arrow";
    }
    set_exits(([
	"south" : ROOMS"riddles3.c",
	"north" : ROOMS"riddles5.c",
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
