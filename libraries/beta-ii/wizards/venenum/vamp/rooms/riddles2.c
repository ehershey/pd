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
	set_items((["writing" : " The moment you break me I am instantly fixed, \n Waiting to be broken again. \n More effort it will take to break me once more, \n Although many will try. \n What am I?",]));
	answer = "record";
    }
    if (random==1)
    {
	set_items((["writing" : " Tiny as an ant, \n Huge as a whale, \n You can't touch me, but you can change me. \n I can be frightening, although I can't hurt you. \n I will dance to any music, although I can't hear it. \n You can't run from me, but I'm afraid of the dark. \n What am I?",])); 
	answer = "shadow";
    }
    if (random==2)
    {
	set_items((["writing" : " Quite often held, but never touched, \n Always wet but never rusting, \n Often bites but seldom bit, \n To use me well you must have wit. \n What am I?",])); 
	answer = "tongue";
    }
    if (random==3)
    {
	set_items((["writing" : " Unlike a child, I cannot be seen, only heard. \n However, I will not speak unless spoken to. \n I can be strong and I can be weak, \n There is no language I cannot speak, \n But never of my own desire. \n What am I?",])); 
	answer = "echo";
    }
    if (random==4)
    {
	set_items((["writing" : " The first of me is a creature whose breeding is indeterminate. \n The second of me is a price you must forfeit. \n My entirety can be found in the river of Time and refers to events of this day. \n What am I?",])); 
	answer = "current";
    }
    set_exits(([
	"south" : ROOMS"riddles1.c",
	"north" : ROOMS"riddles3.c",
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
