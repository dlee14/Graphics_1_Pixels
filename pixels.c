#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
  int ppm = open("pic.ppm", O_CREAT | O_WRONLY, 0644);
  int r, g, b;
  char * header = "P3\n500 500\n255\n";
  write(ppm, header, strlen(header));


  char line[14];
  int w, h;
  for (h = 0; h < 500; h++) {
    for (w = 0; w < 500; w++) {
      r = (w * h) % 256;
      g = (w * h) % 256;
      b = (w * h) % 256;
      sprintf(line, "%d %d %d", r, g, b);
      if(w != 499) {
        strcat(line, " ");
      }
      write(ppm, line, sizeof(line));
    }
    write(ppm, "\n", sizeof("\n"));
  }

  close(ppm);
  return 0;
}
