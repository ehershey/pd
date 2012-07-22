// This is a way to call functions at a later time without
// using call_out, only one additional heart_beat in the mud

inherit DAEMON;

private static mapping _Delays = ([]);

mapping query_all_delays();
mixed *query_delays(int time);
int query_delay_time(object ob, string func);
varargs void add_delay(int time, object ob, string func, mixed *args, int load);
void remove_delay(int time, object ob, string func);
void perform_delays();

/*
 * _Delays = ([
 *   1177789668 : ({
 *     ({ ob, "func", ({ arg1, arg2 }), "obpath" }),
 *     ({ ob2, "func2", ({ arg1, arg2 }), "ob2path" }),
 *   }),
 *   1177799973 : ({
 *     ({ ob, "myfun", ({ }), "" }),
 *   }),
 * ]);
 */

void create() {
  daemon::create();
  set_no_clean(1);
  _Delays = ([]);
}

void heart_beat() {
  perform_delays();
  if (!sizeof(_Delays)) set_heart_beat(0);
}


mapping query_all_delays() { return copy(_Delays); }

mixed *query_delays(int time) {
  if (!nullp(_Delays[time]))
    return _Delays[time];
  else
    return 0;
}

int query_delay_time(object ob, string func) {
  foreach (int t, mixed *list in _Delays)
    foreach (mixed *ar in list)
      if (ob == ar[0] && func == ar[1])
        return t;
  return 0;
}



// args and load are optional, args defaults to ({}) and load to 1
varargs void add_delay(int time, object ob, string func, mixed *args, int load) {
  string path;

  if (!time || !ob || !func) return;

  // time can either be an exact number in time() format,
  // or a number of seconds from now
  // 1 million seconds is about 11.5 days, should be a safe threshold
  if (time < 1000000) time = time()+time;
  
  if (nullp(args)) args = ({});
  else if (!arrayp(args)) args = ({ args });

  if (!nullp(load) && !load) path = "";
  else path = base_name(ob);

  if (nullp(_Delays[time])) _Delays[time] = ({});

  _Delays[time] += ({ ({ ob, func, args, path }) });

  set_heart_beat(1);
}


void remove_delay(int time, object ob, string func) {
  if (nullp(_Delays[time])) return;
  
  foreach (mixed arr in _Delays[time])
    if (ob == arr[0] && func == arr[1])
      _Delays[time] -= ({ arr });

  if (!sizeof(_Delays[time])) map_delete(_Delays, time);
}



void perform_delays() {
  if (!sizeof(_Delays)) return;
  
  foreach (int t, mixed *list in _Delays) {
    if (t <= time()) {
      foreach(mixed *ar in list) {
        object ob = ar[0];
        if (!ob && strlen(ar[3]))
          ob = load_object(ar[3]);
        if (ob)
          call_other(ob, ({ ar[1] }) + ar[2]);
      }
      map_delete(_Delays, t);
    }
  }

}


