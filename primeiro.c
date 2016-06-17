#include <stdio.h>
#include <unistd.h>

int main(){
	int b, c, d, e, f, g;
	b = fork();
	if( b == 0 ){
		// b
		d = fork();
		if (d) {
			e = fork();
		}
	} else {
		// a
		c = fork();
		if (!c) {
			f = fork();
			if (!f) {
				g = fork();
			}
		}
	}
	sleep(60);
}
