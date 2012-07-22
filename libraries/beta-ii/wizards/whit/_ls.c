//  Forsaken Mudlib v1.0
//  Part of the Forsaken Mudlib Development Project
//  Creator: Whit
//  Name: Ls Command
//  Purpose: Returns the files in a given directory

#define SPACER 10
#define UNLOAD "  "
#define LOAD "* "
#include <std.h>
#include <daemons.h>
inherit DAEMON;

string align(string strtmp, int i) {
	int x, r, tmp;
	string out, str;
	str=strip_color(strtmp);
	x = sizeof(str);
	out = "";
	if(i==x) return str;

	if(x > i) return strtmp[0..i-1];

	r = i-x;
	out = strtmp;
	if(!out) out="";
	while(r--) {
		if(!out) out = " ";
		else out += " ";
	}
	return out;
}

varargs string format_p(string *str, int cols) {
   string out, *ex, a, b;
   int tmp, tmp2, co, tmp3;
   if(!cols) cols = 2;
   out = "";
   ex = ({});
   tmp = sizeof(str);
   tmp2 = 30;


   while(tmp--) if(sizeof(str[tmp]) > tmp2) tmp2 = sizeof(str[tmp]);
   str=sort_array(str, "sort_");
   str=sort_array(str, "sort_alpha");
   tmp = sizeof(str);
   while(tmp--) { 
     if(sscanf(str[tmp], "|%s|/", a) == 1)
       ex += ({ UNLOAD+"%^RED%^%^BOLD%^"+align(a+"%^BLUE%^%^BOLD%^/", tmp2)+"%^RESET%^" });
     else
     if(sscanf(str[tmp], "%s/", a) == 1)
       ex += ({ UNLOAD+"%^BLUE%^%^BOLD%^"+align(str[tmp], tmp2)+"%^RESET%^" });
     else
     if(sscanf(str[tmp], "%s.bak", a) == 1)
       ex += ({ UNLOAD+"%^BLACK%^%^BOLD%^"+align(str[tmp], tmp2)+"%^RESET%^" });
     else
     if(sscanf(str[tmp], "*%s.c", a) == 1)
       ex += ({ LOAD+"%^BOLD%^"+align(a+".c", tmp2)+"%^RESET%^" });
     else
     if(sscanf(str[tmp], "%s.c", a) == 1)
       ex += ({ UNLOAD+"%^BOLD%^"+align(str[tmp], tmp2)+"%^RESET%^" });
     else
     if(sscanf(str[tmp], "%s.old", a) == 1)
       ex += ({ UNLOAD+"%^BOLD%^"+align(str[tmp], tmp2)+"%^RESET%^" });
     else 
     ex += ({ UNLOAD+"%^BOLD%^%^RED%^"+align(str[tmp], tmp2)+"%^RESET%^" });     
   }

   if(cols > 4) cols = 4;
   tmp3 = 10;
   tmp = sizeof(ex);

   while(tmp--) {
     co++;

     if(co >= cols) {
       out += ex[tmp]+"\n";
       co = 0;
       tmp3 = SPACER;
     } else {
     while(tmp3--) out += " ";
     tmp3 = SPACER;
     out += ex[tmp];
     }
   }
   return out+"\n";
}

int cmd_ls(string str) {
   int i, size, dir, files;
   string *all, a, *out, out2;
   if(!str) str = "";
   str = resolv_path(str, this_player()->get_path());
   out = ({});
   seteuid("Root");
   if(str != "/")
     if (str[strlen(str)-1..strlen(str)-1] != "/") str += "/";
   if(!master()->valid_read(str, this_player(), "")) 
     return notify_fail("Access denied.\n");
   if(file_size(str)!=-2) return notify_fail("No such directory.\n");
   all = get_dir(str);
   all=filter_array(all, "filter_dots");
   if(!archp(this_player()))
     all=filter_array(all, "filter_o");
   i=sizeof(all);
   message("command", "Directory info for "+str+"\n\n", this_object());

   while(i--) {
     if(str == "/") {
       if(file_size(str+all[i]) == -2) {
         if(!master()->valid_read(str+all[i]+"/", this_player()))
           out += ({ "|"+all[i]+"|/" });
         else out += ({ all[i]+"/" });
         dir++;
       }
       else {
         if(find_object(str+all[i])) out += ({ "*"+all[i] }); else
         out += ({ all[i]+"" });
         size = size + sizeof(read_file(str+all[i]));
         files++;
       }
     } else
     if(file_size(str+"/"+all[i]) == -2) {
       out += ({ all[i]+"/" });
       dir++;
     } 
     else {
       if(find_object(str+all[i])) out += ({ "*"+all[i] }); else
       out += ({ all[i]+"" });
       size = size + sizeof(read_file(str+all[i]));
       files++;
     }
   }
   seteuid(geteuid());
   message("system", "Directory information for: (\""+str+"\")\n", this_player());
   out=filter_array(out, "remove_dots", this_object());
   out2=format_p(out, 3);
   if(strlen(out2) > 8000) {
     out2 += "\n"+size+" bytes in "+files+" files.  "+dir+" directories.\n";
     this_player()->more(out2);
     return 1;
   }
   message("system", format_p(out, 2), this_player());
   message("system", "\n"+size+" bytes in "+files+" files.  "+dir+" directories.\n", this_player());
   return 1;
}

void help() {
   write("Syntax: <ls [dir]>\n");
   write("This will show the contents of the directory [dir].  "
   "If no [dir] is specified,  it will then show the contents "
   "of your current working directory.\n");
}

int sort_alpha(string one, string two) {
   string tmp, tmp2;
   if(sscanf(one, "_%s", tmp)==1); else tmp=one;
   if(sscanf(two, "_%s", tmp2)==1); else tmp2=two;
   if(sscanf(one, "*_%s", tmp)==1); else tmp=one;
   if(sscanf(two, "*_%s", tmp2)==1); else tmp2=two;
   if(sscanf(one, "*%s", tmp)==1); else tmp=one;
   if(sscanf(two, "*%s", tmp2)==1); else tmp2=two;
   if(sscanf(one, "|%s|/", tmp)==1); else tmp=one;
   if(sscanf(two, "|%s|/", tmp2)==1); else tmp2=two;

   return strcmp(tmp, tmp2);
}

int sort_(string one, string two) {
   return strcmp(one, two);
}

int remove_dots(string one) {
   string tmp;
   if(sscanf(one, "_%s", tmp)==1); else tmp=one;
   if(sscanf(one, "*_%s", tmp)==1); else tmp=one;
   if(sscanf(one, "*%s", tmp)==1); else tmp=one;
   if(sscanf(one, "|%s|/", tmp)==1); else tmp=one;
   if(one[0..0]==".") return 0;
   return 1;
}

int filter_dots(string f) {
   if(f[0..0]==".") return 0;
   return 1;
}
int filter_o(string f) {
   if(f[sizeof(f)-2..sizeof(f)-1]==".") return 0;
   return 1;
}
