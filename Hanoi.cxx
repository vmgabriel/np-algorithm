/*
 * Hanoi.cxx
 * 
 * Copyright 2016 Gabriel Vargas <gabreta@VmGabriel96>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

//Torres de Hanoi
#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

double timeval_diff(struct timeval * a, struct timeval * b)
{
    return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
	//cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
			
    }
    else
    {
	hanoi(num-1,A,B,C);
	//cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
	hanoi(num-1,B,C,A);
    }
}

int main()
{
    int n=0;
    char A='A',B='B',C='C';
    for (n=1;n<=57;n++)
    {
	struct timeval t_ini, t_fin;
	double secs;

	gettimeofday(&t_ini, NULL);
	hanoi(n,A,C,B);
	gettimeofday(&t_fin, NULL);

	secs = timeval_diff(&t_fin, &t_ini);

	cout <<"n: "<<n<<", Tiempo: "<<secs<<endl;
    }
    return 0;
}
