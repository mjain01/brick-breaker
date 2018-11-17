#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
void PLAY1(double);
void P(double);
void L(double);
void A(double);
void Y(double);
void E(double);
void X(double);
void I(double);
void T(double);
void rotates(int,int,int,int);
void P1(double);
void L1(double);
void A1(double);
void Y1(double);
int theta=0;
double x13,y13,x23,y23;int xc1=250,yc1=200;
double x1a,y1a;
void PLAY(double);
int start();
void color(int,int,int,int);
void EXIT(double);
int start();
//int rectx1=100,recty1=200,rectx2=300, recty2=200, rectx3=300 ,recty3=300, rectx4=100 ,recty4=300;
int ox=200;int oy=250;int flagy=-1;
int sign1(float);
void line(double,double,double,double);
void circle_rotate();
int dd=0;
void circle_rotate()
{
	if(dd>=3)
	{
	setcolor(BLACK);
	circle(xc1,yc1,10);
	setcolor(WHITE);
	dd=0;
	theta++;
	}
	setcolor(WHITE);
		 x1a=(xc1-320)*cos(3.142*theta/180)-(240-yc1)*sin(theta*3.142/180)+320;
y1a=(xc1-320)*sin(theta*3.142/180)+(oy-240)*cos(theta*3.142/180)+240;
xc1=(int)x1a;
yc1=(int)y1a;
circle(xc1,yc1,10);
dd++;
}
void line(double x12,double y12,double x22,double y22)
{
	int x1=(int)x12;int y1=(int)y12;int x2=(int)x22;int y2=(int)y22;
    int s1,i,s2,flag,x,y;
    float dx,dy,e,temp;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    x=x1;
    y=y1;
    s1=sign1(x2-x1);
    s2=sign1(y2-y1);
    if(dy>dx)
    {
      temp=dx;
      dx=dy;
      dy=temp;
      flag=1;
    }
    else
      flag=0;

      e=2*dy-dx;
      i=1;
      while(i<=dx)
      {

      putpixel(x,y,WHITE);
	  outtextxy(100,100,"hello");
      while(e>=0)
      {
        if(flag==1)
        x=x+s1;
        else
        y=y+s2;
        e=e-2*dx;
      }
      if(flag==1)
       y=y+s2;
       else
       x=x+s1;
       e=e+2*dy;
       i++;
      }
}
 int sign1(float arg)
 {
 if(arg<0)
 return -1;
 else if(arg==0)
 return 0;
 else
 return 1;
 }
//int rectx1=100,recty1=200,rectx2=300, recty2=200, rectx3=300 ,recty3=300, rectx4=100 ,recty4=300;
int start()
{
	int cu,cd;
		cu=0;
	cd=0;
	PLAY(0.5);
	EXIT(0.5);
	while(1)
	{
//circle_rotate();
	if(GetAsyncKeyState( VK_UP))
   {
	   cu++;
	   if(cu>=100)
	   {
		   flagy=1;

		    cleardevice();
		   cu=0;
PLAY(0.7);
EXIT(0.5);
   }
   }
   else if(GetAsyncKeyState( VK_DOWN))
   {
	   cd++;
	   if(cd>=100)
	   {flagy=0;
		   cleardevice();
		   cd=0;
PLAY(0.5);
EXIT(0.7);

   }
   }
   else if(GetAsyncKeyState( VK_SPACE))
   {
	   break;
   }
   else if(GetAsyncKeyState( VK_RETURN))
	{
		if(flagy==1)
		{
		//	PLAY1(0.7);
			return flagy;
		}
		else if(flagy==0)
		{		
//	PLAY1(0.7);
	return flagy;
		}		
		return -1;
	}
	
}
return -1;
}
void PLAY(double k)
{	ox=300;oy=150;

	P(k);
	L(k);
	A(k);
	Y(k);
}
void PLAY1(double k)
{	ox=300;oy=150;
for(theta=0;theta<=360;theta++)
{
	P1(0.7);
	L1(0.7);
	A1(0.7);
	Y1(0.7);
	delay(100);
	cleardevice();
}	
}
void EXIT(double k)
{ox=300;oy=250;
	E(k);
		X(k);
		I(k);
		T(k);
}
void P(double k)
{
	line((-90*k)+ox,(-45*k)+oy,(-90*k)+ox,(k*45)+oy);//|
	line((-90*k)+ox,(-45*k)+oy,(-50*k)+ox,(-45*k)+oy);//-
	line((-50*k)+ox,(-45*k)+oy,(-50*k)+ox,(-5*k)+oy);//|
	line((-50*k)+ox,(-5*k)+oy,(-90*k)+ox,(-5*k)+oy);//-
}
void L(double k)
{
		line((-30*k)+ox,(-45*k)+oy,(-30*k)+ox,(k*45)+oy);//|
	line((-30*k)+ox,(45*k)+oy,(-10*k)+ox,(45*k)+oy);//-

}
void A(double k)
{
		line((10*k)+ox,(-45*k)+oy,(10*k)+ox,(k*45)+oy);
		line((10*k)+ox,(-45*k)+oy,(40*k)+ox,(k*-45)+oy);
		line((40*k)+ox,(-45*k)+oy,(40*k)+ox,(k*45)+oy);
	    line((10*k)+ox,(-20*k)+oy,(40*k)+ox,(k*-20)+oy);
}
void Y(double k)
{
		line((60*k)+ox,(-45*k)+oy,(60*k)+ox,(k*-15)+oy);
			line((60*k)+ox,(-15*k)+oy,(90*k)+ox,(k*-15)+oy);
				line((90*k)+ox,(-45*k)+oy,(90*k)+ox,(k*45)+oy);

}
void E(double k)
{
	line((-90*k)+ox,(-45*k)+oy,(-90*k)+ox,(k*45)+oy);
	line((-90*k)+ox,(-45*k)+oy,(-60*k)+ox,(k*-45)+oy);
line((-90*k)+ox,(2*k)+oy,(-60*k)+ox,(k*2)+oy);
line((-90*k)+ox,(45*k)+oy,(-60*k)+ox,(k*45)+oy);
}
void X(double k)
{
	line((-40*k)+ox,(-45*k)+oy,(-10*k)+ox,(k*45)+oy);
	line((-10*k)+ox,(-45*k)+oy,(-40*k)+ox,(k*45)+oy);
}
void I(double k)
{
	line((10*k)+ox,(-45*k)+oy,(40*k)+ox,(k*-45)+oy);
	line((25*k)+ox,(-45*k)+oy,(25*k)+ox,(k*45)+oy);
	line((20*k)+ox,(46*k)+oy,(20*k)+ox,(k*46)+oy);
}
void T(double k)
{
	line((60*k)+ox,(-45*k)+oy,(90*k)+ox,(k*-45)+oy);
	line((75*k)+ox,(-45*k)+oy,(75*k)+ox,(k*45)+oy);
}

void color(int a1,int b1,int a2,int b2)//545,460,630,475
{

	int d;
		for(d=b1;d<=b2;d++)
		{
			setcolor(BLACK);
			line(a1,d,a2,d);
		}
		setcolor(WHITE);

}
void P1(double k)
{
	rotates(-90,-45,-90,45);
	line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);//|
	rotates(-90,-45,-50,-45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//	line((-90*k)+ox,(-45*k)+oy,(-50*k)+ox,(-45*k)+oy);//-
	rotates(-50,-45,-50,-5);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//	line((-50*k)+ox,(-45*k)+oy,(-50*k)+ox,(-5*k)+oy);//|
	rotates(-50,-5,-90,-5);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//	line((-50*k)+ox,(-5*k)+oy,(-90*k)+ox,(-5*k)+oy);//-
}
void L1(double k)
{
	rotates(-30,-45,-30,45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//		line((-30*k)+ox,(-45*k)+oy,(-30*k)+ox,(k*45)+oy);//|
		rotates(-30,45,-10,45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//	line((-30*k)+ox,(45*k)+oy,(-10*k)+ox,(45*k)+oy);//-

}
void A1(double k)
{
	rotates(10,-45,10,45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//		line((10*k)+ox,(-45*k)+oy,(10*k)+ox,(k*45)+oy);
		rotates(10,-45,40,-45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//		line((10*k)+ox,(-45*k)+oy,(40*k)+ox,(k*-45)+oy);
		rotates(40,-45,40,45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//		line((40*k)+ox,(-45*k)+oy,(40*k)+ox,(k*45)+oy);
		rotates(10,-20,40,-20);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//	    line((10*k)+ox,(-20*k)+oy,(40*k)+ox,(k*-20)+oy);
}
void Y1(double k)
{
		rotates(60,-45,60,-15);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//		line((60*k)+ox,(-45*k)+oy,(60*k)+ox,(k*-15)+oy);
			rotates(60,-15,90,-15);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//			line((60*k)+ox,(-15*k)+oy,(90*k)+ox,(k*-15)+oy);
				rotates(90,-45,90,45);
line((x13*k)+ox,(y13*k)+oy,(x23*k)+ox,(k*y23)+oy);
//				line((90*k)+ox,(-45*k)+oy,(90*k)+ox,(k*45)+oy);

}
void rotates(int xl1,int yl1,int xl2,int yl2)
{
double x13,y13,x23,y23;
		 x13=(xl1-ox)*cos(3.142*theta/180)-(oy-yl1)*sin(theta*3.142/180)+ox;
y13=(xl1-ox)*sin(theta*3.142/180)+(oy-yl1)*cos(theta*3.142/180)+oy;
		 x23=(xl2-ox)*cos(3.142*theta/180)-(oy-yl2)*sin(theta*3.142/180)+ox;
y23=(xl2-ox)*sin(theta*3.142/180)+(oy-yl2)*cos(theta*3.142/180)+oy;
	


}
