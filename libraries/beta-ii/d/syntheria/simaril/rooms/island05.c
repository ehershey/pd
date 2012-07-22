#include <std.h>
#include <simaril.h>

inherit ROOM;

int cocon = 0;

void create()
{
    ::create();
        set_name("small island");
        set_short("Small island");
        set_long("Large green plants are all around, reaching into the sky. "
                  "A thin sandy path runs through here, leading to the north and south. "
                  "Small insects buzz around, biting and biting and biting, ARGHHHH!!!"       
                );  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "forest"      : 1,
        ]) );
        set_items(([
        "island"    :   "A small island covered with lush greens.",
        "plants"    :   "A wide variety of green plant life that grows wild.",
        "tree"      :   "A huge tree that stretches into the sky. There looks like there might be something growing near the top of the tree. Maybe if you hit the tree some of them may fall.",
        ]));
            set_listen("default", "The island is silent, save for the occasional breeze.");
            set_smell("default", "Sea salt fills the air, masking all other smells.");
                set_exits(([
                        "north"             : ROOMS"island04.c",
                        "south"             : ROOMS"island06.c",                  
        ]));
        cocon = random(7); 
        new(OBJ"tree.c")->move(this_object()); 
}
 
void reset() {
   ::reset();
   cocon = random(7);

   
}
      
void init() {
        ::init();
                add_action("hit_tree", "kick");
}


int hit_tree(string str)
{
        object ob;
        if(!str)
                return notify_fail("kick what?\n");
        if(str != "tree")
                return notify_fail("You kick " +str+ "!\n");
        if(this_player()->query_disable()) 
            return notify_fail("You are too busy to kick the tree again!");
        this_player()->set_disable();
        if(cocon == 0)
        {
            message("target", "You kick the tree hard, but nothing falls from it.", this_player()); 
            message("target", ""+this_player()->query_cap_name()+" kicks the tree hard, but nothing happens.", environment(this_player()), this_player());
            return 1;
        }
        if(random(2) == 0)
        {
            message("target", "You kick the tree hard, but nothing falls from it.", this_player()); 
            message("target", ""+this_player()->query_cap_name()+" kicks the tree hard, but nothing happens.", environment(this_player()), this_player());
            return 1;
        }
        else
        {
            cocon = cocon - 1;
            ob = new(FOOD);
            ob->set_short("A large coconut");
            ob->set_long("A ripe coconut fresh from the tree.");
            ob->set_name("coconut");

            ob->set_id(({"coconut","large coconut", "food"}));
            ob->set_weight(5);
            ob->set_dis(1);
            ob->set_my_mess("You crack open the coconut and eat up its meat.");
            ob->set_your_mess("cracks open a coconut a feeds on the sweet meat inside.");
            ob->set_strength(random(25)+10);
            ob->move(environment(this_player()));

            if(random(10) == 5)
            {
                message("target", "You kick the tree hard, and a coconut falls, hitting you in the head!", this_player()); 
                message("target", ""+this_player()->query_cap_name()+" kicks the tree hard, and a coconut falls from above, knocking "+ this_player()->query_objective()+ " in the head!", environment(this_player()), this_player());
                this_player()->add_hp(-random(10));
            }
            else
            {
                message("target", "You kick the tree hard, and a coconut falls to the ground.", this_player()); 
                message("target", ""+this_player()->query_cap_name()+" kicks the tree hard, and a coconut falls to the ground.", environment(this_player()), this_player());
            }
        } 
        
        return 1;
}





