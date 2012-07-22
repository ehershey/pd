#include <std.h>
#include <security.h>
#include <daemons.h>

#define NEWWIZ "/wizards/newwiz/"
inherit DAEMON;

int cmd_addimm(string str) {
 object ob;
 string wiz;

  if (!archp(this_player())) return 0;
  if (!ob=find_player(str))
    return notify_fail("That player isnt on to be immortalized.\n");
  
  if (wizardp(ob))
    return notify_fail("That person is already a wizard!\n");
  wiz = "/wizards/"+ob->query_name()+"/";
  seteuid(UID_CRESAVE);
  if (file_size(wiz) != -2)
    {
     
     mkdir(wiz);
     mkdir(wiz+"arm");
     cp( NEWWIZ+"arm/wond_boots.c", wiz+"/arm/");
     mkdir(wiz+"item");
     cp( NEWWIZ+"item/cabinet.c", wiz+"/item/");
     mkdir(wiz+"mob");
     mkdir(wiz+"room");
     cp( NEWWIZ+"room/newhouse.c", wiz+"/room/");
     cp( NEWWIZ+"room/workroom.c", wiz);
     cp( NEWWIZ+"new_wiz.c", wiz+"/");
  }
 if (file_size(wiz+"workroom.c") < 0)
   cp ( NEWWIZ+"workroom.c", wiz+"/");
 
    seteuid(UID_LOG);
    log_file("addimm", sprintf("%s is now an immortal",(string)ob->query_name()));
    seteuid(getuid());
    seteuid(UID_ADVANCE);
    ob->set_position("wizard");
    seteuid(getuid());
    ob->set_level(1000);
     write("--- "+ob->query_cap_name()+" is now an immortal.");
   ob->force_me("cd ~");
   message("info", "You are now an immortal on Primal Darkness Builders!", ob);


  return 1;
    
 
}
void help() {
    message("help",
        "Syntax: <watch [site|name] [ip or site to be watched]>\n\n"
        "Sets it up so that whenever a player of a certain name, or "
        "a player from a certain site logs in it will get logged.  "
        "Examples: watch name forlock    watch site 134.181.*\n\n"
        "See also: unwatch, whowatched", this_player()
    );
}
