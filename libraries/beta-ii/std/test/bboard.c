//      /std/bboard.c
//      from the Nightmare mudlib
//      a new, inheritable bulletin board
//      created by Descartes of Borg 06 march 1993

#include <teststd.h>
#include <move.h>
#include <daemons.h>
#include <bboard.h>

#define POST_DELAY_SECS 20
#define POST_DELAY_PROP "last_post_time"

inherit OBJECT;

int max_posts;
string location, board_id;
string *edit_ok;
mapping title;

int post_message(string str);

int is_board() { return 1; }

void init() {
    add_action("search_message", "search");
    add_action("remove_message", "remove");
    add_action("reply_message", "answer");
    add_action("post_message", "post");
    add_action("edit_message", "edit");
    add_action("read_message", "read");
}

int post_message(string str) {

    if ((int)this_player()->query(POST_DELAY_PROP)+POST_DELAY_SECS > time())
      return notify_fail("Posting limited to 1 every "+POST_DELAY_SECS+" seconds.\n");

    if(!title) title = ([]);
    if(!str) {
	notify_fail("You must give a title for your post.\n");
	return 0;
    }
    if(strlen(str) > 25) {
	notify_fail("Title cannot contain more than 25 characters.\n");
	return 0;
    }
    str=TERMINAL_D->no_colours(str);
    if((int)BBOARD_D->get_num_posts(board_id) >= max_posts) {
	//        notify_fail("You will first have to remove a note!\n");
	//        return 0;
	write("The board is full.  You will have to remove an earlier post to make a new post.");
	return 1;
	write("Seeing as the board is full, you remove the first note "
	  "on the board, then post yours.");
	BBOARD_D->remove_message(board_id, 0);
    }
    if(title[this_player()]) if(wizardp(this_player())) write("Warning! You are already marked as posting!\n");
    title[this_player()] = str;
    this_player()->edit(BBOARD_EDIT+(string)this_player()->query_name(), "postit", this_object());
    return 1;
}

int abort() {
   map_delete(title, this_player());
}

varargs int postit() {
    int x;

    x = (int)BBOARD_D->post_message(board_id, title[this_player()]);
    if(x == BBOARD_OK) {
      write("Posted.\n");
      this_player()->set(POST_DELAY_PROP, time());
    }
    else if(x == EDIT_ABORT) write("Edit aborted.\n");
    else if(x == BAD_DATA) write("Error in posting call.\n");
    map_delete(title, this_player());
    return 1;
}

int reply_message(string str) {
    int number;

    if(!title) title = ([]);
    if(!str) {
	notify_fail("Reply to which message?\n");
	return 0;
    }
    if((int)BBOARD_D->get_num_posts(board_id) >= max_posts) {
	notify_fail("You will first have to remove a note.\n");
	return 0;
    }
    if(sscanf(str, "%d", number) != 1) {
	notify_fail("Invalid message number.\n");
	return 0;
    }
    number --;
    str = (string)BBOARD_D->get_title(board_id, number);
    str = "Re: "+str;
    return post_message(str);
}

int edit_message(string str) {
    int number, x;

    if(!title) title = ([]);
    if(!str) {
	notify_fail("You must specify which message you wish to edit.\n");
	return 0;
    }
    if(sscanf(str, "%d", number) != 1) {
	notify_fail("Invalid message number.\n");
	return 0;
    }
    number --;
    title[this_player()] = (string)BBOARD_D->get_title(board_id, number);
    x = (int)BBOARD_D->edit_note(board_id, number);
    if(x==BBOARD_OK) {
	write(title[this_player()]+": "+number+"\n");
	write("Editing post.\n");
	this_player()->edit(BBOARD_EDIT+(string)this_player()->query_name(), "edit_stop_ed", this_object());
	return 1;
    }
    else if(x == INVALID_MSG) write("Invalid message number.\n");
    else if(x == ILLEGAL_ACCESS) write("You may only edit your own posts.\n");
    else write("Error in editing post.\n");
    map_delete(title, this_player());
    return 1;
}
void edit_stop_ed() {
    int x;

    x = (int)BBOARD_D->post_message(board_id, title[this_player()]);
    if(x == BBOARD_OK) write("Message edited.\n");
    else write(title[this_player()] + " "+x+"\n");
    map_delete(title, this_player());
    rm((string)this_player()->query_edit_filename());
}


int remove_message(string str) {
    int number, x;

    if(!str) {
	notify_fail("You must specify which note you wish to remove!\n");
	return 0;
    }
    if(sscanf(str, "%d", number) != 1) {
	notify_fail("Invalid message number!\n");
	return 0;
    }
    number --;
    x = (int)BBOARD_D->remove_message(board_id, number);
    if(x==BBOARD_OK) write("Message "+(number+1)+" removed.\n");
    else if(x == INVALID_MSG) write("Invalid message number.\n");
    else if(x == ILLEGAL_ACCESS) write("You may only remove your own posts.\n");
    else write("Error "+x+" in removing post.\n");
    return 1;
}

int search_message(string str) {
   int id, i, ok;
   string seed, out="";
   mixed *m;
   mapping msg, m2;
   if(!str || str == "") return 0;
   if(sscanf(str, "%d %s", id, seed) == 2) {
     msg = BBOARD_D->get_message(board_id, id-1);
     if(!msg) { write("No such message.");  return 1; }
     write("Search message #"+id+" \""+msg["title"]+"\" by "+msg["owner"]+"");
     m = explode(msg["message"], "\n");
     for(i=0; i<sizeof(m); i++) {
       if(strsrch(m[i], seed) != -1) {
         if(i < 10)
           out+="[  "+(i+1)+"] "+m[i]; else
         if(i < 100) 
           out+="[ "+(i+1)+"] "+m[i]; else
         out+="[  "+(i+1)+"] "+m[i];
         out+="\n";
         ok++;
       }
       if(ok > 20) { write("Your search returned too many results.  Try refining your query and try again."); }
     }
     if(!ok) { write("No text found."); } else { write(out); return 1; }
   }
   i=(int)BBOARD_D->get_num_posts(board_id);
   if(sscanf(str, "user %s", seed)) {
     m=({});
     seed=lower_case(seed);
     while(i--) {
       msg = BBOARD_D->get_message(board_id, i);
       if(msg["owner"] == seed) {
         msg["id"]=i;
         m += ({ msg });
      }
     }
     if(!sizeof(m)) write("Your search returned no matches."); else {
       i=sizeof(m);
       while(i--) {
     if(m[i]["id"] < 10)
       out += "[  "+(m[i]["id"]+1)+"] "; else
     if(m[i]["id"] < 100)
       out += "[ "+(m[i]["id"]+1)+"] "; else
       out += "["+(m[i]["id"]+1)+"] ";
     out += " \""+m[i]["title"]+"\" by "+m[i]["owner"]+"\n";
       }     
     }
     write("The following posts were posted by "+seed+"\n"+out);

     return 1;
   }
   m=({});
   while(i--) {
     msg = BBOARD_D->get_message(board_id, i);
     if(strsrch(msg["title"], str) != -1) 
       m += ({ (["owner":msg["owner"], "title":msg["title"], (int)"id":i]) }); else
     if(strsrch(msg["message"], str) != -1) 
       m += ({ (["owner":msg["owner"], "title":msg["title"], "id":i]) });
   }
   if(!m || m == ({}) || !sizeof(m)) return 0;
   i=sizeof(m);
   write("The following posts contain \""+str+"\":");
   while(i--) {
     m2=m[i];
     if(m[i]["id"] < 10)
       out += "[  "+(m[i]["id"]+1)+"] "; else
     if(m[i]["id"] < 100)
       out += "[ "+(m[i]["id"]+1)+"] "; else
       out += "["+(m[i]["id"]+1)+"] ";
     out += " \""+m[i]["title"]+"\" by "+m[i]["owner"]+"\n";
   }
   write(out);
   return 1;
}

int read_message(string str) {
    int number;
    mapping msg;
    string *lines;

    if(!str)
	number = 1 + (int)BBOARD_D->get_new_post(board_id, (string)this_player()->query_name());
    else if(sscanf(str, "%d", number) != 1) {
	notify_fail("Invalid message number.\n");
	return 0;
    }
    msg = (mapping)BBOARD_D->get_message(board_id, number-1);
    if(!msg) {
	notify_fail("Invalid message number.\n");
	return 0;
    }
    lines = ({ "Message "+number+" by "+capitalize(msg["owner"])+": \""+TERMINAL_D->no_colours(msg["title"])+"\""
      "\n%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^" });
    lines += explode(msg["message"], "\n");
    lines += ({ "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^" });
    this_player()->more(lines);
    BBOARD_D->set_read(board_id, (string)this_player()->query_name(), number-1);
    return 1;
}

string query_short()
{
    string seeker;
    int posts, tot, act;

    tot = (int)BBOARD_D->get_num_posts(board_id);
    /* changed from get_new_post to get_num_read --stranger 20000609 */
    posts = (int)BBOARD_D->get_num_read(board_id, (string)this_player()->query_name());
    if (posts==-1)
    {
	tot = 0;
	posts = 0;
    }
    seeker = ::query_short();
    act = (tot-posts); 
    seeker += " %^RED%^%^BOLD%^< %^RESET%^%^RED%^"+act+"%^BOLD%^%^BLUE%^ Unread,%^RESET%^ %^RED%^"+tot+"%^BOLD%^%^BLUE%^ Posts %^RESET%^%^RED%^%^BOLD%^>%^MAGENTA%^";

    return seeker;
}
string query_long(string junk) {
    string borg;

    borg = "\n\n%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]%^BLUE%^------------------------%^BOLD%^(%^RESET%^ %^BOLD%^Board Commands %^BLUE%^}------------------------%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]\n";
    borg += "%^BOLD%^%^BLUE%^|%^RESET%^    <post [title]> <edit [#]> <read [(#)]> <answer [#]> <remove [#]>  %^BOLD%^%^BLUE%^|\n";
    borg += "%^BOLD%^%^BLUE%^|%^RESET%^      <search user [user]> <search [post] [what]> <search [what]>     %^BOLD%^%^BLUE%^|\n";
    borg += "%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]%^BOLD%^%^BLUE%^------------------------------------------------------------------%^CYAN%^%^BOLD%^[%^WHITE%^*%^CYAN%^]\n";
    borg += "\n"+::query_long(0)+"\n";

    borg += "There are "+(int)BBOARD_D->get_num_posts(board_id)+" message"+(BBOARD_D->get_num_posts(board_id)==1?"":"s")+" posted.\n";
    borg += (string)BBOARD_D->display_board(board_id);
    return borg;
}

void set_board_id(string str) {
    //    if(board_id) return;
    board_id = str;
}

string query_board_id() { return board_id; }

void set_max_posts(int x) { max_posts = x; }

int query_max_posts() { return max_posts; }

void set_location(string file) {
    if(location) return;
    location = file;
    ::move(location);
}

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

int get() { return 0; }

int drop() { return 1; }

void set_edit_ok(string *who) {
    if(!who) edit_ok = ({});
    else edit_ok = who;
}

string *query_edit_ok() {
    if(!edit_ok) return ({});
    return edit_ok;
}

void clean_up() { return; }

