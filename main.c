#include <stdio.h>
typedef struct storage {
  FILE * content;
  FILE * type;
  FILE * extra;
};
typedef struct cache {
  storage *content[];
};
typedef struct object {
  char content[];
  char type;
  char extra[];
}

class store {
  public:
    char NextName[5] = "     ";
    cache dataStore;
    void close() {
      if (*dataStore.content != NULL) {
        cache tmp = *dataStore;
        for(int i = 0; i <= sizeof tmp.content; i++) {
          fclose(tmp.content[i].content);
          fclose(tmp.content[i].type);
          fclose(tmp.content[i].extra);
        }
      }
    }
    void writeCache(object input) {
      char tmpChar[] = NextName;
      tmpChar[sizeof NextName + 1] = "0";
      FILE * f1 = fopen(tmpChar, "w+");
      fput(input.content, f1);
      char tmpChar[] = NextName;
      tmpChar[sizeof NextName + 1] = "1";
      FILE * f2 = fopen(tmpChar, "w+");
      fputc(input.type, f2);
      char tmpChar[] = NextName;
      tmpChar[sizeof NextName + 1] = "2";
      FILE * f3 = fopen(tmpChar, "w+");
      fput(input.extra, f3)
      storage s;
      s.content = f1;
      s.type = f2;
      s.extra = f3;
      dataStore.content[sizeof dataStore.content + 1] = &s;
      bool running = true;
      int k = 0;
      while running {
        if (NextName[k] != NULL) {
          if (NextName[k] < 255) {
            NextName[k] += 1;
            running = false;
          }
          else {
            k += 1;
          }
        }
        else {
          NextName[k] = 0;
          running = false;
        }
      }
    }
    object readCache(int index) {
      storage * contentPtr = dataStore.content[index];
      storage content = *contentPtr;
      object output;
      fgets(output.content, 2048, content.content);
      fgets(output.type, 2048, content.type);
      fgets(output.extra, 2048, content.extra)
      return output;
    }
    object codeInt(int input) {
      object o;
      char content[];
      for (int i = 0; i <= input; i++) {
        if (content[sizeof content] <= 256) {
          content[sizeof content] += 1;
        }
        else {
          content[sizeof content + 1] = 0
        }
      }
      o.content = content;
      o.tpye = "0"
      o.extra = "none"
      return o;
    }
}
int main() {
  store s;
  object test = s.codeInt(100);
  s.writeCache(test);
  s.close();
  return 0;
}
