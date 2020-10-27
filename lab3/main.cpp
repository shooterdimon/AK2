#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]) {
    int result = 0;
    map<string, bool> used;

    int option_index = -1;
    //f-first;s-second;t-third;e-eights
    const char *short_options = "hlvnoV::";

    const struct option long_options[] = {
            {"help",  0, NULL, 'h'},
            {"list", 0, NULL, 'l'},
            {"version",  0, NULL, 'v'},
            {"noconsole", 0, NULL, 'n'},
            {"onefile", 0, NULL, 'o'},
            {"value", 2, NULL, 'V'}, // Optional parameter
            {NULL,0,NULL,0}
    };

    while ((result = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (result) {
            case 'h': {
                if (used["h"] == false) {
                    printf("Arg: Help\n");
                    used["h"] = true;
                    break;
                }
                break;
            }
            case 'l': {
                if (used["l"] == false) {
                    printf("Arg: List\n");
                    used["l"] = true;
                    break;
                }
                break;
            }
            case 'v': {
                if (used["v"] == false) {
                    printf("Arg: Version\n");
                    used["v"] = true;
                    break;
                }
                break;
            }
            case 'n': {
                if (used["n"] == false) {
                    printf("Arg: Noconsole\n");
                    used["n"] = true;
                    break;
                }
                break;
            }
            case 'o': {
                if (used["o"] == false) {
                    printf("Arg: Onefile\n");
                    used["o"] = true;
                    break;
                }
                break;    
            }
            case 'V': {
		if (used["V"] == false) {
			if (optarg == NULL) {
				printf("Arg: Value without parameter\n"); 
				used["V"] = true;
			} else {
				printf("Arg: Value = %s\n", optarg); 
				used["V"] = true;
			}
				
			break;
		}
		break;
            }
            case '?': default: {
                printf("Error: Key %c was not found\n", result);
                break;
            }
        }
        option_index = -1;
    }
}

