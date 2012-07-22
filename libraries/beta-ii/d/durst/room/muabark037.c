#include <std.h>
#include <durst.h>

inherit ROOM;

int Count;
int Door;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("The MuaBark Desert stretches off in all directions. Large sand dunes make it impossible to see very far in any direction. A powerful wind kicks sand into the air, making it difficult to breath.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			"west"			: ROOMS "muabark036.c",
			"southeast"		: ROOMS "muabark038.c",
			"southwest"		: ROOMS "muabark033.c",
		]));
		Count = 0;
        Door = 0;
}

void reset() {
   ::reset();

//if (children(MOB"md-nomad.c")==({})||
//    sizeof(children(MOB"md-nomad.c"))<7)
//     new(MOB "md-nomad.c")->move(this_object());

//if (!present("scorpion", this_object()))
//    new(MOB"md-scorpion.c")->move(this_object());
//if (!present("snake", this_object()))
//    new(MOB"md-snake.c")->move(this_object());
//if (!present("scorpion", this_object()))
//    new(MOB"md-scorpion.c")->move(this_object());

            Count = 0;
                if( Door != 0 )
                {
                        remove_exit("south");
                }
                Door = 0;

}

void init()
{
        ::init();
                Count++;
                if( Count > 5 )
                {
                        if( Door == 0 )
                        {
                                Door = 1;
				Count = 0;
                                add_exit(ROOMS "md-cave.c", "south");
                        }
                      
                       
                }
		
		if(Door == 1)
		{
			Door = 2;
		}
		else if(Door == 2)
		{
			Door = 3;
		}
		else if(Door == 3)
		{
			Count = 0;
			Door = 0;
			remove_exit("south");
		}
}


