#include <stdio.h>
#include <conio.h>
#include "game.h"
#include <time.h>
#include <string.h>

#define chieudai 80
#define chieurong 25
#define may 10

enum trang_thai {len, xuong, phai , trai};
enum kq{thang, thua};

struct toa_do
{
	int x, y; //x la hoang do . y la tung do
};
struct con_ran
{
	toa_do dot[50] ;
	int n;
	int diem = 0;
	trang_thai tt;
	int mang = 3;
	int may_man=0;
};
struct hoa_qua
{
	toa_do td;
};
struct qua_mang
{
	toa_do td;

};
struct qua_thui
{
	int n = 3;
	toa_do td[100];
};
void khoi_tao(con_ran &ran, hoa_qua &qua, qua_thui &thui,qua_mang &qm)  //ko chay dc vi thieu dau &
{
	ran.n = 3;
	ran.dot[0].x = 5;
	ran.dot[0].y = 5;
	ran.dot[1].x = 6;
	ran.dot[1].y = 5;
	ran.dot[2].x = 7;
	ran.dot[2].y = 5;

	ran.tt = phai;
	qua.td.x = 10;
	qua.td.y = 10;
		for (int i = 0; i < thui.n; i++)
		{
			thui.td[i].x = rand() % chieudai - 1;
			thui.td[i].y = rand() % chieurong - 1;
		}
		
		qm.td.x = 9;
		qm.td.y = 9;

}
void khung(void)
{
	TextColor(7);
	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\n");
	for (int i = 1; i < 24; i++)
	{
		gotoXY(0, i);
		printf("|");
		gotoXY(79 ,i);
		printf("|");
	}
	printf("\n");
	for (int i = 0; i < 80; i++)
		printf("-");
	

}
void hien_thi(con_ran &ran,hoa_qua &qua,qua_thui &thui, qua_mang &qm,char *ten)
{
	clrscr();   //
	khung();
	
	gotoXY(89, 10);
	printf("Diem: %d",ran.diem);
	gotoXY(89, 11);
	printf("Mang: %d", ran.mang);
	gotoXY(89, 12);
	printf("So qua thui: %d", thui.n);
	gotoXY(89, 13);
	
	printf("+An 0 dc 1 diem va to hon");
	gotoXY(89, 14);
	printf("+An x la thua");
	gotoXY(86, 15);
	printf("+Nhan G de thay doi vi tri tat ca");
	gotoXY(86, 17);
	printf("con so may man: %d ?2", ran.may_man);
	gotoXY(89, 16);
	printf("Ho ten: ");
	puts(ten);
	for (int i = 0; i <= thui.n; i++)
	{
		TextColor(6);
		gotoXY(thui.td[i].x, thui.td[i].y);
		printf("x");
	}
	TextColor(3);
	gotoXY(qua.td.x, qua.td.y);
	putchar(2);
	for(int i=0; i<ran.n; i++)
	{
		TextColor(10);
		gotoXY(ran.dot[i].x, ran.dot[i].y);
		printf("*");
	}
	
	if (ran.may_man == 2)
	{
		TextColor(4);
	gotoXY(qm.td.x, qm.td.y);
	printf("M");
	}

}
void xu_ly(con_ran &ran, hoa_qua &qua,qua_thui &thui,qua_mang &qm)
{
	for (int i = ran.n; i > 0; i--)
	{
		ran.dot[i] = ran.dot[i - 1];
		
	}

	if(_kbhit() )
	{ 
	char key;
	key = _getch();
	
	if (ran.tt != trai && (key == 'd' || key == 'D')) ran.tt = phai;
	if (ran.tt != phai && (key == 'a' || key == 'A')) ran.tt = trai;
	if (ran.tt != len && (key == 's' || key == 'S')) ran.tt = xuong;
	if (ran.tt != xuong &&  (key == 'w' || key == 'W') ) ran.tt = len;
	if (key == 'g' || key == 'G')
	{
		qua.td.x = rand() % chieudai;
		qua.td.y = rand() % chieurong;
		for (int i = 0; i < thui.n; i++)
		{
			thui.td[i].x = rand() % chieudai;
			thui.td[i].y = rand() % chieurong;
		}
	}
    }

	if (ran.tt == phai) ran.dot[0].x++;
	if (ran.tt == trai) ran.dot[0].x--;
	if (ran.tt == len) ran.dot[0].y--;
	if (ran.tt == xuong) ran.dot[0].y++;

	if (ran.dot[0].x == chieudai - 1) ran.dot[0].x=1;
	if (ran.dot[0].y == chieurong - 1) ran.dot[0].y=1;
	if (ran.dot[0].x == 0) ran.dot[0].x=chieudai-2;
	if (ran.dot[0].y == 0) ran.dot[0].y=chieurong-2;

	if (ran.dot[0].x == qua.td.x && ran.dot[0].y == qua.td.y)
	{
		ran.diem++;
		ran.n++;
		thui.n++;
		qua.td.x = rand() % chieudai;// nho
		qua.td.y = rand() % chieurong;//

		for (int i = 0; i < thui.n; i++)
		{
			thui.td[i].x = rand() % chieudai;
			thui.td[i].y = rand() % chieurong;
		}

		ran.may_man = rand() % may;
		if (ran.may_man == 2)
		{
			qm.td.x = rand() % chieudai - 1;
			qm.td.y = rand() % chieurong - 1;
		}
	}
	
	if (ran.dot[0].x == qm.td.x && ran.dot[0].y == qm.td.y)
	{
		ran.mang++;
		ran.may_man = rand() % may;
	}

}
void win(void)
{
	clrscr();
	printf("\n\n\n\n\n");
	printf("  ||      ||       ||   ||   ||\\\    ||\n");
	printf("   ||     ||      ||    ||   || \\\   ||\n");
	printf("    ||   || ||   ||     ||   ||  \\\  ||\n");
	printf("     || ||   || ||      ||   ||   \\\ ||\n");
	printf("      ||      ||        ||   ||    \\\|| ");
}
void lost(void)
{
	clrscr();
	printf("\n\n\n\n\n");
	printf("  ========   ||      ||   ||     ||      //\\\ \n");
	printf("     ||      ||      ||   ||     ||     // \\\\ \n");
	printf("     ||      ||======||   ||     ||    //===\\\\ \n");
	printf("     ||      ||      ||   ||     ||   //     \\\\ \n");
	printf("     ||      ||      ||   \\ ======/  //       \\\\ ");
}
void thang_thua(con_ran &ran, hoa_qua &qua, qua_thui &thui,kq &kq, qua_mang &qm)
{
	for (int i = 0; i < thui.n; i++)
	{
		if (ran.dot[0].x == thui.td[i].x && ran.dot[0].y == thui.td[i].y)
		{
			{
				ran.mang--;
			    break; 
			}
		}
	}
	if (ran.diem == 30)
	{
		kq = thang;

	}
	//if (ran.dot[0].x == chieudai ) kq = thua;
	//if (ran.dot[0].y == chieurong ) kq = thua;
	//if (ran.dot[0].x == 0) kq = thua;
	//if (ran.dot[0].y == 0) kq = thua;
	if (ran.mang == 0) kq = thua;

	for (int i = 3; i < ran.n; i++)
	{
		if(ran.dot[0].x == ran.dot[i].x  && ran.dot[0].y == ran.dot[i].y)
		{
			ran.mang--;
			break;
		}
	}   // dang sai can fix
	  
	
	if (ran.dot[0].x == qm.td.x  && ran.dot[0].y == qm.td.y)
	{
		ran.mang++;
	}
}
int main() // ko chay dc neu thieu int
{
	
	
	
	char ten[100];
	
	printf("Nhap ten:");
	gets_s(ten);
	
		kq kq;
		srand(time(NULL));  //nho
		con_ran ran;
		hoa_qua qua;
		qua_thui thui;
		qua_mang qm;

		khoi_tao(ran, qua, thui, qm);
		while (1)
		{
			//hien thi
			hien_thi(ran, qua, thui, qm, ten);
			//xu ly
			xu_ly(ran, qua, thui, qm);
			//thang thua

			thang_thua(ran, qua, thui, kq, qm);
			if (kq == thang)
			{
				win(); break;
			}
			if (kq == thua)
			{
				lost();
				break;
			}

			if (ran.diem < 5)	Sleep(100);
			if (ran.diem < 10 && ran.diem >= 5)	Sleep(90);
			if (ran.diem < 20 & ran.diem >= 10)	Sleep(80);
			if (ran.diem < 25 && ran.diem >= 20)  Sleep(70);
			if (ran.diem >= 25) Sleep(65);
			//
		}
		
		_getch();
	_getch();
	return 0;
}