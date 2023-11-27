#include <stdio.h>
#include <string.h>

char substitution_key[128];

void init_substitution_key() {
}

void decrypt_substitution(const char *ciphertext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= '0' && ciphertext[i] <= '9') {
            putchar(substitution_key[ciphertext[i]]);
        } else {
            putchar(ciphertext[i]);
        }
    }
    putchar('\n');
}

int main() {
    init_substitution_key();
    
    const char *ciphertext = "53���305))6*;4826)4�.)4�);806*;48�8�60))85;;]8*;:�*8�83 (88)5*�;46(;88*96*?;8)*�(;485);5*�2:*�(;4956*2(5*�4)8�8* ;4069285);)6�8)4��;1(�9;48081;8:8�1;48�85;4)485�528806*81 (�9;48;(88;4(�?34;48)4�;161;:188;�?;";
    
    decrypt_substitution(ciphertext);
    
    return 0;
}
