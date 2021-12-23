#include <stdio.h>
#include <string.h>

#include "uECC.h"

void vli_print(uint8_t *vli, unsigned int size) {
    for (unsigned i = 0; i < size; ++i) {
        printf("%02X", (unsigned)vli[i]);
    }
}

size_t hex_to_bytes(const char *src, uint8_t *dest, size_t count) {
    size_t i;
    int value;
    for (i = 0; i < count && sscanf(src + i * 2, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

int main(void) {
    int i, c;
    const struct uECC_Curve_t *curve = uECC_secp256r1();
    uint8_t public[64] = {0};
    char hex[128];

    while (1) {
        printf(
            "> ECDH "
            "P-256(secp256r1)の公開鍵の16進数文字列("
            "先頭の04を除く64バイト、128文字)"
            "を入力してEnterを押してください\n");
        scanf("%s", hex);
        hex_to_bytes(hex, public, 64);
        // vli_print(public, 64);
        // printf("\n");

        if (uECC_valid_public_key(public, curve) == 1) {
            printf("> OK: public key is valid\n");
        } else {
            printf("> NG: public key is invalid\n");
        }
    }
    return 0;
}