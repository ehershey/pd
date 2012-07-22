#include <std.h>
#include <sp.h>

inherit ROOM;

int cmd_ring(string);

void create()
{
   ::create();
    set_short("The Inner Temple");
    set_long("%^ORANGE%^Very old symbols glow on the walls.  The material that this room is composed of is some sort of orange-gold rock. "
	"Many stone chairs surround a great blaze of fire.  An intense smoke rises from the fire and fills the room.  An archway to the north, "
	"decorated with thousands of tiny symbols, is protected by a divine force-field.  Three bells line the western wall.");
    
    set_items(([
          "bells" : "There are three different bells.  The smallest bell bears the gold-inlaid image of raging flames.  The "
		"medium sized bell is decorated with snowflakes of sapphire that have been deeply embedded.  The largest of "
                "the bells appears to be composed of a strange combination of sand and metal.",
          "walls" : "The walls glow with ancient symbols.",
	  "symbols" : "The symbols are ancient and unique looking.  They glow.",
	  "doorway" : "The doorway is fairly large, but it's just a black arch.  A dim light comes through.",
	  "chairs" : "The chairs are made of an orangey-gold rock.  They surround the great fire.",
	  "fire" : "Raging with life but not out of control, this great fire burns brilliantly to the side of the room.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "seekpal33.c",
    ]));
        
}

void init()
{
    ::init();
    add_action("cmd_ring", "ring");
    
}

int cmd_ring(string str)
{
    if(!str)
    {
    write("Ring what?\n");
    return 1;
    }
    //if(str != "large bell" || str != "medium bell" || str != "small bell")
    //{
    //write("Now why would you want to ring " + str + "!\n");
    //return 1;
    //}
    
    if(str == "large bell")
    {
           write("You ring the large bell and although the room is silent, a loud ringing fills your mind.");

   }
    if(str == "medium bell")
    {
           write("You ring the medium bell and although the room is silent, a loud ringing fills your mind.");
    }
    if(str == "small bell")
    {
           write("You ring the small bell and although the room is silent, a loud ringing fills your mind.");
    }
    
    //large, small, large, medium, large
    
    if(str == "large bell" && this_player()->query("bell_combo") == 0)
    {
           this_player()->set("bell_combo", 1);
    }
    else if(this_player()->query("bell_combo") == 1)
    {
         if(str == "small bell")
         {
                this_player()->set("bell_combo", 2);
         }
         else
         {
                this_player()->set("bell_combo", 0);    
         }
    }
    else if(this_player()->query("bell_combo") == 2)
    {
         if(str == "large bell")
         {
           this_player()->set("bell_combo", 3);
         }
         else
         {
           this_player()->set("bell_combo", 0);                 
         }
    }
    else if(this_player()->query("bell_combo") == 3)
    {
 
       if(str == "medium bell")
         {
           this_player()->set("bell_combo", 4);
         } 
         else
         {
           this_player()->set("bell_combo", 0);     
         }   
    }
    else if(this_player()->query("bell_combo") == 4)
    {
                if(str == "large bell")
        {
           this_player()->set("bell_combo", 0);
           write("%^YELLOW%^The sound of the bells echoes throughout your mind!");
           this_player()-> force_player ("sleep");
           this_player()->move_player( ROOMS  "seekpal35.c");
           
                }
                else
                {
           this_player()->set("bell_combo", 0); 
                }
    }
    
    return 1;
}
