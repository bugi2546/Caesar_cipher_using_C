#include <stdio.h>
#include <string.h>

// 함수 선언
void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main() {
    char message[100];
    int shift;

    printf("암호화할 메시지를 입력하세요: ");
    fgets(message, sizeof(message), stdin);

    printf("암호화할 횟수(숫자)를 입력하세요: ");
    scanf("%d", &shift);

    // 암호화
    encrypt(message, shift);
    printf("암호화된 메시지: %s\n", message);

    // 복호화
    decrypt(message, shift);
    printf("복호화된 메시지: %s\n", message);

    return 0;
}

// 암호화 함수
void encrypt(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
    }
}

// 복호화 함수
void decrypt(char *message, int shift) {
    // 복호화는 암호화와는 반대 방향으로 이동하면 됩니다.
    encrypt(message, 26 - shift); // 시저 암호에서는 26 - shift로 복호화합니다.
}
