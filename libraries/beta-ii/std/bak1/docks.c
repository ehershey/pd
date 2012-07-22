#include <std.h>
#include <daemons.h>
inherit PIER;

static string letter;

int *query_coords() { return OCEAN_D->query_coord_from_letter(letter); }

void set_letter(string str) { letter = str; }

void init() {
 ::init();
   add_action("boat_recall", "recall");
   add_action("boat_board", "board");
}

int boat_board(string str) {
   string file;
   object ob;
   int *i, *z;

   if (!str || str=="") {
     write("Board what?");
     return 1;
   }
   file = DIR_BOATS+"/"+str+".c";
   ob = get_object(file);
   if (!ob) {
     write("You dont see that boat.");
     return 1;
   }
   i = this_object()->query_coords();
   z = ob->query_xy();
   if ( i[0] != z[0] && i[1] != z[0] ) {
    write("You dont see that boat here.");
    return 1;
   }
   write("You board "+capitalize(str)+"'s boat.");
   this_player()->move_player(file, "on a boat");
   return 1;
}

int boat_recall(string str) {
 object ob;
 string st;
 int *i;

 st = DIR_BOATS+"/"+this_player()->query_name()+".c";
 if (file_size(st) < 0)
   return 0;

 ob = get_object(st);
 i = query_coords();
 ob->set_xy(i[0], i[1]);
 
 write("Your boat pulls into the docks.");
 return 1;
}
