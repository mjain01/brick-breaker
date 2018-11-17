#include<graphics.h>
#include<windows.h>
#include<graphics.h>
#include<math.h>
#include "front.h"
int rand(double);
void color(int,int,int,int);
int blocks[25];
void print();
void bricks();
void tostring(int);
void define();
int brickno(int);
int space();
char str[100],ch[100];
struct brick
{
int xb[4];
int yb[4];
}b[25];
void file1();
void rdraw();
void plate();
void draw();
void quad1();
void quad2();
void quad3();
void quad4();
void collision();
int cc=0;int count_bricks=0;
int brick_no;
int global_c;
int after_global_c;
int quad=1;
int top,left,right,bottom;
int xp1=300,yp1=400,xp2=300+80,yp2=400+10;
int static x=300;
int static y=300;
int static a=320;
double static x1c,y1c;
int lp,rp;
   int counter,flag;
   //std::ofstream myfile;
   int main()
{
//std::    ofstream myfile;
	int z;
	 int gd = DETECT, gm;
//initwindow(1024,720);
 initgraph(&gd, &gm, "");
   lp=0;
   rp=0;
   z=0;
 //  myfile.open ("example.txt");

  // myfile<<"hello";
  /*myfile << "Writing this to a file.\n";
  myfile.close();*/
 z=start();
 if(z==0)
	 exit(0);
 cleardevice();
   x1c=x;y1c=y;
   define();
   bricks();
   rdraw();
flag=0;
getch();
while(1)
{

/*if(cc==50)
{


	myfile << "cc="<<cc<<"\n";
	myfile << "x="<<x<<"\n";
	myfile << "y="<<y<<"\n";
	myfile << "a="<<a<<"\n";
	myfile << "quad="<<quad<<"\n";
		myfile << "brick_no="<<brick_no<<"\n";
		myfile << "global_c="<<global_c<<"\n";
	myfile<<"-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*- \n";
}*/
if(space()==1)
{
//	myfile.close();
    break;

}
    if (flag==1)
    {
	//	myfile.close();
    break;
    }
if(count_bricks==24)
{
	//myfile.close();
	break;
}
    plate();
collision();
}
closegraph();
return 0;
   }
   void draw()
{
	 if(cc>=70)
	 {
//myfile << "cc=";
	//myfile << "x=";
	//myfile << "y=";
	//myfile << "a=";
	//myfile << "quad=";
		 cc=0;
	x1c=x1c+cos(a*3.142/180);
	y1c=y1c+sin(a*3.142/180);
	x=(int)x1c;
	y=(int)y1c;
	//------------------
		//x=rand(x1c);
	//y=rand(y1c);
	//circle(x,y,10);
	//setcolor(BLACK);
		circle(x,y,10);
setcolor(WHITE);
	 }
	 else{
		 if(cc==69)
		 {
			 setcolor(BLACK);
	 circle(x,y,10);
	 setcolor(WHITE);
		 }
		 setcolor(WHITE);

		 circle(x,y,10);
		 cc++;
	 }
	 setcolor(BLACK);
	 circle(x,y,10);
	 setcolor(WHITE);

		}
	void	collision()
		{
		    	 int x1,x2,x3,x4,y1,y2,y3,y4,c,no;
			top=y-5;bottom=y+5;left=x-5;right=x+5;
			if(top==1&&quad!=4&&quad!=3)
	{
//outtextxy(310,450,"top");
		if(quad==1 )
		{
			quad=4;
			a=360-a;
		}
		else if(quad==2 )
		{
			quad=3;
			a=360-a;
	 	}
	}
	else	if(bottom==478&&quad!=1&&quad!=2)
	{
flag=1;
	//	outtextxy(310,450,"bottom");
	/*	if(quad==4)
		{

			quad=1;
			a=360-a;
			//quad1();
		}
		else if(quad==3)
		{
			quad=2;
			a=360-a;
			//quad2();
		}*/
	}
		else if(left<=0&&quad!=4&&quad!=1)
	{
if(quad==3 )
		{
			quad=4;
			a=180-a;
        }
		else if(quad==2 )
		{
			quad=1;
			a=540-a;
		}
	}
	//	outtextxy(310,450,"left");
     else if(right==639&&quad!=3&&quad!=2)
	 {
 //outtextxy(310,450,"right");
		 if(quad==4 )
		 {
			a=180-a;
			 quad=3;
		 }
		 else if(quad==1 )
		 {
			 quad=2;
			 a=540-a;
		  }
	 }
/*	 else if(x>=20&&x<=615&&y>=20&&y<=215)
 {*/
//	    outtextxy(360,450,"danger");
else if(bottom==yp1&&(right-5)>=xp1&&right-5<=xp2)//plate
    {
		if(quad==4 )
		{
			quad=1;
			a=360-a;
			}
		else if(quad==3 )
		{

			quad=2;
			a=360-a;
		}}
	else if(quad==1)//bricks
	 {
		 for(c=1;c<25;c++)
		 {
			 no=blocks[c];
			 if(blocks[c]!=-1)
			 {
				  x2=b[c].xb[1];
				 y2=b[c].yb[1];
				 x1=b[c].xb[0];
				 y1=b[c].yb[0];
				 x3=b[c].xb[2];
				 y3=b[c].yb[2];
				 x4=b[c].xb[3];
				 y4=b[c].yb[3];
				 if(x>=x4&&x<=x3&&top==y4  )//horizontal check
						 {
							 global_c=blocks[c];
							 count_bricks++;
					        a=360-a;
					brick_no=brickno(blocks[c]);
					blocks[c]=-1;
					 quad=4;
after_global_c=blocks[c];
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					c=-1;

				//	outtextxy(310,450,"brick");
					break;
				 }
				 else if(y>=y1&&y<=y4&&right==x1 )//vertical check
				 {

global_c=blocks[c];							count_bricks++;
					 brick_no=brickno(blocks[c]);
					 a=540-a;
					 blocks[c]=-1;
					 quad=2;
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					c=-1;
				//	outtextxy(310,450,"brick");
after_global_c=blocks[c];
					break;
		 }
		 }
		 }
	 }
  else  if(quad==2)//bricks
	 {
		 for(c=1;c<25;c++)
		 {
			 no=blocks[c];
			 if(no!=-1)
			 {

				 x1=b[c].xb[0];
				 y1=b[c].yb[0];
				 x2=b[c].xb[1];
				 y2=b[c].yb[1];
				 x3=b[c].xb[2];
				 y3=b[c].yb[2];
				 x4=b[c].xb[3];
				 y4=b[c].yb[3];
				 if(y>=y2&&y<=y3&&left==x2 )//vertical check
				 {
					global_c=blocks[c]; 							 count_bricks++;
					 brick_no=brickno(blocks[c]);
					 a=540-a;
					 blocks[c]=-1;
					 quad=1;
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					c=-1;
after_global_c=blocks[c];
			//		outtextxy(310,450,"brick");
					break;
				 }
				 else if(x>=x4&&x<=x3&&top==y4)//horizontal check
				 {
					 					global_c=blocks[c];		 count_bricks++;
					 brick_no=brickno(blocks[c]);
					 a=360-a;
					 blocks[c]=-1;
					 quad=3;

					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					c=-1;
after_global_c=blocks[c];
			//		outtextxy(310,450,"brick");
					break;
		 }
		 }
		 }
		 }
 else if(quad==3)//bricks
 {
	for(c=1;c<25;c++)
		 {
			 no=blocks[c];
			 if(no!=-1)
			 {
			 x4=b[c].xb[3];
				 y4=b[c].yb[3];
				 x1=b[c].xb[0];
				 y1=b[c].yb[0];
				 x2=b[c].xb[1];
				 y2=b[c].yb[1];
				 x3=b[c].xb[2];
				 y3=b[c].yb[2];
				 if(x>=x1&&x<=x2&&bottom==y1 )//horizontal
				 {							 count_bricks++;global_c=blocks[c];
					 brick_no=brickno(blocks[c]);
					 a=360-a;
					 blocks[c]=-1;
					 quad=2;
					 //quad2();
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					c=-1;
				//	outtextxy(310,450,"brick");
					after_global_c=blocks[c];
					break;
				 }
				 else if(y>=y2&&y<=y3&&left==x2 )
				 {
					 							 count_bricks++;global_c=blocks[c];
					 brick_no=brickno(blocks[c]);
					 a=180-a;
					 blocks[c]=-1;
					 quad=4;
					// quad4();
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					c=-1;
after_global_c=blocks[c];
			//		outtextxy(310,450,"brick");
					break;
		 }}}
 }
else if(quad==4)//bricks
{
for(c=1;c<25;c++)
		 {
			 no=blocks[c];
			 if(no!=-1)
			 {
				 x1=b[c].xb[0];
				 y1=b[c].yb[0];

				 x4=b[c].xb[3];
				 y4=b[c].yb[3];
				 x2=b[c].xb[1];
				 y2=b[c].yb[1];
				 if(x>=x1&&x<=x2&&bottom==y1 )//horizontal check
				 {
					brick_no= brickno(blocks[c]);
					 global_c=blocks[c];
							 count_bricks++;
					 a=360-a;
					 quad=1;
					 blocks[c]=-1;
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
after_global_c=blocks[c];
					c=-1;
			//		outtextxy(310,450,"brick");
					break;
				 }
				 else if(y>=y1&&y<=y4&&right>=x1&&right<=x1+2)
				 {
					 							 count_bricks++;global_c=blocks[c];
					 brick_no=brickno(blocks[c]);
					 a=180-a;
					 quad=3;
blocks[c]=-1;;
					 setcolor(BLACK);
					 rectangle(b[c].xb[0],b[c].yb[0],b[c].xb[2],b[c].yb[2]);
					setcolor(WHITE);
					 c=-1;
				//	 outtextxy(310,450,"brick");
after_global_c=blocks[c];
				break;
				 }
		 }
}
 }
	draw();
		}
void plate()
{int cp;
    if(GetAsyncKeyState( VK_LEFT ))
   {
  if(lp>=50)
       {

       lp=0;
       setcolor(BLACK);
rdraw();
xp1--;
xp2--;
rdraw();
       }
       else{
        lp++;
       }
}
else if(GetAsyncKeyState( VK_RIGHT))
{
    if(rp>=50)
    {

rp=0;
setcolor(BLACK);
rdraw();
xp1++;
xp2++;
rdraw();
    }
    else
    {
        rp++;
    }
    }
else{
    rdraw();
}
}
int space()
{
	if(GetAsyncKeyState( VK_SPACE))
	{
		return 1;
	}
	else
		return 0;
}
void print()
{
	int d=50;
	tostring(x);

	outtextxy(20,450,str);
	tostring(y);
	outtextxy(80,450,str);
	tostring(a);
	//outtextxy(140,450,"angle");
	outtextxy(220,450,str);
	tostring(quad);
	outtextxy(260,450,str);
	//outtextxy(120,450,"delay=-");
	//outtextxy(170,450,);
	/*if(x>=630&&y>=455)
	{
		d=1;
	}
	else
	{
		d=1;
	}*/	//delay(d);
	//rectangle(15,440,250,490);
	color(15,440,450,490);
}
void define()
{
//std:: ofstream cord; d-1
//cord.open("cord.txt"); d-1
	int x;
	int i;int l=75;int br=25;int lt=25;int bt=25;
	for(x=1;x<25;x++)
	{
		blocks [x]=x;

		b[x].xb[0]=lt;
		b[x].yb[0]=bt;
			b[x].xb[1]=lt+75;
		b[x].yb[1]=bt;
			b[x].xb[2]=lt+75;
		b[x].yb[2]=bt+25;
			b[x].xb[3]=lt;
		b[x].yb[3]=bt+25;


/*if(x==18) d-1
{
	cord<<b[x].xb[0]<<" ";
	cord<<b[x].yb[0]<<"\n";

	cord<<b[x].xb[1]<<" ";
	cord<<b[x].yb[1]<<"\n";

	cord<<b[x].xb[2]<<" ";
	cord<<b[x].yb[2]<<"\n";

	cord<<b[x].xb[3]<<" ";
	cord<<b[x].yb[3]<<"\n";
}
else if(x==20)
{
	cord<<"--------------------------"<<"\n";
	cord<<b[x].xb[0]<<" ";
	cord<<b[x].yb[0]<<"\n";

	cord<<b[x].xb[1]<<" ";
	cord<<b[x].yb[1]<<"\n";

	cord<<b[x].xb[2]<<" ";
	cord<<b[x].yb[2]<<"\n";

	cord<<b[x].xb[3]<<" ";
	cord<<b[x].yb[3]<<"\n";
}*/
	lt=lt+100;
	if(x%6==0)
	{
		lt=25;
		bt=bt+50;
	}

	}
}
void bricks()
{

	int i,x1,x2,x3,x4,y1,y2,y3,y4;
	for(i=1;i<25;i++)
	{
		if(blocks[i]!=-1)
		x1=b[i].xb[0];
		y1=b[i].yb[0];
		x3=b[i].xb[2];
		y3=b[i].yb[2];
		rectangle(x1,y1,x3,y3);
	}
}
void tostring(int num)
{

    int i, rem, len = 0, n;
 str[0]=' ';
 str[1]=' ';
 str[2]=' ';
 str[3]=' ';
  n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}void rdraw()
{
rectangle(xp1,yp1,xp2,yp2);
setcolor(WHITE);
}
int brickno(int h)
{
	setcolor(BLACK);
	color(50,450,90,480);

	tostring(h);
	outtextxy(50,460,str);
	setcolor(WHITE);
	return h;
	}int rand(double a)
{
	 double x;
	x=a-(int)a;
	if(x<0.50)
	{
		return ((int)a);
	}
	else
	{
		return ((int)a+1);
	}
	return 0;
}
