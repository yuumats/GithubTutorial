#include <stdio.h>

int main(void) {
	while (1)
    {
        int input_num = 0; #入力コマンドの初期化

        printf("数値を入力してください\n");
        scanf("%d", &input_num);
        
        if (input_num == 0)
        {
            printf("プログラムを終了します\n");
            break;
        }
        /* ここに処理を追加してみよう */
        else
        {
            printf("該当するコマンドがありません\n");
        }
        break;
    }
	return 0;
}
