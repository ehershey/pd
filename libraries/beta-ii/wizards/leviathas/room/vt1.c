#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Cain's room.");
    set_day_long("________________________________"
                "|              _|_               |"
                "|>            | | |             <|"
                "|             | | |              |"
                "|           o | | | o            |"
                "|          ___| | |___           |"
                "|         |  Pri|mal  |          |"
                "|>        |_Dark|ness_|         <|"
                "|_____________|_|_|______________|");
  
  set_night_long("________________________________"
                "|              _|_               |"
                "|>            | | |             <|"
                "|             | | |              |"
                "|           o | | | o            |"
                "|          ___| | |___           |"
                "|         |  Pri|mal  |          |"
                "|>        |_Dark|ness_|         <|"
                "|_____________|_|_|______________|");

   
    
    set_items(([
	
    ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"south" : ROOMS "vtower3.c",
	"enter" : ROOMS "cainroom1.c",
    ]));
}


