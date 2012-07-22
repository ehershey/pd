#include <std.h>
#include <daemons.h>

#define LIV_ICON "%^RESET%^%^GREEN%^*%^RESET%^"
#define MY_ICON "%^RESET%^%^RED%^X%^RESET%^"
#define SEPARATOR " %^RESET%^%^GREEN%^|%^RESET%^ "

inherit DAEMON;

string mapper(object who);
string *make_map(object env, string *long, string *exits, string what, int wrap, mapping heights);
string *get_last_colors(string *l);
int do_sortlr(string a, string b);
string do_reps(string l, int flag);
int get_height(string what);
int get_width(string dir);

// anything that lines up vertically must be the same width,
// that is, nw, w, and sw must all be 4 (or 3 or 5 or whatever)
// also, anything that lines up horizontally must all be
// the same height; w, here, and e are 1 line each, nw n ne are 2 lines
// all *'s will be replaced with LIV_ICON, @ with MY_ICON
// U is where up exit goes and D for down exit
mapping mapdesc = ([
  "northwest" : ({
    "[*] ",
    "   \\"
  }),
  "north" : ({
    "[*]",
    " | "
  }),
  "northeast" : ({
    " [*]",
    "/   "
  })
  "west" : ({ "[*]-" }),
  "here" : ({ "[@]" }),
  "east" : ({ "-[*]" })
  "southwest" : ({
    "   /",
    "[*] "
  }),
  "south" : ({
    " | ",
    "[*]"
  }),
  "southeast" : ({
    "\\   ",
    " [*]"
  })
]);
mapping updown = ([
  "up" : ({ 1, 6, "+" }),
  "down" : ({ 3, 4, "-" }),
]);
string *sortlr = ({
  "northwest", "north", "northeast",
  "west", "here", "east",
  "southwest", "south", "southeast",
});

string mapper(object who) {
  object env;
  string *exits;
  string *lines = ({});
  string *long;
  string *col;
  string term;
  int wrap;
  int mapwrap;
  mapping heights = ([]);

  if (!who || !living(who)) return "";

  env = environment(who);
  exits = env->query_obvious_exits() + ({ "here" });

  // first, figure out how wide the screen is...
  if (this_player()) {
    wrap = atoi(this_player()->getenv("SCREEN"));
    term = this_player()->getenv("TERM");
  }
  else {
    wrap = 80;
    term = "unknown";
  }
  wrap -= 1;
  // then, subtract the width of the map to find out how long the room
  // descriptions can be with the map added on
  mapwrap = wrap - (get_width("west") + get_width("here") + get_width("east"));
  // lastly, subtract the width of the separator
  mapwrap -= strlen(strip_color(SEPARATOR));

  // wrap the description, and separate out each line
  // this handy function ignores colors when wrapping but doesn't strip them
  long = explode(
    terminal_colour(env->query_long(0), TERMINAL_D->query_term_info(term), mapwrap, 0),
    "\n"
  );

  foreach (string h in ({ "top", "middle", "bottom" }) )
    heights[h] = get_height(h);
  heights["total"] = heights["top"] + heights["middle"] + heights["bottom"];

  for (int i = heights["total"] - sizeof(long); i > 0; i--)
    long += ({ " " });

  long = long[0..heights["total"]-1] +
         ({ implode(long[heights["total"]..<1], " ") });

  // figure out what color each line should start with
  // this function does the whole room desc at once so it should
  // be a little faster than the old way
/*
  col = get_last_colors(long[0..heights["total"]]);
  for (int i = 0; i < sizeof(col) && i+1 < sizeof(long); i++)
    long[i+1] = col[i] + long[i+1];
*/

  // use copy() here, because each call needs to have the original info,
  // and arrays are passed by reference
  foreach (string which in ({"top", "middle", "bottom"}) )
    lines += make_map(env, long, copy(exits), which, mapwrap, heights);

/*
  for (int i = 0; i < sizeof(long); i++) {
    long[i] = format_line(long[i], copy(exits), heights);
  }
*/

  // "rest" should just be one line, with no \n's embedded
  // we have to do all the wrapping ourselves, so we wrap "rest" here:
  message("info", identify(lines[<1]), this_player());
  lines += ({ terminal_colour(long[<1], TERMINAL_D->query_term_info(term), wrap, 0) });


  return implode(lines, "\n");
}

string *make_map(object env, string *long, string *exits, string what, int wrap, mapping heights) {
  int start = 0;
  string *allex;
  int height;
  int u = 0;

  // figure out what line this section starts at
  // note that I'm being clever here, I purposely don't use breaks so the switch drops through
  switch (what) {
    case "rest": start += heights["bottom"];
    case "bottom": start += heights["middle"];
    case "middle": start += heights["top"];
  }

  // note that I don't wrap this here, but up above
  if (what == "rest") {
    return ({ implode(long[start..<1], " ") });
  }

  height = heights[what];
  allex = keys(mapdesc[what]);
  if (member_array("up", exits) != -1) u |= updown["up"][4];
  if (member_array("down", exits) != -1) u |= updown["down"][4];

  // cut down to the lines we care about for this section
  long = long[start..start-1+height];
  // cut down to the exits for this section
  exits = filter(exits, (: member_array($1, $2) != -1 :), allex);
  // now sort from left-to-right, -1 puts it to the left and 1 puts it to the right
  allex = sort_array(allex, "do_sortlr", this_object());

  // pad each line and add the separator
  for (int i = 0; i < sizeof(long); i++) {
    int r = strlen(strip_color(long[i]));
    int p = wrap - r;
    if (p > 0) long[i] = long[i] + repeat_string(" ", p);
    long[i] = long[i] + SEPARATOR;
    message("info", sprintf("%O", r), this_player());
  }
//    long[i] = arrange_string(long[i], wrap) + SEPARATOR;
//  long = map(long, (: (arrange_string($1, $2) + SEPARATOR) :), wrap );
  message("info", sprintf("%O", long), this_player());

  // check each possible exit in this section
  foreach (string dir in allex) {
    object ob;
    // reset the living flag each time
    int flag = 0;
    // room doesn't have this exit, fill with blanks
    if (member_array(dir, exits) == -1) {
      for (int i = 0; i < height; i++)
        long[i] += repeat_string(" ", get_width(dir));
      continue;
    }
    else if (dir != "here") ob = load_object(env->query_exit(dir));
    // check for living things
    if (ob && sizeof(filter(all_inventory(ob), (: living($1) :) )))
      flag |= 1;
    for (int i = 0; i < height; i++)
      long[i] += do_reps(mapdesc[what][dir][i], flag);
  }
  foreach (string dir, mixed *info in updown) {
    if (u & info[4] && what == info[0]) {
      int t = info[2] + strlen(long[info[1]]) - (get_width("west")+get_width("here")+get_width("east"));
      long[info[1]][t..t] = info[3];
    }
  }

  return long;

}
string do_reps(string l, int flag) {
  string livrep = " ";
  if (flag & 1)
    livrep = LIV_ICON;
  l = replace_string(l, "@", MY_ICON);
  l = replace_string(l, "*", livrep);
  return l;
}
int get_height(string dir) {
  return sizeof(mapdesc[dir]);
}
int get_width(string dir) {
  return strlen(mapdesc[dir][0]);
}
int do_sortlr(string a, string b) {
  int x = member_array(a, sortlr) - member_array(b, sortlr);
  if (x < 0) return -1;
  else return 1;
}
string *get_last_colors(string *l) {
  string code = "%^";
  string *ret = ({ });
  int s = sizeof(l);
  int c = strlen(code);

  foreach (string line in l) {
    int a = 0;
    int z = -1;
    int bold = 0;
    int toggle = 0;
    string tmp = "";

    // search each line, left to right, for color code
    while ((z = strsrch(line[a..<1], code)) != -1) {
      toggle = !toggle;
      // every SECOND find, parse the color code
      if (toggle) {
        tmp = line[a..z-1];
        switch (tmp) {
          case "BOLD": bold = 1; tmp = ""; break;
          case "RESET": bold = 0; tmp = ""; break;
          default:
        }
      }
      a = z + c;
    } // end while

    // whatever we were left with at the end of the while loop is
    // the last color information for this line, so store it:
    if (bold) tmp = code+"BOLD"+code+tmp;
    ret += ({ tmp });

  } // end foreach

  // make sure there are enough entries in the return value
  // reusing c here
  if ((c = (s - sizeof(ret))) > 0) while (c--) ret += ({ "" });

  return ret;

}
