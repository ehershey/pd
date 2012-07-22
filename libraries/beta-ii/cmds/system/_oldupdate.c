//      /bin/system/_update.c
//      from the Nightmare Mudlib
//      destructs an old version of a file and loads a new one
//      created by Sulam 911219
//      security changes by Descartes of Borg 930810

#include <std.h>
#include <rooms.h>
#include <security.h>
#include <move.h>
#include <daemons.h>

inherit DAEMON;

int cmd_oldupdate(string str) {
    object *ob;
    object obb, ob2;
    string file, res, *deep;
    int n, master_flag, i;
  
    IMSTAT_D->add_stat(this_player()->query_name(), "update", time());
    if(!str) {
        if(!environment(this_player())) {
            write("No environment!");
            return 1;
        }
        obb = environment(this_player());
        file = file_name(obb);
        message("Nsystem", "Update environment ("+file+"): ", this_player());
        ob = all_inventory(obb);
        for (n = 0; n < sizeof(ob); n++)
        {
            if (ob[n]->is_player()) ob[n]->move(ROOM_VOID);
        }
        seteuid(getuid(previous_object()));
        destruct(obb);
        seteuid(UID_SYSTEM);
        if(this_player()->move(file) != MOVE_OK) 
          message("system", "Error in loading file.", this_player());
        for (n = 0; n < sizeof(ob); n++)
        {
	    if( ob[n] ) /* something may have happened during the update */
		ob[n]->move(environment(this_player()));
        }
        message("system", "Ok.", this_player());
        return 1;
    }
  
 if (sscanf(str, "-a %s", str))
   {
    write("Updating all files directly/indirectly related to this object.");
    str = resolv_path((string)this_player()->get_path(), str);
    ob2 = find_object(str);
    if (!ob2) return notify_fail("Couldnt update "+str+"\n");
    deep = ({ str });
    i = sizeof(deep += deep_inherit_list(ob2));
    while(i--)
     {
      ob2 = find_object( deep[i] );
     if (ob2) { 
      res = catch(ob2->remove());
      if(res) message("system", deep[i]+": error in remove()", this_player());
      if(res) return 1;
     }

    if (ob2) {
      seteuid(getuid(previous_object()));
      destruct(ob2);
     }

    if(!find_object(deep[i])) {
        file_size(deep[i]);
        message("system",deep[i]+": "+((res=catch(call_other(deep[i],"???"))) ?
          res : "updated and loaded."), this_player());
      }
      else {
        notify_fail(deep[i]+": couldn't destruct\n");
        return 0;
       }

   }
    return 1;
   }
    str = resolv_path((string)this_player()->get_path(), str);
/* Have to do special things for the master object */
    if((ob2 = find_object(str)) == master()) master_flag = 1;
    if(ob2) {
        res = catch(ob2->remove());
        if(res)
          message("system", str+": error in remove()", this_player());
        if(ob2) {
            seteuid(getuid(previous_object()));
            destruct(ob2);
            if(!master_flag) seteuid(UID_SYSTEM);
        }
    }
    if(!find_object(str)) {
        file_size(str);
        message("system", str+": "+((res=catch(call_other(str,"???"))) ?
          res : "updated and loaded."), this_player());
        if(master_flag) seteuid(UID_SYSTEM);

    }
    else {
        notify_fail(str+": couldn't destruct\n");
        return 0;
    }
    return 1;
}

void help() {
    message("help",
      "Syntax: <update [file]>\n\n"
      "Destructs the master object of the file named and then attempts "
      "to reload a new version of it.\n\n"
      "See also: call, clone, cref, dest, dref, load, renew", this_player()
    );
}
