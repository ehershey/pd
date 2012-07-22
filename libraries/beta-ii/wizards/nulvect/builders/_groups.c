
#include <std.h>

inherit DAEMON;

int CHECK_GROUP(mapping groups,string str);
int cmd_groups(string str) {
      string label;

     mapping groups=master()->query_groups();
      string *lists=sort_array(keys(groups),-1);
      string *club;
         int countera=sizeof(lists);

    if(!str) {

       for(countera;countera>0;countera--) {
           club=({});
          label=lists[countera-1];
           club=sort_array((groups[label]),1);

         write("%^GREEN%^%^BOLD%^Group name :: %^RED%^%^BOLD%^"+label+"%^CYAN%^%^BOLD%^");
         write(format_page(club,4));
                   } // End for loop
         return 1; } // end listing of ALL groups if no str is entered
    else {
       CHECK_GROUP(groups,str);
       return 1; }

}

int CHECK_GROUP(mapping groups,string str) {
          string *club=groups[str] ? sort_array((groups[str]),1) : ({"%^CYAN%^%^BOLD%^No such group%^RESET%^"});

         write("%^GREEN%^%^BOLD%^The Group you requested, %^RED%^%^BOLD%^"+str+"%^GREEN%^%^BOLD%^, has the following members;%^RESET%^");
         write(format_page(club,4));

return 1; } // end listing for as single membership group
