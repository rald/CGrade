#include<stdio.h>

void flush(void) {
	int ch;
	while((ch=getchar())!=EOF && ch!='\n');
}

struct Student {
	char id[16];
	char name[16];
	float mid;
	float fin;
};

struct Student students[100];
int n=0;
int i;
int another;

int main(void) {

	do {
		printf("Student No.: "); scanf("%s",students[n].id);
		printf("Name: "); scanf("%s",students[n].name);
		printf("Midterm Grade: "); scanf("%f",&students[n].mid);
		printf("Final Grade: "); scanf("%f",&students[n].fin); 
		flush();
		printf("Another? "); another=getchar();
		n++;
	} while(another=='Y' || another=='y');

	printf("\n%-16s %-16s %-13s %-11s %-10s %-7s\n","Student No.","Name","Midterm Grade","Final Grade","Ave. Grade","Remarks");

	for(i=0;i<n;i++) {

		float ave=(students[i].mid+students[i].fin)/2.0;

		char *rem=ave<3.00?"Passed":"Failed";

		printf("%-16s %-16s %-13.2f %-11.2f %-10.2f %-7s\n",
				students[i].id,
				students[i].name,
				students[i].mid,
				students[i].fin,
				ave,
				rem);
	}

	printf("\n");

	return 0;
}
