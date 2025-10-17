/*
 * nqueens_ga_min.c
 * Estrutura geral de um Algoritmo GenC)tico para N-Rainhas (N=4), versC#o enxuta.
 * - SaC-da apenas no terminal (stdout).
 * - Sem escrita de mC)tricas/arquivos.
 * - FunC'C5es com TODOs para o aluno completar.
 *
 * Compilar: gcc -Wall -O2 nqueens_ga_min.c -o nqueens
 * Executar : ./nqueens            (seed baseada no tempo)
 *            ./nqueens 12345      (seed fixa p/ reprodutibilidade)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* ---------------- ParC"metros do problema e do GA ---------------- */
#define N               4           /* tamanho do tabuleiro */
#define POP_SIZE        100         /* tamanho da populaC'C#o */
#define MAX_GEN         1000        /* mC!x. geraC'C5es */
#define CROSS_RATE      0.80f       /* taxa de crossover */
#define MUT_RATE        0.10f       /* taxa de mutaC'C#o por gene */
#define ELITE_COUNT     2           /* nB: de elites preservados */
#define TOURNAMENT_K    3           /* tamanho do torneio */

/* ---------------- RepresentaC'C#o de indivC-duo -------------------- */
typedef struct {
	int gene[N];     /* gene[i] = coluna da rainha na linha i */
	int fitness;     /* aptidC#o */
} Individual;

/* -------------------- Utilidades aleatC3rias --------------------- */
static inline int rand_int(int a, int b) {
	/* inteiro uniforme em [a,b] (assume a <= b) */
	return a + rand() % (b - a + 1);
}

static inline double rand_unit() {
	/* real uniforme em [0,1) */
	return (double)rand() / (double)(RAND_MAX);
}

/* -------------------- ProtC3tipos das funC'C5es -------------------- */
void random_individual(Individual *ind);
int  compute_conflicts(const Individual *ind);
int  evaluate(Individual *ind);
int  cmp_desc_fitness(const void *a, const void *b);
void copy_individual(const Individual *src, Individual *dst);
int  tournament_select(Individual pop[], int pop_size);
void one_point_crossover(const Individual *p1, const Individual *p2,
                         Individual *c1, Individual *c2);
void mutate(Individual *ind);
void print_board_ascii(const Individual *ind);

/* -------------------- ImplementaC'C5es (STUBs) -------------------- */
void random_individual(Individual *ind) {
	// TODO: para cada i em [0..N-1], sorteie ind->gene[i] em [0, N-1].
	// Inicie ind->fitness = 0 (serC! definido em evaluate).
	for(int i=0; i<N; i++)
	{
		ind->gene[i] = rand_int(0, N-1);
	}

	ind->fitness = 0;

	(void)ind;
}

int compute_conflicts(const Individual *ind) {
	/* TODO: contar pares (i<j) em conflito:
	     - mesma coluna: ind->gene[i] == ind->gene[j]
	     - mesma diagonal: abs(i-j) == abs(ind->gene[i] - ind->gene[j]) */
	int cont = 0;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(ind->gene[i] == ind->gene[j] || abs(i-j) == abs(ind->gene[i] - ind->gene[j])
		{
			cont++;
		}
	}
}

(void)ind;

	return cont;
}

int evaluate(Individual *ind) {
	/* TODO:
	   total_pairs = N*(N-1)/2
	   conflicts   = compute_conflicts(ind)
	   ind->fitness = total_pairs - conflicts
	   return ind->fitness; */

    total_pairs = N*(N-1)/2;
    conflicts   = compute_conflicts(ind);
    ind->fitness = total_pairs - conflicts;
    return ind->fitness;
	   
	(void)ind;
}

int cmp_desc_fitness(const void *a, const void *b) {
	/* TODO: ordenar decrescentemente por fitness */
	const Individual *ia = (const Individual*)a;
	const Individual *ib = (const Individual*)b;
	(void)ia;
	(void)ib;
	return 0; /* provisC3rio */
}

void copy_individual(const Individual *src, Individual *dst) {
	/* TODO: copiar todos os genes e o fitness */
	(void)src;
	(void)dst;
}

int tournament_select(Individual pop[], int pop_size) {
	/* TODO:
	   - sorteie TOURNAMENT_K C-ndices em [0, pop_size-1]
	   - retorne o C-ndice do indivC-duo com maior fitness */
	(void)pop;
	(void)pop_size;
	return 0; /* provisC3rio */
}

void one_point_crossover(const Individual *p1, const Individual *p2,
                         Individual *c1, Individual *c2) {
	/* TODO:
	   - Com prob. CROSS_RATE: escolher um corte em [1, N-1),
	     combinar prefixo de p1 com sufixo de p2 (c1) e o inverso (c2)
	   - Caso contrC!rio: apenas copiar p1->c1 e p2->c2 */
	(void)p1;
	(void)p2;
	(void)c1;
	(void)c2;
}

void mutate(Individual *ind) {
	/* TODO: para cada gene i, com prob. MUT_RATE,
	   sorteie nova coluna em [0, N-1] */
	(void)ind;
}

void print_board_ascii(const Individual *ind) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (ind->gene[i] == j) printf("Q ");
			else                   printf(". ");
		}
		printf("\n");
	}
}

/* --------------------------- main ------------------------------- */
int main(int argc, char *argv[]) {
	/* Seed: tempo ou valor fixo informado na linha de comando */
	if (argc >= 2) {
		unsigned int seed = (unsigned int)strtoul(argv[1], NULL, 10);
		srand(seed);
	} else {
		srand((unsigned int)time(NULL));
	}

	Individual pop[POP_SIZE], new_pop[POP_SIZE];

	/* 1) InicializaC'C#o e avaliaC'C#o */
	for (int i = 0; i < POP_SIZE; ++i) {
		random_individual(&pop[i]);  /* TODO */
		evaluate(&pop[i]);           /* TODO */
	}

	/* 2) OrdenaC'C#o inicial (facilita elitismo) */
	qsort(pop, POP_SIZE, sizeof(Individual), cmp_desc_fitness); /* TODO */

	const int TOTAL_PAIRS = N * (N - 1) / 2;
	int best_gen_found = -1;

	/* 3) Loop evolutivo */
	for (int gen = 1; gen <= MAX_GEN; ++gen) {

		/* 3a) Elitismo */
		for (int e = 0; e < ELITE_COUNT; ++e) {
			copy_individual(&pop[e], &new_pop[e]); /* TODO */
		}

		/* 3b) ReproduC'C#o: seleC'C#o, crossover, mutaC'C#o */
		for (int i = ELITE_COUNT; i < POP_SIZE; i += 2) {
			int p1 = tournament_select(pop, POP_SIZE); /* TODO */
			int p2 = tournament_select(pop, POP_SIZE); /* TODO */

			Individual c1, c2;
			one_point_crossover(&pop[p1], &pop[p2], &c1, &c2);  /* TODO */
			mutate(&c1);                                        /* TODO */
			mutate(&c2);                                        /* TODO */
			evaluate(&c1);                                      /* TODO */
			evaluate(&c2);                                      /* TODO */

			new_pop[i] = c1;
			if (i + 1 < POP_SIZE) new_pop[i + 1] = c2;
		}

		/* 3c) SubstituiC'C#o e ordenaC'C#o */
		for (int i = 0; i < POP_SIZE; ++i) pop[i] = new_pop[i];
		qsort(pop, POP_SIZE, sizeof(Individual), cmp_desc_fitness); /* TODO */

		/* 3d) Parada por soluC'C#o C3tima (fitness = C(N,2)) */
		if (pop[0].fitness == TOTAL_PAIRS) {
			best_gen_found = gen;
			break;
		}
	}

	/* 4) SaC-da no terminal: melhor indivC-duo e tabuleiro */
	Individual best = pop[0];
	printf("Melhor fitness: %d (C3timo = %d)\n", best.fitness, TOTAL_PAIRS);
	printf("Cromossomo (lin->col): ");
	for (int i = 0; i < N; ++i) printf("%d ", best.gene[i]);
	printf("\n\nTabuleiro:\n");
	print_board_ascii(&best);  /* TODO */

	if (best_gen_found >= 0)
		printf("\nSoluC'C#o C3tima alcanC'ada na geraC'C#o: %d\n", best_gen_found);
	else
		printf("\nSoluC'C#o C3tima NCO alcanC'ada (ajuste parC"metros/operadores).\n");

	return 0;
}
