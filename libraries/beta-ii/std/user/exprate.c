// code for tracking exp rate

static int *_ExpRate = ({ 0, 0 });

void set_exprate_start(int time) { _ExpRate[0] = time; }
int query_exprate_start() { return _ExpRate[0]; }

void add_exprate_exp(int exp) { _ExpRate[1] += exp; }
int query_exprate_exp() { return _ExpRate[1]; }

void clear_exprate() { _ExpRate = ({ 0, 0 }); }

