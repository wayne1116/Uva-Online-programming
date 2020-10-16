#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[1024], *ptr;
	while(fgets(line,1024,stdin)!=NULL){
		ptr=line;
		while(*ptr){
			switch(*ptr){
				case 'e':
					printf("q");
					break;
				case 'r':
					printf("w");
					break;
				case 't':
					printf("e");
					break;
				case 'y':
					printf("r");
					break;
				case 'u':
					printf("t");
					break;
				case 'i':
					printf("y");
					break;
				case 'o':
					printf("u");
					break;
				case 'p':
					printf("i");
					break;
				case '[':
					printf("o");
					break;
				case ']':
					printf("p");
					break;
				case 'd':
					printf("a");
					break;
				case 'f':
					printf("s");
					break;
				case 'g':
					printf("d");
					break;
				case 'h':
					printf("f");
					break;
				case 'j':
					printf("g");
					break;
				case 'k':
					printf("h");
					break;
				case 'l':
					printf("j");
					break;
				case ';':
					printf("k");
					break;
				case '\'':
					printf("l");
					break;
				case 'c':
					printf("z");
					break;
				case 'v':
					printf("x");
					break;
				case 'b':
					printf("c");
					break;
				case 'n':
					printf("v");
					break;
				case 'm':
					printf("b");
					break;
				case ',':
					printf("n");
					break;
				case '.':
					printf("m");
					break;
				default:
					printf("%c", *ptr);
					break; 
			}
			ptr++;
		}
	}
	return 0;
}
