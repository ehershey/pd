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
		set_long("A large cyclone of sand makes navigation very difficult. The air is as thick as the sand below, breathing seems impossible. Death seems certain in this endless desert.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			
			
			"northwest"		: ROOMS "muabark065.c",
			"southeast"		: ROOMS "muabark063.c",
			"north"		: ROOMS "muabark072.c",
			
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
                        remove_exit("east");
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
                                add_exit(ROOMS "md-ice-cavern.c", "east");
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
			remove_exit("east");
		}
}
