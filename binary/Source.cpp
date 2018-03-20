#include <conio.h>
#include <iostream>
#include <math.h>
//#include<conios>

using namespace std;

//#define P 5
//#define P 7 
#define P 	7
#define z 	 10   //remember z must be > P

//void prints(void);
//int m[z];
//int s[z];
int i, j;
void printa(void);
void printb(void);
void sqaurea(void);
void modb(void);
void subractb(void);
int a[z], b[z*2];
void carryb(void);



void main(void)
{
	//prints();
	//s[2] = 1; 
	//prints();

	// clear a[] b[]
	for (int i = 0; i < 10; i++) a[i] = 0; 
	for (int i = 0; i < 20; i++) b[i] = 0;
	printa();
	printb(); 
	a[2] = 1;//set a[] to = 4
	//set a[] to number square 
	for (int k = 0; k < P - 2; k++)
	{

		cout << "P = " << P << "  iteration = " << k + 1 << endl;


		//squareing a and storing this into b

		//cout << "Squar : ";
		sqaurea();
		//printb();

		//pefroming the carry 
		//cout << "Carry : ";
		carryb();
		//printb();


		//takuing 2 away from b 

		//cout << " sub 2: ";
		subractb();
		//printb();

		
		// printing the mod from b and placing it into a
		//cout << "mod = ";
		modb();
		//printa();

		// clear b 

		//for (int i = 0; i < z; i++) b[i] = 0;

		//for (int i = 0; i < z; i++) a[i] = b[i];//clear a
		
		//for (int i = 0; i < z*2; i++) b[i] = 0;
		
		cout << endl;
	}

	printa();






	_getch();

}



void printa(void)
{
	cout << "a[]=";
	for (int i = z-1; i > -1; i--) cout << a[i];
	cout << endl;
}


void carryb(void)
{
	for (int i = 0; i < z*2; i++) {

		if (b[i] > 16383) { b[i] -= 16384;	b[i + 14]++; }
		if (b[i] > 8191) { b[i] -= 8192;	b[i + 13]++; }
		if (b[i] > 4095) { b[i] -= 4096;	b[i + 12]++; }
		if (b[i] > 2047) { b[i] -= 2048;	b[i + 11]++; }
		if (b[i] > 1023) { b[i] -= 1024;	b[i + 10]++; }
		if (b[i] > 511) { b[i] -= 512;		b[i + 9]++; }
		if (b[i] > 255) { b[i] -= 256;		b[i + 8]++; }
		if (b[i] > 127) { b[i] -= 128;	b[i + 7]++; }
		if (b[i] > 63) { b[i] -= 64;		b[i + 6]++; }
		if (b[i] > 31) { b[i] -= 32;		b[i + 5]++; }
		if (b[i] > 15) { b[i] -= 16;		b[i + 4]++; }
		if (b[i] > 7) { b[i] -= 8;		    b[i + 3]++; }

		if (b[i] > 3) { b[i] -= 4;          b[i + 2]++; }
		if (b[i] > 1) { b[i] -= 2;           b[i + 1]++; }
	}
}

void modb(void)
{
	int count = 0;


	//_getch();
	//clearing a
	for (int i = 0; i < z; i++) a[i] = 0;
	//copy first p digits from b[] to a[]
	for (int i = 0; i <P; i++) a[i] = b[i];
	//copy p to P*2 digits
	for (int i = 0; i <P; i++) a[i] += b[i+P];
	
	//printa();
	//carry for a[]
	for (int i = 0; i < P+1; i++)
	{
		if (a[i] > 1)
		{
			a[i] -= 2;
			a[i + 1] ++;
		}
	}
	//check last digit
	if (a[P] == 1)
	{
		a[P] = 0;
		a[0]++;


	}
	//cout << "check last digit ";
	//printa();
	//carry for a[]
	for (int i = 0; i < P + 1; i++)
	{
		if (a[i] > 1)
		{
			a[i] -= 2;
			a[i + 1] ++;
		}
	}
	//printa();
	
	for (int i = 0; i < z*2; i++) b[i] = 0;
}


void subractb(void)
{
	int index;
	if (b[1] == 1)
	{
		//cheack if the 2 units are 1. If they are chage it to zero
		b[1] = 0;
	}
	else {
		for (int i = 2; i < z*2; i++)
		{
			if (b[i] == 1)
			{
				index = i;
				b[i] = 0;
				i = z*2;
			}
		}
		for (int i = index - 1; i >0; i--)
		{
			b[i] = 1;
		}
	}
}



 


void sqaurea(void)
{
	for (int j = 0; j < z; j++)
	{
		if (a[j] == 1)
		{
			for (int i = 0; i < z; i++)

			{
				if (a[i] == 1)
				{
					b[i + j]++;
				}
			}

		}
	}
}

void printb(void)
{
	cout << "b[]=";
	for (int i = z * 2 - 1; i > -1; i--)
	{
		if (i == P-1) cout << " ";
		cout << b[i];
	}
	cout << endl;
}
