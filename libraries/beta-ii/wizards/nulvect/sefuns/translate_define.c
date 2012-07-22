#include <security.h>

int translate_define(string define, string includefile) {
  string tmpdir = "/adm/tmp/translate/";
  string file;

  // can't have | in filenames
  define = replace_string(define, "|", "+");
  // remove spaces too
  define = replace_string(define, " ", "");
  
  file = tmpdir+includefile+"."+define+".c";

  if (file_size(file) == -1) {
    seteuid(UID_ROOT);
    write_file(file,
      "#include <"+includefile+">\n"
      "int translate_this() {\n"
      "  return "+define+";\n"
      "}"
    );
    seteuid(geteuid(previous_object()));
  }

  return file->translate_this();
}

