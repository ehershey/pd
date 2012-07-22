
#include <std.h>
#include <money.h>

#define MENU_WIDTH 60

inherit MONSTER;

mapping menu;
string menuoutput, menuheader, menufooter;
string currency;
int automenu;
string *automenu_strings;

string read_menu(string);
string generate_menu_output(int);
void set_menu_header(string);
void set_menu_footer(string);
void set_menu(mapping);
mapping query_menu();
void set_currency(string);
string query_currency();
string query_file(string);
int query_price(string);
string query_item_short(string);
int convert_money(mapping);
object make_item(string);
int do_buy(string);
string find_drink(string);
void set_automenu(mixed);
varargs int query_automenu(string);

void create() {
  ::create();

  set_read( ({ "menu" }), (: read_menu :) );

  menu = ([]);
  currency = "gold";
  menuoutput = 0;
  menuheader = "The following are served here:";
  menufooter = "<buy item> gets you something to eat or drink.";
  automenu = 1;
  automenu_strings = ({ "menu" });
}

void init() {
  ::init();
  add_action("do_buy", ({ "buy", "order" }) );
}

int move(mixed dest) {
  object oldenv = environment();
  int ret = ::move(dest);
  object env = environment();
  if (!ret && query_automenu()) {
    if (env && env->is_room()) {
      foreach (string str in automenu_strings) {
        env->set_read(str, (: read_menu :) );
        env->set_item(str, (: read_menu :) );
      }
    }
    if (oldenv && oldenv != env && oldenv->is_room()) {
      foreach (string str in automenu_strings) {
        oldenv->remove_read(str);
        oldenv->remove_item(str);
      }
    }
  }
  return ret;
}

int remove() {
  object env = environment();
  if (env && env->is_room() && query_automenu()) {
    foreach (string str in automenu_strings) {
      env->remove_read(str);
      env->remove_item(str);
    }
  }
  return ::remove();
}

void set_automenu(mixed x) {
  if (intp(x))
    automenu = (x == 0 ? 0 : 1);
  else if (arrayp(x) && sizeof(x) && stringp(x[0])) {
    automenu = 1;
    automenu_strings = x;
  }
}
varargs int query_automenu(string str) {
  if (nullp(str)) return automenu;
  else return member_array(str, automenu_strings) != -1;
}

string read_menu(string str) {
  int width = to_int(this_player()->query_env("SCREEN"));
  if (!width) width = 80;

  // generate and store the menu output so we don't have to
  // regenerate it every time someone reads the menu
  if (!menuoutput || !strlen(menuoutput))
    menuoutput = generate_menu_output(MENU_WIDTH);

  // this is pretty unlikely, but just in case...
  if (width < MENU_WIDTH)
    return generate_menu_output(width);

  return menuoutput;
}

string generate_menu_output(int width) {
  string msg = "";

  if (nullp(width)) width = MENU_WIDTH;
  if (width < 30) width = 30;

  msg = "%^RESET%^"+menuheader+"\n";
  msg += repeat_string("-", width)+"\n";
  
  foreach (string item, mapping info in menu) {

    if (info["hidden"]) continue;

    // this uses "column mode" formatting with variables for the widths

    msg += sprintf("%-=*s    %=*s\n",
        width/2 - 2,
        capitalize(strip_color(query_item_short(item))),
        width/2 - 2,
        query_price(item)+" "+query_currency()
    );

  }

  msg += repeat_string("-", width)+"\n";
  msg += menufooter;

  return msg;
}

// these are displayed before/after the menu items
void set_menu_header(string str) { menuheader = str; }
void set_menu_footer(string str) { menufooter = str; }

// set_menu( ([
//   "fish" : "/blah/fish.c",
//   "beer" : ([
//     "type" : "alcoholic",
//     "strength" : 10,
//     "price" : 6,
//   ]),
// ]) );
// will use the file if given, otherwise it will do
// set_type("alcoholic"), set_strength(10), etc on
// a blank object
// id, name, short, long, weight, and value are computed
// automatically if not set
void set_menu(mapping items) {
  menu = ([]);
  foreach (string item, mixed val in items) {
    item = remove_article(item);
    menu[item] = ([]);
    if (stringp(val))
      menu[item]["file"] = val;
    else if (mapp(val)) {
      menu[item] = copy(val);
    }
  }
}
mapping query_menu() { return copy(menu); }

void set_currency(string str) {
  if (member_array(str, HARD_CURRENCIES) != -1)
    currency = str;
  else
    currency = "gold";
}
string query_currency() { return currency; }

string query_file(string item) {
  if (menu[item]) return menu[item]["file"];
  return 0;
}

int query_price(string item) {
  int price = 0;
  if (!menu[item]) return 0;

  price = menu[item]["price"] || menu[item]["value"];
  if (!price && query_file(item)) {
    object ob = load_object(query_file(item));
    price = convert_money(ob->query_curr_value());
  }

  if (!price && menu[item]["strength"]) price = menu[item]["strength"]/6;

  if (!price || price < 1) price = 1;

  return price;
}

string query_item_short(string item) {
  string short;
  if (!menu[item]) return "";

  short = menu[item]["short"];
  if (!short && query_file(item)) {
    object ob = load_object(query_file(item));
    short = ob->query_short();
  }

  if (!short) short = indefinite_article(item);

  return short || "";
}

// costs should be of the form ([ "gold" : 5, "silver" : 25 ])
// this assumes all entries in the mapping are equivalent!!
// figures out the cost in this barkeep's currency
int convert_money(mapping costs) {
  int cost;
  float fromrate, torate;
  string fromcurr, tocurr;

  if (!costs || !sizeof(costs)) return 0;
  if (cost = costs[query_currency()]) return cost;

  tocurr = query_currency();
  fromcurr = keys(costs)[0];
  cost = costs[fromcurr];
  torate = currency_rate(tocurr);
  fromrate = currency_rate(fromcurr);

  cost = (cost/fromrate)*torate;

  return cost;
}

object make_item(string item) {
  object ob;

  if (!menu || !menu[item]) return 0;

  if (menu[item]["file"]) {
   if (ob = new(menu[item]["file"])) return ob;
   else return 0;
  }

  switch (menu[item]["type"]) {
    case "food":
      ob = new(FOOD);
    break;

    case "alcoholic": case "soft drink": case "caffeine":
      ob = new(DRINK);
      ob->set_type(menu[item]["type"]);
    break;

    default:
      return 0;
  }

  foreach (string key, mixed val in menu[item]) {
    if (!ob) break;
    if (key == "type") continue;
    if (key == "hidden") continue;
    call_other(ob, "set_"+key, val);
  }

  ob->set_id((string *)ob->query_id() + ({ item }) );
  ob->set_curr_value(currency, query_price(item));

  if (!ob->query_name())
    ob->set_name(item);
  if (!ob->query_short())
    ob->set_short(indefinite_article(item));
  if (!ob->query_long())
    ob->set_long(capitalize(indefinite_article(item))+" from "+
      this_object()->query_cap_name()+".");
  if (!ob->query_weight())
    ob->set_weight(2);

  return ob;
}

int do_buy(string str) {
  object tp = this_player();
  int cost, num=1;
  int dropped=0, count=0;
  string cur = query_currency();
  string what;

  if (!menu || !sizeof(menu)) {
    command("say Sorry, but I don't sell anything.");
    return 1;
  }

  if (!str) {
    command("say What would you like?");
    return 1;
  }

  sscanf(str, "%d %s", num, str);

  str = lower_case(str);
  str = find_drink(str);

  if (num < 1) {
    command("say You can't buy that many.");
    return 1;
  }

  if (!strlen(str)) {
    command("say I don't serve that.");
    return 1;
  }

  cost = query_price(str);
  cost *= num;

  if (tp->query_money(cur) < cost) {
    command("say "+tp->query_cap_name()+
      ", you do not have enough "+cur+" for that.");
    return 1;
  }

  if (num > 1)
    what = cardinal(num)+" "+pluralize(str);
  else
    what = indefinite_article(str);

  message("info", "You pay "+cost+" "+cur+
    " coin"+(cost > 1 ? "s" : "")+" for "+what+".", tp);
  message("info", tp->query_cap_name()+" buys "+what+
    " from "+this_object()->query_cap_name()+".",
    environment(), ({ tp, this_object() }) );

  count = num;
  while (count--) {
    object ob;
    if (!(ob = make_item(str))) {
      message("info", "An error occurred, please contact a staff member.", tp);
      return 1;
    }

    if (ob->move(tp)) {
      dropped++;
      ob->move(environment());
    }
  }

  if (dropped == 1 && num == 1) {
    what = indefinite_article(str);
    message("info", "You cannot carry it!\n"
                    "You drop "+what+".", tp);
    message("info", tp->query_cap_name()+" drops "+what+".",
        environment(), tp);
  }
  else if (dropped >= 1) {
    what = cardinal(dropped)+" "+pluralize(str);
    message("info", "You cannot carry all of them!\n"
                    "You drop "+what+".", tp);
    message("info", tp->query_cap_name()+" drops "+what+".",
        environment(), tp);
  }

  tp->add_money(cur, -cost);

  return 1;
}

string find_drink(string str) {
  string tmp;
  string ret = "";
  string *try;

  try = ({ str });
  if (str[<2..<2]== "es") try += ({ str[0..<3] });
  else if (str[<1..<1]== "s") try += ({ str[0..<2] });

  foreach (string s in try) {

    if (menu[s]) ret = s;

    else {
      foreach (tmp in keys(menu)) {
        string short = lower_case(remove_article(strip_color(query_item_short(tmp))));
        if (s == short) {
          ret = tmp;
          break;
        }
      }
    }

    if (strlen(ret)) break;

  }

  return ret;
}

