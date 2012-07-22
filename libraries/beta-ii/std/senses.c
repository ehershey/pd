// original code by Ironman
// adapted by Nulvect 2008-03-07


int is_sense(string);
void set_sense(string, mixed, mixed);
void set_senses(string, mapping);
void remove_sense(string, string);
void remove_senses(string);
mixed query_sense(string, string);
mapping query_senses(string);
mapping query_senses_map();


static mapping _AllSenses = ([
  "smell" : ([]),
  "listen" : ([]),
  "touch" : ([]),
  "taste" : ([]),
  "read" : ([]),
  "search" : ([]),
  "item" : ([]),
]);

void create() {
  _AllSenses = ([
    "smell" : ([]),
    "listen" : ([]),
    "touch" : ([]),
    "taste" : ([]),
    "read" : ([]),
    "search" : ([]),
    "item" : ([]),
  ]);
}


// the basics

int is_sense(string sense) {
  if (!sense || !strlen(sense) || member_array(sense, keys(_AllSenses)) == -1)
    return 0;
  return 1;
}

void set_sense(string sense, mixed what, mixed msg) {
  if (!is_sense(sense)) return;
  if (!(stringp(msg) || functionp(msg))) return;
  if (stringp(what)) what = ({ what });
  else if (!arrayp(what)) return;
  foreach (string thing in what)
    _AllSenses[sense][thing] = msg;
}

void set_senses(string sense, mapping all) {
  if (!is_sense(sense)) return;
  if (!(mapp(all) && sizeof(all))) return;
  remove_senses(sense);
  foreach (mixed key, mixed value in all)
    set_sense(sense, key, value);
}

void remove_sense(string sense, string what) {
  if (!is_sense(sense)) return;
  map_delete(_AllSenses[sense], what);
}

void remove_senses(string sense) {
  if (!is_sense(sense)) return;
  _AllSenses[sense] = ([]);
}

mixed query_sense(string sense, string what) {
  mixed ret;
  if (!is_sense(sense)) return "";
  /* don't evaluate here
  ret = _AllSenses[sense][what];
  if (functionp(ret))
    ret = evaluate(ret, what);
  return (string)ret;
  */
  return _AllSenses[sense][what] || "";
}

mapping query_senses(string sense) {
  if (!is_sense(sense)) return ([]);
  return copy(_AllSenses[sense]);
}

mapping query_senses_map() {
  return copy(_AllSenses);
}

// ---


// ease of use and backwards compatibility:

void set_smell(mixed what, mixed msg) { set_sense("smell", what, msg); }
void set_listen(mixed what, mixed msg) { set_sense("listen", what, msg); }
void set_sound(mixed what, mixed msg) { set_sense("listen", what, msg); }
void set_touch(mixed what, mixed msg) { set_sense("touch", what, msg); }
void set_taste(mixed what, mixed msg) { set_sense("taste", what, msg); }
void set_read(mixed what, mixed msg) { set_sense("read", what, msg); }
void set_search(mixed what, mixed msg) { set_sense("search", what, msg); }
void set_item(mixed what, mixed msg) { set_sense("item", what, msg); }
void add_item(mixed what, mixed msg) { set_sense("item", what, msg); }
void set_detail(mixed what, mixed msg) { set_sense("item", what, msg); }

void set_smells(mapping m) { set_senses("smell", m); }
void set_listens(mapping m) { set_senses("listen", m); }
void set_sounds(mapping m) { set_senses("listen", m); }
void set_touches(mapping m) { set_senses("touch", m); }
void set_tastes(mapping m) { set_senses("taste", m); }
void set_reads(mapping m) { set_senses("read", m); }
void set_searches(mapping m) { set_senses("search", m); }
void set_items(mapping m) { set_senses("item", m); }
void set_details(mapping m) { set_senses("item", m); }

void remove_smell(string what) { remove_sense("smell", what); }
void remove_listen(string what) { remove_sense("listen", what); }
void remove_sound(string what) { remove_sense("listen", what); }
void remove_touch(string what) { remove_sense("touch", what); }
void remove_taste(string what) { remove_sense("taste", what); }
void remove_read(string what) { remove_sense("read", what); }
void remove_search(string what) { remove_sense("search", what); }
void remove_item(string what) { remove_sense("item", what); }
void remove_detail(string what) { remove_sense("item", what); }

void remove_smells() { remove_senses("smell"); }
void remove_listens() { remove_senses("listen"); }
void remove_sounds() { remove_senses("listen"); }
void remove_touches() { remove_senses("touch"); }
void remove_tastes() { remove_senses("taste"); }
void remove_reads() { remove_senses("read"); }
void remove_searches() { remove_senses("search"); }
void remove_items() { remove_senses("item"); }
void remove_details() { remove_senses("item"); }

mixed query_smell(string what) { return query_sense("smell", what); }
mixed query_listen(string what) { return query_sense("listen", what); }
mixed query_sound(string what) { return query_sense("listen", what); }
mixed query_touch(string what) { return query_sense("touch", what); }
mixed query_taste(string what) { return query_sense("taste", what); }
mixed query_read(string what) { return query_sense("read", what); }
mixed query_search(string what) { return query_sense("search", what); }
mixed query_item(string what) { return query_sense("item", what); }
mixed query_detail(string what) { return query_sense("item", what); }

mapping query_smells() { return query_senses("smell"); }
mapping query_listens() { return query_senses("listen"); }
mapping query_sounds() { return query_senses("listen"); }
mapping query_touches() { return query_senses("touch"); }
mapping query_tastes() { return query_senses("taste"); }
mapping query_reads() { return query_senses("read"); }
mapping query_searches() { return query_senses("search"); }
mapping query_items() { return query_senses("item"); }
mapping query_details() { return query_senses("item"); }

// ---

