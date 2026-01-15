#include <stdio.h>
int c=0;
int func( int a )
{
++a; ++c;
return( a );
}
int main(void)
{
	int a=1 , b=5; //1．この行の直後にprintfを追加し、 a,b,c の値を表示し、確認せよ
	printf("a=%d,b=%d,c=%d\n",a,b,c);
	{
		int a=2 , c=10; // ２．この行の直後にprintfを追加し、 a,b,c の値を表示し、確認せよ
		printf("a=%d,b=%d,c=%d\n",a,b,c);
		++a;
		++b;
		++c; // ３．この行の直後にprintfを追加し、 a,b,c の値を表示し、確認せよ
		printf("a=%d,b=%d,c=%d\n",a,b,c);
	}
	b = func( a+1 ); // ４．この行の直後にprintfを追加し、 a,b,c の値を表示し、確認せよ
	printf("a=%d,b=%d,c=%d\n",a,b,c);
	return 0;
}
