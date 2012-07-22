
static mapping Hooks = ([]);

mapping query_all_hooks();
void init_hooks(string func);
void clear_hooks(string func);
function *query_hooks(string func);
void add_hook(string func, function ptr);
void insert_hook(string func, function ptr, int x);
void remove_hook(string func, function ptr);
mixed resolve_hooks(string func, mixed arg);

void create() {
  Hooks = ([]);
}

mapping query_all_hooks() {
  return Hooks;
}

void init_hooks(string func) {
  if (!sizeof(Hooks[func])) clear_hooks(func);
}

void clear_hooks(string func) {
  Hooks[func] = ({});
}

function *query_hooks(string func) {
  if (!func) return ({});
  init_hooks(func);
  return Hooks[func];
}

void add_hook(string func, function ptr) {
  if (!func || !functionp(ptr)) return;
  init_hooks(func);
  Hooks[func] += ({ptr});
}

void insert_hook(string func, function ptr, int x) {
  if (!func || !functionp(ptr) || !x) return;
  init_hooks(func);
  x-=2;
  Hooks[func] = Hooks[func][0..x] + ({ptr}) + Hooks[func][x+1..];
}

void remove_hook(string func, function ptr) {
  if (!func || !functionp(ptr)) return;
  init_hooks(func);
  Hooks[func] -= ({ptr});
}

mixed resolve_hooks(string func, mixed arg) {
  mixed tmp = copy(arg);
  init_hooks(func);
  foreach (function f in query_hooks(func))
    tmp = (*f)(tmp);
  return tmp;
}

