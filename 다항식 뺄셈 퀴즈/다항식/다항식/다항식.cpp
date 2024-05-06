#include <stdio.h>
#include <stdlib.h>

//poly_add1 �κ�
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { // ���׽� ����ü Ÿ�� ����
	int degree;// ���׽��� ����
	float coef[MAX_DEGREE];// ���׽��� ���
} polynomial;

polynomial poly_sub1(polynomial A, polynomial B)
{// C = A+B ���⼭ A�� B�� ���׽��̴�. ����ü�� ��ȯ�ȴ�.
	polynomial C;// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // ��� ���׽� ����
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { // A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {// B�� > A��
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d  ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_sub1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}


/* poly_add2 �κ�

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS] = { { 8,3 },{ 7,1 },{ 1,0 },{ 10,3 },{ 3,2 },{ 1,0 } };
int avail = 6;

// �� ���� ������ ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰��Ѵ�.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}



// C = A + B
void poly_sub2(int Astart, int Aend, int Bstart, int Bend, int* Cstart, int* Cend) {
	float tempcoef;
	*Cstart = avail;
	while (Astart <= Aend && Bstart <= Bend) {
		switch (compare(terms[Astart].expon, terms[Bstart].expon)) {
		case '>': // A�� ���� > B�� ����
			attach(terms[Astart].coef, terms[Astart].expon);
			Astart++;
			break;
		case '=': // A�� ���� == B�� ����
			tempcoef = terms[Astart].coef - terms[Bstart].coef;
			if (-tempcoef)
				attach(tempcoef, terms[Astart].expon);
			Astart++;
			Bstart++;
			break;
		case '<': // A�� ���� < B�� ����
			attach(terms[Bstart].coef, terms[Bstart].expon);
			Bstart++;
			break;
		}
	}

	// A�� ������ �׵��� �̵���
	for (; Astart <= Aend; Astart++)
		attach(terms[Astart].coef, terms[Astart].expon);
	// B�� ������ �׵��� �̵���
	for (; Bstart <= Bend; Bstart++)
		attach(terms[Bstart].coef, terms[Bstart].expon);
	*Cend = avail - 1;
}

void print_poly(int start, int end)
{
	for (int i = start; i < end; i++)
		printf("%3.1fx^%d - ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[end].coef, terms[end].expon);
}

int main(void)
{
	int Astart = 0, Aend = 2, Bstart = 3, Bend = 5, Cstart, Cend;
	poly_sub2(Astart, Aend, Bstart, Bend, &Cstart, &Cend);
	print_poly(Astart, Aend);
	print_poly(Bstart, Bend);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(Cstart, Cend);
	return 0;
}
*/